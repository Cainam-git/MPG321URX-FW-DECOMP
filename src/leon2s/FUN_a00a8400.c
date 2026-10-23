/* leon2s FUN_a00a8400 @ 0xa00a8400-0xa00a8508, -mcpu=v8 -Os -g.
 * (u8 port, u16 reg, u8 mask, u8 mode). Read-modify-write of the low byte of hardware register reg of
 * block port: address = ((DAT_a00b4d20[port] + reg) * 4) | 0xcf000000 (DAT_a00b4d20 = u16 base table).
 * mode == 1 sets the bits of mask, any other mode clears them. port > 7 applies the same step to blocks
 * 0..7 in turn. Write-only counterpart: FUN_a00a8370.
 * Source form: the read value and the result are unsigned char locals (register choice of the loop).
 */
extern unsigned short DAT_a00b4d20[];

#define REG(a) (*(volatile unsigned int *)(0xcf000000 | ((a) * 4)))

void FUN_a00a8400(unsigned char port, unsigned short reg, unsigned char mask, unsigned char mode)
{
    unsigned char i;
    unsigned char v;
    unsigned char r;

    if (port > 7) {
        i = 0;
        do {
            v = REG(DAT_a00b4d20[i] + reg);
            if (mode == 1)
                r = v | mask;
            else
                r = v & ~mask;
            REG(DAT_a00b4d20[i] + reg) = r;
            i++;
        } while (i <= 7);
    } else {
        v = REG(DAT_a00b4d20[port] + reg);
        if (mode == 1)
            r = v | mask;
        else
            r = v & ~mask;
        REG(DAT_a00b4d20[port] + reg) = r;
    }
}
