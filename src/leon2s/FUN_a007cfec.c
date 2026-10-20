/* leon2s FUN_a007cfec @ 0xa007cfec-0xa007d054 (26 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/26 mismatches. Twin of FUN_a007af04.
 * Code facts: FUN_a0073520(p) != 0 -> returns FUN_a00a7408(0x10, ARR_a807db00[p != 2].w0c + 0x74) != 0
 * (0x34-byte port records); else returns FUN_a00a657c(p, 0x2f6) & 1 (bit 0 of the read).
 * Fixes vs the autoc draft (51.85): real base ARR_a807db00 (not a807db0c), a657c's RESULT is masked
 * (the draft masked the port), the != 0 arm first, the index as a separate local inside the arm
 * (the af04 form: keeps xor/addx/smul 0x34). Aids: none.
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
