/* leon2m FUN_a0108f70 @ 0xa0108f70-0xa0109110 (104 words).
 * For i = 0..3 sets bits 4..5 of the register 0xcf011aa0 + 4 * i to i (clear, then or), then for i = 1..3 clears
 * bits 0..2 of the register 0xcf011aa0 + 4 * i (clear, then or with 0). Each register update is two
 * read-modify-write accesses.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0108f70(void)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            R(0xcf011aa0) &= ~0x30;
            R(0xcf011aa0) |= 0 << 4;
            break;
        case 1:
            R(0xcf011aa4) &= ~0x30;
            R(0xcf011aa4) |= 1 << 4;
            break;
        case 2:
            R(0xcf011aa8) &= ~0x30;
            R(0xcf011aa8) |= 2 << 4;
            break;
        case 3:
            R(0xcf011aac) &= ~0x30;
            R(0xcf011aac) |= 3 << 4;
            break;
        }
    }
    for (i = 1; i < 4; i++) {
        switch (i) {
        case 1:
            R(0xcf011aa4) &= ~7;
            R(0xcf011aa4) |= 0;
            break;
        case 2:
            R(0xcf011aa8) &= ~7;
            R(0xcf011aa8) |= 0;
            break;
        case 3:
            R(0xcf011aac) &= ~7;
            R(0xcf011aac) |= 0;
            break;
        }
    }
}
