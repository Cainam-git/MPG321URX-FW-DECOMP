/* leon2s FUN_a0094594 @ 0xa0094594  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char undefined1;

extern int FUN_a00a8054();
extern undefined1 DAT_a807a8fc[];

void FUN_a0094594(unsigned int param_1)

{
  undefined1 *pb;
  unsigned int combined;
  unsigned char b2;
  
  param_1 = param_1 & 0xff;
  pb = DAT_a807a8fc + param_1 * 0x14;
  combined = (pb[0x10] & 0xf0) | (pb[0x11] & 0xf);
  b2 = pb[0x12];
  FUN_a00a8054(param_1,1,2,combined);
  FUN_a00a8054(param_1,1,0xb,b2);
  return;
}
