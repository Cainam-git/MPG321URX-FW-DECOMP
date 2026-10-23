/* leon2m FUN_a014d3d4 @ 0xa014d3d4 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a0148540: same code, other constants.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* 0x78-byte record */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();                     /* formatted output (vsnprintf) */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern unsigned char FUN_a0140078(unsigned char);   /* bit n of DAT_a802cbd4 */

/* 0 .. 3 map to themselves, any other value to -1 */
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

unsigned char FUN_a014d3d4(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a0140078((DAT_a802df30[i].w0 >> 12) & 0xf);
}
