/* leon2s FUN_a00aec50 @ 0xa00aec50-0xa00aee08 (-mcpu=v8 -Os -g).
 * With init set: FUN_a00a6fc0(port, 0, 4), FUN_a00a6c00(port, 0x4e0, 8), _DAT_a8079328 = FUN_a00b2064(), returns 0.
 * Otherwise, when FUN_a00b2064() - _DAT_a8079328 is at most 0x10: if FUN_a00ad668(port) is non-zero, returns 0 unless
 * bit 3 of FUN_a00a6bb8(port, 0x4e0) is set, then calls FUN_a00a6c00(port, 0x4e0, 8); else it builds the 24-bit value
 * of FUN_a00a6bb8(port, 0x85 / 0x86 / 0x87), shifts it right by 3 (bit 4 of register 0xd7) or 2 (bit 2 of 0xd7) and
 * by 1 more when bit 5 of register 0xd5 is set, returns 0 unless the result is 0x8000 and bit 2 of
 * FUN_a00a6f78(port, 0) is set, then calls FUN_a00a6fc0(port, 0, 4). Those paths end with
 * _DAT_a8079328 = FUN_a00b2064() and return 1. When more than 0x10 has passed: FUN_a00a6fc0(port, 0, 4),
 * FUN_a00a6c00(port, 0x4e0, 8), _DAT_a8079328 = FUN_a00b2064(), returns 1.
 * Source form: the 0x8000 test reads a copy of the value taken before the result variable is set to 0, so one
 * clear serves both paths as in the firmware.
 */

extern unsigned int _DAT_a8079328;
extern unsigned int FUN_a00b2064(void);
extern unsigned char FUN_a00ad668(unsigned char);
extern unsigned char FUN_a00a6bb8(unsigned char, unsigned short);
extern unsigned int FUN_a00a6f78(unsigned char, unsigned short);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a6fc0(unsigned char, unsigned short, unsigned char);
unsigned char FUN_a00aec50(unsigned char port, unsigned char init)
{
  unsigned int v = 0;
  unsigned char late;
  if (init)
  {
    FUN_a00a6fc0(port, 0, 4);
    FUN_a00a6c00(port, 0x4e0, 8);
    _DAT_a8079328 = FUN_a00b2064();
    goto out;
  }
  late = (FUN_a00b2064() - _DAT_a8079328) > 0x10;
  if (late == 0)
  {
    if (FUN_a00ad668(port))
    {
      if ((FUN_a00a6bb8(port, 0x4e0) & 8) == 0)
      {
        goto out;
      }
      FUN_a00a6c00(port, 0x4e0, 8);
    }
    else
    {
      v = FUN_a00a6bb8(port, 0x85);
      v <<= 8;
      v |= FUN_a00a6bb8(port, 0x86);
      v <<= 8;
      v |= FUN_a00a6bb8(port, 0x87);
      if (FUN_a00a6bb8(port, 0xd7) & 0x10)
      {
        v >>= 3;
      }
      else
        if (FUN_a00a6bb8(port, 0xd7) & 4)
      {
        v >>= 2;
      }
      if (FUN_a00a6bb8(port, 0xd5) & 0x20)
      {
        v >>= 1;
      }
      {
        unsigned int t = v;

        v = 0;
        if (t != 0x8000 || (FUN_a00a6f78(port, 0) & 4) == 0)
          goto out;
      }
      FUN_a00a6fc0(port, 0, 4);
    }
    v = 1;
    _DAT_a8079328 = FUN_a00b2064();
  }
  else
  {
    FUN_a00a6fc0(port, 0, 4);
    FUN_a00a6c00(port, 0x4e0, 8);
    v = 1;
    _DAT_a8079328 = FUN_a00b2064();
  }
  out:
  return v & 1;

}
