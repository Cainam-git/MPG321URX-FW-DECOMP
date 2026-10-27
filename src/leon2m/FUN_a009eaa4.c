/* FUN_a009eaa4 (leon2m 0xa009eaa4-0xa009eac0, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores 0x111 to the word DAT_a802afec, then calls FUN_a008a95c() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3eaa4 is stored in the data word 0xa8025bdc (initialised data, file offset 0x0edbdc) and
 * data word 0xa8025be0 (initialised data, file offset 0x0edbe0) and data word 0xa8025bec (initialised data, file
 * offset 0x0edbec). It lies between FUN_a009ea88 and FUN_a009eac0. Source form: a void wrapper with a constant
 * store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008a95c(void);

void FUN_a009eaa4(void)
{
    DAT_a802afec = 0x111;
    FUN_a008a95c();
}
