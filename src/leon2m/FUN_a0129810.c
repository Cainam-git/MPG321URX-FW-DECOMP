/* leon2m FUN_a0129810 @ 0xa0129810-0xa01298d8 (50 words). BYTE-EXACT: -mcpu=v8 -O3 -g, jf 100 match=True,
 * rawcmp 0/50.
 * What it does: switches the panel to ROM row 1 (the second 0x58-byte PanelRow of the 3-row table
 * DAT_00198380), once:
 *   was = DAT_a802d892.ch (read BEFORE the call: fw 'ldub [%i1+1]' in the call delay slot);
 *   v = FUN_a0108e54() (bit 7 of hardware register 0xcf011aa0, 0 or 1);
 *   if v == 1 and bit 26 (0x4000000) of the FRC config word DAT_a802e3d0 is clear and was == 0:
 *       DAT_a802d892.ch = v, FUN_a01483f4(row DAT_00198380[v], 1) (load the row into DAT_a802e378 and
 *       program the output timing), return 1;
 *   else return 0 (u8 flag, 'and %i0,1' at the join).
 * This path does not read the input rate; it applies the fixed ROM row 1 when FUN_a0108e54() == 1 and the bit-26 mode is off.
 * Lever: the row is passed BY VALUE: 'FUN_a01483f4(DAT_00198380[v], 1)' with the prototype
 * 'void FUN_a01483f4(struct PanelRow, unsigned char)'. The SPARC 32-bit ABI passes a struct argument as
 * a pointer to a caller-made stack copy, so the callee (src/leon2m/FUN_a01483f4.c, 'unsigned char *src')
 * sees the same pointer; the copy is now made by the call expansion (after the DAT_a802d892.ch store in
 * RTL order), which gives the fw sched2 order of the 11 ldd/std pieces and the stb. A named local copy
 * plus '&row' (92.00) gives the same instructions in another order.
 * Further levers: v as unsigned int, the row index v (not the constant 1: fw 'add %o5,0x58,%g1'),
 * nested ifs (an && chain is if-converted). Aids: none. volatile: none (no hardware register here).
 */
struct PanelRow {
    unsigned char b00[8];
    unsigned short f08;
    unsigned char b0a[6];
    unsigned long long clk_min;
    unsigned long long clk_max;
    unsigned short htot_min, htot_typ, htot_max;
    unsigned short f26, f28;
    unsigned short vtot_min, vtot_typ, vtot_max;
    unsigned char b30[0x18];
    unsigned short vf_at_min_clk, hf_min, hf_max, vf_min, vf_max;
    unsigned char b52[6];
};
struct FrcSm { unsigned short state:4; unsigned short sent:1; unsigned short req:1; unsigned short pad:2; unsigned char ch; unsigned short t; };
extern struct FrcSm DAT_a802d892;
extern const struct PanelRow DAT_00198380[3];
extern unsigned int DAT_a802e3d0;
extern unsigned char FUN_a0108e54(void);
extern void FUN_a01483f4(struct PanelRow, unsigned char);

unsigned char FUN_a0129810(void)
{
    unsigned char was, r;
    unsigned int v;

    was = DAT_a802d892.ch;
    v = FUN_a0108e54();
    r = 0;
    if (v == 1) {
        if (!(DAT_a802e3d0 & 0x4000000)) {
            if (was == 0) {
                DAT_a802d892.ch = v;
                FUN_a01483f4(DAT_00198380[v], 1);
                r = 1;
            }
        }
    }
    return r & 1;
}
