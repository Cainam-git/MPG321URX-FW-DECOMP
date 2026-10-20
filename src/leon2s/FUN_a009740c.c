/* FUN_a009740c (leon2s 0xa009740c-0xa00974ec, 224 bytes), flags -mcpu=v8 -Os -g.
 * Bit tests and updates through the 0x34-byte port record ARR_a807db00[port & 0xff] (words +0, +4, +0xc
 * hold register addresses). FUN_a00a7408(bit, addr) tests a bit, FUN_a00a73ac(bit, addr) and
 * FUN_a00a73d4(bit, addr) are the two update calls. When bits 8 of w0c + 0x60 and 0x11 of w0c + 0x74 are
 * both set, or bit 0x11 of w0c + 0x74 is clear and bit 0x10 is set: FUN_a00a73ac(0x10, w04 + 0x34).
 * Otherwise FUN_a00a73d4(0x10, w04 + 0x34), and when bit 0x14 of w00 + 0xec is set,
 * FUN_a00a73d4(0x15, w00 + 0xec). All final calls are tail calls.
 * Source form: two separate ifs with their own FUN_a00a73ac call (GCC merges the call tails); every
 * access names ARR_a807db00[p] directly.
 */
struct PortRec { unsigned int w00; unsigned int w04; unsigned int w08; unsigned int w0c; unsigned char pad[0x34 - 0x10]; };
extern struct PortRec ARR_a807db00[];
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);
extern void FUN_a00a73ac(unsigned int, unsigned int);
extern void FUN_a00a73d4(unsigned int, unsigned int);

void FUN_a009740c(unsigned int port)
{
    unsigned char p = port;

    if (FUN_a00a7408(8, ARR_a807db00[p].w0c + 0x60) && FUN_a00a7408(0x11, ARR_a807db00[p].w0c + 0x74)) {
        FUN_a00a73ac(0x10, ARR_a807db00[p].w04 + 0x34);
        return;
    }
    if (!FUN_a00a7408(0x11, ARR_a807db00[p].w0c + 0x74) && FUN_a00a7408(0x10, ARR_a807db00[p].w0c + 0x74)) {
        FUN_a00a73ac(0x10, ARR_a807db00[p].w04 + 0x34);
        return;
    }
    FUN_a00a73d4(0x10, ARR_a807db00[p].w04 + 0x34);
    if (FUN_a00a7408(0x14, ARR_a807db00[p].w00 + 0xec))
        FUN_a00a73d4(0x15, ARR_a807db00[p].w00 + 0xec);
}
