/* FUN_a008e7c0 (leon2s, 0xa008e7c0-0xa008e940, 96 words). Flags -mcpu=v8 -Os -g. jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 Code facts: void (u8 p1, u8 p2, u8 p3). Read-modify-write of the hardware register 0xcf0116b4 (volatile, real HW).
 If p3 == 1 and p2 is one of 0x31/0x41/0x51/0x61: p1 0 -> |1, p1 1 -> |2, else &0xfc; then p2 0x51: p1 0 -> &0xfb, 1 -> &0xf7;
 p2 0x61: p1 0 -> |4, 1 -> |8. Otherwise (p3 != 1 or other p2): p1 0 -> &0xfe, 1 -> &0xfd. Every other path ends in &0xfc.
 Fix vs the autoc draft: the Q/a dispatch is a switch (fw: cmp 0x51 be; cmp 0x61 be; default b to the shared &0xfc tail).
 Aids: none.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
#define _DAT_cf0116b4 (*(volatile unsigned int *)0xcf0116b4)

void FUN_a008e7c0(unsigned char param_1, unsigned char param_2, unsigned char param_3)

{
  if ((param_3 == '\x01') &&
     ((param_2 == '1' || param_2 == 'A' || (param_2 == 'Q' || param_2 == 'a')))) {
    if (param_1 == '\0') {
      _DAT_cf0116b4 = _DAT_cf0116b4 | 1;
    }
    else if (param_1 == '\x01') {
      _DAT_cf0116b4 = _DAT_cf0116b4 | 2;
    }
    else {
      _DAT_cf0116b4 = _DAT_cf0116b4 & 0xfc;
    }
    switch (param_2) {
    case 'Q':
      if (param_1 == '\0') {
        _DAT_cf0116b4 = _DAT_cf0116b4 & 0xfb;
        return;
      }
      if (param_1 == '\x01') {
        _DAT_cf0116b4 = _DAT_cf0116b4 & 0xf7;
        return;
      }
      break;
    case 'a':
      if (param_1 == '\0') {
        _DAT_cf0116b4 = _DAT_cf0116b4 | 4;
        return;
      }
      if (param_1 == '\x01') {
        _DAT_cf0116b4 = _DAT_cf0116b4 | 8;
        return;
      }
      break;
    }
  }
  else {
    if (param_1 == '\0') {
      _DAT_cf0116b4 = _DAT_cf0116b4 & 0xfe;
      return;
    }
    if (param_1 == '\x01') {
      _DAT_cf0116b4 = _DAT_cf0116b4 & 0xfd;
      return;
    }
  }
  _DAT_cf0116b4 = _DAT_cf0116b4 & 0xfc;
  return;
}