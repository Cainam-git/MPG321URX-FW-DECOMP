/* leon2s FUN_a00a6aa0 @ 0xa00a6aa0-0xa00a6bb8, -mcpu=v8 -Os -g.
 * (u8 port, u16 reg, u8 mask, u8 mode). Read-modify-write of the low byte of hardware register reg of
 * block port: address = ((DAT_a00b4d98[port] + reg) * 4) | 0xcf000000 (DAT_a00b4d98 = u16 base table).
 * mode == 1 sets the bits of mask, any other mode clears them. port == 2 applies the same step to blocks
 * 0 and 1 in turn; port > 2 returns without an access. Read counterpart: FUN_a00a69b4; write-only
 * counterpart: FUN_a00a69fc. Same code as FUN_a00a8400 with another table and port count.
 * Source form: the read value and the result are unsigned char locals.
 */
extern unsigned short DAT_a00b4d98[];

#define REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) * 4)))

void FUN_a00a6aa0(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char i;
    unsigned char v;
    unsigned char r;

    if (port > 2)
        return;
    if (port == 2) {
        i = 0;
        do {
            v = REG(DAT_a00b4d98[i] + reg);
            if (mode == 1)
                r = v | mask;
            else
                r = v & ~mask;
            REG(DAT_a00b4d98[i] + reg) = r;
            i++;
        } while (i <= 1);
    } else if (port < 2) {
        v = REG(DAT_a00b4d98[port] + reg);
        if (mode == 1)
            r = v | mask;
        else
            r = v & ~mask;
        REG(DAT_a00b4d98[port] + reg) = r;
    }
}
