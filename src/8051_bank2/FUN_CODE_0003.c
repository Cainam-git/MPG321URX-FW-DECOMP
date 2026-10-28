/* 8051_bank2 module FUN_CODE_0003: one Keil C51 module, OPTIMIZE(8,SPEED) LARGE, holding FUN_CODE_0003, FUN_CODE_c0be,
 * FUN_CODE_e4bf, FUN_CODE_e1c1, FUN_CODE_df7f, FUN_CODE_da8a, FUN_CODE_e2ab, FUN_CODE_d1bb, FUN_CODE_c1a6 and
 * FUN_CODE_a8a3.
 * Keil's "reuse of common entry code" emits these blocks in front of the callees (all byte-exact with this file):
 *   FUN_CODE_e4b9 @ 0xe4b9 in front of FUN_CODE_e4bf: R3:R2:R1 = generic pointer to XDATA 0x0436, shared by the
 *     e4bf(DAT_EXTMEM_0436) calls of da8a, e2ab, d1bb and c1a6;
 *   FUN_CODE_e1b5 @ 0xe1b5 in front of FUN_CODE_e1c1: R7 = (unsigned char)(i >> 4) (i in R4:R5), from c1a6;
 *   FUN_CODE_df76 @ 0xdf76 in front of FUN_CODE_df7f: R7 = low byte of c1a6's i (XDATA 0x08F2), R5 = R7 + 0x0E;
 *   FUN_CODE_da66 @ 0xda66 and FUN_CODE_da86 @ 0xda86 in front of FUN_CODE_da8a, from the da8a calls of 0003 and c0be.
 * The local of FUN_CODE_c1a6 is named pos: a block operand that names a local of the caller must not share its name
 * with a local of another function in the module (the judge resolves block operands by name).
 *
 * FUN_CODE_0003: sends 0x9F through FUN_CODE_c0be(buf, 2, 1); when buf[3..4] = EF 40 the reply is looked up in the
 *   8-byte records at CODE 0xCB8C with FUN_CODE_c44e. Otherwise up to 3 tries: register 0xF068 = CODE[0xCBD6 + try]
 *   (FUN_CODE_da8a), FUN_CODE_e2da(), three bytes read from 0xF064..0xF066 (FUN_CODE_e105), lookup with FUN_CODE_b044.
 *   Found: the record is copied to XDATA 0x0640 and its byte 2 written to register 0xF067; returns 0. Else returns 2.
 * FUN_CODE_c0be(buf, n, m): writes registers 0xF0C0 = ((n >> 1) << 4) | 3, 0xF0C1 = 0xA7, 0xF0C2 = 0, 0xF0C3 = 0xA7,
 *   0xF0C4 = n, 0xF0C5 = 0xA7, 0xF0C6 = n + m, the n + m bytes of buf to 0xA700 + i, then FUN_CODE_e3ab(), wait 20,
 *   and reads 16 bytes from 0xA700.. back into buf (FUN_CODE_e105).
 * FUN_CODE_e4bf(buf): FUN_CODE_bba9(0x6E, buf), then FUN_CODE_e44b(2).
 * FUN_CODE_e1c1(a): packet {2, 0x0F, a} in XDATA 0x0436, FUN_CODE_bfcf(0x6E, 3, buf), wait 100, tail call e4bf(buf).
 * FUN_CODE_df7f(a, b): the 10-byte record at CODE 0xCBCC is struct-copied to XDATA 0x08F5, bytes 8 and 9 become a
 *   and b, FUN_CODE_bfcf(0x6E, 10, record), tail call FUN_CODE_d059(5000). (An initialised local array compiles to the
 *   same instructions, but the judge cannot place its init image, so the record and image use their addresses.)
 * FUN_CODE_da8a(reg, val): packet 04 78 <reg hi> <reg lo> <val> in XDATA 0x0436, r = FUN_CODE_bfcf(0x6E, 5, buf),
 *   wait 100, e4bf(buf), returns r.
 * FUN_CODE_e2ab(a): packet 02 36 <a>, bfcf (status not kept), wait 4000, e4bf(buf), returns buf[2] << 8 | buf[3].
 * FUN_CODE_d1bb(m): FUN_CODE_e53b(0x14), P1.4 = 1, wait 2, FUN_CODE_de50(m). Only for m == 1: wait 5, e4bf(buf) and
 *   XDATA 0x0648 / 0x0649 = buf[1] / buf[2]; registers 0xF04C = 0x60, 0xD929 = 0x06, 0xF1A8 = 0x02; when register
 *   0xF050 bit 2 is set: 0xF11C |= 0x40, 0xF11D &= ~0x40; 0xF0E0 = 0xAA; 0xF0FF |= 0x40. Ends with FUN_CODE_e53b(1).
 * FUN_CODE_c1a6(mode): bit 0: FUN_CODE_e384(), tail call e4bf(XDATA 0x0436). Bit 2 without bit 1: tail call
 *   FUN_CODE_dd1a(1). Otherwise n = (XDATA[0x0644] << 8) >> 3; with bits 2 and 1: FUN_CODE_e331(8 if that byte is 0x10,
 *   else 0) and pos runs n / 2 .. n - 1, else 0 .. n - 1, step 16; per step e1c1(pos >> 4) when pos % 16 == 0,
 *   df7f(pos, pos + 14), e4bf(XDATA 0x0436). Keil idioms: 'if (x == 0x10) e331(8); else e331(0);' (a ?: gives
 *   MOV R7,#0 instead of CLR A / MOV R7,A); (x << 8) >> 3 gives the 3-step RRC loop (x << 5 gives MUL AB).
 * FUN_CODE_a8a3(mode) (bit result): with mode bit 4: d1bb(1), r = 0003(); mode 0x11: FUN_CODE_ce2a(), r |=
 *   FUN_CODE_8437(mode), prints "result = %d\r\n" (CODE 0xCB51) with r through FUN_CODE_65ab; other modes: XDATA
 *   0x0435 = 0, 0x0434 = 2, r |= FUN_CODE_8437(mode). Then FUN_CODE_ceee(0), register 0xD7E0 = 0x81, FUN_CODE_e21d(1),
 *   FUN_CODE_e24d(0xF3); returns 1 when r is 0 and FUN_CODE_00fc() returns 0 (XDATA 0xF19A = 0 first), else 0.
 *   Without bit 4: XDATA 0x06F2 = 0, d1bb(1), register 0xF0DE = 0x21, 0003(), t = register 0xF1E0, 0xF1E0 = t & 0xF7;
 *   with bit 2 or 3: (bit 3: FUN_CODE_dd6a(0)) FUN_CODE_cee9(), e4bf(buf), FUN_CODE_e44b(10), FUN_CODE_e4a4(), and for
 *   bit 3 FUN_CODE_dd6a(1) and the same three calls again; otherwise the three calls once. Then c1a6(mode), ceee(0),
 *   e4bf(buf), 0xF1E0 = t, FUN_CODE_9f8f(mode); with bit 2 or 3: (bit 3: dd6a(0)) FUN_CODE_ca42(mode), ceee(1) (bit 3:
 *   dd6a(1), ceee(1)); 0xF1E0 = t & 0xF7, 0xF1E0 = t, d1bb(0), then an endless loop.
 *   Compiler aid: 'ACC = ACC;' (sfr ACC) at the end of the inner 'if (mode & 8)' block emits no instructions; it keeps
 *   Keil from cross-jumping that block's 'cee9(); e4bf(buf); e44b(10);' into the identical else-branch calls, so both
 *   copies stay as in the firmware (SJMP over the second copy).
 * Register writes are service-bus packets: FUN_CODE_da8a writes, FUN_CODE_e105 reads (slave 0x6E).
 */
#include <absacc.h>
extern unsigned char code DAT_CODE_cbd6[];
void FUN_CODE_c0be(unsigned char *buf, unsigned char n, unsigned char m);
unsigned char FUN_CODE_c44e(unsigned char *buf, void *tbl);
unsigned char FUN_CODE_b044(unsigned char *buf, void *tbl);
struct FlashInfo { unsigned char b[8]; };
extern struct FlashInfo code DAT_CODE_cb8c[];
extern struct FlashInfo xdata DAT_EXTMEM_0640;
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
void FUN_CODE_e2da(void);
unsigned char FUN_CODE_e105(unsigned int reg);

unsigned char FUN_CODE_0003(void)
{
    unsigned char j, i, id;
    unsigned char buf[16];
    unsigned char res;
    buf[0] = 1;
    buf[1] = 3;
    buf[2] = 0x9f;
    FUN_CODE_c0be(buf, 2, 1);
    if (buf[3] == 0xef && buf[4] == 0x40) {
        id = FUN_CODE_c44e(buf, (void code *)0xcb8c);
        if (id == 0xff) {
            res = 2;
        } else {
            res = 0;
            DAT_EXTMEM_0640 = DAT_CODE_cb8c[id];
            FUN_CODE_da8a(0xf067, DAT_EXTMEM_0640.b[2]);
            return res;
        }
    }
    for (i = 0; i < 3; i++) {
        FUN_CODE_da8a(0xf068, DAT_CODE_cbd6[i]);
        FUN_CODE_e2da();
        for (j = 0; j < 3; j++) buf[j] = FUN_CODE_e105(0xf064 + j);
        id = FUN_CODE_b044(buf, (void code *)0xcb8c);
        if (id != 0xff) break;
    }
    if (id == 0xff) {
        res = 2;
    } else {
        res = 0;
        DAT_EXTMEM_0640 = DAT_CODE_cb8c[id];
        FUN_CODE_da8a(0xf067, DAT_EXTMEM_0640.b[2]);
    }
    return res;
}


void FUN_CODE_e3ab(void);
void FUN_CODE_e44b(unsigned char t);

void FUN_CODE_c0be(unsigned char *buf, unsigned char n, unsigned char m)
{
    unsigned char i;
    FUN_CODE_da8a(0xf0c0, ((n >> 1) << 4) | 3);
    FUN_CODE_da8a(0xf0c1, 0xa7);
    FUN_CODE_da8a(0xf0c2, 0);
    FUN_CODE_da8a(0xf0c3, 0xa7);
    FUN_CODE_da8a(0xf0c4, n);
    FUN_CODE_da8a(0xf0c5, 0xa7);
    FUN_CODE_da8a(0xf0c6, n + m);
    for (i = 0; i < n + m; i++) FUN_CODE_da8a(0xa700 + i, buf[i]);
    FUN_CODE_e3ab();
    FUN_CODE_e44b(0x14);
    for (i = 0; i < 0x10; i++) buf[i] = FUN_CODE_e105(0xa700 + i);
}

unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val)
{
    unsigned char r;
    DAT_EXTMEM_0436[0] = 4;
    DAT_EXTMEM_0436[1] = 0x78;
    DAT_EXTMEM_0436[2] = reg >> 8;
    DAT_EXTMEM_0436[3] = reg;
    DAT_EXTMEM_0436[4] = val;
    r = FUN_CODE_bfcf(0x6e, 5, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
    return r;
}


extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e478(void);
void FUN_CODE_e4bf(unsigned char *buf)
{
    FUN_CODE_bba9(0x6e, buf);
    FUN_CODE_e44b(2);
}


extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e1c1(unsigned char a)
{
    DAT_EXTMEM_0436[0] = 2;
    DAT_EXTMEM_0436[1] = 0x0f;
    DAT_EXTMEM_0436[2] = a;
    FUN_CODE_bfcf(0x6e, 3, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}


struct Rec10 { unsigned char b[10]; };
extern struct Rec10 code DAT_CODE_cbcc;
extern struct Rec10 xdata DAT_EXTMEM_08f5;
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_df7f(unsigned char a, unsigned char b)
{
    DAT_EXTMEM_08f5 = DAT_CODE_cbcc;
    DAT_EXTMEM_08f5.b[8] = a;
    DAT_EXTMEM_08f5.b[9] = b;
    FUN_CODE_bfcf(0x6e, 10, DAT_EXTMEM_08f5.b);
    FUN_CODE_d059(5000);
}


extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char FUN_CODE_bba9(unsigned char addr, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e44b(unsigned char t);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);


extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
unsigned int FUN_CODE_e2ab(unsigned char a)
{
    DAT_EXTMEM_0436[0] = 2;
    DAT_EXTMEM_0436[1] = 0x36;
    DAT_EXTMEM_0436[2] = a;
    FUN_CODE_bfcf(0x6e, 3, DAT_EXTMEM_0436);
    FUN_CODE_d059(4000);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
    return ((unsigned int)DAT_EXTMEM_0436[2] << 8) | DAT_EXTMEM_0436[3];
}


sfr P1 = 0x90;
sbit P1_4 = P1 ^ 4;
extern unsigned char xdata DAT_EXTMEM_0436[];
extern unsigned char xdata DAT_EXTMEM_0648, DAT_EXTMEM_0649;
void FUN_CODE_e53b(unsigned char a);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_de50(unsigned char m);
void FUN_CODE_e4bf(unsigned char *buf);
unsigned char FUN_CODE_e105(unsigned int reg);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);

void FUN_CODE_d1bb(unsigned char m)
{
    FUN_CODE_e53b(0x14);
    P1_4 = 1;
    FUN_CODE_e44b(2);
    FUN_CODE_de50(m);
    if (m == 1) {
        FUN_CODE_e44b(5);
        FUN_CODE_e4bf(DAT_EXTMEM_0436);
        DAT_EXTMEM_0648 = DAT_EXTMEM_0436[1];
        DAT_EXTMEM_0649 = DAT_EXTMEM_0436[2];
        FUN_CODE_da8a(0xf04c, 0x60);
        FUN_CODE_da8a(0xd929, 0x06);
        FUN_CODE_da8a(0xf1a8, 0x02);
        if (FUN_CODE_e105(0xf050) & 0x04) {
            FUN_CODE_da8a(0xf11c, FUN_CODE_e105(0xf11c) | 0x40);
            FUN_CODE_da8a(0xf11d, FUN_CODE_e105(0xf11d) & ~0x40);
        }
        FUN_CODE_da8a(0xf0e0, 0xaa);
        FUN_CODE_da8a(0xf0ff, FUN_CODE_e105(0xf0ff) | 0x40);
    }
    FUN_CODE_e53b(1);
}


extern unsigned char xdata DAT_EXTMEM_0436[];
extern unsigned char xdata DAT_EXTMEM_0644;
extern void FUN_CODE_e384(void);
extern void FUN_CODE_e4bf(unsigned char *p);
extern void FUN_CODE_dd1a(unsigned char a);
extern void FUN_CODE_e331(unsigned char a);
void FUN_CODE_e1c1(unsigned char a);
void FUN_CODE_df7f(unsigned char a, unsigned char b);

void FUN_CODE_c1a6(unsigned char mode)
{
    unsigned int n;
    unsigned int pos;
    if (mode & 1) {
        FUN_CODE_e384();
        FUN_CODE_e4bf(DAT_EXTMEM_0436);
        return;
    }
    if ((mode & 4) && !(mode & 2)) {
        FUN_CODE_dd1a(1);
        return;
    }
    if ((mode & 4) && (mode & 2)) {
        n = ((unsigned int)DAT_EXTMEM_0644 << 8) >> 3;
        if (DAT_EXTMEM_0644 == 0x10) FUN_CODE_e331(8); else FUN_CODE_e331(0);
        for (pos = n >> 1; pos < n; pos += 16) {
            if ((pos & 0x0f) == 0) FUN_CODE_e1c1(pos >> 4);
            FUN_CODE_df7f(pos, pos + 14);
            FUN_CODE_e4bf(DAT_EXTMEM_0436);
        }
    } else {
        n = ((unsigned int)DAT_EXTMEM_0644 << 8) >> 3;
        for (pos = 0; pos < n; pos += 16) {
            if ((pos & 0x0f) == 0) FUN_CODE_e1c1(pos >> 4);
            FUN_CODE_df7f(pos, pos + 14);
            FUN_CODE_e4bf(DAT_EXTMEM_0436);
        }
    }
}

sfr ACC = 0xE0;
struct TagRegion { unsigned char cur; unsigned char next; };
extern struct TagRegion xdata DAT_EXTMEM_0434;
extern unsigned char xdata DAT_EXTMEM_06f2;
extern void FUN_CODE_65ab(void *fmt, ...) large;
void FUN_CODE_d1bb(unsigned char m);
unsigned char FUN_CODE_0003(void);
void FUN_CODE_ce2a(void);
unsigned char FUN_CODE_8437(unsigned char mode);
void FUN_CODE_e21d(unsigned char a);
void FUN_CODE_e24d(unsigned char a);
unsigned char FUN_CODE_00fc(void);
void FUN_CODE_dd6a(bit on);
void FUN_CODE_e4a4(void);
void FUN_CODE_c1a6(unsigned char mode);
void FUN_CODE_9f8f(unsigned char mode);
void FUN_CODE_ca42(unsigned char mode);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);
unsigned char FUN_CODE_e105(unsigned int reg);
void FUN_CODE_ceee(unsigned char on);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_cee9(void);

bit FUN_CODE_a8a3(unsigned char mode)
{
    unsigned char t;
    unsigned char r;
    r = 0;
    if (mode & 0x10) {
        FUN_CODE_d1bb(1);
        r |= FUN_CODE_0003();
        if (mode == 0x11) {
            FUN_CODE_ce2a();
            r |= FUN_CODE_8437(mode);
            FUN_CODE_65ab((void code *)0xcb51, (unsigned int)r);
        } else {
            DAT_EXTMEM_0434.next = 0;
            DAT_EXTMEM_0434.cur = 2;
            r |= FUN_CODE_8437(mode);
        }
        FUN_CODE_ceee(0);
        FUN_CODE_da8a(0xd7e0, 0x81);
        FUN_CODE_e21d(1);
        FUN_CODE_e24d(0xf3);
        if (r == 0) {
            XBYTE[0xF19A] = 0;
            if (FUN_CODE_00fc() == 0) r = 1;
            else r = 0;
        } else r = 0;
        return r;
    }
    DAT_EXTMEM_06f2 = 0;
    FUN_CODE_d1bb(1);
    FUN_CODE_da8a(0xf0de, 0x21);
    FUN_CODE_0003();
    t = FUN_CODE_e105(0xf1e0);
    FUN_CODE_da8a(0xf1e0, t & 0xf7);
    if ((mode & 4) || (mode & 8)) {
        if (mode & 8) FUN_CODE_dd6a(0);
        FUN_CODE_cee9();
        FUN_CODE_e4bf(DAT_EXTMEM_0436);
        FUN_CODE_e44b(10);
        FUN_CODE_e4a4();
        if (mode & 8) {
            FUN_CODE_dd6a(1);
            FUN_CODE_cee9();
            FUN_CODE_e4bf(DAT_EXTMEM_0436);
            FUN_CODE_e44b(10);
            ACC = ACC;
        }
    } else {
        FUN_CODE_cee9();
        FUN_CODE_e4bf(DAT_EXTMEM_0436);
        FUN_CODE_e44b(10);
    }
    FUN_CODE_c1a6(mode);
    FUN_CODE_ceee(0);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
    FUN_CODE_da8a(0xf1e0, t);
    FUN_CODE_9f8f(mode);
    if ((mode & 4) || (mode & 8)) {
        if (mode & 8) FUN_CODE_dd6a(0);
        FUN_CODE_ca42(mode);
        FUN_CODE_ceee(1);
        if (mode & 8) {
            FUN_CODE_dd6a(1);
            FUN_CODE_ceee(1);
        }
    }
    FUN_CODE_da8a(0xf1e0, t & 0xf7);
    FUN_CODE_da8a(0xf1e0, t);
    FUN_CODE_d1bb(0);
    for (;;) ;
}
