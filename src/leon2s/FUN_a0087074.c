/* leon2s FUN_a0087074 @ 0xa0087074  MATCH (-mcpu=v8 -Os -g)
 * The key change is the `+1` offset in the array index - that matches the `ldub [%g1 + 1]` instruction. The multiplication by 6 comes from the three adds (×2, ×3, ×6), and the comparison uses the XOR-with-zero trick.
 */
extern unsigned char ARR_a807cd2e[];

int FUN_a0087074(unsigned int param_1)
{
    return (ARR_a807cd2e[(param_1 & 0xff) * 6 + 1] ^ 0x14) == 0;
}
