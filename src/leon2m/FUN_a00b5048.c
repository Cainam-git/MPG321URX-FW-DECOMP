/* leon2m FUN_a00b5048 @ 0xa00b5048 (-mcpu=v8 -O2 -g)
 * Returns bit 3 of DAT_a802b08e (0 or 1) and clears that bit in memory (AND 0xF7). The byte is loaded once into an
 * unsigned int local that feeds both the AND for the store and the SRL for the return value; the unsigned int
 * locals give the target sequence ldub, and, srl, stb, and.
 */
extern unsigned char DAT_a802b08e;

unsigned int FUN_a00b5048(void)
{
    unsigned int val = DAT_a802b08e;
    unsigned int shifted = val >> 3;
    DAT_a802b08e = val & 0xf7;
    return shifted & 1;
}
