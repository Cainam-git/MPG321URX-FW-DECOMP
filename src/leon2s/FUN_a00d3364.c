/* leon2s FUN_a00d3364 @ 0xa00d3364-0xa00d3670 (195 words), flags -mcpu=v8 -Os -g.
 * int (void). For enEOTF_Type == 2 in DAT_a807d548: lum = u16Max_MasterLum when DAT_a8078c31 == 1 and it is
 * above DAT_a80779dc (then func_0xa0f72bac(DAT_a80779dc, lum, DAT_a8077a08)), else lum = DAT_a80779dc and
 * FUN_a00d264c(). DAT_a8078c39 = 7 for lum 0, 3 up to 1000, 4 up to 1500, 5 up to 2000, 6 up to 4000, else 7;
 * st = 2 for the values 3..6, else 0. DAT_a807d544 = lum; DAT_a80783dc = 256000, 384000, 512000, 1024000 or
 * (other values) 2560000 divided by lum (1 for lum 0, at most 10000), limited to 0xfff. For enEOTF_Type == 3
 * with bit 0 of DAT_a8078c30 set: FUN_a00d31f8() and returns 1. Then returns 0 unless func_0xa0f72f3c(1);
 * FUN_a00d2f20(DAT_a8078c39), func_0xa0f72b94(); returns 0 unless func_0xa0f72f3c(0); FUN_a00d3114(0, 0, 0, 0,
 * 0), func_0xa0f72b94(), FUN_a00d2378(DAT_a80783dc); bits 30..31 of the register word 0xd0013f6c written 0 then
 * 3 (read with func_0xa0f71528, field set with func_0xa0f714b8, written with func_0xa0f71534); bits 24..25 of
 * 0xd0013fdc = st & 2, then bits 30..31 of 0xd0013fdc written 0 then 3; FUN_a00d2d8c(); returns 1.
 * Source form: lum is unsigned int; the else arm (lum not above DAT_a80779dc) written first; st = 0 written in
 * both '7' arms; the limit as one conditional-expression assignment.
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
extern unsigned short DAT_a807d544;
extern unsigned char DAT_a8078c30, DAT_a8078c31, DAT_a8078c39;
extern unsigned short DAT_a80783dc, DAT_a80779dc;
extern unsigned short DAT_a8077a08[];
extern void func_0xa0f72bac(unsigned short, unsigned short, unsigned short *);
extern unsigned char func_0xa0f72f3c(int);
extern void func_0xa0f72b94(void);
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);
extern void func_0xa0f714b8(unsigned int *, unsigned int, unsigned int, unsigned int);
extern void FUN_a00d264c(void);
extern void FUN_a00d31f8(void);
extern void FUN_a00d2f20(unsigned char);
extern void FUN_a00d3114(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00d2378(unsigned int);
extern void FUN_a00d2d8c(void);

int FUN_a00d3364(void)
{
    unsigned int lum;
    unsigned char st = 0;
    unsigned int x;
    unsigned int w;

    if (DAT_a807d548.enEOTF_Type == 2) {
        if (DAT_a8078c31 == 1) {
            lum = DAT_a807d548.u16Max_MasterLum;
            if (lum <= DAT_a80779dc) {
                lum = DAT_a80779dc;
                FUN_a00d264c();
            } else
                func_0xa0f72bac(DAT_a80779dc, lum, DAT_a8077a08);
        } else {
            lum = DAT_a80779dc;
            FUN_a00d264c();
        }
        if (lum == 0) {
            DAT_a8078c39 = 7;
            st = 0;
        } else if (lum <= 1000) {
            DAT_a8078c39 = 3;
            st = 2;
        } else if (lum <= 1500) {
            DAT_a8078c39 = 4;
            st = 2;
        } else if (lum <= 2000) {
            DAT_a8078c39 = 5;
            st = 2;
        } else if (lum <= 4000) {
            DAT_a8078c39 = 6;
            st = 2;
        } else {
            DAT_a8078c39 = 7;
            st = 0;
        }
        DAT_a807d544 = lum;
        x = 1;
        if (lum != 0) {
            x = lum;
            if (lum > 10000)
                x = 10000;
        }
        if (DAT_a8078c39 == 3)
            DAT_a80783dc = 256000 / x;
        else if (DAT_a8078c39 == 4)
            DAT_a80783dc = 384000 / x;
        else if (DAT_a8078c39 == 5)
            DAT_a80783dc = 512000 / x;
        else if (DAT_a8078c39 == 6)
            DAT_a80783dc = 1024000 / x;
        else
            DAT_a80783dc = 2560000 / x;
        DAT_a80783dc = DAT_a80783dc > 0xfff ? 0xfff : DAT_a80783dc;
    } else if (DAT_a807d548.enEOTF_Type == 3) {
        if (DAT_a8078c30 & 1) {
            FUN_a00d31f8();
            return 1;
        }
    }
    if (!func_0xa0f72f3c(1))
        return 0;
    FUN_a00d2f20(DAT_a8078c39);
    func_0xa0f72b94();
    if (!func_0xa0f72f3c(0))
        return 0;
    FUN_a00d3114(0, 0, 0, 0, 0);
    func_0xa0f72b94();
    FUN_a00d2378(DAT_a80783dc);
    w = func_0xa0f71528(0xd0013f6c);
    func_0xa0f714b8(&w, 0x1f, 0x1e, 0);
    func_0xa0f71534(0xd0013f6c, w);
    func_0xa0f714b8(&w, 0x1f, 0x1e, 3);
    func_0xa0f71534(0xd0013f6c, w);
    w = func_0xa0f71528(0xd0013fdc);
    func_0xa0f714b8(&w, 0x19, 0x18, st & 2);
    func_0xa0f71534(0xd0013fdc, w);
    w = func_0xa0f71528(0xd0013fdc);
    func_0xa0f714b8(&w, 0x1f, 0x1e, 0);
    func_0xa0f71534(0xd0013fdc, w);
    func_0xa0f714b8(&w, 0x1f, 0x1e, 3);
    func_0xa0f71534(0xd0013fdc, w);
    FUN_a00d2d8c();
    return 1;
}
