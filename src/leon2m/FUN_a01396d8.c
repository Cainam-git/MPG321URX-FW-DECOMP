/* leon2m FUN_a01396d8 @ 0xa01396d8-0xa01397ec (69 words), flags -mcpu=v8 -O3 -g.
 * Code facts: stack word buf = 0; ROM read func_0x4008c4d0(2, 0x34, &buf, 1). If buf == 0x55aa0002: buf = 0,
 * ROM write func_0x4008c5f8(2, 0x30, &buf, 1), buf = 1, then poll the read up to 0xffff times (u16 counter,
 * sll 16 test) until buf == 0. Then always: buf = 0x55aa0002, write reg 0x30, buf = 1, poll until buf ==
 * 0x55aa0002 or the counter runs out. void(void). Aids: one asm nop after each counter decrement (the fw has a
 * real 'nop' there, not a delay slot; same documented aid as the accepted a00de65c family).
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);

void FUN_a01396d8(void)
{
  unsigned int buf = 0;
  unsigned short n;

  func_0x4008c4d0(2, 0x34, &buf, 1);
  if (buf == 0x55aa0002) {
    buf = 0;
    func_0x4008c5f8(2, 0x30, &buf, 1);
    buf = 1;
    n = 0xffff;
    do {
      func_0x4008c4d0(2, 0x34, &buf, 1);
      n--;
      __asm__ volatile ("nop");
      if (n == 0)
        break;
    } while (buf != 0);
  }
  buf = 0x55aa0002;
  func_0x4008c5f8(2, 0x30, &buf, 1);
  buf = 1;
  n = 0xffff;
  do {
    func_0x4008c4d0(2, 0x34, &buf, 1);
    n--;
    __asm__ volatile ("nop");
    if (n == 0)
      break;
  } while (buf != 0x55aa0002);
}
