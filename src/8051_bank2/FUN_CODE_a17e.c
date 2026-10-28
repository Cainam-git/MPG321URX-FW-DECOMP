/* 8051_bank2 UPDATER MODULE (af07 module: update-medium directory walk, file copy, record reader), hand.
 * ONE Keil C51 module, options OPTIMIZE(8,SPEED) LARGE.
 * It is one file because Keil builds the common-entry blocks in front of af07, 72b0, bf1b and df50 from the call
 * sites it sees in the module (see "Common-entry chains" below); every caller that enters a chain is in this file.
 * All code in this file is real firmware C: NO synthetic callers, NO stub bodies (SYN_A..SYN_G and the 72b0 / bf1b /
 * df50 stubs are gone; documented no-code aids are listed below).
 *
 * Members of this module (bytes; a common-entry block in front where noted):
 *   FUN_CODE_a17e  494 B;  FUN_CODE_9235  670 B;  FUN_CODE_aa43  395 B;  FUN_CODE_9d97  504 B;
 *   FUN_CODE_bdbd  266 B;  FUN_CODE_af07  46 + 317 B (block 0xaed9..0xaf06);  FUN_CODE_3e68  2070 B;
 *   FUN_CODE_bf1b  69 + 195 B (block 0xbec7..0xbf1a);  FUN_CODE_df50  35 + 38 B (block 0xdf2d..0xdf4f; functions.json
 *   has df44 = 0xdf44..0xdf76, the C function starts at 0xdf50);  FUN_CODE_813c  763 B;  FUN_CODE_b84b  303 B
 *   ('x0152 += x0105' is written in BOTH arms; Keil cross-jumps the two arm tails and keeps the firmware's
 *   'LCALL ?C?LSTXDATA; RET', one shared += after the if/else gives LJMP);  FUN_CODE_1000  3669 B (to 0x1e55);
 *   FUN_CODE_872e  730 B;  FUN_CODE_72b0  78 + 967 B (chain 0x7262..0x72af; functions.json has 72a5 =
 *   0x72a5..0x7677, the C function starts at 0x72b0);  FUN_CODE_1e55  3359 B (to 0x2b74).
 *   The extra 72b0 chain level L?0220 is removed with a no-code aid in 1e55's two loop tails (see 'Loop tails').
 *   FUN_CODE_1234 / 13c8 / 13eb / 140a / 140d are pieces inside FUN_CODE_1000, 2342 / 272d pieces inside 1e55,
 *   7262 / 7263 / 72a5, bec7 / bf0c / bf10 / bf15, df2d / df44, aed9..af03 are common-entry block pieces.
 *
 * What the functions do:
 *   bdbd: run-length walk over the record buffer, af07 per byte. a17e / 9d97: mode 041c == 2 tag walk to 0x80,
 *   813c(sum); else read the block at (041d - 2) * 01dc + 0405 + 0105 + 0421 (9d97 adds 3e68(), a547(), returns
 *   a local bit). 9235 / aa43: record tag walks + bdbd / af07 seeks. af07: seek (addr += off / size, off %= size,
 *   read the block when not cached).
 *   3e68: copy the selected file (start cluster 03e6, size 0109) via d6d1(sector, bytes, dst) in <= 0x4000-byte
 *   pieces; FAT chain walk joining consecutive clusters; bit 0x0D = contiguous file.
 *   bf1b: little-endian value of n bytes. df50: 041d / 0421 / 0425 = position of the current entry.
 *   72b0: FAT cluster-chain step (next sector / next cluster, printf "DataCluster = 0x%8lx", 0x0FFFFFFF = end).
 *   813c: take the file of the directory entry at e: x03e6 = first cluster, x0109 = size, x0401 = first sector,
 *   bit 0x0D = contiguous (exFAT flags bit 1). b84b: first sector of the entry at e -> x0152. Both enter the bf1b
 *   chain at bf15 (L? labels are module-local, so they must be members). In b84b the '041c == 1' test is written
 *   '!(DAT_EXTMEM_041c ^ 1)': the fw has XRL #1 / MOV DPTR / JNZ, '== 1' gives CJNE.
 *   872e: ".IMG" test of an exFAT name with entry / sector boundary handling (called by 1000).
 *   1000: the 'E' twin of 1e55 that lists only *.IMG entries (filters 872e / 4e8e / "IMG").
 *   FUN_CODE_1e55 (real function 0x1e55..0x2b74 = 3359 B; functions.json cuts it at 0x2342, the pieces
 *   FUN_CODE_2342 / FUN_CODE_272d are inside it): list the next directory entry of the update medium and print its
 *   name with printf("%s\r\n", 0x011D) (FUN_CODE_65ab = C51 library printf, format string CODE 0xE0A3).
 *     bit 0x0C set (end of directory) -> return 0. Clear the 0x2d-byte name buffer 0x011D.
 *     x041c == 1 (exFAT): read the directory sector, walk the 0x20-byte entries at x0150: 0 -> return 0; 0x85 (File
 *       entry) -> open the stream / name entries with 72b0(), copy 15 UTF-16 chars per name entry (max 3 entries),
 *       printf, skip the entry set, next-entry call, x0409++, return 1; other types -> next entry (x0150 += 0x20).
 *     x041c == 2 (FAT32-style records): af07(03ee, 040a) seek; once (bit 0x0B) call 9235() when the two longs at
 *       the cursor are 0; when they are 0 again step 042c (next cluster: 010d = c89e(042c), 010f = sum of c7c5(i))
 *       and redo 9235's last seek; then when the record is valid: 040c = its long, tag walk to 0x30, 2*n + 0x18,
 *       +0x40, +2, copy n name chars (max 0x2d), printf, x0409++, x040a += record length, af07, return 1;
 *       otherwise bit 0x0C = 1, return 0.
 *     else (FAT12/16): directory walk: 0 -> return 0; 0xE5 (deleted) -> next; attribute 0x0F (VFAT LFN) -> walk the
 *       LFN entries backwards (count = first byte & 0x3f) copying 5 + 6 + 2 UTF-16 chars each (max 3), printf;
 *       short name -> copy the 11 name bytes without blanks, printf; both: skip, next-entry call, x0409++, return 1.
 *   Loop tails: the two end-of-loop 'x0150 += 0x20' statements (fw 0x2208, 0x2b52, 14 B each) keep their
 *     code inline + LCALL 7263 in the fw. Written plainly, Keil folds both into the 72b0 chain as a 13-B head
 *     (extra level L?0220 in front of 0x7262). They are written as 'if (DAT_BIT_000c) x0150 += 0x20; else
 *     x0150 += 0x20;' (documented no-code aid, no new object: bit 0x0C is the real loop bit). Keil cross-jumps the
 *     two equal arms, then drops the bit test (its jump goes to the next instruction), so NO code is left of it;
 *     the if/else join label stays at the call while the common-entry pass runs, and a label at the call stops
 *     the chain absorption. Measured on a minimal test module, variant 'F'
 *     (g1 = base + 14 B, loop site enters at the args label); an xdata test instead of a bit leaves 4 B.
 * Common-entry chains (Keil OPTIMIZE(8) "reuse of common entry code"; each chain lives in front of its callee, so
 * every caller that enters a chain is in this module):
 *   0xaed9..0xaf06 -> af07.
 *   0x7262 (MOVX) + 0x7263..0x72a4 (args x0414, x0429.n, x0150, x01de, x0410) + 0x72a5..0x72af (load long @DPTR)
 *     -> bit FUN_CODE_72b0(long a, char n, int p, long b, long c) at 0x72b0. 7263 / 72a5 are NOT functions.
 *   0xbec7..0xbf08 + bf09 + bf0c/bf10/bf15 -> unsigned long FUN_CODE_bf1b(unsigned char *p, unsigned char n);
 *     users 1000, 1e55, 72b0 @0x74b3, 4116, 433c, 44d9, 8163, 8178, 83aa, b86f. The 011b users enter at bf0c
 *     (without their MOV DPTR,#011b) because Keil built the long bec7 chain (2 users).
 *   0xdf2d (args x03f2, x03f6, DPTR=x03f7) + 0xdf44 (load int @DPTR) -> void df50(long a, char n, int p) at 0xdf50.
 * Code facts used as no-code aids: struct Pos @0x0117 {long blk; int off}, struct Geo @0x0429 {char n; int size},
 * struct Clu @0x010d {int n; long first} (fw INC DPTR runs 011a->011b, 0429->042a, 010e->010f),
 * struct Ent @0x03f2 {long a; char n; int p; long b; long c} = the saved 72b0 arguments (fw df2d reads
 * 03f5 -> 03f6 with INC DPTR; with separate externs the df50 chain is 2 B longer and 1000's exact check fails).
 * Locals of 1e55 are declared in the firmware XDATA order (i 08eb, k 08ed, p 08ef, c1 08f1, c2 08f2, n 08f3,
 * v 08f4, t 08f6, a 08f7, b 08fb, c 08ff, a2 0903; ch is a register local); 3e68's in its order (cb 08fe, cl 0902,
 * next 0906, s 090a, len 090e, dst 0912, fat 0916, fs 091a, fo 091e).
 * More code facts: Keil loads the RIGHT operand of 'g1 + g2' (two globals) first, so fw "0105 loaded first"
 * = 'DAT_EXTMEM_0158 + DAT_EXTMEM_0105'; 'if ((len & 0x1ff) != 0)' gives ?C?ULCMP (bare 'if (len & 0x1ff)' gives
 * ORL); 'len += -0x4000' gives ADD #0FFFFC000; in 872e the ((p - 2) & 0x1f) test is written twice (an int local
 * keeps p - 2 alive and costs 8 B). */
struct Pos { unsigned long blk; unsigned int off; };
extern struct Pos xdata DAT_EXTMEM_0117;
extern unsigned char xdata DAT_EXTMEM_041c;
extern unsigned long xdata DAT_EXTMEM_041d;
extern unsigned long xdata DAT_EXTMEM_0421;
extern unsigned long xdata DAT_EXTMEM_0425;
struct Geo { unsigned char n; unsigned int size; };
extern struct Geo xdata DAT_EXTMEM_0429;
extern unsigned long xdata DAT_EXTMEM_040c;
extern unsigned long xdata DAT_EXTMEM_0405;
extern unsigned long xdata DAT_EXTMEM_0105;
extern unsigned long xdata DAT_EXTMEM_01e2;
extern unsigned int xdata DAT_EXTMEM_01dc;
extern unsigned long xdata DAT_EXTMEM_0100;
extern unsigned char xdata DAT_EXTMEM_01e6[];
extern void FUN_CODE_cbd9(unsigned long addr, unsigned char *buf, unsigned long n);
extern void FUN_CODE_af07(unsigned long addr, unsigned int v);
extern unsigned char xdata DAT_EXTMEM_0104;
extern unsigned char xdata DAT_EXTMEM_014f;
extern unsigned char xdata DAT_EXTMEM_015c[];
void FUN_CODE_bdbd(unsigned long addr, unsigned int off)
{
    unsigned char j;
    unsigned char lo;
    unsigned char hi;
    DAT_EXTMEM_0104 = 0;
    DAT_EXTMEM_014f = 0;
    FUN_CODE_af07(addr, off);
    while (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] != 0) {
        lo = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] & 0x0f;
        hi = (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] & 0xf0) >> 4;
        for (j = 0; j < lo + hi + 1; j++) {
            FUN_CODE_af07(addr, off + j);
            DAT_EXTMEM_015c[DAT_EXTMEM_0104] = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
            DAT_EXTMEM_0104++;
        }
        off += lo + hi + 1;
        FUN_CODE_af07(addr, off);
        DAT_EXTMEM_014f++;
    }
}

void FUN_CODE_af07(unsigned long addr, unsigned int v);
void FUN_CODE_813c(unsigned int v);

void FUN_CODE_a17e(void)
{
    unsigned int sum;
    unsigned long addr;
    if (DAT_EXTMEM_041c == 2) {
        addr = DAT_EXTMEM_040c * 2 + DAT_EXTMEM_01e2;
        FUN_CODE_cbd9(DAT_EXTMEM_0105 + addr, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        sum = 0;
        FUN_CODE_af07(addr, sum + 0x14);
        sum = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
        FUN_CODE_af07(addr, sum);
        while (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] != 0x80) {
            sum += DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off + 4];
            FUN_CODE_af07(addr, sum);
        }
        FUN_CODE_813c(sum);
    } else {
        FUN_CODE_cbd9((DAT_EXTMEM_041d - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + DAT_EXTMEM_0421,
                      DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        FUN_CODE_813c((unsigned int)DAT_EXTMEM_0425);
    }
}

void FUN_CODE_3e68(void);
extern void FUN_CODE_a547(void);
bit FUN_CODE_9d97(void)
{
    unsigned int sum;
    unsigned long addr;
    bit ok;
    if (DAT_EXTMEM_041c == 2) {
        addr = DAT_EXTMEM_040c * 2 + DAT_EXTMEM_01e2;
        FUN_CODE_cbd9(DAT_EXTMEM_0105 + addr, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        sum = 0;
        FUN_CODE_af07(addr, sum + 0x14);
        sum = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
        FUN_CODE_af07(addr, sum);
        while (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] != 0x80) {
            sum += DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off + 4];
            FUN_CODE_af07(addr, sum);
        }
        FUN_CODE_813c(sum);
    } else {
        FUN_CODE_cbd9((DAT_EXTMEM_041d - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + DAT_EXTMEM_0421,
                      DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        FUN_CODE_813c((unsigned int)DAT_EXTMEM_0425);
    }
    FUN_CODE_3e68();
    ok = 1;
    FUN_CODE_a547();
    return ok;
}

extern unsigned long xdata DAT_EXTMEM_03ee;
extern unsigned int xdata DAT_EXTMEM_040a;
extern unsigned char xdata DAT_EXTMEM_0409;
extern void FUN_CODE_d751(void);
extern unsigned int xdata DAT_EXTMEM_08f4, DAT_EXTMEM_08f6;
extern unsigned char xdata DAT_EXTMEM_01fa;
extern unsigned char xdata DAT_EXTMEM_042c;
struct Clu { unsigned int n; unsigned long first; };
extern struct Clu xdata DAT_EXTMEM_010d;
extern unsigned long FUN_CODE_c89e(unsigned char c);
extern unsigned long FUN_CODE_c7c5(unsigned char c);
void FUN_CODE_9235(void)
{
    unsigned int i;
    unsigned long a;
    for (i = 0; i < 0x80; i++) DAT_EXTMEM_015c[i] = 0;
    a = DAT_EXTMEM_01e2 + 10;
    FUN_CODE_cbd9(DAT_EXTMEM_0105 + a, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    i = DAT_EXTMEM_01fa;
    FUN_CODE_af07(a, i);
    while (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] != 0xa0) {
        i += DAT_EXTMEM_01e6[i + 4];
        FUN_CODE_af07(a, i);
    }
    FUN_CODE_af07(a, i + 9);
    i += DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] * 2 + 0x40;
    FUN_CODE_af07(a, i);
    FUN_CODE_bdbd(DAT_EXTMEM_0117.blk, DAT_EXTMEM_0117.off);
    DAT_EXTMEM_010d.n = FUN_CODE_c89e(DAT_EXTMEM_042c);
    DAT_EXTMEM_010d.first = FUN_CODE_c7c5(DAT_EXTMEM_042c);
    a = DAT_EXTMEM_010d.first * DAT_EXTMEM_01dc + DAT_EXTMEM_0429.n;
    i = 0;
    FUN_CODE_cbd9(DAT_EXTMEM_0105 + a, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    FUN_CODE_af07(a, i + 0x18);
    i = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] + 0x18;
    FUN_CODE_af07(a, i);
    FUN_CODE_d751();
}
void FUN_CODE_aa43(void)
{
    unsigned int i;
    unsigned long a;
    a = DAT_EXTMEM_01e2 + 10;
    FUN_CODE_cbd9(DAT_EXTMEM_0105 + a, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    i = DAT_EXTMEM_01fa;
    FUN_CODE_af07(a, i);
    while (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] != 0x90) {
        i += DAT_EXTMEM_01e6[i + 4];
        FUN_CODE_af07(a, i);
    }
    FUN_CODE_af07(a, i + 9);
    i += DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] * 2 + 0x18;
    FUN_CODE_af07(a, i);
    i += 0x10;
    FUN_CODE_af07(a, i);
    i += 0x10;
    FUN_CODE_af07(a, i);
    FUN_CODE_d751();
}

extern bit DAT_BIT_000c;
extern bit DAT_BIT_000b;
unsigned long FUN_CODE_bf1b(unsigned char *p, unsigned char n);
extern unsigned long xdata DAT_EXTMEM_0414;
extern unsigned long xdata DAT_EXTMEM_0410;
extern unsigned long xdata DAT_EXTMEM_01de;
extern unsigned int xdata DAT_EXTMEM_0150;
extern unsigned char xdata DAT_EXTMEM_011d[];
struct Ent { unsigned long a; unsigned char n; unsigned int p; unsigned long b; unsigned long c; };
extern struct Ent xdata DAT_EXTMEM_03f2;   /* saved 72b0 arguments; fw df2d reads 03f2..03f6 in one INC DPTR run */
extern void FUN_CODE_df2d(void);
void FUN_CODE_df50(unsigned long a, unsigned char n, unsigned int p);
extern void FUN_CODE_65ab(void *fmt, ...) large;
bit FUN_CODE_72b0(unsigned long a, unsigned char n, unsigned int p, unsigned long b, unsigned long c);
/* FUN_CODE_1000: command 'E' = list the next *.IMG entry of the update medium (twin of 1e55 with filters).
 * Real span 0x1000..0x1e55 (3669 B; the functions.json pieces 1234 / 13c8 / 13eb / 140a / 140d are inside it).
 * Same three arms as 1e55, plus a filter per arm:
 *   x041c == 1 (exFAT 0x85 entry set): after the stream entry, bit FUN_CODE_872e(x03f7, n) decides; false ->
 *     x0150 += (c1 + 1) * 0x20 (skip the whole set) and go on with the walk.
 *   x041c == 2 (records): the 'record valid' test is a while loop; per record bit FUN_CODE_4e8e(a2, i, t) decides;
 *     false -> x040a += record length, af07(03ee, 040a), d751(), next record (fw back edge LJMP 0x1614).
 *   else (FAT12/16): only names with extension "IMG" (buf[8..10] == 'I','M','G'): LFN set -> extension of the short
 *     entry after the LFN entries (x03f7 + 8), else skip the set (x0150 += (c1 + 1) * 0x20); short entry -> 8-char
 *     name copy (for k != 8), printf, return 1; other short names -> next entry.
 * Every call site of 1000 enters the 72b0 / af07 / bf1b / df50 chains as in the fw (7262 @1e22, 7263 @13f9/1e41). */
bit FUN_CODE_872e(unsigned int p, unsigned char n);
extern bit FUN_CODE_4e8e(unsigned long a, unsigned int i, unsigned char t);
unsigned char FUN_CODE_1000(void)
{
    unsigned int i;
    unsigned int k;
    unsigned int p;
    unsigned char c1;
    unsigned char c2;
    unsigned char n;
    unsigned int v;
    unsigned char t;
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long a2;
    if (DAT_BIT_000c) return 0;
    for (k = 0; k < 0x2d; k++) DAT_EXTMEM_011d[k] = 0;
    if (DAT_EXTMEM_041c == 1) {
        FUN_CODE_cbd9((DAT_EXTMEM_0414 - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + DAT_EXTMEM_0429.n,
                      DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        for (;;) {
            if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] == 0) break;
            if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] == 0x85) {
                c1 = DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + 1];
                n = DAT_EXTMEM_0429.n;
                a = DAT_EXTMEM_0414;
                p = c1 * 0x20 + DAT_EXTMEM_0150;
                b = DAT_EXTMEM_01de;
                c = DAT_EXTMEM_0410;
                FUN_CODE_72b0(a, n, p, b, c);
                while (DAT_EXTMEM_01e6[DAT_EXTMEM_03f2.p + 2] != 0) {
                    DAT_EXTMEM_03f2.p += 2;
                    if ((DAT_EXTMEM_03f2.p & 0x1f) == 0) { DAT_EXTMEM_03f2.p -= 2; break; }
                }
                if (FUN_CODE_872e(DAT_EXTMEM_03f2.p, n)) {
                c2 = 0;
                p = DAT_EXTMEM_0150 + 0x20;
                FUN_CODE_72b0(a, n, p, b, c);
                FUN_CODE_df50(DAT_EXTMEM_03f2.a, DAT_EXTMEM_03f2.n, DAT_EXTMEM_03f2.p);
                p = DAT_EXTMEM_0150 + 0x40;
                FUN_CODE_72b0(a, n, p, b, c);
                do {
                    for (k = 0; k != 0x0f; k++)
                        DAT_EXTMEM_011d[c2 * 0x0f + k] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 2];
                    DAT_EXTMEM_03f2.p += 0x20;
                    FUN_CODE_72b0(DAT_EXTMEM_03f2.a, DAT_EXTMEM_03f2.n, DAT_EXTMEM_03f2.p, DAT_EXTMEM_03f2.b, DAT_EXTMEM_03f2.c);
                    c1--;
                    c2++;
                    if (c2 > 2) { c2 += c1 - 1; break; }
                } while (c1 - 1 != 0);
                FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
                DAT_EXTMEM_0150 += (c2 + 2) * 0x20;
                DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
                FUN_CODE_d751();
                DAT_EXTMEM_0409++;
                return 1;
                }
                DAT_EXTMEM_0150 += (c1 + 1) * 0x20;
            } else {
                DAT_EXTMEM_0150 += 0x20;
            }
            DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
            FUN_CODE_d751();
            if (DAT_BIT_000c) return 0;
        }
        return 0;
    } else if (DAT_EXTMEM_041c == 2) {
        FUN_CODE_af07(DAT_EXTMEM_03ee, DAT_EXTMEM_040a);
        if (!DAT_BIT_000b) {
            if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4) == 0) {
                if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 4 + DAT_EXTMEM_0117.off, 4) == 0) {
                    FUN_CODE_9235();
                    DAT_BIT_000b = 1;
                }
            }
        }
        if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4) == 0) {
            if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 4 + DAT_EXTMEM_0117.off, 4) == 0) {
                if (DAT_EXTMEM_042c < DAT_EXTMEM_014f - 1) {
                    DAT_EXTMEM_042c++;
                    if (DAT_EXTMEM_042c < DAT_EXTMEM_014f) {
                        DAT_EXTMEM_010d.n = FUN_CODE_c89e(DAT_EXTMEM_042c);
                        DAT_EXTMEM_010d.first = 0;
                        DAT_EXTMEM_0429.n = 0;
                        for (i = 0; i < DAT_EXTMEM_042c + 1; i++) DAT_EXTMEM_010d.first += FUN_CODE_c7c5((unsigned char)i);
                    }
                    a2 = DAT_EXTMEM_010d.first * DAT_EXTMEM_01dc + DAT_EXTMEM_0429.n;
                    i = 0;
                    FUN_CODE_cbd9(DAT_EXTMEM_0105 + a2, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
                    FUN_CODE_af07(a2, i + 0x18);
                    i = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] + 0x18;
                    FUN_CODE_af07(a2, i);
                    FUN_CODE_d751();
                }
            }
        }
        while ((FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4) != 0 ||
                FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 4 + DAT_EXTMEM_0117.off, 4) != 0) && DAT_EXTMEM_042c < DAT_EXTMEM_014f) {
            DAT_EXTMEM_040c = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4);
            FUN_CODE_af07(DAT_EXTMEM_03ee, DAT_EXTMEM_040a + 8);
            v = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
            a2 = DAT_EXTMEM_040c * 2 + DAT_EXTMEM_01e2;
            FUN_CODE_cbd9(DAT_EXTMEM_0105 + a2, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
            i = DAT_EXTMEM_01fa;
            FUN_CODE_af07(a2, i);
            while (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] != 0x30) {
                i += DAT_EXTMEM_01e6[i + 4];
                FUN_CODE_af07(a2, i);
            }
            FUN_CODE_af07(a2, i + 9);
            t = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
            i += t * 2 + 0x18;
            FUN_CODE_af07(a2, i);
            i += 0x40;
            FUN_CODE_af07(a2, i);
            t = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
            i += 2;
            FUN_CODE_af07(a2, i);
            if (FUN_CODE_4e8e(a2, i, t)) {
                for (k = 0; k < t; k++) {
                    FUN_CODE_af07(a2, i + k * 2);
                    DAT_EXTMEM_011d[k] = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
                    if (k == 0x2c) break;
                }
                FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
                DAT_EXTMEM_0409++;
                DAT_EXTMEM_040a += v;
                FUN_CODE_af07(DAT_EXTMEM_03ee, DAT_EXTMEM_040a);
                FUN_CODE_d751();
                return 1;
            }
            DAT_EXTMEM_040a += v;
            FUN_CODE_af07(DAT_EXTMEM_03ee, DAT_EXTMEM_040a);
            FUN_CODE_d751();
        }
        DAT_BIT_000c = 1;
        return 0;
    }
    FUN_CODE_cbd9((DAT_EXTMEM_0414 - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + DAT_EXTMEM_0429.n,
                  DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    for (;;) {
        if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] == 0) break;
        if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] != 0xe5) {
            if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + 0x0b] == 0x0f) {
                c1 = DAT_EXTMEM_01e6[DAT_EXTMEM_0150] & 0x3f;
                p = c1 * 0x20 + DAT_EXTMEM_0150;
                n = DAT_EXTMEM_0429.n;
                a = DAT_EXTMEM_0414;
                b = DAT_EXTMEM_01de;
                c = DAT_EXTMEM_0410;
                FUN_CODE_72b0(a, n, p, b, c);
                if (DAT_EXTMEM_01e6[DAT_EXTMEM_03f2.p + 8] == 0x49 && DAT_EXTMEM_01e6[DAT_EXTMEM_03f2.p + 9] == 0x4d &&
                    DAT_EXTMEM_01e6[DAT_EXTMEM_03f2.p + 10] == 0x47) {
                FUN_CODE_df50(DAT_EXTMEM_03f2.a, DAT_EXTMEM_03f2.n, DAT_EXTMEM_03f2.p);
                c2 = 0;
                do {
                    c1--;
                    p = c1 * 0x20 + DAT_EXTMEM_0150;
                    FUN_CODE_72b0(a, n, p, b, c);
                    for (k = 0; k != 5; k++)
                        DAT_EXTMEM_011d[c2 * 0x0d + k] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 1];
                    for (k = 0; k != 6; k++)
                        DAT_EXTMEM_011d[c2 * 0x0d + k + 5] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 0x0e];
                    for (k = 0; k != 2; k++)
                        DAT_EXTMEM_011d[c2 * 0x0d + k + 0x0b] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 0x1c];
                    c2++;
                    if (c2 > 2) { c2 += c1; break; }
                } while (c1 != 0);
                FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
                DAT_EXTMEM_0150 += (c2 + 1) * 0x20;
                DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
                FUN_CODE_d751();
                DAT_EXTMEM_0409++;
                return 1;
                }
                DAT_EXTMEM_0150 += (c1 + 1) * 0x20;
            } else if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + 8] == 0x49 && DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + 9] == 0x4d &&
                       DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + 10] == 0x47) {
                FUN_CODE_df50(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150);
                for (k = 0; k != 8; k++) DAT_EXTMEM_011d[k] = DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + k];
                FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
                DAT_EXTMEM_0150 += 0x20;
                DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
                FUN_CODE_d751();
                DAT_EXTMEM_0409++;
                return 1;
            } else {
                DAT_EXTMEM_0150 += 0x20;
            }
        } else {
            DAT_EXTMEM_0150 += 0x20;
        }
        DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
        FUN_CODE_d751();
        if (DAT_BIT_000c) return 0;
    }
    return 0;
}

unsigned char FUN_CODE_1e55(void)
{
    unsigned int i;
    unsigned int k;
    unsigned int p;
    unsigned char c1;
    unsigned char c2;
    unsigned char n;
    unsigned int v;
    unsigned char t;
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long a2;
    unsigned char ch;
    if (DAT_BIT_000c) return 0;
    for (k = 0; k < 0x2d; k++) DAT_EXTMEM_011d[k] = 0;
    if (DAT_EXTMEM_041c == 1) {
        FUN_CODE_cbd9((DAT_EXTMEM_0414 - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + DAT_EXTMEM_0429.n,
                      DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        for (;;) {
            if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] == 0) break;
            if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] == 0x85) {
                c1 = DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + 1];
                n = DAT_EXTMEM_0429.n;
                a = DAT_EXTMEM_0414;
                p = c1 * 0x20 + DAT_EXTMEM_0150;
                b = DAT_EXTMEM_01de;
                c = DAT_EXTMEM_0410;
                FUN_CODE_72b0(a, n, p, b, c);
                while (DAT_EXTMEM_01e6[DAT_EXTMEM_03f2.p + 2] != 0) {
                    DAT_EXTMEM_03f2.p += 2;
                    if ((DAT_EXTMEM_03f2.p & 0x1f) == 0) { DAT_EXTMEM_03f2.p -= 2; break; }
                }
                c2 = 0;
                p = DAT_EXTMEM_0150 + 0x20;
                FUN_CODE_72b0(a, n, p, b, c);
                FUN_CODE_df50(DAT_EXTMEM_03f2.a, DAT_EXTMEM_03f2.n, DAT_EXTMEM_03f2.p);
                p = DAT_EXTMEM_0150 + 0x40;
                FUN_CODE_72b0(a, n, p, b, c);
                do {
                    for (k = 0; k != 0x0f; k++)
                        DAT_EXTMEM_011d[c2 * 0x0f + k] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 2];
                    DAT_EXTMEM_03f2.p += 0x20;
                    FUN_CODE_72b0(DAT_EXTMEM_03f2.a, DAT_EXTMEM_03f2.n, DAT_EXTMEM_03f2.p, DAT_EXTMEM_03f2.b, DAT_EXTMEM_03f2.c);
                    c1--;
                    c2++;
                    if (c2 > 2) { c2 += c1 - 1; break; }
                } while (c1 - 1 != 0);
                FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
                DAT_EXTMEM_0150 += (c2 + 2) * 0x20;
                DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
                FUN_CODE_d751();
                DAT_EXTMEM_0409++;
                return 1;
            }
            if (DAT_BIT_000c) DAT_EXTMEM_0150 += 0x20; else DAT_EXTMEM_0150 += 0x20;   /* no-code aid, see header */
            DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
            FUN_CODE_d751();
            if (DAT_BIT_000c) return 0;
        }
        return 0;
    } else if (DAT_EXTMEM_041c == 2) {
        FUN_CODE_af07(DAT_EXTMEM_03ee, DAT_EXTMEM_040a);
        if (!DAT_BIT_000b) {
            if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4) == 0) {
                if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 4 + DAT_EXTMEM_0117.off, 4) == 0) {
                    FUN_CODE_9235();
                    DAT_BIT_000b = 1;
                }
            }
        }
        if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4) == 0) {
            if (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 4 + DAT_EXTMEM_0117.off, 4) == 0) {
                if (DAT_EXTMEM_042c < DAT_EXTMEM_014f - 1) {
                    DAT_EXTMEM_042c++;
                    if (DAT_EXTMEM_042c < DAT_EXTMEM_014f) {
                        DAT_EXTMEM_010d.n = FUN_CODE_c89e(DAT_EXTMEM_042c);
                        DAT_EXTMEM_010d.first = 0;
                        DAT_EXTMEM_0429.n = 0;
                        for (i = 0; i < DAT_EXTMEM_042c + 1; i++) DAT_EXTMEM_010d.first += FUN_CODE_c7c5((unsigned char)i);
                    }
                    a2 = DAT_EXTMEM_010d.first * DAT_EXTMEM_01dc + DAT_EXTMEM_0429.n;
                    i = 0;
                    FUN_CODE_cbd9(DAT_EXTMEM_0105 + a2, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
                    FUN_CODE_af07(a2, i + 0x18);
                    i = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] + 0x18;
                    FUN_CODE_af07(a2, i);
                    FUN_CODE_d751();
                }
            }
        }
        if ((FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4) != 0 ||
             FUN_CODE_bf1b(DAT_EXTMEM_01e6 + 4 + DAT_EXTMEM_0117.off, 4) != 0) && DAT_EXTMEM_042c < DAT_EXTMEM_014f) {
            DAT_EXTMEM_040c = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, 4);
            FUN_CODE_af07(DAT_EXTMEM_03ee, DAT_EXTMEM_040a + 8);
            v = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
            a2 = DAT_EXTMEM_040c * 2 + DAT_EXTMEM_01e2;
            FUN_CODE_cbd9(DAT_EXTMEM_0105 + a2, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
            i = DAT_EXTMEM_01fa;
            FUN_CODE_af07(a2, i);
            while (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] != 0x30) {
                i += DAT_EXTMEM_01e6[i + 4];
                FUN_CODE_af07(a2, i);
            }
            FUN_CODE_af07(a2, i + 9);
            t = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
            i += t * 2 + 0x18;
            FUN_CODE_af07(a2, i);
            i += 0x40;
            FUN_CODE_af07(a2, i);
            t = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
            i += 2;
            FUN_CODE_af07(a2, i);
            for (k = 0; k < t; k++) {
                FUN_CODE_af07(a2, i + k * 2);
                DAT_EXTMEM_011d[k] = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off];
                if (k == 0x2c) break;
            }
            FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
            DAT_EXTMEM_0409++;
            DAT_EXTMEM_040a += v;
            FUN_CODE_af07(DAT_EXTMEM_03ee, DAT_EXTMEM_040a);
            FUN_CODE_d751();
            return 1;
        }
        DAT_BIT_000c = 1;
        return 0;
    }
    FUN_CODE_cbd9((DAT_EXTMEM_0414 - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + DAT_EXTMEM_0429.n,
                  DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    for (;;) {
        if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] == 0) break;
        if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150] != 0xe5) {
            if (DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + 0x0b] == 0x0f) {
                c1 = DAT_EXTMEM_01e6[DAT_EXTMEM_0150] & 0x3f;
                p = c1 * 0x20 + DAT_EXTMEM_0150;
                n = DAT_EXTMEM_0429.n;
                a = DAT_EXTMEM_0414;
                b = DAT_EXTMEM_01de;
                c = DAT_EXTMEM_0410;
                FUN_CODE_72b0(a, n, p, b, c);
                FUN_CODE_df50(DAT_EXTMEM_03f2.a, DAT_EXTMEM_03f2.n, DAT_EXTMEM_03f2.p);
                c2 = 0;
                do {
                    c1--;
                    p = c1 * 0x20 + DAT_EXTMEM_0150;
                    FUN_CODE_72b0(a, n, p, b, c);
                    for (k = 0; k != 5; k++)
                        DAT_EXTMEM_011d[c2 * 0x0d + k] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 1];
                    for (k = 0; k != 6; k++)
                        DAT_EXTMEM_011d[c2 * 0x0d + k + 5] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 0x0e];
                    for (k = 0; k != 2; k++)
                        DAT_EXTMEM_011d[c2 * 0x0d + k + 0x0b] = DAT_EXTMEM_01e6[k * 2 + DAT_EXTMEM_03f2.p + 0x1c];
                    c2++;
                    if (c2 > 2) { c2 += c1; break; }
                } while (c1 != 0);
                FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
                DAT_EXTMEM_0150 += (c2 + 1) * 0x20;
                DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
                FUN_CODE_d751();
                DAT_EXTMEM_0409++;
                return 1;
            }
            FUN_CODE_df50(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150);
            for (k = 0; k < 0x0b; k++) {
                ch = DAT_EXTMEM_01e6[DAT_EXTMEM_0150 + k];
                if (ch != 0x20) DAT_EXTMEM_011d[k] = ch;
            }
            FUN_CODE_65ab((void code *)0xe0a3, (char *)DAT_EXTMEM_011d);
            DAT_EXTMEM_0150 += 0x20;
            DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
            FUN_CODE_d751();
            DAT_EXTMEM_0409++;
            return 1;
        }
        if (DAT_BIT_000c) DAT_EXTMEM_0150 += 0x20; else DAT_EXTMEM_0150 += 0x20;   /* no-code aid, see header */
        DAT_BIT_000c = FUN_CODE_72b0(DAT_EXTMEM_0414, DAT_EXTMEM_0429.n, DAT_EXTMEM_0150, DAT_EXTMEM_01de, DAT_EXTMEM_0410);
        FUN_CODE_d751();
        if (DAT_BIT_000c) return 0;
    }
    return 0;
}

/* FUN_CODE_3e68: copy the selected file (start cluster x03e6, size x0109) from the medium through
 * FUN_CODE_d6d1(sector, bytes, destination offset) in pieces of at most 0x4000 bytes.
 *   x041c == 2: the file is contiguous: sector = x03e6 * 01dc + 0105, 0x4000-byte pieces, then the rest.
 *   else (FAT): cb = bytes per cluster; walk the FAT chain (FAT sector fat + cl / (size / 4), entry offset
 *   cl * 4 % size, entry & 0x0FFFFFFF), joining runs of consecutive clusters into one d6d1 read of up to 0x4000
 *   bytes; the last piece is rounded up to 0x200 bytes. bit 0x0D set = no chain (contiguous file, min. 0x200 B).
 *   The chain step 'len += cb; cl = next; next = bf1b(01e6 + fo, 4)' at 0x433c / 0x44d9 is what Keil puts into
 *   the common-entry block 0xbec7 in front of bf1b. */
extern bit DAT_BIT_000d;
extern unsigned long xdata DAT_EXTMEM_03e6;
extern unsigned long xdata DAT_EXTMEM_0109;
extern unsigned long xdata DAT_EXTMEM_0158;
extern void FUN_CODE_d6d1(unsigned long s, unsigned long n, unsigned long dst);
void FUN_CODE_3e68(void)
{
    unsigned long cb;
    unsigned long cl;
    unsigned long next;
    unsigned long s;
    unsigned long len;
    unsigned long dst;
    unsigned long fat;
    unsigned long fs;
    unsigned int fo;
    if (DAT_EXTMEM_041c == 2) {
        s = DAT_EXTMEM_03e6 * DAT_EXTMEM_01dc + DAT_EXTMEM_0105;
        len = DAT_EXTMEM_0109;
        dst = 0;
        while (len > 0x4000) {
            FUN_CODE_d6d1(s, 0x4000, dst);
            dst += 0x4000;
            len += -0x4000;
            s += 0x4000 / DAT_EXTMEM_0429.size;
        }
        FUN_CODE_d6d1(s, len, dst);
        dst += len;
    } else {
        cb = DAT_EXTMEM_0429.size;
        cb = DAT_EXTMEM_01dc * cb;
        cl = DAT_EXTMEM_03e6;
        if (!DAT_BIT_000d) {
            fat = DAT_EXTMEM_0158 + DAT_EXTMEM_0105;
            fs = fat + cl / (DAT_EXTMEM_0429.size >> 2);
            FUN_CODE_cbd9(fs, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
            fo = cl * 4 % DAT_EXTMEM_0429.size;
            next = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + fo, 4) & 0x0fffffff;
        } else {
            next = 0x0ffffff8;
        }
        dst = 0;
        do {
            if (!DAT_BIT_000d) {
                len = 0;
                fo = next * 4 % DAT_EXTMEM_0429.size;
            } else {
                if (DAT_EXTMEM_0109 < 0x200) len = 0x200; else len = DAT_EXTMEM_0109;
            }
            s = (cl - 2) * DAT_EXTMEM_01dc;
            s = s + DAT_EXTMEM_0405 + DAT_EXTMEM_0105;
            while (len < 0x4000 && next - cl == 1) {
                if (fat + next / (DAT_EXTMEM_0429.size >> 2) != fs) {
                    fs = fat + next / (DAT_EXTMEM_0429.size >> 2);
                    FUN_CODE_cbd9(fs, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
                }
                len += cb;
                cl = next;
                next = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + fo, 4) & 0x0fffffff;
                fo = next * 4 % DAT_EXTMEM_0429.size;
            }
            if (next > 0x0ffffff8) {
                len += cb;
            } else if (next - cl > 1 && !DAT_BIT_000d) {
                cl = next;
                if (fat + next / (DAT_EXTMEM_0429.size >> 2) != fs) {
                    fs = fat + next / (DAT_EXTMEM_0429.size >> 2);
                    FUN_CODE_cbd9(fs, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
                }
                len += cb;
                cl = next;
                next = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + fo, 4) & 0x0fffffff;
            }
            while (len > 0x4000) {
                FUN_CODE_d6d1(s, 0x4000, dst);
                dst += 0x4000;
                len += -0x4000;
                s += 0x4000 / DAT_EXTMEM_0429.size;
            }
            if ((len & 0x1ff) != 0) len = (len / 0x200 + 1) * 0x200;
            FUN_CODE_d6d1(s, len, dst);
            dst += len;
        } while (next < 0x0ffffff8);
    }
}
/* FUN_CODE_813c: take the file whose directory entry starts at offset e of the sector buffer 0x01E6:
 * x03e6 = first cluster, x0109 = size in bytes, x0401 = its first sector, bit 0x0D = contiguous (no FAT chain).
 * exFAT (041c == 1, e = stream extension entry): size @ e + 0x18, cluster @ e + 0x14, bit 0x0D = flags bit 1.
 * 041c == 2 (records): af07 seeks to e + 0x40 / 0x41; nibbles of that byte = lengths of the two numbers that follow;
 *   x010d = the first one, x03e6 = the second; x0109 = 010d * 01dc * block size.
 * FAT: cluster = (hi @ e + 0x14) << 16 + lo @ e + 0x1a, size @ e + 0x1c, bit 0x0D = 0.
 * The 4ffa() result is stored and never read (same as in b84b). */
extern unsigned char FUN_CODE_4ffa(void);
extern unsigned long xdata DAT_EXTMEM_0401;
extern unsigned long xdata DAT_EXTMEM_0418;
void FUN_CODE_813c(unsigned int e)
{
    unsigned char t;
    unsigned char f;
    unsigned char g;
    unsigned long a;
    t = FUN_CODE_4ffa();
    if (DAT_EXTMEM_041c == 1) {
        DAT_EXTMEM_0109 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x18, 4);
        DAT_EXTMEM_03e6 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x14, 4);
        DAT_EXTMEM_0401 = (DAT_EXTMEM_03e6 - 2) * DAT_EXTMEM_01dc + DAT_EXTMEM_0405;
        DAT_EXTMEM_0401 += DAT_EXTMEM_0105;
        if (DAT_EXTMEM_01e6[e + 1] & 0x02) DAT_BIT_000d = 1; else DAT_BIT_000d = 0;
    } else if (DAT_EXTMEM_041c == 2) {
        a = DAT_EXTMEM_0117.blk;
        FUN_CODE_af07(a, e + 0x40);
        f = DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] & 0x0f;
        g = (DAT_EXTMEM_01e6[DAT_EXTMEM_0117.off] & 0xf0) >> 4;
        FUN_CODE_af07(a, e + 0x41);
        DAT_EXTMEM_010d.n = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, f);
        FUN_CODE_af07(a, e + 0x41 + f);
        DAT_EXTMEM_03e6 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + DAT_EXTMEM_0117.off, g);
        DAT_EXTMEM_0109 = (unsigned long)DAT_EXTMEM_010d.n * DAT_EXTMEM_01dc * DAT_EXTMEM_0429.size;
    } else {
        DAT_EXTMEM_03e6 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x14, 2);
        DAT_EXTMEM_03e6 = (DAT_EXTMEM_03e6 << 16) + FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x1a, 2);
        DAT_EXTMEM_0109 = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x1c, 4);
        DAT_EXTMEM_0401 = (DAT_EXTMEM_03e6 - DAT_EXTMEM_0418) * DAT_EXTMEM_01dc + DAT_EXTMEM_0405;
        DAT_EXTMEM_0401 += DAT_EXTMEM_0105;
        DAT_BIT_000d = 0;
    }
}

/* FUN_CODE_b84b: first sector of the file whose directory entry starts at offset e of the sector buffer
 * 0x01E6 -> x0152 (absolute sector). exFAT (041c == 1): first cluster = the long at e + 0x34 (stream extension
 * entry + 0x14), x0152 = (cl - 2) * 01dc + x014b; else (FAT): cl = (hi word @ e + 0x14) << 16 + lo word @ e + 0x1a,
 * x0152 = (cl - x0418) * 01dc + 0405. Then x0152 += 0105, written in each arm (the fw keeps 'LCALL
 * ?C?LSTXDATA; RET' at 0xb976 only with the two arm tails cross-jumped). The 4ffa() result is stored and never read. */
extern unsigned long xdata DAT_EXTMEM_0152;
extern unsigned long xdata DAT_EXTMEM_014b;
extern unsigned long xdata DAT_EXTMEM_0418;
void FUN_CODE_b84b(unsigned int e)
{
    unsigned char t;
    unsigned long v;
    t = FUN_CODE_4ffa();
    if (!(DAT_EXTMEM_041c ^ 1)) {
        DAT_EXTMEM_0152 = (FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x34, 4) - 2) * DAT_EXTMEM_01dc + DAT_EXTMEM_014b;
        DAT_EXTMEM_0152 += DAT_EXTMEM_0105;
    } else {
        v = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x14, 2);
        v = (v << 16) + FUN_CODE_bf1b(DAT_EXTMEM_01e6 + e + 0x1a, 2);
        DAT_EXTMEM_0152 = (v - DAT_EXTMEM_0418) * DAT_EXTMEM_01dc + DAT_EXTMEM_0405;
        DAT_EXTMEM_0152 += DAT_EXTMEM_0105;
    }
}

/* df50: store the walk position of the current entry: 041d = a, 0421 = n, 0425 = p. */
void FUN_CODE_df50(unsigned long a, unsigned char n, unsigned int p)
{
    DAT_EXTMEM_041d = a;
    DAT_EXTMEM_0421 = n;
    DAT_EXTMEM_0425 = p;
}
/* FUN_CODE_bf1b: little-endian value of the n bytes at p (p[n-1] is the high byte). */
unsigned long FUN_CODE_bf1b(unsigned char *p, unsigned char n)
{
    unsigned char i;
    unsigned long v;
    v = 0;
    for (i = 1; i < n + 1; i++) {
        v <<= 8;
        v |= p[n - i];
    }
    return v;
}
extern unsigned long xdata DAT_EXTMEM_0158;
/* FUN_CODE_72b0: FAT cluster-chain step of the directory walk. a = cluster, n = sector in the cluster,
 * p = byte offset in the sector, b = FAT sector index, c = byte offset in the FAT sector (all saved to struct Ent
 * @0x03f2 at the end). Past the sector end: next sector of the cluster (p %= size); else re-read the current
 * sector when n changed. Past the last sector of the cluster: read the FAT sector, a = bf1b(&FAT entry, 4),
 * printf("DataCluster = 0x%8lx\r\n") (CODE 0xE08C), 0x0FFFFFFF = end of chain -> return 1, else compute the next
 * FAT position (c = a * 4, b = c / size, c %= size) and read the first sector of cluster a. Entered through the
 * common-entry chain 0x7262 / 0x7263 / 0x72a5 (see the header). */
bit FUN_CODE_72b0(unsigned long a, unsigned char n, unsigned int p, unsigned long b, unsigned long c)
{
    bit ok;
    ok = 0;
    if (p >= DAT_EXTMEM_0429.size) {
        n++;
        p = p % DAT_EXTMEM_0429.size;
        FUN_CODE_cbd9((a - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + n,
                      DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    } else if (n != DAT_EXTMEM_03f2.n) {
        FUN_CODE_cbd9((DAT_EXTMEM_0414 - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + DAT_EXTMEM_0429.n,
                      DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    }
    if (n >= DAT_EXTMEM_01dc) {
        n = 0;
        FUN_CODE_cbd9(DAT_EXTMEM_0158 + DAT_EXTMEM_0105 + b, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        a = FUN_CODE_bf1b(DAT_EXTMEM_01e6 + (unsigned int)c, 4);
        FUN_CODE_65ab((void code *)0xe08c, a);   /* "DataCluster = 0x%8lx\r\n" */
        if (a == 0x0fffffff) {
            ok = 1;
        } else {
            c = a * 4;
            b = c / DAT_EXTMEM_0429.size;
            if (c >= DAT_EXTMEM_0429.size) c = c % DAT_EXTMEM_0429.size;
            FUN_CODE_cbd9((a - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105), DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
        }
    }
    DAT_EXTMEM_03f2.a = a;
    DAT_EXTMEM_03f2.n = n;
    DAT_EXTMEM_03f2.p = p;
    DAT_EXTMEM_03f2.b = b;
    DAT_EXTMEM_03f2.c = c;
    return ok;
}

/* FUN_CODE_872e: called by 1000 in the exFAT arm: bit = the name ending at offset p of the sector buffer
 * 0x01E6 is ".IMG" (UTF-16 chars 'G' @p, 'M' @p-2, 'I' @p-4, either case). When 'M' or 'I' fall in front of a
 * 0x20-byte entry start, the char is 2 bytes further back (skips the entry-type byte + 1); when it falls in front of
 * the sector start, the previous sector is loaded with 72b0(saved state) and the char is at 0x1FE / 0x1FC. Always
 * re-reads sector ((0414 - 2) * 01dc + 0405 + 0105 + n) at the end. Code fact: the ((p - 2) & 0x1f) test is written
 * twice (no local); an int local keeps p - 2 alive (Keil CSE) and costs 8 B. */
bit FUN_CODE_872e(unsigned int p, unsigned char n)
{
    bit ok;
    ok = 0;
    if (((p - 2) & 0x1f) == 0 || ((p - 4) & 0x1f) == 0) {
        if (((p - 2) & 0x1f) == 0) {
            if (DAT_EXTMEM_01e6[p] == 'G' || DAT_EXTMEM_01e6[p] == 'g') {
                if (p - 2 == 0) {
                    FUN_CODE_72b0(DAT_EXTMEM_03f2.a, n, p, DAT_EXTMEM_03f2.b, DAT_EXTMEM_03f2.c);
                    if ((DAT_EXTMEM_01e6[0x1fe] == 'M' || DAT_EXTMEM_01e6[0x1fe] == 'm') &&
                        (DAT_EXTMEM_01e6[0x1fc] == 'I' || DAT_EXTMEM_01e6[0x1fc] == 'i')) ok = 1; else ok = 0;
                } else {
                    if ((DAT_EXTMEM_01e6[p - 4] == 'M' || DAT_EXTMEM_01e6[p - 4] == 'm') &&
                        (DAT_EXTMEM_01e6[p - 6] == 'I' || DAT_EXTMEM_01e6[p - 6] == 'i')) ok = 1; else ok = 0;
                }
            } else ok = 0;
        } else if (((p - 4) & 0x1f) == 0) {
            if ((DAT_EXTMEM_01e6[p] == 'G' || DAT_EXTMEM_01e6[p] == 'g') &&
                (DAT_EXTMEM_01e6[p - 2] == 'M' || DAT_EXTMEM_01e6[p - 2] == 'm')) {
                if (p - 4 == 0) {
                    FUN_CODE_72b0(DAT_EXTMEM_03f2.a, n, p, DAT_EXTMEM_03f2.b, DAT_EXTMEM_03f2.c);
                    if (DAT_EXTMEM_01e6[0x1fe] == 'I' || DAT_EXTMEM_01e6[0x1fe] == 'i') ok = 1; else ok = 0;
                } else {
                    if (DAT_EXTMEM_01e6[p - 6] == 'I' || DAT_EXTMEM_01e6[p - 6] == 'i') ok = 1; else ok = 0;
                }
            } else ok = 0;
        }
    } else {
        if ((DAT_EXTMEM_01e6[p] == 'G' || DAT_EXTMEM_01e6[p] == 'g') &&
            (DAT_EXTMEM_01e6[p - 2] == 'M' || DAT_EXTMEM_01e6[p - 2] == 'm') &&
            (DAT_EXTMEM_01e6[p - 4] == 'I' || DAT_EXTMEM_01e6[p - 4] == 'i')) ok = 1; else ok = 0;
    }
    FUN_CODE_cbd9((DAT_EXTMEM_0414 - 2) * DAT_EXTMEM_01dc + (DAT_EXTMEM_0405 + DAT_EXTMEM_0105) + n,
                  DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    return ok;
}

void FUN_CODE_af07(unsigned long addr, unsigned int off)
{
    if (off >= DAT_EXTMEM_0429.size) {
        addr += off / DAT_EXTMEM_0429.size;
        off = off % DAT_EXTMEM_0429.size;
        if (DAT_EXTMEM_0100 != addr) FUN_CODE_cbd9(DAT_EXTMEM_0105 + addr, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    } else {
        if (DAT_EXTMEM_0100 != addr) FUN_CODE_cbd9(DAT_EXTMEM_0105 + addr, DAT_EXTMEM_01e6, DAT_EXTMEM_0429.size);
    }
    DAT_EXTMEM_0117.blk = addr;
    DAT_EXTMEM_0117.off = off;
    DAT_EXTMEM_0100 = addr;
}

