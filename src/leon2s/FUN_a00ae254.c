/* leon2s FUN_a00ae254 @ 0xa00ae254-0xa00ae344, -mcpu=v8 -Os -g.
 * (u8 port, unsigned int v). m = low byte of v & 0xf0. Writes bit 7 of m to register 0x44 mask 0x80
 * (FUN_a00a6c98). If FUN_a00ae238(port) == 1, clears mask 0x40, 0x20 and 0x10 of register 0x44; otherwise
 * writes bits 6, 5 and 4 of m to them. Finally writes 1 (m != 0) or 0 to register 0x40 mask 0x10.
 * Source form: the bit-7 argument is (m & 0x80) != 0, which keeps the and -16 in the parameter register and a
 * separate zero-extension for the later bit reads; the last write is an if/else with constant arguments.
 */
extern unsigned char FUN_a00ae238(unsigned char);
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a00ae254(unsigned char port, unsigned int v)
{
    unsigned char m;

    m = v & 0xf0;
    FUN_a00a6c98(port, 0x44, 0x80, (m & 0x80) != 0);
    if (FUN_a00ae238(port) == 1) {
        FUN_a00a6c98(port, 0x44, 0x40, 0);
        FUN_a00a6c98(port, 0x44, 0x20, 0);
        FUN_a00a6c98(port, 0x44, 0x10, 0);
    } else {
        FUN_a00a6c98(port, 0x44, 0x40, (m >> 6) & 1);
        FUN_a00a6c98(port, 0x44, 0x20, (m >> 5) & 1);
        FUN_a00a6c98(port, 0x44, 0x10, (m >> 4) & 1);
    }
    if (m)
        FUN_a00a6c98(port, 0x40, 0x10, 1);
    else
        FUN_a00a6c98(port, 0x40, 0x10, 0);
}
