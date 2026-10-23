/*
 * FUN_a00b1224 (leon2s, 0xa00b1224-0xa00b12c4, 160 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: switch on the u8 mode param_2 (signed case tree, root 1). Each case makes two
 * FUN_a00a6c98(port, 0x55, mask, on) bit writes on port register 0x55: mode 0 clears bits 0x40
 * and 0x10, mode 1 sets both, mode 2 sets 0x40 and clears 0x10. Any other mode does nothing.
 * The second call of each case is a sibcall (call + restore). FUN_a00a6c98 is void
 * (u32, u16, u32, u32), the accepted prototype in src/leon2s.
 * Aids: none. The case SOURCE order 0, 2, 1 gives the fw block layout (other orders give another layout).
 */
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a00b1224(unsigned char param_1, unsigned char param_2)
{
    switch (param_2) {
    case 0:
        FUN_a00a6c98(param_1, 0x55, 0x40, 0);
        FUN_a00a6c98(param_1, 0x55, 0x10, 0);
        break;
    case 2:
        FUN_a00a6c98(param_1, 0x55, 0x40, 1);
        FUN_a00a6c98(param_1, 0x55, 0x10, 0);
        break;
    case 1:
        FUN_a00a6c98(param_1, 0x55, 0x40, 1);
        FUN_a00a6c98(param_1, 0x55, 0x10, 1);
        break;
    }
}
