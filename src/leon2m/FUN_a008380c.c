/* leon2m FUN_a008380c @ 0xa008380c  APPGetFRCMode (hand; BYTE-EXACT at -mcpu=v8 -O3, no -g;
 * jf 100 %, rawcmp 165 words 0 mismatches)
 *
 * Chooses the frame-rate-conversion (FRC) mode 0..3 for display channel 0 and prints "APPGetFRCMode %x"
 * (string 0xFEED8). Bit 0 of the result goes to FUN_a0148e34, bit 1 to FUN_a0148eb4 (both via pointer-table
 * callers FUN_a0083aa0 / FUN_a0083abc); they set bits 27 / 26 of 0xA802E3D0.
 * Inputs: vfreq = FUN_a0145660(0, 1) (tenths of Hz), ids 7 and 8 of the input record, w = FUN_a014837c(1)
 * (halfword +0x0A of the raw panel row), the active transformed row (DAT_a802d6a4: vf_min +0x4E, vf_max +0x50).
 *   special flag FUN_a014e010() (bit 19 of 0xA802DFA0) == 1: mode 0 outside (vf_min - 2.0 Hz, vf_max + 2.0 Hz);
 *       inside: 1, except an 800x600 input (ids 7/8 = 800/600) below 62.0 Hz gives 0.
 *   otherwise: tentative mode 2 when byte 0xA802D2AF == 0, else 0; port flag FUN_a01485e0(0) set -> 0;
 *       vfreq outside [vf_min - 2.0 Hz, vf_max + 2.0 Hz] -> 0;
 *       0xA802D2AF == 0 and byte 0xA802D434 in 4..6 or 8: 1 for 4..6 (keeps the tentative mode when it is 4 and
 *       id 8 == w), 0 for 8;
 *       else FUN_a0148540(0) and vfreq <= 240.0 Hz and chip variant FUN_a011cf88() <= 0x82 -> 3;
 *       else (FUN_a0148540(0) or byte 0xA802D295) and no bits 12-15 in word 0xA802D2C4 and 0xA802D2AF <= 1 -> 2;
 *       else the tentative mode.
 * The only refresh-rate condition is the +-2.0 Hz window around the active row; on the <62 Hz row that is
 * 46.0..62.0 Hz.
 * Body written instruction by instruction from the original (control flow: e010 == 1 path with <= / >= limits and
 *   the 800x600 case; other path with < / > limits, b1f / b1a4 / 0x95f / FUN_a011cf88 cases, goto out where the
 *   original returns early). Bit 0 of the result selects FRC Lock (via FUN_a0083aa0 -> FUN_a0148e34); FRC result
 *   bits: bit 0 -> 0xA802E3D0 bit 27, bit 1 -> bit 26 = FRC main bypass.
 * Source keys: input values held as int and cast (unsigned short) at use; natural if/else-if chain (gcc predicts
 *   '== const' false, which puts the special-flag path out of line); '(x7 == 800) & (x8 == 600)' with bitwise &;
 *   the 4..6 test as an unsigned char flag set in an if; the final mode as 'mode = 0; if (t <= 2) mode = 1;';
 *   the special path as 'if (in range) {...} else mode = 0;'.
 * BYTE-EXACT at '-mcpu=v8 -O3' (without -g; with -g only one trailing nop after the last call differs, the known
 *   no--g sign). Further levers: b is an unsigned char local, and the two identical "4..6 or 8" bodies are ONE
 *   body under 'if (in46 || DAT_a802d290.b1a4 == 8)'. Re-reading the field in the second operand keeps the || as
 *   two branches (a plain 'b == 8' lets gcc merge it into an orcc), and the 8 test then zero-extends b again,
 *   which produces the firmware's 'and %o5,0xff'.
 */

struct PanelParam { unsigned char b00[0x4e]; unsigned short vf_min, vf_max; unsigned char b52[6]; };
struct Frc { unsigned char b00[5]; unsigned char b05; unsigned char b06[0x19]; unsigned char b1f; unsigned char b20[0x14];
             unsigned int w34; unsigned char rest[0x16c]; unsigned char b1a4; };
extern struct PanelParam *DAT_a802d6a4;
extern struct Frc DAT_a802d290;
extern int FUN_a0145660(int, int);
extern int FUN_a014837c(int);
extern unsigned char FUN_a014e010(void);
extern unsigned char FUN_a01485e0(int);
extern unsigned char FUN_a0148540(int);
extern unsigned char FUN_a011cf88(void);
extern int FUN_a00df170();
extern char s_000feed8[];
unsigned char FUN_a008380c(void)
{
    int vf, x7, x8, w;
    unsigned char mode = 0;
    vf = FUN_a0145660(0, 1);
    FUN_a0145660(0, 0);
    x7 = FUN_a0145660(0, 7);
    x8 = FUN_a0145660(0, 8);
    w = FUN_a014837c(1);
    if (FUN_a014e010() == 1) {
        if ((unsigned short)vf > DAT_a802d6a4->vf_min - 20 && (unsigned short)vf < DAT_a802d6a4->vf_max + 20) {
            if (((unsigned short)x7 == 800) & ((unsigned short)x8 == 600)) { if ((unsigned short)vf > 0x26b) mode = 1; }
            else mode = 1;
        } else mode = 0;
    } else {
        if (DAT_a802d290.b1f == 0) mode = 2;
        if (FUN_a01485e0(0)) mode = 0;
        else if ((unsigned short)vf < DAT_a802d6a4->vf_min - 20 || (unsigned short)vf > DAT_a802d6a4->vf_max + 20) mode = 0;
        else {
            if (DAT_a802d290.b1f == 0) {
                unsigned char b = DAT_a802d290.b1a4;
                unsigned char in46 = 0;
                if ((unsigned char)(b - 4) <= 2) in46 = 1;
                if (in46 || DAT_a802d290.b1a4 == 8) {
                    if ((b == 4) & ((unsigned short)x8 == (unsigned short)w)) ; else { mode = 0; if ((unsigned char)(b - 4) <= 2) mode = 1; }
                    goto done;
                }
            }
            if (FUN_a0148540(0) && (unsigned short)vf <= 0x95f && FUN_a011cf88() <= 0x82) mode = 3;
            else if ((FUN_a0148540(0) || DAT_a802d290.b05) && !(DAT_a802d290.w34 & 0xf000) && DAT_a802d290.b1f <= 1) mode = 2;
        }
    }
done:
    FUN_a00df170(s_000feed8, mode);
    return mode;
}
