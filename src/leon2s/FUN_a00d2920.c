/* leon2s FUN_a00d2920 @ 0xa00d2920-0xa00d2b88, -mcpu=v8 -Os -g.
 * void (void). Code linked 0xF10000 above its load address: calls go to func_0xa0f7.... / 0xa0f8.... /
 * 0xa0fc.... and the strings are named by their link addresses (s_9f1c...: "[Static HDR]..." texts at
 * 0xa00d6268.. in the image). Register word 0xd0013ff0 (func_0xa0f71528 reads, func_0xa0f71534 writes):
 * 0x55: write 0, DAT_a8078c38 = 0, print "Re-apply HDR!" and pass "\n" to func_0xa0f71280. 2: write 0, print
 * enEOTF_Type / u16Max_MasterLum / u16MaxCLL of DAT_a807d548 (word +4, halfwords +0x1c, +0x20), gu8HDR_Mode
 * (DAT_a8078c38), u8EOTFMode (DAT_a8078c39), ucHDRSource (DAT_a8078c37), u16HDRGain (DAT_a80783dc) and
 * PanelMaxLum (DAT_a80779dc); then the TMO LUT read-back of FUN_a0061adc on 0xd0013f60 / 0xd0013f64 with
 * func_0xa0f714b8 field writes and func_0xa0fc1794 waits, printing g_usRealTMO[i] (DAT_a8077a08[i]) for
 * i = 0, 0x10, .. 0x100; "\n"; finally bits 0 and 20 of 0xd0013f60 cleared.
 * Source form: i = 0 at its declaration (the firmware sets it before the first test).
 */
struct HdrInfo {
    unsigned int w0;
    unsigned int enEOTF_Type;
    unsigned char _8[0x1c - 8];
    unsigned short u16Max_MasterLum;
    unsigned char _1e[2];
    unsigned short u16MaxCLL;
};
extern struct HdrInfo DAT_a807d548;
extern unsigned char DAT_a8078c37, DAT_a8078c38, DAT_a8078c39;
extern unsigned short DAT_a80783dc, DAT_a80779dc;
extern unsigned short DAT_a8077a08[];
extern const char s_9f1c6268[];
extern const char s_9f1c6278[];
extern const char s_9f1c62a0[];
extern const char s_9f1c62d0[];
extern const char s_9f1c62f8[];
extern const char s_9f1c6318[];
extern const char s_9f1c6338[];
extern const char s_9f1c6358[];
extern const char s_9f1c6378[];
extern const char s_9f1c6398[];
extern const char s_9f1c63b8[];
extern const char s_9f1cca78[];
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);
extern void func_0xa0f714b8(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void func_0xa0f71280(const char *);
extern void func_0xa0fc1794(unsigned int);
extern int func_0xa0f83044(const char *, ...);

void FUN_a00d2920(void)
{
    unsigned int w = 0;
    unsigned int i = 0;

    if (func_0xa0f71528(0xd0013ff0) == 0x55) {
        func_0xa0f71534(0xd0013ff0, 0);
        DAT_a8078c38 = 0;
        func_0xa0f83044(s_9f1c6268);
        func_0xa0f71280(s_9f1cca78);
        return;
    }
    if (func_0xa0f71528(0xd0013ff0) != 2)
        return;
    func_0xa0f71534(0xd0013ff0, 0);
    func_0xa0f83044(s_9f1c6278, DAT_a807d548.enEOTF_Type);
    func_0xa0f83044(s_9f1c62a0, DAT_a807d548.u16Max_MasterLum);
    func_0xa0f83044(s_9f1c62d0, DAT_a807d548.u16MaxCLL);
    func_0xa0f83044(s_9f1c62f8, DAT_a8078c38);
    func_0xa0f83044(s_9f1c6318, DAT_a8078c39);
    func_0xa0f83044(s_9f1c6338, DAT_a8078c37);
    func_0xa0f83044(s_9f1c6358, DAT_a80783dc);
    func_0xa0f83044(s_9f1c6378, DAT_a80779dc);
    w = func_0xa0f71528(0xd0013f60);
    func_0xa0f714b8(&w, 0, 0, 1);
    func_0xa0f714b8(&w, 0x14, 0x14, 1);
    func_0xa0f714b8(&w, 0x10, 8, 0);
    func_0xa0f71534(0xd0013f60, w);
    for (; i <= 0x100; i += 0x10) {
        func_0xa0f714b8(&w, 0, 0, 1);
        func_0xa0f714b8(&w, 0x10, 8, i);
        func_0xa0f71534(0xd0013f60, w);
        func_0xa0fc1794(5);
        func_0xa0f71534(0xd0013f60, w);
        func_0xa0fc1794(5);
        func_0xa0f71534(0xd0013f60, w);
        func_0xa0fc1794(10);
        func_0xa0f83044(s_9f1c6398, i, func_0xa0f71528(0xd0013f64));
        func_0xa0f83044(s_9f1c63b8, i, DAT_a8077a08[i]);
    }
    func_0xa0f71280(s_9f1cca78);
    w = func_0xa0f71528(0xd0013f60);
    func_0xa0f714b8(&w, 0, 0, 0);
    func_0xa0f714b8(&w, 0x14, 0x14, 0);
    func_0xa0f71534(0xd0013f60, w);
}
