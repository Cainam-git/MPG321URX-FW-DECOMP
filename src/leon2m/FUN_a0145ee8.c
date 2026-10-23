/* leon2m FUN_a0145ee8 @ 0xa0145ee8-0xa0145fac (49 words).
 * When off is non-zero, only FUN_a013b6e4(0) is called. Otherwise FUN_a013b6e4(1), then it reads bits 4..7 of the
 * first word of channel record ch (the 0x78-byte records at 0xa802df30) and calls FUN_a00f63bc(value) unless
 * the value is 4. A channel number outside 0..3 prints "SYS remapping channel OOR" and uses channel 0. Same field as
 * FUN_a0147064 and FUN_a01470fc.
 */
struct Chan { unsigned int hi24 : 24; unsigned int f4 : 4; unsigned int lo4 : 4; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
extern void FUN_a00f63bc(unsigned int);
extern void FUN_a013b6e4(int);
extern int FUN_a00df170();                     /* debug printf */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */

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

void FUN_a0145ee8(unsigned char ch, unsigned char off)
{
    unsigned char i;

    if (off) {
        FUN_a013b6e4(0);
        return;
    }
    FUN_a013b6e4(1);
    i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    {
        unsigned int v = DAT_a802df30[i].f4;

        if (v != 4)
            FUN_a00f63bc(v);
    }
}
