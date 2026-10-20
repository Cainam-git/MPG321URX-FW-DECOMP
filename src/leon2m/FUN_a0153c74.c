/* leon2m FUN_a0153c74 @ 0xa0153c74..0xa01541ec (350 words): system-settings check at power-on. BYTE-EXACT.
 * -mcpu=v8 -O3 -g: rawcmp 0/350 and tools/exact.py exact() = None (linked at the real
 * address, all relocations resolved, bytes == firmware). jf shows 85.14 match=False ONLY because of a diff.py
 * normaliser quirk: the ROM base is 'sethi %hi(DAT_00020000); or %r, %lo(DAT_00020000) = 0, %rd'; the firmware word
 * prints as 'mov %r, %rd' and its later field loads '[%rd + 0x1aa]' are labelled %lo(ADDR), while the relocated 'or'
 * stops that tracking. All 52 differing rows are those 6 base 'or's and 46 ROM field loads (checked row by row).
 *
 * Plain words (code facts; storage = settings chip dev 0, read with FUN_a0140360, written with FUN_a0140e74):
 *  1. FUN_a0140304(0) == 0 ('storage not usable'; FW.021 returns 1): print 'DG_SYSSETTING OPR is invalid 1'
 *     (s_001a7620) and write the ROM defaults: P = 0x30 bytes ROM 0x20140 -> storage 0x440, S = 0x50 bytes ROM
 *     0x20170 -> storage 0x470 (flag 1).
 *  2. Else check(): read S from storage 0x470 into a zeroed buffer twice per round until the version word +0x3A reads
 *     the same twice (no round counter; a chip that never answers leaves the buffer unchanged, so it ends),
 *     print '%04x,%04x' (stored ver, ROM ver). Result 1 if ver != ROM 0x7690, or +0x40 != ROM 0x04C0, or +0x3E !=
 *     ROM 0x0470; result 2 if +0x38 != ROM 0x0001 or +0x3C != FUN_a012ce18(); else 0.
 *     Result 1: print 'SysNvram_IsEmpty 1' (s_001a7608) and write the ROM defaults as in step 1.
 *     Else check() runs a SECOND time (full read again; the source calls it in 'else if (check() == 2)'); result 2:
 *     print 'SysNvram_IsEmpty 2', copy the 16-byte pattern ROM s_001a75e6 (16 x 0xFF) with FUN_a013c910, write it to storage
 *     0x300..0x43F in 20 chunks of 16 (remainder 0, no extra write), read S, set +0x38 / +0x1A / +0x3E / +0x40 from ROM
 *     and +0x3C = FUN_a012ce18(), write S back (flag 1).
 *  3. Always: read P (storage 0x440, 0x30 bytes) into RAM 0xA802E1F0 and S (0x470, 0x50) into RAM 0xA802E1A0.
 *  4. ROM self-check: ROM 0x20168 != 0xA5A5 -> print 'While : 3' and HANG for ever; ROM 0x201B2 != ROM 0x20168 ->
 *     'While : 4' and HANG. Both are ROM constants (flash 0x128168 / 0x1281B2 = A5A5 / A5A5 in FW.021),
 *     so these hangs are not taken.
 *  5. If the RAM function pointer 0xA802CC4C is non-zero, call it.
 * Can it wait or fail? The stable-read loop has no counter but needs two DIFFERENT consecutive version words to spin.
 * Every storage write goes through FUN_a0140e74, whose ACK poll has no limit; writes happen only on the
 * stored bytes listed in step 2. The ROM hangs in step 4 cannot trigger with these ROM bytes.
 * Exact-form levers: (1) the 'not usable' arm FIRST ('if (!FUN_a0140304(0)) ... else if (check() == 1) ... else if
 * (check() == 2)'): gives the firmware's register renaming AND its stack-slot sharing (the defaults copy reuses the
 * first check's buffer slot fp-88 / the second's fp-216); (2) Part / Rec 8-byte aligned (no-code type attribute:
 * the firmware copies the ROM records with ldd/std, which gcc only does inline for 8-aligned structs; with 2-byte
 * alignment it calls memcpy); (3) the defaults as 'declare r, p; p = ROM.p; r = ROM.r;' (load order of the copy);
 * (4) a u16 total 'n = 0x140; i < n / 16' (gives 'cmp 0x14; bcs' instead of 'cmp 0x13; bleu'); (5) the IsEmpty-2
 * field order h38, b1a, h3e, h40 (gives the firmware's load / store order).
 */
struct Rec { unsigned char a[0x1a]; unsigned char b1a; unsigned char c[0x1d];
             unsigned short h38, ver, chk, h3e, h40, magic2; unsigned char d[0xc]; } __attribute__((aligned(8)));
struct Part { unsigned char a[0x28]; unsigned short magic1; unsigned char c[6]; } __attribute__((aligned(8)));
struct NV { struct Part p; struct Rec r; };
struct Defaults { unsigned char other[0x140]; struct NV nv; };   /* 0x000..0x13F: not read here */
extern const struct Defaults DAT_00020000;
extern struct Rec DAT_a802e1a0;
extern struct Part DAT_a802e1f0;
extern void (*DAT_a802cc4c)(void);
extern char s_001a75e6[], s_001a75f8[], s_001a7608[], s_001a7620[], s_001a7648[];
extern unsigned char FUN_a0140304(unsigned char);
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);
extern void FUN_a0140e74(unsigned char, unsigned short, unsigned short, void *, unsigned char);
extern unsigned short FUN_a012ce18(void);
extern void *FUN_a013c910(void *, const void *, unsigned int);
extern int FUN_a00df170(const char *, ...);

static unsigned char check(void)
{
    struct Rec r = {{0}};
    unsigned short v, cur;

    do {
        FUN_a0140360(0, 0x470, 0x50, &r);
        v = r.ver;
        FUN_a0140360(0, 0x470, 0x50, &r);
        cur = r.ver;
    } while (cur != v);
    FUN_a00df170(s_001a75f8, cur, DAT_00020000.nv.r.ver);
    if (DAT_00020000.nv.r.ver != cur)
        return 1;
    if (r.h40 != DAT_00020000.nv.r.h40)
        return 1;
    if (r.h3e != DAT_00020000.nv.r.h3e)
        return 1;
    if (r.h38 != DAT_00020000.nv.r.h38)
        return 2;
    return r.chk != FUN_a012ce18() ? 2 : 0;
}

void FUN_a0153c74(void)
{
    if (!FUN_a0140304(0)) {
        FUN_a00df170(s_001a7620, 1);
        {
            struct Rec r;
            struct Part p;
            p = DAT_00020000.nv.p;
            r = DAT_00020000.nv.r;
            FUN_a0140e74(0, 0x440, 0x30, &p, 0);
            FUN_a0140e74(0, 0x470, 0x50, &r, 1);
        }
    } else if (check() == 1) {
        FUN_a00df170(s_001a7608, 1);
        {
            struct Rec r;
            struct Part p;
            p = DAT_00020000.nv.p;
            r = DAT_00020000.nv.r;
            FUN_a0140e74(0, 0x440, 0x30, &p, 0);
            FUN_a0140e74(0, 0x470, 0x50, &r, 1);
        }
    } else if (check() == 2) {
        {
            unsigned char pat[16];
            struct Rec r;
            unsigned short i, n;
            FUN_a00df170(s_001a7608, 2);
            FUN_a013c910(pat, s_001a75e6, 16);
            n = 0x140;
            for (i = 0; i < n / 16; i++)
                FUN_a0140e74(0, 0x300 + (i << 4), 16, pat, 0);
            n = n - (i << 4);
            if (n != 0)
                FUN_a0140e74(0, 0x300 + (i << 4), n, pat, 0);
            FUN_a0140360(0, 0x470, 0x50, &r);
            r.h38 = DAT_00020000.nv.r.h38;
            r.b1a = DAT_00020000.nv.r.b1a;
            r.h3e = DAT_00020000.nv.r.h3e;
            r.h40 = DAT_00020000.nv.r.h40;
            r.chk = FUN_a012ce18();
            FUN_a0140e74(0, 0x470, 0x50, &r, 1);
        }
    }
    FUN_a0140360(0, 0x440, 0x30, &DAT_a802e1f0);
    FUN_a0140360(0, 0x470, 0x50, &DAT_a802e1a0);
    if (DAT_00020000.nv.p.magic1 != 0xa5a5) {
        FUN_a00df170(s_001a7648, 3);
        for (;;)
            ;
    }
    if (DAT_00020000.nv.r.magic2 != DAT_00020000.nv.p.magic1) {
        FUN_a00df170(s_001a7648, 4);
        for (;;)
            ;
    }
    if (DAT_a802cc4c != 0)
        DAT_a802cc4c();
}
