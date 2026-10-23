/* leon2s FUN_a00abe20 @ 0xa00abe20-0xa00abff0, -mcpu=v8 -Os -g.
 * (u8 port), void. With r = the 0x12c-byte record ARR_a807dc18[port], between FUN_a00a6c98(port, 0x30, 0x80, 1)
 * and the tail call FUN_a00a6c98(port, 0x30, 0x80, 0) it writes (FUN_a00a6c00 / FUN_a00a6c98):
 * register 0x200 = 0x12 when byte +0x117 is 1 or 2, else 0x11; 0x201 = 0x14 when byte +0x110 is 2 or 3, 10 when
 * it is 1, else 6; 0x202 = 0x84 / 0x82 / 0x81 for byte +0x111 = 2 / 1 / other; bit 0x40 of 0x202 = (byte +0x117
 * != 0); 0x203 = 0x81 when byte +0x110 is 3, else 1; 0x266 = 0x83 and FUN_a00abbc4(port) when byte +0x117 is 2,
 * else 0x266 = 0.
 * Source form: each arm holds its complete call; GCC shares the common arguments.
 */
struct Port {
    unsigned char pad[0x110];
    unsigned char b110;
    unsigned char b111;
    unsigned char pad112[5];
    unsigned char b117;
    unsigned char rest[0x12c - 0x118];
};
extern struct Port ARR_a807dc18[];
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00abbc4(unsigned char);

void FUN_a00abe20(unsigned char port)
{
    FUN_a00a6c98(port, 0x30, 0x80, 1);
    if ((unsigned char)(ARR_a807dc18[port].b117 - 1) <= 1)
        FUN_a00a6c00(port, 0x200, 0x12);
    else
        FUN_a00a6c00(port, 0x200, 0x11);
    if ((unsigned char)(ARR_a807dc18[port].b110 - 2) <= 1)
        FUN_a00a6c00(port, 0x201, 0x14);
    else if (ARR_a807dc18[port].b110 == 1)
        FUN_a00a6c00(port, 0x201, 10);
    else
        FUN_a00a6c00(port, 0x201, 6);
    if (ARR_a807dc18[port].b111 == 2)
        FUN_a00a6c00(port, 0x202, 0x84);
    else if (ARR_a807dc18[port].b111 == 1)
        FUN_a00a6c00(port, 0x202, 0x82);
    else
        FUN_a00a6c00(port, 0x202, 0x81);
    if (ARR_a807dc18[port].b117 == 0)
        FUN_a00a6c98(port, 0x202, 0x40, 0);
    else
        FUN_a00a6c98(port, 0x202, 0x40, 1);
    if (ARR_a807dc18[port].b110 == 3)
        FUN_a00a6c00(port, 0x203, 0x81);
    else
        FUN_a00a6c00(port, 0x203, 1);
    if (ARR_a807dc18[port].b117 == 2) {
        FUN_a00a6c00(port, 0x266, 0x83);
        FUN_a00abbc4(port);
    } else {
        FUN_a00a6c00(port, 0x266, 0);
    }
    FUN_a00a6c98(port, 0x30, 0x80, 0);
}
