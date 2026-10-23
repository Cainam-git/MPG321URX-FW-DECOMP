/* FUN_a00ae0dc (leon2s 0xa00ae0dc-0xa00ae1c0, 228 bytes), flags -mcpu=v8 -Os -g.
 * Sets on = 1 when FUN_a00ad828(c) returns nonzero (else 0), calls FUN_a00a6c98(a, 0xd5, 1, 1), then
 * FUN_a00a6c98(a, 0xd5, 0x20, on) and FUN_a00a6c00(a, 0xd7, v) with v = 0x12 for b == 8, 6 for b == 4 and 2
 * otherwise, and ends with the tail call FUN_a00adf84(a, 8 / b) (signed division).
 * Source form: FUN_a00adf84 takes two parameters (it never reads %i2); the third register at the tail call is
 * the leftover value of on. Each arm keeps its own FUN_a00a6c98 call.
 */
extern unsigned char FUN_a00ad828(unsigned char);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00adf84(unsigned char, unsigned char);

void FUN_a00ae0dc(unsigned char a, unsigned char b, unsigned char c)
{
    unsigned char on = 0;

    if (FUN_a00ad828(c))
        on = 1;

    FUN_a00a6c98(a, 0xd5, 1, 1);
    if (b == 8) {
        FUN_a00a6c98(a, 0xd5, 0x20, on);
        FUN_a00a6c00(a, 0xd7, 0x12);
    } else if (b == 4) {
        FUN_a00a6c98(a, 0xd5, 0x20, on);
        FUN_a00a6c00(a, 0xd7, 6);
    } else {
        FUN_a00a6c98(a, 0xd5, 0x20, on);
        FUN_a00a6c00(a, 0xd7, 2);
    }
    FUN_a00adf84(a, 8 / b);
}
