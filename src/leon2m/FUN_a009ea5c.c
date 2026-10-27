/* FUN_a009ea5c (leon2m 0xa009ea5c-0xa009ea78, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores 0x111 to the word DAT_a802afec, then calls FUN_a008a878() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3ea5c is stored in the data word 0xa8025bcc (initialised data, file offset 0x0edbcc). It
 * lies between FUN_a009ea40 and FUN_a009ea78. Source form: a void wrapper with a constant store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008a878(void);

void FUN_a009ea5c(void)
{
    DAT_a802afec = 0x111;
    FUN_a008a878();
}
