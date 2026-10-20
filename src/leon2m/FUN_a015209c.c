/* leon2m FUN_a015209c @ 0xa015209c-0xa015266c (372 words; the asm header's "1284 bytes" label is wrong, its range is
 * right). System_Initialize. -mcpu=v8 -O3 -g.
 * Written from the asm.
 * What it does (start-up, once): prints "System_Initialize"; clock/PLL set-up FUN_a011d748 / FUN_a011e220 on block 7
 * and 0xff; FUN_a010031c(0, 7), (1, 7), (2, FUN_a0125124(byte 0xa802e126)), (3, FUN_a0125124(byte 0xa802e138));
 * FUN_a014f6f4, a0124eec, a0150da4, a012f12c, a00f87dc; the per-port record {2, 1, 1, 1} (12 bytes, PASSED BY VALUE)
 * to FUN_a01207f4(port 0..3); FUN_a01218c8, FUN_a01141fc. Then "Disp_Init": the 36-byte output configuration
 * (struct OutCfg, as in src/leon2m/FUN_a0105150.c) is built on the stack and PASSED BY VALUE to FUN_a0105150:
 *   he/h10/h12 = the packed 16-bit settings at bytes +1/+3/+5 of DAT_a802e1a0 (word loads, odd offsets);
 *   b0/b1 = 1/1 when h10 != 0, 1/0 when only he != 0, b0 = 0 when both are 0 (b1 then not written);
 *   w4 = 3 or 0 by panel-row word0 bits 20..22 == 2 when row byte 7 == 8, 2 when byte 7 == 10, else NOT written;
 *   w8 = display mode from row byte 6 (DispModeTransform, jump table at fw 0xf11a0, f = row word0 bits 17..19):
 *   0x10 -> 1, 0x11 -> f == 1 ? 3 : 4, 0x20 -> 5, 0x21 -> f == 0 ? 0x11 : 8, 0x24 -> 0xe, 0x40 -> f == 0 ? 6 : 5,
 *   0x41 -> f == 2 ? 0xa : f == 0 ? 9 : 8, 0x22/0x42 -> f == 2 ? 0xd : f == 0 ? 0xc : 0xb, others -> 0;
 *   printed as "------>DispModeTransform %d,%d , %d" (byte 6, f, mode); bc = 0x80, bd = 0, b2 = 0, b14 = 0
 *   (b3, b15..b17, w18..w20 are copied uninitialised, as in the fw). Then FUN_a01111e4(&zero byte) when the
 *   FIRST row pointer's word0 bits 20..22 are 0; FUN_a01410a4, a01423dc, a0129b44, a00fc200(0),
 *   a00fc30c(0xd3ea4), a0125c84, a0139a30, a0139c3c, a0139b90, a013a8d4(0x400, 0x16), a0110fb4, a015202c;
 *   FRCConfigPostFRC FUN_a0107e44(byte 0xa802e3d3 != 0, rate = u16 row +0x52 of DAT_a802e378, 1);
 *   FUN_a0109bbc(0, 0, 0, same rate); converter lock mode FUN_a01085f8(ch, 0, 0) for ch 0..3 (all cleared);
 *   FUN_a010b610; ROM timer/irq handler set-up func_0x4008a880(1, 1, FUN_a002fa34), func_0x4008c11c(4, 0x99),
 *   func_0x40089820(1, 1), FUN_a0138e28(u16 0xa802e214), func_0x4008a880(1, 2, FUN_a002fae0),
 *   func_0x40089820(1, 2); FUN_a010afe4(0), FUN_a010b1b4(0), FUN_a01382b0; "System_Initialize End" when
 *   FUN_a00dd614(0x10) (log level) is non-zero.
 * Nothing here reads the input timing. The post-FRC rate at start-up is the panel row's
 * +0x52 value; in the ROM default row DAT_001a30d0 it is 2400 (240.0 Hz), byte 6 = 0x42, byte 7 = 0x0a, word0
 * 0x2c120400 (f = 1 -> mode 0xb, w4 = 2). All four converter channels start with lock mode 0.
 * Code facts that fix the source: callee prototypes from the call sites (FUN_a015202c and FUN_a01410a4 /
 * a0110fb4 / a010b610 / a014f6f4 get no arguments; FUN_a010afe4 / a010b1b4 get only %o0); the OutCfg local and
 * the zero byte live in inner blocks (fw frame order: record copies at -40..-88, OutCfg at -128, its copy at
 * -168, the byte at -169); the row word0 is a union of the word (mask tests) and bit-fields (the print uses the
 * 3-bit field: with a mask/shift there gcse moves the word load into every switch arm); "if (x == K) A; else B;"
 * test forms (fw subx/addx constants); settings copies in the order h10, h12, he; switch arms in source order
 * 0x10, 0x11, 0x20, 0x21, 0x24, 0x40, 0x41, 0x22/0x42 (register names, hill-climb), mode = 0 before the switch.
 * volatile: none. Aids: none.
 */
struct OutCfg { unsigned char b0, b1, b2, b3; unsigned int w4, w8; unsigned char bc, bd; unsigned short he;
                unsigned short h10, h12; unsigned char b14, b15, b16, b17; unsigned int w18, w1c, w20; };
struct PortCfg { unsigned int a, b; unsigned char c, d; };
struct Row {
  union { unsigned int w0; struct { unsigned int r23 : 9, f20 : 3, f17 : 3, r0 : 17; } f; } u;
  unsigned short h4;
  unsigned char b6, b7;
};
struct RamRow { unsigned char p00[0x52]; unsigned short h52; };
struct __attribute__((packed, aligned(4))) Sel {
  unsigned char b00;
  unsigned short h01 : 16, h03 : 16, h05 : 16;
  unsigned char b07;
};
struct E116 { unsigned char p00[0x10]; unsigned char b10; unsigned char p11[0x11]; unsigned char b22; };
extern struct RamRow DAT_a802e378;
extern struct Sel DAT_a802e1a0;
extern struct E116 DAT_a802e116;
extern unsigned short DAT_a802e214;
extern unsigned char DAT_a802e3d3;
extern const char s_001a7528[], s_001a7518[], s_001a74f0[], s_001a7540[];
extern struct Row *FUN_a01241fc(void);
extern int FUN_a00df170();
extern void FUN_a011d748(unsigned char, unsigned char, unsigned short, int);
extern void FUN_a011e220(unsigned char, int);
extern void FUN_a010031c(unsigned char, unsigned char);
extern unsigned char FUN_a0125124(unsigned char);
extern void FUN_a014f6f4(void);
extern void FUN_a0124eec(void);
extern void FUN_a0150da4(void);
extern void FUN_a012f12c(void);
extern void FUN_a00f87dc(void);
extern void FUN_a01207f4(unsigned char, struct PortCfg);
extern void FUN_a01218c8(void);
extern void FUN_a01141fc(void);
extern void FUN_a0105150(struct OutCfg);
extern void FUN_a01111e4(unsigned char *);
extern void FUN_a01410a4(void);
extern void FUN_a01423dc(void);
extern void FUN_a0129b44(void);
extern void FUN_a00fc200(unsigned char);
extern void FUN_a00fc30c(unsigned int);
extern void FUN_a0125c84(void);
extern void FUN_a0139a30(void);
extern void FUN_a0139c3c(void);
extern void FUN_a0139b90(void);
extern void FUN_a013a8d4(unsigned int, unsigned char);
extern void FUN_a0110fb4(void);
extern void FUN_a015202c(void);
extern void FUN_a0107e44(unsigned char, unsigned short, unsigned char);
extern void FUN_a0109bbc(unsigned char, unsigned char, unsigned short, unsigned short);
extern void FUN_a01085f8(int, unsigned char, unsigned char);
extern void FUN_a010b610(void);
extern void func_0x4008a880(int, int, void (*)(void));
extern void func_0x4008c11c(int, int);
extern void func_0x40089820(int, int);
extern void FUN_a002fa34(void);
extern void FUN_a002fae0(void);
extern void FUN_a0138e28(unsigned short);
extern void FUN_a010afe4(unsigned char *);
extern void FUN_a010b1b4(unsigned char *);
extern void FUN_a01382b0(void);
extern unsigned char FUN_a00dd614(unsigned int);

void FUN_a015209c(void)
{
  struct Row *row0, *row;
  struct PortCfg pc;

  row0 = FUN_a01241fc();
  FUN_a00df170(s_001a7528);
  FUN_a011d748(7, 0xd, 0x3c0, 0);
  FUN_a011e220(7, 1);
  FUN_a011d748(7, 0xff, 0x9c40, 0);
  FUN_a011e220(7, 0);
  FUN_a011d748(7, 0xb, 0x7530, 0);
  FUN_a011d748(7, 0xc, 0x7530, 0);
  FUN_a011d748(7, 0xe, 0x7530, 0);
  FUN_a011d748(0xff, 0x18, 0x3c0, 0);
  FUN_a011d748(0xff, 0xff, 0x3c0, 0);
  FUN_a011d748(0xff, 0xff, 0x3c0, 0);
  FUN_a011d748(0xff, 0xff, 0x3c0, 0);
  FUN_a010031c(0, 7);
  FUN_a010031c(1, 7);
  FUN_a010031c(2, FUN_a0125124(DAT_a802e116.b10));
  FUN_a010031c(3, FUN_a0125124(DAT_a802e116.b22));
  FUN_a014f6f4();
  FUN_a0124eec();
  FUN_a0150da4();
  FUN_a012f12c();
  FUN_a00f87dc();

  pc.a = 2;
  pc.b = 1;
  pc.c = 1;
  pc.d = 1;
  FUN_a01207f4(0, pc);
  FUN_a01207f4(1, pc);
  FUN_a01207f4(2, pc);
  FUN_a01207f4(3, pc);
  FUN_a01218c8();
  FUN_a01141fc();

  {
  struct OutCfg cfg;
  unsigned int mode;

  row = FUN_a01241fc();
  cfg.b2 = 0;
  FUN_a00df170(s_001a7518);
  cfg.h10 = DAT_a802e1a0.h03;
  cfg.h12 = DAT_a802e1a0.h05;
  cfg.he = DAT_a802e1a0.h01;
  if (cfg.h10 != 0) {
    cfg.b0 = 1;
    cfg.b1 = 1;
  } else if (cfg.he != 0) {
    cfg.b0 = 1;
    cfg.b1 = 0;
  } else {
    cfg.b0 = 0;
  }
  switch (row->b7) {
  case 8:
    if ((row->u.w0 & 0x700000) == 0x200000)
      cfg.w4 = 3;
    else
      cfg.w4 = 0;
    break;
  case 10:
    cfg.w4 = 2;
    break;
  }

  row = FUN_a01241fc();
  mode = 0;
  switch (row->b6) {
  case 0x10:
    mode = 1;
    break;
  case 0x11:
    if ((row->u.w0 & 0xe0000) == 0x20000) mode = 3;
    else mode = 4;
    break;
  case 0x20:
    mode = 5;
    break;
  case 0x21:
    if ((row->u.w0 & 0xe0000) == 0) mode = 0x11;
    else mode = 8;
    break;
  case 0x24:
    mode = 0xe;
    break;
  case 0x40:
    if ((row->u.w0 & 0xe0000) == 0) mode = 6;
    else mode = 5;
    break;
  case 0x41:
    if ((row->u.w0 & 0xe0000) == 0x40000) mode = 0xa;
    else if ((row->u.w0 & 0xe0000) == 0) mode = 9;
    else mode = 8;
    break;
  case 0x22:
  case 0x42:
    if ((row->u.w0 & 0xe0000) == 0x40000) mode = 0xd;
    else if ((row->u.w0 & 0xe0000) == 0) mode = 0xc;
    else mode = 0xb;
    break;
  }
  FUN_a00df170(s_001a74f0, row->b6, row->u.f.f17, mode);
  cfg.w8 = mode;
  cfg.bc = 0x80;
  cfg.bd = 0;
  cfg.b14 = 0;
  FUN_a0105150(cfg);
  if ((row0->u.w0 & 0x700000) == 0) {
    unsigned char t = 0;
    FUN_a01111e4(&t);
  }
  }
  FUN_a01410a4();
  FUN_a01423dc();
  FUN_a0129b44();
  FUN_a00fc200(0);
  FUN_a00fc30c(0xd3ea4);
  FUN_a0125c84();
  FUN_a0139a30();
  FUN_a0139c3c();
  FUN_a0139b90();
  FUN_a013a8d4(0x400, 0x16);
  FUN_a0110fb4();
  FUN_a015202c();
  FUN_a0107e44(DAT_a802e3d3 != 0, DAT_a802e378.h52, 1);
  FUN_a0109bbc(0, 0, 0, DAT_a802e378.h52);
  FUN_a01085f8(0, 0, 0);
  FUN_a01085f8(1, 0, 0);
  FUN_a01085f8(2, 0, 0);
  FUN_a01085f8(3, 0, 0);
  FUN_a010b610();
  func_0x4008a880(1, 1, FUN_a002fa34);
  func_0x4008c11c(4, 0x99);
  func_0x40089820(1, 1);
  FUN_a0138e28(DAT_a802e214);
  func_0x4008a880(1, 2, FUN_a002fae0);
  func_0x40089820(1, 2);
  FUN_a010afe4(0);
  FUN_a010b1b4(0);
  FUN_a01382b0();
  if (FUN_a00dd614(0x10))
    FUN_a00df170(s_001a7540);
}
