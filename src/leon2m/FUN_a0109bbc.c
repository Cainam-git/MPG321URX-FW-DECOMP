/* leon2m FUN_a0109bbc @ 0xa0109bbc  FRC lock / free-run set-up
 * Flags: -mcpu=v8 -O3 -g -msoft-float, see the CONSTANTS note at the end of this header.
 *
 * void FUN_a0109bbc(lock, unused, p3, vfreq): vfreq = input refresh in tenths of Hz; the second parameter is never
 * read.
 * Callers: FUN_a013dc6c "FRC Lock" (1, 0xA802E3D0+0x38 == 3, a 16-bit local, input record 0xA802DF30 +8), "FRC Free
 *   Run" (0, 0, 0, 0xA802E3CA); FUN_a0148500 (0, 0, ?, raw row +0x52); FUN_a01518c8, FUN_a015209c.
 * lock == 0 (free run): prints "FRC freerun mode\r\n"; 0xCF011C04 = 0x60; 16-bit register pairs 0xCF011C38 and
 *   0xCF011C48 (FUN_a00f308c: low byte at a, high byte at a+4) = transformed row +0x2C (each re-read through
 *   DAT_a802d6a4); then with v = FUN_a011cf88():
 *     v > 0x82 and 0xCF011E40 bit 3: clear bits 1-2 of 0xCF011E40, 0xCF011AE8 = DAT_a802d702 >> 1
 *     else v > 0x83 and bit 2:       clear bits 1 and 3,         0xCF011AE8 = DAT_a802d702 >> 2
 *     else v > 0x83 and bit 1:       clear bits 2-3,             0xCF011AE8 = DAT_a802d702 >> 3
 *     else                                                        0xCF011AE8 = DAT_a802d702
 *   (0xA802D702 is the vertical value FRCConfigPostFRC FUN_a0107e44 stores); then clears bit 6 of 0xCF011EC0.
 * lock != 0: func_0x4008e2a4() (= FUN_a002e2a4); 0xCF011C38 pair = 0x3FFF; then single-precision soft float:
 *   in_lines  = (float)clock(0) * 1e6 / reg(0, 0x82) * 10 / vfreq   (clock = FUN_a0102fd0 MHz, reg = FUN_a00f25f8)
 *   0xCF011A80 bit 7 clear:
 *     out_lines = (float)clock(4) * 1e6 / pair(0xCF011C20) * 10 / vfreq     (pair = FUN_a00f3078)
 *     d = (float)reg(0, 0x64) / in_lines - (float)p3 / out_lines
 *     off = d > 0 ? min((u16)(in_lines * d + 5), in_lines - 5) : 5
 *   bit 7 set:
 *     out_lines = (float)clock(4) * 1e6 / (u16)(pair(0xCF011AC0) + pair(AC8) + pair(AD0) + pair(AD8)) * 10 / vfreq
 *     d = (float)(reg(0, 0x62) + reg(0, 0x64)) / in_lines - (float)p3 / out_lines
 *     off = d > 0 ? min((u16)(in_lines * d + 16), in_lines - 16) : 16
 *     if transformed row +0x0A > reg(0, 0x64): off = reg(0, 0x64) / 2, prints "%x,%x\r\n" (reg64, off)
 *   prints "lock mode %x,%x,%x,%x\r\n" (reg64, in_lines, out_lines, off); 0xCF011C48 pair = off;
 *   0xCF011C04 = 0xA0; 0xCF011AE8 pair = 0xFFFF; 0xCF011EC4 = off & 0xFF; 0xCF011EC0 = ((off >> 8) & 0x3F) | 0x40.
 * ROW FIELDS READ: transformed row *DAT_a802d6a4 only: +0x2C (free run, written to 0xCF011C38 and
 *   0xCF011C48 unchanged) and +0x0A (lock with 0xCF011A80 bit 7 set: compared with reg(0,0x64), caps the lock
 *   offset). +0x0A is read at entry on every path (used only there). No raw-row or row-index reads.
 * The input rate enters only the float arithmetic (in_lines / out_lines); no reject path here.
 * Source form: the free-run chain has a separate FUN_a00f308c(0xCF011AE8, ...) call in every branch (gcc
 *   cross-jumps them; the call heuristic puts the three bodies out of line); the four 0xCF011ACx reads go into
 *   unsigned short locals; explicit (float) casts on unsigned short values (clock(), reg64, p3) give gcc's
 *   signed-convert + 65536.0 fix-up, while the divisors are promoted to int (zero-extend, no fix-up);
 *   'reg64 < h0a' (not 'h0a > reg64') gives the bgu.
 * CONSTANTS: 1e6, 0.0, 5.0, 16.0 (0x19ACCC..ACD8, in this order) and 10.0 (0x198760) / 65536.0 (0x19A2D0) are the
 * literal-pool entries of this file after the linker merged .rodata.cst4 across the program (10.0 and 65536.0
 * already existed). The build places .rodata.cst4 as one block, so this file's own pool is not placed at those
 * addresses; the same code with the five constants named by their firmware addresses links with only 65536.0 left in
 * .rodata.cst4 at 0x19A2D0, and its .text and relocations equal this file's entry for entry. __gtsf2 = FUN_a0155b78.
 */
struct PanelParam
{
  unsigned int w0;
  unsigned short h4;
  unsigned char b6;
  unsigned char b7;
  unsigned short h08;
  unsigned short h0a;
  unsigned char b0c[4];
  unsigned long long clk_min;
  unsigned long long clk_max;
  unsigned short h20;
  unsigned short h22;
  unsigned short h24;
  unsigned short h26;
  unsigned short h28;
  unsigned short h2a;
  unsigned short h2c;
};
#define REG_cf011a80 (*(volatile unsigned int *)0xcf011a80)
#define REG_cf011c04 (*(volatile unsigned int *)0xcf011c04)
#define REG_cf011e40 (*(volatile unsigned int *)0xcf011e40)
#define REG_cf011ec0 (*(volatile unsigned int *)0xcf011ec0)
#define REG_cf011ec4 (*(volatile unsigned int *)0xcf011ec4)
extern struct PanelParam *DAT_a802d6a4;
extern unsigned short DAT_a802d702;
extern int FUN_a00df170();
extern char s_0019ac58[], s_0019ac70[], s_001a7018[];
extern void func_0x4008e2a4(void);
extern void FUN_a00f308c(unsigned int, unsigned int);
extern int FUN_a00f3078(int);
extern unsigned short FUN_a00f25f8(unsigned char, unsigned char);
extern unsigned short FUN_a0102fd0(unsigned char);
extern unsigned char FUN_a011cf88(void);

void FUN_a0109bbc(unsigned char lock, unsigned char unused, unsigned short p3, unsigned short vfreq)
{
  unsigned short h0a = DAT_a802d6a4->h0a;
  unsigned short in_lines, out_lines, v62, v64, htot, off;
  float d;
  unsigned short r0, r1, r2, r3;

  if (lock != 0) {
    func_0x4008e2a4();
    FUN_a00f308c(0xcf011c38, 0x3fff);
    if ((REG_cf011a80 & 0x80) == 0) {
      in_lines = (float)FUN_a0102fd0(0) * 1000000.0f / FUN_a00f25f8(0, 0x82) * 10.0f / vfreq;
      v64 = FUN_a00f25f8(0, 0x64);
      htot = FUN_a00f3078(0xcf011c20);
      out_lines = (float)FUN_a0102fd0(4) * 1000000.0f / htot * 10.0f / vfreq;
      d = (float)v64 / in_lines - (float)p3 / out_lines;
      if (d > 0.0f) {
        off = in_lines * d + 5.0f;
        if (off > in_lines - 5) off = in_lines - 5;
      } else {
        off = 5;
      }
    } else {
      in_lines = (float)FUN_a0102fd0(0) * 1000000.0f / FUN_a00f25f8(0, 0x82) * 10.0f / vfreq;
      v62 = FUN_a00f25f8(0, 0x62);
      v64 = FUN_a00f25f8(0, 0x64);
      r0 = FUN_a00f3078(0xcf011ac0);
      r1 = FUN_a00f3078(0xcf011ac8);
      r2 = FUN_a00f3078(0xcf011ad0);
      r3 = FUN_a00f3078(0xcf011ad8);
      htot = r0 + r1 + r2 + r3;
      out_lines = (float)FUN_a0102fd0(4) * 1000000.0f / htot * 10.0f / vfreq;
      d = (float)(v62 + v64) / in_lines - (float)p3 / out_lines;
      if (d > 0.0f) {
        off = in_lines * d + 16.0f;
        if (off > in_lines - 16) off = in_lines - 16;
      } else {
        off = 16;
      }
      if (v64 < h0a) {
        off = v64 >> 1;
        FUN_a00df170(s_001a7018, v64, off);
      }
    }
    FUN_a00df170(s_0019ac70, v64, in_lines, out_lines, off);
    FUN_a00f308c(0xcf011c48, off);
    REG_cf011c04 = 0xa0;
    FUN_a00f308c(0xcf011ae8, 0xffff);
    REG_cf011ec4 = off & 0xff;
    REG_cf011ec0 = (off >> 8) & 0x3f | 0x40;
  } else {
    FUN_a00df170(s_0019ac58);
    REG_cf011c04 = 0x60;
    FUN_a00f308c(0xcf011c38, DAT_a802d6a4->h2c);
    FUN_a00f308c(0xcf011c48, DAT_a802d6a4->h2c);
    if (FUN_a011cf88() > 0x82 && (REG_cf011e40 & 8)) {
      REG_cf011e40 &= ~6;
      FUN_a00f308c(0xcf011ae8, DAT_a802d702 >> 1);
    } else if (FUN_a011cf88() > 0x83 && (REG_cf011e40 & 4)) {
      REG_cf011e40 &= ~10;
      FUN_a00f308c(0xcf011ae8, DAT_a802d702 >> 2);
    } else if (FUN_a011cf88() > 0x83 && (REG_cf011e40 & 2)) {
      REG_cf011e40 &= ~12;
      FUN_a00f308c(0xcf011ae8, DAT_a802d702 >> 3);
    } else {
      FUN_a00f308c(0xcf011ae8, DAT_a802d702);
    }
    REG_cf011ec0 &= ~0x40;
  }
}
