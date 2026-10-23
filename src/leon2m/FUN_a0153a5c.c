/* leon2m FUN_a0153a5c @ 0xa0153a5c (-mcpu=v8 -O3 -g)
 * Copies the 16-byte pattern at 0x1a75e6 into a stack buffer (FUN_a013c910) and writes it with FUN_a0140e74(0, addr,
 * 0x10, buf, 0) to EEPROM addresses 0x300 .. 0x4b0 (28 writes, 0x1c0 bytes); the remainder write after the loop has
 * length 0 and is skipped.
 */

extern int FUN_a013c910();
extern int FUN_a0140e74();
void FUN_a0153a5c(void)
{
  unsigned short uVar1;
  unsigned short uVar2;
  unsigned char auStack_18[16];
  FUN_a013c910(auStack_18, 0x1a75e6, 0x10);
  uVar2 = 0x1b + 1;
  uVar1 = 0;
  do
  {
    FUN_a0140e74(0, (unsigned short) ((uVar1 * 0x10) + 0x300), 0x10, (int) auStack_18, 0);
    uVar1 = uVar1 + 1;
  }
  while (uVar1 < uVar2);
  uVar2 = 0x1c0 - (uVar1 * 0x10);
  if (uVar2 != 0)
  {
    FUN_a0140e74(0, (unsigned short) ((uVar1 * 0x10) + 0x300), uVar2, (int) auStack_18, 0);
  }
}
