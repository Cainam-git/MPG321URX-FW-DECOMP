/* leon2m FUN_a01381f0 @ 0xa01381f0-0xa0138284 (37 words).
 * Maps mode 0/1/2/3 to the command byte 2/3/4/5 (other modes leave it 0), sends the 4-byte buffer
 * {byte, 0, 0, 0} with FUN_a01370dc(0x7c, 4, buf, 0), runs FUN_a0137344(1) and returns the word DAT_a802cba0.
 * No direct callers were found. The buffer is an initialised 4-byte array (the word at %fp-16 is cleared,
 * then one byte is stored); the cases are a switch without a jump table. The result is a full word load.
 */
extern unsigned int DAT_a802cba0;
extern void FUN_a01370dc(int, int, unsigned char *, int);
extern void FUN_a0137344(int);

unsigned int FUN_a01381f0(unsigned char mode)
{
  unsigned char buf[4] = {0};

  switch (mode) {
  case 1: buf[0] = 3; break;
  case 2: buf[0] = 4; break;
  case 3: buf[0] = 5; break;
  case 0: buf[0] = 2; break;
  }
  FUN_a01370dc(0x7c, 4, buf, 0);
  FUN_a0137344(1);
  return DAT_a802cba0;
}
