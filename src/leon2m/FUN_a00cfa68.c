/* leon2m FUN_a00cfa68 @ 0xa00cfa68-0xa00cfacc (25 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 25 words.
 * Code facts: crc = 0; for u8 i = 4..7: crc = FUN_a00cea70(param_1[i], crc) (u16 crc step, (u8, u16) -> u16:
 * the callee ends with sll/srl 16 of %i1); then param_2[0..4] = 0x6e, 0x83, 2, crc >> 8, crc (low byte);
 * tail FUN_a0089f60(0x50) (1 u8 arg: it only stores %o0 to byte 0xa802af9e). void.
 * Fix vs the autoc draft (68.00): the loop reads BYTES of param_1 (the draft read words) and passes the
 * running u16 crc; FUN_a0089f60 takes 1 arg; the stores in ascending offset order (1 of 120 orders). Aids: none.
 */
extern void FUN_a0089f60(unsigned char);
extern unsigned short FUN_a00cea70(unsigned char, unsigned short);

void FUN_a00cfa68(unsigned char *param_1, unsigned char *param_2)
{
  unsigned short crc = 0;
  unsigned char i;

  for (i = 4; i < 8; i++)
    crc = FUN_a00cea70(param_1[i], crc);
  param_2[0] = 0x6e;
  param_2[1] = 0x83;
  param_2[2] = 2;
  param_2[3] = crc >> 8;
  param_2[4] = crc;
  FUN_a0089f60(0x50);
}
