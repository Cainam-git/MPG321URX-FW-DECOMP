/* audio_set_source_enable  (FUN_a008ae80)
 *
 * Switch the audio capture of one source on or off.
 *   source: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 *   enable: 1 = on
 * Name basis: derived - per-source register writes in the receivers (DP 0x55/0x58/0x5A bit 7, HDMI
 *   0x127/0x129)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008ae80 @ 0xa008ae80 (-mcpu=v8 -Os -g)
 * Source form: the switch compiles to a jump table (sources 1..0x13); the case bodies are listed in the order
 * 3, 0x13, 1, 0x11, 2, 8, 10, 0xC, 0xE, 4, 6, and each case writes its full sequence (GCC shares the common
 * tails).
 */

/* Audio source ids (the numbers audio_route_source and the audio select registers use). */
enum {
    AUDIO_SRC_1        = 1,
    AUDIO_SRC_2        = 2,
    AUDIO_SRC_3        = 3,
    AUDIO_SRC_DP0      = 4,     /* DP receiver 0 */
    AUDIO_SRC_DP1      = 6,     /* DP receiver 1 */
    AUDIO_SRC_HDMI0    = 8,     /* HDMI 2.0 receiver 0 */
    AUDIO_SRC_HDMI1    = 10,    /* HDMI 2.0 receiver 1 */
    AUDIO_SRC_HDMI21_0 = 0xc,   /* HDMI 2.1 receiver 0 */
    AUDIO_SRC_HDMI21_1 = 0xe,   /* HDMI 2.1 receiver 1 */
    AUDIO_SRC_1_ALT    = 0x11,  /* variant of source 1 */
    AUDIO_SRC_3_ALT    = 0x13   /* variant of source 3 */
};

/* Registers of the audio routing block. */
#define AUDIO_REG_10C0       (*(volatile unsigned int *)0xcf0110c0)    /* 0xF4 for source 1, 0xF2 for source 0x11 */
#define AUDIO_REG_1118       (*(volatile unsigned int *)0xcf011118)    /* bit 0 pulsed */
#define AUDIO_REG_1148       (*(volatile unsigned int *)0xcf011148)
#define AUDIO_SRC3_UNIT_REG  (*(volatile unsigned int *)0xcf0111d4)    /* bits 6..7 = unit of source 3 / 0x13; bit 0 = 0x13 variant */
#define AUDIO_REG_11DC       (*(volatile unsigned int *)0xcf0111dc)    /* bit 3 pulsed */

/* Receiver numbers of the register helpers. */
#define RX0 0
#define RX1 1

/* hdmi_reg_update_bits / dp_reg_update_bits: last argument 1 sets the bits, 0 clears them. */
#define BITS_SET   1
#define BITS_CLEAR 0

extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_rx21_set_audio_enable(unsigned char, unsigned char);
extern unsigned char dp_get_regc1_bit0(unsigned char);

/*
 * Switch the audio of one source on or off in the hardware it comes from.
 *
 *   source  audio source id (AUDIO_SRC_*)
 *   enable  1 = on, 0 = off
 *
 * Called by audio_route_source (mailbox command 0x92) as its first step, with that command's enable byte.
 *
 * What each source gets:
 *  - sources 3 / 0x13 (on only): bit 0 of AUDIO_SRC3_UNIT_REG cleared / set, then bit 0 of AUDIO_REG_1118 and
 *    bit 3 of AUDIO_REG_11DC pulsed, bit 7 of AUDIO_REG_1148 set;
 *  - sources 1 / 0x11 (on only): AUDIO_REG_10C0 = 0xF4 / 0xF2;
 *  - source 2 (on only): AUDIO_REG_1148 written 0, then 0x87;
 *  - HDMI 2.0 receivers: bits 4..5 of register 0x127 and bits 0..2 of register 0x129 follow 'enable', bit 1 of
 *    register 0x137 the opposite;
 *  - HDMI 2.1 receivers: hdmi_rx21_set_audio_enable;
 *  - DP receivers: bit 7 of registers 0x55, 0x58 and 0x5A follow 'enable'; on receiver 0, switching on also
 *    sets bit 4 of register 0x7D and register 0x7E to 0xFF when bit 0 of its register 0xC1 is set, else
 *    clears them.
 * Any other source id does nothing.
 */
void audio_set_source_enable(unsigned char source, unsigned char enable)
{
    switch (source) {
    case AUDIO_SRC_3:
        if (enable) {
            AUDIO_SRC3_UNIT_REG &= ~1;
            AUDIO_REG_1118 |= 1;
            AUDIO_REG_1118 &= ~1;
            AUDIO_REG_11DC |= 8;
            AUDIO_REG_11DC &= ~8;
            AUDIO_REG_1148 |= 0x80;
        }
        break;
    case AUDIO_SRC_3_ALT:
        if (enable) {
            AUDIO_SRC3_UNIT_REG |= 1;
            AUDIO_REG_1118 |= 1;
            AUDIO_REG_1118 &= ~1;
            AUDIO_REG_11DC |= 8;
            AUDIO_REG_11DC &= ~8;
            AUDIO_REG_1148 |= 0x80;
        }
        break;
    case AUDIO_SRC_1:
        if (enable)
            AUDIO_REG_10C0 = 0xf4;
        break;
    case AUDIO_SRC_1_ALT:
        if (enable)
            AUDIO_REG_10C0 = 0xf2;
        break;
    case AUDIO_SRC_2:
        if (enable) {
            AUDIO_REG_1148 = 0;
            AUDIO_REG_1148 = 0x87;
        }
        break;
    case AUDIO_SRC_HDMI0:
        if (enable) {
            hdmi_reg_update_bits(RX0, 0x127, 0x20, BITS_SET);
            hdmi_reg_update_bits(RX0, 0x127, 0x10, BITS_SET);
            hdmi_reg_update_bits(RX0, 0x129, 4, BITS_SET);
            hdmi_reg_update_bits(RX0, 0x129, 1, BITS_SET);
            hdmi_reg_update_bits(RX0, 0x129, 2, BITS_SET);
            hdmi_reg_update_bits(RX0, 0x137, 2, BITS_CLEAR);
        } else {
            hdmi_reg_update_bits(RX0, 0x127, 0x20, BITS_CLEAR);
            hdmi_reg_update_bits(RX0, 0x127, 0x10, BITS_CLEAR);
            hdmi_reg_update_bits(RX0, 0x129, 4, BITS_CLEAR);
            hdmi_reg_update_bits(RX0, 0x129, 1, BITS_CLEAR);
            hdmi_reg_update_bits(RX0, 0x129, 2, BITS_CLEAR);
            hdmi_reg_update_bits(RX0, 0x137, 2, BITS_SET);
        }
        break;
    case AUDIO_SRC_HDMI1:
        if (enable) {
            hdmi_reg_update_bits(RX1, 0x127, 0x20, BITS_SET);
            hdmi_reg_update_bits(RX1, 0x127, 0x10, BITS_SET);
            hdmi_reg_update_bits(RX1, 0x129, 4, BITS_SET);
            hdmi_reg_update_bits(RX1, 0x129, 1, BITS_SET);
            hdmi_reg_update_bits(RX1, 0x129, 2, BITS_SET);
            hdmi_reg_update_bits(RX1, 0x137, 2, BITS_CLEAR);
        } else {
            hdmi_reg_update_bits(RX1, 0x127, 0x20, BITS_CLEAR);
            hdmi_reg_update_bits(RX1, 0x127, 0x10, BITS_CLEAR);
            hdmi_reg_update_bits(RX1, 0x129, 4, BITS_CLEAR);
            hdmi_reg_update_bits(RX1, 0x129, 1, BITS_CLEAR);
            hdmi_reg_update_bits(RX1, 0x129, 2, BITS_CLEAR);
            hdmi_reg_update_bits(RX1, 0x137, 2, BITS_SET);
        }
        break;
    case AUDIO_SRC_HDMI21_0:
        hdmi_rx21_set_audio_enable(RX0, enable);
        break;
    case AUDIO_SRC_HDMI21_1:
        hdmi_rx21_set_audio_enable(RX1, enable);
        break;
    case AUDIO_SRC_DP0:
        if (enable) {
            dp_reg_update_bits(RX0, 0x55, 0x80, BITS_SET);
            dp_reg_update_bits(RX0, 0x58, 0x80, BITS_SET);
            dp_reg_update_bits(RX0, 0x5a, 0x80, BITS_SET);
            /* Registers 0x7D / 0x7E follow bit 0 of register 0xC1. */
            if (dp_get_regc1_bit0(RX0)) {
                dp_reg_update_bits(RX0, 0x7d, 0x10, BITS_SET);
                dp_reg_write8(RX0, 0x7e, 0xff);
            } else {
                dp_reg_update_bits(RX0, 0x7d, 0x10, BITS_CLEAR);
                dp_reg_write8(RX0, 0x7e, 0);
            }
        } else {
            dp_reg_update_bits(RX0, 0x55, 0x80, BITS_CLEAR);
            dp_reg_update_bits(RX0, 0x58, 0x80, BITS_CLEAR);
            dp_reg_update_bits(RX0, 0x5a, 0x80, BITS_CLEAR);
        }
        break;
    case AUDIO_SRC_DP1:
        if (enable) {
            dp_reg_update_bits(RX1, 0x55, 0x80, BITS_SET);
            dp_reg_update_bits(RX1, 0x58, 0x80, BITS_SET);
            dp_reg_update_bits(RX1, 0x5a, 0x80, BITS_SET);
        } else {
            dp_reg_update_bits(RX1, 0x55, 0x80, BITS_CLEAR);
            dp_reg_update_bits(RX1, 0x58, 0x80, BITS_CLEAR);
            dp_reg_update_bits(RX1, 0x5a, 0x80, BITS_CLEAR);
        }
        break;
    }
}
