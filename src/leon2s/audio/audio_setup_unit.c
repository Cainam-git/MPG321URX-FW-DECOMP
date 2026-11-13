/* audio_setup_unit  (FUN_a008bddc)
 *
 * Program an audio unit for the type of source assigned to it.
 *   source: audio source id (4/6 DP, 8/10 HDMI 2.0, 12/14 HDMI 2.1)
 *   unit: audio unit
 * Name basis: derived - per-source register sequences; caller audio_route_source
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008bddc @ 0xa008bddc (-mcpu=v8 -Os -g)
 * Source forms the exact build depends on:
 *  - set_unit_mode_for_source is a static helper with unsigned char parameters (GCC inlines it); its inner test
 *    is a switch listing case 2 before case 1, and cases 3 and 0x13 are separate (more than three case bodies
 *    keep the jump table);
 *  - both switches compile to jump tables;
 *  - shared_lock_take is the same inline helper as in audio_set_shared_enable_bits; every take has its own
 *    release.
 */

/* Audio source ids (as in audio_set_source_enable). Sources 5 and 7 share the unit field of 4 and 6. */
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

/* Lock register shared between the two processors: this program claims it by writing 2. */
#define SHARED_LOCK (*(volatile unsigned int *)0xcf03c840)
#define LOCK_FREE      0
#define LOCK_BUSY      1        /* held by the other processor */
#define LOCK_HELD_HERE 2

#define AUDIO_SHARED_ENABLE_REG (*(volatile unsigned int *)0xcf012444)   /* bit 4 + unit = that unit's enable bit */
#define AUDIO_UNIT_SOURCE_REG01 (*(volatile unsigned int *)0xcf011240)   /* low nibble unit 0, high nibble unit 1 */
#define AUDIO_UNIT_SOURCE_REG23 (*(volatile unsigned int *)0xcf011244)   /* low nibble unit 2, high nibble unit 3 */

/* Byte registers of an audio unit (audio_reg_*). */
#define UNIT_REG_0      0
#define UNIT_REG_1      1
#define UNIT_REG_2      2       /* bits 0..1 = unit mode (audio_set_unit_mode) */
#define UNIT_REG_3      3
#define UNIT_REG_7      7

#define DP_REG_51       0x51    /* DP receiver register; bit 0 tested before the second write group */

extern unsigned char audio_config_byte_1;
extern void audio_set_unit_mode(unsigned char unit, unsigned char mode);
extern void audio_reg_write_masked(unsigned char unit, unsigned char reg, unsigned char mask, unsigned char val);
extern void audio_reg_write8(unsigned char unit, unsigned char reg, unsigned char val);
extern unsigned char audio_reg_read8(unsigned char unit, unsigned char reg);
extern unsigned char audio_is_source_selected(unsigned char source);
extern unsigned int dp_reg_read8(unsigned char a, unsigned short b);

/* Take the shared lock: up to 0x10000 tries, each claiming it unless it reads LOCK_BUSY, until it reads
   LOCK_HELD_HERE; then it is claimed once more whatever the outcome. */
static inline void shared_lock_take(void)
{
    unsigned short tries = 0xffff;

    do {
        if (SHARED_LOCK != LOCK_BUSY)
            SHARED_LOCK = LOCK_HELD_HERE;
        if (SHARED_LOCK == LOCK_HELD_HERE)
            break;
        tries--;
    } while (tries != 0xffff);
    SHARED_LOCK = LOCK_HELD_HERE;
}

/* Phase 1: the unit mode (0..3) that belongs to the source. For DP-type sources 4..7 it comes from bits 6..7
   of the audio configuration's byte 1: 1 gives mode 2, 2 gives mode 0, anything else mode 1. */
static void set_unit_mode_for_source(unsigned char source, unsigned char unit)
{
    switch (source) {
    case AUDIO_SRC_DP0:
    case AUDIO_SRC_5:
    case AUDIO_SRC_DP1:
    case AUDIO_SRC_7:
        switch (audio_config_byte_1 >> 6) {
        case 2:
            audio_set_unit_mode(unit, 0);
            break;
        case 1:
            audio_set_unit_mode(unit, 2);
            break;
        default:
            audio_set_unit_mode(unit, 1);
            break;
        }
        break;
    case AUDIO_SRC_2:
    case AUDIO_SRC_HDMI0:
    case AUDIO_SRC_HDMI1:
    case AUDIO_SRC_HDMI21_0:
    case AUDIO_SRC_HDMI21_1:
        audio_set_unit_mode(unit, 1);
        break;
    case AUDIO_SRC_3:
        audio_set_unit_mode(unit, 3);
        break;
    case AUDIO_SRC_3_ALT:
        audio_set_unit_mode(unit, 3);
        break;
    }
}

/*
 * Set up one audio unit (0..3) for the source that has just been assigned to it.
 *
 *   source  audio source id (AUDIO_SRC_*)
 *   unit    audio unit 0..3
 *
 * Called by audio_route_source (mailbox command 0x92) right after the source has been assigned to the unit.
 *
 * Phases:
 *  1. Set the unit mode for the source type (set_unit_mode_for_source); sources 1 / 0x11 leave it as it is.
 *  2. Clear bits 2, 3 and 5 of unit register 2.
 *  3. Write the register sequence of the source type:
 *     - DP sources 4..7: one group of writes to unit registers 7, 2 and 0, then registers 1 and 3. For the
 *       two DP receivers (4, 6) the group after the first write is repeated when the source is set in the
 *       audio select registers (audio_is_source_selected) and bit 0 of the receiver's register 0x51 is set;
 *     - HDMI sources (8, 10, 0xC, 0xE): the unit's writes, then the source id goes into the unit's nibble of
 *       AUDIO_UNIT_SOURCE_REG01 / 23;
 *     - source 2 and sources 3 / 0x13: fixed values into registers 8..10 and 12..14, then bit 6 of register 2 pulsed
 *       (cleared, set, cleared); source 2 also pulses bit 7 of register 7 (cleared, set);
 *     - sources 1 / 0x11: the unit's enable bit in AUDIO_SHARED_ENABLE_REG set, cleared and set again, each
 *       under the shared lock, then registers 4..6 get 0x95, 0x18, 4 (the values audio_configure writes into
 *       all four units) and register 1 gets 0x68.
 *  Other source ids get only phases 1 and 2.
 */
void audio_setup_unit(unsigned char source, unsigned char unit)
{
    unsigned char value;

    /* 1, 2. */
    set_unit_mode_for_source(source, unit);
    audio_reg_write_masked(unit, UNIT_REG_2, 0x2c, 0);

    /* 3. */
    switch (source) {
    case AUDIO_SRC_DP0:
        audio_reg_write_masked(unit, UNIT_REG_7, 0x40, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x80, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x10, 0);
        audio_reg_write_masked(unit, UNIT_REG_2, 8, 8);
        audio_reg_write_masked(unit, UNIT_REG_0, 1, 1);
        if (audio_is_source_selected(source) && (dp_reg_read8(0, DP_REG_51) & 1)) {
            audio_reg_write_masked(unit, UNIT_REG_7, 0x80, 0);
            audio_reg_write_masked(unit, UNIT_REG_7, 0x10, 0);
            audio_reg_write_masked(unit, UNIT_REG_2, 8, 8);
            audio_reg_write_masked(unit, UNIT_REG_0, 1, 1);
        }
        audio_reg_write_masked(unit, UNIT_REG_1, 0x40, 0x40);
        audio_reg_write8(unit, UNIT_REG_3, 0x12);
        break;
    case AUDIO_SRC_5:
    case AUDIO_SRC_7:
        audio_reg_write_masked(unit, UNIT_REG_7, 0x40, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x80, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x10, 0);
        audio_reg_write_masked(unit, UNIT_REG_2, 8, 8);
        audio_reg_write_masked(unit, UNIT_REG_0, 1, 1);
        audio_reg_write_masked(unit, UNIT_REG_1, 0x40, 0x40);
        audio_reg_write8(unit, UNIT_REG_3, 0x12);
        break;
    case AUDIO_SRC_DP1:
        audio_reg_write_masked(unit, UNIT_REG_7, 0x40, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x80, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x10, 0);
        audio_reg_write_masked(unit, UNIT_REG_2, 8, 8);
        audio_reg_write_masked(unit, UNIT_REG_0, 1, 1);
        if (audio_is_source_selected(source) && (dp_reg_read8(1, DP_REG_51) & 1)) {
            audio_reg_write_masked(unit, UNIT_REG_7, 0x80, 0);
            audio_reg_write_masked(unit, UNIT_REG_7, 0x10, 0);
            audio_reg_write_masked(unit, UNIT_REG_2, 8, 8);
            audio_reg_write_masked(unit, UNIT_REG_0, 1, 1);
        }
        audio_reg_write_masked(unit, UNIT_REG_1, 0x40, 0x40);
        audio_reg_write8(unit, UNIT_REG_3, 0x12);
        break;
    case AUDIO_SRC_HDMI0:
    case AUDIO_SRC_HDMI1:
    case AUDIO_SRC_HDMI21_0:
    case AUDIO_SRC_HDMI21_1:
        audio_reg_write_masked(unit, UNIT_REG_7, 0x40, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x10, 0x10);
        audio_reg_write_masked(unit, UNIT_REG_0, 1, 0);
        audio_reg_write_masked(unit, UNIT_REG_1, 0x40, 0x40);
        audio_reg_write8(unit, UNIT_REG_3, 0x1a);
        /* Record the source id in the unit's nibble. */
        switch (unit) {
        case 0:
            AUDIO_UNIT_SOURCE_REG01 = (AUDIO_UNIT_SOURCE_REG01 & 0xf0) | (source & 0xf);
            break;
        case 1:
            AUDIO_UNIT_SOURCE_REG01 = (AUDIO_UNIT_SOURCE_REG01 & 0xf) | ((source & 0xf) << 4);
            break;
        case 2:
            AUDIO_UNIT_SOURCE_REG23 = (AUDIO_UNIT_SOURCE_REG23 & 0xf0) | (source & 0xf);
            break;
        case 3:
            AUDIO_UNIT_SOURCE_REG23 = (AUDIO_UNIT_SOURCE_REG23 & 0xf) | ((source & 0xf) << 4);
            break;
        }
        break;
    case AUDIO_SRC_2:
        audio_reg_write_masked(unit, UNIT_REG_7, 0x40, 0);
        audio_reg_write_masked(unit, UNIT_REG_0, 1, 0);
        audio_reg_write_masked(unit, UNIT_REG_2, 0x24, 0x24);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x80, 0x80);
        audio_reg_write8(unit, 8, 0);
        audio_reg_write8(unit, 9, 4);
        audio_reg_write8(unit, 10, 0);
        audio_reg_write8(unit, 12, 0);
        audio_reg_write8(unit, 13, 1);
        audio_reg_write8(unit, 14, 0);
        audio_reg_write8(unit, UNIT_REG_3, 0x1a);
        /* Pulse bit 6 of register 2, then bit 7 of register 7. */
        value = audio_reg_read8(unit, UNIT_REG_2);
        audio_reg_write8(unit, UNIT_REG_2, value & 0xbf);
        audio_reg_write8(unit, UNIT_REG_2, value | 0x40);
        audio_reg_write8(unit, UNIT_REG_2, value & 0xbf);
        value = audio_reg_read8(unit, UNIT_REG_7);
        audio_reg_write8(unit, UNIT_REG_7, value & 0x7f);
        audio_reg_write8(unit, UNIT_REG_7, value | 0x80);
        break;
    case AUDIO_SRC_1:
    case AUDIO_SRC_1_ALT:
        audio_reg_write_masked(unit, UNIT_REG_7, 0x40, 0);
        audio_reg_write_masked(unit, UNIT_REG_0, 1, 0);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x10, 0);
        audio_reg_write8(unit, UNIT_REG_3, 2);
        audio_reg_write_masked(unit, UNIT_REG_7, 0x80, 0);
        /* The enable register is shared with the other processor: set, clear, set the unit's bit, each
           under the lock. */
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG |= 1 << (unit + 4);
        SHARED_LOCK = LOCK_FREE;
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG &= ~(1 << (unit + 4));
        SHARED_LOCK = LOCK_FREE;
        shared_lock_take();
        AUDIO_SHARED_ENABLE_REG |= 1 << (unit + 4);
        SHARED_LOCK = LOCK_FREE;
        audio_reg_write8(unit, 4, 0x95);
        audio_reg_write8(unit, 5, 0x18);
        audio_reg_write8(unit, 6, 4);
        audio_reg_write8(unit, UNIT_REG_1, 0x68);
        break;
    case AUDIO_SRC_3:
    case AUDIO_SRC_3_ALT:
        audio_reg_write8(unit, UNIT_REG_3, 0x1a);
        audio_reg_write_masked(unit, UNIT_REG_2, 0x24, 0x24);
        audio_reg_write8(unit, UNIT_REG_7, 0x40);
        audio_reg_write8(unit, 8, 0);
        audio_reg_write8(unit, 9, 0x80);
        audio_reg_write8(unit, 10, 0);
        audio_reg_write8(unit, 12, 0);
        audio_reg_write8(unit, 13, 1);
        audio_reg_write8(unit, 14, 0);
        /* Pulse bit 6 of register 2. */
        value = audio_reg_read8(unit, UNIT_REG_2);
        audio_reg_write8(unit, UNIT_REG_2, value & 0xbf);
        audio_reg_write8(unit, UNIT_REG_2, value | 0x40);
        audio_reg_write8(unit, UNIT_REG_2, value & 0xbf);
        break;
    }
}
