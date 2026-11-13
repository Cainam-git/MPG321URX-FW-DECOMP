/* sys_is_mode_4_to_6  (FUN_a00837e4)
 *
 * Return 1 when mode byte 0xA802D434 is 4, 5 or 6.
 * Returns: 0 or 1
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00837e4 @ 0xa00837e4, flags -mcpu=v8 -O3 -g. Leaf.
 * The range test is on the unsigned char difference (firmware 'and 0xff; cmp 2; bgu'), not a signed int compare; the
 * result is a flag set per path and masked with 'and 1' at the join ('return r & 1'). _Bool gives other code.
 */
extern unsigned char user_settings_screen_size;

/*
 * Return 1 when the Screen Size setting (settings byte +0x1A4) is 4, 5 or 6, else 0.
 * Called by uart_cmd_set_optix_scope.
 */
unsigned char sys_is_mode_4_to_6(void)
{
    unsigned char result = 0;

    if ((unsigned char)(user_settings_screen_size - 4) < 3)
        result = 1;
    return result & 1;
}
