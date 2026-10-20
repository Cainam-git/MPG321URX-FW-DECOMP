/* leon2m FUN_a0082acc @ 0xa0082acc  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a802af41; /* 0xa802af41 */
extern int FUN_a008ee6c(int a, int b); /* 0xa008ee6c */
extern int FUN_a008f354(void); /* 0xa008f354 */
extern void FUN_a0143da8(int a, int b, int c, int d, int e, int f); /* 0xa0143da8 */

void FUN_a0082acc(int a, int b, int c, int d, int e, int f)
{
    unsigned char tmp;
    FUN_a008f354();
    FUN_a008ee6c(0xff, 0);
    tmp = DAT_a802af41;
    DAT_a802af41 = tmp & ~1;
    FUN_a0143da8(a, b, c, d, e, f);
}
