/* audio_configure  (FUN_a008cba8)
 *
 * Store the 3-byte audio configuration and initialise the audio block with it.
 *   config_bytes: 3 configuration bytes
 * Name basis: derived - mailbox command 0x90; runs the audio register initialisers and routes source 1 to
 *   output 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008cba8 @ 0xa008cba8-0xa008ced8 (204 words), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the copy is a memcpy call (lib_memcpy, declared with that link name);
 *  - byte 0 is read once into the unsigned int local byte0 for the first two tests, and again from
 *    audio_config for the later ones;
 *  - case 2 is written before case 1 in the first switch;
 *  - the second switch lists case 0 with the same calls as the default (value 3): the compare tree at
 *    0xa008ce00 has root 1 (a case 0 node, 'ble' to the block at 0xa008ce78), and the case 2 test at 0xa008ce10
 *    also branches to that default block.
 */
extern unsigned char audio_config[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern void audio_set_shared_enable_bits(unsigned char);
extern void audio_init_main_registers(void);
extern void audio_init_register_groups(void);
extern void audio_init_ctrl_registers(void);
extern void audio_route_source(unsigned char, unsigned char, unsigned char, unsigned char);
extern void audio_reg_write8(unsigned char unit, unsigned char reg, unsigned char val);
extern void audio_set_config_bit6(unsigned char);
extern void audio_clear_main_enable(void);
extern void dp_set_mode_registers(unsigned char, unsigned char);
extern void hdmi_rx21_set_audio_reg9_bit21(unsigned char, unsigned char);
extern void audio_set_hdmi_rx_reg126_bit5(unsigned char, unsigned char);
extern void dp_set_reg55_bits(unsigned char, unsigned char);
extern void hdmi_rx21_set_audio_mode_bits(unsigned char, unsigned char);
extern void audio_set_hdmi_rx_reg126_mode(unsigned char, unsigned char);
extern void audio_reset_output_regs(void);

#define REG(a) (*(volatile unsigned int *)(a))

/* The three configuration bytes (audio_config[0..2]). */
#define AUDIO_CONFIG_SIZE        3
#define CFG0_REGS_1140           0x80   /* byte 0: write the registers 0xCF011140..0xCF011158 */
#define CFG0_CALL_BIT6_0         0x40   /* byte 0: audio_set_config_bit6(0), which writes nothing */
#define CFG0_CALL_BIT6_1         0x20   /* byte 0: audio_set_config_bit6(1): 0x40 into reg_audio_config */
#define CFG0_SOURCE3_REGS        0x18   /* byte 0: set up the source 3 / 0x13 registers 0xCF0111D4..EC */
#define CFG1_MODE_SHIFT          6      /* byte 1 bits 6..7: receiver mode, also the unit mode of DP sources */
#define CFG1_MODE2_SHIFT         4      /* byte 1 bits 4..5: second receiver mode */
#define CFG2_OUTPUT0             1      /* byte 2: main audio registers on; audio_set_mute mutes output 0 */

#define AUDIO_SRC_1              1      /* audio source id 1 (as in audio_set_source_enable) */
#define AUDIO_OUTPUT_0           0
#define AUDIO_UNIT_0             0
#define ALL_SHARED_ENABLE_BITS   4      /* audio_set_shared_enable_bits: bits 4..7 at once */
#define LAST_AUDIO_UNIT          3
#define BOTH_RECEIVERS           2      /* receiver argument of the DP and HDMI 2.0 helpers */

/*
 * Mailbox command 0x90: keep the audio configuration and bring the audio block up with it.
 *
 *   config_bytes  the three configuration bytes of the command
 *
 * The only sender is audio_init_config in the main program (from System_Initialize). It sends byte 0 = 0x01,
 * byte 2 = 1 and byte 1 with bits 6..7 = 0 (bits 0..5 of byte 1 are not set by the sender). With those values
 * none of the byte 0 branches below runs, the main audio registers are loaded a second time, and the switch on
 * byte 1 bits 6..7 takes its default; the switch on bits 4..5 depends on bits the sender leaves unset.
 *
 * Phases:
 *  1. Keep the bytes in audio_config (audio_set_mute and audio_setup_unit read them later).
 *  2. Fixed start-up: all shared enable bits, the main, group and control audio registers, then route source 1
 *     to output 0 through unit 0, and registers 4..6 of all four units = 0x95, 0x18, 4.
 *  3. Byte 0 options (see the CFG0_* bits).
 *  4. Byte 2 bit 0: main audio registers loaded again, or the main enable cleared.
 *  5. Byte 1 bits 6..7 and bits 4..5: one mode (0, 1 or 2) each, passed to the DP receivers, the HDMI 2.1
 *     receivers and the HDMI 2.0 receivers. Field value 1 gives mode 1 and value 2 mode 2 for bits 6..7, but
 *     the other way round for bits 4..5; value 0 and 3 give mode 0.
 *  6. Reset the output registers; keep bits 0..3 of register 0xCF014770 and set bit 6.
 */
void audio_configure(const void *config_bytes)
{
    unsigned char unit;
    unsigned int byte0;

    /* 1. */
    memcpy(audio_config, config_bytes, AUDIO_CONFIG_SIZE);

    /* 2. */
    audio_set_shared_enable_bits(ALL_SHARED_ENABLE_BITS);
    audio_init_main_registers();
    audio_init_register_groups();
    audio_init_ctrl_registers();
    audio_route_source(AUDIO_SRC_1, AUDIO_OUTPUT_0, AUDIO_UNIT_0, 1);
    for (unit = 0; unit <= LAST_AUDIO_UNIT; unit++) {
        audio_reg_write8(unit, 4, 0x95);
        audio_reg_write8(unit, 5, 0x18);
        audio_reg_write8(unit, 6, 4);
    }

    /* 3. */
    byte0 = audio_config[0];
    if (byte0 & CFG0_REGS_1140) {
        REG(0xcf011148) = 7;
        REG(0xcf011140) = 3;
        REG(0xcf011144) = 8;
        REG(0xcf011154) = 0;
        REG(0xcf011158) = 0xff;
    }
    if (byte0 & CFG0_CALL_BIT6_0)
        audio_set_config_bit6(0);
    if (audio_config[0] & CFG0_CALL_BIT6_1)
        audio_set_config_bit6(1);
    if (audio_config[0] & CFG0_SOURCE3_REGS) {
        REG(0xcf0111d4) &= ~1;          /* the source 3 variant (not 0x13) */
        REG(0xcf0111d4) |= 0x20;
        REG(0xcf0111d8) |= 0x20;
        REG(0xcf0111dc) = 0x87;
        REG(0xcf011118) |= 1;
        REG(0xcf011118) &= ~1;
        REG(0xcf0111e8) = 0;
        REG(0xcf0111ec) = 0xff;
        REG(0xcf0111e4) = 3;
    }

    /* 4. */
    if (audio_config[2] & CFG2_OUTPUT0)
        audio_init_main_registers();
    else
        audio_clear_main_enable();

    /* 5. */
    switch (audio_config[1] >> CFG1_MODE_SHIFT) {
    case 2:
        dp_set_mode_registers(BOTH_RECEIVERS, 2);
        hdmi_rx21_set_audio_reg9_bit21(0, 1);
        hdmi_rx21_set_audio_reg9_bit21(1, 1);
        audio_set_hdmi_rx_reg126_bit5(BOTH_RECEIVERS, 1);
        break;
    case 1:
        dp_set_mode_registers(BOTH_RECEIVERS, 1);
        hdmi_rx21_set_audio_reg9_bit21(0, 1);
        hdmi_rx21_set_audio_reg9_bit21(1, 1);
        audio_set_hdmi_rx_reg126_bit5(BOTH_RECEIVERS, 1);
        break;
    default:
        dp_set_mode_registers(BOTH_RECEIVERS, 0);
        hdmi_rx21_set_audio_reg9_bit21(0, 0);
        hdmi_rx21_set_audio_reg9_bit21(1, 0);
        audio_set_hdmi_rx_reg126_bit5(BOTH_RECEIVERS, 0);
        break;
    }
    switch ((audio_config[1] >> CFG1_MODE2_SHIFT) & 3) {
    case 1:
        dp_set_reg55_bits(BOTH_RECEIVERS, 2);
        hdmi_rx21_set_audio_mode_bits(0, 2);
        hdmi_rx21_set_audio_mode_bits(1, 2);
        audio_set_hdmi_rx_reg126_mode(BOTH_RECEIVERS, 2);
        break;
    case 2:
        dp_set_reg55_bits(BOTH_RECEIVERS, 1);
        hdmi_rx21_set_audio_mode_bits(0, 1);
        hdmi_rx21_set_audio_mode_bits(1, 1);
        audio_set_hdmi_rx_reg126_mode(BOTH_RECEIVERS, 1);
        break;
    case 0:
        dp_set_reg55_bits(BOTH_RECEIVERS, 0);
        hdmi_rx21_set_audio_mode_bits(0, 0);
        hdmi_rx21_set_audio_mode_bits(1, 0);
        audio_set_hdmi_rx_reg126_mode(BOTH_RECEIVERS, 0);
        break;
    default:
        dp_set_reg55_bits(BOTH_RECEIVERS, 0);
        hdmi_rx21_set_audio_mode_bits(0, 0);
        hdmi_rx21_set_audio_mode_bits(1, 0);
        audio_set_hdmi_rx_reg126_mode(BOTH_RECEIVERS, 0);
        break;
    }

    /* 6. */
    audio_reset_output_regs();
    REG(0xcf014770) &= 0xf;
    REG(0xcf014770) |= 0x40;
}
