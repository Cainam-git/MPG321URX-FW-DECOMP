/* panel_level_gen_step_to_target  (FUN_a0129c64)
 *
 * Step the generator level towards its target and select the matching table entry.
 * Name basis: descriptive - level byte at 0xA802A448 towards the scaled target at 0xA802A449; waits for a
 *   frame; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129c64 @ 0xa0129c64-0xa0129edc (158 words), flags -mcpu=v8 -O3 -g.
 * Source form: the target assignment is written out in each of the three arms (blur mode 1, 2, other). The
 * table search is the same code as in panel_level_gen_set_target (two counting loops, then the "at most 0x18"
 * test after both).
 */
/* The part of the system configuration record (sys_config, docs/RECORDS.md) that is read here. */
struct sys_config_record {
    unsigned char pad00[8];
    unsigned char brightness;           /* +0x08: the brightness setting stored by panel_api_set_brightness */
    unsigned char pad09[0x38 - 9];
    unsigned int blurfree_mode;         /* +0x38: the blur-reduction mode (1 = GEN1, 2 = GEN2, else off) */
};

/* The brightness setting is converted as in panel_api_set_brightness: (brightness * scale + 50) / 100 + 126,
   with the scale 607 (0x25F) in both blur-reduction modes and 897 (0x381) otherwise. The generator takes a
   quarter of that value. */
#define BLURFREE_GEN1               1
#define BLURFREE_GEN2               2
#define BRIGHTNESS_SCALE_BLURFREE   607u
#define BRIGHTNESS_SCALE_OFF        897u
#define BRIGHTNESS_OFFSET           126
#define LEVEL_DIVIDER               4

/* The byte at 0xA802CA03 is set to 126 (the brightness offset) before each use; it is the level written to the
   generator, while the stepped value is written as the companion byte (panel_level_gen_set_level_pair). */
#define LEVEL_BASE                  0x7e

/* Entries 0x18..0x3F of the 128-byte table panel_level_gen_levels are searched for the level read back. */
#define LEVEL_INDEX_MIN             0x18
#define LEVEL_INDEX_MAX             0x3f

extern struct sys_config_record sys_config;
extern unsigned char panel_level_gen_level, panel_level_gen_target, panel_level_gen_index, panel_level_gen_last_value;
extern unsigned char panel_level_gen_flags, panel_level_gen_min_level;
extern const unsigned char panel_level_gen_levels[];
extern void panel_level_gen_set_level_pair(unsigned int, unsigned int);
extern void panel_level_gen_set_reg_110_copy(unsigned int);
extern void panel_level_gen_set_reg_114_copy(unsigned int);
extern unsigned int panel_level_gen_get_min_level(void);
extern void panel_wait_sync_pulse(void);

#define STEP_DOWN_PERCENT   85      /* share of the target used while bit 0 of the byte at 0xA802CA02 is clear */

/*
 * Move the level generator's level one step towards its goal and re-select the table entry for the level the
 * generator then reports. No parameters, no return value. Nothing calls this routine by name.
 *
 * The goal: the target (panel_level_gen_target) is recomputed from the brightness setting and the blur-reduction
 * mode, as panel_level_gen_set_target does. The goal level is the target itself when bit 0 of the byte at
 * 0xA802CA02 is set (panel_level_gen_set_target sets that byte to 0x81), else 85 percent of the target; it is
 * never below 126 (LEVEL_BASE).
 *
 * When panel_level_gen_level already equals the goal, nothing more happens. Otherwise it moves by 1 towards
 * the goal, and the generator gets LEVEL_BASE as its level and the stepped value as the companion byte. The
 * level register is then read back (read_back_level) and the table entry is chosen:
 *   - read_back_level above panel_level_gen_last_value: count up from panel_level_gen_index to 0x3F and store the
 *     first index whose table entry is at least read_back_level;
 *   - otherwise count down from panel_level_gen_index to 0x18 and store the index above the first entry that is
 *     below read_back_level;
 *   - the stored index is never below 0x18.
 * The index times 4 goes to both registers 0xCF016110 and 0xCF016114, read_back_level is kept as
 * panel_level_gen_last_value, and the routine waits for one sync pulse of the panel.
 */
void panel_level_gen_step_to_target(void)
{
    unsigned char read_back_level, table_index, goal_level;

    if (sys_config.blurfree_mode == BLURFREE_GEN1)
        panel_level_gen_target = ((sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET) / LEVEL_DIVIDER;
    else if (sys_config.blurfree_mode == BLURFREE_GEN2)
        panel_level_gen_target = ((sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET) / LEVEL_DIVIDER;
    else
        panel_level_gen_target = ((sys_config.brightness * BRIGHTNESS_SCALE_OFF + 50) / 100 + BRIGHTNESS_OFFSET) / LEVEL_DIVIDER;
    panel_level_gen_min_level = LEVEL_BASE;
    if (panel_level_gen_flags & 1)
        goal_level = panel_level_gen_target;
    else
        goal_level = panel_level_gen_target * STEP_DOWN_PERCENT / 100;
    if (goal_level < panel_level_gen_min_level)
        goal_level = panel_level_gen_min_level;
    if (panel_level_gen_level == goal_level)
        return;
    if (panel_level_gen_level > goal_level)
        panel_level_gen_level--;
    else
        panel_level_gen_level++;
    panel_level_gen_set_level_pair(panel_level_gen_min_level, panel_level_gen_level);
    read_back_level = panel_level_gen_get_min_level();
    if (read_back_level > panel_level_gen_last_value) {
        for (table_index = panel_level_gen_index; table_index <= LEVEL_INDEX_MAX; table_index++)
            if (panel_level_gen_levels[table_index] >= read_back_level) {
                panel_level_gen_index = table_index;
                break;
            }
    } else {
        for (table_index = panel_level_gen_index; table_index > LEVEL_INDEX_MIN - 1; table_index--)
            if (panel_level_gen_levels[table_index] < read_back_level) {
                panel_level_gen_index = table_index + 1;
                break;
            }
    }
    if (table_index <= LEVEL_INDEX_MIN)
        panel_level_gen_index = LEVEL_INDEX_MIN;
    panel_level_gen_set_reg_110_copy((unsigned char)(panel_level_gen_index << 2));
    panel_level_gen_set_reg_114_copy((unsigned char)(panel_level_gen_index << 2));
    panel_level_gen_last_value = read_back_level;
    panel_wait_sync_pulse();
}
