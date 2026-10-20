/* leon2m FUN_a0082ec4 @ 0xa0082ec4-0xa00830f4 (140 words), flags -mcpu=v8 -O3 -g. No callers by direct call.
 * Reads h = FUN_a0145660(1, 7) and w = FUN_a0145660(1, 8). a = 1 when |h - u16 0xa8024006| <= h / 6, b = 1 when
 * |w - u16 0xa8024004| <= w / 6. Searches the 12 records of 18 bytes at 0xfeb30 (u16 fields at +0, +2, +6) for the
 * first one with |h - rec.h| <= 10 and |w - rec.w| <= 10; nothing is written when none is found. Found:
 *   a == 0: *p3 = v06 + 8, *p1 = u16 0xa802400a - 8, *p4 = rec.x6;
 *   a == 1 and b == 0: v06 > v04: *p3 = v06 + 8, *p1 = v0a, *p4 = rec.x6, *p2 = 0;
 *                      else *p3 = v06, *p1 = v0a, *p4 = v04, *p2 = u16 0xa8024008.
 * Source form: the distances are kept in a variable d (a direct abs(..) <= 10 test is folded into a range test);
 * compiler aid: __builtin_expect(.., 1) on the a == 1 && b == 0 test emits no instructions; it places the a == 0
 * block after the other blocks, as in the firmware.
 */
struct Rec { unsigned short h, w, x4, x6, r[5]; };

extern unsigned short DAT_a8024004, DAT_a8024006, DAT_a8024008, DAT_a802400a;
extern const struct Rec DAT_000feb30[];
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern int abs(int);

void FUN_a0082ec4(unsigned short *p1, unsigned short *p2, unsigned short *p3, unsigned short *p4)
{
  unsigned short h, w, th, tw;
  unsigned char a, b, found, i;
  int d;

  h = FUN_a0145660(1, 7);
  w = FUN_a0145660(1, 8);
  found = 0;
  th = h / 6;
  if (abs(h - DAT_a8024006) > th)
    a = 0;
  else
    a = 1;
  tw = w / 6;
  if (abs(w - DAT_a8024004) > tw)
    b = 0;
  else
    b = 1;
  for (i = 0; i < 12; i++) {
    d = abs(h - DAT_000feb30[i].h);
    if (d > 10)
      continue;
    d = abs(w - DAT_000feb30[i].w);
    if (d > 10)
      continue;
    found = 1;
    break;
  }
  if (found) {
    if (a == 0) {
      *p3 = DAT_a8024006 + 8;
      *p1 = DAT_a802400a - 8;
      *p4 = DAT_000feb30[i].x6;
    } else if (__builtin_expect(a == 1 && b == 0, 1)) {
      if (DAT_a8024006 > DAT_a8024004) {
        *p3 = DAT_a8024006 + 8;
        *p1 = DAT_a802400a;
        *p4 = DAT_000feb30[i].x6;
        *p2 = 0;
      } else {
        *p3 = DAT_a8024006;
        *p1 = DAT_a802400a;
        *p4 = DAT_a8024004;
        *p2 = DAT_a8024008;
      }
    }
  }
}
