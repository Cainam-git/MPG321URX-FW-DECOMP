/* DRV_HDMI21_ReStart_AEQ2 (leon2s 0xa007fde0-0xa007fffc, 540 bytes, including the ret/restore tail),
 * flags -mcpu=v8 -Os -g.
 * Only for ports 2 and 3 (record index k = 0 / 1). Under bit 11 of DAT_a8078634 prints "[HDMI21]: \x1b[1m=%s=\n\x1b[m"
 * with the function name. rate = byte 1 of the 0xb0-byte record ARR_a807d680[k]; FUN_a0079f80(p) when byte
 * +0x34 is set; FUN_a0079778(port, 1, 1). For rate 4..6 and a non-zero lane mask, each lane i (0..3) with its
 * mask bit set gets FUN_a00a7488(port, 0x360c / 0x3610, 0xffff0000 / 0xffff, 0x3d0 / 0x3d00000) (register
 * 0x360c for lanes 0-1, 0x3610 for lanes 2-3; low half for even lanes, high half for odd lanes). Then
 * FUN_a0079778(port, 0, 1), FUN_a00a73ac(8, word 0 of ARR_a807db00[k] + 4), FUN_a00b1794(1),
 * FUN_a00a73d4(8, same). When byte +0x34 is set: FUN_a007a630, FUN_a007a6f0, and with full != 0 the sequence
 * DRV_HDMI21_Print_SCDC_Error, FUN_a0079aac, FUN_a007f7c8, FUN_a007fa0c, FUN_a00798fc, FUN_a00b1794(1),
 * FUN_a00799b8, DRV_HDMI21_Print_SCDC_Error; finally FUN_a007f7c8(port) (sibling call).
 * Source form: the port appears as an unsigned char copy p (port test), 'port & 0xff' (first FUN_a0079778
 * call and lane writes) and a later unsigned char copy q; the rate and mask tests are nested ifs.
 */
struct Port34 { unsigned int w0; unsigned char rest[0x34 - 4]; };
extern struct Port34 ARR_a807db00[];
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a0079f80(unsigned char);
extern void FUN_a0079778(unsigned char port, unsigned char on, unsigned char mode);
extern void FUN_a00a7488(unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a73ac(unsigned int, unsigned int);
extern void FUN_a00a73d4(unsigned int, unsigned int);
extern void FUN_a00b1794(unsigned int);
extern void FUN_a007a630(unsigned char);
extern void FUN_a007a6f0(unsigned char);
extern void DRV_HDMI21_Print_SCDC_Error(unsigned char);
extern void FUN_a0079aac(unsigned char);
extern void FUN_a007f7c8(unsigned char);
extern void FUN_a007fa0c(unsigned char);
extern void FUN_a00798fc(unsigned char);
extern void FUN_a00799b8(unsigned char);
static const char fn_[] = "DRV_HDMI21_ReStart_AEQ2";

void DRV_HDMI21_ReStart_AEQ2(unsigned int port, unsigned char mask, unsigned char full)
{
    unsigned char p = port;
    unsigned char k;
    unsigned char rate;
    unsigned char i;
    unsigned char q;

    if (p == 2)
        k = 0;
    else if (p == 3)
        k = 1;
    else
        return;
    if (DAT_a8078634 & 0x800)
        FUN_a0073044("[HDMI21]: \x1b[1m=%s=\n\x1b[m", fn_);
    rate = ARR_a807d680[k][1];
    if (ARR_a807d680[k][0x34])
        FUN_a0079f80(p);
    FUN_a0079778(port & 0xff, 1, 1);
    if ((unsigned char)(rate - 4) <= 2)
    if (mask) {
        for (i = 0; i <= 3; i++) {
            if ((mask >> i) & 1) {
                if (i == 0)
                    FUN_a00a7488(port & 0xff, 0x360c, 0xffff0000, 0x3d0);
                else if (i == 1)
                    FUN_a00a7488(port & 0xff, 0x360c, 0xffff, 0x3d00000);
                else if (i == 2)
                    FUN_a00a7488(port & 0xff, 0x3610, 0xffff0000, 0x3d0);
                else
                    FUN_a00a7488(port & 0xff, 0x3610, 0xffff, 0x3d00000);
            }
        }
    }
    q = port;
    FUN_a0079778(q, 0, 1);
    FUN_a00a73ac(8, ARR_a807db00[k].w0 + 4);
    FUN_a00b1794(1);
    FUN_a00a73d4(8, ARR_a807db00[k].w0 + 4);
    if (ARR_a807d680[k][0x34] == 0)
        return;
    FUN_a007a630(q);
    FUN_a007a6f0(q);
    if (full) {
        DRV_HDMI21_Print_SCDC_Error(q);
        FUN_a0079aac(q);
        FUN_a007f7c8(q);
        FUN_a007fa0c(q);
        FUN_a00798fc(q);
        FUN_a00b1794(1);
        FUN_a00799b8(q);
        DRV_HDMI21_Print_SCDC_Error(q);
    }
    FUN_a007f7c8(q);
}
