/* leon2m FUN_a012a774 @ 0xa012a774-0xa012ad64 (1520 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a01492b8,
 * FUN_a014c7bc, FUN_a0153018.
 * m != 0: words 0xa802ca08 = 0 and halfword 0xa802ca12 = 0, the 16 bytes of table 0x1a4ea8 are copied to
 * 0xa802cae0 and summed into 0xa802ca12. Returns unless byte 7 of 0xa802e3d0 is 1. old = FUN_a00f6cf4();
 * FUN_a00f76dc(m, 0xa802ca5c); the sum of the 16 words at 0xa802ca5c goes to word 0xa802ca0c.
 * m != 0: FUN_a00f7894({0, 0, 0x10}) and setlvl((byte 8 of 0xa802e3d0 * 0x3ff + 0x32) / 100).
 * m == 0: with r = FUN_a01448fc(0) and FUN_a00f62ac(0) != 0, a/b/c = FUN_a00f6340/635c/6378(0) set or clear
 * byte 0xa802ca18 (bit 0 of r clear: b <= 0x10 sets, b > 0x13 clears; else all below 4 sets, any above 7 clears);
 * FUN_a011996c(0) != 0 or byte 0xa802e1a7 not 0 or 2 clears it. Byte 0xa802ca18 == 0: halfword 0xa802ca16 =
 * func_0x4008d588(), and a set byte 0xa802ca14 is cleared with FUN_a01249ec() and setlvl(0). Otherwise, when
 * func_0x4008d594(0xa802ca16) > 10000: 0xa802ca16 = func_0x4008d588(), and a clear 0xa802ca14 is set with
 * FUN_a0143804(0x20) and FUN_a0124a08(). Then, with 0xa802ca14 == 0 and 0xa802ca0c != 0: q = (sum - word 0) *
 * 0x3ff / sum (64-bit product) is stored in halfword 0xa802caf0 when it differs (limited to 0x3ff); with cur =
 * halfword 0xa802caf2 and tgt = 0xa802caf0, when cur - tgt + 5 > 10 (unsigned) or byte 0xa802ca19 is set, 0xa802ca19
 * = 1 and cur moves by 4 towards tgt (not past it, not below 0 or 0xa802caf0) into 0xa802caf2 followed by
 * put(0xa802caf2), or 0xa802ca19 = 0 when cur == tgt. Finally FUN_a00f63bc(old).
 * setlvl(v): lim = 0x3ff; without the hook word at 0xa802cc1c + 0x34, 0xa802caf2 = v, else hook(&lim) and
 * 0xa802caf2 = v * 0x3ff / lim; then put(0xa802caf2). put(v): v = v * 0x381 / 0x3ff + 0x7e, hook(&v) when set,
 * FUN_a0143804(v).
 * Source form: put and setlvl are static helpers inlined by GCC; cur and tgt are declared with initializers in
 * their own inner block (this decides the register of the 0xa802caf2 address copy, %o7); 0xa802ca19 and 0xa802caf0
 * are named DAT_A802CA19 / DAT_A802CAF0 (the symbol names set GCSE's register order).
 * Compiler aid: the 'for (;;) break;' after the 0xa802ca12 clear and the one after the 0xa802caf0 = q store emit no
 * instructions; each ends a basic block there, which gives the firmware's instruction order at the start of the
 * copy loop and around the 0x3ff limit store.
 */
struct Arg { unsigned char a, b, m; };
struct Hooks { unsigned char p00[0x34]; void (*f34)(unsigned short *); };

extern struct Hooks DAT_a802cc1c;
extern unsigned char DAT_a802e3d0[];
extern unsigned char DAT_a802e1a7;
extern const unsigned char DAT_001a4ea8[16];
extern unsigned char DAT_a802cae0[16];
extern int DAT_a802ca08;
extern int DAT_a802ca0c;
extern unsigned short DAT_a802ca12;
extern unsigned char DAT_a802ca14;
extern unsigned short DAT_a802ca16;
extern unsigned char DAT_a802ca18;
extern unsigned char DAT_A802CA19;
extern int DAT_a802ca5c[16];
extern unsigned short DAT_A802CAF0;
extern unsigned short DAT_a802caf2;

extern unsigned char FUN_a00f6cf4(void);
extern void FUN_a00f76dc(unsigned char, int *);
extern void FUN_a00f7894(struct Arg);
extern void FUN_a00f63bc(unsigned char);
extern unsigned char FUN_a01448fc(unsigned char);
extern unsigned char FUN_a00f62ac(unsigned char);
extern unsigned char FUN_a00f6340(unsigned char);
extern unsigned char FUN_a00f635c(unsigned char);
extern unsigned char FUN_a00f6378(unsigned char);
extern unsigned char FUN_a011996c(unsigned char);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);
extern void FUN_a0143804(unsigned short);
extern void FUN_a01249ec(void);
extern void FUN_a0124a08(void);

static void put(unsigned short v)
{
    v = v * 0x381U / 0x3ff + 0x7e;
    if (DAT_a802cc1c.f34 != 0)
        DAT_a802cc1c.f34(&v);
    FUN_a0143804(v);
}

static void setlvl(unsigned short v)
{
    unsigned short lim;

    lim = 0x3ff;
    if (DAT_a802cc1c.f34 == 0)
        DAT_a802caf2 = v;
    else {
        DAT_a802cc1c.f34(&lim);
        DAT_a802caf2 = v * 0x3ffU / lim;
    }
    put(DAT_a802caf2);
}

void FUN_a012a774(unsigned char m)
{
    unsigned char i, old;
    struct Arg s;

    if (m != 0) {
        const unsigned char *p = DAT_001a4ea8;
        DAT_a802ca08 = 0;
        DAT_a802ca12 = 0;
        for (;;) break;
        for (i = 0; i < 16; i++) {
            DAT_a802cae0[i] = p[i];
            DAT_a802ca12 += p[i];
        }
    }
    if (DAT_a802e3d0[7] != 1)
        return;
    old = FUN_a00f6cf4();
    FUN_a00f76dc(m, DAT_a802ca5c);
    DAT_a802ca0c = 0;
    for (i = 0; i < 16; i++)
        DAT_a802ca0c += DAT_a802ca5c[i];
    if (m != 0) {
        s.m = 0x10;
        s.b = 0;
        s.a = 0;
        FUN_a00f7894(s);
        setlvl((DAT_a802e3d0[8] * 0x3ffU + 0x32) / 100);
    } else {
        unsigned char r, a, b, c;
        unsigned short q;

        r = FUN_a01448fc(0);
        if (FUN_a00f62ac(0) != 0) {
            a = FUN_a00f6340(0);
            b = FUN_a00f635c(0);
            c = FUN_a00f6378(0);
            if (!(r & 1)) {
                if (b <= 0x10)
                    DAT_a802ca18 = 1;
                if (b > 0x13)
                    DAT_a802ca18 = 0;
            } else if (a < 4 && b < 4 && c < 4)
                DAT_a802ca18 = 1;
            else if (a > 7 || b > 7 || c > 7)
                DAT_a802ca18 = 0;
        }
        if (FUN_a011996c(0) != 0 || (DAT_a802e1a7 != 0 && DAT_a802e1a7 != 2))
            DAT_a802ca18 = 0;
        if (DAT_a802ca18 == 0) {
            DAT_a802ca16 = func_0x4008d588();
            if (DAT_a802ca14 != 0) {
                DAT_a802ca14 = 0;
                FUN_a01249ec();
                setlvl(0);
            }
        } else if (func_0x4008d594(DAT_a802ca16) > 10000) {
            DAT_a802ca16 = func_0x4008d588();
            if (DAT_a802ca14 == 0) {
                DAT_a802ca14 = 1;
                FUN_a0143804(0x20);
                FUN_a0124a08();
            }
        }
        if (DAT_a802ca14 == 0 && DAT_a802ca0c != 0) {
            q = (unsigned long long)(unsigned int)(DAT_a802ca0c - DAT_a802ca5c[0]) * 0x3ff
                / (unsigned int)DAT_a802ca0c;
            if (q != DAT_A802CAF0) {
                if (q == 0)
                    DAT_A802CAF0 = 0;
                else {
                    DAT_A802CAF0 = q;
                    for (;;) break;
                    if (q > 0x3ff)
                        DAT_A802CAF0 = 0x3ff;
                }
            }
            {
                unsigned short cur = DAT_a802caf2;
                unsigned short tgt = DAT_A802CAF0;
                if (cur - tgt + 5U > 10 || DAT_A802CA19 != 0) {
                    DAT_A802CA19 = 1;
                    if (cur != tgt) {
                        if (cur < tgt) {
                            cur += 4;
                            if (cur > tgt)
                                DAT_a802caf2 = tgt;
                            else
                                DAT_a802caf2 = cur;
                        } else {
                            if (cur > 4)
                                DAT_a802caf2 = cur - 4;
                            else
                                DAT_a802caf2 = 0;
                            if (DAT_a802caf2 < DAT_A802CAF0)
                                DAT_a802caf2 = DAT_A802CAF0;
                        }
                        put(DAT_a802caf2);
                    } else
                        DAT_A802CA19 = 0;
                }
            }
        }
    }
    FUN_a00f63bc(old);
}
