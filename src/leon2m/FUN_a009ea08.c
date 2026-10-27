/* FUN_a009ea08 (leon2m 0xa009ea08-0xa009ea24, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores 0x10c to the word DAT_a802afec, then calls FUN_a00b87d4() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3ea08 is stored in the data word 0xa8024208 (initialised data, file offset 0x0ec208) and
 * data word 0xa802421c (initialised data, file offset 0x0ec21c). It lies between FUN_a009e9a8 and FUN_a009ea24.
 * Source form: a void wrapper with a constant store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a00b87d4(void);

void FUN_a009ea08(void)
{
    DAT_a802afec = 0x10c;
    FUN_a00b87d4();
}
