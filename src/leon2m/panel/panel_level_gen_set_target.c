/* panel_level_gen_set_target  (FUN_a0129edc)
 *
 * Compute the generator's target level from a record and set the generator up for it.
 * Name basis: descriptive - scaled from byte 8 of the record; table search for the matching entry; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129edc @ 0xa0129edc-0xa012a128 (147 words), flags -mcpu=v8 -O3 -g.
 * Source form: the target assignment is written out in each of the three arms (blur mode 1, 2, other). The
 * table search is the same code as in panel_level_gen_step_to_target.
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
extern void panel_level_gen_set_enable(unsigned char);
extern void panel_level_gen_set_d8_low4(unsigned int);
extern void panel_level_gen_set_reg_104(unsigned int, int);
extern void panel_level_gen_set_level_pair(unsigned int, unsigned int);
extern void panel_level_gen_set_reg_110_copy(unsigned int);
extern void panel_level_gen_set_reg_114_copy(unsigned int);
extern void panel_level_gen_set_ctrl_high_bits(unsigned int);
extern void panel_level_gen_set_f4_upper_field(unsigned int);
extern void panel_level_gen_set_f4_bit4(unsigned int);
extern void panel_level_gen_set_reg_0c4(unsigned int, unsigned int);
extern unsigned int panel_level_gen_get_min_level(void);
extern unsigned char pq_block_is_blanked(unsigned char blk);
extern void panel_wait_sync_pulse(void);
extern void panel_level_gen_set_ctrl_bit0(void);
extern void sys_poll_events_stub_copy3();
extern void panel_level_gen_set_ctrl_bit1(void);
extern void panel_pwm_set_control_bit3(unsigned char ch, unsigned char b);

#define LEVEL_REG_110_START     0x40    /* first value of registers 0xCF016110 / 0xCF016114 */
#define PICTURE_BLOCK_8         8       /* picture block whose blanking decides the sync pulse wait */
#define PWM_CHANNEL_7           7       /* this routine passes channel 7: panel_pwm_set_control_bit3 writes nothing for it */
#define LEVEL_STATE_FLAGS       0x81    /* value stored at 0xA802CA02 at the end */

/*
 * Set the level generator up from the brightness setting: switch it off, compute its target level, load the
 * start values, choose the table entry, switch it on. No parameters, no return value. Nothing calls this
 * routine by name.
 *
 * Steps, in order:
 *   1. generator off (panel_level_gen_set_enable(0)), register 0xCF0160D8 low bits 0, register 0xCF016104 = 0;
 *   2. target = ((brightness * scale + 50) / 100 + 126) / 4 (the conversion of panel_api_set_brightness, with the
 *      scale chosen by the blur-reduction mode in sys_config), and the current level starts at the target;
 *   3. the generator gets LEVEL_BASE (126) as its level and the current level as the companion byte; registers
 *      0xCF016110 and 0xCF016114 get 0x40; control bits 4..7 = 8 with bit 3 set, register 0xCF0160F4 field = 1 and bit 4 = 1,
 *      register 0xCF0160C4 = (0, 1);
 *   4. the level register is read back and the table entry is chosen as in panel_level_gen_step_to_target
 *      (index kept in panel_level_gen_index, never below 0x18); the index times 4 goes to registers 0xCF016110 and
 *      0xCF016114 and the read-back value is kept as panel_level_gen_last_value;
 *   5. one wait for a sync pulse unless picture block 8 is blanked;
 *   6. control bit 0, then control bit 1 of the generator are set, and PWM control bit 3 of channel 7 is set
 *      (no register for that channel: nothing is written);
 *   7. the byte at 0xA802CA02 is set to 0x81.
 */
void panel_level_gen_set_target(void)
{
    unsigned char read_back_level, table_index;

    panel_level_gen_set_enable(0);
    panel_level_gen_set_d8_low4(0);
    panel_level_gen_set_reg_104(0, 0);
    if (sys_config.blurfree_mode == BLURFREE_GEN1)
        panel_level_gen_target = ((sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET) / LEVEL_DIVIDER;
    else if (sys_config.blurfree_mode == BLURFREE_GEN2)
        panel_level_gen_target = ((sys_config.brightness * BRIGHTNESS_SCALE_BLURFREE + 50) / 100 + BRIGHTNESS_OFFSET) / LEVEL_DIVIDER;
    else
        panel_level_gen_target = ((sys_config.brightness * BRIGHTNESS_SCALE_OFF + 50) / 100 + BRIGHTNESS_OFFSET) / LEVEL_DIVIDER;
    panel_level_gen_level = panel_level_gen_target;
    panel_level_gen_min_level = LEVEL_BASE;
    panel_level_gen_set_level_pair(panel_level_gen_min_level, panel_level_gen_level);
    panel_level_gen_set_reg_110_copy(LEVEL_REG_110_START);
    panel_level_gen_set_reg_114_copy(LEVEL_REG_110_START);
    panel_level_gen_set_ctrl_high_bits(8);
    panel_level_gen_set_f4_upper_field(1);
    panel_level_gen_set_f4_bit4(1);
    panel_level_gen_set_reg_0c4(0, 1);
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
    if (pq_block_is_blanked(PICTURE_BLOCK_8) == 0)
        panel_wait_sync_pulse();
    panel_level_gen_set_ctrl_bit0();
    sys_poll_events_stub_copy3(7, 0xd);
    panel_level_gen_set_ctrl_bit1();
    panel_pwm_set_control_bit3(PWM_CHANNEL_7, 1);
    panel_level_gen_flags = LEVEL_STATE_FLAGS;
}
