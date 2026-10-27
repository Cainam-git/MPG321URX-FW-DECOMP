/* FUN_a009eadc (leon2m 0xa009eadc-0xa009eaf8, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores 0x112 to the word DAT_a802afec, then calls FUN_a008b83c() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3eadc is stored in the data word 0xa8025be8 (initialised data, file offset 0x0edbe8). It
 * lies between FUN_a009eac0 and FUN_a009eaf8. Source form: a void wrapper with a constant store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008b83c(void);

void FUN_a009eadc(void)
{
    DAT_a802afec = 0x112;
    FUN_a008b83c();
}
