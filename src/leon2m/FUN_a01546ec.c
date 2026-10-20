/* leon2m FUN_a01546ec
 * Returns byte b of row a of the 26-byte table at 0x1a807d. Same code as FUN_a015468c (11-byte rows at 0x1a7a6e).
 * This file is compiled unoptimised and without -mcpu=v8 (flags -g only): the row offset a * 26 is built from
 * shifts and adds, as SPARC v7 has no multiply instruction.
 */
extern const unsigned char DAT_001a807d[][26];
unsigned char FUN_a01546ec(unsigned short a, unsigned short b)
{
    return DAT_001a807d[a][b];
}
