/* leon2m FUN_a00e4278 @ 0xa00e4278 (-mcpu=v8 -O2 -g)
 * Sets up one device (param_1 = its handle) and starts it, repeating the setup while the
 * device answers "busy". From the call pattern, FUN_a00e03b0(dev, reg, val) writes a
 * register and FUN_a00e05d8(dev, reg, mask, val) changes only the masked bits.
 *   - FUN_a00dfc50(dev, param_2, param_3): preparation step
 *   - regs 0x44-0x53: fixed mask/enable pattern; reg 0x40 bits, 0x41 = 3, 0x5b/0x5c, 0x42 = 0x28
 *   - reg 0x5a: mode from param_2 (0 -> 7; 1 or 2 -> bits 0x81 under mask 0x87)
 *   - reg 0x2cd pulsed 0x8f/0x80/0x8f and reg 0x6c bit 5 pulsed low then high (resets)
 *   - reg 0x40 bit 7 set (start), then FUN_a00e40f4(dev, param_4) gives the result
 * Result 3 repeats the whole setup; anything else is returned. Result 1 was meant to retry
 * after pulsing a field of reg 0x54, but the retry limit is 0, so that path never runs and
 * 1 is returned at once. The duplicated param_2 == 1 / == 2 branches are needed for the match.
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
extern int FUN_a00dfc50();
extern void FUN_a00e03b0();
extern void FUN_a00e05d8();
extern void FUN_a00e0774();
extern int FUN_a00e40f4();

int FUN_a00e4278(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  FUN_a00dfc50(param_1,param_2,param_3);
  for (;;) {
    {
      FUN_a00e03b0(param_1,0x44,0xff);
      FUN_a00e03b0(param_1,0x45,0xf0);
      FUN_a00e03b0(param_1,0x46,0xff);
      FUN_a00e03b0(param_1,0x47,0xff);
      FUN_a00e03b0(param_1,0x48,0);
      FUN_a00e03b0(param_1,0x49,0);
      FUN_a00e03b0(param_1,0x4a,0);
      FUN_a00e03b0(param_1,0x4b,0);
      FUN_a00e03b0(param_1,0x4c,0xff);
      FUN_a00e03b0(param_1,0x4d,0xff);
      FUN_a00e03b0(param_1,0x4e,0xff);
      FUN_a00e03b0(param_1,0x4f,0);
      FUN_a00e03b0(param_1,0x50,0xff);
      FUN_a00e03b0(param_1,0x51,0xff);
      FUN_a00e03b0(param_1,0x52,0xff);
      FUN_a00e03b0(param_1,0x53,0xf);
      FUN_a00e05d8(param_1,0x40,0x87,2);
      FUN_a00e05d8(param_1,0x40,0x20,0x20);
      FUN_a00e03b0(param_1,0x41,3);
      FUN_a00e03b0(param_1,0x5b,0x3c);
      FUN_a00e03b0(param_1,0x5c,0);
      FUN_a00e03b0(param_1,0x42,0x28);
      FUN_a00e05d8(param_1,0x43,3,0);
      if (param_2 == 0) {
        FUN_a00e03b0(param_1,0x5a,7);
      }
      else if (param_2 == 1) {
        FUN_a00e05d8(param_1,0x5a,0x87,0x81);
      }
      else if (param_2 == 2) {
        FUN_a00e05d8(param_1,0x5a,0x87,0x81);
      }
      FUN_a00e03b0(param_1,0x2cd,0x8f);
      FUN_a00e03b0(param_1,0x2cd,0x80);
      FUN_a00e03b0(param_1,0x2cd,0x8f);
      FUN_a00e05d8(param_1,0x6c,0x20,0);
      FUN_a00e05d8(param_1,0x6c,0x20,0x20);
      FUN_a00e05d8(param_1,0x40,0x80,0x80);
      iVar1 = FUN_a00e40f4(param_1,param_4);
      if (iVar1 == 1) {
        iVar2 = iVar2 + 1;
        if (0 < iVar2) break;
        FUN_a00e0774(param_1,0x54,8,3,1);
        FUN_a00e0774(param_1,0x54,8,3,0);
      }
      else if (iVar1 == 3) continue;
      else break;
    }
  }
  return iVar1;
}