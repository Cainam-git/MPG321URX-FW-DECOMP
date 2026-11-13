/* oled_get_care_table_byte  (FUN_a0127a08)
 *
 * Return a byte of the four-entry care table, the last one for index 0xFF.
 * Returns: byte
 * Name basis: descriptive - byte table at 0xA802A440
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127a08 @ 0xa0127a08, flags -mcpu=v8 -O2 -g.
 * Source form: the index is tested as (index & 0xff) == 0xff and used as oled_care_table[index & 0xff]; the
 * last entry is read through its own label.
 */
extern unsigned char oled_care_table[];
extern unsigned char oled_care_table_last;

#define CARE_TABLE_LAST 0xff        /* index that selects the last entry (table offset 3) */

/*
 * Return one hour value of the OLED care table, a table of four bytes. Index 0xFF stands for the last entry.
 * The callers compare the values with device setting 13, the hour count printed as "OFFS H": osd_run_periodic_task takes the
 * first entry above it, oled_get_protect_step_code the last entry minus 1.
 */
unsigned char oled_get_care_table_byte(unsigned int index)
{
    if ((index & 0xff) == CARE_TABLE_LAST) {
        return oled_care_table_last;
    }
    return oled_care_table[index & 0xff];
}
