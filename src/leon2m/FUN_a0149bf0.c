/* leon2m FUN_a0149bf0 @ 0xa0149bf0  SYSAPI_ConfigSystemPIPMode(mode)
 * Flags: -mcpu=v8 -O3 -g over the REAL range 0xa0149bf0-0xa0149e8c, 668 bytes.
 *
 * RANGE: the asm header (and symbols/leon2m.splits.json "a0149bf0": "a0149db8") cut this function at its tail call;
 *   the 8-entry jump table (0xe34b4 + 0xA0060000 run-time offset) targets 0xa0149e5c (modes 0,2), 0xa0149e14 (1,5),
 *   0xa0149cf4 (3,6), 0xa0149db8 (4,7). "FUN_a0149db8" is one case body of this function, 0xa0149e14-0xa0149e8c
 *   two more. Judged with jf.py with the target range overridden (exact bytes incl. the jump-table
 *   proof of tools/exact.py).
 *
 * Code facts:
 *   PIP state block 0xA802E1A0 (byte +7 = 0xA802E1A7 = the current PIP/PBP mode; the panel row picker FUN_a00dac38 reads
 *   it as its input class). Window table 0xA802DF30, 4 entries of 0x78 bytes (+0x00 cfg word, bits 12-15 passed to
 *   FUN_a0101e24; +0x40 ctl word).
 *   1. Leaving mode 0 for any non-zero mode, or leaving mode 2 for any mode other than 0/2:
 *      FUN_a0107e44(0xA802E3D3 != 0, 0xA802E3CA, 1) (FRCConfigPostFRC).
 *   2. New mode 5..7: FUN_a01084a8(0, 1); FUN_a0109110(1).
 *   3. Mode changes: clear bit 30 of window 0's ctl word (0xA802DF70).
 *   4. Store the mode, print "SYSAPI_ConfigSystemPIPMode %d" (string s_001a6fd8).
 *   5. Per mode, FUN_a0101e24(window[i].cfg >> 12 & 0xf, on) for i = 0..3, windows switched on:
 *      modes 0,2: 1 window; 1,5: 2; 3,6: 3; 4,7: 4; any other value: none called.
 *   6. FUN_a010385c(1); FUN_a012f1ec(0..3, 2); FUN_a013129c(); FUN_a0118628(mode == 0 ? 2 : 3);
 *      tail call FUN_a0153970(&0xA802E1A0, 0).
 * Callers: FUN_a0096858 (several sites), FUN_a00c4ec4 (several sites), FUN_a00da254.
 * keys: (state == 0) & (mode != 0) with bitwise & (setcc + btst); the final call written as if/else with
 *   two calls (a ?: or a variable gives the addx / clr shapes); switch cases in natural order 0,2 / 1,5 / 3,6 / 4,7
 *   with four explicit calls each (gcc cross-jumps the shared tails); mode is an unsigned int parameter.
 */
struct PipWin { unsigned int cfg; unsigned char pad0[0x3c]; unsigned int ctl; unsigned char pad1[0x34]; };
struct PipState { unsigned char pad[7]; unsigned char mode; };
extern struct PipWin DAT_a802df30[4];
extern struct PipState DAT_a802e1a0;
extern unsigned char DAT_a802e3d3;
extern unsigned short DAT_a802e3ca;
extern const char s_001a6fd8[];
extern int FUN_a00df170();
extern void FUN_a0107e44(int, unsigned short, int);
extern void FUN_a01084a8(unsigned char, int);
extern void FUN_a0109110(unsigned char);
extern void FUN_a0101e24(unsigned int, unsigned char);
extern void FUN_a010385c(int);
extern void FUN_a012f1ec(int, int);
extern void FUN_a013129c(void);
extern void FUN_a0118628(int);
extern void FUN_a0153970(struct PipState *, unsigned char);

void FUN_a0149bf0(unsigned int mode)
{
    if (((DAT_a802e1a0.mode == 0) & (mode != 0)) || (DAT_a802e1a0.mode == 2 && ((mode != 2) & (mode != 0))))
        FUN_a0107e44(DAT_a802e3d3 != 0, DAT_a802e3ca, 1);
    if (mode - 5 <= 2) {
        FUN_a01084a8(0, 1);
        FUN_a0109110(1);
    }
    if (DAT_a802e1a0.mode != mode)
        DAT_a802df30[0].ctl &= ~0x40000000;
    DAT_a802e1a0.mode = mode;
    FUN_a00df170(s_001a6fd8, mode);
    switch (DAT_a802e1a0.mode) {
    case 0: case 2:
        FUN_a0101e24(DAT_a802df30[0].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[1].cfg >> 12 & 0xf, 0);
        FUN_a0101e24(DAT_a802df30[2].cfg >> 12 & 0xf, 0);
        FUN_a0101e24(DAT_a802df30[3].cfg >> 12 & 0xf, 0);
        break;
    case 1: case 5:
        FUN_a0101e24(DAT_a802df30[0].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[1].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[2].cfg >> 12 & 0xf, 0);
        FUN_a0101e24(DAT_a802df30[3].cfg >> 12 & 0xf, 0);
        break;
    case 3: case 6:
        FUN_a0101e24(DAT_a802df30[0].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[1].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[2].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[3].cfg >> 12 & 0xf, 0);
        break;
    case 4: case 7:
        FUN_a0101e24(DAT_a802df30[0].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[1].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[2].cfg >> 12 & 0xf, 1);
        FUN_a0101e24(DAT_a802df30[3].cfg >> 12 & 0xf, 1);
        break;
    }
    FUN_a010385c(1);
    FUN_a012f1ec(0, 2);
    FUN_a012f1ec(1, 2);
    FUN_a012f1ec(2, 2);
    FUN_a012f1ec(3, 2);
    FUN_a013129c();
    if (DAT_a802e1a0.mode == 0)
        FUN_a0118628(2);
    else
        FUN_a0118628(3);
    FUN_a0153970(&DAT_a802e1a0, 0);
}
