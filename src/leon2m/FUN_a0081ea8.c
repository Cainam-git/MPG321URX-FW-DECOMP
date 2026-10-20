/* leon2m FUN_a0081ea8 @ 0xa0081ea8..0xa0082acc (777 words), flags -mcpu=v8 -O3 -g
 * (rawcmp a0081ea8..a0082acc 777 words / 0 mismatches).
 * Hand: all 6 cases written from the asm.
 *
 * What it does: APP power-state entry, switch on the state 0..5 (jump table at run-time 0x201EC, case = +0xA0060000).
 * G = settings block DAT_a802d290 (w000 flags, b01e current item, 0x1fc bytes), C = DAT_a802cff4 state words.
 * 0 "APPSTATE_PWR_ONOFF": skip when Burn In b1d5 != 0 and h1f6 == 0x55AA. C->h004 & 0x6000 == 0 or 0x4000:
 *   "dc off" path (b1e2/b1e6 refresh from C->h010, LED/af41 bit 0 off, save settings, FUN_a0080490(0));
 *   == 0x2000: "dc on": clears w000 bit 14, factory reset of b1d5/h1f6 (0xBB99) + FUN_a0145c5c(n, 0) list
 *   when armed, power-on sequence, "show logo" when (w000 & 0x5000) == 0x1000 and h1f6 != 0x55AA.
 * 1: when any port FUN_a0143c14(0..3) != 0: af41 bit 0 off, FUN_a0090fd8, FUN_a0080490(0).
 * 2 "APPSTATE_PWR_ON": like the dc-on tail (logo, FUN_a0086ae8(1), C->h000 bit 10, b1a1/b1a2 from tables).
 * 3 "APPSetPowersaving 01/02": power saving entry with "--->RETURN0/1/2" exits.
 * 4: LED/GPIO + panel off sequence, FUN_a014a820(0), FUN_a01437fc().
 * 5: C->h004 & 0x6000 == 0x4000 and w000 bit 9 clear: FUN_a0080978 + af60[0..3] = 0xFF; when FUN_a01279dc() == 1
 *   and FUN_a0090fcc() != 0xFE: (w000 bit 9 clear: FUN_a0124b40, FUN_a0124a68, af60[0..3] = 0xFF),
 *   FUN_a00d9978, FUN_a00d99a8, FUN_a00da754(G b0ac); when C->h006 bit 6: clear it, next item, FUN_a0086ae8(3).
 *
 * Keys: cff4 +0 / +4 as BIT-FIELDS (susp:2 = bits 13..14, b12, b14, b10), w000 bit 14 clear as a bit-field,
 * if/else FUN_a014a820(1)/(0), the store orders of the b1a1/b1a2 tails and the 0xFF byte groups.
 * Keys (case 5):
 * - C->h006 bit-6 clear as a BIT-FIELD (s006.b6 = 0): fixes the and/sth/or schedule at 0xA0082210..18.
 * - DOCUMENTED NO-CODE AID, dead test: 'm' is the unsigned short result of FUN_a0090fcc(); 'm >> 16' is always 0
 *   (a 0..0xFFFF value shifted right by 16), so '!(m >> 16)' is always 1 and the added '&&' operand never jumps:
 *   behaviour is unchanged and combine deletes the test (nonzero bits of the zero-extended u16), so it emits NO
 *   instruction (final code = firmware, ). __builtin_expect(.., 1) only states that it is always true (a
 *   branch-probability note, no code). Why it is needed: without it cse1 follows the 'w000 bit 9 set' jump around
 *   the then-block (cse skip-blocks, the join label had one use) and reuses the &DAT_a802d290 register of the w000
 *   test for the b0ac read (fw: a fresh 'or %l0,0x290,%i0' in the FUN_a00d9978 delay slot). The second jump to
 *   the join label stops that; with plain '!(m >> 16)' the bb-reorder cold-trace order moves (97.43), the
 *   __builtin_expect form keeps the firmware layout.
 * - The asm-label alias alternative (extern struct G290 G_alias __asm__("DAT_a802d290") for the b0ac read) also
 *   breaks the CSE link but tops out at rawcmp 1 (0xA00827C8): combine folds the alias' own single-use HIGH into
 *   'sethi %hi(DAT_a802d290+0xac)' instead of reusing %l0. Not used.
 */
struct G290 {
  union { unsigned int w000; struct { unsigned int hi : 17, b14 : 1, x13 : 1, b12 : 1, x : 2, b9 : 1, lo : 9; } s000; };
  unsigned char p004[0x1a];
  unsigned char b01e, b01f;
  unsigned char p020[0x88];
  unsigned int w0a8;
  union { unsigned int w0ac; unsigned char b0ac; };
  unsigned char p0b0[0xe7];
  unsigned char b197[4];
  unsigned char b19b[4];
  unsigned char p19f;
  unsigned char b1a0, b1a1, b1a2;
  unsigned char p1a3[0x32];
  unsigned char b1d5, b1d6;
  unsigned char p1d7[0xb];
  unsigned char b1e2;
  unsigned char p1e3[3];
  unsigned char b1e6;
  unsigned char p1e7[0xf];
  unsigned short h1f6;
};
struct Scff4 {
  union { unsigned short h000; struct { unsigned short b15 : 1, b14 : 1, b11 : 3, b10 : 1, rest : 10; } s000; };
  unsigned short h002;
  union { unsigned short h004; struct { unsigned short b15 : 1, susp : 2, b12 : 1, rest : 12; } s004; };
  union { unsigned short h006; struct { unsigned short x : 9, b6 : 1, lo : 6; } s006; };
  unsigned short h008, h00a, h00c, h00e, h010;
  unsigned char p012[7];
  unsigned char b019;
  unsigned char p01a[0x24];
  union { unsigned short h03e; struct { unsigned char b03e, b03f; }; };
};
extern struct G290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4;
extern unsigned char DAT_a802d288;
extern unsigned char DAT_a802af41;
extern unsigned char DAT_a802af60[4];
extern unsigned char DAT_a8024010[4];
extern const char s_000fedd8[], s_000fedf0[], s_000fedf8[], s_000fee10[], s_000fee28[], s_000fee38[];
extern const char s_000fee48[], s_000fedc8[], s_000fee60[], s_000fee70[];
extern int FUN_a00df170();
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00dc3dc(void);
extern void FUN_a0145c5c(int, int);
extern void FUN_a0145360(int);
extern void FUN_a00d9238(void);
extern void FUN_a0127898(void);
extern void FUN_a00d5cd8(void);
extern void FUN_a014782c(int);
extern void FUN_a00d9978(void);
extern void FUN_a0125950(void);
extern void FUN_a0125898(void);
extern void FUN_a00db12c(unsigned char);
extern void FUN_a0125988(void);
extern void FUN_a0148aa8(unsigned char);
extern void FUN_a0148268(int, int);
extern void FUN_a008ef48(void);
extern void FUN_a008ee6c(int, int);
extern void FUN_a0143d98(void);
extern void FUN_a0143da8(void);
extern unsigned short FUN_a0090fcc(void);
extern void FUN_a0090fd8(void);
extern void FUN_a0080490(int);
extern unsigned char FUN_a01279dc(void);
extern void FUN_a0086ae8(int);
extern void FUN_a0080978(void);
extern void FUN_a00d99a8(void);
extern void FUN_a00da754(unsigned char);
extern unsigned char FUN_a012792c(void);
extern unsigned char FUN_a0127944(void);
extern void FUN_a01278f0(unsigned char);
extern void FUN_a0127914(unsigned char);
extern void FUN_a0127c78(void);
extern void FUN_a0124a08(void);
extern void FUN_a0124ab0(void);
extern void FUN_a0124af8(void);
extern void FUN_a0124a68(void);
extern void FUN_a0124b40(void);
extern void FUN_a0125ac8(void);
extern void FUN_a0125c18(void);
extern void FUN_a014a820(int);
extern void FUN_a01437fc(void);
extern void FUN_a012596c(void);
extern void FUN_a01259a4(void);
extern void FUN_a0125be0(void);
extern void FUN_a01258ec(void);
extern void FUN_a01259c0(unsigned char);
extern void FUN_a0125d90(void);
extern void FUN_a012587c(void);
extern void FUN_a0125bbc();
extern void FUN_a0125dac(void);
extern void FUN_a0125d74(void);
extern unsigned char FUN_a0141a98(void);
extern void FUN_a014512c(unsigned int, unsigned int);
extern void FUN_a0147760(void);
extern void FUN_a0125a24(void);
extern void FUN_a0125de4(void);
extern void FUN_a008767c(int);
extern void FUN_a01451fc(void);
extern int FUN_a014aed0();
extern void FUN_a00869b0(int, int);
extern unsigned char FUN_a0143c14(unsigned char);

void FUN_a0081ea8(unsigned int state)
{
  unsigned char saved = DAT_a802d290.b01e;
  unsigned char i, none;
  unsigned short m;

  switch (state) {
  case 0:
    FUN_a00df170(s_000fedd8);
    if (DAT_a802d290.b1d5 != 0 && DAT_a802d290.h1f6 == 0x55aa)
      return;
    if (DAT_a802cff4.s004.susp == 0 || DAT_a802cff4.s004.susp == 2) {
      FUN_a00df170(s_000fee60);
      if (DAT_a802cff4.h010 <= 4 && FUN_a0090fcc() == 0x10a && DAT_a802d290.b1e2 != DAT_a802cff4.h010) {
        DAT_a802d290.b1e2 = DAT_a802cff4.h010;
        DAT_a802d290.b1e6 = 0;
      }
      if (DAT_a802cff4.h010 <= 4 && DAT_a802d290.b1e2 != DAT_a802cff4.h010 && DAT_a802cff4.b019 == 1) {
        DAT_a802d290.b1e2 = DAT_a802cff4.h010;
        DAT_a802d290.b1e6 = 0;
      }
      if (DAT_a802af41 & 1) {
        FUN_a008ee6c(0xff, 0);
        DAT_a802af41 &= ~1;
        FUN_a0143da8();
      }
      FUN_a0090fd8();
      FUN_a014aed0(0x30, &DAT_a802d290, 0, 0x1fc);
      FUN_a0080490(0);
      return;
    }
    if (DAT_a802cff4.s004.susp != 1)
      return;
    FUN_a00df170(s_000fedf0);
    DAT_a802d290.s000.b14 = 0;
    if (DAT_a802d290.h1f6 == 0x55aa || DAT_a802d290.b1d5 != 0) {
      DAT_a802d290.h1f6 = 0xbb99;
      DAT_a802d290.b1d5 = 0;
      FUN_a00dc3dc();
      FUN_a0145c5c(8, 0);
      FUN_a0145c5c(9, 0);
      FUN_a0145c5c(6, 0);
      FUN_a0145c5c(7, 0);
      FUN_a0145c5c(0xb, 0);
      FUN_a0145c5c(0xa, 0);
      FUN_a0145c5c(0xd, 0);
      FUN_a0145c5c(0xc, 0);
      FUN_a0145c5c(0x10, 0);
      FUN_a0145c5c(0xe, 0);
      FUN_a0145c5c(0xf, 0);
      FUN_a0145360(1);
    }
    DAT_a802cff4.s004.b12 = 1;
    if (FUN_a014459c(FUN_a01445fc(DAT_a802d290.b01e) + 1) > 0x14)
      DAT_a802d290.b01e = FUN_a014459c(0);
    else
      DAT_a802d290.b01e = FUN_a014459c(FUN_a01445fc(DAT_a802d290.b01e) + 1);
    FUN_a00d9238();
    DAT_a802d290.b01e = saved;
    FUN_a00d9238();
    FUN_a0127898();
    FUN_a00d5cd8();
    FUN_a0124b40();
    FUN_a0124a68();
    if ((DAT_a802d290.w0ac & 0x100000) && DAT_a802d290.b01f == 0) {
      FUN_a014782c(2);
      FUN_a014782c(3);
    }
    FUN_a00d9978();
    FUN_a0125950();
    FUN_a0125898();
    FUN_a00db12c(0);
    FUN_a0125988();
    FUN_a0148aa8(1);
    FUN_a0148268(1, 1);
    if ((DAT_a802d290.w000 & 0x5000) == 0x1000 && DAT_a802d290.h1f6 != 0x55aa) {
      FUN_a00df170(s_000fedc8, 1);
      FUN_a008ef48();
      FUN_a008ee6c(0xff, 1);
      FUN_a008ee6c(0x40, 0);
      DAT_a802af41 |= 1;
      FUN_a0143d98();
      FUN_a00869b0(3, 3000);
    }
    if ((DAT_a802d290.w000 & 0x5000) != 0x1000 || DAT_a802d290.h1f6 == 0x55aa)
      FUN_a0143da8();
    if (DAT_a802d290.w000 & 0x4000)
      DAT_a802cff4.s000.b10 = 0;
    else
      DAT_a802cff4.s000.b10 = 1;
    DAT_a802d290.b1a1 = DAT_a802d290.b197[DAT_a802d290.b1a0];
    DAT_a802d290.b1a2 = DAT_a802d290.b19b[DAT_a802d290.b1a0];
    DAT_a802cff4.s000.b14 = 0;
    DAT_a802cff4.s004.susp = 0;
    return;

  case 1:
    none = 1;
    for (i = 0; i <= 3; i++)
      if (FUN_a0143c14(i)) {
        none = 0;
        break;
      }
    if (none)
      return;
    if (DAT_a802af41 & 1) {
      FUN_a008ee6c(0xff, 0);
      DAT_a802af41 &= ~1;
      FUN_a0143da8();
    }
    FUN_a0090fd8();
    FUN_a0080490(0);
    return;

  case 2:
    FUN_a00df170(s_000fedf8);
    DAT_a802cff4.s004.susp = 0;
    if (FUN_a014459c(FUN_a01445fc(DAT_a802d290.b01e) + 1) > 0x14)
      DAT_a802d290.b01e = FUN_a014459c(0);
    else
      DAT_a802d290.b01e = FUN_a014459c(FUN_a01445fc(DAT_a802d290.b01e) + 1);
    FUN_a00d9238();
    DAT_a802d290.b01e = saved;
    FUN_a00d9238();
    FUN_a0127898();
    FUN_a0124b40();
    FUN_a0124a68();
    FUN_a0148aa8(1);
    if ((DAT_a802d290.w000 & 0x5000) == 0x1000 && DAT_a802d290.h1f6 != 0x55aa) {
      FUN_a00df170(s_000fedc8, 1);
      FUN_a008ef48();
      FUN_a008ee6c(0xff, 1);
      FUN_a008ee6c(0x40, 0);
      DAT_a802af41 |= 1;
      FUN_a0143d98();
      FUN_a00869b0(3, 3000);
    }
    FUN_a0086ae8(1);
    if (DAT_a802d290.w000 & 0x4000)
      DAT_a802cff4.s000.b10 = 0;
    else
      DAT_a802cff4.s000.b10 = 1;
    DAT_a802d290.b1a1 = DAT_a802d290.b197[DAT_a802d290.b1a0];
    DAT_a802d290.b1a2 = DAT_a802d290.b19b[DAT_a802d290.b1a0];
    DAT_a802cff4.s000.b14 = 0;
    return;

  case 3:
    FUN_a00df170(s_000fee10);
    DAT_a802cff4.b03f = 0;
    DAT_a802cff4.h00c = 0;
    if (FUN_a012792c() || FUN_a0127944()) {
      FUN_a00df170(s_000fee28);
      DAT_a802cff4.s000.b10 = 1;
      return;
    }
    FUN_a0090fd8();
    FUN_a01278f0(1);
    FUN_a0127914(1);
    FUN_a0127c78();
    if (FUN_a012792c() || FUN_a0127944()) {
      FUN_a00df170(s_000fee38);
      DAT_a802cff4.s000.b10 = 1;
      return;
    }
    FUN_a00df170(s_000fee48);
    DAT_a802cff4.h03e &= ~0x8000;
    FUN_a0124a08();
    if (DAT_a802d290.h1f6 != 0x55aa || DAT_a802d290.b1d6 != 0x55) {
      FUN_a0124ab0();
      FUN_a0124af8();
    }
    if (DAT_a802d290.h1f6 != 0x55aa || DAT_a802d290.b1d6 != 0x55)
      FUN_a0125ac8();
    FUN_a0125c18();
    if (!(DAT_a802d290.w0a8 & 0x8000) && !FUN_a01279dc()) {
      if (DAT_a802d290.h1f6 != 0x55aa || DAT_a802d290.b1d6 != 0x55) {
        FUN_a012596c();
        FUN_a01259a4();
        FUN_a0125be0();
        FUN_a01259c0(0);
      }
      if (DAT_a802d288 == 1 && DAT_a802d290.h1f6 == 0x55aa) {
        FUN_a0125950();
        FUN_a0125d90();
        FUN_a012587c();
        FUN_a0125bbc(1);
      } else if (DAT_a802d290.h1f6 != 0x55aa || DAT_a802d290.b1d6 != 0x55) {
        FUN_a012596c();
        FUN_a0125dac();
        FUN_a0125bbc(0);
        FUN_a0125d74();
      }
    }
    if (FUN_a01279dc() == 1) {
      if (FUN_a0141a98())
        FUN_a014512c(0, 1);
      FUN_a00df170(s_000fee70);
      DAT_a802cff4.s000.b10 = 1;
      return;
    }
    if ((DAT_a802d290.w0ac & 0x100000) && DAT_a802d290.b01f == 0) {
      DAT_a8024010[3] = 0xff;
      DAT_a8024010[2] = 0xff;
      DAT_a8024010[1] = 0xff;
      DAT_a8024010[0] = 0xff;
    } else if (!(DAT_a802d290.w0a8 & 0x8000))
      FUN_a0147760();
    if (DAT_a802d290.w000 & 0x200)
      FUN_a014a820(1);
    else
      FUN_a014a820(0);
    if (DAT_a802cff4.h006 & 0x80) {
      FUN_a014512c(0, 1);
      DAT_a802cff4.h006 |= 0x40;
    } else {
      FUN_a014512c(0, 1);
      FUN_a0125a24();
      if (DAT_a802d290.h1f6 != 0x55aa || DAT_a802d290.b1d6 != 0x55) {
        FUN_a0125de4();
        FUN_a008767c(1);
        FUN_a01451fc();
      }
    }
    DAT_a802cff4.s000.b10 = 1;
    return;

  case 4:
    FUN_a0124ab0();
    FUN_a0124af8();
    FUN_a0125ac8();
    FUN_a0125c18();
    if (!(DAT_a802d290.w0a8 & 0x8000)) {
      FUN_a012596c();
      FUN_a01259a4();
      FUN_a0125be0();
      FUN_a01258ec();
    }
    FUN_a014a820(0);
    FUN_a01437fc();
    return;

  case 5:
    if (DAT_a802cff4.s004.susp == 2 && !(DAT_a802d290.w000 & 0x200)) {
      FUN_a0080978();
      DAT_a802af60[0] = 0xff;
      DAT_a802af60[1] = 0xff;
      DAT_a802af60[2] = 0xff;
      DAT_a802af60[3] = 0xff;
    }
    if (FUN_a01279dc() == 1 && (m = FUN_a0090fcc()) != 0xfe) {
      if (__builtin_expect(!(m >> 16), 1) && !(DAT_a802d290.w000 & 0x200)) {
        FUN_a0124b40();
        FUN_a0124a68();
        DAT_a802af60[0] = 0xff;
        DAT_a802af60[1] = 0xff;
        DAT_a802af60[2] = 0xff;
        DAT_a802af60[3] = 0xff;
      }
      FUN_a00d9978();
      FUN_a00d99a8();
      FUN_a00da754(DAT_a802d290.b0ac);
    }
    if (DAT_a802cff4.h006 & 0x40) {
      DAT_a802cff4.s006.b6 = 0;
      if (FUN_a014459c(FUN_a01445fc(DAT_a802d290.b01e) + 1) > 0x14)
        DAT_a802d290.b01e = FUN_a014459c(0);
      else
        DAT_a802d290.b01e = FUN_a014459c(FUN_a01445fc(DAT_a802d290.b01e) + 1);
      FUN_a00d9238();
      DAT_a802d290.b01e = saved;
      FUN_a00d9238();
      FUN_a0124b40();
      FUN_a0124a68();
      FUN_a0148aa8(1);
      FUN_a0086ae8(3);
    }
    return;
  }
}
