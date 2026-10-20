/* leon2m unit: FUN_a00d3d30 @ 0xa00d3d30 + FUN_a00d6054 @ 0xa00d6054 APP_ConfigDispSize (hand), both BYTE-EXACT.
 * Status: FUN_a00d6054 rawcmp 0/1623 ('-mcpu=v8 -O3 -g' and -msoft-float), FUN_a00d3d30 rawcmp 0/35, -Wall -W clean.
 *   jf 99.00 match=False only from the exact() link step: 'memcpy' (gcc block-move libcall; fw memcpy =
 *   FUN_a013c910) has no firmware address, and .rodata.str1.8 / .rodata (strings at file 0x2a0768, tb init) are
 *   not inside parts/leon2m.bin. Judge gap, not code.
 * Unit context (real file context, no dummy objects):
 *   - FUN_a00d3d30 (35 insns) is the real neighbour compiled before FUN_a00d6054 in the same unit: it is the only
 *     text between the unit's first .rodata user (a00d3bb4) and a00d6054 that has .LLC constants (soft-float
 *     libcalls, so the unit is built -msoft-float). Image: its 6 floats 22,30,128,100,70,28 are the first
 *     .rodata.cst4 entries (0x198748.., 0x198744 = alignment padding, unreferenced); the two printf strings of this
 *     file are the first .rodata.str1.8 entries (0x198768, 0x198798); tb is the last object of the unit's plain
 *     .rodata (0x198720). The cc1 output order of this file is the same: cst4 22,30,128,100,70,28 / str1.8
 *     APP_ConfigDispSize, height / .rodata tb.
 *   - gcc 3.4 const_labelno: a00d3d30's expansion uses .LLC0-.LLC12 (6 pool entries output), so the first string is
 *     .LLC13 and tb = .LLC14 (fw window .LLC10-29) -> gcse PRE makes the fp-48 pseudo before HIGH(tb) -> fw
 *     'sethi %hi(tb),%l5; add %fp,-48,%l4' in all 7 tb copies.
 *   - The printf strings are literals (as in the fw: they live in the unit's merged .rodata.str1.8).
 * Source forms of FUN_a00d6054 that the firmware bytes require (all value-identical):
 *   - D434 case 4/8 fit arm: 'h = pH;' before 'oh = inH;' (fw 0xe28 'sth h' before 'mov %i3,%l2'), and oh = inH
 *     before ow = inW (fw a00d6e80 'mov %i3,%l2' right after the sth [fp-76], before the two clrh).
 *   - inW declared before inH ('unsigned short inW, inH, pW, pH;'), and 'outR = w * 100 / h;' written before
 *     'inR = inW * 100 / inH;' (independent statements): the inW<<16 PRE pseudo then ties with inH<<16 at priority
 *     75 and the lower allocno inW<<16 gets %l7, inH<<16 %i5, as fw a00d6150/a00d6164.
 *   - The 7 helper tables ta are 'unsigned short ta[3][3]' (no record CLOBBERs; the decl mem attrs give the fw order
 *     'all constants, ldub b1f, 9 ta stores, cmp' at every table block; .h/.v/.f = [0]/[1]/[2]).
 *   - ar_hmode reads the input size through the inline helper in_size(port, &iw, &ih) (pointer outputs, same calls
 *     and values). Its ADDRESSOF copies survive cse1 and are deleted before global-alloc, so the PRE hash table
 *     gets the fw size (max_cuid 2395, (n/4)|1 = 599) -> fw 'sethi %hi(tb),%l5; add %fp,-48,%l4' order in all 7 tb
 *     copies. (The same helper in FUN_a00d6054 itself changes the case-2 'inH == 0 || inW == 0' code.)
 *   - ar_h: natural case order 0, 1, 2, 3 and 'if (b != 0) { switch } else v = tb[b1a4].h;'. The fw renames the 12
 *     ar_h copy-1 chains from the same LRU pool in the block order case 0, 1, 2, 3, tb last.
 *   - Case-group orders (each moved group ends in break): ar_v1 switch(port) 'case 0: + default:' first, then 1, 2,
 *     3 (the bb164 'b == 1 || b == 4' renames match the fw); disp_base_size port-1 inner switch 'case 3: break;'
 *     after 'case 6:'.
 *   - Fine-offset block (w00 & 0x20): 'w = pW; h = pH; ow = pW; ow += b3a; oh = pH; oh += b3c; xo = ..; yo = ..;'
 *     (fold puts the decl operand of 'pW + b3a' second; the fw adds 'pW, b3a'). Block 0x410-0x44c byte-equal.
 *   - D434 switch(b1a4) in ascending case order 0, 1, 4/8, 5, 6, 9, default. The cases compute the offsets from the
 *     just-assigned w/h/ow/oh like the sub-window path: case 0 'h = pH;' before the 'ow > pW' cap and
 *     'xo = (w - ow) >> 1;'; cases 1 and 9 'h = pH; w = pW; xo = (w - ow) >> 1;' (the two identical bodies must stay
 *     identical); case 4/8 'xo = (w - inW) >> 1; yo = (h - inH) >> 1;' with the test 'inW > pW || inH > pH' like
 *     cases 5/6; cases 5/6 'xo = (w - ow) >> 1; yo = (h - oh) >> 1;' (case 5 w before h). Fw: the out[] w copy
 *     'mov %l6,%o2' comes before the shifts and pW's register is reused.
 * Compiler aids (code-free; every aid line is marked '/ * aid * /'):
 *   'do continue; while (0);' = PRED_CONTINUE (taken 56 %), 'goto L; L: ;' = PRED_GOTO (not taken 70 %); stacks of
 *   both set the branch probability of one edge. Identical-body helper copies (ar_mode1, ar_h2, ar_v1) give one
 *   inline copy its own branch weights. Effects on the bb-reorder trace (code facts, gdb fibheap key probe):
 *   - ar_v1 case 2 entry: "goto s0" + 3 continues: bb169 113 -> 103 (block 0x14b4, bb282 first).
 *   - ar_v1 "default:": 5 gotos + 17 continues (near-cancelling, 7:2 lattice): bb159 91 -> 90, so bb30 (91) is taken
 *     before it (0x14d4); bb169 stays 103.
 *   - ar_h2 = identical-body copy of ar_h used ONLY by the ar_hmode case-2 arm (copy B; ar_h keeps the default arm,
 *     copy A). Stacks: ar_h2 case-1 entry (4 goto, 14 cont), case-1 before break (4 goto, 14 cont), case-1 then-arm
 *     (6 goto, 21 cont) and the ar_hmode "case 2:" call site (6 goto, 21 cont): bb304 (copy-B case-1 test) 90 -> 86
 *     (below bb168 87, block 0x1530), bb306 (else arm) 45 -> 44 (still before bb26 43) while bb305 (then arm, 43)
 *     stays the fall-through.
 *   - ar_mode1 = identical-body copy of ar_mode used ONLY by the scaling switch (copy 1; ar_mode keeps the printf
 *     use). "goto m3a" at ar_mode1 case 3: the bb135/bb219 tie (435/435) breaks copy 1 first (block 0x1238);
 *     (6 goto, 21 cont) in ar_mode1 case-1 then-arm: bb138 217 -> 220, before bb222 (0x141c); (1 goto, 3 cont)
 *     at ar_v case 3: 0x11ec, 0x14c0, 0x17f8-0x1808.
 *   - (6 goto, 21 cont) at ar_h (copy A) "case 2:" entry: bb190 (ar_v case 2) before bb284 (0x1790) and the
 *     single words 0x11e4/0x14a4.
 *   - The out[] store order and the xo/yo types and declaration order do not produce the 0x1924 tail; it needs the
 *     o pointer below.
 *   - Documented no-code aid (same class as the FUN_a0081ea8 dead test):
 *     'unsigned short *o; o = out + (port >> 8);' as the first statement, all 8 out[] stores written through o.
 *     Proof o == out: port is 'unsigned char' (0..255), so port >> 8 == 0 on every path; o is never changed.
 *     No code: combine folds port >> 8 to 0 (nonzero_bits), o and out share %i1, the copy is deleted after reload.
 *     Mechanism (code facts, gdb on the real cc1, alias.c 3.4.4): cse/gcse see 'o = out + s' (no copy, so cprop
 *     cannot fold o back into out; base of o = base of out, w/h PRE unchanged). combine merges the param copy
 *     'out = %i1' into o's insn, which lies AFTER NOTE_INSN_FUNCTION_BEG -> sched1's init_alias_analysis has
 *     copying_arguments false there -> find_base_value(%i1) = 0 -> reg_base_value[o] = 0 -> every o[] store
 *     may-alias the frame loads of x/y in sched1 ONLY (sched2: %i1 static arg base, known). That is the fw tail
 *     'lduh [fp-90] yo, [fp-78] x, [fp-80] y, [fp-82] xo; sth 7,0..6' (0x1924-0x192c).
 *     A plain 'o = out;' / '&out[0]' / int cast is folded by gcse cprop. record_set (3.4.4) kills a pointer's base
 *     on ANY second non-self set (no same-base check).
 *   - Tail order (independent statements): o[7], o[0], o[1], o[2], o[3], o[4], then y read into t before
 *     o[6] = xo, o[5] = t (with all stores may-alias in sched1 this keeps out[0] off the last slot: no 0x9d0 swap).
 */
extern unsigned char DAT_a802d29a;
unsigned char FUN_a00d3d30(void)
{
    unsigned char v = DAT_a802d29a;
    float f;
    if (v > 70)
        f = (float)(v - 70) * 22.0f / 30.0f + 128.0f;
    else
        f = (float)(int)v * 100.0f / 70.0f + 28.0f;
    return f;
}

/* leon2m FUN_a00d6054 @ 0xa00d6054  APP_ConfigDispSize (hand)
 *
 * Computes the display window of channel 'port' (0 = main, 1..3 = PIP/PBP sub windows) and writes 8 halfwords:
 *   out[0] ow, out[1] oh  = window size actually shown (after aspect handling)
 *   out[2] w,  out[3] h   = base window size (panel size, or the PIP/PBP share of it)
 *   out[4] x,  out[5] y   = position of the base window on the panel
 *   out[6] xo, out[7] yo  = offset of the shown window inside the base window
 * Inputs: input size inW/inH (FUN_a0145660 ids 7/8, or the panel size FUN_a014837c(0/1) when FUN_a0143c14(port) < 6),
 * panel size FUN_a014837c(0)/(1), config block DAT_a802d290 (0xA802D290):
 *   +0x00 word (bit 5 = fine offset mode), +0x1f u8 multi-window mode (0 = single), +0x2f u8 PBP split,
 *   +0x30 word (bits 0-3, 4-7 PIP position, 8-11, 12-15 aspect index, 16-23 PIP size), +0x34 word (aspect indexes
 *   of ports 1..3 in bits 20-23 / 24-27 / 28-31), +0x3a..+0x3d u8 fine offsets, +0x4b u8, +0x54/+0x56 u16 PIP x/y,
 *   +0x1a4 u8 main aspect setting (0xA802D434), +0x1f0 u16 custom PBP width.
 * Aspect tables (every lookup re-initialises them; they are locals of small helpers gcc inlined):
 *   tb[6] (rodata 0x198720) indexed by +0x1a4, ta[3] built on the stack, entries {h ratio, v ratio, flags} (10000 = 1.0).
 * Strings: 0x198768 "APP_ConfigDispSize_%d_bg : %d %d %d %d\r\n", 0x198798 "\x1b[1;35m(%d)height(%d) %d\r\n\x1b[m".
 * Flow (code facts, all checked against asm/leon2m/FUN_a00d6054.s):
 *   1. base size w,h (inlined disp_base_size; jump table 0x73A78 for port 1 x mode 0..7), base position x,y
 *      (inlined disp_base_pos; jump table 0x73A64 on +0x30 bits 4-7, 0..4), inR = inW*100/inH, outR = w*100/h, print.
 *   2. mode +0x1f > 1 and != 4: oh from ar_mode (1: inH*v, 2: w*inH/inW capped at h, else h*v; /10000 rounded),
 *      oh rounded down to a multiple of 4, print "height", oh capped at the panel height; ow from ar_hmode
 *      (1: w or oh*inW/inH, 2: oh*h ratio, else w*h ratio); xo/yo centre the window.
 *   3. port 0 in single/PIP mode: +0x00 bit 5 -> fine offsets; else switch on +0x1a4 (jump table 0x73A98):
 *      0 = input aspect at full height (width capped at the panel), 1/9 = 4:3 (pH*13333/10000), 4/8 = 1:1 when the
 *      input fits, 6 = 3296x1852 / 5 = 2992x1680 when the input fits, 2/3/7/>9 (and the 'does not fit' cases) = full panel.
 *   4. other ports in single/PIP mode: shown window = base window.
 * Source-shape facts (code facts vs the firmware):
 *   - disp_base_pos port-1 pos case 4 s==2: the y part goes through int copies ('int yy = y; int t1 =
 *     FUN_a014837c(1); FUN_a0145660(1, 4); t1 -= 0x21c; if (yy > t1)', same values and compare): fw a00d70f0
 *     zero-extends the first panel-height read BEFORE the FUN_a0145660 call (sll %o4 / srl %l0); a u16 keeps the
 *     raw value across the call ('mov %o0,%l3', one extra insn).
 *   - D434 case 4/8 'does not fit' arm is a second identical copy of the full-panel body ending in break (gcc
 *     cross-jumps it into the default block), not 'goto full': fw a00d6e58 'bne,a' with the full block's first
 *     insn 'mov %i4,%l2' in the annulled slot (predicted taken); 'goto full' is predicted not taken and dbr fills
 *     the slot from the fall-through (one insn less). Code-free compiler aid (identical-arm copy).
 *   - disp_base_pos port-1 pos case 4 is written through a local 'struct cfg290 *c = &DAT_a802d290;' with the s==1
 *     x part in plain x-form ('x = c->h54; ... if (x > ..) { x = ..; c->h54 = x; }'): the case-4 pointer gets %l2 as
 *     fw a00d7088 'or %l3,0x290,%l2'. Without the local pointer the s==1 y then-arm store gets a fresh sethi/or
 *     (1625 insns).
 *   - 'ow = w; oh = h;' is a default set right after the base position (fw keeps the w/h loaded for the print live
 *     in l0/l2 up to out[0]/out[1] of the port!=0 path, a00d625c); that pressure spills xo/yo/outR/inR like fw (frame 208).
 *   - ar_mode case 2 computes 'ow * inH / inW' (fw reuses zext(w) l3 across the print + memcpy calls, a00d6678);
 *     'r = oh & 3; if (r) oh -= r;' (fw andcc %l2,3,%g1 + sub, a00d6680).
 *   - ar_mode: 'r = 1' init, no default; ar_mode/ar_hmode test 'b != 0' first (fw puts every b==0 arm out of line).
 *   - outR declared before inR (fw slots outR -98, inR -106); the fit tests read 'inW > pW || inH > pH'.
 *   - disp_base_size port 0 has separate 'case 6:' and 'case 7:' bodies and port 2 separate 'case 5:' / 'case 7:'
 *     (fw a00d6cf4 'be 6' + 'cmp 7; b,a a00d69d4' into port 3's shared 'bne,a; sth; halve' block; grouped labels
 *     give a range test 'bg,a'); port 2 b1f==4 tests '(w30 & 0xf00) == 0 / == 0x100' (fw a00d64d4 andcc 0xf00).
 *   - ar_v/ar_h declare 'v = 10000' before the table initializers (fw a00d632c builds 0x2710 before the memcpy).
 *   - 'r' (oh remainder) is unsigned int (fw a00d6684: be; sll; sub %i2; sll; mov).
 *   - disp_base_pos port 2 switches on '(int)(w30 & 0xf)' (fw a00d7158 signed ble, like a promoted bit-field).
 *   - D434 case 0 cap 'if (ow > pW)' (fw a00d6ed0 cmp pW,ow; bcc); ar_hmode case 1 'inR > outR || oh < pH'
 *     (fw a00d69f8 compares the <<16 values directly).
 *   - disp_base_size port 1 'case 5:', 'case 6:', 'case 7:' are three separate identical halve bodies (gcc cross-jumps
 *     them; jump table 0x73A78 entries 5..7 all hit fw 0x769dc).
 *   - +0x30 is NOT read through bit-fields for bits 8-11: gcc 3.4 compiles 'field == 1' to srl 8; and 0xf; cmp 1,
 *     fw a00d64d4 has andcc 0xf00; cmp 0x100 (a union {word; bit-fields} compiles byte-identical to the masks).
 *   - fw jump-table target order (0x73A64 / 0x73A78 / 0x73A98): pos 3<2<1<0<4, port1 3<5/6/7<1/4<2<0,
 *     D434 full<1/9<4/8<0<6<5.
 *   - D434 'case 1:' and 'case 9:' are two separate identical 4:3 bodies (gcc cross-jumps them, jump table 0x73A98
 *     entries 1 and 9 hit one block as fw cac). The split gives the tablejump two equal-probability shares into the
 *     4:3 block, which changes the bb-reorder STC heap history; only then do the D434 blocks come out in the fw order
 *     full<1/9<4/8<0<6<5 (with grouped labels case 0 always comes last; fibheap replay).
 *   - disp_base_size port 1 'case 1:' and 'case 4:' are two separate identical bodies (gcc cross-jumps them fully,
 *     jump table 0x73A78 entries 1 and 4 hit one block, fw c08). Whether the merge is complete depends on the port-1
 *     case order (reload picks the sethi scratch of each copy; with a different order the copies use %o4 vs %o5 and
 *     do not merge: 1626 insns). The split gives the tablejump two shares into the 1/4 block.
 *   - ar_v is written TWICE as two inline helpers with the same statements: ar_v1 (used by the ar_mode 'default:'
 *     arm) and ar_v (used by 'case 1:'). One shared helper gives both inline copies the same port/b weights, but the
 *     fw block layout needs the copy-1 port-1 group weighted differently from copy 2 (code facts, -dB dumps). The
 *     copy-1 entry itself cannot be lowered by any note: it is fed by the ar_mode tree 154 'mode==1' (NONEQUAL x
 *     CALL, the copy entry holds the AR_TABLES memcpy) and 155 'mode==2' (51.2 %), pinned by the bb177 and case-2
 *     bb201 (620..~670) / bb202 (310..318) key windows (gdb fibheap probe), and any aid in the copy-1 'b == 0' arm
 *     flips the bbro trace at that 50 % test or changes the code (1619/1620 insns).
 * Branch-weight aids (code-free, marked '/ * aid * /'; see also the unit header above):
 *   - At the start of the ar_hmode b == 0 else block: 4x "goto wN; wN: ;" + 14x "do continue; while (0);"
 *     (PRED_GOTO 70 % not taken x4 + PRED_CONTINUE 56 % taken x14, Dempster-Shafer odds 0.4286^4 x 1.2727^14 = 0.978
 *     on the else edge: P(b != 0) 50 % -> 50.28 %). Effect (code facts, -dB): every ar_hmode switch block rises by
 *     1-3 (case-1 b==2 block 435 -> 438, the -224 / -244 blocks -> 225 / 245), so the round-4 fibheap no longer ties
 *     them with the two ar_mode copies (block 0x1204). Smaller stacks on the same lattice fail: (2 goto, 7 cont) =
 *     50.15 % gives a 0x12e8 move, (6, 21) = 50.42 % a 0x1560 one (gdb key probe: hmode +1 alone fixes the tie only
 *     with the copy-2 entry -1).
 *   - ar_v1 case 0 (the last case) falls into an explicit 'default:' that holds only an aid stack (default does
 *     nothing). Reason (code facts, -dB, predict.c process_note_prediction): the default block post-dominates the
 *     'port <= 1' side (bb159, port == 0 guard) but not the port 2/3 side, so its note head is bb158 (the switch-tree
 *     'cmp port,1; ble' with OPCODE_POSITIVE 79 %): DS 0.21 x goto 0.3 x continue^3 -> bb159 freq 101 -> 91, below
 *     bb30 (91, disp_base_size port-1 case 2 b2f==1 test) in the round-4 heap; bb167 (copy-1 port-1 entry) stays 173.
 *     This removes the 0x14d4/0x1530 block move; goto + 3 cont, 3 goto + 10 cont and 5 goto + 17 cont give the same
 *     .o; 1 goto alone breaks the layout.
 *   - 'default: do continue; while (0); break;' in the disp_base_pos (w30 >> 4) & 0xf switch (values 5-15 leave the
 *     switch either way): PRED_CONTINUE on its range check lowers the tablejump block that ties with the port-1 copy
 *     block, which puts the D434 case 0 block at the fw place.
 */

struct ar { unsigned short h, v, f; };

struct cfg290 {
    unsigned int w00;           /* +0x000 */
    unsigned char p04[0x1b];
    unsigned char b1f;          /* +0x01f 0xA802D2AF */
    unsigned char p20[0xf];
    unsigned char b2f;          /* +0x02f 0xA802D2BF */
    unsigned int w30;           /* +0x030 0xA802D2C0 */
    unsigned int w34;           /* +0x034 0xA802D2C4 */
    unsigned char p38[2];
    unsigned char b3a, b3b, b3c, b3d;   /* +0x03a..+0x03d */
    unsigned char p3e[0xd];
    unsigned char b4b;          /* +0x04b */
    unsigned char p4c[8];
    unsigned short h54, h56;    /* +0x054, +0x056 */
    unsigned char p58[0x14c];
    unsigned char b1a4;         /* +0x1a4 0xA802D434 */
    unsigned char p1a5[0x4b];
    unsigned short h1f0;        /* +0x1f0 0xA802D480 */
};

extern struct cfg290 DAT_a802d290;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a013c910");   /* gcc's block-copy libcalls go to the firmware memcpy FUN_a013c910 (asm-label declaration, no code) */
extern unsigned char FUN_a0143c14(unsigned char);
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern unsigned short FUN_a014837c(unsigned char);
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00844f8();

#define AR_TABLES \
    struct ar tb[6] = { {10000, 10000, 0}, {10000, 10000, 3}, {13333, 10000, 5}, {13333, 10000, 5}, \
                        {10000, 10000, 11}, {7500, 7500, 17} }; \
    unsigned short ta[3][3] = { {10000, 10000, 0x11}, {7500, 7500, 0x11}, {5000, 5000, 0x11} }

/* scaling mode of the window: bit 3 of the flags (bits 3-4 for the PBP split cases) */
static __inline__ unsigned char ar_mode(unsigned char port)
{
    struct ar tb[6] = { {10000, 10000, 0}, {10000, 10000, 3}, {13333, 10000, 5}, {13333, 10000, 5}, {10000, 10000, 11}, {7500, 7500, 17} };
    unsigned short ta[3][3];
    ta[0][0] = 10000; ta[0][1] = 10000; ta[0][2] = 0x11;
    ta[1][0] = 7500; ta[1][1] = 7500; ta[1][2] = 0x11;
    ta[2][0] = 5000; ta[2][1] = 5000; ta[2][2] = 0x11;
    unsigned char b = DAT_a802d290.b1f;
    unsigned char r = 1;

    if (b != 0) {
        switch (port) {
        case 0:
            if (DAT_a802d290.b1f == 2 || DAT_a802d290.b1f == 5 || DAT_a802d290.b1f == 6 || DAT_a802d290.b1f == 7) {
                if (DAT_a802d290.b1f == 2)
                    r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 3;
                else
                    r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 1;
            } else
                r = (tb[DAT_a802d290.b1a4].f >> 3) & 1;
            break;
        case 1:
            if (b == 1 || b == 4)
                r = (ta[(DAT_a802d290.w30 >> 16) & 0xff][2] >> 3) & 1;
            else if (b == 2 && ((unsigned char)(DAT_a802d290.b2f - 1) <= 1 ||
                                (DAT_a802d290.b2f == 0 && !(unsigned char)FUN_a00844f8())))
                r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 3;
            else
                r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 1;
            break;
        case 2:
            if (b == 4)
                { do continue; while (0); r = (ta[(DAT_a802d290.w30 >> 8) & 0xf][2] >> 3) & 1; }  /* aid */
            else
                { do continue; while (0); r = (ta[(DAT_a802d290.w34 >> 24) & 0xf][2] >> 3) & 1; }  /* aid */
            break;
        case 3:
            { do continue; while (0); r = (ta[(DAT_a802d290.w34 >> 20) & 0xf][2] >> 3) & 1; }  /* aid */
            break;
        }
    } else if (port == 0)
        r = (tb[DAT_a802d290.b1a4].f >> 3) & 1;
    return r & 3;
}

/* ar_mode1 = ar_mode for the scaling switch (identical body, see header) */
static __inline__ unsigned char ar_mode1(unsigned char port)
{
    struct ar tb[6] = { {10000, 10000, 0}, {10000, 10000, 3}, {13333, 10000, 5}, {13333, 10000, 5}, {10000, 10000, 11}, {7500, 7500, 17} };
    unsigned short ta[3][3];
    ta[0][0] = 10000; ta[0][1] = 10000; ta[0][2] = 0x11;
    ta[1][0] = 7500; ta[1][1] = 7500; ta[1][2] = 0x11;
    ta[2][0] = 5000; ta[2][1] = 5000; ta[2][2] = 0x11;
    unsigned char b = DAT_a802d290.b1f;
    unsigned char r = 1;

    if (b != 0) {
        switch (port) {
        case 0:
            if (DAT_a802d290.b1f == 2 || DAT_a802d290.b1f == 5 || DAT_a802d290.b1f == 6 || DAT_a802d290.b1f == 7) {
                if (DAT_a802d290.b1f == 2)
                    r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 3;
                else
                    r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 1;
            } else
                r = (tb[DAT_a802d290.b1a4].f >> 3) & 1;
            break;
        case 1:
            if (b == 1 || b == 4)
                { goto ma0; ma0: ; goto ma1; ma1: ; goto ma2; ma2: ; goto ma3; ma3: ; goto ma4; ma4: ; goto ma5; ma5: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); r = (ta[(DAT_a802d290.w30 >> 16) & 0xff][2] >> 3) & 1; }  /* aid */
            else if (b == 2 && ((unsigned char)(DAT_a802d290.b2f - 1) <= 1 ||
                                (DAT_a802d290.b2f == 0 && !(unsigned char)FUN_a00844f8())))
                r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 3;
            else
                r = (ta[(DAT_a802d290.w30 >> 12) & 0xf][2] >> 3) & 1;
            break;
        case 2:
            if (b == 4)
                { do continue; while (0); r = (ta[(DAT_a802d290.w30 >> 8) & 0xf][2] >> 3) & 1; }  /* aid */
            else
                { do continue; while (0); r = (ta[(DAT_a802d290.w34 >> 24) & 0xf][2] >> 3) & 1; }  /* aid */
            break;
        case 3:
            { goto m3a; m3a: ; }  /* aid */
            { do continue; while (0); r = (ta[(DAT_a802d290.w34 >> 20) & 0xf][2] >> 3) & 1; }  /* aid */
            break;
        }
    } else if (port == 0)
        r = (tb[DAT_a802d290.b1a4].f >> 3) & 1;
    return r & 3;
}

/* input size of the channel */
static __inline__ void in_size(unsigned char port, unsigned short *pw, unsigned short *ph)
{
    if (FUN_a0143c14(port) > 5) {
        *pw = FUN_a0145660(port, 7);
        *ph = FUN_a0145660(port, 8);
    } else {
        *pw = FUN_a014837c(0);
        *ph = FUN_a014837c(1);
    }
}

/* width scaling mode: bits 1-2 of the flags */
static __inline__ unsigned char ar_hmode(unsigned char port)
{
    AR_TABLES;
    unsigned short iw, ih;
    unsigned char b;
    unsigned char r = 0;

    in_size(port, &iw, &ih);
    b = DAT_a802d290.b1f;
    if (b != 0) {
        switch (port) {
        case 0:
            if (DAT_a802d290.b1f == 2 || DAT_a802d290.b1f == 5 || DAT_a802d290.b1f == 6 || DAT_a802d290.b1f == 7)
                r = 1;
            else
                r = (tb[DAT_a802d290.b1a4].f >> 1) & 3;
            break;
        case 1:
            if (b == 2)
                { do continue; while (0); r = 1; }  /* aid */
            else if (b == 1 || b == 4)
                r = (ta[(DAT_a802d290.w30 >> 16) & 0xff][2] >> 1) & 3;
            else
                r = (ta[DAT_a802d290.w34 >> 28][2] >> 1) & 3;
            break;
        case 2:
            if (b == 4)
                { do continue; while (0); r = (ta[(DAT_a802d290.w30 >> 8) & 0xf][2] >> 1) & 3; }  /* aid */
            else
                { do continue; while (0); r = (ta[(DAT_a802d290.w34 >> 24) & 0xf][2] >> 1) & 3; }  /* aid */
            break;
        case 3:
            r = (ta[(DAT_a802d290.w34 >> 20) & 0xf][2] >> 1) & 3;
            break;
        }
    } else {
        { goto w293_0; w293_0: ; goto w293_1; w293_1: ; goto w293_2; w293_2: ; goto w293_3; w293_3: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
        if (port == 0)
            r = (tb[DAT_a802d290.b1a4].f >> 1) & 3;
        else
            r = 1;
    }
    return r & 3;
}

/* vertical ratio (10000 = 1.0); ar_v1 = the same helper for the ar_mode default arm (case order / aid differ, see header) */
static __inline__ unsigned short ar_v1(unsigned char port)
{
    unsigned short v = 10000;
    AR_TABLES;
    unsigned char b = DAT_a802d290.b1f;

    if (b != 0) {
        switch (port) {
        case 0:
            if (b != 1 && b != 4)
                v = ta[(DAT_a802d290.w30 >> 12) & 0xf][1];
            else
                v = tb[DAT_a802d290.b1a4].v;
        default:
            { goto d0; d0: ; goto d1; d1: ; goto d2; d2: ; goto d3; d3: ; goto d4; d4: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
            break;
        case 1:
            if (b == 1 || b == 4)
                { do continue; while (0); v = ta[(DAT_a802d290.w30 >> 16) & 0xff][1]; }  /* aid */
            else
                { do continue; while (0); v = ta[DAT_a802d290.w34 >> 28][1]; }  /* aid */
            { do continue; while (0); do continue; while (0); do continue; while (0); goto g1; g1: ; break; }  /* aid */
        case 2:
            { goto s0; s0: ; do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
            if (b == 4)
                v = ta[(DAT_a802d290.w30 >> 8) & 0xf][1];
            else
                { do continue; while (0); v = ta[(DAT_a802d290.w34 >> 24) & 0xf][1]; }  /* aid */
            break;
        case 3:
            { do continue; while (0); v = ta[(DAT_a802d290.w34 >> 20) & 0xf][1]; }  /* aid */
            break;
        }
    } else
        v = tb[DAT_a802d290.b1a4].v;
    return v;
}

static __inline__ unsigned short ar_v(unsigned char port)
{
    unsigned short v = 10000;
    struct ar tb[6] = { {10000, 10000, 0}, {10000, 10000, 3}, {13333, 10000, 5}, {13333, 10000, 5}, {10000, 10000, 11}, {7500, 7500, 17} };
    unsigned short ta[3][3];
    ta[0][0] = 10000; ta[0][1] = 10000; ta[0][2] = 0x11;
    ta[1][0] = 7500; ta[1][1] = 7500; ta[1][2] = 0x11;
    ta[2][0] = 5000; ta[2][1] = 5000; ta[2][2] = 0x11;
    unsigned char b = DAT_a802d290.b1f;

    if (b != 0) {
        switch (port) {
        case 0:
            if (b != 1 && b != 4)
                v = ta[(DAT_a802d290.w30 >> 12) & 0xf][1];
            else
                v = tb[DAT_a802d290.b1a4].v;
            break;
        case 1:
            if (b == 1 || b == 4)
                v = ta[(DAT_a802d290.w30 >> 16) & 0xff][1];
            else
                v = ta[DAT_a802d290.w34 >> 28][1];
            break;
        case 2:
            if (b == 4)
                v = ta[(DAT_a802d290.w30 >> 8) & 0xf][1];
            else
                v = ta[(DAT_a802d290.w34 >> 24) & 0xf][1];
            break;
        case 3:
            { goto v3a; v3a: ; do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
            v = ta[(DAT_a802d290.w34 >> 20) & 0xf][1];
            break;
        }
    } else
        v = tb[DAT_a802d290.b1a4].v;
    return v;
}

/* horizontal ratio (10000 = 1.0) */
static __inline__ unsigned short ar_h(unsigned char port)
{
    unsigned short v = 10000;
    AR_TABLES;
    unsigned char b = DAT_a802d290.b1f;

    if (b != 0) {
        switch (port) {
        case 0:
            if (b != 1 && b != 4)
                v = ta[(DAT_a802d290.w30 >> 12) & 0xf][0];
            else
                v = tb[DAT_a802d290.b1a4].h;
            break;
        case 1:
            if (b == 1 || b == 4)
                v = ta[(DAT_a802d290.w30 >> 16) & 0xff][0];
            else
                v = ta[DAT_a802d290.w34 >> 28][0];
            break;
        case 2:
            { goto hc0; hc0: ; goto hc1; hc1: ; goto hc2; hc2: ; goto hc3; hc3: ; goto hc4; hc4: ; goto hc5; hc5: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
            if (b == 4)
                v = ta[(DAT_a802d290.w30 >> 8) & 0xf][0];
            else
                v = ta[(DAT_a802d290.w34 >> 24) & 0xf][0];
            break;
        case 3:
            v = ta[(DAT_a802d290.w34 >> 20) & 0xf][0];
            break;
        }
    } else
        v = tb[DAT_a802d290.b1a4].h;
    return v;
}

/* ar_h2 = ar_h for the ar_hmode case-2 use (identical body, see header) */
static __inline__ unsigned short ar_h2(unsigned char port)
{
    unsigned short v = 10000;
    AR_TABLES;
    unsigned char b = DAT_a802d290.b1f;

    if (b != 0) {
        switch (port) {
        case 0:
            if (b != 1 && b != 4)
                v = ta[(DAT_a802d290.w30 >> 12) & 0xf][0];
            else
                v = tb[DAT_a802d290.b1a4].h;
            break;
        case 1:
            { goto h0; h0: ; goto h1; h1: ; goto h2; h2: ; goto h3; h3: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
            if (b == 1 || b == 4)
                { goto u0; u0: ; goto u1; u1: ; goto u2; u2: ; goto u3; u3: ; goto u4; u4: ; goto u5; u5: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); v = ta[(DAT_a802d290.w30 >> 16) & 0xff][0]; }  /* aid */
            else
                v = ta[DAT_a802d290.w34 >> 28][0];
            { goto j0; j0: ; goto j1; j1: ; goto j2; j2: ; goto j3; j3: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
            break;
        case 2:
            if (b == 4)
                v = ta[(DAT_a802d290.w30 >> 8) & 0xf][0];
            else
                v = ta[(DAT_a802d290.w34 >> 24) & 0xf][0];
            break;
        case 3:
            v = ta[(DAT_a802d290.w34 >> 20) & 0xf][0];
            break;
        }
    } else
        v = tb[DAT_a802d290.b1a4].h;
    return v;
}

/* base window size of the channel (PIP / PBP share of the panel) */
static __inline__ void disp_base_size(unsigned char port, unsigned short *pw_out, unsigned short *ph_out)
{
    unsigned short w, h;
    unsigned char s;
    unsigned int r15;

    w = FUN_a014837c(0);
    h = FUN_a014837c(1);
    switch (port) {
    case 0:
        switch (DAT_a802d290.b1f) {
        case 2:
            if (DAT_a802d290.b2f == 0)
                w = ((w * 3) >> 5) << 3;
            else if (DAT_a802d290.b2f == 1)
                w = (w >> 4) << 3;
            else if (DAT_a802d290.b2f == 2)
                w = DAT_a802d290.h1f0;
            else
                w = w >> 1;
            break;
        case 5:
            w = w >> 1;
            break;
        case 6:
            w = w >> 1;
            h = h >> 1;
            break;
        case 7:
            w = w >> 1;
            h = h >> 1;
            break;
        }
        break;
    case 1:
        switch (DAT_a802d290.b1f) {
        case 0:
            if (DAT_a802d290.b4b == 0) {
                w = FUN_a014837c(1) >> 2;
                h = FUN_a014837c(1) >> 2;
            } else if (DAT_a802d290.b4b == 1) {
                { do continue; while (0); w = FUN_a014837c(1) / 3; }  /* aid */
                h = FUN_a014837c(1) / 3;
            } else {
                w = FUN_a014837c(1) >> 1;
                h = FUN_a014837c(1) >> 1;
            }
            break;
        case 1:
            s = (DAT_a802d290.w30 >> 16) & 0xff;
            if (s == 0) {
                w = 0x6c0;
                h = 0x3cc;
            } else if (s == 1) {
                w = 0x540;
                h = 0x2f4;
            } else if (s == 2) {
                FUN_a0145660(1, 4);
                w = 0x3c0;
                h = 0x21c;
            } else {
                r15 = s * 15;
                h = s * 8 + 0x137;
                w = (r15 + 0x228) & ~1;
            }
            break;
        case 2:
            if (DAT_a802d290.b2f == 0)
                w = (w >> 5) << 3;
            else if (DAT_a802d290.b2f == 1)
                { do continue; while (0); w = (w >> 4) << 3; }  /* aid */
            else if (DAT_a802d290.b2f == 2)
                w = w - DAT_a802d290.h1f0;
            else
                w = w >> 1;
            break;
        case 5:
            w = w >> 1;
            h = h >> 1;
            break;
        case 6:
            w = w >> 1;
            h = h >> 1;
            break;
        case 3:
            break;
        case 7:
            w = w >> 1;
            h = h >> 1;
            break;
        case 4:
            s = (DAT_a802d290.w30 >> 16) & 0xff;
            if (s == 0) {
                w = 0x6c0;
                h = 0x3cc;
            } else if (s == 1) {
                w = 0x540;
                h = 0x2f4;
            } else if (s == 2) {
                FUN_a0145660(1, 4);
                w = 0x3c0;
                h = 0x21c;
            } else {
                r15 = s * 15;
                h = s * 8 + 0x137;
                w = (r15 + 0x228) & ~1;
            }
            break;
        }
        break;
    case 2:
        switch (DAT_a802d290.b1f) {
        case 4:
            if ((DAT_a802d290.w30 & 0xf00) == 0) {
                w = 0x6c0;
                h = 0x3cc;
            } else if ((DAT_a802d290.w30 & 0xf00) == 0x100) {
                w = 0x540;
                h = 0x2f4;
            } else {
                FUN_a0145660(1, 4);
                w = 0x3c0;
                h = 0x21c;
            }
            break;
        case 5:
            w = w >> 1;
            h = h >> 1;
            break;
        case 6:
            w = w >> 1;
            break;
        case 7:
            w = w >> 1;
            h = h >> 1;
            break;
        }
        break;
    case 3:
        if (DAT_a802d290.b1f == 7) {
            w = w >> 1;
            h = h >> 1;
        }
        break;
    }

    *pw_out = w;
    *ph_out = h;
}

/* base window position of the channel */
static __inline__ void disp_base_pos(unsigned char port, unsigned short w, unsigned short h,
                                     unsigned short *px, unsigned short *py)
{
    unsigned short pw, ph, x, y, t;
    unsigned char s;

    pw = FUN_a014837c(0);
    ph = FUN_a014837c(1);
    x = 0;
    y = 0;
    switch (port) {
    case 0:
        x = 0;
        break;
    case 1:
        if (DAT_a802d290.b1f == 0) {
            x = (pw - w) / 2;
            y = (ph - h) / 2;
        } else if (DAT_a802d290.b1f == 1 || DAT_a802d290.b1f == 4) {
            switch ((DAT_a802d290.w30 >> 4) & 0xf) {
            case 4:
                {
                struct cfg290 *c = &DAT_a802d290;
                s = (c->w30 >> 16) & 0xff;
                if (s == 0) {
                    x = c->h54;
                    y = c->h56;
                    if (x > FUN_a014837c(0) - 0x6c0) {
                        x = FUN_a014837c(0) - 0x6c0;
                        c->h54 = x;
                    }
                    if (y > FUN_a014837c(1) - 0x3cc) {
                        y = FUN_a014837c(1) - 0x3cc;
                        c->h56 = y;
                    }
                } else if (s == 1) {
                    x = c->h54;
                    y = c->h56;
                    if (x > FUN_a014837c(0) - 0x540) {
                        x = FUN_a014837c(0) - 0x540;
                        c->h54 = x;
                    }
                    if (y > FUN_a014837c(1) - 0x2f4) {
                        y = FUN_a014837c(1) - 0x2f4;
                        c->h56 = y;
                    }
                } else if (s == 2) {
                    x = c->h54;
                    y = c->h56;
                    if (x > FUN_a014837c(0) - 0x3c0) {
                        x = FUN_a014837c(0) - 0x3c0;
                        c->h54 = x;
                    }
                    {
                        int yy = y;
                        int t1 = FUN_a014837c(1);
                        FUN_a0145660(1, 4);
                        t1 -= 0x21c;
                        if (yy > t1) {
                            t = FUN_a014837c(1);
                            FUN_a0145660(1, 4);
                            y = t - 0x21c;
                            c->h56 = y;
                        }
                    }
                }
                }
                break;
            case 1:
                x = pw - w;
                y = 0;
                break;
            case 2:
                x = 0;
                s = (DAT_a802d290.w30 >> 16) & 0xff;
                if (s == 0)
                    y = ph - 0x3cc;
                else if (s == 1)
                    y = ph - 0x2f4;
                else {
                    FUN_a0145660(1, 4);
                    y = ph - 0x21c;
                }
                break;
            case 3:
                x = pw - w;
                s = (DAT_a802d290.w30 >> 16) & 0xff;
                if (s == 0)
                    y = ph - 0x3cc;
                else if (s == 1)
                    y = ph - 0x2f4;
                else {
                    FUN_a0145660(1, 4);
                    y = ph - 0x21c;
                }
                break;
            case 0:
                x = 0;
                y = 0;
                break;
            default:  do continue; while (0);  /* aid */
                break;
            }
        } else if (DAT_a802d290.b1f == 2 || DAT_a802d290.b1f == 5) {
            if (DAT_a802d290.b2f == 0)
                { do continue; while (0); do continue; while (0); x = ((pw * 3) >> 5) << 3; }  /* aid */
            else if (DAT_a802d290.b2f == 1)
                x = pw >> 1;
            else if (DAT_a802d290.b2f == 2)
                x = DAT_a802d290.h1f0;
            else
                x = pw >> 1;
            { do continue; while (0); y = 0; }  /* aid */
        } else if (DAT_a802d290.b1f == 6 || DAT_a802d290.b1f == 7) {
            x = 0;
            y = ph >> 1;
        }
        break;
    case 2:
        if (DAT_a802d290.b1f == 4) {
            switch ((int)(DAT_a802d290.w30 & 0xf)) {
            case 0:
                x = 0;
                break;
            case 1:
                x = (w > (pw >> 1)) ? pw - w : pw >> 1;
                y = 0;
                break;
            case 2:
                x = 0;
                y = (h > (ph >> 1)) ? ph - h : ph >> 1;
                break;
            case 3:
                x = (w > (pw >> 1)) ? pw - w : pw >> 1;
                y = (h > (ph >> 1)) ? ph - h : ph >> 1;
                break;
            }
        } else if (DAT_a802d290.b1f == 5) {
            { do continue; while (0); x = pw >> 1; }  /* aid */
            y = ph >> 1;
        } else if (DAT_a802d290.b1f == 6 || DAT_a802d290.b1f == 7) {
            x = pw >> 1;
        }
        break;
    case 3:
        if (DAT_a802d290.b1f == 7) {
            { goto aid2; aid2: ; x = pw >> 1; }  /* aid */
            y = ph >> 1;
        }
        break;
    }

    *px = x;
    *py = y;
}

void FUN_a00d6054(unsigned char port, unsigned short *out)
{
    unsigned short inW, inH, pW, pH;
    unsigned short w = 0, h = 0, x = 0, y = 0, xo = 0, yo = 0;
    unsigned short ow, oh, outR, inR;
    unsigned int r;   /* r: remainder of oh / 4 */
    unsigned short *o;

    o = out + (port >> 8);   /* aid: == out, port is unsigned char; see header */
    if (FUN_a0143c14(port) > 5) {
        inW = FUN_a0145660(port, 7);
        inH = FUN_a0145660(port, 8);
    } else {
        inW = FUN_a014837c(0);
        inH = FUN_a014837c(1);
    }
    pW = FUN_a014837c(0);
    pH = FUN_a014837c(1);
    disp_base_size(port, &w, &h);
    disp_base_pos(port, w, h, &x, &y);

    ow = w;
    oh = h;
    outR = (unsigned int)(w * 100) / h;
    inR = (unsigned int)(inW * 100) / inH;
    FUN_a00df170("APP_ConfigDispSize_%d_bg : %d %d %d %d\r\n", port, w, h, x, y);

    if (DAT_a802d290.b1f > 1 && DAT_a802d290.b1f != 4) {
        /* sub-window modes: scale by the aspect tables */
        switch (ar_mode1(port)) {
        default:
            oh = (unsigned int)(h * ar_v1(port) + 5000) / 10000;
            break;
        case 1:
            oh = (unsigned int)(inH * ar_v(port) + 5000) / 10000;
            break;
        case 2:
            if (inH == 0 || inW == 0)
                oh = h;
            else {
                oh = (unsigned int)(ow * inH) / inW;
                if (oh > h)
                    oh = h;
            }
            break;
        }
        r = oh & 3;
        if (r)
            oh -= r;
        FUN_a00df170("\x1b[1;35m(%d)height(%d) %d\r\n\x1b[m", port, ar_mode(port), oh);
        if (oh > pH)
            oh = pH;
        switch (ar_hmode(port)) {
        default:
            ow = (unsigned int)(w * ar_h(port) + 5000) / 10000;
            break;
        case 1:
            if (inR > outR || oh < pH)
                ow = w;
            else
                ow = (unsigned int)(oh * inW) / inH;
            break;
        case 2:
            { goto c0; c0: ; goto c1; c1: ; goto c2; c2: ; goto c3; c3: ; goto c4; c4: ; goto c5; c5: ; do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); do continue; while (0); }  /* aid */
            ow = (unsigned int)(oh * ar_h2(port) + 5000) / 10000;
            break;
        }
        xo = (w - ow) >> 1;
        yo = (h - oh) >> 1;
    } else if (port == 0) {
        if (DAT_a802d290.w00 & 0x20) {
            w = pW;
            h = pH;
            ow = pW;
            ow += DAT_a802d290.b3a;
            oh = pH;
            oh += DAT_a802d290.b3c;
            xo = (3 - DAT_a802d290.b3b) * 8;
            yo = 3 - DAT_a802d290.b3d;
        } else {
            switch (DAT_a802d290.b1a4) {
            case 0:     /* keep the input aspect, full height */
                oh = pH;
                ow = (unsigned int)(pH * inW) / inH;
                h = pH;
                if (ow > pW)
                    ow = pW;
                w = pW;
                x = 0;
                y = 0;
                xo = (w - ow) >> 1;
                yo = 0;
                break;
            case 1:     /* 4:3 */
                oh = pH;
                ow = (unsigned int)(pH * 13333 + 5000) / 10000;
                h = pH;
                w = pW;
                xo = (w - ow) >> 1;
                x = 0;
                y = 0;
                yo = 0;
                break;
            case 4:     /* 1:1 when the input fits */
            case 8:
                if (inW > pW || inH > pH) {
                    ow = pW;
                    oh = pH;
                    w = pW;
                    h = pH;
                    x = 0;
                    y = 0;
                    xo = 0;
                    yo = 0;
                    break;
                }
                h = pH;
                oh = inH;
                w = pW;
                x = 0;
                y = 0;
                ow = inW;
                xo = (w - inW) >> 1;
                yo = (h - inH) >> 1;
                break;
            case 5:
                if (inW > pW || inH > pH)
                    goto full;
                ow = 0xbb0;
                oh = 0x690;
                w = pW;
                h = pH;
                x = 0;
                y = 0;
                xo = (w - ow) >> 1;
                yo = (h - oh) >> 1;
                break;
            case 6:
                if (inW > pW || inH > pH)
                    goto full;
                ow = 0xce0;
                oh = 0x73c;
                w = pW;
                h = pH;
                x = 0;
                y = 0;
                xo = (w - ow) >> 1;
                yo = (h - oh) >> 1;
                break;
            case 9:
                oh = pH;
                ow = (unsigned int)(pH * 13333 + 5000) / 10000;
                h = pH;
                w = pW;
                xo = (w - ow) >> 1;
                x = 0;
                y = 0;
                yo = 0;
                break;
            default:    /* 2, 3, 7, > 9: full panel */
            full:
                ow = pW;
                oh = pH;
                w = pW;
                h = pH;
                x = 0;
                y = 0;
                xo = 0;
                yo = 0;
                break;
            }
        }
    }
    o[7] = yo;
    o[0] = ow;
    o[1] = oh;
    o[2] = w;
    o[3] = h;
    o[4] = x;
    {
        unsigned short t = y;
        o[6] = xo;
        o[5] = t;
    }
}
