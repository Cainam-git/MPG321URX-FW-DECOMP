/* leon2m FUN_a0121f58 @ 0xa0121f58 (-mcpu=v8 -O3 -g, gcc 3.4.4; autoc, finished by hand)
 * Vx1 transmitter block set-up (part of the panel-link set-up FUN_a01227f0, its only caller).
 * First a fixed register sequence (0xCF01CFA8 = 0, 0xCF01CF9C = 0x70, 0xCF01CF94 = 0x82, 0xCF01CFA0 = 0x62,
 * 0xCF01CF9C = 0x30, 0xCF01CF98 = 2, 0xCF01CC58 = 1), then per display mode = byte +6 of the active, transformed panel
 * row (DAT_a802d6a4, written by DispModeTransform):
 *   modes 5..7  -> one of the four transmitter blocks (register stride 0x8C) is switched on,
 *   modes 8..10 -> two blocks,   any other mode -> all four blocks.
 * On FW.021 a 60 Hz-class input selects 0x58-byte row 2, whose display mode is 5 (one block); FW.012 used mode 11
 * (all four) for the same input. What the blocks are electrically is not stated by
 * any firmware text.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char *DAT_a802d6a4;
extern int func_0x4008d1a0();

void FUN_a0121f58(void)
{
    unsigned char m;

    R(0xcf01cfa8) = 0;
    R(0xcf01cf9c) = 0x70;
    R(0xcf01cf94) = 0x82;
    R(0xcf01cfa0) = 0x62;
    R(0xcf01cf9c) = 0x30;
    R(0xcf01cf98) = 2;
    R(0xcf01cc58) = 1;
    m = DAT_a802d6a4[6];
    switch (m) {
    case 5: case 6: case 7:
        R(0xcf01cc6c) = 0x66;
        R(0xcf01cc70) = 0;
            break;
    case 8: case 9: case 10:
        R(0xcf01cc6c) = 0x66;
        R(0xcf01cc70) = 0;
        break;
    default:
        R(0xcf01cc6c) = 0x66;
        R(0xcf01cc70) = 0x66;
    }
    R(0xcf01cc68) = 0x66;
    R(0xcf01cf18) = 5;
    R(0xcf01cfa4) = 5;
    func_0x4008d1a0(1);
    R(0xcf01cf9c) = 0x31;
    R(0xcf01cc14) = 1;
    R(0xcf01cf94) = 0xd3;
    func_0x4008d1a0(1);
    R(0xcf01cf94) = 0x53;
    R(0xcf01cfa0) = 0x62;
    func_0x4008d1a0(1);
    R(0xcf01ccec) = 0x81;
    R(0xcf01cd78) = 0x81;
    R(0xcf01ce04) = 0x81;
    R(0xcf01ce90) = 0x81;
    m = DAT_a802d6a4[6];
    switch (m) {
    case 5: case 6: case 7:
        R(0xcf01cd18) = 0xff;
        R(0xcf01cda4) = 0x80;
        R(0xcf01ce30) = 0;
        R(0xcf01cebc) = 0;
        R(0xcf01cd28) = 0;
        R(0xcf01cdb4) = 0;
        R(0xcf01ce40) = 0;
        R(0xcf01cecc) = 0;
        R(0xcf01ccf0) = 0x18;
        R(0xcf01ccf8) = 0xff;
        R(0xcf01cd84) = 0;
        R(0xcf01ce10) = 0;
        R(0xcf01ce9c) = 0;
            break;
    case 8: case 9: case 10:
        R(0xcf01cd18) = 0xff;
        R(0xcf01cda4) = 0xff;
        R(0xcf01ce30) = 0;
        R(0xcf01cebc) = 0;
        R(0xcf01cd28) = 0;
        R(0xcf01cdb4) = 0;
        R(0xcf01ce40) = 0;
        R(0xcf01cecc) = 0;
        R(0xcf01ccf0) = 0x18;
        R(0xcf01ccf8) = 0xff;
        R(0xcf01cd84) = 0xff;
        R(0xcf01ce10) = 0;
        R(0xcf01ce9c) = 0;
        break;
    default:
        R(0xcf01cd18) = 0xff;
        R(0xcf01cda4) = 0xff;
        R(0xcf01ce30) = 0xff;
        R(0xcf01cebc) = 0xff;
        R(0xcf01cd28) = 0;
        R(0xcf01cdb4) = 0;
        R(0xcf01ce40) = 0;
        R(0xcf01cecc) = 0;
        R(0xcf01ccf0) = 0x18;
        R(0xcf01ccf8) = 0xff;
        R(0xcf01cd84) = 0xff;
        R(0xcf01ce10) = 0xff;
        R(0xcf01ce9c) = 0xff;
    }
}
