/* 8051_bank1 FUN_CODE_45aa @ 0x45aa  FUN_CODE_45aa(ch) (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Callers: FUN_CODE_8a51 (0x8B36, 0x8B40). A fixed sequence of FUN_CODE_d884(ch, reg, value) calls (ch first, register
 * number second, value third) plus one FUN_CODE_c73e(ch, 0x87, 0x40, 1) call.
 * LARGE slots: ch 0xA4B4, then three byte locals a = 0 (0xA4B5), b = 1 (0xA4B6), c = 0 (0xA4B7), set at the start
 * and tested later; each test selects one of two call groups:
 *   a != 0: (0x85, 0), (0x87, 0x80), (0xAF, 1); else (0x85, 0), (0x87, 0), (0xAF, 0).
 *   b != 0: FUN_CODE_c73e(ch, 0x87, 0x40, 1); else the same with 0 (Keil merges the two calls).
 *   c != 0: 17 writes to 0xDD..0xEA, 0xF7..0xF9 ending with (0xEA, 0xFF); else (0xDD, 0), (0xEA, 0).
 * The values are listed in the code. ch is read back from its slot before every call (the option set without
 * REGFILE(R.ORC)); the last call is a tail jump (LJMP). Keil shares the common tails of both arms. No aids.
 */
void FUN_CODE_d884(unsigned char ch, unsigned char reg, unsigned char v);
void FUN_CODE_c73e(unsigned char bank, unsigned char idx, unsigned char mask, unsigned char set);

void FUN_CODE_45aa(unsigned char ch)
{
    unsigned char a, b, c;

    a = 0;
    b = 1;
    c = 0;
    FUN_CODE_d884(ch, 0x80, 0x12);
    FUN_CODE_d884(ch, 0x81, 0x14);
    FUN_CODE_d884(ch, 0x82, 0x84);
    FUN_CODE_d884(ch, 0x83, 0x81);
    FUN_CODE_d884(ch, 0x84, 0x01);
    FUN_CODE_d884(ch, 0x85, 0x00);
    FUN_CODE_d884(ch, 0x86, 0x01);
    FUN_CODE_d884(ch, 0x8a, 0x06);
    FUN_CODE_d884(ch, 0x8c, 0x0a);
    FUN_CODE_d884(ch, 0x8d, 0x84);
    FUN_CODE_d884(ch, 0x95, 0x41);
    FUN_CODE_d884(ch, 0x96, 0x00);
    FUN_CODE_d884(ch, 0x97, 0x77);
    FUN_CODE_d884(ch, 0x98, 0x77);
    FUN_CODE_d884(ch, 0x99, 0x81);
    FUN_CODE_d884(ch, 0x9a, 0x01);
    FUN_CODE_d884(ch, 0x9b, 0x11);
    FUN_CODE_d884(ch, 0x9c, 0x11);
    FUN_CODE_d884(ch, 0xc2, 0x41);
    if (a) {
        FUN_CODE_d884(ch, 0x85, 0x00);
        FUN_CODE_d884(ch, 0x87, 0x80);
        FUN_CODE_d884(ch, 0xaf, 0x01);
    } else {
        FUN_CODE_d884(ch, 0x85, 0x00);
        FUN_CODE_d884(ch, 0x87, 0x00);
        FUN_CODE_d884(ch, 0xaf, 0x00);
    }
    FUN_CODE_d884(ch, 0xbc, 0x00);
    FUN_CODE_d884(ch, 0xc3, 0x00);
    FUN_CODE_d884(ch, 0xfc, 0x01);
    if (b) {
        FUN_CODE_c73e(ch, 0x87, 0x40, 1);
    } else {
        FUN_CODE_c73e(ch, 0x87, 0x40, 0);
    }
    if (c) {
        FUN_CODE_d884(ch, 0xdd, 0x0d);
        FUN_CODE_d884(ch, 0xde, 0x21);
        FUN_CODE_d884(ch, 0xdf, 0x00);
        FUN_CODE_d884(ch, 0xe0, 0x76);
        FUN_CODE_d884(ch, 0xe1, 0xab);
        FUN_CODE_d884(ch, 0xe2, 0x01);
        FUN_CODE_d884(ch, 0xe3, 0x01);
        FUN_CODE_d884(ch, 0xf7, 0x40);
        FUN_CODE_d884(ch, 0xf8, 0x82);
        FUN_CODE_d884(ch, 0xe4, 0x1f);
        FUN_CODE_d884(ch, 0xe5, 0x0e);
        FUN_CODE_d884(ch, 0xe6, 0x22);
        FUN_CODE_d884(ch, 0xe7, 0x08);
        FUN_CODE_d884(ch, 0xe8, 0x01);
        FUN_CODE_d884(ch, 0xf9, 0xf5);
        FUN_CODE_d884(ch, 0xe9, 0x4c);
        FUN_CODE_d884(ch, 0xea, 0xff);
    } else {
        FUN_CODE_d884(ch, 0xdd, 0x00);
        FUN_CODE_d884(ch, 0xea, 0x00);
    }
    FUN_CODE_d884(ch, 0xae, 0x07);
    FUN_CODE_d884(ch, 0xeb, 0x00);
    FUN_CODE_d884(ch, 0xa7, 0x01);
}
