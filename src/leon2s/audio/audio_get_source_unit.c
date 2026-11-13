/* audio_get_source_unit  (FUN_a008a040)
 *
 * Return the audio unit (0..3) a source is assigned to.
 *   src: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 * Returns: unit number or 0xFF
 * Name basis: derived - 2-bit fields of 0xCF0111C0..D4 per source, set by audio_set_source_unit; 0xFF for
 *   unknown sources
 *
 * Matching notes
 * --------------
 * FUN_a008a040 (leon2s 0xa008a040-0xa008a110, 208 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: every case stores into one unsigned int result that is returned as unsigned char (the default
 * case stores -1).
 */
/* Audio source ids (as in audio_set_source_enable). Sources 5 and 7 share the unit register of 4 and 6. */
enum {
    AUDIO_SRC_1        = 1,
    AUDIO_SRC_2        = 2,
    AUDIO_SRC_3        = 3,
    AUDIO_SRC_DP0      = 4,     /* DP receiver 0 */
    AUDIO_SRC_5        = 5,
    AUDIO_SRC_DP1      = 6,     /* DP receiver 1 */
    AUDIO_SRC_7        = 7,
    AUDIO_SRC_HDMI0    = 8,     /* HDMI 2.0 receiver 0 */
    AUDIO_SRC_HDMI1    = 10,    /* HDMI 2.0 receiver 1 */
    AUDIO_SRC_HDMI21_0 = 0xc,   /* HDMI 2.1 receiver 0 */
    AUDIO_SRC_HDMI21_1 = 0xe,   /* HDMI 2.1 receiver 1 */
    AUDIO_SRC_1_ALT    = 0x11,
    AUDIO_SRC_3_ALT    = 0x13
};

/* Registers that hold the unit number of the sources, one 2-bit field per source (written by audio_set_source_unit). */
#define UNIT_REG_11C0 (*(volatile unsigned int *)0xcf0111c0)    /* sources 1 / 0x11 (bits 6..7), 2 (bits 2..3) */
#define UNIT_REG_11C4 (*(volatile unsigned int *)0xcf0111c4)    /* sources 4 (bits 6..7), 5 (bits 2..3) */
#define UNIT_REG_11C8 (*(volatile unsigned int *)0xcf0111c8)    /* sources 6 (bits 6..7), 7 (bits 2..3) */
#define UNIT_REG_11CC (*(volatile unsigned int *)0xcf0111cc)    /* sources 8 (bits 6..7), 10 (bits 2..3) */
#define UNIT_REG_11D0 (*(volatile unsigned int *)0xcf0111d0)    /* sources 12 (bits 6..7), 14 (bits 2..3) */
#define UNIT_REG_11D4 (*(volatile unsigned int *)0xcf0111d4)    /* sources 3 / 0x13 (bits 6..7) */

/*
 * Return the audio unit (0..3) that audio source src is assigned to: the 2-bit field that audio_set_source_unit
 * wrote for it. Every source id has a fixed register and bit position (see the UNIT_REG_* list); any other id
 * returns 0xff.
 */
unsigned char audio_get_source_unit(unsigned char src)
{
    unsigned int unit;

    switch (src) {
    case AUDIO_SRC_1:
    case AUDIO_SRC_1_ALT:
        unit = (UNIT_REG_11C0 >> 6) & 3;
        break;
    case AUDIO_SRC_2:
        unit = (UNIT_REG_11C0 >> 2) & 3;
        break;
    case AUDIO_SRC_3:
    case AUDIO_SRC_3_ALT:
        unit = (UNIT_REG_11D4 >> 6) & 3;
        break;
    case AUDIO_SRC_DP0:
        unit = (UNIT_REG_11C4 >> 6) & 3;
        break;
    case AUDIO_SRC_5:
        unit = (UNIT_REG_11C4 >> 2) & 3;
        break;
    case AUDIO_SRC_DP1:
        unit = (UNIT_REG_11C8 >> 6) & 3;
        break;
    case AUDIO_SRC_7:
        unit = (UNIT_REG_11C8 >> 2) & 3;
        break;
    case AUDIO_SRC_HDMI0:
        unit = (UNIT_REG_11CC >> 6) & 3;
        break;
    case AUDIO_SRC_HDMI1:
        unit = (UNIT_REG_11CC >> 2) & 3;
        break;
    case AUDIO_SRC_HDMI21_0:
        unit = (UNIT_REG_11D0 >> 6) & 3;
        break;
    case AUDIO_SRC_HDMI21_1:
        unit = (UNIT_REG_11D0 >> 2) & 3;
        break;
    default:
        unit = -1;                  /* unknown source: returned as 0xff */
        break;
    }
    return unit;
}
