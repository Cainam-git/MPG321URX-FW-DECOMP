/* leon2m FUN_a013a8d4 @ 0xa013a8d4  send command 0x84 to the Tensilica core through mailbox portal 2 (hand;
 * BYTE-EXACT at -mcpu=v8 -O3 -g -msoft-float).
 *
 * Reads portal 2 offset 0x20 (MailBox_Read func_0x4008c4d0); while it is non-zero, waits 1 ms (func_0x4008d1a0) and
 * re-reads, at most 100 times; when it reads 0 writes 0x84000000 | b << 16 | (u16)a to offset 0x20
 * (MailBox_Write func_0x4008c5f8); gives up silently after 100 tries.
 * BYTE-EXACT key: the u16 value is the FIRST parameter, the byte the second (swapped: 89.1 %).
 */
extern void func_0x4008c4d0();
extern void func_0x4008c5f8();
extern int func_0x4008d1a0();
void FUN_a013a8d4(unsigned int param_2, unsigned char param_1)
{
  unsigned int local_c;
  int counter;
  local_c = 0xffffffff;
  func_0x4008c4d0(2, 0x20, &local_c, 1);
  counter = 100;
  if (local_c == 0)
  {
    goto success;
  }
  do
  {
    func_0x4008d1a0(1);
    counter--;
    func_0x4008c4d0(2, 0x20, &local_c, 1);
    if (counter == 0)
    {
      goto check;
    }
    if (local_c == 0)
    {
      goto success;
    }
  }
  while (1);
  check:
  if (local_c == 0)
  {
    goto success;
  }

  return;
  success:
  local_c = (param_1 & 0xff) << 0x10;
  counter = (param_2 << 0x10) >> 0x10;
  local_c |= 0x84000000;
  local_c |= counter;
  func_0x4008c5f8(2, 0x20, &local_c, 1);
}
