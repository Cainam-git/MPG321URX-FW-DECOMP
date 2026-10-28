/* leon2m FUN_a013dc6c @ 0xa013dc6c-0xa013f1e4  input channel bring-up state machine
 * Flags -mcpu=v8 -O3 -g -msoft-float. 1374 words.
 *
 * One step per call for the channel DAT_a802cbd2 (0..3, 0xff = none): record c = DAT_a802df30[ch] (0x78 bytes).
 * Word +0: state (bits 28-31), step (20-23), port (12-15), f8 (8-11), f4 (4-7), bit 0. Word +0x70: flags,
 * bit 22 = 'run the state machine again in this call'. Port records 0x2A bytes at 0xA802E224 (status byte +2 == 4
 * = port ready, h00 bit 12 = port busy). Debug prints go through FUN_a00dd614(4).
 *   state 1/2: wait for port status 4 (bit 21) / 6 (bit 24) -> state 3.   4 -> 5.
 *   5: (bit 17: FUN_a00ef048 + FUN_a00f1150) port ready -> state 6.
 *   6: step 0 copy the port timing into the record (+6..+0x10), step 1 FUN_a013f370 -> state 7.
 *   7: FUN_a0101028 / FUN_a013c144 / FUN_a01016a4 -> state 8.
 *   8: 8 steps (input measurement + FRC set-up: FUN_a010325c, FUN_a01038c0, FUN_a0104380, FUN_a01045a0,
 *      FUN_a0104a34, FUN_a00f04f8) -> state 9 or 12.
 *   9 -> 10 (FUN_a0132964 == 1 keeps it), 10: step 0 output rate set-up (FUN_a0105ca4, FUN_a0107e44, FUN_a0109bbc,
 *      FUN_a01085f8, FUN_a0106b08), step 1 FUN_a0141ae8 in 5..6, step 2 -> state 11.
 *   11: FUN_a0141a98 -> FUN_a0118a28 ... -> state 12 when bit 26.   12: FUN_a0132964 == 1 -> state 5.
 *   Any 'port not ready' in states 7..12 -> state 5 and stop.
 * Finally DAT_a802cbd2 = (DAT_a802cbd2 + 1) & 3 (next channel on the next call).
 *
 * Source form (each item checked against the fw asm):
 *  - state 10 step 0 is 'if (!(c->w70 & 0x30000000)) { ...whole step... } INC_STEP(c); break;' (fw shares one
 *    INC_STEP after the 0x30000000 test, 0xf40-0x1020).
 *  - ch == 0: 'if (DAT_a802e3d0.u0.w & 0x8000000) {set arm} else {clear arm}' (fw falls through into the set arm,
 *    printf s_001a5988 at 0x1078; the clear arm s_001a59a8 is out of line at 0x1414).
 *  - 0xA802E3D0 is its own object (struct E3D0), not part of the 0x58-byte row at 0xA802E378: the fw reaches
 *    w58/w5c/w90/e3d3 as [base+0]/[+4]/[+0x38]/[+3] from one 'or %l4,0x3d0' (0x105c-0x10d8).
 *  - set arm: 'if (DAT_a802df30[0].h08 > lim) FUN_a0107e44(b3 != 0, rate, 1); else FUN_a0107e44(b3 != 0, lim, 1);'
 *    (lim is dead after it; gcc cross-jumps the call: fw 0x1080-0x10a8 'bleu,a' with 'ldub [..+3],%i5' in the slot,
 *    else arm 'cmp %g0,%i5; b; addx' out of line at 0x1408; fw compares before reading e3d3).
 *  - FUN_a0109bbc's 4th arg is DAT_a802df30[0].h08 (no 'ca' local): fresh 'or %i3,0x330' at 0xf84 and 0x10c0.
 *  - 'r < m / 2' test with the (1, ok) arm first (fw 0x1514 'bcc' back to the (0, 0) arm), 'ch' declared before 'ok'.
 *  - port_code's local is 'unsigned char v' (fw keeps 'and %o0,3,%o0' after the port-code join, 3x).
 *  - port_code IS the inlined FUN_a013cda8(ch) (same file, has 10 other callers): the static function takes the
 *    CHANNEL, 'static unsigned int port_code(unsigned char ch)' with the switch on PORT(&DAT_a802df30[ch]); compiled
 *    standalone it gives the code of FUN_a013cda8 (an int/uint parameter does not). Called as
 *    port_code(0) / port_code(3) / port_code(ch); no '& 3' at the callers (v is 0..3).
 *  - case 1 is written without the fall-through: 'if (F21) {status 4 -> 3} else if (F24 && status 6) -> 3; break;'
 *    (same code; gcc cross-jumps the copy into case 2's test, fw de84 -> def8).
 *  - case 6 abort is 'SET_STW(c, 5); CLR(c, 22);' but the aborts of states 7..11 are 'CLR(c, 22); SET_STW(c, 5);'.
 *    With this, both fw blocks get their insn order: case 6 at 0x660 (ld word first, only the final 'st w70' + loop
 *    test tail-shared via the 'b; st word' delay slot) and the 7..11 block at 0x368. With the same order in all six
 *    gcc merges case 6 completely (-9 insns).
 *  - state 5 ready arm writes the w70 bits first: 'c->w70 &= ~0xc000; CLR(c, 31); CLR(c, 27); SET_ST(c, 6);
 *    SET_STEP(c, 0); h00 &= ~0x1000;'. Then the fw 0x70c tail keeps its own loop-test copy (sethi; st w70; st word;
 *    b; btst) and does not share the 'st w70' tail.
 *  - state 6 step 0 stores b3f through a second Chan pointer ('struct Chan *c2 = c;' at the head of STEP 0,
 *    'c2->b3f = ...', plain INC_STEP).
 *  - state 6 step 1: 'if (FUN_a013bb50(PORT(c))) SET(c, 28); else CLR(c, 28);' (fw falls into the SET arm, 0xca4).
 *  - state 7: FUN_a01016a4 takes 5 args (inp, PORT(c), (w70 >> 12) & 3, 1, b28) (fw: PORT in %o1, b28 in %o4).
 *  - the state 8 STEP switch is in natural case order 0..7.
 *  - state 8 step 5: the f4 test is '(c->u.w & 0xf0) != 0x40' (fw 0x132c 'and %o0,0xf0; cmp 0x40'; 'u.b.f4 != 4'
 *    gives srl+and+cmp 4), the call is plain 'FUN_a0104a34(PORT(c), c->u.b.f8, c->h06, c->u.b.f4);', and the exit is
 *    'SET_STEP(c, 0); SET_ST(c, 9);' (fw 0x1364: andn 0xf00000 before the andn 0xf0000000 / or 0x90000000).
 *  - FUN_a00df170(s_001a5950, ch, DAT_a802df30[ch].h08): the debug print takes a 3rd argument. fw loads h08 into %o2
 *    at 0x1018 for the 'h08 > rate + 20' test and keeps it there untouched up to the call at 0x1034; with a 2-arg call
 *    gcc renames that chain (bb118). The live-out chain is not renamed in the fw.
 *  - case 12 is written abort-first: 'if (status != 4) {abort} else if (BUSY) {abort} else {FUN_a0132964 == 1 ...}'
 *    (same code; fw renames the abort block before the FUN_a0132964 compare).
 *  - prototypes: 'void FUN_a01045a0(unsigned char, unsigned long long *, unsigned short)' (a K&R declaration
 *    swaps the argument set-up order at fw 0x8fc); 'void FUN_a00ef1b0(int, int, struct S16 *)' (the callee ends in a
 *    plain 'restore' and reuses %i0 as a local); 'void FUN_a01016a4(unsigned char, unsigned char, unsigned int,
 *    unsigned char, unsigned char)' (fw 0xa01016a4 is a tail-call wrapper: st %o2, 'and 0xff' on o0/o1/o3/o4; with an
 *    int return the call RTL sets %o0 and the scheduler moves the %o0 argument set-up at fw 0x600 and 0x890);
 *    FUN_a01085f8(int, uchar, uchar); FUN_a0104a34(uchar port, int f8, ushort h, int f4); FUN_a0107e44 / FUN_a0109bbc
 *    with their signatures from src/leon2m.
 * Compiler aids (no code):
 *  - CASE ORDER (every moved case ends in 'break'): main switch 0/3, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 2; the state 10
 *    and state 11 step switches in natural order.
 *  - 'do continue; while (0);' (continue binds to the do-while(0), PRED_CONTINUE hint) after 'if (F(c, 17)) {' in
 *    state 8 step 5.
 *  - 'for (;;) break;' (break binds to the empty for; ends cse1's extended block) after FUN_a0118a28 in state 11
 *    step 0.
 *  - Two __builtin_expect branch hints (no instructions; they only set the edge probability, PRED_BUILTIN_EXPECT
 *    99 %, first-match, so it replaces the guessed heuristics on that one branch). Each alone gives a different
 *    layout; together they give the firmware's block order with the same instructions:
 *    - state 8 step 1: 'if (__builtin_expect(!!((int)c->w40 < 0), 1)) CLR(c, 22);'. The edge into the CLR(c, 22)
 *      arm goes from 21 % to 99 %. Block frequencies: the CLR(22) arm 0 -> 2 and the shared CLR(22)/CLR(28) andn
 *      tail 0 -> 2. bb-reorder then extends the step 1 trace through the arm and places the andn tail as its own
 *      round-4 trace right after it (it was one of the last round-4 traces).
 *    - state 11 step 1: 'if (__builtin_expect(!!(F(c, 26)), 0)) {'. The edge into the 'step 0, state 12' arm goes
 *      from 50 % to 1 %, so that arm's frequency goes 3 -> 0 and its round-4 trace moves behind the other
 *      low-frequency traces.
 *    Net effect in round 4: the frequency-0 single-block traces are taken in the firmware's order: the state 8 step 5
 *    srl stub (0x82 test else arm) with its following blocks, then the step 0 fn0c stub, the state 10 stub, the
 *    FUN_a01062e0 stub and last the state 8 step 2 printf stub (without the hints: step 2 printf stub first, srl
 *    stub last), which is the cold-stub order at fw 0x1274 / 0x13ac.
 */
struct InT { unsigned short h00, h02; unsigned char p04[8]; unsigned short h0c, h0e, h10, h12, h14, h16; unsigned char rest[0x24]; };
struct OutT { unsigned short h00, h02, h04, h06, h08, h0a, h0c, h0e; unsigned char p10[8]; unsigned long long pclk; unsigned int w20; };
struct S16 { unsigned int w[4]; };

struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;  /* +0x00 */
    unsigned short h04;                     /* +0x04 timer */
    unsigned short h06, h08;                /* +0x06 (struct InT starts here) */
    unsigned char b0a, b0b, b0c, b0d;
    unsigned short h0e, h10;
    unsigned char p12[0x3e - 0x12];
    unsigned char b3e, b3f;                 /* +0x3e */
    unsigned int w40;                       /* +0x40 */
    unsigned char p44[4];
    struct OutT out;                        /* +0x48 */
    unsigned int w70;                       /* +0x70 flags, bit 22 = run again */
    unsigned short h74;                     /* +0x74 */
};
struct Port {
    unsigned short h00;                     /* +0x00 bit 12 = busy */
    unsigned char status;                   /* +0x02 */
    unsigned char p03[6], b09, b0a;
    unsigned char p0b[0x1a - 0x0b];
    unsigned short h1a, h1c, h1e, h20;
    unsigned char b22, b23, b24, p25;
    unsigned short h26;
    unsigned char b28, p29;
};
struct Row378 {                             /* 0xA802E378, the active panel row (0x58 bytes) */
    unsigned char p00[0x48];
    unsigned short h48;                     /* 0xA802E3C0 */
    unsigned char p4a[0x52 - 0x4a];
    unsigned short rate;                    /* 0xA802E3CA */
    unsigned char p54[0x58 - 0x54];
};
struct E3D0 {                               /* 0xA802E3D0, a separate object right after the panel row */
    union { unsigned int w; unsigned char b[4]; } u0;   /* +0x00 flags, byte 3 = 0xA802E3D3 */
    unsigned int w4;                        /* +0x04 */
    unsigned char p08[0x38 - 0x08];
    unsigned int w38;                       /* +0x38 = 0xA802E408 */
};
struct CB { unsigned char p00[0xc]; void (*fn0c)(unsigned char, struct S16 *); unsigned char p10[0x38 - 0x10];
            void (*fn38)(unsigned char); };
struct PanelParam { unsigned char p00[0xa]; unsigned short h0a; unsigned char p0c[0x50 - 0x0c]; unsigned short h50; };

extern unsigned char DAT_a802cbd2;
extern struct Chan DAT_a802df30[4];
extern struct Port DAT_a802e224[];
extern struct Row378 DAT_a802e378;
extern struct E3D0 DAT_a802e3d0;
extern unsigned char DAT_a802e3d3, DAT_a802e3f2, DAT_a802e3f3;
extern struct CB DAT_a802cc1c;
extern struct PanelParam *DAT_a802d6a4;

extern char s_001a57c8[], s_001a57e8[], s_001a5808[], s_001a5820[], s_001a5840[], s_001a5858[], s_001a5870[],
    s_001a5888[], s_001a58a0[], s_001a58b8[], s_001a58d0[], s_001a58f0[], s_001a5910[], s_001a5928[],
    s_001a5950[], s_001a5988[], s_001a59a8[], s_001a59d0[];

extern unsigned char FUN_a00dd614(unsigned char);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned short func_0x4008d594(unsigned short);
extern unsigned short func_0x4008d588(void);
extern int func_0x4008e2a4();
extern int func_0x4008e3c4();
extern int FUN_a014226c();
extern unsigned char FUN_a0132964();
extern int FUN_a00f0b58();
extern unsigned char FUN_a0142e8c(unsigned int);
extern unsigned char FUN_a0141a98(void);
extern int FUN_a013b86c();
extern void FUN_a0118a28(unsigned char, unsigned char);
extern int FUN_a0101028();
extern int FUN_a013c144();
extern void FUN_a01016a4(unsigned char, unsigned char, unsigned int, unsigned char, unsigned char);
extern unsigned char FUN_a01211d4();
extern void FUN_a013f370(unsigned char);
extern unsigned char FUN_a013ba14();
extern unsigned char FUN_a013bb50();
extern unsigned char FUN_a0141ae8(void);
extern unsigned short FUN_a0105ca4();
extern unsigned char FUN_a011cf88(void);
extern void FUN_a01085f8(int ch, unsigned char mode, unsigned char ok);
extern void FUN_a01062e0(int, unsigned char);
extern void FUN_a0106b08(unsigned char);
extern void FUN_a0107e44(unsigned char, unsigned short, unsigned char);
extern void FUN_a0109bbc(unsigned char, unsigned char, unsigned short, unsigned short);
extern int FUN_a00ef048();
extern int FUN_a00f1150();
extern unsigned char FUN_a00f04f8(unsigned char, unsigned char);
extern void FUN_a0104a34(unsigned char port, int f8, unsigned short h, int f4);
extern unsigned char FUN_a0142168(unsigned char);
extern int FUN_a0137b5c();
extern unsigned char FUN_a00fd820(unsigned char);
extern int FUN_a012b404();
extern int FUN_a00f6898();
extern int FUN_a00f63bc(int);
extern int FUN_a00f6b34();
extern void FUN_a00eef7c(unsigned char p);
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern void FUN_a013dbcc(unsigned char, void *, struct S16 *);
extern void FUN_a00ef1b0(int, int, struct S16 *);
extern void FUN_a01045a0(unsigned char, unsigned long long *, unsigned short);
extern void FUN_a0104380(unsigned char, unsigned long long *);
extern void FUN_a01038c0(unsigned char, int, unsigned char, struct InT *, struct OutT *, int, unsigned char);
extern int FUN_a013d684(int);
extern int FUN_a013d918(int);
extern int FUN_a010325c();
extern int FUN_a013d1b4(unsigned char, struct S16 *);


#define ST(c)     ((c)->u.b.state)
#define STEP(c)   ((c)->u.b.step)
#define PORT(c)   ((c)->u.b.port)
#define SET_ST(c, v)   ((c)->u.b.state = (v))
#define SET_STW(c, v)  ((c)->u.w = ((c)->u.w & ~0xf0000000) | ((unsigned int)(v) << 28))
#define SET_STEP(c, v) ((c)->u.b.step = (v))
#define INC_STEP(c)    ((c)->u.b.step++)
#define F(c, b)   (((c)->w70 >> (b)) & 1)
#define SET(c, b) ((c)->w70 |= 1u << (b))
#define CLR(c, b) ((c)->w70 &= ~(1u << (b)))
#define BUSY(p)   ((DAT_a802e224[p].h00 >> 12) & 1)
#define DBG(s) do { if (FUN_a00dd614(4)) FUN_a00df170(s, DAT_a802cbd2); } while (0)
#define PORT_OK(c) (DAT_a802e224[PORT(c)].status == 4 && !BUSY(PORT(c)))

static unsigned int port_code(unsigned char ch)
{
    unsigned char v = 0;
    switch (PORT(&DAT_a802df30[ch])) {
    case 0: v = 0; break;
    case 1: v = 1; break;
    case 2: v = 2; break;
    case 3: v = 3; break;
    }
    return v;
}

static int chan_skip(struct Chan *c)
{
    if ((c->u.w & 0xf000) == 0x2000 && DAT_a802e3f2 == 1) return 1;
    if ((c->u.w & 0xf000) == 0x3000 && DAT_a802e3f3 == 1) return 1;
    return 0;
}

void FUN_a013dc6c(void)
{
    struct Chan *c;
    unsigned char inp;
    struct S16 s1, s2, t1;
    struct InT ibuf;
    struct OutT oc;
    unsigned char buf2[0x3c];
    struct S16 t2;

    if (DAT_a802cbd2 == 0xff) return;
    c = &DAT_a802df30[DAT_a802cbd2];
    inp = FUN_a014226c(DAT_a802e224[PORT(c)].b0a);
    if (!chan_skip(c) && DAT_a802cbd2 != 0xff) {
        do {
            switch (ST(c)) {
            case 0:
            case 3:
                break;
            case 1:
                if (F(c, 21)) {
                    if (DAT_a802e224[PORT(c)].status == 4) SET_ST(c, 3);
                } else if (F(c, 24) && DAT_a802e224[PORT(c)].status == 6) SET_ST(c, 3);
                break;
            case 4:
                SET_STW(c, 5);
                break;
            case 5:
                if (F(c, 17)) {
                    FUN_a00ef048(PORT(c));
                    FUN_a00f1150(PORT(c));
                }
                if (DAT_a802e224[PORT(c)].status == 4) {
                    c->w70 &= ~0xc000;
                    CLR(c, 31);
                    CLR(c, 27);
                    SET_ST(c, 6);
                    SET_STEP(c, 0);
                    DAT_a802e224[PORT(c)].h00 &= ~0x1000;
                }
                break;
            case 6:
                if (PORT_OK(c)) {
                if (F(c, 25)) break;
                if (F(c, 17)) {
                    if (FUN_a01211d4(PORT(c))) break;
                    CLR(c, 22);
                }
                if (STEP(c) == 0) {
                    struct Port *p;
                    struct Chan *c2 = c;
                    DBG(s_001a57c8);
                    p = &DAT_a802e224[PORT(c)];
                    c->h06 = p->h1e;
                    c->h08 = p->h20;
                    c->b0b = p->b22;
                    c->b0c = p->b23;
                    c->b0a = p->b24;
                    if (FUN_a0142e8c(PORT(c)) == 5) {
                        p = &DAT_a802e224[PORT(c)];
                        c->h0e = p->h1a;
                        c->h08 = (c->h06 * 1000u + p->h1c / 2) / p->h1c;
                        c->h10 = p->h1c;
                    } else
                        c->h10 = DAT_a802e224[PORT(c)].h26;
                    c2->b3f = DAT_a802e224[PORT(c)].b09;
                    c->w40 &= ~0x80000000;
                    c->w40 &= ~0x40000000;
                    INC_STEP(c);
                } else if (STEP(c) == 1) {
                    DBG(s_001a58d0);
                    FUN_a013f370(PORT(c));
                    SET_STEP(c, 0);
                    SET_ST(c, 7);
                    if (FUN_a013ba14(PORT(c))) SET(c, 29); else CLR(c, 29);
                    if (FUN_a013bb50(PORT(c))) SET(c, 28); else CLR(c, 28);
                }
                } else {
                    SET_STW(c, 5);
                    CLR(c, 22);
                }
                break;
            case 7:
                if (PORT_OK(c)) {
                DBG(s_001a5808);
                c->b3e = FUN_a0101028(DAT_a802e224[PORT(c)].b28);
                FUN_a013c144(inp, PORT(c), (c->w70 & 0xc000) == 0);
                FUN_a01016a4(inp, PORT(c), ((c->w70 >> 12) & 3), 1, DAT_a802e224[PORT(c)].b28);
                SET_ST(c, 8);
                SET_STEP(c, 0);
                } else {
                    CLR(c, 22);
                    SET_STW(c, 5);
                }
                break;
            case 8:
                if (PORT_OK(c)) {
                if (F(c, 25)) break;
                switch (STEP(c)) {
                case 0:
                    DBG(s_001a58b8);
                    if (F(c, 17)) {
                        FUN_a00ef048(PORT(c));
                        FUN_a00f1150(PORT(c));
                        SET_STEP(c, 5);
                        c->h04 = func_0x4008d588();
                    } else {
                        if (DAT_a802cc1c.fn0c) {
                            DAT_a802cc1c.fn0c(DAT_a802cbd2, &s1);
                            t1 = s1;
                            FUN_a013d1b4(DAT_a802cbd2, &t1);
                        }
                        INC_STEP(c);
                    }
                    break;
                case 1:
                    DBG(s_001a58a0);
                    FUN_a013d684(DAT_a802cbd2);
                    FUN_a013d918(DAT_a802cbd2);
                    FUN_a010325c(PORT(c), c->u.b.b0, F(c, 20), (struct InT *)&c->h06, &c->out);
                    INC_STEP(c);
                    c->h04 = func_0x4008d588();
                    if (__builtin_expect(!!((int)c->w40 < 0), 1)) CLR(c, 22);
                    break;
                case 2:
                    if (func_0x4008d594(c->h04) > 80) {
                        DBG(s_001a5888);
                        FUN_a013c910(&ibuf, &c->h06, 0x3c);
                        oc = c->out;
                        FUN_a01038c0(PORT(c), c->u.b.f8, c->u.b.b0, &ibuf, &oc, F(c, 20), (DAT_a802e3d0.u0.w >> 25) & (c->w70 >> 31));
                        SET_STEP(c, 5);
                        c->h04 = func_0x4008d588();
                    }
                    break;
                case 3:
                    DBG(s_001a5870);
                    FUN_a0104380(PORT(c), &c->out.pclk);
                    INC_STEP(c);
                    break;
                case 4:
                    DBG(s_001a5858);
                    FUN_a01045a0(PORT(c), &c->out.pclk, c->h08);
                    INC_STEP(c);
                    c->h04 = func_0x4008d588();
                    break;
                case 5:
                    DBG(s_001a5840);
                    if (func_0x4008d594(c->h04) > 40) {
                        if (F(c, 17)) {
                            do continue; while (0);
                            FUN_a00eef7c(PORT(c));
                            FUN_a013c910(buf2, &c->h06, 0x3c);
                            FUN_a013dbcc(PORT(c), buf2, &s2);
                            t2 = s2;
                            FUN_a00ef1b0(1, 1, &t2);
                            SET_STEP(c, 6);
                            c->h04 = func_0x4008d588();
                        } else {
                            FUN_a0104a34(PORT(c), c->u.b.f8, c->h06, c->u.b.f4);
                            if (FUN_a011cf88() > 0x82)
                                FUN_a0137b5c(FUN_a0142168(DAT_a802e224[PORT(c)].b0a), 1, (unsigned char)(1 << DAT_a802cbd2));
                            if (FUN_a00fd820(PORT(c)) == 0x71 || FUN_a00fd820(PORT(c)) == 0x81)
                                FUN_a012b404(inp);
                            if ((c->u.w & 0xf0) != 0x40) {
                                FUN_a00f6898(c->u.b.f4);
                                FUN_a00f63bc(c->u.b.f4);
                                FUN_a00f6b34(0xff);
                            }
                            SET_STEP(c, 0);
                            SET_ST(c, 9);
                            c->h04 = func_0x4008d588();
                            CLR(c, 22);
                        }
                        CLR(c, 11);
                    }
                    break;
                case 6:
                    if (func_0x4008d594(c->h04) > 50) {
                        FUN_a00f04f8(PORT(c), 1);
                        SET_STEP(c, 7);
                    }
                    break;
                case 7:
                    if (FUN_a00f04f8(PORT(c), 0)) {
                        SET_STEP(c, 0);
                        SET_ST(c, 12);
                        CLR(c, 22);
                    }
                    break;
                }
                } else {
                    CLR(c, 22);
                    SET_STW(c, 5);
                }
                break;
            case 9:
                if (PORT_OK(c)) {
                if (FUN_a00dd614(4)) FUN_a00df170(s_001a5928, DAT_a802cbd2, F(c, 27), F(c, 24));
                if (FUN_a0132964(PORT(c), inp) == 1) break;
                if ((c->w70 & 0x9000000) == 0x9000000) {
                    SET_STEP(c, 0);
                    SET_ST(c, 10);
                }
                } else {
                    CLR(c, 22);
                    SET_STW(c, 5);
                }
                break;
            case 10:
                if (PORT_OK(c)) {
                DBG(s_001a57e8);
                switch ((int)STEP(c)) {
                case 0:
                    if (!(c->w70 & 0x30000000)) {
                    if (!F(c, 11)) {
                        unsigned short lim, r, m;
                        unsigned char ch = DAT_a802cbd2;
                        unsigned char ok = 1;
                        lim = DAT_a802e378.h48 > 650 ? DAT_a802e378.h48 : 650;
                        oc = DAT_a802df30[0].out;
                        r = FUN_a0105ca4(ch);
                        m = DAT_a802d6a4->h0a;
                        if (FUN_a011cf88() <= 0x82) lim = lim > DAT_a802d6a4->h50 ? DAT_a802d6a4->h50 : lim;
                        else lim = 0;
                        if (DAT_a802df30[ch].h08 > DAT_a802e378.rate + 20) ok = 0;
                        FUN_a00df170(s_001a5950, ch, DAT_a802df30[ch].h08);
                        if (ch == 0) {
                            if (!(DAT_a802df30[0].u.b.b0)) {
                                if (DAT_a802e3d0.u0.w & 0x8000000) {
                                    FUN_a00df170(s_001a5988);
                                    if (DAT_a802df30[0].h08 > lim) {
                                        FUN_a0107e44(DAT_a802e3d0.u0.b[3] != 0, DAT_a802e378.rate, 1);
                                    } else {
                                        FUN_a0107e44(DAT_a802e3d0.u0.b[3] != 0, lim, 1);
                                    }
                                    FUN_a0109bbc(1, DAT_a802e3d0.w38 == 3, oc.h0c, DAT_a802df30[0].h08);
                                    if ((DAT_a802e3d0.w4 & 0xf0000000) == 0x30000000 || (DAT_a802e3d0.w4 & 0xf0000000) == 0x20000000)
                                        FUN_a01085f8(port_code(0), 2, ok & 1);
                                    else {
                                        FUN_a00df170(s_001a59d0, r, m);
                                        if (r < m / 2)
                                            FUN_a01085f8(port_code(0), 1, ok & 1);
                                        else
                                            FUN_a01085f8(port_code(0), 0, 0);
                                    }
                                } else {
                                    FUN_a00df170(s_001a59a8);
                                    FUN_a0107e44(DAT_a802e3d0.u0.b[3] != 0, DAT_a802e378.rate, 1);
                                    FUN_a0109bbc(0, 0, 0, DAT_a802df30[0].h08);
                                    FUN_a01085f8(port_code(0), 2, ok & 1);
                                }
                            }
                        } else if (ch == 3 && (DAT_a802e3d0.u0.w & 0x200000))
                            FUN_a01085f8(port_code(3), 0, 0);
                        else
                            FUN_a01085f8(port_code(ch), 2, ok & 1);
                    }
                    CLR(c, 11);
                    if (DAT_a802cbd2 == 0 && DAT_a802e3d3 == 0) FUN_a01062e0(DAT_a802e378.rate, 0);
                    FUN_a0106b08(PORT(c));
                    c->h04 = func_0x4008d588();
                    }
                    INC_STEP(c);
                    break;
                case 1:
                    if (F(c, 26) && FUN_a0141ae8() > 4 && FUN_a0141ae8() <= 6) INC_STEP(c);
                    break;
                case 2:
                    SET_STEP(c, 0);
                    SET_ST(c, 11);
                    break;
                }
                } else {
                    CLR(c, 22);
                    SET_STW(c, 5);
                }
                break;
            case 11:
                if (PORT_OK(c)) {
                DBG(s_001a58f0);
                switch ((int)STEP(c)) {
                case 0:
                    if (!F(c, 16) || func_0x4008d594(c->h04) >= c->h74) {
                        if (FUN_a0141a98()) {
                            if (!(c->w70 & 0x30000000)) {
                                if (DAT_a802cc1c.fn38) DAT_a802cc1c.fn38(FUN_a013b86c(PORT(c)));
                                FUN_a0118a28(PORT(c), 0);
                                for (;;) break;
                                func_0x4008e2a4();
                                func_0x4008e2a4();
                                func_0x4008e2a4();
                                func_0x4008e3c4(PORT(c), 0);
                            }
                            INC_STEP(c);
                        }
                    }
                    break;
                case 1:
                    if (__builtin_expect(!!(F(c, 26)), 0)) {
                        SET_STEP(c, 0);
                        SET_ST(c, 12);
                    }
                    break;
                }
                } else {
                    CLR(c, 22);
                    SET_STW(c, 5);
                }
                break;
            case 12:
                if (DAT_a802e224[PORT(c)].status != 4) {
                    CLR(c, 22);
                    SET_ST(c, 5);
                    DBG(s_001a5820);
                } else if (BUSY(PORT(c))) {
                    CLR(c, 22);
                    SET_ST(c, 5);
                    DBG(s_001a5820);
                } else {
                    if (FUN_a0132964(PORT(c), inp) == 1) {
                        SET(c, 11);
                        CLR(c, 22);
                        SET_ST(c, 5);
                        FUN_a00df170(s_001a5910, DAT_a802cbd2);
                    } else if (F(c, 17))
                        FUN_a00f0b58(PORT(c));
                }
                break;
            case 2:
                if (F(c, 24) && DAT_a802e224[PORT(c)].status == 6) SET_ST(c, 3);
                break;
            }
        } while (c->w70 & 0x400000);
    }
    DAT_a802cbd2 = (DAT_a802cbd2 + 1) & 3;
}
