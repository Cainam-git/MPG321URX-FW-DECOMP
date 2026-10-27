/* leon2s FUN_a00b3530 @ 0xa00b3530-0xa00b383c (195 words), flags -mcpu=v8 -g (unoptimised).
 * int (u8 n). Returns -1 unless n == 9. v = low byte of the register 0xcf03c880. For i = 0 .. n - 1 and the
 * 20-byte records ARR_a807a824[i] whose byte 0 is above 3: when bit 0 of v is set, byte 0 = 2 if bit 1 of byte
 * +0xd is set (the same test on both sides of a test of bit 3 of the halfword +0x12); when bit 1 of v is set,
 * bit 3 of +0x12 is clear and bit 13 of the halfword +0xe is set, clears that bit and sets byte 0 = 2.
 * Then copies the register 0xcf03c910 to 0xcf03c920 and returns 3.
 * Source form: halfword bit-fields read through (unsigned char) casts (the firmware masks each extracted bit
 * with 0xff); two return statements (the unoptimised code keeps the result in a stack slot).
 */
struct Rec20 {
    unsigned char b0;
    unsigned char _1[0xc];
    unsigned char b0d;
    unsigned short e15 : 2;
    unsigned short e13 : 1;
    unsigned short e0 : 13;
    unsigned char _10[2];
    unsigned short f4 : 12;
    unsigned short f3 : 1;
    unsigned short f0 : 3;
};
extern struct Rec20 ARR_a807a824[];

#define REG_CF03C880 (*(volatile unsigned int *)0xcf03c880)
#define REG_CF03C910 (*(volatile unsigned int *)0xcf03c910)
#define REG_CF03C920 (*(volatile unsigned int *)0xcf03c920)

int FUN_a00b3530(unsigned char n)
{
    unsigned char i;
    unsigned char v;

    if (n != 9)
        return -1;
    {
        v = REG_CF03C880;
        for (i = 0; i < n; i++) {
            if (ARR_a807a824[i].b0 > 3) {
                if (v & 1) {
                    if ((unsigned char)ARR_a807a824[i].f3) {
                        if (ARR_a807a824[i].b0d & 2)
                            ARR_a807a824[i].b0 = 2;
                    } else {
                        if (ARR_a807a824[i].b0d & 2)
                            ARR_a807a824[i].b0 = 2;
                    }
                }
                if (v & 2) {
                    if (!(unsigned char)ARR_a807a824[i].f3) {
                        if ((unsigned char)ARR_a807a824[i].e13) {
                            ARR_a807a824[i].e13 = 0;
                            ARR_a807a824[i].b0 = 2;
                        }
                    }
                }
            }
        }
        REG_CF03C920 = REG_CF03C910;
    }
    return 3;
}
