/* leon2s FUN_a0094594 @ 0xa0094594 (-mcpu=v8 -Os -g)
 * Table 0xA807A8FC holds records of 0x14 bytes. For record p1 (low byte) writes (byte +0x10 & 0xF0) | (byte +0x11
 * & 0x0F) through FUN_a00a8054(p1, 1, 2, value) and byte +0x12 through FUN_a00a8054(p1, 1, 0xb, value).
 * Source form: Ghidra's type and symbol names are kept.
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
