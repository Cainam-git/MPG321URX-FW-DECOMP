/* hdmi_tx_phy_set_power  (FUN_a008dbd4)
 *
 * Run the HDMI TX PHY power-up or power-down register sequence.
 *   port: HDMI TX port
 *   on: 1 = power up
 *   mode: variant
 * Name basis: descriptive - fixed bank 1 sequence on regs 0x39, 0x9C, 0xB0, 0xB7 and 0xC0..0xC9 with waits;
 *   called with 0 by hdmi_tx_phy_power_down
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008dbd4 @ 0xa008dbd4-0xa008df40 (219 words), flags -mcpu=v8 -Os -g (section default).
 * Source form the exact build depends on: the read-modify-writes of registers 0xC9, 0x9C and 0xB7 are
 * separate statements on the unsigned char local value (one expression lets fold drop the first mask).
 * The firmware ends both arms with a tail call of the last register write.
 */
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern unsigned int hdmi_tx_reg_read8(unsigned char, unsigned char, unsigned short);
extern void timer_delay_long_units(int);

#define HDMI_TX_BANK_PHY 1              /* bank 1 of an HDMI transmitter's registers */
#define BITS_CLEAR       0              /* last argument of hdmi_tx_reg_update_bits */
#define BITS_SET         1

/* PHY registers of the sequence (bank 1). */
#define TX_PHY_REG_39    0x39
#define TX_PHY_REG_9C    0x9c
#define TX_PHY_REG_B0    0xb0
#define TX_PHY_REG_B7    0xb7
#define TX_PHY_REG_C0    0xc0
#define TX_PHY_REG_C2    0xc2
#define TX_PHY_REG_C3    0xc3
#define TX_PHY_REG_C5    0xc5
#define TX_PHY_REG_C6    0xc6
#define TX_PHY_REG_C7    0xc7
#define TX_PHY_REG_C9    0xc9

#define MODE_RATE_5_UP   1              /* mode: the FRL rate is 5 or more */

/*
 * Switch the PHY of an HDMI transmitter on or off by a fixed sequence of bank-1 register writes.
 *
 *   port  the HDMI TX port
 *   on    not 0: power-up sequence; 0: power-down sequence
 *   mode  power-up only: MODE_RATE_5_UP sets bit 1 and clears bit 2 of register 0xC6, any other value the
 *         other way round
 *
 * Called by hdmi_tx_phy_switch_power (TX set-up step 7, with on = 1 only for an FRL link above rate 3, and
 * mode = 1 from FRL rate 5) and with on = 0, mode = 0 by hdmi_tx_phy_power_down.
 *
 * Power-down clears bit 5 of 0x9C, bit 4 of 0xC6 and bits 2 and 3 of 0xC5, waits, sets bit 1 of 0xC7 and
 * clears bits 0..2 of 0xC6, waits, then clears bit 3 of 0xC6 and bit 5 of 0x39. It leaves the values the
 * power-up writes to 0xC9, 0x9C bits 0..2, 0xC6 bits 5..7, 0xC3, 0xC2, 0xC0, 0xB7 and 0xB0 as they are.
 * Every wait is one long delay unit (timer_delay_long_units(1)).
 */
void hdmi_tx_phy_set_power(unsigned char port, unsigned char on, unsigned char mode)
{
    unsigned char value;

    if (on) {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 8, BITS_SET);
        timer_delay_long_units(1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C7, 2, BITS_CLEAR);
        /* Bits 1..3 of 0xC9 = 3. */
        value = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C9);
        value &= ~0xe;
        value |= 6;
        value &= ~8;
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C9, value);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 1, BITS_SET);
        if (mode == MODE_RATE_5_UP) {
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 2, BITS_SET);
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 4, BITS_CLEAR);
        } else {
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 2, BITS_CLEAR);
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 4, BITS_SET);
        }
        timer_delay_long_units(1);
        /* Bits 5..7 of 0xC6 = 4. */
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, (hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6) & 0x1f) | 0x80);
        timer_delay_long_units(1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 0x10, BITS_SET);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C5, 4, BITS_SET);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C5, 8, BITS_SET);
        /* Bits 0..2 of 0x9C = 3. */
        value = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_9C);
        value &= ~7;
        value |= 3;
        value &= ~4;
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_9C, value);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_9C, 0x20, BITS_SET);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_39, 0x20, BITS_SET);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C3, 0x1c);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C2, 0x3a);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C0, 1, BITS_SET);
        /* Bits 0..2 of 0xB7 = 3. */
        value = hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_B7);
        value &= ~7;
        value |= 3;
        value &= ~4;
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_PHY, TX_PHY_REG_B7, value);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_B0, 0x20, BITS_SET);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_B0, 0x10, BITS_SET);
    } else {
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_9C, 0x20, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 0x10, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C5, 4, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C5, 8, BITS_CLEAR);
        timer_delay_long_units(1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C7, 2, BITS_SET);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 1, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 2, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 4, BITS_CLEAR);
        timer_delay_long_units(1);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_C6, 8, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, TX_PHY_REG_39, 0x20, BITS_CLEAR);
    }
}
