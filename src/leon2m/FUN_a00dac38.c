/* leon2m FUN_a00dac38 @ 0xa00dac38  SYSAPI_GetPanelParamStruct = the panel row picker
 * (hand; -O3).
 *
 * off = 20 (5 when FUN_a0145af8(2) == 1). Reads vfreq (tenths of Hz, id 1), hfreq (id 0) and active lines (id 10) via
 * FUN_a0145660(0, n) (ids 8 and 7 are read and ignored).
 * force == 1: if the current row (FUN_a01295c4) is not 1: select row 1 (FUN_a01295b8), copy PANEL_ROWS[row] (0x58
 *   bytes from 0x198380) and apply it with FUN_a01483f4(&row, 1), then FUN_a0107e44(0xA802E3D3 != 0, 0xA802E3CA, 1).
 * otherwise: prints 'hfrq(%d) = %d', 'active_in(%d) = %d', 'vfreq(%d) = %d' (port from FUN_a0108e54), then
 *   'scaler_hfrq_out = %d' (p0 / 1000) and 'Vfreq %d %d %d' (p0 / 2348 three times; p0 is only ever 0 or 1).
 *   Input class 0xA802E1A7 == 0 or 2:
 *     h = (u16)hfreq * 2160 / (u16)active * 1000, or (u16)hfreq * 1000 when active is 0 (2160 = panel height; the
 *     MAG 271QPX build has 1440 here);
 *     FUN_a0148540(0) != 0: mode by line rate: h / 2348 <= 699 -> 2, <= 1299 -> 1, else 0;
 *     otherwise by refresh: vfreq < off + 600 -> 2, < off + 1200 -> 1, else 0;
 *     if mode differs from the current row: select it, copy and apply it with FUN_a01483f4(&row, 1).
 *   Any other class: as the force path but FUN_a01483f4(&row, 0).
 * Always ends printing 'SYSAPI_GetPanelParamStruct %x,%x' with FUN_a0126878() and the current row.
 * Row 2 (the 60 Hz row) is chosen below 62.0 Hz (refresh path) or for h/2348 <= 699 (line-rate path); FW.012
 *   had only the refresh path and no row 2. The two limits are the immediates 0x2bb (699) and 0x258 (600).
 * Callers (all four call sites, void to each): FUN_a008454c (1,1,0), FUN_a0127c78 (0,1,0) twice, FUN_a01295e4 (1,1,1).
 * keys: -O3; the line-rate value written in ONE expression ((u16)hfreq * 2160 / a * 1000, with
 *   a = (u16)active held in an unsigned int), so gcc reuses the zero-extended active from its print; the callees'
 *   real signatures (FUN_a01295c4 unsigned char, FUN_a0126878 unsigned short, FUN_a0145af8 unsigned short), but
 *   FUN_a0145660 declared int-returning (the original extends its results at the uses).
 */
struct PanelRow { unsigned long long q[11]; };
extern struct PanelRow DAT_00198380[];
#define PANEL_ROWS DAT_00198380
extern unsigned char DAT_a802e1a7, DAT_a802e3d3;
extern unsigned short DAT_a802e3ca;
extern unsigned short FUN_a0145af8(unsigned int);
extern int FUN_a0145660(int, int);
extern unsigned int FUN_a0108e54(void);
extern int FUN_a00df170();
extern char s_00198950[], s_00198970[], s_00198990[], s_001989b0[], s_001989d8[], s_001989f8[];
extern unsigned char FUN_a0148540(unsigned char);
extern unsigned char FUN_a01295c4(void);
extern void FUN_a01295b8(unsigned char);
extern void FUN_a01483f4(struct PanelRow *, unsigned char);
extern unsigned short FUN_a0126878(void);
extern void FUN_a0107e44(int, unsigned short, int);

void FUN_a00dac38(unsigned int hfrq_out, int unused, unsigned char force)
{
    struct PanelRow row;
    unsigned char off = 20;
    int vfreq, hfreq, active;
    unsigned int h;
    unsigned char mode;
    int cur;

    if ((unsigned short)FUN_a0145af8(2) == 1) off = 5;
    FUN_a0145660(0, 8);
    FUN_a0145660(0, 7);
    vfreq = FUN_a0145660(0, 1);
    hfreq = FUN_a0145660(0, 0);
    active = FUN_a0145660(0, 10);
    if (force == 1) {
        if ((unsigned char)FUN_a01295c4() != 1) {
            FUN_a01295b8(1);
            row = PANEL_ROWS[(unsigned char)FUN_a01295c4()];
            FUN_a01483f4(&row, 1);
            FUN_a0107e44(DAT_a802e3d3 != 0, DAT_a802e3ca, 1);
        }
    } else {
        FUN_a00df170(s_00198970, (unsigned char)FUN_a0108e54(), (unsigned short)hfreq);
        FUN_a00df170(s_00198950, (unsigned char)FUN_a0108e54(), (unsigned short)active);
        FUN_a00df170(s_00198990, (unsigned char)FUN_a0108e54(), (unsigned short)vfreq);
        FUN_a00df170(s_001989b0, hfrq_out / 1000);
        FUN_a00df170(s_001989d8, hfrq_out / 2348, hfrq_out / 2348, hfrq_out / 2348);
        if (DAT_a802e1a7 == 0 || DAT_a802e1a7 == 2) {
            { unsigned int a = (unsigned short)active;
            if (a != 0) h = (unsigned short)hfreq * 2160 / a * 1000; else h = (unsigned short)hfreq * 1000; }
            if (FUN_a0148540(0) != 0) {
                if (h / 2348 <= 699) mode = 2;
                else if (h / 2348 <= 1299) mode = 1;
                else mode = 0;
            } else {
                if ((unsigned short)vfreq < off + 600) mode = 2;
                else if ((unsigned short)vfreq < off + 1200) mode = 1;
                else mode = 0;
            }
            if ((unsigned char)FUN_a01295c4() != mode) {
                FUN_a01295b8(mode);
                row = PANEL_ROWS[(unsigned char)FUN_a01295c4()];
                FUN_a01483f4(&row, 1);
            }
        } else if ((unsigned char)FUN_a01295c4() != 1) {
            FUN_a01295b8(1);
            row = PANEL_ROWS[(unsigned char)FUN_a01295c4()];
            FUN_a01483f4(&row, 0);
            FUN_a0107e44(DAT_a802e3d3 != 0, DAT_a802e3ca, 1);
        }
    }
    cur = FUN_a0126878();
    FUN_a00df170(s_001989f8, (unsigned short)cur, (unsigned char)FUN_a01295c4());
}
