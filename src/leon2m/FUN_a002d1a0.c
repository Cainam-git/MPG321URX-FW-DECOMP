/* leon2m FUN_a002d1a0 @ 0xa002d1a0  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Waits for a 16-bit handshake: stores (param_1 + 1) & 0xFFFF in the
 * volatile word at 0xa802b0c0 and loads a countdown of (word at 0xa8025c74) / 100 into 0xa802d638, then spins while
 * the 0xa802b0c0 word is non-zero, decrementing the countdown. When the countdown reaches 0 with the word still
 * holding the stored value, it calls 0x7f170(0x198f68).
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
extern unsigned int _DAT_a8025c74;
extern volatile unsigned int _DAT_a802b0c0;
extern unsigned int _DAT_a802d638;
extern int func_0x0007f170();

void FUN_a002d1a0(int param_1)

{
  unsigned short uVar1;
  
  uVar1 = param_1 + 1U & 0xffff;
  _DAT_a802d638 = _DAT_a8025c74 / 100;
  _DAT_a802b0c0 = uVar1;
  while (_DAT_a802b0c0 != 0) {
    _DAT_a802d638 = _DAT_a802d638 - 1;
    if ((_DAT_a802d638 == 0) && (uVar1 == _DAT_a802b0c0)) {
      func_0x0007f170(0x198f68);
    }
  }
}