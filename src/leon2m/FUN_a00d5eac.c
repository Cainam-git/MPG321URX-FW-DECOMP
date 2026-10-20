/* leon2m FUN_a00d5eac @ 0xa00d5eac-0xa00d5f3c (36 words).
 * Does nothing when byte 0xa802d2af (offset 0x1f of the block at 0xa802d290) is non-zero. Otherwise, when byte
 * 0xa802d2da (offset 0x4a) is 0 it calls FUN_a014d474(1, 0) and FUN_a014dd98(1, 0), else FUN_a014dd98(1, 1) and
 * FUN_a014d474(1, 1). When flag is non-zero it then calls FUN_a014d474(1, 0) and FUN_a0149fb8(1, b), passing its
 * second parameter on unchanged.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a014d474(unsigned char, unsigned char);
extern void FUN_a014dd98(unsigned char, unsigned char);
extern void FUN_a0149fb8(unsigned char, unsigned int);

void FUN_a00d5eac(unsigned char flag, unsigned int b)
{
    if (DAT_a802d290[0x1f] != 0)
        return;
    if (DAT_a802d290[0x4a] != 0) {
        FUN_a014dd98(1, 1);
        FUN_a014d474(1, 1);
    } else {
        FUN_a014d474(1, 0);
        FUN_a014dd98(1, 0);
    }
    if (flag) {
        FUN_a014d474(1, 0);
        FUN_a0149fb8(1, b);
    }
}
