/* leon2s FUN_a0091cf4 @ 0xa0091cf4 (-mcpu=v8 -Os -g)
 * p = p1 & 0xff. When the low byte of the ROM call func_0x9f1b7bf8(p1) is 0: b = bit 0 of FUN_a00a7fd8(p, 0, 0x27);
 * func_0x9f1b8a1c(p, 0); the byte p3 is stored in a 1-byte stack buffer and passed as func_0x9f1b80f0(p, buf, 0xa8,
 * p2 & 0xff, 1); then func_0x9f1b8a1c(p, b). Otherwise nothing.
 * Source form: b goes through a char local masked with 1 again before the last call (keeps the and 1 of the firmware).
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
extern int FUN_a00a7fd8();
extern int func_0x9f1b7bf8();
extern unsigned char func_0x9f1b80f0();
extern void func_0x9f1b8a1c();

void FUN_a0091cf4(unsigned char param_1, char param_2,undefined1 param_3)

{
    char t21_;
  unsigned short uVar1;
  uint uVar2;
  undefined1 local_9 [1];
  
  uVar2 = param_1 & 0xff;
  uVar1 = func_0x9f1b7bf8(param_1);
  if ((uVar1 & 0xff) == 0) {
    uVar1 = FUN_a00a7fd8(uVar2,0,0x27) & 1;
    func_0x9f1b8a1c(uVar2,0);
    local_9[0] = param_3;
    func_0x9f1b80f0(uVar2,local_9,0xa8,param_2 & 0xff,1);
    t21_ = uVar1;
    t21_ = t21_ & 1;
    func_0x9f1b8a1c(uVar2, t21_);
  }
}