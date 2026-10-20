/* leon2m FUN_a0124180 @ 0xa0124180-0xa01241fc (31 words), flags -mcpu=v8 -O3 -g.
 * What it does: the start-up default of the active panel row. It copies the 0x58-byte ROM default
 * row DAT_001a30d0 into the RAM row DAT_a802e378 (the row FUN_a01241fc returns and that the
 * rate code reads: h08/h0a sizes, the u16 fields at 0x4e/0x50/0x52). One struct assignment;
 * gcc expands it into 11 ldd/std pairs (one pair spilled to the frame, as in the fw).
 * Nothing input-dependent happens here; it only resets the row to the
 * ROM default before any mode is chosen.
 * Code facts used for the type: the fw copies with ldd/std, so both objects are 8-byte aligned;
 * the field layout is the one other src/leon2m files use for DAT_a802e378 (w0, h4, b6, b7, h08,
 * h0a, ..., h4e, h50, h52). An all-u64 array struct gives the same instructions but a different
 * sched2 slot for the spill reload (96.77); with the real mixed-field layout it is exact.
 * The row's real 64-bit fields (clk_min / clk_max at +0x10/+0x18, as in FUN_a01483f4) give the 8-byte alignment
 * that makes the fw use ldd/std, so no __attribute__((aligned(8))) aid is needed. Any struct with an 8-byte member
 * gives the same bytes.
 */
struct Row {
    unsigned int w0;
    unsigned short h4;
    unsigned char b6, b7;
    unsigned short h08, h0a;
    unsigned char b0c[4];
    unsigned long long clk_min, clk_max;
    unsigned char b20[0x2e];
    unsigned short h4e, h50, h52;
    unsigned char b54[4];
};
extern struct Row DAT_a802e378;
extern const struct Row DAT_001a30d0;

void FUN_a0124180(void)
{
    DAT_a802e378 = DAT_001a30d0;
}
