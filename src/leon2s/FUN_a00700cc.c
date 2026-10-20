/* leon2s FUN_a00700cc @ 0xa00700cc  publish the input port records and status words to the Big chip
 * (hand; BYTE-EXACT at -mcpu=v8 -Os -g:
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches over 0xa00700cc-0xa00703b8, 187 words).
 *
 * 1. ids[7] = port ids from mailbox word 0 (FUN_a006fca8). For each slot i (0..6): id = ids[i], n = id - 1,
 *    rec = port record 0xA807A824 + 20 * n. When id is 1..9 and the record's 'changed' bytes +0xf or +0x10 are 1:
 *    print "InputPortidx  %d" n, FUN_a006fbac(id, n, buf) builds the 4-word descriptor (buf[0] byte 1 = rec+0xd,
 *    the flags byte whose bit 2 is the line-rate switch), FUN_a006fad4(slot map[2i+1], 0, buf, 4) writes it to
 *    mailbox portal 1 slot i+1 (read by the Big chip's FUN_a01387a4); if +0x10 was 1: FUN_a006fc58(i) and clear it;
 *    clear +0xf.
 * 2. word 2 byte 0 -> DAT_a80788d3; word 3 bits 8..15 = FUN_a0083e28(); FUN_a006fedc() (word 3 bits 24..31);
 *    word 3 bits 0..5 = DAT_a80788d2 & 0x3f, DAT_a80788d2 &= ~DAT_a80788dd, bits 6..7 = FUN_a0088f84() & 3;
 *    if DAT_a80788d2 != 0: print "RxHPDStatus : %02X" DAT_a80788d2 and pulse 0x9f1cc264(0/1) + 0x9f1cc0a8()
 *    for bits 4/5 of the word.
 * 3. word 0 (DAT_a80788e0): bits 1..2 = 0x9f1c3efc() & 3, write; bits 4..31 = the 7 port type nibbles
 *    (rec[i].b0 & 0xf, 4 bits each), write. This nibble is the type the Big chip tests for 5 (line-rate path).
 *
 * Flags: -mcpu=v8 -Os -g (as every src/leon2s file; -O2/-O3 score 27-42 %).
 * Keys (last swap):
 *  - the record address is integer arithmetic 'n * sizeof(struct PortRec) + b' (Ghidra shows the same shape:
 *    iVar4 = n * 0x14; *(char *)(iVar4 + 0xa807a833)), with b = the record base as unsigned int.
 *  - DOCUMENTED NO-CODE AID: 'b = (unsigned int)DAT_a807a824 + (x >> 8)'. x = id is an unsigned char zero-extended,
 *    so x <= 0xff and x >> 8 == 0 always: the term is provably zero and emits no code (rawcmp 0).
 *    Mechanism (gcc 3.4.4, checked in the -da dumps): combine (pass 20) folds (lshiftrt x 8) to 0 by nonzero_bits and
 *    merges 'tmp = x >> 8', 'base = lo_sum(high, DAT_a807a824)' (REG_EQUAL DAT_a807a824) and 'b = tmp + base' into
 *    'b = lo_sum(high, DAT_a807a824)' at b's insn, keeping that insn's notes: NO REG_EQUAL. So local-alloc.c
 *    update_equiv_regs gives b no REG_EQUIV and does NOT move the %lo 'or' next to the add (it does for every
 *    single-set constant base, which made the sched2 tie between the 'or' and the last 'sll' fall to the sll by
 *    INSN_LUID). The 'or' keeps its source position before the multiply's last shift -> fw order
 *    'sethi; or %g1,0x24,%g1; sll %o5,2,%o5; add %o5,%g1,%l1'. b stays a local pseudo tied with the high
 *    (high dies in the or) -> one qty, %g1 (fw). Without the '>> 8' term the same file is 99.47 (the old swap).
 *  - memcpy (gcc's block-copy libcall for the map[] initializer) declared with the asm label of the firmware
 *    memcpy FUN_a00b15d8 (call 0xa00b15d8), as for leon2m FUN_a00d6054 (no code change; the jf
 *    link step needs a firmware name).
 * Earlier keys:
 *  - the HPD print has a REAL second argument (string 0xa00664b0 has %02X): FUN_a0073044(s, DAT_a80788d2) - it
 *    keeps the reloaded byte in %o1 and fixes the arg order / or-stb order of the word-3 block.
 *  - documented no-code aid 'for (;;) break;' after the record address: its loop notes stop sched1 from hoisting
 *    the 1..9 range test above the record address (fw order: address, then 'and %o4,0xff' + test).
 *  - the 1..9 test is on a SEPARATE 'unsigned int x = id;' taken BEFORE n = id - 1 (fw keeps
 *    'and %o4,0xff,%l3' and passes %l3 to FUN_a006fbac): id is then still live after the extend, so regmove.c
 *    optimize_reg_copy_3 cannot fold the extend into the ldub, and global.c does not copy x's %o0 preference to id
 *    (id stays in %o4). No volatile needed.
 *  - separate loop counter k with i = k (fw %l4 counter, %l2 byte copy); the word-3 block written with
 *    the c/w/d/lo temporaries in this order; the type loop bound held in a variable (cnt = 7).
 */
struct PortRec { unsigned char b0, b1; unsigned short h2, h4, h6, h8, ha; unsigned char bc, bd, be, bf, b10, b11, b12, b13; };
extern struct PortRec DAT_a807a824[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern unsigned char DAT_a80788d2, DAT_a80788d3, DAT_a80788dd;
extern unsigned int DAT_a80788e0;
extern char s_a0066498[], s_a00664b0[];
extern int FUN_a0073044();
extern void FUN_a006fca8(unsigned char *ids);
extern void FUN_a006fbac(unsigned char id, unsigned char n, unsigned int *buf);
extern void FUN_a006fad4(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void FUN_a006faa8(unsigned char slot, int word, unsigned int *buf, unsigned char n);
extern void FUN_a006fc58(unsigned char i);
extern void FUN_a006fedc(void);
extern unsigned char FUN_a0083e28(void);
extern unsigned char FUN_a0088f84(void);
extern void func_0x9f1cc264(int);
extern void func_0x9f1cc0a8(void);
extern int func_0x9f1c3efc(void);

void FUN_a00700cc(void)
{
    unsigned char map[14] = { 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7 };
    unsigned int buf[4];
    unsigned char ids[8];
    unsigned int w52, w56, w60, types;
    unsigned char i, k;

    FUN_a006fca8(ids);
    for (k = 0; k < 7; k++) {
        unsigned char id;
        unsigned int x;
        i = k;
        id = ids[i];
        x = id;
        unsigned char n = id - 1;
        unsigned int b = (unsigned int)DAT_a807a824 + (x >> 8);
        struct PortRec *r = (struct PortRec *)(n * sizeof(struct PortRec) + b);
        for (;;) break;
        if (x - 1 <= 8 && (r->bf == 1 || r->b10 == 1)) {
            FUN_a0073044(s_a0066498, n);
            FUN_a006fbac(x, n, buf);
            FUN_a006fad4(map[i * 2 + 1], 0, buf, 4);
            if (r->b10 == 1) {
                FUN_a006fc58(i);
                r->b10 = 0;
            }
            r->bf = 0;
        }
    }
    FUN_a006faa8(0, 2, &w52, 1);
    DAT_a80788d3 = *(unsigned char *)&w52;
    w56 = 0;
    FUN_a006faa8(0, 3, &w56, 1);
    w56 &= 0xffff00ff;
    w56 |= FUN_a0083e28() << 8;
    FUN_a006fad4(0, 3, &w56, 1);
    FUN_a006fedc();
    w60 = 0;
    FUN_a006faa8(0, 3, &w60, 1);
    {
        unsigned char c = DAT_a80788d2;
        unsigned int w = w60;
        unsigned char d = c & ~DAT_a80788dd;
        unsigned int lo = c & 0x3f;
        w &= ~0xff;
        DAT_a80788d2 = d;
        w60 = w | lo;
    }
    w60 |= (FUN_a0088f84() & 3) << 6;
    if (DAT_a80788d2 != 0) {
        FUN_a0073044(s_a00664b0, DAT_a80788d2);
        if (w60 & 0x10) { func_0x9f1cc264(0); func_0x9f1cc0a8(); }
        if (w60 & 0x20) { func_0x9f1cc264(1); func_0x9f1cc0a8(); }
    }
    FUN_a006fad4(0, 3, &w60, 1);
    DAT_a80788e0 &= ~6;
    DAT_a80788e0 |= (func_0x9f1c3efc() & 3) * 2;
    FUN_a006fad4(0, 0, &DAT_a80788e0, 1);
    types = 0;
    {
        unsigned char cnt = 7;
        for (i = 0; i < cnt; i++)
            types |= (DAT_a807a824[i].b0 & 0xf) << (i * 4);
    }
    DAT_a80788e0 = (DAT_a80788e0 & 0xf) | types << 4;
    FUN_a006fad4(0, 0, &DAT_a80788e0, 1);
}
