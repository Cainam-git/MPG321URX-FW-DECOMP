/* leon2m FUN_a00fde94 @ 0xa00fde94-0xa00fdf44 (44 words), flags -mcpu=v8 -O3 -g.
 * Parameter c. x = (c << 4) | c for c <= 7, else 0. When register 0xcf02010c equals x: for i = 0..7 other than c,
 * the first i with FUN_a00f1a90(i, 4) & 3 == 0 and FUN_a00f1a90(i, 3) & 0x20 == 0 is written to the register
 * as (i << 4) | i (byte), and the function returns. Otherwise nothing is written. Caller: FUN_a0142ed0.
 * Source form: the byte value is built in two statements (x = v << 4; x |= v;) with an if/else for x; the
 * counter i is an unsigned char.
 */
#define REG (*(volatile unsigned int *)0xcf02010c)
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);

void FUN_a00fde94(unsigned char c)
{
    unsigned char x;
    unsigned char i;

    if (c > 7)
        x = 0;
    else {
        x = c << 4;
        x |= c;
    }
    if (REG == x) {
        for (i = 0; i <= 7; i++) {
            if (i != c) {
                if (!(FUN_a00f1a90(i, 4) & 3)) {
                    if (!(FUN_a00f1a90(i, 3) & 0x20)) {
                        x = i << 4;
                        x |= i;
                        REG = x;
                        return;
                    }
                }
            }
        }
    }
}
