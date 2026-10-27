/* FUN_a009ea40 (leon2m 0xa009ea40-0xa009ea5c, 28 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores 0x111 to the word DAT_a802afec, then calls FUN_a008a794() as a tail call; the nop after it is the -g line
 * nop. Its CPU address 0x3ea40 is stored in the data word 0xa8025bd0 (initialised data, file offset 0x0edbd0). It
 * lies between FUN_a009ea24 and FUN_a009ea5c. Source form: a void wrapper with a constant store before the call.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008a794(void);

void FUN_a009ea40(void)
{
    DAT_a802afec = 0x111;
    FUN_a008a794();
}
