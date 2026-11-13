/* pq_api_set_channel_offset_second  (FUN_a014a258)
 *
 * Store the per-channel offset of the second set for red, green or blue.
 * Name basis: derived - bytes read by pq_add_channel_offset_b; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a258 @ 0xa014a258-0xa014a2a0 (72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with one extern byte per case.
 */
extern unsigned char sys_config_red_offset_second, sys_config_green_offset_second, sys_config_blue_offset_second;

#define RGB_RED   0
#define RGB_GREEN 1
#define RGB_BLUE  2

/*
 * Store the offset of one colour in the second offset set (sys_config bytes +0x15..+0x17). Nothing is applied
 * here; pq_add_channel_offset_b adds the stored offset to a value.
 *
 *   color   RGB_RED, RGB_GREEN or RGB_BLUE; any other value does nothing
 *   offset  the offset byte
 *
 * Nothing in the firmware calls this routine.
 */
void pq_api_set_channel_offset_second(unsigned char color, unsigned char offset)
{
    switch (color) {
    case RGB_RED:
        sys_config_red_offset_second = offset;
        break;
    case RGB_GREEN:
        sys_config_green_offset_second = offset;
        break;
    case RGB_BLUE:
        sys_config_blue_offset_second = offset;
        break;
    }
}
