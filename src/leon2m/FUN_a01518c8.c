/* leon2m FUN_a01518c8 @ 0xa01518c8-0xa01519b4 (59 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/59 (hand, written from the asm).
 * What it does: GlobalModeHandler state 5 entry for channel ch:
 *   FUN_a01241fc() (getter of the active panel row 0xa802e378; its result is not used here);
 *   pc = the 4-bit port field of DAT_a802df30[ch] (ch 1..3; anything else uses record 0);
 *   FUN_a0118a80(pc, 0, 0, 0); FUN_a010aae8(pc, 0, 0, 0); FUN_a0106ba8(pc);
 *   clear bit 20 (0x100000) of the record's word at +0x68 (c->w68 &= ~0x100000);
 *   ch 0 only: FUN_a0109bbc(0, 0, 0, DAT_a802e3ca) (the FRC lock / free-run set-up, lock = 0, with the
 *   u16 at 0xa802e3ca as its vfreq argument);
 *   FUN_a01061c0(0) as a tail call.
 * Only the channel-0 call passes a rate (DAT_a802e3ca, lock 0 = free-run set-up); the rest does not read the rate.
 * Prototypes from the callees' asm: FUN_a010aae8(u8, u8, u8, int) void (and 0xff on %i0..%i2, %i3 unmasked;
 * an int-int-int-int declaration reorders the argument set-up), FUN_a0118a80(u8, u8, int, u8) void,
 * FUN_a0109bbc from src/leon2m. Lever: record switch 'case 0: default:', 1, 2, 3. volatile: none. Aids: none.
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x68 - 0x04];
    unsigned int w68;
    unsigned char p6c[0x78 - 0x6c];
};
extern struct Chan DAT_a802df30[4];
extern unsigned short DAT_a802e3ca;
extern unsigned char *FUN_a01241fc(void);
extern void FUN_a0118a80(unsigned char, unsigned char, int, unsigned char);
extern void FUN_a010aae8(unsigned char, unsigned char, unsigned char, int);
extern void FUN_a0106ba8(unsigned char);
extern void FUN_a01061c0(unsigned char);
extern void FUN_a0109bbc(unsigned char lock, unsigned char unused, unsigned short p3, unsigned short vfreq);

void FUN_a01518c8(unsigned char ch)
{
    unsigned char pc;

    FUN_a01241fc();
    switch (ch) {
    case 0: default: pc = DAT_a802df30[0].u.b.port; break;
    case 1: pc = DAT_a802df30[1].u.b.port; break;
    case 2: pc = DAT_a802df30[2].u.b.port; break;
    case 3: pc = DAT_a802df30[3].u.b.port; break;
    }
    FUN_a0118a80(pc, 0, 0, 0);
    FUN_a010aae8(pc, 0, 0, 0);
    FUN_a0106ba8(pc);
    DAT_a802df30[ch].w68 &= ~0x100000;
    if (ch == 0)
        FUN_a0109bbc(0, 0, 0, DAT_a802e3ca);
    FUN_a01061c0(0);
}
