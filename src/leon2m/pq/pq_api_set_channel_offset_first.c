/* pq_api_set_channel_offset_first  (FUN_a014a210)
 *
 * Store the per-channel offset of the first set for red, green or blue.
 * Name basis: derived - bytes read by pq_add_channel_offset_a; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a210 @ 0xa014a210-0xa014a258 (72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with one extern byte per case.
 */
extern unsigned char sys_config_red_offset_first, sys_config_green_offset_first, sys_config_blue_offset_first;

#define RGB_RED   0
#define RGB_GREEN 1
#define RGB_BLUE  2

/*
 * Store the offset of one colour in the first offset set (sys_config bytes +0x12..+0x14). Nothing is applied
 * here; pq_add_channel_offset_a adds the stored offset to a value, with 0x80 meaning no offset.
 *
 *   color   RGB_RED, RGB_GREEN or RGB_BLUE; any other value does nothing
 *   offset  the offset byte
 *
 * Nothing in the firmware calls this routine.
 */
void pq_api_set_channel_offset_first(unsigned char color, unsigned char offset)
{
    switch (color) {
    case RGB_RED:
        sys_config_red_offset_first = offset;
        break;
    case RGB_GREEN:
        sys_config_green_offset_first = offset;
        break;
    case RGB_BLUE:
        sys_config_blue_offset_first = offset;
        break;
    }
}
