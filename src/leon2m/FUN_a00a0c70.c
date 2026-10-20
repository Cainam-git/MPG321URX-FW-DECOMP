/* leon2m FUN_a00a0c70 @ 0xa00a0c70-0xa00a0ee8 (158 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT: jf 100.00 match=True,
 * rawcmp 0/158 mismatches. Uses a no-code aid (2 stacked 'do continue; while (0);' hints, see Aids).
 * One of 4 twins (a00a0508 / a00a0780 / a00a09f8 / a00a0c70 = port state byte DAT_a802d290 +0x18d / +0x18c /
 * +0x18b / +0x18a; FUN_a014459c arg 0 / 2 / 3 / 1; FUN_a00b8e7c arg 3 / 2 / 1 / 0). This one: st[0] (+0x18a),
 * FUN_a014459c(1), FUN_a00b8e7c(0). void, no parameters (the fw never reads %i0/%i1). Pointer-called per-port
 * handler.
 * Code facts: if d290 u16 +0x1f6 == 0x55aa and (u32 +0x1d4 & 0xffff00) == 0x5500: d290+0x1e = FUN_a014459c(k),
 *   FUN_a00d9238(), FUN_a00808ac(4, 0), DAT_a802b08e |= 2, return.
 * Else (not 0x55aa): DAT_a802cff4 bit 10 set -> return; d290+0x1a9 == 1 and st == 2: DAT_a802cffe = 5; if bit 15
 *   of u16 DAT_a802cff8: set its bit 10 and FUN_a00808ac(4, 0); afec = 0; FUN_a00b5080(); FUN_a00b0f48();
 *   afec = 0x116; b08e |= 2; d290+0x1aa = 0; DAT_a802d03c = func_0x4008d588() (ms tick); return.
 * Then (also the 0x55aa path that fails the 0x5500 test): (u8)FUN_a013ce6c(0) must be 0xc and st != 0;
 *   st == 1: return if int +0x11c < 0, or u32 +0xb0 != 0 and (u8)FUN_a00d8bd8() == 1, or FUN_a00d7d48() != 0;
 *   st == 6: return if FUN_a00d7d48() != 0; then st == 6: return if int +0x1f4 < 0; else st == 9: return if
 *   FUN_a00d7d48() != 0 or u32 +0x174 bit 15; st == 10: return if FUN_a00d7d48() != 0;
 *   finally FUN_a00b8e7c(n), DAT_a802afec = st + 0xf9, tail call FUN_a00a45a8().
 * This function itself reads no timing or rate value; the per-port step above is chosen by the port state byte st
 *   and the d290 / cff4 flags.
 * Matching form: bit 15 of the u16 written '(short)(x & 0x8000)' (fw: sethi 0xffff8000; and; sll 16; cmp; the
 *   plain mask gives ldsh/bl); a pointer p = &DAT_a802d290 taken right before the first st == 6 test and used for
 *   the rest (the fw keeps ONE base register from there, so gcse PRE merges the st loads); FUN_a00d8bd8 takes no
 *   arguments; the 6-arm written 'if (+0x1f4 >= 0) goto ten; return;'.
 * Aids: two 'do continue; while (0);' lines before that 'return' (documented no-code PRED_CONTINUE hint, the
 *   c7bc class; no instructions). Why (cfglayout.c fixup_reorder_chain, -da dumps): neither successor of the
 *   +0x1f4 test is next, so the jump is inverted when its REG_BR_PROB < 50 %. Opcode-positive (x < 0: 21 %) and
 *   the goto (70 % not taken) give 38 % -> ours 'bge T10; b,a ret'; the two hints (56 % each) give 59 % -> the fw
 *   'bl ret; b T10'. Same result with 6 hints and no goto. No natural form found (switch, if/else orders, goto
 *   forms, ~6 test spellings, else-if nesting; the early-return heuristic cannot fire: ret is the last bb).
 */
struct D290 {
    unsigned char p000[0x1e];
    unsigned char b1e;
    unsigned char p01f[0xb0 - 0x1f];
    unsigned int w0b0;
    unsigned char p0b4[0x11c - 0xb4];
    int w11c;
    unsigned char p120[0x174 - 0x120];
    unsigned int w174;
    unsigned char p178[0x18a - 0x178];
    unsigned char st[4];
    unsigned char p18e[0x1a9 - 0x18e];
    unsigned char b1a9;
    unsigned char b1aa;
    unsigned char p1ab[0x1d4 - 0x1ab];
    unsigned int w1d4;
    unsigned char p1d8[0x1f4 - 0x1d8];
    union { int w; struct { unsigned short hi, lo; } h; } u1f4;
};
struct CFF4 {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned char p6[4];
    unsigned char ba;
};
extern struct D290 DAT_a802d290;
extern struct CFF4 DAT_a802cff4;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern unsigned short _DAT_a802d03c;
extern unsigned char FUN_a014459c(unsigned char v);
extern void FUN_a00d9238(void);
extern void FUN_a00808ac(int, int);
extern unsigned int FUN_a013ce6c(unsigned int);
extern unsigned int FUN_a00d8bd8(void);
extern int FUN_a00d7d48(void);
extern void FUN_a00b8e7c(int);
extern void FUN_a00a45a8(void);
extern void FUN_a00b5080(void);
extern void FUN_a00b0f48(void);
extern unsigned short func_0x4008d588(void);

void FUN_a00a0c70(void)
{
    struct D290 *p;

    if (DAT_a802d290.u1f4.h.lo == 0x55aa) {
        if ((DAT_a802d290.w1d4 & 0xffff00) == 0x5500) {
            DAT_a802d290.b1e = FUN_a014459c(1);
            FUN_a00d9238();
            FUN_a00808ac(4, 0);
            DAT_a802b08e |= 2;
            return;
        }
    } else {
        if (DAT_a802cff4.h0 & 0x400)
            return;
        if (DAT_a802d290.b1a9 == 1 && DAT_a802d290.st[0] == 2) {
            DAT_a802cff4.ba = 5;
            if ((short)(DAT_a802cff4.h4 & 0x8000)) {
                DAT_a802cff4.h4 |= 0x400;
                FUN_a00808ac(4, 0);
            }
            _DAT_a802afec = 0;
            FUN_a00b5080();
            FUN_a00b0f48();
            _DAT_a802afec = 0x116;
            DAT_a802b08e |= 2;
            DAT_a802d290.b1aa = 0;
            _DAT_a802d03c = func_0x4008d588();
            return;
        }
    }
    if ((FUN_a013ce6c(0) & 0xff) != 0xc)
        return;
    if (DAT_a802d290.st[0] == 0)
        return;
    if (DAT_a802d290.st[0] == 1) {
        if (DAT_a802d290.w11c < 0)
            return;
        if (DAT_a802d290.w0b0 != 0 && (unsigned char)FUN_a00d8bd8() == 1)
            return;
        if (FUN_a00d7d48() != 0)
            return;
    }
    p = &DAT_a802d290;
    if (p->st[0] == 6) {
        if (FUN_a00d7d48() != 0)
            return;
    }
    if (p->st[0] == 6) {
        if (p->u1f4.w >= 0)
            goto ten;
        do continue; while (0);
        do continue; while (0);
        return;
    } else if (p->st[0] == 9) {
        if (FUN_a00d7d48() != 0)
            return;
        if (p->w174 & 0x8000)
            return;
    }
ten:
    if (p->st[0] == 10) {
        if (FUN_a00d7d48() != 0)
            return;
    }
    FUN_a00b8e7c(0);
    _DAT_a802afec = p->st[0] + 0xf9;
    FUN_a00a45a8();
}
