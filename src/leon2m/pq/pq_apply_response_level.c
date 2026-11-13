/* pq_apply_response_level  (FUN_a014110c)
 *
 * Load the table set for a level and restart the block when the level changed.
 * Name basis: descriptive - table pointer per level at 0xA8027BB0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014110c @ 0xa014110c-0xa014118c (128 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: sys_return_zero_copy2 is declared returning unsigned char (its low byte is tested).
 */
extern unsigned char pq_response_level_last, device_settings_pip_mode;
extern unsigned int pq_response_level_tables[];
extern void pq_block8_set_timing(unsigned int level_table);
extern void pq_block8_set_mode(unsigned int mode);
extern void pq_block8_start(void);
extern unsigned char sys_return_zero_copy2(void);

/* Modes of picture block 8 (pq_block8_set_mode) chosen here. */
#define BLOCK8_MODE_SINGLE_PICTURE 2    /* picture mode 0 (device_settings_pip_mode) */
#define BLOCK8_MODE_OTHER          3    /* every other picture mode */

/*
 * Apply a response level through picture block 8, then start the block.
 *
 *   level  index into pq_response_level_tables (sys_config byte +0x1C, response_level)
 *
 * The level's table is loaded and the block's mode set only when the level differs from the one applied last
 * (sys_return_zero_copy2 always returns 0, so it never forces a reload). Picture block 8 is started in every
 * case. Called by pq_api_set_response_level and sys_api_config, both after pq_block8_stop.
 */
void pq_apply_response_level(unsigned char level)
{
    if (pq_response_level_last != level || sys_return_zero_copy2()) {
        pq_block8_set_timing(pq_response_level_tables[level]);
        pq_response_level_last = level;
        if (device_settings_pip_mode == 0)
            pq_block8_set_mode(BLOCK8_MODE_SINGLE_PICTURE);
        else
            pq_block8_set_mode(BLOCK8_MODE_OTHER);
    }
    pq_block8_start();
}
