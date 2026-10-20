/* leon2m FUN_a0142518 @ 0xa0142518-0xa01427d4 (175 words), -mcpu=v8 -O3 -g:
 * (behaviour checked against the asm on every path).
 * What it does: called by FUN_a013c144 (480p chain) when port record word +0x70 bit 30 is set, with the active
 *   size w (width) and h (lines). rec = FUN_a013cd4c(port); return when (word0 & 0xe) == 4. m = word0 bits 1..3:
 *   0 -> 0, 1 -> 1, else 3. DAT_a802e3d0 bit 25 + rec word +0x70 bit 31 + FUN_a0121258(port) == 1: w rounded up
 *   to a multiple of 8. pad = 0. FUN_a0142e8c(port) == 5: class c = FUN_a00fd820(port) (0xb1 -> FUN_a012fc20());
 *   lim = DAT_a802e116[r].h06 with r = FUN_a0142168(byte +0x0a of source record DAT_a802e224[src], src = word0
 *   bits 12..15) when c is 0x71/0x81/0x31/0x41/0x51/0x61 and r <= 6, else 0; pad = w;
 *   FUN_a011ff28(m, w > lim ? w + 0x22 : lim). pad < 0x30: FUN_a00f98f4(port, 0x30 - pad) and pad = 0x30; else
 *   FUN_a00f98f4(port, 0). Tail: FUN_a01200f8(m, pad, h) when e3d0 bit 25 + w70 bit 31 + FUN_a0121258(src) == 1;
 *   else FUN_a01200f8(m, pad, h >> 1) when FUN_a0121258(src) != 0 (interlaced source: half the lines); else
 *   FUN_a01200f8(m, pad, h).
 * Only the size (w, h), the source class and the interlace flag matter here, not the input rate;
 *   this is the 480p / interlace chain size set-up (pad = horizontal padding, at least 0x30).
 * Code facts that fix the source, all plain C, no aids:
 *   - m through an inline helper 'r = 3; switch (v) { case 0; case 1 }' (fw: 'mov 3' in the bne delay slot, then
 *     the 'mov %o4,%l3' copy of the helper's result).
 *   - word +0x70 bit 31 as a BIT-FIELD (with 'w70 < 0' the opcode heuristic sent the rounding block to the end).
 *   - the class test as THREE else-if arms (0x71/0x81, 0x31/0x41, 0x51/0x61) with identical lookup bodies:
 *     crossjump merges them, but at branch-prediction time each lookup is dominated by its own pair test, so the
 *     call heuristic predicts all three pair branches not taken (fw: fall-through insns in their delay slots).
 *   - lim a u16 local set in every arm and 'if (lim < w) lim = w + 0x22; FUN_a011ff28(m, lim);' (fw: both sides
 *     'sll 16' in the compare, one shared 'srl 16' before the call).
 *   - the e3d0 bit-25 skip of the rounding written as a 'goto sized;' (gcc 3.4 PRED_GOTO predicts the goto path
 *     not taken). Same code; the changed block frequencies make global-alloc give port %l1 and pad %l2 like the
 *     fw (with the plain '&&' chain pad's priority was 400 vs port's 397 and the two swapped).
 *   FUN_a01200f8's 2nd arg is the u16 pad (fw sets %i1 = 0x300000 only on the pad < 0x30 path).
 */
struct Port {
  unsigned int w0;
  unsigned char p04[0x70 - 4];
  unsigned int b31 : 1;
  unsigned int b30 : 1;
  unsigned int r70 : 30;
};
struct SrcT { unsigned char p00[0x0a]; unsigned char b0a; unsigned char p0b[0x2a - 0x0b]; };
struct Ent { unsigned char p00[6]; unsigned short h06; unsigned char p08[0x12 - 8]; };
extern struct SrcT DAT_a802e224[];
extern struct Ent DAT_a802e116[];
extern unsigned int DAT_a802e3d0;
extern struct Port *FUN_a013cd4c(unsigned char port);
extern unsigned char FUN_a0121258(unsigned char port);
extern unsigned char FUN_a0142e8c(unsigned char port);
extern unsigned char FUN_a00fd820(unsigned char);
extern unsigned char FUN_a012fc20(void);
extern unsigned char FUN_a0142168(unsigned char);
extern void FUN_a011ff28(unsigned char, unsigned short);
extern void FUN_a00f98f4(unsigned char, unsigned char);
extern void FUN_a01200f8(unsigned char, unsigned short, unsigned short);

static unsigned char mode_of(unsigned int v)
{
  unsigned char r = 3;
  switch (v) {
  case 0: r = 0; break;
  case 1: r = 1; break;
  }
  return r;
}

void FUN_a0142518(unsigned char port, unsigned short w, unsigned short h)
{
  struct Port *rec;
  unsigned char m, c;
  unsigned short pad, lim;

  rec = FUN_a013cd4c(port);
  if ((rec->w0 & 0xe) == 4)
    return;
  pad = 0;
  m = mode_of((rec->w0 >> 1) & 7);
  if (!(DAT_a802e3d0 & 0x2000000))
    goto sized;
  if (rec->b31 && FUN_a0121258(port) == 1)
    w = (w + 7) / 8 * 8;
sized:
  if (FUN_a0142e8c(port) == 5) {
    c = FUN_a00fd820(port);
    if (c == 0xb1)
      c = FUN_a012fc20();
    if (c == 0x71 || c == 0x81) {
      if (FUN_a0142168(DAT_a802e224[(rec->w0 >> 12) & 0xf].b0a) <= 6)
        lim = DAT_a802e116[FUN_a0142168(DAT_a802e224[(rec->w0 >> 12) & 0xf].b0a)].h06;
      else
        lim = 0;
    } else if (c == 0x31 || c == 0x41) {
      if (FUN_a0142168(DAT_a802e224[(rec->w0 >> 12) & 0xf].b0a) <= 6)
        lim = DAT_a802e116[FUN_a0142168(DAT_a802e224[(rec->w0 >> 12) & 0xf].b0a)].h06;
      else
        lim = 0;
    } else if (c == 0x51 || c == 0x61) {
      if (FUN_a0142168(DAT_a802e224[(rec->w0 >> 12) & 0xf].b0a) <= 6)
        lim = DAT_a802e116[FUN_a0142168(DAT_a802e224[(rec->w0 >> 12) & 0xf].b0a)].h06;
      else
        lim = 0;
    } else
      lim = 0;
    pad = w;
    if (lim < w)
      lim = w + 0x22;
    FUN_a011ff28(m, lim);
  }
  if (pad < 0x30) {
    FUN_a00f98f4(port, 0x30 - pad);
    pad = 0x30;
  } else {
    FUN_a00f98f4(port, 0);
  }
  if ((DAT_a802e3d0 & 0x2000000) && rec->b31 && FUN_a0121258((rec->w0 >> 12) & 0xf) == 1)
    FUN_a01200f8(m, pad, h);
  else if (FUN_a0121258((rec->w0 >> 12) & 0xf))
    FUN_a01200f8(m, pad, h >> 1);
  else
    FUN_a01200f8(m, pad, h);
}
