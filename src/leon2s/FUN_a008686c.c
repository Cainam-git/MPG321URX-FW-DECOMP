/* FUN_a008686c (leon2s), flags -mcpu=v8 -Os -g.
 * Reads 16 bytes d[] with FUN_a0086400(port, 0x90, 0, 0xf, d) into the 6-byte record ARR_a807cd2e[port]:
 * bytes 1..4 = d[0..3], byte 5 = d[14] & 0x7f; ok = (result != 0). When bit 7 of d[14] is set, reads again with
 * FUN_a0086400(port, 0x90, 0x2200, 0xf, d) (ok = 0 on a zero result), raises bytes 1..3 to d[0..2] where those
 * are larger and sets byte 5 = d[14] when d[14] & 0x7f is larger. Then: byte 2 in 31..40 becomes 0x1e; byte 2 other than 6, 0x0a, 0x14, 0x1e
 * becomes 6 (ok = 0); bits 0x10, 0x40 and 0x20 of byte 0 copy bit 7 of byte 3, bit 6 of byte 3 and bit 7 of
 * byte 4; byte 3 keeps its low 5 bits and becomes 1 unless they are 1, 2 or 4 (ok = 0); byte 5 = 4 * byte 5 when
 * byte 5 is 1..4, else 1; bit 3 of byte 0 copies bit 6 of d[7]. Last, FUN_a008639c(port, 0x90, 0x21, d) fills d
 * again; bits 2 and 1 of byte 0 take bits 0 and 1 of d[0], and bit 7 of byte 0 = ok when that call returned 0.
 * Source form: the first copies go through a row pointer; byte 5 is read through an inlined static helper; bit 7
 * is a 1-bit field of a union view of the record, stored from 'unsigned char b7 = -(x == 0) & ok' computed in an
 * unsigned int mask m first (the firmware's addx -1 mask).
 */
union Rec6 {
    unsigned char b[6];
    struct { unsigned char f7 : 1, f6 : 1, f5 : 1, f4 : 1, f3 : 1, f2 : 1, f1 : 1, f0 : 1; } bits;
};

extern union Rec6 ARR_a807cd2e[];
extern unsigned char FUN_a0086400(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char FUN_a008639c(unsigned int, unsigned int, unsigned int, unsigned char *);
static inline unsigned char rec5(unsigned char p)
{
  return ARR_a807cd2e[p].b[5];
}

void FUN_a008686c(unsigned char port)
{
  unsigned char d[16] = {0};
  unsigned char ok;
  unsigned char ok2;
  unsigned char x;
  unsigned int v;
  unsigned char *row;
  ok = FUN_a0086400(port, 0x90, 0, 0xf, d) != 0;
  v = d[14];
  row = ARR_a807cd2e[port].b;
  row[1] = d[0];
  row[2] = d[1];
  row[3] = d[2];
  row[4] = d[3];
  row[5] = v & 0x7f;
  ok2 = ok;
  if (v & 0x80)
  {
    if (FUN_a0086400(port, 0x90, 0x2200, 0xf, d) == 0)
    {
      ok2 = 0;
    }
    if (d[0] > ARR_a807cd2e[port].b[1])
    {
      ARR_a807cd2e[port].b[1] = d[0];
    }
    if (d[1] > ARR_a807cd2e[port].b[2])
    {
      ARR_a807cd2e[port].b[2] = d[1];
    }
    if (d[2] > ARR_a807cd2e[port].b[3])
    {
      ARR_a807cd2e[port].b[3] = d[2];
    }
    if ((d[14] & 0x7f) > rec5(port))
    {
      ARR_a807cd2e[port].b[5] = d[14];
    }
  }
  if (((unsigned char) (ARR_a807cd2e[port].b[2] - 31)) <= 9)
  {
    ARR_a807cd2e[port].b[2] = 0x1e;
  }
  x = ARR_a807cd2e[port].b[2];
  if ((x != 6) && (x != 0xa))
  {
    if (x != 0x14)
    {
      if (x != 0x1e)
      {
        ARR_a807cd2e[port].b[2] = 6;
        ok2 = 0;
      }
    }
  }
  if (((signed char) ARR_a807cd2e[port].b[3]) < 0)
  {
    ARR_a807cd2e[port].b[0] |= 0x10;
  }
  else
  {
    ARR_a807cd2e[port].b[0] &= ~0x10;
  }
  if (ARR_a807cd2e[port].b[3] & 0x40)
  {
    ARR_a807cd2e[port].b[0] |= 0x40;
  }
  else
  {
    ARR_a807cd2e[port].b[0] &= ~0x40;
  }
  if (((signed char) ARR_a807cd2e[port].b[4]) < 0)
  {
    ARR_a807cd2e[port].b[0] |= 0x20;
  }
  else
  {
    ARR_a807cd2e[port].b[0] &= ~0x20;
  }
  x = ARR_a807cd2e[port].b[3] & 0x1f;
  ARR_a807cd2e[port].b[3] = x;
  if ((((unsigned char) (x - 1)) > 1) && (x != 4))
  {
    ARR_a807cd2e[port].b[3] = 1;
    ok2 = 0;
  }
  x = rec5(port);
  if (((unsigned char) (x - 1)) <= 3)
  {
    ARR_a807cd2e[port].b[5] = x << 2;
  }
  else
  {
    ARR_a807cd2e[port].b[5] = 1;
  }
  if (d[7] & 0x40)
  {
    ARR_a807cd2e[port].b[0] |= 8;
  }
  else
  {
    ARR_a807cd2e[port].b[0] &= ~8;
  }
  x = FUN_a008639c(port, 0x90, 0x21, d);
  {
    unsigned int m = -(x == 0);
    unsigned char b7 = m & ok2;

    ARR_a807cd2e[port].b[0] = (ARR_a807cd2e[port].b[0] & (~6)) | ((d[0] & 1) << 2) | (d[0] & 2);
    ARR_a807cd2e[port].bits.f7 = b7;
  }
}
