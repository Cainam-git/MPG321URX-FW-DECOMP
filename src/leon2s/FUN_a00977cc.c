/* leon2s FUN_a00977cc @ 0xa00977cc-0xa00977e8 (7 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0 mismatches / 7 words. Leaf (retl).
 * Code facts: halfword store: ARR_a807d7e0[u8 port] (400-byte records, smul 0x190) +0x32 = u16 value.
 * Fix vs the autoc draft (71.43): real base ARR_a807d7e0 as a 400-byte struct array (draft: ARR_a807d812 mid-
 * record name), u8/u16 params. Aids: none.
 */
struct R7E0 { unsigned char pad[0x32]; unsigned short h32; unsigned char pad2[400 - 0x34]; };
extern struct R7E0 ARR_a807d7e0[];

void FUN_a00977cc(unsigned char param_1, unsigned short param_2)
{
  ARR_a807d7e0[param_1].h32 = param_2;
}
