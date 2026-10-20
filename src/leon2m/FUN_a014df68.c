/* FUN_a014df68: v = (u8)FUN_a01421c4(FUN_a0142218(FUN_a0125198(p))); bit 20 of the RAM word DAT_a802e3d0 = on;
 * v == 0x71: k = 0 and FUN_a0151aa4(0x10, 1); v == 0x81: k = 1 and FUN_a0151aa4(0x20, 1); otherwise nothing
 * more happens. With a k, tail-calls FUN_a012b8a8(k, bit 20 of DAT_a802e3d0). Callers: FUN_a008b83c,
 * FUN_a008c25c. Same source form as FUN_a014a654 (switch on v); bit 20 is a 1-bit bit-field.
 */
struct E3d0 { unsigned int b31_21 : 11, b20 : 1, rest : 20; };
extern struct E3d0 DAT_a802e3d0;
extern int FUN_a0125198(unsigned char);
extern void FUN_a012b8a8(unsigned char, unsigned char);
extern int FUN_a01421c4(unsigned char);
extern int FUN_a0142218(unsigned char);
extern void FUN_a0151aa4(unsigned int, unsigned int);

void FUN_a014df68(unsigned char p, unsigned int on)
{
    unsigned char v;
    unsigned char k;

    v = FUN_a01421c4(FUN_a0142218(FUN_a0125198(p)));
    DAT_a802e3d0.b20 = on;
    switch (v) {
    case 0x71:
        k = 0;
        FUN_a0151aa4(0x10, 1);
        break;
    case 0x81:
        k = 1;
        FUN_a0151aa4(0x20, 1);
        break;
    default:
        k = 0xff;
        break;
    }
    if (k != 0xff)
        FUN_a012b8a8(k, DAT_a802e3d0.b20);

}
