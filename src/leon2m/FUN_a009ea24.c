/* FUN_a009ea24 (leon2m 0xa009ea24-0xa009ea40, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores 0x111 to the word DAT_a802afec, then calls FUN_a008d2f8() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3ea24 is stored in the data word 0xa8024244 (initialised data, file offset 0x0ec244) and
 * data word 0xa8024254 (initialised data, file offset 0x0ec254) and data word 0xa8025c24 (initialised data, file
 * offset 0x0edc24). It lies between FUN_a009ea08 and FUN_a009ea40. Source form: a void wrapper with a constant
 * store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008d2f8(void);

void FUN_a009ea24(void)
{
    DAT_a802afec = 0x111;
    FUN_a008d2f8();
}
