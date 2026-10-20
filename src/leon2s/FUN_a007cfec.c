/* leon2s FUN_a007cfec @ 0xa007cfec-0xa007d054 (26 words), flags -mcpu=v8 -Os -g.
 * Twin of FUN_a007af04.
 * FUN_a0073520(p) != 0 -> returns FUN_a00a7408(0x10, ARR_a807db00[p != 2].w0c + 0x74) != 0 (0x34-byte port
 * records); else returns FUN_a00a657c(p, 0x2f6) & 1 (bit 0 of the read result).
 * Source form: the != 0 arm first, and the index as a separate local inside that arm (the FUN_a007af04 form:
 * keeps xor/addx/smul 0x34).
 */
struct PortRec { unsigned char pad[0xc]; unsigned int w0c; unsigned char pad2[0x34 - 0x10]; };
extern struct PortRec ARR_a807db00[];
extern unsigned char FUN_a0073520(unsigned char);
extern unsigned int FUN_a00a657c(unsigned char, unsigned short);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int);

unsigned int FUN_a007cfec(unsigned char p)
{
    if (FUN_a0073520(p) != 0)
    {
        unsigned int i = p != 2;
        return FUN_a00a7408(0x10, ARR_a807db00[i].w0c + 0x74) != 0;
    }
    return FUN_a00a657c(p, 0x2f6) & 1;
}
