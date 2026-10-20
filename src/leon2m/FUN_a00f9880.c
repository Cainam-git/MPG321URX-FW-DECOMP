/* leon2m FUN_a00f9880 @ 0xa00f9880  MATCH (-mcpu=v8 -O3 -g)
 * When FUN_a010a874() returns non-zero and bit 3 of block-0 register 3 (FUN_a00f1a90(0, 3)) is set, clears that
 * bit with FUN_a00f1b5c(0, 3, 8, 0), calls FUN_4008d1a0(0x28), sets the bit again with FUN_a00f1b5c(0, 3, 8, 1)
 * and prints "toggle for preFRC" (red) through FUN_a00df170. Callers: FUN_a013c040, FUN_a013c144.
 */
extern unsigned char FUN_a010a874(void);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern int FUN_4008d1a0(int, ...);
extern int FUN_a00df170(const char *fmt, ...);

void FUN_a00f9880(void)
{
    if (FUN_a010a874() && (FUN_a00f1a90(0, 3) & 8)) {
        FUN_a00f1b5c(0, 3, 8, 0);
        FUN_4008d1a0(0x28);
        FUN_a00f1b5c(0, 3, 8, 1);
        FUN_a00df170("\033[1;31mtoggle for preFRC\r\n\033[m");
    }
}
