/* oled_get_care_table_count  (FUN_a0127a00)
 *
 * Return 4, the number of care table entries.
 * Returns: 4
 * Name basis: derived - constant 4; osd_run_periodic_task uses it as the limit of its loop over
 *   oled_get_care_table_byte
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127a00 @ 0xa0127a00, flags -mcpu=v8 -O2 -g.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();


/*
 * Return the number of entries of the care table (oled_care_table), 4. osd_run_periodic_task uses it as the
 * loop limit when it looks for the first table entry above the OFFS hours.
 */
int oled_get_care_table_count(void)
{
    return 4;
}