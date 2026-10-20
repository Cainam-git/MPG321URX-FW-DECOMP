/* leon2m FUN_a00295a4 @ 0xa00295a4  main() of the Big chip (MATCH -mcpu=v8 -Os -g, gcc 3.4.4, autoc).
 * Called by the reset code (FUN_a0028ff0) once processor state, windows, stack and trap base are set.
 * It runs from the RAM copy of the image (calls carry RAM-relative displacements; firmware address = Ghidra's
 * func_0x000XXXXX + 0xA0060000): three one-time initialisations FUN_a008796c, FUN_a015266c, FUN_a0087020, then an
 * endless loop over the tasks FUN_a01387a4, FUN_a0153018, FUN_a0087430, FUN_a00dcec4.
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
extern int func_0x00027020();
extern int func_0x00027430();
extern int func_0x0002796c();
extern int func_0x0007cec4();
extern int func_0x000d87a4();
extern int func_0x000f266c();
extern int func_0x000f3018();

void FUN_a00295a4(void)

{
  func_0x0002796c();
  func_0x000f266c();
  func_0x00027020();
  do {
    func_0x000d87a4();
    func_0x000f3018();
    func_0x00027430();
    func_0x0007cec4();
  } while( true );
}