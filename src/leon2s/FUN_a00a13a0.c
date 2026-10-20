/* FUN_a00a13a0 (leon2s 0xa00a13a0-0xa00a146c, 204 bytes), flags -mcpu=v8 -Os -g.
 * r = register block of the 0x34-byte port record ARR_a807db00[port] (volatile MMIO, as in FUN_a009c558); rec =
 * 400-byte record ARR_a807d7e0[port]. Reads r[0x18] (value unused). When the low 24 bits of r[0x19] are 0x1a,
 * w = r[0x1a]: rec[0x160] = bits 16-23, rec[0x161] = bits 24-31, rec[0x15d..0x15f] = bits 8, 9, 10, rec[0x15c] = 1.
 * Otherwise rec[0x10c] = rec[0x10d] = 1, FUN_a009fcb8(port, rec + 0xec) when rec[0x10e] is 0, rec[0x15c] = 0.
 * Then tail-calls FUN_a00a0b98(port, 0x11, 0). Store order as written.
 */
struct PortRec
{
  unsigned int w00;
  volatile unsigned int *regs;
  unsigned char pad[0x34 - 8];
};
extern struct PortRec ARR_a807db00[];
extern unsigned char ARR_a807d7e0[][0x190];
extern void FUN_a009fcb8(unsigned char, unsigned char *);
extern void FUN_a00a0b98(unsigned char, int, int);
void FUN_a00a13a0(unsigned char port)
{
  volatile unsigned int *r = ARR_a807db00[port].regs;
  unsigned int w;
  w = r[0x18];
  if ((r[0x19] & 0xffffff) == 0x1a)
  {
    w = r[0x1a];
    ARR_a807d7e0[port][0x160] = w >> 16;
    ARR_a807d7e0[port][0x161] = w >> 24;
    ARR_a807d7e0[port][0x15d] = (w >> 8) & 1;
    ARR_a807d7e0[port][0x15e] = (((w >> 8) & 0xff) >> 1) & 1;
    ARR_a807d7e0[port][0x15f] = (((w >> 8) & 0xff) >> 2) & 1;
    ARR_a807d7e0[port][0x15c] = 1;
  }
  else
  {
    ARR_a807d7e0[port][0x10c] = 1;
    ARR_a807d7e0[port][0x10d] = 1;
    if (ARR_a807d7e0[port][0x10e] == 0)
    {
      FUN_a009fcb8(port, ARR_a807d7e0[port] + 0xec);
    }
    ARR_a807d7e0[port][0x15c] = 0;
  }
  FUN_a00a0b98(port, 0x11, 0);
}
