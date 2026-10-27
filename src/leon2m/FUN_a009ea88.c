/* FUN_a009ea88 (leon2m 0xa009ea88-0xa009eaa4, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores 0x112 to the word DAT_a802afec, then calls FUN_a008e270() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3ea88 is stored in the data word 0xa8025bc4 (initialised data, file offset 0x0edbc4) and
 * data word 0xa8025bd4 (initialised data, file offset 0x0edbd4). It lies between FUN_a009ea78 and FUN_a009eaa4.
 * Source form: a void wrapper with a constant store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008e270(void);

void FUN_a009ea88(void)
{
    DAT_a802afec = 0x112;
    FUN_a008e270();
}
