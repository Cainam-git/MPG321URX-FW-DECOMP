/* leon2m FUN_a011d748 @ 0xa011d748-0xa011dd9c (1620 bytes), flags -mcpu=v8 -O3 -g.
 * FUN_a011d748(id, port, freq, clksel): for id 0x10..0x18 and 0x1f clksel is forced to 0; clksel &= 3 selects
 * clk = 96000000 (1) or 12000000 (0), any other value prints "ConfigScalerPWM only support MPLLCLK_96MHz and
 * REFCLK_12MHz\r\n" and returns. div = (clk * 10 / freq - 5) / 10 picks presc / scale = 10 / 0x400
 * (div >= 0x400), 8 / 0x100 (div >= 0x100) or 4 / 0x10; then div = (clk * 10 / scale / freq - 5) / 10 and, while
 * presc < 0xf and div > 0x3ff, presc++ and div >>= 1.
 * Register blocks by id (jump tables at 0xa011d304 for the read, 0xa011d214 for the write): 1..6 at 0xcf016120 +
 * 0x18 * (id - 1), the group 0x10..0x18 / 0x1f at 0xcf016400, 0x19 at 0xcf016494, 0x1a at 0xcf0164c0. v = word +4
 * & 0xc0 (other ids return); bits = ((div >> 4) & 0x30) | v | presc (u8); word +0 &= 0xfc, then |= clksel (not for
 * the group), word +4 = bits, word +8 = low byte of div. Then FUN_a00fe880(a, b, c) with the constants of port 0..27
 * (jump table at 0xa011d294; port 0x10 is listed last).
 * volatile: hardware registers only.
 * Source form: K&R definition (id and port are masked at each use); scale is an unsigned short (the 'and 0x510'
 * of the three scale values); bits is an unsigned char; the error flag err is reused for the low byte of div after
 * the read switch; the case order of both id switches (as listed) sets the register names in the case blocks.
 */
#define REG(a) (*(volatile unsigned int *)(a))

extern int FUN_a00df170(const char *, ...);
extern void FUN_a00fe880(unsigned char, unsigned char, unsigned int);

void FUN_a011d748(id, port, freq, clksel)
unsigned char id;
unsigned char port;
unsigned int freq;
unsigned int clksel;
{
  unsigned int clk;
  unsigned int div;
  unsigned int v;
  unsigned char bits;
  unsigned short scale;
  unsigned char presc;
  unsigned char err;
  if ((((unsigned char) (id - 0x10)) < 9) || (((unsigned char) id) == 0x1f))
  {
    clksel = 0;
  }
  clksel &= 3;
  if (clksel == 1)
  {
    clk = 96000000;
  }
  else
    if (clksel == 0)
  {
    clk = 12000000;
  }
  else
  {
    FUN_a00df170("ConfigScalerPWM only support MPLLCLK_96MHz and REFCLK_12MHz\r\n");
    return;
  }
  div = (((clk * 10) / freq) - 5) / 10;
  presc = 10;
  scale = 0x400;
  if (div < 0x400)
  {
    presc = 8;
    scale = 0x100;
    if (div < 0x100)
    {
      presc = 4;
      scale = 0x10;
    }
  }
  div = ((((clk * 10) / scale) / freq) - 5) / 10;
  while (presc < 0xf)
  {
    if (div <= 0x3ff)
    {
      break;
    }
    presc++;
    div >>= 1;
  }

  err = 0;
  switch ((unsigned char) id)
  {

    case 0x1a:
      v = REG(0xcf0164c4) & 0xc0;
      break;

    case 6:
      v = REG(0xcf01619c) & 0xc0;
      break;

    case 3:
      v = REG(0xcf016154) & 0xc0;
      break;

    case 0x19:
      v = REG(0xcf016498) & 0xc0;
      break;
    case 1:
      v = REG(0xcf016124) & 0xc0;
      break;

    case 2:
      v = REG(0xcf01613c) & 0xc0;
      break;

    case 0x10:

    case 0x11:

    case 0x12:

    case 0x13:

    case 0x14:

    case 0x15:

    case 0x16:

    case 0x17:

    case 0x18:

    case 0x1f:
      v = REG(0xcf016404) & 0xc0;
      break;

    case 4:
      v = REG(0xcf01616c) & 0xc0;
      break;

    default:
      v = 0;
      err = 1;
      break;

    case 5:
      v = REG(0xcf016184) & 0xc0;
      break;

  }

  if (err)
  {
    return;
  }
  bits = ((div >> 4) & 0x30) | (v | presc);
  err = div;
  switch ((unsigned char) id)
  {

    case 5:
      REG(0xcf016180) &= 0xfc;
      REG(0xcf016180) |= clksel;
      REG(0xcf016184) = bits & 0xff;
      REG(0xcf016188) = err & 0xff;
      break;

    case 4:
      REG(0xcf016168) &= 0xfc;
      REG(0xcf016168) |= clksel;
      REG(0xcf01616c) = bits & 0xff;
      REG(0xcf016170) = err & 0xff;
      break;

    case 1:
      REG(0xcf016120) &= 0xfc;
      REG(0xcf016120) |= clksel;
      REG(0xcf016124) = bits & 0xff;
      REG(0xcf016128) = err & 0xff;
      break;

    case 6:
      REG(0xcf016198) &= 0xfc;
      REG(0xcf016198) |= clksel;
      REG(0xcf01619c) = bits & 0xff;
      REG(0xcf0161a0) = err & 0xff;
      break;

    case 3:
      REG(0xcf016150) &= 0xfc;
      REG(0xcf016150) |= clksel;
      REG(0xcf016154) = bits & 0xff;
      REG(0xcf016158) = err & 0xff;
      break;

    case 2:
      REG(0xcf016138) &= 0xfc;
      REG(0xcf016138) |= clksel;
      REG(0xcf01613c) = bits & 0xff;
      REG(0xcf016140) = err & 0xff;
      break;
    case 0x10:

    case 0x11:

    case 0x12:

    case 0x13:

    case 0x14:

    case 0x15:

    case 0x16:

    case 0x17:

    case 0x18:

    case 0x1f:
      REG(0xcf016400) &= 0xfc;
      REG(0xcf016404) = bits & 0xff;
      REG(0xcf016408) = err & 0xff;
      break;

    case 0x19:
      REG(0xcf016494) &= 0xfc;
      REG(0xcf016494) |= clksel;
      REG(0xcf016498) = bits & 0xff;
      REG(0xcf01649c) = err & 0xff;
      break;

    case 0x1a:
      REG(0xcf0164c0) &= 0xfc;
      REG(0xcf0164c0) |= clksel;
      REG(0xcf0164c4) = bits & 0xff;
      REG(0xcf0164c8) = err & 0xff;
      break;

  }

  switch ((unsigned char) port)
  {
    case 0:
      FUN_a00fe880(0xb, 1, 5);
      break;

    case 1:
      FUN_a00fe880(0xf, 4, 5);
      break;

    case 2:
      FUN_a00fe880(0xa, 1, 5);
      break;

    case 3:
      FUN_a00fe880(0xb, 2, 5);
      break;

    case 4:
      FUN_a00fe880(0xf, 8, 5);
      break;

    case 5:
      FUN_a00fe880(0xa, 2, 5);
      break;

    case 6:
      FUN_a00fe880(5, 4, 5);
      break;

    case 7:
      FUN_a00fe880(0xb, 4, 5);
      break;

    case 8:
      FUN_a00fe880(0xf, 0x10, 5);
      break;

    case 9:
      FUN_a00fe880(5, 8, 5);
      break;

    case 10:
      FUN_a00fe880(0xb, 8, 5);
      break;

    case 11:
      FUN_a00fe880(0xf, 0x20, 5);
      break;

    case 12:
      FUN_a00fe880(0xf, 0x40, 5);
      break;

    case 13:
      FUN_a00fe880(0xd, 0x40, 5);
      break;

    case 14:
      FUN_a00fe880(0xf, 0x80, 5);
      break;

    case 15:
      FUN_a00fe880(0xd, 0x80, 5);
      break;

    case 17:
      FUN_a00fe880(0xb, 1, 0xa);
      break;

    case 18:
      FUN_a00fe880(9, 2, 0xa);
      break;

    case 19:
      FUN_a00fe880(0xb, 2, 0xa);
      break;

    case 20:
      FUN_a00fe880(9, 4, 0xa);
      break;

    case 21:
      FUN_a00fe880(0xb, 4, 0xa);
      break;

    case 22:
      FUN_a00fe880(9, 8, 0xa);
      break;

    case 23:
      FUN_a00fe880(0xb, 8, 0xa);
      break;

    case 24:
      FUN_a00fe880(9, 0x10, 0xa);
      break;

    case 25:
      FUN_a00fe880(9, 0x20, 0xa);
      break;

    case 26:
      FUN_a00fe880(9, 0x40, 0xa);
      break;

    case 27:
      FUN_a00fe880(9, 0x80, 0xa);
      break;

    case 16:
      FUN_a00fe880(9, 1, 0xa);
      break;

  }

}
