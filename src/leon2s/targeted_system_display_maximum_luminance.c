/* leon2s targeted_system_display_maximum_luminance @ 0xa0061adc-0xa0061d60, -mcpu=v8 -Os -g.
 * void (void). When FUN_a0061528 reads 1 from the register 0xd0013ff0: writes 0 to it (FUN_a0061534) and prints
 * "[Dynamic HDR]..." lines through FUN_a0073044 for targeted_system_display_maximum_luminance (halfword +0x88 of
 * DAT_a8078aa0), num_bezier_curve_anchors (byte +0x58), knee_point_x / knee_point_y (halfwords +2 / +4),
 * g_SceneMaxL (DAT_a8076680), g_SenceProductMax (DAT_a807667c), g_stDISP_Info.u16MaxLum (DAT_a8078a90) and
 * tone_mapping_flag (byte +1); for i = 0..8 the "Metadata" anchor ((*DAT_a807cd74)(DAT_a8078a38, i + 0x275) << 2)
 * and the "Guided" anchor (halfword i at +0x5a). Then, on the word w of the register 0xd0013f60 (read with
 * FUN_a0061528, fields set with FUN_a0061a6c(&w, hi, lo, v), written back with FUN_a0061534): bits 0 and 20 set,
 * bits 8..16 cleared; for i = 0, 0x10, .. 0x100: bit 0 set, bits 8..16 = i, w written three times with
 * FUN_a00b1794(5), (5), (10) waits, prints TMO_LUT[i] (register 0xd0013f64) and g_usTMOBuf[i] (DAT_a8076278[i]);
 * finally bits 0 and 20 cleared.
 * Source forms: w = 0 before the first write; i is set to 0 before the last header print; FUN_a0061a6c is
 * declared void here (its result is not used; an int return reorders the argument set-up).
 */
struct HdrMeta {
    unsigned char _0;
    unsigned char tone_mapping_flag;
    unsigned short knee_point_x;
    unsigned short knee_point_y;
    unsigned char _6[0x58 - 6];
    unsigned char num_bezier_curve_anchors;
    unsigned char _59;
    unsigned short bezier_curve_anchor[(0x88 - 0x5a) / 2];
    unsigned short targeted_system_display_maximum_luminance;
};
extern struct HdrMeta DAT_a8078aa0;
extern unsigned int DAT_a8076680, DAT_a807667c, DAT_a8078a90;
extern unsigned int DAT_a8076278[];
extern unsigned char DAT_a8078a38;
extern unsigned char (*DAT_a807cd74)(unsigned char, unsigned short);
extern unsigned int FUN_a0061528(volatile unsigned int *);
extern void FUN_a0061534(volatile unsigned int *, unsigned int);
extern void FUN_a0061a6c(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void FUN_a00b1794(unsigned short);
extern int FUN_a0073044(const char *, ...);

#define REG_D0013F60 ((volatile unsigned int *)0xd0013f60)
#define REG_D0013F64 ((volatile unsigned int *)0xd0013f64)
#define REG_D0013FF0 ((volatile unsigned int *)0xd0013ff0)

void targeted_system_display_maximum_luminance(void)
{
    unsigned int w;
    unsigned int i;

    if (FUN_a0061528(REG_D0013FF0) != 1)
        return;
    w = 0;
    FUN_a0061534(REG_D0013FF0, 0);
    FUN_a0073044("[Dynamic HDR]targeted_system_display_maximum_luminance=%d\n",
                 DAT_a8078aa0.targeted_system_display_maximum_luminance);
    FUN_a0073044("[Dynamic HDR]num_bezier_curve_anchors=%d\n", DAT_a8078aa0.num_bezier_curve_anchors);
    FUN_a0073044("[Dynamic HDR]knee_point_x=%d\n", DAT_a8078aa0.knee_point_x);
    FUN_a0073044("[Dynamic HDR]knee_point_y=%d\n", DAT_a8078aa0.knee_point_y);
    FUN_a0073044("[Dynamic HDR]g_SceneMaxL=%d\n", DAT_a8076680);
    FUN_a0073044("[Dynamic HDR]g_SenceProductMax=%d\n", DAT_a807667c);
    FUN_a0073044("[Dynamic HDR]g_stDISP_Info.u16MaxLum=%d\n", DAT_a8078a90);
    i = 0;
    FUN_a0073044("[Dynamic HDR]g_stMetaData10Plus.tone_mapping_flag=%d\n", DAT_a8078aa0.tone_mapping_flag);
    for (; i <= 8; i++) {
        FUN_a0073044("[Dynamic HDR]Metadata bezier_curve_anchor[%d]=%d\n", i,
                     DAT_a807cd74(DAT_a8078a38, i + 0x275) << 2);
        FUN_a0073044("[Dynamic HDR]Guided bezier_curve_anchor[%d]=%d\n", i, DAT_a8078aa0.bezier_curve_anchor[i]);
    }
    w = FUN_a0061528(REG_D0013F60);
    FUN_a0061a6c(&w, 0, 0, 1);
    FUN_a0061a6c(&w, 0x14, 0x14, 1);
    FUN_a0061a6c(&w, 0x10, 8, 0);
    FUN_a0061534(REG_D0013F60, w);
    for (i = 0; i <= 0x100; i += 0x10) {
        FUN_a0061a6c(&w, 0, 0, 1);
        FUN_a0061a6c(&w, 0x10, 8, i);
        FUN_a0061534(REG_D0013F60, w);
        FUN_a00b1794(5);
        FUN_a0061534(REG_D0013F60, w);
        FUN_a00b1794(5);
        FUN_a0061534(REG_D0013F60, w);
        FUN_a00b1794(10);
        FUN_a0073044("[Dynamic HDR]   TMO_LUT[%d]=%d\n", i, FUN_a0061528(REG_D0013F64));
        FUN_a0073044("[Dynamic HDR]g_usTMOBuf[%d]=%d\n", i, DAT_a8076278[i]);
    }
    w = FUN_a0061528(REG_D0013F60);
    FUN_a0061a6c(&w, 0, 0, 0);
    FUN_a0061a6c(&w, 0x14, 0x14, 0);
    FUN_a0061534(REG_D0013F60, w);
}
