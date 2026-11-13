/* hdmi_tx_set_txffe_mode  (FUN_a00a3578)
 *
 * Set the transmit equaliser (TxFFE) mode and level of an HDMI TX port.
 *   port: HDMI TX port
 *   txffe_mode: 1 = Preshoot, 2 = De-Emphasis, 3 = NO, any other value = Normal (Exit Mode)
 *   pass_3..pass_6: not used here; handed on to hdmi_tx_set_regs_7c_9a in modes 1 and 2
 * Name basis: proven - prints 'TxFFE De-Emphasis', 'TxFFE_Preshoot', 'TxFFE_NO', 'TxFFE_Normal(Exit Mode)[%d]'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a3578 @ 0xa00a3578-0xa00a3788 (132 words), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the callees are declared without prototypes; `port_word` is the port as an unsigned int, taken in each
 *    arm after the print;
 *  - the normal-mode print passes `mode` as its argument;
 *  - the two tables are one array of {u8, u8} records and one of u16 (the firmware loads the second byte of a
 *    record from base + 1).
 */

/* Texts printed for each mode. */
extern unsigned int DAT_a006ba08;               /* "\t\t - TxFFE De-Emphasis" */
extern unsigned int DAT_a006ba28;               /* "\t\t - TxFFE_Preshoot" */
extern unsigned int DAT_a006ba48;               /* "\t\t - TxFFE_NO" */
extern unsigned int DAT_a006ba60;               /* "\t\t - TxFFE_Normal(Exit Mode)[%d]\n" */
extern int dbg_printf();
extern unsigned int dbg_print_string();
extern void hdmi_tx_set_regs_08_98();
extern void hdmi_tx_set_regs_0e_9b();
extern void hdmi_tx_set_regs_7c_9a();
extern int hdmi_tx_reg_read8();
extern void hdmi_tx_reg_write8();
extern void hdmi_tx_reg_update_bits();

/* Values of the De-Emphasis mode for each TxFFE level (data RAM; start values {0xD,4}, {0xC,5}, {0xB,6},
   {0xA,7} for levels 0..3). */
struct de_emphasis_values {
    unsigned char regs_08_98;           /* for hdmi_tx_set_regs_08_98 */
    unsigned char regs_0e_9b;           /* for hdmi_tx_set_regs_0e_9b */
};
extern struct de_emphasis_values hdmi_tx_ffe_de_emphasis_values[];
/* Value of the normal mode for each TxFFE level, written to FRL registers 0xE2 (low byte) / 0xE3 (high byte)
   (data RAM; start values 0, 0x55, 0xAA, 0xFF for levels 0..3). */
extern unsigned short hdmi_tx_ffe_normal_values[];
extern unsigned char hdmi_tx_ffe_levels[];

/* TxFFE modes, named by their printed texts (as chosen by DRV_HDMI21_TXDetect_FSM_LTS_3). */
enum txffe_mode {
    TXFFE_MODE_NORMAL      = 0,         /* 'TxFFE_Normal(Exit Mode)' (every value other than 1..3) */
    TXFFE_MODE_PRESHOOT    = 1,         /* 'TxFFE_Preshoot' */
    TXFFE_MODE_DE_EMPHASIS = 2,         /* 'TxFFE De-Emphasis' */
    TXFFE_MODE_NO          = 3          /* 'TxFFE_NO' */
};

#define HDMI_TX_BANK_PHY     1          /* bank 1 of an HDMI transmitter's registers */
#define HDMI_TX_BANK_FRL     4          /* bank 4 of an HDMI transmitter's registers (the FRL registers) */
#define PHY_REG_7D           0x7d
#define REG_7D_FFE_BIT       0x10       /* bit 4 of PHY register 0x7D: set in modes 1..3, cleared in the normal mode */
#define FRL_REG_FFE_LOW      0xe2
#define FRL_REG_FFE_HIGH     0xe3
#define UPDATE_SET           1          /* mode argument of hdmi_tx_reg_update_bits */
#define UPDATE_CLEAR         0
#define PRESHOOT_REGS_08_98  0xe        /* fixed values of the Preshoot mode */
#define PRESHOOT_REGS_7C_9A  3

/*
 * Set the TxFFE mode of HDMI output `port`, using the port's TxFFE level (hdmi_tx_ffe_levels, 0..3) where the
 * mode has levels.
 *
 *   port           HDMI output port
 *   txffe_mode     TXFFE_MODE_*; only the low byte counts
 *   pass_3..pass_6 not used here; handed on to hdmi_tx_set_regs_7c_9a in modes 1 and 2 (the only caller,
 *                  DRV_HDMI21_TXDetect_FSM_LTS_3, passes two arguments)
 *
 * Each mode prints its text, then:
 *   De-Emphasis (2): PHY bit 0x7D.4 set; registers 8/0x98 get mode 3 with the level's regs_08_98 value,
 *                    registers 0x0E/0x9B the level's regs_0e_9b value, registers 0x7C/0x9A the value 0.
 *   Preshoot (1):    PHY bit 0x7D.4 set; registers 8/0x98 mode 3 with 0xE, 0x0E/0x9B 0, 0x7C/0x9A 3.
 *   NO (3):          PHY bit 0x7D.4 set; PHY register 8 bits 4..7 set, register 0x0E bits 0..2 and 4..6 and
 *                    register 0x7C bits 4..5 cleared.
 *   other (normal):  PHY bit 0x7D.4 cleared; the level's 16-bit value into FRL registers 0xE2/0xE3.
 * LTS_3 calls it with the mode it chose from SCDC register 0x35, and again after it raised the level.
 */
void hdmi_tx_set_txffe_mode(unsigned char port, int txffe_mode, unsigned int pass_3, unsigned int pass_4, unsigned int pass_5, unsigned int pass_6)
{
    unsigned int port_word;
    unsigned int value;
    unsigned char mode = txffe_mode;

    if (mode == TXFFE_MODE_DE_EMPHASIS) {
        dbg_print_string(&DAT_a006ba08);
        port_word = port;
        hdmi_tx_reg_update_bits(port_word, HDMI_TX_BANK_PHY, PHY_REG_7D, REG_7D_FFE_BIT, UPDATE_SET);
        hdmi_tx_set_regs_08_98(port_word, 3, hdmi_tx_ffe_de_emphasis_values[hdmi_tx_ffe_levels[port_word]].regs_08_98);
        hdmi_tx_set_regs_0e_9b(port_word, hdmi_tx_ffe_de_emphasis_values[hdmi_tx_ffe_levels[port_word]].regs_0e_9b);
        hdmi_tx_set_regs_7c_9a(port_word, 0, pass_3, pass_4, pass_5, pass_6);
        return;
    }
    if (mode == TXFFE_MODE_PRESHOOT) {
        dbg_print_string(&DAT_a006ba28);
        port_word = port;
        hdmi_tx_reg_update_bits(port_word, HDMI_TX_BANK_PHY, PHY_REG_7D, REG_7D_FFE_BIT, UPDATE_SET);
        hdmi_tx_set_regs_08_98(port_word, 3, PRESHOOT_REGS_08_98);
        hdmi_tx_set_regs_0e_9b(port_word, 0);
        hdmi_tx_set_regs_7c_9a(port_word, PRESHOOT_REGS_7C_9A, pass_3, pass_4, pass_5, pass_6);
        return;
    }
    if (mode == TXFFE_MODE_NO) {
        dbg_print_string(&DAT_a006ba48);
        port_word = port;
        hdmi_tx_reg_update_bits(port_word, HDMI_TX_BANK_PHY, PHY_REG_7D, REG_7D_FFE_BIT, UPDATE_SET);
        value = hdmi_tx_reg_read8(port_word, HDMI_TX_BANK_PHY, 8);
        hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_PHY, 8, (value | 0xfffffff0) & 0xff);
        value = hdmi_tx_reg_read8(port_word, HDMI_TX_BANK_PHY, 0xe);
        hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_PHY, 0xe, value & 0xf8);
        value = hdmi_tx_reg_read8(port_word, HDMI_TX_BANK_PHY, 0xe);
        hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_PHY, 0xe, value & 0x8f);
        value = hdmi_tx_reg_read8(port_word, HDMI_TX_BANK_PHY, 0x7c) & 0xcf;
        hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_PHY, 0x7c, value);
        return;
    }
    dbg_printf(&DAT_a006ba60, mode);
    port_word = port;
    hdmi_tx_reg_update_bits(port_word, HDMI_TX_BANK_PHY, PHY_REG_7D, REG_7D_FFE_BIT, UPDATE_CLEAR);
    hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_FRL, FRL_REG_FFE_LOW, hdmi_tx_ffe_normal_values[hdmi_tx_ffe_levels[port_word]] & 0xff);
    value = hdmi_tx_ffe_normal_values[hdmi_tx_ffe_levels[port_word]] >> 8;
    hdmi_tx_reg_write8(port_word, HDMI_TX_BANK_FRL, FRL_REG_FFE_HIGH, value);
    return;
}
