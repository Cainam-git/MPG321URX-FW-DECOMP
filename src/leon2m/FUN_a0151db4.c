/* leon2m FUN_a0151db4 @ 0xa0151db4  Disp_Init (hand; BYTE-EXACT at -mcpu=v8 -O3
 * and at -mcpu=v8 -O3 -g). Real size 0x25C bytes.
 *
 * Prints "Disp_Init", builds a 36-byte output configuration and passes it BY VALUE to FUN_a0105150 (output path
 * set-up, variant A; FUN_a015373c builds the same record for FUN_a0106d64).
 *   rec = the saved-settings record 0xA802E1A0 (packed, see FUN_a0145af8): u16 x at +1, h at +3, v at +5.
 *   +0x10 = rec.h, +0x12 = rec.v, +0x0E = rec.x; +0 / +1 = 1 / 1 when h != 0, else 1 / 0 when x != 0, else +0 = 0.
 *   +0x02 = 0. +0x04 = 3 when the active row's bits per colour (byte 7) is 8 and its link type (word 0 bits 20..22)
 *   is 2, 0 for 8 bits on other links, 2 for 10 bits, else left unset.
 *   +0x08 = DispModeTransform() (FUN_a0151c84, inlined), +0x0C = 0x80, +0x0D = 0, +0x14 = 0.
 * No direct call by address; System_Initialize FUN_a015209c inlines this function.
 * BYTE-EXACT keys: DispModeTransform CALLED and inlined (its keys: case order, if-chain for 0x22/0x42); packed
 *   record fields.
 * SOURCE NOTE: DispModeTransform (FUN_a0151c84, its own byte-exact file) is defined here as a static copy
 *   (DispModeTransform_inl) so gcc inlines it exactly as the original did, without a second global definition.
 */

struct RowHdr { unsigned int hi:12; unsigned int fmt:3; unsigned int lo:9; unsigned char mode; unsigned char b7; };
extern unsigned char *FUN_a01241fc(void);
extern int FUN_a00df170();
extern char s_001a74f0[];
struct OutCfg { unsigned char b0, b1, b2, pad3; int dual; int mode; unsigned char f54a, f54b; unsigned short x14;
                unsigned short h, v; unsigned char f55; unsigned char rest[15]; };
struct InTiming { unsigned char b0; unsigned short x; unsigned short h; unsigned short v; unsigned char b7; } __attribute__((packed, aligned(4)));
extern struct InTiming DAT_a802e1a0;
extern void FUN_a0105150(struct OutCfg);
extern char s_001a7518[];
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

void FUN_a0151db4(void)
{
    struct OutCfg c;
    unsigned char *row = (unsigned char *)FUN_a01241fc();
    c.b2 = 0;
    FUN_a00df170(s_001a7518);
    c.h = DAT_a802e1a0.h;
    c.v = DAT_a802e1a0.v;
    c.x14 = DAT_a802e1a0.x;
    if (c.h != 0) { c.b0 = 1; c.b1 = 1; }
    else if (c.x14 != 0) { c.b0 = 1; c.b1 = 0; }
    else c.b0 = 0;
    if (row[7] == 8) { if ((*(unsigned int *)row & 0x700000) == 0x200000) c.dual = 3; else c.dual = 0; }
    else if (row[7] == 10) c.dual = 2;
    c.mode = DispModeTransform_inl();
    c.f54a = 0x80;
    c.f54b = 0;
    c.f55 = 0;
    FUN_a0105150(c);
}
