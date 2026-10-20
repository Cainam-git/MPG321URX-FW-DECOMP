/*
 * FUN_a01227f0 - V-by-One (Vx1) transmitter lane set-up (Big chip, leon2m). '-mcpu=v8 -O3 -g'
 * (0xa01227f0..0xa0122cd8, 314 words).
 *
 * What it does: from the active transformed panel row DAT_a802d6a4 (byte +6 display mode, +7 bits per colour)
 * prints "Vx1 Lane BW = %ld" (= k * FUN_a0105a94(1, 0) * 5 / 4), writes the Vx1 TX set-up registers
 * 0xCF00EB40..EB60,
 * the reset/strobe sequence on 0xCF01CBB8.., the block enables 0xCF01CD10/CD9C/CE28/CEB4 by mode, the 32 lane
 * registers from DAT_a8027b0c, and per block (stride 0x8C) a flag 0xFF/0 plus four values (DAT_a802c9ec*17-17)&0xFF
 * when DAT_a802c9ec != 0. Inputs: none; output: none. Callers: FUN_a01413d0 (panel power sequencer, state 4, link
 * 1).
 *
 * Source form:
 * - Tail: DAT_a802c9ec is read ONCE into v; x = v * 17 - 17 is computed once before the four tests (unsigned short
 *   x,
 *   stored as (unsigned char) x in each block).
 * - Tests 2..4 are written 'z = v == 0; if (z)': with plain 'if (v == 0)' gcse's jump bypass (10.bypass, implicit
 *   set
 *   v == 0) threads the A arms into each other and cse2 deletes the tests; the setcc makes the join block 2 insns so
 *   bypass_block skips it, and combine folds it back into 'cmp v,0' (the firmware keeps all four tests).
 * - Head (switches with repeated case bodies, explicit locals): behaviour-neutral.
 */
extern unsigned char *DAT_a802d6a4;
extern unsigned char DAT_a8027b0c;
extern unsigned char DAT_a802c9ec;
extern unsigned short FUN_a0105a94(int, int);
extern int FUN_a00df170();
extern char s_001a3030[];
extern void FUN_a0121f58(void);
extern int func_0x4008d1a0();
void FUN_a01227f0(void)
{
  unsigned char i;
  unsigned char v;
  int z;
  int w;
  unsigned short x;
  unsigned char bpp;
  if (DAT_a802d6a4[7] == 10)
  {
    bpp = 4;
  }
  else
  {
    bpp = (DAT_a802d6a4[7] == 8) ? (3) : (5);
  }
  w = FUN_a0105a94(1, 0);
  FUN_a00df170(s_001a3030, ((unsigned int) ((bpp * w) * 5)) >> 2);
  *((volatile unsigned int *) 0xcf00eb58) = 7;
  *((volatile unsigned int *) 0xcf00eb44) = 1;
  FUN_a0121f58();
  *((volatile unsigned int *) 0xcf01cbb8) = 0xff;
  *((volatile unsigned int *) 0xcf01cbbc) = 0;
  *((volatile unsigned int *) 0xcf01c99c) = 0xfd;
  *((volatile unsigned int *) 0xcf01c830) = 4;
  *((volatile unsigned int *) 0xcf01c804) = 0;
  *((volatile unsigned int *) 0xcf01cbb8) = 1;
  for (i = 0; 7 >= i; i++)
  {
    *((volatile unsigned int *) 0xcf01cbb8) = (unsigned char) (0x80 >> i);
    *((volatile unsigned int *) 0xcf01c800) = 0;
  }

  if (DAT_a802d6a4[7] == 10)
  {
    *((volatile unsigned int *) 0xcf00eb40) = 2;
  }
  else
    if (DAT_a802d6a4[7] == 8)
  {
    *((volatile unsigned int *) 0xcf00eb40) = 1;
  }
  else
  {
    *((volatile unsigned int *) 0xcf00eb40) = 3;
  }
  *((volatile unsigned int *) 0xcf00eb44) = 0;
  *((volatile unsigned int *) 0xcf00eb48) = 4;
  *((volatile unsigned int *) 0xcf00eb4c) = 0;
  *((volatile unsigned int *) 0xcf00eb50) = 0;
  switch (DAT_a802d6a4[6])
  {
    case 10:
      *((volatile unsigned int *) 0xcf00eb54) = 5;
      break;

    case 9:
      *((volatile unsigned int *) 0xcf00eb54) = 5;
      break;

    case 8:
      *((volatile unsigned int *) 0xcf00eb54) = 1;
      break;

    case 7:
      *((volatile unsigned int *) 0xcf00eb54) = 1;
      break;

    case 6:
      *((volatile unsigned int *) 0xcf00eb54) = 1;
      break;

    case 5:
      *((volatile unsigned int *) 0xcf00eb54) = 1;
      break;

    default:
      *((volatile unsigned int *) 0xcf00eb54) = 7;
      break;

  }

  *((volatile unsigned int *) 0xcf00eb58) = 7;
  *((volatile unsigned int *) 0xcf00eb60) = (*((volatile unsigned int *) 0xcf00eb60)) & 0xfc;
  *((volatile unsigned int *) 0xcf00eb5c) = 0;
  func_0x4008d1a0(10);
  switch (DAT_a802d6a4[6])
  {
    case 5:

    case 6:

    case 7:
      *((volatile unsigned int *) 0xcf01cd10) = 0xff;
      *((volatile unsigned int *) 0xcf01cd9c) = 0;
      *((volatile unsigned int *) 0xcf01ce28) = 0;
      *((volatile unsigned int *) 0xcf01ceb4) = 0;
      break;

    case 8:

    case 9:

    case 10:
      *((volatile unsigned int *) 0xcf01cd10) = 0xff;
      *((volatile unsigned int *) 0xcf01cd9c) = 0xff;
      *((volatile unsigned int *) 0xcf01ce28) = 0;
      *((volatile unsigned int *) 0xcf01ceb4) = 0;
      break;

    default:
      *((volatile unsigned int *) 0xcf01cd10) = 0xff;
      *((volatile unsigned int *) 0xcf01cd9c) = 0xff;
      *((volatile unsigned int *) 0xcf01ce28) = 0xff;
      *((volatile unsigned int *) 0xcf01ceb4) = 0xff;
      break;

  }

  *((volatile unsigned int *) 0xcf01cd30) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cd34) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cd38) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cd3c) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cd40) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cd44) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cd48) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cd4c) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdbc) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdc0) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdc4) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdc8) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdcc) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdd0) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdd4) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cdd8) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce48) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce4c) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce50) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce54) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce58) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce5c) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce60) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ce64) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ced4) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ced8) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cedc) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cee0) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cee4) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cee8) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01ceec) = DAT_a8027b0c;
  *((volatile unsigned int *) 0xcf01cef0) = DAT_a8027b0c;
  v = DAT_a802c9ec;
  x = (v * 17) - 17;
  if (v == 0)
  {
    *((volatile unsigned int *) 0xcf01cd0c) = 0;
  }
  else
  {
    *((volatile unsigned int *) 0xcf01cd0c) = 0xff;
    *((volatile unsigned int *) 0xcf01ccfc) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cd00) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cd04) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cd08) = (unsigned char) x;
  }
  z = v == 0;
  if (z)
  {
    *((volatile unsigned int *) 0xcf01cd98) = 0;
  }
  else
  {
    *((volatile unsigned int *) 0xcf01cd98) = 0xff;
    *((volatile unsigned int *) 0xcf01cd88) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cd8c) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cd90) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cd94) = (unsigned char) x;
  }
  z = v == 0;
  if (z)
  {
    *((volatile unsigned int *) 0xcf01ce24) = 0;
  }
  else
  {
    *((volatile unsigned int *) 0xcf01ce24) = 0xff;
    *((volatile unsigned int *) 0xcf01ce14) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01ce18) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01ce1c) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01ce20) = (unsigned char) x;
  }
  z = v == 0;
  if (z)
  {
    *((volatile unsigned int *) 0xcf01ceb0) = 0;
  }
  else
  {
    *((volatile unsigned int *) 0xcf01ceb0) = 0xff;
    *((volatile unsigned int *) 0xcf01cea0) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cea4) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01cea8) = (unsigned char) x;
    *((volatile unsigned int *) 0xcf01ceac) = (unsigned char) x;
  }
}
