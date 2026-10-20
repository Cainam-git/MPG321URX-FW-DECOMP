/* leon2m FUN_a002a5e4 @ 0xa002a5e4 (-mcpu=v8 -O2 -g)
 * Reads the register at 0x9F020064 through FUN_a002c250, ORs in ((b & 0xFF) << a) << 16 and passes the result with
 * the remaining four parameters to FUN_a002c25c. FUN_a002c250 is declared to return int, which avoids an
 * 'and %o0,0xff,%o0' on its result.
 */
/* 0xa002c250 */
extern int FUN_a002c250(unsigned int addr);
/* 0xa002c25c */
extern int FUN_a002c25c(unsigned int addr, unsigned int val, unsigned int p3, unsigned int p4, unsigned int p5, unsigned int p6);

void FUN_a002a5e4(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f)
{
    unsigned int ret;
    unsigned int val;

    ret = FUN_a002c250(0x9f020064);
    val = ((b & 0xff) << a) << 16 | ret;
    FUN_a002c25c(0x9f020064, val, c, d, e, f);
}
