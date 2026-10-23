/* DRV_HDMI21_Set_PHY_PreAEQ (leon2s 0xa007fffc-0xa0080244, 584 bytes, including the ret/restore tail),
 * flags -mcpu=v8 -Os -g.
 * Only for ports 2 and 3 (record index k = 0 / 1). Under bit 11 of DAT_a8078634 prints s_a0067868
 * ("[HDMI21]: \x1b[1m=%s=\n\x1b[m") with the function name. FUN_a0079f80(p) when byte 2 of the 0xb0-byte record
 * ARR_a807d680[k] is 4..6; FUN_a0079778(port, 1, 1). For channels i = 0..3 prints the "PreAEQ CH%d Set AEQ_R"
 * and "AEQ_C" values DAT_a00b3ae4[DAT_a807cc50[i]] and DAT_a00b3adc[DAT_a807cc60[i]] under the same bit and
 * writes FUN_a00a7488(port, DAT_a00b3b18[i], 0xff0000f0, (R & 0xf) | ((C & 0xffff) << 8)). Then
 * FUN_a0079778(port, 0, 1), FUN_a00b1794(1) and, when byte +0x34 of the record is set, the same call sequence
 * as DRV_HDMI21_ReStart_AEQ2 (FUN_a007a630, FUN_a007a6f0, the full != 0 block, FUN_a007f7c8 as sibling call).
 * Source form: the port appears as an unsigned char copy p, 'port & 0xff' in q (first part) and a later
 * unsigned char copy r; the first format string is a separate symbol (not next to the other two).
 */
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned char DAT_a807cc50[];
extern unsigned char DAT_a807cc60[];
extern unsigned int DAT_a00b3ae4[];
extern unsigned int DAT_a00b3adc[];
extern unsigned short DAT_a00b3b18[4];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern const char s_a0067868[];
extern void FUN_a0079f80(unsigned char);
extern void FUN_a0079778(unsigned char port, unsigned char on, unsigned char mode);
extern void FUN_a00a7488(unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(unsigned int);
extern void FUN_a007a630(unsigned char);
extern void FUN_a007a6f0(unsigned char);
extern void DRV_HDMI21_Print_SCDC_Error(unsigned char);
extern void FUN_a0079aac(unsigned char);
extern void FUN_a007f7c8(unsigned char);
extern void FUN_a007fa0c(unsigned char);
extern void FUN_a00798fc(unsigned char);
extern void FUN_a00799b8(unsigned char);
static const char fn_[] = "DRV_HDMI21_Set_PHY_PreAEQ";

void DRV_HDMI21_Set_PHY_PreAEQ(unsigned int port, unsigned char full)
{
    unsigned char p = port;
    unsigned char k;
    unsigned int q;
    unsigned char i;
    unsigned char r;

    if (p == 2)
        k = 0;
    else if (p == 3)
        k = 1;
    else
        return;
    if (DAT_a8078634 & 0x800)
        FUN_a0073044(s_a0067868, fn_);
    if ((unsigned char)(ARR_a807d680[k][2] - 4) <= 2)
        FUN_a0079f80(p);
    q = port & 0xff;
    FUN_a0079778(q, 1, 1);
    for (i = 0; i <= 3; i++) {
        if (DAT_a8078634 & 0x800)
            FUN_a0073044("[HDMI21]: ## jay debug ==> PreAEQ CH%d Set AEQ_R 0x%08lx ##\n", i, DAT_a00b3ae4[DAT_a807cc50[i]]);
        if (DAT_a8078634 & 0x800)
            FUN_a0073044("[HDMI21]: ## jay debug ==> PreAEQ CH%d Set AEQ_C 0x%08lx ##\n", i, DAT_a00b3adc[DAT_a807cc60[i]]);
        if (i <= 3)
            FUN_a00a7488(q, DAT_a00b3b18[i], 0xff0000f0,
                         (DAT_a00b3ae4[DAT_a807cc50[i]] & 0xf) | ((DAT_a00b3adc[DAT_a807cc60[i]] & 0xffff) << 8));
    }
    r = port;
    FUN_a0079778(r, 0, 1);
    FUN_a00b1794(1);
    if (ARR_a807d680[k][0x34] == 0)
        return;
    FUN_a007a630(r);
    FUN_a007a6f0(r);
    if (full) {
        DRV_HDMI21_Print_SCDC_Error(r);
        FUN_a0079aac(r);
        FUN_a007f7c8(r);
        FUN_a007fa0c(r);
        FUN_a00798fc(r);
        FUN_a00b1794(1);
        FUN_a00799b8(r);
        DRV_HDMI21_Print_SCDC_Error(r);
    }
    FUN_a007f7c8(r);
}
