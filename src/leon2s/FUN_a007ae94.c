/* FUN_a007ae94 (leon2s 0xa007ae94-0xa007af04, 112 bytes), flags -mcpu=v8 -Os -g.
 * When FUN_a0073520(p) is non-zero: tests bit 0x12 of the word array at (word +0xc of the 0x34-byte port
 * record ARR_a807db00[p != 2]) + 0x74 bytes through FUN_a00a7408; otherwise tests bit 2 of register 0x2f6
 * of port p (FUN_a00a657c). Returns 1 when the tested bit is set, else 0.
 * Source form: early returns, each test as 'if (...) return 1; return 0;' (as FUN_a007b2a0); the record index is
 * a separate local 'i = p != 2' inside the != 0 arm (as FUN_a007af04).
 */
struct PortRec { unsigned char pad[0xc]; unsigned int w0c; unsigned char pad2[0x34 - 0x10]; };
extern struct PortRec ARR_a807db00[];
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

unsigned int FUN_a007ae94(unsigned char p)
{
    if (FUN_a0073520(p) != 0)
    {
        unsigned int i = p != 2;
        if (FUN_a00a7408(0x12, ARR_a807db00[i].w0c + 0x74))
            return 1;
        return 0;
    }
    if (FUN_a00a657c(p, 0x2f6) & 4)
        return 1;
    return 0;
}
