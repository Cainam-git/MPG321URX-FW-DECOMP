/* FUN_a014a11c: sel 0 / 1 / 2: stores v into byte DAT_a802e3dc / DAT_a802e3dd / DAT_a802e3de and passes
 * (v * 200 + 50) / 100 + 0x38 (unsigned arithmetic, i.e. 2 * v + 0x38 rounded) as a u16 to FUN_a013b42c /
 * FUN_a013b44c / FUN_a013b46c (tail calls); other sel values do nothing. Callers include FUN_a00d45f8,
 * FUN_a00d462c, FUN_a00d972c, FUN_a00d9764.
 */
extern unsigned char DAT_a802e3dc, DAT_a802e3dd, DAT_a802e3de;
extern void FUN_a013b42c(unsigned short v);
extern void FUN_a013b44c(unsigned short v);
extern void FUN_a013b46c(unsigned short v);

void FUN_a014a11c(unsigned char sel, unsigned char v)
{
    switch (sel) {
    case 0:
        DAT_a802e3dc = v;
        FUN_a013b42c((v * 200u + 50) / 100 + 0x38);
        break;
    case 1:
        DAT_a802e3dd = v;
        FUN_a013b44c((v * 200u + 50) / 100 + 0x38);
        break;
    case 2:
        DAT_a802e3de = v;
        FUN_a013b46c((v * 200u + 50) / 100 + 0x38);
        break;
    }
}
