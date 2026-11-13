/* sys_api_get_channel_state_code  (FUN_a0143c14)
 *
 * Return the state of a channel as a code for the application layer.
 * Returns: state code
 * Name basis: derived - raw states 3, 5 and above 12 become 4; many callers in the application layer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143c14 @ 0xa0143c14, flags -mcpu=v8 -O3 -g
 * Case order: 12 first, 3/5 merged with default last (gcc 3.4 jump-table block order).
 */
#define SYS_CONFIG_BIT21 0x200000

extern unsigned int sys_config;
extern unsigned char sys_get_channel_state(int);

/* Return ch for 0..3, else -1. */
static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Translate the raw state of channel ch (sys_get_channel_state) into the code the application layer uses:
 *   raw 0->0, 1->1, 2->2, 4->3, 6->5, 7->6, 8->7, 9->8, 10 and 11->9, 12->10;
 *   raw 3, 5 and anything above 12 -> 4.
 * Channel 3 always gives 4 while bit 21 of sys_config is set. A channel number outside 0..3 becomes 0xFF
 * and is looked up as such. The result is masked to 4 bits. */
unsigned char sys_api_get_channel_state_code(unsigned char ch)
{
    unsigned char i = remap(ch);
    unsigned char code;

    if (i == 3 && (sys_config & SYS_CONFIG_BIT21))
        code = 4;
    else switch (sys_get_channel_state(i)) {
    case 12: code = 10; break;
    case 0: code = 0; break;
    case 1: code = 1; break;
    case 2: code = 2; break;
    case 4: code = 3; break;
    case 6: code = 5; break;
    case 7: code = 6; break;
    case 8: code = 7; break;
    case 9: code = 8; break;
    case 10: case 11: code = 9; break;
    case 3: case 5: default: code = 4; break;
    }
    return code & 0xf;
}
