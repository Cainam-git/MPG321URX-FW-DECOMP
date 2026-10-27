/* leon2s FUN_a008aba8 @ 0xa008aba8-0xa008ae18, -mcpu=v8 -Os -g (leaf).
 * (u8 sel, unsigned int b), void. Jump-table switch on sel (table: the 19 words at 0xa008ab5c, sel 1..0x13):
 * sel 4..8, 10, 12, 14 clear bit b of the register 0xcf014770 and then set fields of one register:
 * 8 / 12: 0xcf0111cc / 0xcf0111d0 = low byte of (bits 0..5 | b << 6 | 0x20); 10 / 14: the same registers =
 * low byte of (value without bits 2..3 | b << 2 | 2); 4: 0xcf0111c4 = bits 0..5 | 0x20; 5: 0xcf0111c4 = (value
 * | 6) & 0xf7; 6: 0xcf0111c8 = bits 0..5 | 0xa0; 7: 0xcf0111c8 = low byte of (value | 0xe). 1 and 0x11 clear
 * bit (u8)b of 0xcf014770 and set 0xcf0111c0 = (bits 0..4 | 0x20) | (u8)b << 6; 2: 0xcf0111c0 = ((value | 0x10)
 * & 0xf3) | (u8)b << 2; 3 and 0x13 or (u8)b into 0xcf014770 and set 0xcf0111d4 like 0xcf0111c0 in case 1.
 * Other values do nothing.
 * Source forms: the cases are written in the firmware's block order (8, 10, 12, 14, 4..7, 1, 2, 3); the low part
 * of the case 1 / 3 value is an unsigned char (keeps the '| 0x20' before the '| b << 6').
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a008aba8(unsigned char sel, unsigned int b)
{
    switch (sel) {
    case 8:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111cc) = ((R(0xcf0111cc) & 0x3f) | (b << 6) | 0x20) & 0xff;
        break;
    case 10:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111cc) = ((R(0xcf0111cc) & ~0xc) | (b << 2) | 2) & 0xff;
        break;
    case 12:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111d0) = ((R(0xcf0111d0) & 0x3f) | (b << 6) | 0x20) & 0xff;
        break;
    case 14:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111d0) = ((R(0xcf0111d0) & ~0xc) | (b << 2) | 2) & 0xff;
        break;
    case 4:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111c4) = (R(0xcf0111c4) & 0x3f) | 0x20;
        break;
    case 5:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111c4) = (R(0xcf0111c4) | 6) & 0xf7;
        break;
    case 6:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111c8) = (R(0xcf0111c8) & 0x3f) | 0xa0;
        break;
    case 7:
        R(0xcf014770) &= ~(1 << b);
        R(0xcf0111c8) = (R(0xcf0111c8) | 0xe) & 0xff;
        break;
    case 1:
    case 0x11:
        R(0xcf014770) &= ~(1 << (unsigned char)b);
        R(0xcf0111c0) = (unsigned char)((R(0xcf0111c0) & 0x1f) | 0x20) | ((unsigned char)b << 6);
        break;
    case 2:
        R(0xcf0111c0) = ((R(0xcf0111c0) | 0x10) & 0xf3) | ((unsigned char)b << 2);
        break;
    case 3:
    case 0x13:
        R(0xcf014770) |= (unsigned char)b;
        R(0xcf0111d4) = (unsigned char)((R(0xcf0111d4) & 0x1f) | 0x20) | ((unsigned char)b << 6);
        break;
    }
}
