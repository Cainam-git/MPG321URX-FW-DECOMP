/* leon2m FUN_a0154750
 * Returns byte b of row a of the 42-byte table at 0x1a81cf. Same code as FUN_a015468c (11-byte rows at 0x1a7a6e).
 * This file is compiled unoptimised and without -mcpu=v8 (flags -g only): the row offset a * 42 is built from
 * shifts and adds, as SPARC v7 has no multiply instruction.
 */
extern const unsigned char DAT_001a81cf[][42];
unsigned char FUN_a0154750(unsigned short a, unsigned short b)
{
    return DAT_001a81cf[a][b];
}
