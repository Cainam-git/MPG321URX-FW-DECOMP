/* leon2m FUN_a00d2334 @ 0xa00d2334 (-mcpu=v8 -O2 -g)
 * Copies the 13 bytes src[6..18] (src = p) to bytes 3..15 of the record at 0xA802D274, then
 * FUN_a014aed0(0x30, 0xA802D274, 0x2e0, 0x1c); returns 0xe0.
 */

extern int FUN_a014aed0(int, unsigned int *, int, int);
extern unsigned int DAT_a802d274;
int FUN_a00d2334(int param_1)
{
  unsigned int uVar1;
  unsigned char uVar2;
  unsigned char *src;
  unsigned char *dst;
  uVar1 = 0;
  uVar2 = 0;
  src = (unsigned char *) param_1;
  do
  {
    uVar1 = uVar1 + 1;
    dst = (unsigned char *) (&DAT_a802d274);
    dst[uVar2 + 3] = src[uVar2 + 6];
    uVar2 = uVar1 & 0xff;
  }
  while (uVar2 < 0xd);
  FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
  return 0xe0;
}
