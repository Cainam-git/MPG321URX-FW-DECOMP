/* leon2s FUN_a00aa5e8 @ 0xa00aa5e8-0xa00aa7bc (includes the shared ret/restore tail), -mcpu=v8 -Os -g.
 * (u8 port, u8 rate, u8 on, u8 go), void. FUN_a00aa538(port, on). Port 0: registers 0xcf012ac4 = 0,
 * 0xcf012ac8 = 0x80 (0 for rate 0x14) and 0xcf012acc = 0xd / 0x16 / 0x2d / 0x43 for rate 6 / 10 / 0x14 / other;
 * then the tail call FUN_a00aa00c() when go != 0. Other ports: registers 0xcf012a84 / a88 / a8c = 0x5c, 0x77, 0xd
 * (rate 6), 0x99, 0x71, 0x16 (10), 0x33, 0xe3, 0x2c (0x14) or 0xcc, 0x54, 0x43 (other), then
 * FUN_a00a7d04(1, 0xe6, 2, 1) for rate 6 and other rates, (.., 0) for 10 and 0x14; then the tail call
 * FUN_a00a9c4c() when go != 0.
 * Source form: each rate arm holds its own call; GCC shares the identical ones.
 */
extern void FUN_a00aa538(unsigned char, unsigned char);
extern void FUN_a00a7d04(unsigned int, short, unsigned int, unsigned int);
extern void FUN_a00aa00c(void);
extern void FUN_a00a9c4c(void);

#define R284 (*(volatile unsigned int *)0xcf012a84)
#define R288 (*(volatile unsigned int *)0xcf012a88)
#define R28C (*(volatile unsigned int *)0xcf012a8c)
#define R2C4 (*(volatile unsigned int *)0xcf012ac4)
#define R2C8 (*(volatile unsigned int *)0xcf012ac8)
#define R2CC (*(volatile unsigned int *)0xcf012acc)

void FUN_a00aa5e8(unsigned char port, unsigned char rate, unsigned char on, unsigned char go)
{
    FUN_a00aa538(port, on);
    if (port == 0) {
        if (rate == 6) {
            R2C4 = 0;
            R2C8 = 0x80;
            R2CC = 0xd;
        } else if (rate == 10) {
            R2C4 = 0;
            R2C8 = 0x80;
            R2CC = 0x16;
        } else if (rate == 0x14) {
            R2C4 = 0;
            R2C8 = 0;
            R2CC = 0x2d;
        } else {
            R2C4 = 0;
            R2C8 = 0x80;
            R2CC = 0x43;
        }
        if (go)
            FUN_a00aa00c();
    } else {
        if (rate == 6) {
            R284 = 0x5c;
            R288 = 0x77;
            R28C = 0xd;
            FUN_a00a7d04(1, 0xe6, 2, 1);
        } else if (rate == 10) {
            R284 = 0x99;
            R288 = 0x71;
            R28C = 0x16;
            FUN_a00a7d04(1, 0xe6, 2, 0);
        } else if (rate == 0x14) {
            R284 = 0x33;
            R288 = 0xe3;
            R28C = 0x2c;
            FUN_a00a7d04(1, 0xe6, 2, 0);
        } else {
            R284 = 0xcc;
            R288 = 0x54;
            R28C = 0x43;
            FUN_a00a7d04(1, 0xe6, 2, 1);
        }
        if (go)
            FUN_a00a9c4c();
    }
}
