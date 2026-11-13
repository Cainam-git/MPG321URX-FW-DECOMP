/* panel_api_copy_active_row  (FUN_a01483b8)
 *
 * Copy the active panel timing row (0x58 bytes) to a buffer.
 * Name basis: derived - copy from 0xA802E378; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01483b8 @ 0xa01483b8-0xa01483f4 (60 bytes, a leaf), flags -mcpu=v8 -Os -g.
 * Source form: the counter is an unsigned short.
 */
extern unsigned char panel_active_row[];
#define PANEL_ROW_SIZE 0x58     /* bytes of one panel timing row */

/*
 * Copy the active panel timing row to a buffer.
 *
 *   dest  buffer of at least 0x58 bytes
 *
 * No routine calls it.
 */
void panel_api_copy_active_row(unsigned char *dest)
{
    unsigned short i;
    for (i = 0; i < PANEL_ROW_SIZE; i++)
        *(dest + i) = *(i + panel_active_row);
}
