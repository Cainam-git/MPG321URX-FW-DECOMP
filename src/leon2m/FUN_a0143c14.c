/* leon2m FUN_a0143c14 @ 0xa0143c14, flags -mcpu=v8 -O3 -g
 * Mapped port state: remaps channel 'ch' (0..3, else 0xFF), returns 4 for channel 3 while bit 21 of
 * DAT_a802e3d0 is set; else maps the raw state FUN_a013ce6c(ch) to the APP state code:
 * 0->0, 1->1, 2->2, 4->3, 6->5, 7->6, 8->7, 9->8, 10/11->9, 12->10, 3/5/>12->4. Result & 0xF.
 * Case order: 12 first, 3/5 merged with default last (gcc 3.4 jump-table block order).
 */
extern unsigned int DAT_a802e3d0;
extern unsigned char FUN_a013ce6c(int);

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

unsigned char FUN_a0143c14(unsigned char ch)
{
    unsigned char i = remap(ch);
    unsigned char r;

    if (i == 3 && (DAT_a802e3d0 & 0x200000))
        r = 4;
    else switch (FUN_a013ce6c(i)) {
    case 12: r = 10; break;
    case 0: r = 0; break;
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 4: r = 3; break;
    case 6: r = 5; break;
    case 7: r = 6; break;
    case 8: r = 7; break;
    case 9: r = 8; break;
    case 10: case 11: r = 9; break;
    case 3: case 5: default: r = 4; break;
    }
    return r & 0xf;
}
