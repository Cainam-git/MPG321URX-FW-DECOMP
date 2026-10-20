/* leon2m FUN_a00f35d0 @ 0xa00f35d0 (-mcpu=v8 -O3 -g)
 * Writes the low byte of sel << 5 to the three hardware registers 0xCF020024, 0xCF02002C and 0xCF020034.
 * When sel is 8 it is first replaced by a level 0..7: the code clears 0xCF01245C, writes 5 to 0xCF012458, calls
 * FUN_4008d1a0(5), reads the 16-bit count n at 0xCF012460 (FUN_a00f3078) and computes q = 0x180000 / n (16 bits);
 * q <= 0x24 gives 7, <= 0x36 6, <= 0x4F 5, <= 0x59 4, <= 0x6D 3, <= 0x8B 2, <= 0xB3 1, larger 0.
 * No direct callers found.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern int FUN_4008d1a0(int, ...);
extern unsigned int FUN_a00f3078(volatile unsigned int *p);

void FUN_a00f35d0(unsigned int sel)
{
    unsigned short n, q;

    if (sel == 8) {
        R(0xcf01245c) = 0;
        R(0xcf012458) = 5;
        FUN_4008d1a0(5);
        n = FUN_a00f3078((volatile unsigned int *)0xcf012460);
        q = 0x180000 / n;
        if (q <= 0x24)
            sel = 7;
        else if (q <= 0x36)
            sel = 6;
        else if (q <= 0x4f)
            sel = 5;
        else if (q <= 0x59)
            sel = 4;
        else if (q <= 0x6d)
            sel = 3;
        else if (q <= 0x8b)
            sel = 2;
        else if (q <= 0xb3)
            sel = 1;
        else
            sel = 0;
    }
    R(0xcf020024) = (unsigned char)(sel << 5);
    R(0xcf02002c) = (unsigned char)(sel << 5);
    R(0xcf020034) = (unsigned char)(sel << 5);
}
