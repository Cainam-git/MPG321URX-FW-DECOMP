/* leon2m FUN_a00f446c @ 0xa00f446c-0xa00f4e60 (637 words), flags -mcpu=v8 -O3 -g.
 *
 * What it does: pointer-called link-training / equaliser calibration of input block blk; p = training record,
 *   u16 p->h0c = lower bound of the sweep value. Returns 1 = trained, 0 = failed.
 *   FUN_a0121d4c(blk) == 0 -> return 0. Progress byte DAT_a802b7b1 = 4; regs 0x2a / 0x4a saved, reg 0x2a = 0,
 *   reg 0x4a bit 7 = ((hw 0xcf020114 & 7) == 5); flags DAT_a802b7ad (sweep failed) and DAT_a802b7ac (abort) = 0.
 *   FUN_a00f3c18(blk, p) (set-up) must succeed. Every failure runs fail(): restore 0x2a / 0x4a, then the progress
 *   callback DAT_a802b79c(pct++) every 20 ms up to 99, then (100); input lost (FUN_a0121374(blk) == 1) during it
 *   sets the abort flag and stops.
 *   Stage 0 (only when neither flag is set): sweep value v = FUN_a00f3528() (u16, kept as orig; started at
 *     h0c + 0x10 when v <= h0c), up to 32 passes: FUN_a0121e3c, reg 0x36 = 0x41, wait <= 0x63 timer ticks for
 *     reg 0x36 bit 0 to clear (else abort flag, orig back, fail); reg 0x49: class = bits 6..7, step = bits 0..5:
 *     class 0 = done, 1 = v += step (must stay <= 2 * h0c), 2/3 = v -= step (must stay >= h0c); then the
 *     HFREQ CHECK: FUN_a0120a18(blk) (hfreq, 100 Hz units) * v must be <= 2050000 (0x1f47d0), else
 *     orig back, DAT_a802b7ad = 1, fail; then FUN_a00f42b8(blk, v).
 *   Stage 1: 4 probes FUN_a00f42b8(base - 2 .. base + 1) with the metric FUN_a00f3f64; keeps max (with the
 *     DAT_a802b7af / b0 bytes of that probe) and min; position = max pos, even-aligned unless |max - min| == 1;
 *     window code = af + 0x18 (DAT_a802b7ae = 0x20) when the max metric < (FUN_a00f8dd4 * FUN_a00f8df0) << 6,
 *     else b0 - 8 (DAT_a802b7ae = 0x10); FUN_a00f37d0(code & 0x3f).
 *   Stage 2: for j = 1 .. DAT_a802b7ae - 1: progress tick, wait for reg 0x36 bit 1 (input lost or timeout =
 *     abort), FUN_a00f37d0((start + j) & 0x3f) with start = FUN_a00f3580(), reg 0x36 = 0x42, value = reg 0x45
 *     << 16 + reg 0x43, smoothed s = v/4 + prev/2 + prev2/4; from j = 4 the position with the smallest
 *     |s - last s| wins; FUN_a00f37d0(best - 1). Then FUN_a00f3c18(blk, p) again; on success the callback
 *     steps to 100, regs 0x2a / 0x4a are restored, return 1.
 * Rate: the only rate input is the hfreq value in the stage-0 bound. Arithmetic from the code (not measured):
 *   2160p with 2250 total lines is about 135.0 kHz at 60.000 Hz (rate 1350), so the stage-0 sweep value must stay
 *   <= 2050000 / 1350 = 1518; at rate 1352 (135.2 kHz) the bound is 2050000 / 1352 = 1516.
 *
 * Source facts (plain C, no compiler aids):
 *   - window code t is an UNSIGNED CHAR and the DAT_a802b7ae store is written inside each arm. With the store
 *     in the arms each arm has 5 insns, so ifcvt (find_if_case_1, BRANCH_COST 3 on v8) does not hoist an arm
 *     before reload; after reload crossjump merges the identical arm tails 'and x,0x3f,t; sethi; stb' into the
 *     join and ce3 hoists the 2-insn af arm above the branch. The u8 t keeps the call's own 'and 0x3f'. This
 *     gives the firmware's 'double and' shape and the register renaming of the later blocks.
 *   - stage-2 wait: the input-lost test is the first statement of a for (;;) loop with its arm in place
 *     '{ DAT_a802b7ac = 1; return 0; }' (fw: the input-lost exit enters the abort block at its stb with
 *     %g1 = 1 from the compare; cse uses the compare register for the constant, crossjump merges it with the
 *     'ok == 0' abort block). This also gives the fw cold-block order. Stage 0's wait helper uses the same
 *     for (;;) form with 'break'.
 *   - the main tick before stage 1 is 'if (DAT_a802b7b1 <= 99 && DAT_a802b79c != 0) tick'.
 *   - stage 1: loads af before b0, 'af = 0' before 'b0 = 0' (fw af %l7, b0 %l6), n++ at the end of the probe
 *     body, |max - min| via abs() (fw 'xor sign, x' order).
 *   - stage 2: init order best, p1, p2, last, bestd; 'pos = (pos - 1) & 0x3f' before s.
 *   - also: goto loops in stages 0 / 1 (no loop-invariant motion in the fw), FUN_a00f3528
 *     returns unsigned short, u16 stage-1 positions, 'h2 = h + h' before the 'cur <= h' test, the hfreq
 *     limit as a local 'lim = 2050000; pr = rate * cur; if (lim < pr)', history 'p3 = p2; p2 = p1; p1 = val',
 *     e read before FUN_a00f3580, af / b0 unsigned int, 'goto abort2' for the ok == 0 abort.
 * volatile only on the hardware register 0xcf020114.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct Lt { unsigned char p00[0xc]; unsigned short h0c; };
extern unsigned char DAT_a802b7ac, DAT_a802b7ad, DAT_a802b7ae, DAT_a802b7af, DAT_a802b7b0, DAT_a802b7b1;
extern void (*DAT_a802b79c)(unsigned char pct);
extern unsigned char FUN_a0121d4c(unsigned char blk);
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned short FUN_a00f1ce4(unsigned char blk, unsigned char reg);
extern void FUN_a00f1d48(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned char FUN_a00f3c18(unsigned char blk, struct Lt *p);
extern unsigned short FUN_a00f3528(void);
extern unsigned char FUN_a00f3580(void);
extern unsigned int FUN_a00f3f64(unsigned char blk);
extern void FUN_a00f42b8(unsigned char blk, unsigned short v);
extern void FUN_a00f37d0(unsigned char v);
extern unsigned int FUN_a00f8dd4(unsigned char blk);
extern unsigned int FUN_a00f8df0(unsigned char blk);
extern unsigned short FUN_a0120a18(unsigned char blk);
extern unsigned char FUN_a0121374(unsigned char blk);
extern void FUN_a0121e3c(unsigned char blk);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void func_0x4008d1a0(int ms);
extern int abs(int);

static unsigned char fail(unsigned char blk, unsigned char s2a, unsigned char s4a)
{
  FUN_a00f2298(blk, 0x2a, s2a);
  FUN_a00f1ad4(blk, 0x4a, s4a);
  if (DAT_a802b79c == 0)
    return 0;
  while (DAT_a802b7b1 <= 99) {
    DAT_a802b79c(DAT_a802b7b1++);
    func_0x4008d1a0(20);
    if (FUN_a0121374(blk) == 1) {
      DAT_a802b7ac = 1;
      return 0;
    }
  }
  DAT_a802b79c(100);
  return 0;
}

static unsigned char wait36(unsigned char blk, unsigned char mask)
{
  unsigned short t0;
  unsigned char ok;

  t0 = func_0x4008d588();
  ok = 0;
  for (;;) {
    if (FUN_a0121374(blk) == 1)
      break;
    if (!(FUN_a00f1a90(blk, 0x36) & mask)) {
      ok = 1;
      break;
    }
    if (func_0x4008d594(t0) > 0x63)
      break;
  }
  if (ok == 0)
    DAT_a802b7ac = 1;
  return ok;
}

static unsigned char stage0(unsigned char blk, struct Lt *p)
{
  unsigned short h, cur, orig, h2;
  unsigned char k, ok, r, cls, v;
  unsigned short t0;
  unsigned int lim, pr;

  h = p->h0c;
  FUN_a00f1d48(blk, 0x47, h);
  cur = orig = FUN_a00f3528();
  h2 = h + h;
  if (cur <= h) {
    cur = h + 0x10;
    FUN_a00f42b8(blk, cur);
  }
  k = 0;
next:
    FUN_a0121e3c(blk);
    FUN_a00f1ad4(blk, 0x36, 0x41);
    if (!wait36(blk, 1)) {
      FUN_a00f42b8(blk, orig);
      return 0;
    }
    FUN_a00f1ce4(blk, 0x40);
    r = FUN_a00f1a90(blk, 0x49);
    cls = (r & 0xc0) >> 6;
    v = r & 0x3f;
    if (cls == 0)
      goto done;
    if (cls == 1) {
      cur = cur + v;
      if (cur > h2)
        goto bad;
    } else if (cls > 1) {
      cur = cur - v;
      if (cur < h)
        goto bad;
    }
    lim = 2050000;
    pr = FUN_a0120a18(blk) * cur;
    if (lim < pr)
      goto bad;
    FUN_a00f42b8(blk, cur);
    k++;
    if (k < 0x20)
      goto next;
done:
  if (k == 0xff)
    goto bad;
  return 1;
bad:
  FUN_a00f42b8(blk, orig);
  DAT_a802b7ad = 1;
  return 0;
}

static unsigned char stage1(unsigned char blk)
{
  unsigned short base, pos, maxpos, minpos, sel;
  unsigned int v, maxv, minv, lim;
  unsigned char n;
  unsigned int af, b0;
  unsigned char t;

  base = FUN_a00f3528();
  af = 0;
  maxpos = base;
  b0 = 0;
  minpos = base;
  maxv = 0;
  minv = 0xffffffff;
  pos = base - 2;
  n = 0;
again:
    FUN_a00f42b8(blk, pos);
    v = FUN_a00f3f64(blk);
    if (DAT_a802b7ac == 1)
      return 0;
    if (maxv < v) {
      af = DAT_a802b7af;
      b0 = DAT_a802b7b0;
      maxv = v;
      maxpos = pos;
    }
    if (minv > v) {
      minv = v;
      minpos = pos;
    }
    pos++;
    n++;
  if (n <= 3)
    goto again;
  sel = maxpos;
  {
    int d = abs(maxpos - minpos);
    if (d != 1)
      sel = maxpos & ~1;
  }
  FUN_a00f42b8(blk, sel);
  if (maxpos != sel) {
    maxv = FUN_a00f3f64(blk);
    af = DAT_a802b7af;
    b0 = DAT_a802b7b0;
  }
  {
    unsigned short a = FUN_a00f8dd4(blk), b = FUN_a00f8df0(blk);
    lim = (a * b) << 6;
  }
  if (maxv < lim) {
    t = (af + 0x18) & 0x3f;
    DAT_a802b7ae = 0x20;
  } else {
    t = (b0 - 8) & 0x3f;
    DAT_a802b7ae = 0x10;
  }
  FUN_a00f37d0(t);
  return 1;
}

static unsigned char stage2(unsigned char blk)
{
  unsigned char start, e, j, pos, ok, best;
  unsigned int val, p1, p2, s, last, d, bestd, p3;
  unsigned short t0;

  e = DAT_a802b7ae;
  start = FUN_a00f3580();
  FUN_a00f1ad4(blk, 0x36, 0x42);
  best = 0;
  p1 = 0;
  p2 = 0;
  last = 0;
  bestd = 0xffffffff;
  for (j = 1; j < e; j++) {
    if (DAT_a802b7b1 <= 99 && DAT_a802b79c != 0)
      DAT_a802b79c(DAT_a802b7b1++);
    t0 = func_0x4008d588();
    ok = 0;
    for (;;) {
      if (FUN_a0121374(blk) == 1) {
        DAT_a802b7ac = 1;
        return 0;
      }
      if (!(FUN_a00f1a90(blk, 0x36) & 2)) {
        ok = 1;
        break;
      }
      if (func_0x4008d594(t0) > 0x63)
        break;
    }
    if (ok == 0)
      goto abort2;
    pos = (start + j) & 0x3f;
    FUN_a00f37d0(pos);
    FUN_a00f1ad4(blk, 0x36, 0x42);
    val = (FUN_a00f1ce4(blk, 0x45) << 16) + FUN_a00f1ce4(blk, 0x43);
    p3 = p2;
    p2 = p1;
    p1 = val;
    pos = (pos - 1) & 0x3f;
    s = (p1 >> 2) + (p2 >> 1) + (p3 >> 2);
    if (j > 3) {
      if (s > last)
        d = s - last;
      else
        d = last - s;
      if (d < bestd) {
        best = pos;
        bestd = d;
      }
    }
    last = s;
  }
  FUN_a00f37d0((best - 1) & 0x3f);
  return 1;
abort2:
  DAT_a802b7ac = 1;
  return 0;
}

unsigned char FUN_a00f446c(unsigned char blk, struct Lt *p)
{
  unsigned char s4a, s2a;

  if (!FUN_a0121d4c(blk))
    return 0;
  DAT_a802b7b1 = 4;
  s2a = FUN_a00f2254(blk, 0x2a);
  s4a = FUN_a00f1a90(blk, 0x4a);
  FUN_a00f2298(blk, 0x2a, 0);
  if ((R(0xcf020114) & 7) == 5)
    FUN_a00f1b5c(blk, 0x4a, 0x80, 1);
  else
    FUN_a00f1b5c(blk, 0x4a, 0x80, 0);
  DAT_a802b7ad = 0;
  DAT_a802b7ac = 0;
  if (!FUN_a00f3c18(blk, p))
    return fail(blk, s2a, s4a);
  if (DAT_a802b7ac == 0 && DAT_a802b7ad == 0) {
    if (!stage0(blk, p))
      return fail(blk, s2a, s4a);
  }
  if (DAT_a802b7b1 <= 99 && DAT_a802b79c != 0)
    DAT_a802b79c(DAT_a802b7b1++);
  if (!stage1(blk))
    return fail(blk, s2a, s4a);
  if (!stage2(blk))
    return fail(blk, s2a, s4a);
  if (!FUN_a00f3c18(blk, p))
    return fail(blk, s2a, s4a);
  if (DAT_a802b79c != 0) {
    while (DAT_a802b7b1 <= 99) {
      DAT_a802b79c(DAT_a802b7b1++);
      func_0x4008d1a0(20);
      if (FUN_a0121374(blk) == 1) {
        DAT_a802b7ac = 1;
        goto out;
      }
    }
    DAT_a802b79c(100);
  }
out:
  FUN_a00f2298(blk, 0x2a, s2a);
  FUN_a00f1ad4(blk, 0x4a, s4a);
  return 1;
}
