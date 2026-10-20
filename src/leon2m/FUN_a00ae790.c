/* leon2m FUN_a00ae790 @ 0xa00ae790-0xa00ae8e0 (84 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * With m = (byte 0xa802d412 & 3) * 2 + 4 (0xa802d290 + 0x182): FUN_a00b3ed0(0, 0, 0, 0); for m == 10
 * FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0) and FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11), else
 * FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0); then FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0). The byte is stepped back to (byte + 5) % 6;
 * when the new value is 5 or 3, FUN_a00b8ca8(value / 4) is called. Then FUN_a00ad86c(byte & 3, 1), FUN_a00dbcf0, and bit 1 (0x02) of
 * byte 0xa802b08e is set. Same form as FUN_a00adec0.
 * Exact form: the divisor 6 is held in a local (the firmware divides with sdiv by the immediate 6). The tests for 5
 * and 3 are two ifs, the first one jumping to the call (written with ||, GCC merges them into flag arithmetic).
 */
struct St {
    unsigned char pad[0x182];
    unsigned char bx;
};
extern struct St DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern void FUN_a00ad86c(unsigned char, unsigned char);
extern void FUN_a00b8ca8(unsigned char);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int);
extern void FUN_a00dbcf0(void);

void FUN_a00ae790(void)
{
    unsigned char m;
    unsigned char n = 6;

    m = ((DAT_a802d290.bx & 3) * 2 + 4) & 0xff;
    FUN_a00b3ed0(0, 0, 0, 0);

    if (m == 10) {
        FUN_a00b32e4(0, 0, 0x792, 3, 10, 2, 0);
        FUN_a00b32e4(1, 0, 0x3092, 3, 0xc, 1, 0x11);
    } else {
        FUN_a00b32e4(0, 0, 0x792, 3, m, 3, 0);
    }

    FUN_a00b32e4(0, 0, 0x792, 0x12, m, 3, 0);

    DAT_a802d290.bx = (DAT_a802d290.bx + 5) % n;
    if (DAT_a802d290.bx == 5)
        goto call;
    if (DAT_a802d290.bx == 3)
call:   FUN_a00b8ca8(DAT_a802d290.bx / 4);
    FUN_a00ad86c(DAT_a802d290.bx & 3, 1);
    FUN_a00dbcf0();
    DAT_a802b08e = DAT_a802b08e | 2;
}
