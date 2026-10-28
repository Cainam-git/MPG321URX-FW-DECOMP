/* leon2s FUN_a00a7058 @ 0xa00a7058-0xa00a7168, -mcpu=v8 -Os -g.
 * (u8 port, u16 reg, u8 mask, u8 mode). Read-modify-write of the low byte of hardware register reg of
 * block port: address = ((DAT_a00b4d90[port] + reg) * 4) | 0xcf000000 (DAT_a00b4d90 = u16 base table).
 * mode == 1 sets the bits of mask, any other mode clears them. port == 2 applies the same step to blocks
 * 0 and 1 in turn; port > 2 returns without an access; ports 0 and 1 are written without a further range test.
 * Same code as FUN_a00a6aa0 with the table DAT_a00b4d90 and a plain else for the single-port case.
 * Source form: the read value and the result are unsigned char locals.
 */
extern unsigned short DAT_a00b4d90[];

#define REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) * 4)))

void FUN_a00a7058(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char i;
    unsigned char v;
    unsigned char r;

    if (port > 2)
        return;
    if (port == 2) {
        i = 0;
        do {
            v = REG(DAT_a00b4d90[i] + reg);
            if (mode == 1)
                r = v | mask;
            else
                r = v & ~mask;
            REG(DAT_a00b4d90[i] + reg) = r;
            i++;
        } while (i <= 1);
    } else {
        v = REG(DAT_a00b4d90[port] + reg);
        if (mode == 1)
            r = v | mask;
        else
            r = v & ~mask;
        REG(DAT_a00b4d90[port] + reg) = r;
    }
}
