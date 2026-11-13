/* _hdmi21_Initialize  (hdmi21_Initialize)
 *
 * Initialise the HDMI 2.1 receiver hardware and both ports at start-up.
 * Returns: 0
 * Name basis: proven - original name printed ('[INIT]: %s' with '_hdmi21_Initialize'); runs
 *   hdmi_rx21_init_port per port
 *
 * Matching notes
 * --------------
 * hdmi21_Initialize (leon2s 0xa00a303c-0xa00a317c, 320 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on: the routine's name is a static string (routine_name) printed with
 * "%s"; the loop counter is initialised at its declaration and copied into port in the loop.
 */

#define HDMI_MSG_INIT_INFO      0x01    /* dbg_hdmi_message_flags bit 0: the "[INIT]" lines */

#define RX21_COUNT              2       /* HDMI 2.1 receivers */
#define PHY_REG_1F0C            0x1f0c
#define REG_1F0C_BIT8           8       /* tested on PHY 0: set skips the two hdmi_rx21_init_reg1_byte1 steps */
#define CHIP_REV_82             0x82    /* sys_get_chip_revision */
#define TICK_GROUP_0            0       /* first argument of sys_register_tick_hook */

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    volatile unsigned int *block1;
    volatile unsigned int *block2;
    volatile unsigned int *block3;
    unsigned int blocks_4_to_7[4];
    volatile unsigned int *block8;
    unsigned char blocks_9_to_12[0x34 - 0x24];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern int hdmi_rx21_init_reg1_byte1(unsigned char);
extern void hdmi_rx21_init_clear_reg2d_fields(void);
extern int hdmi_rx21_init_reg2d_bits(unsigned char);
extern int hdmi_rx21_init_audio_regs(void);
extern int hdmi_rx21_write_all_port_enables(unsigned char);
extern int hdmi_rx21_init_ctrl_bits_20_21(void);
extern int _hdmi_Init_Interrupt(void);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern void hdmi_rx21_init_port(unsigned int);
extern unsigned char sys_get_chip_revision(void);
extern void sys_register_tick_hook(unsigned int, void (*)(void));
extern void hdmi_rx21_poll_frl_rate_change(void);
static const char routine_name[] = "_hdmi21_Initialize";

/*
 * Start-up of the two HDMI 2.1 receivers.
 *
 * Returns 0.
 *
 * Order:
 *  1. Steps for both receivers: byte 1 of block 0 word 1 set to 0xFF (only while bit 8 of PHY register
 *     0x1F0C of PHY 0 is clear), the fields of control registers 0x2D / 0x2E cleared and the bits of 0x2D set
 *     (mode 1), the audio registers, byte 1 of block 0 word 1 set to 0x10 (same condition as before), the
 *     port enables on, control bits 20 and 21, and the interrupts (_hdmi_Init_Interrupt).
 *  2. Per receiver: block 0 word 2 bit 1 cleared, the low byte of block 3 register 0x50 set to 1, block 0
 *     word 1 bit 12 set, the port set up (hdmi_rx21_init_port), and 0x10000 written to block 8 register 0x3C.
 *  3. On chip revisions up to CHIP_REV_82 the FRL rate check of both receivers
 *     (hdmi_rx21_poll_frl_rate_change) is entered as a tick hook.
 */
int _hdmi21_Initialize(void)
{
    unsigned char i = 0;
    unsigned char port;

    if (dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO)
        dbg_printf("[INIT]: %s\n", routine_name);

    /* 1. Both receivers. */
    if (hdmi_phy_test_bit(REG_1F0C_BIT8, 0, PHY_REG_1F0C) == 0)
        hdmi_rx21_init_reg1_byte1(1);
    hdmi_rx21_init_clear_reg2d_fields();
    hdmi_rx21_init_reg2d_bits(1);
    hdmi_rx21_init_audio_regs();
    if (hdmi_phy_test_bit(REG_1F0C_BIT8, 0, PHY_REG_1F0C) == 0)
        hdmi_rx21_init_reg1_byte1(0);
    hdmi_rx21_write_all_port_enables(1);
    hdmi_rx21_init_ctrl_bits_20_21();
    _hdmi_Init_Interrupt();

    /* 2. Each receiver. */
    for (; i < RX21_COUNT; i++) {
        port = i;
        reg_clear_bit(1, hdmi_rx21_reg_blocks[port].block0 + 2);
        hdmi_rx21_reg_blocks[port].block3[0x50 / 4] = (hdmi_rx21_reg_blocks[port].block3[0x50 / 4] & ~0xff) | 1;
        reg_set_bit(0xc, hdmi_rx21_reg_blocks[port].block0 + 1);
        hdmi_rx21_init_port(port);
        hdmi_rx21_reg_blocks[port].block8[0x3c / 4] = 0x10000;
    }

    /* 3. Older chips only. */
    if (sys_get_chip_revision() <= CHIP_REV_82)
        sys_register_tick_hook(TICK_GROUP_0, hdmi_rx21_poll_frl_rate_change);
    return 0;
}
