/* leon2m FUN_a01470fc @ 0xa01470fc-0xa01471a0 (41 words).
 * Writes the low 4 bits of v into bits 4..7 of the first word of display channel record ch (the 0x78-byte records at
 * 0xa802df30). A channel number outside 0..3 prints "SYS remapping channel OOR" and uses channel 0. Setter
 * counterpart of FUN_a0147064.
 */
struct Chan { unsigned int hi24 : 24; unsigned int f4 : 4; unsigned int lo4 : 4; unsigned char rest[0x74]; };
extern struct Chan DAT_a802df30[4];
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

void FUN_a01470fc(unsigned char ch, unsigned int v)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    DAT_a802df30[i].f4 = v;
}
