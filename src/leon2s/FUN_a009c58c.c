/* leon2s FUN_a009c58c @ 0xa009c58c (-mcpu=v8 -Os -g)
 * For the port byte p, reads the pointer in word 1 of the 0x34-byte (13-word) per-port record p at 0xA807DB00 and
 * returns the low 24 bits of the word at that pointer + 0x0C. Element indexing on the unsigned int array ([p * 13
 * + 1]) gives the smul and ld [%o0 + 4] of the target.
 */
extern unsigned int DAT_a807db00[];  // 0xa807db00

unsigned int FUN_a009c58c(unsigned int param_1)
{
    return (*(unsigned int *)(DAT_a807db00[(param_1 & 0xff) * 13 + 1] + 0xc)) & 0xffffff;
}
