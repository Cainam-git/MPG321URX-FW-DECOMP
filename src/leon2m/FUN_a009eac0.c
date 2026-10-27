/* FUN_a009eac0 (leon2m 0xa009eac0-0xa009eadc, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores 0x112 to the word DAT_a802afec, then calls FUN_a008c25c() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3eac0 is stored in the data word 0xa8025be4 (initialised data, file offset 0x0edbe4). It
 * lies between FUN_a009eaa4 and FUN_a009eadc. Source form: a void wrapper with a constant store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008c25c(void);

void FUN_a009eac0(void)
{
    DAT_a802afec = 0x112;
    FUN_a008c25c();
}
