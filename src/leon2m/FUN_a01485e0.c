/* leon2m FUN_a01485e0 @ 0xa01485e0 (-mcpu=v8 -O3 -g)
 * k = p1; any k above 3 prints "SYS remapping channel OOR" through FUN_a00df170 and uses 0. Returns
 * FUN_a01400bc(bits 12-15 of word 0 of record k of the 0x78-byte records at 0xA802DF30); FUN_a01400bc returns bit n
 * of byte 0xA802CBD3. Called from FUN_a008380c.
 */
struct Chan { unsigned int w0; unsigned char rest[0x74]; };   /* 0x78-byte record */
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170();                     /* formatted output (vsnprintf) */
extern char s_001a6dd8[];                      /* "SYS remapping channel OOR\r\n" */
extern unsigned char FUN_a01400bc(unsigned char);   /* bit n of byte 0xA802CBD3 */

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

unsigned char FUN_a01485e0(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { FUN_a00df170(s_001a6dd8); i = 0; }
    return FUN_a01400bc((DAT_a802df30[i].w0 >> 12) & 0xf);
}
