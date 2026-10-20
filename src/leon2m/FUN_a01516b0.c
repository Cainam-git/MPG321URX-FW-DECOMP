/* leon2m FUN_a01516b0 @ 0xa01516b0-0xa01517f4 (81 words). -mcpu=v8 -O3 -g.
 * (written from the asm).
 * What it does: GlobalModeHandler state A entry for channel ch ("SysTasksBeforeDisplay_byChannel %d"):
 *   1. log s_001a74c8 = "SysTasksBeforeDisplay_byChannel %d\r\n" with ch;
 *   2. pc = the 4-bit port field (bits 12..15 of word 0) of the channel record DAT_a802df30[ch] (ch 1..3,
 *      anything else uses record 0);
 *   3. if pc == 0 and FUN_a00fd820(0) (the port class of port 0) is 0xb1: FUN_a012fc20();
 *   4. if the port state FUN_a0142e8c(pc) (byte +9 of the 0x2a-byte DAT_a802e224 port entry) is not 5: look
 *      at the other channels i = 0..3 (i != ch) whose state nibble (bits 28..31) is 0xc and stop at the first
 *      one whose port state FUN_a0142e8c(its port) is not 5 (the loop only calls FUN_a0142e8c; it changes nothing);
 *   5. FUN_a012fcf4() (GMDHEnableFRC, no arguments: its asm never reads %i0..%i5) as a tail call on every path.
 * Nothing here reads the input rate; it is the per-channel entry step before display,
 * and always ends in the FRC enable FUN_a012fcf4.
 * Lever: the record switch in the order 'case 0: default:', 1, 2, 3 (rnreg follows source block order:
 * fw case registers %o5/%o1/%o2/%o3; other orders swap them). Callee prototypes from src/leon2m.
 * volatile: none. Aids: none.
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x78 - 0x04];
};
extern struct Chan DAT_a802df30[4];
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char FUN_a0142e8c(unsigned int);
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a012fc20(void);
extern void FUN_a012fcf4(void);
extern char s_001a74c8[];

void FUN_a01516b0(unsigned char ch)
{
    unsigned char pc, i;

    FUN_a00df170(s_001a74c8, ch);
    switch (ch) {
    case 0: default: pc = DAT_a802df30[0].u.b.port; break;
    case 1: pc = DAT_a802df30[1].u.b.port; break;
    case 2: pc = DAT_a802df30[2].u.b.port; break;
    case 3: pc = DAT_a802df30[3].u.b.port; break;
    }
    if (pc == 0) {
        if (FUN_a00fd820(0) == 0xb1)
            FUN_a012fc20();
    }
    if (FUN_a0142e8c(pc) != 5) {
        for (i = 0; i < 4; i++) {
            if (i != ch && DAT_a802df30[i].u.b.state == 0xc && FUN_a0142e8c(DAT_a802df30[i].u.b.port) != 5)
                break;
        }
    }
    FUN_a012fcf4();
}
