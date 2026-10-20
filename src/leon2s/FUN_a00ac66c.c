/* leon2s FUN_a00ac66c @ 0xa00ac66c-0xa00acac0 (277 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches.
 * Code facts: port init: a long fixed sequence of FUN_a00a6c00(port, reg, val) writes and
 * FUN_a00a6c98(port, reg, mask, on) bit updates. Per-port 300-byte records at 0xa807dc18 (smul 0x12c):
 * byte +0x112 == 0 -> reg 0xc0 bit 1 off; after reg 0xa0 bit 4 on, byte +0x110 picks reg 0x47 = 0x40
 * (== 0) or 0x80 (== 1). Port 0 only: reg 0x24 bit 0x80 on and, if record 0 byte +0x112 != 0, a
 * block with 0xcf004680 |= 0x20, FUN_a00b1b18(), 0xcf0046a8 &= ~1, 0xcf0046ac &= ~2, regs 9..0xe
 * and FUN_a00a6fc0(0, 0x3e, 1); other ports: reg 0x24 bit 0x80 off. Six final bit updates, the
 * last one a tail call. void.
 * Fixes vs the autoc draft (96.76): real base ARR_a807dc18 (draft: mid-record DAT_a807dd2a /
 * DAT_a807dd28) as a 300-byte struct; both record reads index ARR_a807dc18[port] the same way so
 * cse shares one address (kept in %l0); the +0x110 byte is read AFTER the reg 0xa0 call (fw ldub
 * after the call); void return (draft 'short', no value). Aids: none.
 */

struct Port { unsigned char pad[0x110]; unsigned char b110; unsigned char pad1; unsigned char b112; unsigned char pad2[300 - 0x113]; };
extern struct Port ARR_a807dc18[];
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned int);
extern void FUN_a00a6c98(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a6fc0(unsigned int, unsigned short, unsigned int);
extern void FUN_a00b1b18(void);
void FUN_a00ac66c(unsigned char param_1)
{
  unsigned char cVar1;
  FUN_a00a6c00(param_1, 0, 0x1f);
  FUN_a00a6c00(param_1, 0x30, 0x30);
  FUN_a00a6c98(param_1, 0xc0, 8, 0);
  FUN_a00a6c98(param_1, 0xc0, 0x10, 1);
  if (ARR_a807dc18[param_1].b112 == 0)
  {
    FUN_a00a6c98(param_1, 0xc0, 1, 0);
  }
  FUN_a00a6c98(param_1, 0x33, 0x87, 1);
  FUN_a00a6c98(param_1, 0x37, 0x38, 1);
  FUN_a00a6c00(param_1, 0x3a, 0x82);
  FUN_a00a6c00(param_1, 0x34, 4);
  FUN_a00a6c00(param_1, 0xc7, 0x20);
  FUN_a00a6c98(param_1, 1, 0xf, 0);
  FUN_a00a6c00(param_1, 0x3f, 0x20);
  FUN_a00a6c98(param_1, 0xa0, 8, 1);
  FUN_a00a6c00(param_1, 0xb4, 0x49);
  FUN_a00a6c98(param_1, 0x42, 0x40, 1);
  FUN_a00a6c98(param_1, 0xa0, 4, 1);
  cVar1 = ARR_a807dc18[param_1].b110;
  if (cVar1 == 0)
  {
    FUN_a00a6c00(param_1, 0x47, 0x40);
  }
  else
    if (cVar1 == 1)
  {
    FUN_a00a6c00(param_1, 0x47, 0x80);
  }
  FUN_a00a6c00(param_1, 0x57, 3);
  FUN_a00a6c98(param_1, 0x55, 0x80, 0);
  FUN_a00a6c00(param_1, 0x58, 0);
  FUN_a00a6c00(param_1, 0x5a, 0);
  FUN_a00a6c00(param_1, 0x59, 0);
  FUN_a00a6c00(param_1, 0x70, 1);
  FUN_a00a6c00(param_1, 0x71, 0xff);
  FUN_a00a6c00(param_1, 0x50, 0x80);
  FUN_a00a6c00(param_1, 0x54, 0xff);
  FUN_a00a6c00(param_1, 0x11, 0xad);
  FUN_a00a6c00(param_1, 0x10, 0xb);
  FUN_a00a6c00(param_1, 0xf, 0);
  FUN_a00a6c00(param_1, 0x14, 0);
  FUN_a00a6c00(param_1, 0x13, 0x80);
  FUN_a00a6c00(param_1, 0x12, 0);
  if (!(param_1 == 0))
  {
    FUN_a00a6c98(param_1, 0x24, 0x80, 0);
  }
  else
  {
    FUN_a00a6c98(0, 0x24, 0x80, 1);
    if (ARR_a807dc18[0].b112 != 0)
    {
      FUN_a00a6c98(0, 0x30, 0x80, 1);
      *((volatile unsigned int *) 0xcf004680) = (*((volatile unsigned int *) 0xcf004680)) | 0x20;
      FUN_a00a6c98(0, 0x30, 0x80, 0);
      FUN_a00a6c00(0, 0xf7, 3);
      FUN_a00a6c00(0, 0xf7, 0x91);
      FUN_a00b1b18();
      *((volatile unsigned int *) 0xcf0046a8) = (*((volatile unsigned int *) 0xcf0046a8)) & 0xfffffffe;
      *((volatile unsigned int *) 0xcf0046ac) = (*((volatile unsigned int *) 0xcf0046ac)) & 0xfffffffd;
      FUN_a00a6c98(0, 0, 0x20, 1);
      FUN_a00a6c98(0, 0x38, 2, 1);
      FUN_a00a6c00(0, 9, 0);
      FUN_a00a6c00(0, 10, 0x1e);
      FUN_a00a6c00(0, 0xb, 0xe0);
      FUN_a00a6c00(0, 0xc, 0);
      FUN_a00a6c00(0, 0xd, 0x80);
      FUN_a00a6c00(0, 0xe, 0);
      FUN_a00a6fc0(0, 0x3e, 1);
    }
  }
  FUN_a00a6c98(param_1, 0x39, 2, 1);
  FUN_a00a6c98(param_1, 0xc2, 1, 1);
  FUN_a00a6c98(param_1, 0x38, 8, 1);
  FUN_a00a6c98(param_1, 0x38, 0x10, 0);
  FUN_a00a6c98(param_1, 0xc2, 0x80, 1);
  FUN_a00a6c98(param_1, 0x40, 1, 0);
}
