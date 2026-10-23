/* 8051_bank2 module FUN_CODE_467e: the callers of the common-entry blocks in front of FUN_CODE_e373 and FUN_CODE_e1a4,
 * hand-written, one Keil C51 module compiled with OPTIMIZE(8,SPEED) LARGE.
 * It is one file because Keil OPTIMIZE(8) "reuse of common entry code" builds one block in front of a callee from the
 * call sites it sees in the same module; every function that enters one of these blocks is defined here:
 *   0xE35B..0xE373 -> e373 (users 5219, 69e5, 76b4, 8a0e, 94d3, d2fb, cbd9, cca2, d4b2)
 *   0xE17C..0xE1A4 -> e1a4 (users 5219, 69e5, 76b4, 8a0e, 94d3, b97a, 467e)
 *   0x9981..0x999F -> 999f (cbd9, cca2, d4b2)        0x9B8D -> 9b91 (69e5, d2fb, 467e)
 *   0xDAC1 -> dac5 (467e, 8f9b, b45f, b97a)           0xDDB7 -> ddbb (69e5, b97a)
 *   0xB308 -> b317 (467e)                             0x8A08 -> 8a0e (76b4)
 *   0x69C3..0x69E5 -> 69e5 (5219, 8a0e)               0x5200..0x5219 -> 5219 (ba96)
 *   0x8F95 -> 8f9b (467e)                             0x7677..0x76B4 -> 76b4 (467e, 9734)
 * A block holds the instructions that the call sites share in front of the LCALL, including the tail of the statement
 * before the call (the 76b4 block stores the request fields addr, n, id and st; the e35b entry stores the local
 * 0x0907 of 5219). LJMP (tail) call sites are never merged (c60e, b45f's last dac5 call, 94d3's last e1a4 call).
 * Definition order matters: for each callee Keil merges only the FIRST call site whose count argument differs from the
 * block's (A loaded before MOV DPTR,#098AH), so 69e5 is defined first (its first e373(b, 2) and e1a4(b, 2) enter at
 * 0xE36F / 0xE1A0); dac5 is defined after b45f (otherwise Keil knows R5 survives the first dac5 call and drops
 * b45f's second 'MOV R5,#2').
 *
 * Data (XDATA unless noted):
 *   0x08BC struct Dev: td = DATA pointer to a 32-byte descriptor (struct TD: two link words, the 16-bit word tok at +8,
 *     bytes b10 / b11, five buffer words at +12..+31), a 0x08BD, b 0x08C1, c 0x08C5, d 0x08C9 (controller addresses).
 *   0x0829 = DATA pointer to a 28-byte descriptor (struct QH, fields named by offset).
 *   DATA 0x0022 = 32-byte word buffer: e373(addr, n) reads n * 32 bytes at addr into it (abce), e1a4(addr, n) writes
 *     it back (b1a9); 999f swaps the bytes of each 32-bit word between two buffers.
 *   0x075C struct Req (request record read by 76b4): id, st, cblen, dir, cb[16], len, addr, n.
 *   0x082A struct CBW (0x2E bytes): 76b4 sets sig = 0x55534243, len, tag, flags, lun, cblen, cb[] and copies it with
 *     999f into DATA 0x0022; ep_in 0x0856 / ep_out 0x0857.
 *   0x07D9 struct pkt[10]: 8-byte records passed to 5219 (byte [1] selects the switch case, [6] is the length).
 *   Registers 0x10 / 0x14 / 0x1C / 0x24 / 0x28 / 0x30 / 0x80 through 9b91 (read) and b317 (write); the firmware
 *   prints register 0x14 as "USBSTS %08lX\n" (0xC99C).
 * Functions (all byte-exact in this file):
 *   e373 / e1a4: read / write n records at addr. 999f: word byte swap. 9b91 / b317: 32-bit register read / write.
 *   ddbb: register bits clear. dac5: fill n * 32 bytes of DATA 0x0022. cbd9 / cca2 / d4b2: read records in a loop.
 *   d2fb: reads 8 bytes into its local record r and returns it. 94d3 / 8a0e / 69e5 / 5219 / b45f / b97a / 8f9b / 467e:
 *   descriptor set-up and transfer sequences (69e5 prints "HC SendPort TERM %BX, temp_addr_02 %08X\n" 0xC973 and
 *   "D_GET(STATUS,pd) [%08lX]\n" 0xC9AA). 76b4: builds the 0x082A record from 0x075C and runs the three stages.
 *   ba96: retry loop over 5219 / 467e / 35a9. 9734 / c60e: fill 0x075C (cb[0] = 0x2A / 0x28) and call 76b4.
 * Source forms the bytes depend on (each checked against the alternatives):
 *   - Masked field updates are written 'x = x & keep | v & mask' with the operand Keil must evaluate first on the
 *     side the firmware evaluates first; '(v << 0) & mask' (a field written with shift 0, 8a0e off and b45f v) makes
 *     Keil evaluate it before the descriptor load as the firmware does.
 *   - '(x | 0x80) % 0x100' / '(x & 0x7f) % 0x100' on b11 (94d3, 69e5): the '% 0x100' emits no code; it keeps Keil from
 *     commuting the constant operand (MOV A,@R0 / ORL A,#80H as in the firmware instead of MOV A,#80H / ORL A,@R0).
 *   - Length into tok (8a0e w, 5219 n0..n2): computed into its own unsigned int local before the update, one local
 *     per switch arm (a local shared by two arms is given an XDATA home by Keil).
 *   - '(unsigned int)(b - 1)' and '(unsigned int)a * 2UL' (?C?LIMUL) for the record offsets; d2fb's n is a local set
 *     to 1 (Keil keeps it in R7 and folds the load: MOV A,#1 / ADD A,#0FFH).
 *   - 76b4 tests 'len > avail' twice (the firmware compares again inside the loop).
 *   - ba96 leaves its loop with break (shared 'MOV R7,#0 / RET'); 467e returns r from every exit.
 *   - b97a sets its local p (0x0902) to DATA 0x0022 and never reads it (the firmware has the three stores).
 *   - Locals that a common-entry block reads have names unique in the module (tda, qha, tdb, qhb, tdc, qhc, cur, dst,
 *     nxt) so the judge resolves the block operands to the right function.
 * Judge keys this file needs in symbols/8051_bank2.libs.json besides the learned ones: ?FUN_CODE_d2fb?XD = 0x08EB (r is
 * only addressed with #LOW / #HIGH).
 */
struct TD { unsigned long next; unsigned long alt; unsigned int tok; unsigned char b10; unsigned char b11; unsigned long buf[5]; };
struct QH { unsigned long w0; unsigned int i4; unsigned char b6; unsigned char b7; unsigned char b8; unsigned char b9; unsigned char b10;
            unsigned char b11; unsigned long w12; unsigned long w16; unsigned long w20; unsigned char b24; unsigned char b25;
            unsigned char b26; unsigned char b27; };
struct Dev { struct TD idata *td; unsigned long a; unsigned long b; unsigned long c; unsigned long d; };
struct Req { unsigned long id; unsigned char st; unsigned char cblen; unsigned char dir; unsigned char cb[16]; unsigned long len;
             unsigned long addr; unsigned int n; };
struct CBW { unsigned long sig; unsigned long tag; unsigned long len; unsigned char flags; unsigned char lun; unsigned char cblen;
             unsigned char cb[16]; unsigned char pad[13]; unsigned char ep_in; unsigned char ep_out; };
struct pkt { unsigned char b[8]; };
struct pair { unsigned char a; unsigned char b; };
struct cap { unsigned char b[8]; };
extern struct Dev xdata DAT_EXTMEM_08bc;
extern struct QH idata * xdata DAT_EXTMEM_0829;
extern struct Req xdata DAT_EXTMEM_075c;
extern struct CBW xdata DAT_EXTMEM_082a;
extern struct pkt xdata DAT_EXTMEM_07d9[10];
extern unsigned char data DAT_0022[];
extern unsigned long xdata DAT_EXTMEM_07d5;
extern unsigned long xdata DAT_EXTMEM_0717;
extern unsigned long xdata DAT_EXTMEM_08b4;
extern unsigned long xdata DAT_EXTMEM_08de;
extern unsigned char xdata DAT_EXTMEM_071b;
extern unsigned char xdata DAT_EXTMEM_075b;
extern unsigned char xdata DAT_EXTMEM_07d1[2];
extern unsigned char xdata DAT_EXTMEM_07d3[];
extern unsigned int xdata DAT_EXTMEM_0780;
extern unsigned char xdata DAT_EXTMEM_08cd[3];
extern unsigned char xdata DAT_EXTMEM_cd00, DAT_EXTMEM_cd01, DAT_EXTMEM_cd02, DAT_EXTMEM_cd03, DAT_EXTMEM_cd04, DAT_EXTMEM_cd05;
extern unsigned char xdata DAT_EXTMEM_cd06, DAT_EXTMEM_cd07, DAT_EXTMEM_cd08, DAT_EXTMEM_cd09;
extern unsigned char xdata DAT_EXTMEM_cd20, DAT_EXTMEM_cd21, DAT_EXTMEM_cd22, DAT_EXTMEM_cd23, DAT_EXTMEM_cd24, DAT_EXTMEM_cd25;
extern unsigned char xdata DAT_EXTMEM_cd26, DAT_EXTMEM_cd27, DAT_EXTMEM_cd28, DAT_EXTMEM_cd29;
extern unsigned char xdata DAT_EXTMEM_f19a, DAT_EXTMEM_f19b, DAT_EXTMEM_f19c, DAT_EXTMEM_f19d, DAT_EXTMEM_f19e, DAT_EXTMEM_f19f;
extern unsigned char xdata DAT_EXTMEM_f194;
extern void FUN_CODE_abce(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
extern void FUN_CODE_b1a9(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
extern void FUN_CODE_65ab(void *fmt, ...) large;
extern void FUN_CODE_e04a(unsigned long a, unsigned long b, unsigned char n);
extern void FUN_CODE_e1eb(void);
extern unsigned char FUN_CODE_e4c9(void);
extern void FUN_CODE_e4d9(void);
extern void FUN_CODE_d938(unsigned long addr, unsigned char n);
extern void FUN_CODE_dfbe(unsigned int reg, unsigned long mask);
extern void FUN_CODE_e44b(unsigned char n);
extern unsigned char FUN_CODE_e3f9(void);
extern void FUN_CODE_b706(void);
extern unsigned char FUN_CODE_35a9(unsigned char m);
void FUN_CODE_e373(unsigned long addr, unsigned char n);
void FUN_CODE_e1a4(unsigned long addr, unsigned char n);
void FUN_CODE_dac5(unsigned char val, unsigned char n);
void FUN_CODE_999f(unsigned char *dst, unsigned char *src, unsigned char len);
unsigned long FUN_CODE_9b91(unsigned int reg);
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_ddbb(unsigned int reg, unsigned long mask);
void FUN_CODE_cbd9(unsigned long addr, unsigned char *buf, unsigned long n);
void FUN_CODE_cca2(unsigned long a, unsigned char *p);
struct cap FUN_CODE_d2fb(void);
void FUN_CODE_d4b2(unsigned char k, unsigned char *p);
void FUN_CODE_b45f(unsigned char v);
void FUN_CODE_b97a(void);
unsigned char FUN_CODE_ba96(void);
void FUN_CODE_94d3(unsigned char a, unsigned char b);
unsigned char FUN_CODE_8a0e(unsigned char a, unsigned int n, unsigned long *buf, unsigned long off, unsigned char f);
void FUN_CODE_76b4(void);
void FUN_CODE_69e5(unsigned long a, unsigned long b);
void FUN_CODE_5219(unsigned char a, unsigned char *p, unsigned int len);
void FUN_CODE_8f9b(unsigned long v, unsigned long typ, unsigned long addr, unsigned long h, unsigned long ep, unsigned long mps);
struct pair FUN_CODE_467e(void);
void FUN_CODE_9734(unsigned long a);
void FUN_CODE_c60e(unsigned long a, unsigned long b, unsigned long c);

void FUN_CODE_69e5(unsigned long a, unsigned long b)
{
    unsigned long cur;
    unsigned long dst;
    unsigned long nxt;
    unsigned int k;
    FUN_CODE_ddbb(0x10, 0x20);
    k = 0;
    while ((FUN_CODE_9b91(0x14) & 0x8000) != 0) {
        k++;
        if (k > 100) {
            DAT_EXTMEM_07d3[DAT_EXTMEM_075b]++;
            break;
        }
    }
    FUN_CODE_e373(b, 2);
    cur = (DAT_EXTMEM_0829->w16 & 0xffffffe0) >> 5;
    FUN_CODE_e04a(cur, a, 1);
    dst = a;
    FUN_CODE_e373(dst, 1);
    DAT_EXTMEM_08bc.td->next = DAT_EXTMEM_08bc.td->next & 0xfffffffe | 1;
    FUN_CODE_e1a4(dst, 1);
    nxt = cur;
    FUN_CODE_e373(nxt, 1);
    k = 0;
    while (!(unsigned char)(DAT_EXTMEM_08bc.td->next & 1)) {
        nxt = DAT_EXTMEM_08bc.td->next & 0xffffffe0;
        FUN_CODE_e373(nxt, 1);
        FUN_CODE_65ab((void code *)0xc973, (unsigned char)(DAT_EXTMEM_08bc.td->next & 1), nxt);
        k++;
        if (k > 10) {
            DAT_EXTMEM_07d3[DAT_EXTMEM_075b]++;
            break;
        }
    }
    DAT_EXTMEM_08bc.td->next = DAT_EXTMEM_08bc.td->next & 0x1f | dst << 5 & 0xffffffe0;
    DAT_EXTMEM_08bc.td->next = DAT_EXTMEM_08bc.td->next & 0xfffffffe;
    DAT_EXTMEM_08bc.td->alt = DAT_EXTMEM_08bc.td->alt & 0x1f | dst << 5 & 0xffffffe0;
    DAT_EXTMEM_08bc.td->alt = DAT_EXTMEM_08bc.td->alt & 0xfffffffe;
    FUN_CODE_e1a4(nxt, 1);
    FUN_CODE_dfbe(0x10, 0x20);
    k = 0;
    while ((FUN_CODE_9b91(0x14) & 0x8000) == 0) {
        FUN_CODE_65ab((void code *)0xc99c, FUN_CODE_9b91(0x14));
        k++;
        if (k > 10) {
            DAT_EXTMEM_07d3[DAT_EXTMEM_075b]++;
            break;
        }
    }
    FUN_CODE_e373(cur, 1);
    DAT_EXTMEM_08bc.td->b11 = (DAT_EXTMEM_08bc.td->b11 | 0x80) % 0x100;
    FUN_CODE_e1a4(cur, 1);
    k = 0;
    do {
        FUN_CODE_e44b(5);
        FUN_CODE_e373(cur, 1);
        if (DAT_EXTMEM_08bc.td->b11 & 0x80) FUN_CODE_65ab((void code *)0xc9aa, (unsigned long)DAT_EXTMEM_08bc.td->b11);
        k++;
        if (k > 100) {
            DAT_EXTMEM_07d3[DAT_EXTMEM_075b]++;
            break;
        }
    } while (DAT_EXTMEM_08bc.td->b11 & 0x80);
    FUN_CODE_b317(0x14, FUN_CODE_9b91(0x14));
    FUN_CODE_e373(b, 2);
    DAT_EXTMEM_0829->b27 = 0;
    FUN_CODE_e1a4(b, 2);
    FUN_CODE_dac5(0, 1);
    DAT_EXTMEM_08bc.td->next = DAT_EXTMEM_08bc.td->next & 0xfffffffe | 1;
    DAT_EXTMEM_08bc.td->b11 = (DAT_EXTMEM_08bc.td->b11 & 0x7f) % 0x100;
    DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0x7f | 0x80;
    DAT_EXTMEM_08bc.td->alt = DAT_EXTMEM_08bc.td->alt & 0xfffffffe | 1;
    DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xf3 | 0x0c;
    FUN_CODE_e1a4(cur, 1);
    FUN_CODE_ddbb(0x10, 0x20);
    k = 0;
    while ((FUN_CODE_9b91(0x14) & 0x8000) != 0) {
        k++;
        if (k > 10) {
            DAT_EXTMEM_07d3[DAT_EXTMEM_075b]++;
            break;
        }
    }
}

void FUN_CODE_e373(unsigned long addr, unsigned char n)
{
    FUN_CODE_abce(DAT_0022, addr, n, 0);
}

void FUN_CODE_e1a4(unsigned long addr, unsigned char n)
{
    FUN_CODE_b1a9(DAT_0022, addr, n, 0);
}

void FUN_CODE_999f(unsigned char *dst, unsigned char *src, unsigned char len)
{
    unsigned char i;
    unsigned char j;
    for (i = 0; i < (len >> 2); i++) {
        j = i << 2;
        dst[j] = src[j + 3];
        dst[j + 1] = src[j + 2];
        dst[j + 2] = src[j + 1];
        dst[j + 3] = src[j];
    }
    if (i * 4 < len) {
        j = i << 2;
        dst[j] = src[j + 3];
        dst[j + 1] = src[j + 2];
        dst[j + 2] = src[j + 1];
        dst[j + 3] = src[j];
    }
}

unsigned long FUN_CODE_9b91(unsigned int reg)
{
    unsigned char n;
    unsigned long v;
    reg &= 0x01ff;
    if (DAT_EXTMEM_075b == 1) {
        DAT_EXTMEM_cd21 = reg;
        DAT_EXTMEM_cd20 = ((reg >> 4) & 0x10) + 0x40;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd20 & 1));
        v = DAT_EXTMEM_cd29;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd28;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd27;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd26;
    } else {
        DAT_EXTMEM_cd01 = reg;
        DAT_EXTMEM_cd00 = ((reg >> 4) & 0x10) + 0x40;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd00 & 1));
        v = DAT_EXTMEM_cd09;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd08;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd07;
        v = (v << 8) + (unsigned long)DAT_EXTMEM_cd06;
    }
    return v;
}

void FUN_CODE_b317(unsigned int reg, unsigned long v)
{
    unsigned char n;
    reg &= 0x01ff;
    if (DAT_EXTMEM_075b == 1) {
        DAT_EXTMEM_cd21 = reg;
        DAT_EXTMEM_cd22 = v;
        DAT_EXTMEM_cd23 = v >> 8;
        DAT_EXTMEM_cd24 = v >> 16;
        DAT_EXTMEM_cd25 = v >> 24;
        DAT_EXTMEM_cd20 = ((reg >> 4) & 0x10) + 0x80;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd20 & 1));
    } else {
        DAT_EXTMEM_cd01 = reg;
        DAT_EXTMEM_cd02 = v;
        DAT_EXTMEM_cd03 = v >> 8;
        DAT_EXTMEM_cd04 = v >> 16;
        DAT_EXTMEM_cd05 = v >> 24;
        DAT_EXTMEM_cd00 = ((reg >> 4) & 0x10) + 0x80;
        n = 10;
        do {
            n--;
            FUN_CODE_e44b(1);
        } while (n > 0 && !(DAT_EXTMEM_cd00 & 1));
    }
}

void FUN_CODE_ddbb(unsigned int reg, unsigned long mask)
{
    unsigned long v;
    v = FUN_CODE_9b91(reg);
    FUN_CODE_b317(reg, v & ~mask);
}

void FUN_CODE_cbd9(unsigned long addr, unsigned char *buf, unsigned long n)
{
    unsigned int i;
    FUN_CODE_c60e(addr, n, DAT_EXTMEM_07d5);
    for (i = 0; i < n / 0x20; i++) {
        FUN_CODE_e373(DAT_EXTMEM_07d5 + i, 1);
        FUN_CODE_999f(buf + (i << 5), DAT_0022, 0x20);
    }
}

void FUN_CODE_cca2(unsigned long a, unsigned char *p)
{
    unsigned int i;
    DAT_EXTMEM_0717 = DAT_EXTMEM_08bc.d + 0x700;
    i = 0;
    do {
        FUN_CODE_e373(DAT_EXTMEM_0717 + i + a * 0x10, 1);
        FUN_CODE_999f(p + (i << 5), DAT_0022, 0x20);
        i++;
    } while (i < 0x10);
}

struct cap FUN_CODE_d2fb(void)
{
    struct cap r;
    unsigned char i;
    unsigned char n;
    for (i = 0; i < 8; i++) r.b[i] = 0;
    n = 1;
    FUN_CODE_e373(DAT_EXTMEM_08bc.c + (unsigned int)(n - 1), 1);
    if (!(DAT_EXTMEM_08bc.td->b11 & 0x80)) {
        FUN_CODE_d938(DAT_EXTMEM_08bc.a, 1);
        FUN_CODE_e373(DAT_EXTMEM_08bc.a, 1);
        FUN_CODE_999f(r.b, DAT_0022, 8);
        FUN_CODE_dfbe(0x14, FUN_CODE_9b91(0x14));
        FUN_CODE_94d3(1, 1);
    }
    return r;
}

void FUN_CODE_d4b2(unsigned char k, unsigned char *p)
{
    unsigned int i;
    for (i = 0; i < 0x10; i++) {
        FUN_CODE_e373(DAT_EXTMEM_07d5 + i + k * 0x10, 1);
        FUN_CODE_999f(p + (i << 5), DAT_0022, 0x20);
    }
}

void FUN_CODE_b45f(unsigned char v)
{
    FUN_CODE_e373(DAT_EXTMEM_08bc.b, 2);
    DAT_EXTMEM_0829->b7 = DAT_EXTMEM_0829->b7 & 0x80 | (v << 0) & 0x7f;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b, 2);
    FUN_CODE_e373(DAT_EXTMEM_08bc.b + 2, 2);
    DAT_EXTMEM_0829->b7 = DAT_EXTMEM_0829->b7 & 0x80 | (v << 0) & 0x7f;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 2, 2);
    FUN_CODE_e373(DAT_EXTMEM_08bc.b + 4, 2);
    DAT_EXTMEM_0829->b7 = DAT_EXTMEM_0829->b7 & 0x80 | (v << 0) & 0x7f;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 4, 2);
    FUN_CODE_e373(DAT_EXTMEM_08bc.b + 6, 2);
    DAT_EXTMEM_0829->b7 = DAT_EXTMEM_0829->b7 & 0x80 | (v << 0) & 0x7f;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 6, 2);
    FUN_CODE_dac5(0, 2);
    FUN_CODE_dac5(0, 2);
}

void FUN_CODE_b97a(void)
{
    unsigned char i;
    unsigned char *p;
    p = DAT_0022;
    FUN_CODE_94d3(0, 1);
    FUN_CODE_b317(0x24, DAT_EXTMEM_08b4 << 5);
    FUN_CODE_dac5(0, 2);
    ((unsigned long data *)DAT_0022)[0] = DAT_EXTMEM_08bc.b << 5 | 2;
    for (i = 1; i < 0x10; i++) ((unsigned long data *)DAT_0022)[i] = DAT_EXTMEM_08bc.b << 5 | 3;
    for (i = 0; i < 0x10; i++) FUN_CODE_e1a4(DAT_EXTMEM_08b4 + i * 2, 2);
    FUN_CODE_dac5(0, 1);
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.a, 1);
    FUN_CODE_ddbb(0x10, 0xd);
    FUN_CODE_b317(0x1c, 0);
    FUN_CODE_b317(0x10, FUN_CODE_9b91(0x10) & 0xfff0ffff | 0x80019);
}

unsigned char FUN_CODE_ba96(void)
{
    struct pair r;
    unsigned char *p;
    unsigned char n;
    unsigned char f;
    f = 1;
    p = &DAT_EXTMEM_071b;
    n = 1;
    do {
        if (f == 1) {
            FUN_CODE_b706();
            FUN_CODE_467e();
            f = 0;
        }
        DAT_EXTMEM_07d9[8].b[2] = 8;
        DAT_EXTMEM_07d9[8].b[4] = n;
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[8].b, DAT_EXTMEM_07d9[8].b[6]);
        DAT_EXTMEM_07d9[8].b[2] = 0x16;
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[8].b, DAT_EXTMEM_07d9[8].b[6]);
        if (!FUN_CODE_e3f9()) break;
        DAT_EXTMEM_07d9[8].b[2] = 4;
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[8].b, DAT_EXTMEM_07d9[8].b[6]);
        DAT_EXTMEM_07d9[7].b[4] = n;
        DAT_EXTMEM_07d9[6].b[4] = n;
        DAT_EXTMEM_07d9[7].b[2] = 0x10;
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[7].b, DAT_EXTMEM_07d9[7].b[6]);
        if (!FUN_CODE_e3f9()) break;
        DAT_EXTMEM_07d9[7].b[2] = 4;
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[7].b, DAT_EXTMEM_07d9[7].b[6]);
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[6].b, DAT_EXTMEM_07d9[6].b[6]);
        if (!FUN_CODE_e3f9()) break;
        DAT_EXTMEM_07d9[7].b[2] = 0x14;
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[7].b, DAT_EXTMEM_07d9[7].b[6]);
        FUN_CODE_5219(0, DAT_EXTMEM_07d9[6].b, DAT_EXTMEM_07d9[6].b[6]);
        if (p[0] == 3 && p[1] == 5) {
            r = FUN_CODE_467e();
            if (r.a == 8 && r.b == 0x50) {
                if (FUN_CODE_35a9(0)) return 1;
            }
            f = 1;
        }
        if (!FUN_CODE_e3f9()) break;
        n++;
    } while (n < 5);
    return 0;
}

void FUN_CODE_94d3(unsigned char a, unsigned char b)
{
    unsigned long tdb;
    unsigned long qhb;
    tdb = DAT_EXTMEM_08bc.c + (unsigned int)(b - 1);
    FUN_CODE_e373(tdb, 1);
    if (a == 0) {
        DAT_EXTMEM_08bc.td->next = DAT_EXTMEM_08bc.td->next & 0xfffffffe | 1;
        DAT_EXTMEM_08bc.td->alt = DAT_EXTMEM_08bc.td->alt & 0xfffffffe | 1;
        DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xfc | 1;
        DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0x7f | 0x80;
    }
    DAT_EXTMEM_08bc.td->tok = DAT_EXTMEM_08bc.td->tok & 0x8000 | 8;
    DAT_EXTMEM_08bc.td->buf[0] &= 0xfffff000;
    DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfff | DAT_EXTMEM_08bc.a << 5 & 0xfffff000;
    DAT_EXTMEM_08bc.td->b11 = (DAT_EXTMEM_08bc.td->b11 | 0x80) % 0x100;
    FUN_CODE_e1a4(tdb, 1);
    qhb = DAT_EXTMEM_08bc.b + (unsigned int)(b - 1) * 2UL;
    FUN_CODE_e373(qhb, 2);
    if (a == 0) {
        DAT_EXTMEM_0829->w0 = DAT_EXTMEM_0829->w0 & 0xfffffffe | 1;
        DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0xf0 | 1;
        DAT_EXTMEM_0829->b7 = DAT_EXTMEM_0829->b7 & 0x80 | 3;
        DAT_EXTMEM_0829->b11 = 0xff;
        DAT_EXTMEM_0829->i4 &= 0xf7ff;
    }
    DAT_EXTMEM_0829->w16 = DAT_EXTMEM_0829->w16 & 0x1f | DAT_EXTMEM_08bc.c << 5 & 0xffffffe0;
    DAT_EXTMEM_0829->w20 = DAT_EXTMEM_0829->w20 & 0x1f | DAT_EXTMEM_08bc.c << 5 & 0xffffffe0;
    DAT_EXTMEM_0829->w16 = DAT_EXTMEM_0829->w16 & 0xfffffffe;
    DAT_EXTMEM_0829->w20 = DAT_EXTMEM_0829->w20 & 0xfffffffe;
    FUN_CODE_e1a4(qhb, 2);
}

unsigned char FUN_CODE_8a0e(unsigned char a, unsigned int n, unsigned long *buf, unsigned long off, unsigned char f)
{
    unsigned char *q;
    unsigned long tdc;
    unsigned long qhc;
    unsigned int w;
    if (a == 2) q = &DAT_EXTMEM_08cd[1];
    else q = &DAT_EXTMEM_08cd[2];
    tdc = DAT_EXTMEM_08bc.c + *q;
    qhc = DAT_EXTMEM_08bc.b + (unsigned int)a * 2UL;
    FUN_CODE_e373(tdc, 1);
    w = n & 0x7fff;
    DAT_EXTMEM_08bc.td->tok = w | DAT_EXTMEM_08bc.td->tok & 0x8000;
    DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfff | *buf++ & 0xfffff000;
    DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfffff000 | (off << 0) & 0xfff;
    DAT_EXTMEM_08bc.td->buf[1] = DAT_EXTMEM_08bc.td->buf[1] & 0xfff | *buf++ & 0xfffff000;
    DAT_EXTMEM_08bc.td->buf[2] = DAT_EXTMEM_08bc.td->buf[2] & 0xfff | *buf++ & 0xfffff000;
    DAT_EXTMEM_08bc.td->buf[3] = DAT_EXTMEM_08bc.td->buf[3] & 0xfff | *buf++ & 0xfffff000;
    DAT_EXTMEM_08bc.td->buf[4] = DAT_EXTMEM_08bc.td->buf[4] & 0xfff | *buf++ & 0xfffff000;
    if (f) DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xfc | 1;
    else DAT_EXTMEM_08bc.td->b10 &= 0xfc;
    FUN_CODE_e1a4(tdc, 1);
    FUN_CODE_69e5(tdc, qhc);
    if (*q == 4 || *q == 6) (*q)++;
    else (*q)--;
    return 0;
}

void FUN_CODE_76b4(void)
{
    unsigned long pg[5];
    unsigned char i;
    unsigned long len;
    unsigned long avail;
    unsigned long off;
    DAT_EXTMEM_082a.sig = 0x55534243;
    FUN_CODE_999f((unsigned char *)&DAT_EXTMEM_082a.len, (unsigned char *)&DAT_EXTMEM_075c.len, 4);
    DAT_EXTMEM_082a.tag = DAT_EXTMEM_08de;
    switch (DAT_EXTMEM_075c.dir) {
    case 1:
        DAT_EXTMEM_082a.flags = 0;
        break;
    case 2:
        DAT_EXTMEM_082a.flags = 0x80;
        break;
    }
    DAT_EXTMEM_082a.lun = 0;
    DAT_EXTMEM_082a.cblen = DAT_EXTMEM_075c.cblen;
    for (i = 0; i < 0x10; i++) DAT_EXTMEM_082a.cb[i] = DAT_EXTMEM_075c.cb[i];
    FUN_CODE_e373(DAT_EXTMEM_08bc.a, 1);
    FUN_CODE_999f(DAT_0022, (unsigned char *)&DAT_EXTMEM_082a, sizeof(DAT_EXTMEM_082a));
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.a, 1);
    pg[0] = DAT_EXTMEM_08bc.a << 5;
    pg[1] = 0;
    pg[2] = 0;
    pg[3] = 0;
    pg[4] = 0;
    FUN_CODE_8a0e(DAT_EXTMEM_082a.ep_out, 0x1f, pg, 0, 0);
    if (DAT_EXTMEM_075c.len > 0) {
        len = DAT_EXTMEM_075c.len;
        pg[0] = DAT_EXTMEM_075c.addr & 0xfffff000;
        off = DAT_EXTMEM_075c.addr & 0xfff;
        avail = 0x1000 - off;
        i = 1;
        while (len > avail) {
            if (len > avail) {
                if (i < 5) {
                    pg[i] = pg[i - 1] + 0x1000;
                } else {
                    FUN_CODE_65ab((void code *)0xc9c4);
                    for (;;) ;
                }
            }
            len -= avail;
            avail = 0x1000;
            i++;
        }
        switch (DAT_EXTMEM_075c.dir) {
        case 1:
            FUN_CODE_8a0e(DAT_EXTMEM_082a.ep_out, (unsigned int)DAT_EXTMEM_075c.len, pg, off, 0);
            break;
        case 2:
            FUN_CODE_8a0e(DAT_EXTMEM_082a.ep_in, (unsigned int)DAT_EXTMEM_075c.len, pg, off, 1);
            break;
        }
    }
    FUN_CODE_e373(DAT_EXTMEM_08bc.a, 1);
    FUN_CODE_999f(DAT_0022, (unsigned char *)&DAT_EXTMEM_082a, sizeof(DAT_EXTMEM_082a));
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.a, 1);
    pg[0] = DAT_EXTMEM_08bc.a << 5;
    pg[1] = 0;
    pg[2] = 0;
    pg[3] = 0;
    pg[4] = 0;
    FUN_CODE_8a0e(DAT_EXTMEM_082a.ep_in, 0x1f, pg, 0, 1);
    FUN_CODE_e373(DAT_EXTMEM_08bc.a, 1);
    DAT_EXTMEM_0780 = (unsigned char)((unsigned long data *)DAT_0022)[3];
    DAT_EXTMEM_08de = DAT_EXTMEM_08de + 1;
}

void FUN_CODE_5219(unsigned char a, unsigned char *p, unsigned int len)
{
    unsigned long tda;
    unsigned long qha;
    unsigned int n0;
    unsigned int n1;
    unsigned int n2;
    FUN_CODE_dac5(0, 1);
    FUN_CODE_999f(DAT_0022, p, 8);
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.a, 1);
    tda = DAT_EXTMEM_08bc.c + (unsigned int)(DAT_EXTMEM_08cd[0] + a * 2);
    FUN_CODE_e373(tda, 1);
    DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xfc | 2;
    DAT_EXTMEM_08bc.td->tok = DAT_EXTMEM_08bc.td->tok & 0x8000 | 8;
    DAT_EXTMEM_08bc.td->tok &= 0x7fff;
    DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfff | DAT_EXTMEM_08bc.a << 5 & 0xfffff000;
    FUN_CODE_e1a4(tda, 1);
    qha = DAT_EXTMEM_08bc.b + (unsigned int)a * 2UL;
    FUN_CODE_69e5(tda, qha);
    DAT_EXTMEM_08cd[0]++;
    DAT_EXTMEM_08cd[0] &= 1;
    tda = DAT_EXTMEM_08bc.c + (unsigned int)(DAT_EXTMEM_08cd[0] + a * 2);
    qha = DAT_EXTMEM_08bc.b + (unsigned int)a * 2UL;
    switch (p[1]) {
    case 0x00:
    case 0x06:
    case 0x08:
    case 0x0a:
    case 0xfe:
        FUN_CODE_e373(tda, 1);
        DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xfc | 1;
        n0 = len & 0x7fff;
        DAT_EXTMEM_08bc.td->tok = n0 | DAT_EXTMEM_08bc.td->tok & 0x8000;
        DAT_EXTMEM_08bc.td->tok = DAT_EXTMEM_08bc.td->tok & 0x7fff | 0x8000;
        DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfff | DAT_EXTMEM_08bc.a << 5 & 0xfffff000;
        FUN_CODE_e1a4(tda, 1);
        FUN_CODE_69e5(tda, qha);
        DAT_EXTMEM_08cd[0]++;
        DAT_EXTMEM_08cd[0] &= 1;
        tda = DAT_EXTMEM_08bc.c + (unsigned int)(DAT_EXTMEM_08cd[0] + a * 2);
        qha = DAT_EXTMEM_08bc.b + (unsigned int)a * 2UL;
        FUN_CODE_e373(DAT_EXTMEM_08bc.a, 1);
        FUN_CODE_999f(&DAT_EXTMEM_071b, DAT_0022, len);
        FUN_CODE_e373(tda, 1);
        DAT_EXTMEM_08bc.td->b10 &= 0xfc;
        DAT_EXTMEM_08bc.td->tok &= 0x8000;
        DAT_EXTMEM_08bc.td->tok = DAT_EXTMEM_08bc.td->tok & 0x7fff | 0x8000;
        FUN_CODE_e1a4(tda, 1);
        FUN_CODE_69e5(tda, qha);
        break;
    case 0x01:
    case 0x03:
    case 0x05:
    case 0x09:
    case 0x0b:
    case 0xff:
        FUN_CODE_e373(tda, 1);
        DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xfc | 1;
        n1 = len & 0x7fff;
        DAT_EXTMEM_08bc.td->tok = n1 | DAT_EXTMEM_08bc.td->tok & 0x8000;
        DAT_EXTMEM_08bc.td->tok = DAT_EXTMEM_08bc.td->tok & 0x7fff | 0x8000;
        DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfff | DAT_EXTMEM_08bc.a << 5 & 0xfffff000;
        FUN_CODE_e1a4(tda, 1);
        FUN_CODE_69e5(tda, qha);
        DAT_EXTMEM_08cd[0]++;
        DAT_EXTMEM_08cd[0] &= 1;
        FUN_CODE_e373(DAT_EXTMEM_08bc.a, 1);
        FUN_CODE_999f(&DAT_EXTMEM_071b, DAT_0022, len);
        break;
    case 0x07:
        FUN_CODE_e373(tda, 1);
        DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xfc | 1;
        n2 = len & 0x7fff;
        DAT_EXTMEM_08bc.td->tok = n2 | DAT_EXTMEM_08bc.td->tok & 0x8000;
        DAT_EXTMEM_08bc.td->tok = DAT_EXTMEM_08bc.td->tok & 0x7fff | 0x8000;
        DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfff | DAT_EXTMEM_08bc.a << 5 & 0xfffff000;
        FUN_CODE_e1a4(DAT_EXTMEM_08bc.a, 1);
        FUN_CODE_69e5(tda, qha);
        DAT_EXTMEM_08cd[0]++;
        DAT_EXTMEM_08cd[0] &= 1;
        tda = DAT_EXTMEM_08bc.c + (unsigned int)(DAT_EXTMEM_08cd[0] + a * 2);
        qha = DAT_EXTMEM_08bc.b + (unsigned int)a * 2UL;
        FUN_CODE_e373(tda, 1);
        DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xfc | 1;
        DAT_EXTMEM_08bc.td->tok &= 0x8000;
        DAT_EXTMEM_08bc.td->tok = DAT_EXTMEM_08bc.td->tok & 0x7fff | 0x8000;
        FUN_CODE_e1a4(DAT_EXTMEM_08bc.a, 1);
        FUN_CODE_69e5(tda, qha);
        DAT_EXTMEM_08cd[0]++;
        DAT_EXTMEM_08cd[0] &= 1;
        break;
    }
}

void FUN_CODE_8f9b(unsigned long v, unsigned long typ, unsigned long addr, unsigned long h, unsigned long ep, unsigned long mps)
{
    FUN_CODE_dac5(0, 2);
    DAT_EXTMEM_0829->w0 = DAT_EXTMEM_0829->w0 & 0xfffffffe;
    DAT_EXTMEM_0829->w0 = DAT_EXTMEM_0829->w0 & 0xfffffff9 | typ << 1 & 6;
    DAT_EXTMEM_0829->b7 = DAT_EXTMEM_0829->b7 & 0x80 | addr & 0x7f;
    DAT_EXTMEM_0829->b7 = DAT_EXTMEM_0829->b7 & 0x7f;
    DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0xf0 | ep & 0xf;
    if (FUN_CODE_9b91(0x80) & 0x800000) {
        DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0xcf | 0x20;
        DAT_EXTMEM_0829->i4 &= 0xf7ff;
    } else {
        DAT_EXTMEM_0829->i4 = DAT_EXTMEM_0829->i4 & 0xf7ff | 0x800;
        if (FUN_CODE_9b91(0x80) & 0x400000) DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0xcf | 0x10;
        else DAT_EXTMEM_0829->b6 &= 0xcf;
    }
    if (v == 0 || v == 1) DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0xbf | 0x40;
    else DAT_EXTMEM_0829->b6 &= 0xbf;
    DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0x7f | h << 7 & 0x80;
    DAT_EXTMEM_0829->i4 = DAT_EXTMEM_0829->i4 & 0xf800 | mps & 0x7ff;
    DAT_EXTMEM_0829->i4 &= 0x0fff;
    DAT_EXTMEM_0829->w16 = DAT_EXTMEM_0829->w16 & 0xfffffffe | 1;
    DAT_EXTMEM_0829->w20 = DAT_EXTMEM_0829->w20 & 0xfffffffe | 1;
    DAT_EXTMEM_0829->w16 = DAT_EXTMEM_0829->w16 & 0x1f | (DAT_EXTMEM_08bc.c + (2 * v + 1)) << 5 & 0xffffffe0;
    DAT_EXTMEM_0829->w16 = DAT_EXTMEM_0829->w16 & 0xfffffffe;
}

struct pair FUN_CODE_467e(void)
{
    unsigned char i;
    unsigned char k;
    unsigned char *p;
    struct pair r;
    i = 0;
    p = &DAT_EXTMEM_071b;
    FUN_CODE_dac5(0, 2);
    DAT_EXTMEM_08bc.td->next = DAT_EXTMEM_08bc.td->next & 0xfffffffe | 1;
    DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0x7f | 0x80;
    DAT_EXTMEM_08bc.td->alt = DAT_EXTMEM_08bc.td->alt & 0xfffffffe | 1;
    DAT_EXTMEM_08bc.td->b10 = DAT_EXTMEM_08bc.td->b10 & 0xf3 | 0x0c;
    DAT_EXTMEM_08bc.td->buf[0] = DAT_EXTMEM_08bc.td->buf[0] & 0xfff | DAT_EXTMEM_08bc.a << 5 & 0xfffff000;
    for (i = 0; i < 8; i++) FUN_CODE_e1a4(DAT_EXTMEM_08bc.c + i, 1);
    FUN_CODE_8f9b(0, 1, 0, 1, 0, 8);
    DAT_EXTMEM_0829->w0 = DAT_EXTMEM_0829->w0 & 0x1f | (DAT_EXTMEM_08bc.b + 2) << 5 & 0xffffffe0;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b, 2);
    FUN_CODE_8f9b(1, 1, 0, 0, 0, 8);
    DAT_EXTMEM_0829->w0 = DAT_EXTMEM_0829->w0 & 0x1f | DAT_EXTMEM_08bc.b << 5 & 0xffffffe0;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 2, 2);
    if (!(FUN_CODE_9b91(0x80) & 0x800000)) i = 1;
    else i = 0;
    FUN_CODE_8f9b(2, 1, 3, 0, 1, 0x200);
    DAT_EXTMEM_0829->w0 = DAT_EXTMEM_0829->w0 & 0x1f | (DAT_EXTMEM_08bc.b + 6) << 5 & 0xffffffe0;
    if (i == 1) DAT_EXTMEM_0829->i4 = DAT_EXTMEM_0829->i4 & 0xf800 | 0x40;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 4, 2);
    FUN_CODE_8f9b(3, 1, 3, 0, 2, 0x200);
    DAT_EXTMEM_0829->w0 = DAT_EXTMEM_0829->w0 & 0x1f | (DAT_EXTMEM_08bc.b + 4) << 5 & 0xffffffe0;
    if (i == 1) DAT_EXTMEM_0829->i4 = DAT_EXTMEM_0829->i4 & 0xf800 | 0x40;
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 6, 2);
    FUN_CODE_b317(0x28, DAT_EXTMEM_08bc.b << 5);
    DAT_EXTMEM_07d9[1].b[2] = DAT_EXTMEM_07d1[DAT_EXTMEM_075b];
    FUN_CODE_5219(0, DAT_EXTMEM_07d9[1].b, 0);
    FUN_CODE_b45f(DAT_EXTMEM_07d1[DAT_EXTMEM_075b]);
    DAT_EXTMEM_07d1[DAT_EXTMEM_075b] += 2;
    if (FUN_CODE_e4c9()) return r;
    DAT_EXTMEM_07d9[4].b[6] = 8;
    FUN_CODE_5219(1, DAT_EXTMEM_07d9[4].b, DAT_EXTMEM_07d9[4].b[6]);
    FUN_CODE_e373(DAT_EXTMEM_08bc.b + 2, 2);
    DAT_EXTMEM_0829->i4 = DAT_EXTMEM_0829->i4 & 0xf800 | p[7];
    FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 2, 2);
    DAT_EXTMEM_07d9[4].b[6] = *p;
    FUN_CODE_5219(1, DAT_EXTMEM_07d9[4].b, DAT_EXTMEM_07d9[4].b[6]);
    if (FUN_CODE_e4c9()) return r;
    DAT_EXTMEM_07d9[0].b[6] = 0x20;
    FUN_CODE_5219(1, DAT_EXTMEM_07d9[0].b, 0x20);
    if (FUN_CODE_e4c9()) return r;
    r.a = p[0x0e];
    r.b = p[0x10];
    if (r.a == 8) {
        if ((p[0x14] & 0x80) > 0) {
            DAT_EXTMEM_082a.ep_in = 2;
            DAT_EXTMEM_082a.ep_out = 3;
        } else {
            DAT_EXTMEM_082a.ep_in = 3;
            DAT_EXTMEM_082a.ep_out = 2;
        }
        FUN_CODE_e373(DAT_EXTMEM_08bc.b + 4, 2);
        DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0xf0 | p[0x14] & 0xf;
        FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 4, 2);
        FUN_CODE_e373(DAT_EXTMEM_08bc.b + 6, 2);
        DAT_EXTMEM_0829->b6 = DAT_EXTMEM_0829->b6 & 0xf0 | p[0x1b] & 0xf;
        FUN_CODE_e1a4(DAT_EXTMEM_08bc.b + 6, 2);
        FUN_CODE_5219(1, DAT_EXTMEM_07d9[2].b, 0);
        FUN_CODE_e44b(1);
        if (FUN_CODE_e4c9()) return r;
        FUN_CODE_5219(1, DAT_EXTMEM_07d9[3].b, 1);
        if (FUN_CODE_e4c9()) return r;
        FUN_CODE_b317(0x10, FUN_CODE_9b91(0x10) & 0xffffffdf);
        i = 0;
        while ((FUN_CODE_9b91(0x14) & 0x8000) != 0) {
            i++;
            if (i > 200) break;
        }
        FUN_CODE_b317(0x28, (DAT_EXTMEM_08bc.b + 4) << 5);
        FUN_CODE_9b91(0x28);
        FUN_CODE_9b91(0x10);
        FUN_CODE_e44b(1);
        if (FUN_CODE_e4c9()) return r;
        for (i = 0; i < 10; i++) {
            FUN_CODE_e1eb();
            DAT_EXTMEM_075c.cb[0] = 0;
            DAT_EXTMEM_075c.cblen = 6;
            DAT_EXTMEM_075c.dir = 2;
            DAT_EXTMEM_075c.len = 0;
            DAT_EXTMEM_075c.n = 0;
            DAT_EXTMEM_075c.id ^= 0x80000000;
            DAT_EXTMEM_075c.st = 0;
            FUN_CODE_76b4();
            FUN_CODE_e44b(1);
            if (DAT_EXTMEM_0780 == 0) {
                FUN_CODE_e4d9();
                break;
            }
            FUN_CODE_e1eb();
            DAT_EXTMEM_075c.cb[0] = 3;
            DAT_EXTMEM_075c.cb[4] = 0x12;
            DAT_EXTMEM_075c.cblen = 6;
            DAT_EXTMEM_075c.dir = 2;
            DAT_EXTMEM_075c.len = 0x12;
            DAT_EXTMEM_075c.addr = DAT_EXTMEM_08bc.a << 5;
            DAT_EXTMEM_075c.n = 0;
            DAT_EXTMEM_075c.id ^= 0x80000000;
            DAT_EXTMEM_075c.st = 0;
            FUN_CODE_76b4();
            for (k = 0; k < 100; k++) {
                FUN_CODE_65ab((void code *)0xc9c9);
                FUN_CODE_e44b(0x0f);
            }
            DAT_EXTMEM_07d3[DAT_EXTMEM_075b]++;
        }
        if (FUN_CODE_e4c9()) return r;
        FUN_CODE_e1eb();
        DAT_EXTMEM_075c.cb[0] = 0x12;
        DAT_EXTMEM_075c.cb[4] = 0x24;
        DAT_EXTMEM_075c.cblen = 6;
        DAT_EXTMEM_075c.dir = 2;
        DAT_EXTMEM_075c.len = 0x24;
        DAT_EXTMEM_075c.addr = DAT_EXTMEM_08bc.a << 5;
        DAT_EXTMEM_075c.n = 0;
        DAT_EXTMEM_075c.id ^= 0x80000000;
        DAT_EXTMEM_075c.st = 0;
        FUN_CODE_76b4();
        FUN_CODE_e44b(1);
        FUN_CODE_e1eb();
        DAT_EXTMEM_075c.cb[0] = 0x25;
        DAT_EXTMEM_075c.cblen = 10;
        DAT_EXTMEM_075c.dir = 2;
        DAT_EXTMEM_075c.len = 8;
        DAT_EXTMEM_075c.addr = DAT_EXTMEM_08bc.a << 5;
        DAT_EXTMEM_075c.n = 0;
        DAT_EXTMEM_075c.id ^= 0x80000000;
        DAT_EXTMEM_075c.st = 0;
        FUN_CODE_76b4();
        FUN_CODE_e44b(1);
    } else if (r.a == 3) {
        FUN_CODE_5219(1, DAT_EXTMEM_07d9[2].b, 0);
        FUN_CODE_e44b(1);
        FUN_CODE_b97a();
    } else if (r.a == 9) {
        FUN_CODE_5219(1, DAT_EXTMEM_07d9[2].b, 0);
        FUN_CODE_e44b(1);
        FUN_CODE_5219(1, DAT_EXTMEM_07d9[9].b, 0);
    }
    return r;
}

void FUN_CODE_dac5(unsigned char val, unsigned char n)
{
    unsigned char i;
    unsigned char *p;
    p = DAT_0022;
    for (i = 0; i < n * 32; i++) p[i] = val;
}

void FUN_CODE_9734(unsigned long a)
{
    unsigned long b;
    unsigned int n;
    unsigned int i;
    unsigned int m;
    b = DAT_EXTMEM_f19a;
    b = (b << 8) + DAT_EXTMEM_f19b;
    b = (b << 8) + DAT_EXTMEM_f19c;
    b = (b << 8) + DAT_EXTMEM_f19d;
    b <<= 5;
    n = DAT_EXTMEM_f19e;
    n = (n << 8) + DAT_EXTMEM_f19f;
    m = 0x5000;
    i = 0;
    while (i < n) {
        DAT_EXTMEM_f194 = (unsigned long)i * 0xff / n;
        FUN_CODE_e1eb();
        DAT_EXTMEM_075c.cb[0] = 0x2a;
        DAT_EXTMEM_075c.cb[1] = 8;
        DAT_EXTMEM_075c.cb[2] = a >> 24;
        DAT_EXTMEM_075c.cb[3] = a >> 16;
        DAT_EXTMEM_075c.cb[4] = a >> 8;
        DAT_EXTMEM_075c.cb[5] = a;
        DAT_EXTMEM_075c.cb[8] = m >> 9;
        DAT_EXTMEM_075c.cblen = 0x0a;
        DAT_EXTMEM_075c.dir = 1;
        DAT_EXTMEM_075c.len = m;
        DAT_EXTMEM_075c.addr = b;
        DAT_EXTMEM_075c.n = 0;
        DAT_EXTMEM_075c.id ^= 0x80000000;
        DAT_EXTMEM_075c.st = 0;
        FUN_CODE_76b4();
        if (FUN_CODE_e4c9()) {
            FUN_CODE_e4d9();
            FUN_CODE_b706();
            FUN_CODE_467e();
            continue;
        }
        a += m >> 9;
        b += m;
        i++;
    }
}

void FUN_CODE_c60e(unsigned long a, unsigned long b, unsigned long c)
{
    FUN_CODE_e1eb();
    DAT_EXTMEM_075c.cb[0] = 0x28;
    DAT_EXTMEM_075c.cb[2] = a >> 24;
    DAT_EXTMEM_075c.cb[3] = a >> 16;
    DAT_EXTMEM_075c.cb[4] = a >> 8;
    DAT_EXTMEM_075c.cb[5] = a;
    DAT_EXTMEM_075c.cb[8] = b / 0x200;
    DAT_EXTMEM_075c.cblen = 0x0a;
    DAT_EXTMEM_075c.dir = 2;
    DAT_EXTMEM_075c.len = b;
    DAT_EXTMEM_075c.addr = c << 5;
    DAT_EXTMEM_075c.n = 0;
    DAT_EXTMEM_075c.id ^= 0x80000000;
    DAT_EXTMEM_075c.st = 0;
    FUN_CODE_76b4();
}
