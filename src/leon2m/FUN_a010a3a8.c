/* leon2m FUN_a010a3a8 @ 0xa010a3a8-0xa010a494 (59 words), flags -mcpu=v8 -O3 -g.
 * Sets bit 4 (0x10) of three hardware registers A = 0xcf01e684, B = 0xcf01e688, C = 0xcf01e68c (volatile, each a
 * separate read-modify-write) by c:
 *   c == 1:    A |= 0x10, B &= ~0x10, C |= 0x10 when on != 0 else C &= ~0x10;
 *   c == 2:    A |= 0x10, B |= 0x10,  C |= 0x10 when on != 0 else C &= ~0x10;
 *   other c:   A, B and C &= ~0x10.
 * Source form: the same switch as FUN_a01085f8 with the default arm first (it gives the fw's per-case address
 * copies in the register window).
 */
#define R284 (*(volatile unsigned int *)0xcf01e684)
#define R288 (*(volatile unsigned int *)0xcf01e688)
#define R28C (*(volatile unsigned int *)0xcf01e68c)

void FUN_a010a3a8(unsigned char c, unsigned char on)
{
    switch (c) {
    default:
        R284 &= ~0x10;
        R288 &= ~0x10;
        R28C &= ~0x10;
        break;
    case 1:
        R284 |= 0x10;
        R288 &= ~0x10;
        if (on)
            R28C |= 0x10;
        else
            R28C &= ~0x10;
        break;
    case 2:
        R284 |= 0x10;
        R288 |= 0x10;
        if (on)
            R28C |= 0x10;
        else
            R28C &= ~0x10;
        break;
    }
}
