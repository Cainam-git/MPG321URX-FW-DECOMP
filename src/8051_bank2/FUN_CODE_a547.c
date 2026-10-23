/* FUN_CODE_a547, 8051_bank2 (helper chip updater), range 0xA547..0xA6FA (435 B; functions.json size 434 is 1 short).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Code facts: only when FUN_CODE_db76() returns 1 (carry): reads one byte (abce(buf 0x08F2, e4e9(), 1, 0), then
 * bf1b(0x08FB, 1)) as the record count DAT_EXTMEM_042e, clears the ulong 0x0113, and for each record i
 * (local i at 0x08F1) sets rec[i].a (0x0652 + 8 i, ulong) to 1 for i = 0, else rec[i-1].a + (rec[i-1].b + 32) / 32
 * (?C?ULDIV); reads at rec[i].a + e4e9() and stores bf1b(0x08F6, 4) as rec[i].b; for i > 0 it adds
 * d7d0(rec[i].b) (bytes rounded up to 256-byte units) to 0x0113; for the last record it also stores
 * bf1b(0x08F2, 4) to the ulong 0x042F and the low byte of bf1b(0x08F6, 4) to 0x0433. The i == 0 arm still indexes
 * rec[i] (MUL by 8) and cross-jumps into the shared e4e9 tail.
 * Aid (documented, no code): the three buffers are named by firmware address (DAT_EXTMEM_08f2[4], 08f6[4], 08fb[1],
 * as for e384 / df7f). They sit in this function's LARGE block (i = 0x08F1 is its first local) and the
 * true local-array forms give the SAME bytes (the variants 'i; a[4]; b[5]; c[1]' and 'i; a[4]; b[4]; x; c[1]'
 * both MATCH), but the byte 0x08FA between b and c is never used by the code, so which declaration fills
 * it cannot be read from the firmware; the extern form invents nothing.
 * struct rec { ulong a; ulong b; } at 0x0652 is the one in src/8051_bank2/FUN_CODE_8437.c. Callee prototypes as in
 * the other src files (abce small, bf1b, d7d0, e4e9, db76). Caller: FUN_CODE_9d97 (0x9F89).
 */
struct rec { unsigned long a; unsigned long b; };
extern struct rec xdata DAT_EXTMEM_0652[20];
extern unsigned char xdata DAT_EXTMEM_042e;
extern unsigned long xdata DAT_EXTMEM_042f;
extern unsigned char xdata DAT_EXTMEM_0433;
extern unsigned long xdata DAT_EXTMEM_0113;
extern unsigned char xdata DAT_EXTMEM_08f2[4];
extern unsigned char xdata DAT_EXTMEM_08f6[4];
extern unsigned char xdata DAT_EXTMEM_08fb[1];
bit FUN_CODE_db76(void);
extern unsigned long FUN_CODE_e4e9(void);
extern void FUN_CODE_abce(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
unsigned long FUN_CODE_bf1b(unsigned char *p, unsigned char n);
unsigned long FUN_CODE_d7d0(unsigned long n);
void FUN_CODE_a547(void)
{
    unsigned char i;
    if (FUN_CODE_db76()) {
        FUN_CODE_abce(DAT_EXTMEM_08f2, FUN_CODE_e4e9(), 1, 0);
        DAT_EXTMEM_042e = FUN_CODE_bf1b(DAT_EXTMEM_08fb, 1);
        DAT_EXTMEM_0113 = 0;
        for (i = 0; i < DAT_EXTMEM_042e; i++) {
            if (i == 0) DAT_EXTMEM_0652[i].a = 1;
            else DAT_EXTMEM_0652[i].a = DAT_EXTMEM_0652[i - 1].a + (DAT_EXTMEM_0652[i - 1].b + 32) / 32;
            FUN_CODE_abce(DAT_EXTMEM_08f2, DAT_EXTMEM_0652[i].a + FUN_CODE_e4e9(), 1, 0);
            DAT_EXTMEM_0652[i].b = FUN_CODE_bf1b(DAT_EXTMEM_08f6, 4);
            if (i > 0) DAT_EXTMEM_0113 += FUN_CODE_d7d0(DAT_EXTMEM_0652[i].b);
            if (i == DAT_EXTMEM_042e - 1) {
                DAT_EXTMEM_042f = FUN_CODE_bf1b(DAT_EXTMEM_08f2, 4);
                DAT_EXTMEM_0433 = FUN_CODE_bf1b(DAT_EXTMEM_08f6, 4);
            }
        }
    }
}
