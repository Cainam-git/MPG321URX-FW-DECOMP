/* leon2m FUN_a015373c @ 0xa015373c  output path set-up after a panel row change
 * Flags: -mcpu=v8 -O3 -g (-mcpu=v8 -O3 gives the same code). NEW in FW.021. Real size 564 bytes.
 *
 * Called at the end of FUN_a0141840 (panel row transform) and by FUN_a0141964, so in FW.021 every panel row change
 * (FUN_a00dac38 -> FUN_a01483f4 -> FUN_a0141840) re-runs the output path set-up.
 * Builds a 36-byte output configuration on the stack and passes it BY VALUE to FUN_a0106d64, then FUN_a0139a30.
 * row = FUN_a01241fc() (the raw active panel row at 0xA802E378); rec = the saved-settings record 0xA802E1A0
 * (packed, see FUN_a0145af8): u16 h at +3, u16 v at +5.
 *   +0x00 = 1 when rec.h != 0 (then +0x10 = rec.h, +0x12 = rec.v), else 0 (+0x10/+0x12 left unset).
 *   +0x02 = row word 0 bit 25.          +0x04 = 2 when row byte 7 (bits per colour) == 10, else 0.
 *   +0x08 = DispModeTransform() (FUN_a0151c84, inlined; see its file for the mode table).
 *   +0x0C = (w >> 29 & 1) << 7 | (w >> 31) << 5 | (w >> 30 & 1) << 4, +0x0D = (w >> 27 & 3) << 6, w = row word +0x54,
 *           i.e. +0x0C bit 7 = row byte 0x54 bit 5, bit 5 = byte 0x54 bit 7, bit 4 = byte 0x54 bit 6;
 *           +0x0D bits 7..6 = byte 0x54 bits 4..3.
 *   +0x14 = row byte 0x55.
 * The FW.021 panel rows carry byte 0x54 = 0x20 -> +0x0C = 0x80, +0x0D = 0, the same
 *   values Disp_Init FUN_a0151db4 stores as constants; FUN_a0106d64 writes +0x0C to 0xCF00ED58.
 * Callers: FUN_a0141840, FUN_a0141964.
 * Source form: DispModeTransform CALLED (FUN_a0151c84 defined in this file and inlined by gcc -O3; its own
 *   source form applies: case order and the if-chain for 0x22/0x42); the record fields read as packed u16
 *   members (gives the firmware's ldub +3 / ld +4 >> 24 / >> 8); the +0x0C/+0x0D bytes as single-bit extracts
 *   shifted into place
 *   (pre-shifted masks make gcc narrow 0x80/0xC0 to -128/-64).
 * SOURCE NOTE: DispModeTransform (FUN_a0151c84, also in its own file) is defined here as a static copy
 *   (DispModeTransform_inl) so gcc inlines it exactly as the original did, without a second global definition.
 */

struct RowHdr { unsigned int hi:12; unsigned int fmt:3; unsigned int lo:9; unsigned char mode; unsigned char b7; };
struct OutCfg
{
  unsigned char has_res;
  unsigned char pad1;
  unsigned char b25;
  unsigned char pad3;
  int dual;
  int mode;
  unsigned char f54a;
  unsigned char f54b;
  unsigned char pad14[2];
  unsigned short h;
  unsigned short v;
  unsigned char f55;
  unsigned char rest[15];
};
struct InTiming
{
  unsigned char b0;
  unsigned char b1;
  unsigned char b2;
  unsigned short h;
  unsigned short v;
  unsigned char b7;
} __attribute__((packed, aligned(4)));
extern struct InTiming DAT_a802e1a0;
extern unsigned char *FUN_a01241fc(void);
extern int FUN_a00df170();
extern char s_001a74f0[];
extern void FUN_a0106d64(struct OutCfg);
extern void FUN_a0139a30(void);
static int DispModeTransform_inl(void)
{
  unsigned char *row = FUN_a01241fc();
  int m = 0;
  switch (row[6])
  {
    case 0x10: m = 1; break;
    case 0x24: m = 14; break;
    case 0x20: m = 5; break;
    case 0x11: if ((*(unsigned int *)row & 0xe0000) == 0x20000) m = 3; else m = 4; break;
    case 0x21: if ((*(unsigned int *)row & 0xe0000) == 0) m = 17; else m = 8; break;
    case 0x40: if ((*(unsigned int *)row & 0xe0000) == 0) m = 6; else m = 5; break;
    case 0x41: if ((*(unsigned int *)row & 0xe0000) == 0x40000) m = 10; else if ((*(unsigned int *)row & 0xe0000) == 0) m = 9; else m = 8; break;
    case 0x22: case 0x42: if ((*(unsigned int *)row & 0xe0000) == 0x40000) m = 13; else if ((*(unsigned int *)row & 0xe0000) == 0) m = 12; else m = 11; break;
  }
  FUN_a00df170(s_001a74f0, row[6], ((struct RowHdr *)row)->fmt, m);
  return m;
}

void FUN_a015373c(void)
{
  struct OutCfg c;
  unsigned char *row = FUN_a01241fc();
  unsigned int h;
  unsigned char *r;
  int m;
  c.b25 = ((*((unsigned int *) row)) >> 25) & 1;
  h = DAT_a802e1a0.h;
  if (h != 0)
  {
    c.has_res = 1;
    c.h = h;
    c.v = DAT_a802e1a0.v;
  }
  else
  {
    c.has_res = 0;
  }
  if (row[7] == 10)
  {
    c.dual = 2;
  }
  else
  {
    c.dual = 0;
  }
  m = DispModeTransform_inl();
  c.mode = m;
  c.f54a = (((*((unsigned int *) (row + 0x54))) >> 29 & 1) << 7) | (((*((unsigned int *) (row + 0x54))) >> 31) << 5) | (((*((unsigned int *) (row + 0x54))) >> 30 & 1) << 4);
  c.f54b = ((*((unsigned int *) (row + 0x54))) >> 27 & 3) << 6;
  c.f55 = row[0x55];
  FUN_a0106d64(c);
  FUN_a0139a30();
}
