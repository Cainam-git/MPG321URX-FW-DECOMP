/* 8051_bank1 FUN_CODE_42f6 @ 0x42f6 (692 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Works on the record at XDATA 0xA735: last (unsigned int, 0xA735), s[2] (0xA737), mode (0xA739), u (0xA73A, an
 * XDATA address or two bytes), c[2] = {hi, lo} (0xA73C). Returns when mode is 0; now = FUN_CODE_d94a().
 * mode 1: p = u as an XDATA pointer. When *p equals c[0].hi and (now - last) / 100 > c[0].lo, the bits that differ
 *   between c[0].hi and c[1].hi are taken from c[1].hi in *p; when *p differs from c[0].hi and (now - last) / 100 >
 *   c[1].lo, they are taken from c[0].hi. Otherwise it returns. Then last = now.
 * Other modes: returns unless now - last > 100; last = now; for i = 0, 1 with field = u.b[i] >> 5 not 7:
 *   p = first byte of the 6-byte record [field] at XDATA 0xE84B, cur = *p, step = (s[i] & 0x7F) * (u.b[0] & 0x1F)
 *   / 10 (at least 1), r = (c[i].hi - c[i].lo) / ((u.b[1] & 0x1F) * 5). With bit 7 of s[i] clear, *p moves up by step
 *   (s[i] = step) or to c[i].hi when less than step remains (s[i] = r + 0x80); with bit 7 set, *p moves down by
 *   step (s[i] = step + 0x80) or to c[i].lo (s[i] = r).
 * Caller: FUN_CODE_3fe7 (0x40F9). LARGE locals include k 0xA475, i 0xA477, hi 0xA479, lo 0xA47A, p 0xA47B..0xA47D.
 * volatile on 0xE84B..: outside the XDATA RAM blocks the start-up code clears (0xA000..0xAFFF, 0xF800..0xFFFF),
 *   referenced by no other code, read and rewritten in place through p. Keil therefore stores p and reads it back
 *   before the first access (type byte stored with 'MOV A,#01H').
 * Source form: the record index is written as the expression '(u.b[i] & 0xe0) >> 5' both in the test against 7 and
 *   in the index (Keil reuses the value in R5; a local copy adds 'MOV R7,AR5').
 */
struct S_a735 {
    unsigned int last;
    unsigned char s[2];
    unsigned char mode;
    union { unsigned int addr; unsigned char b[2]; } u;
    struct { unsigned char hi, lo; } c[2];
};
extern struct S_a735 xdata DAT_EXTMEM_a735;
extern struct { unsigned char b[6]; } volatile xdata DAT_EXTMEM_e84b[];
extern unsigned int FUN_CODE_d94a(void);

void FUN_CODE_42f6(void)
{
    unsigned int now;
    unsigned char k;
    unsigned char step;
    unsigned char i;
    unsigned char cur;
    unsigned char hi;
    unsigned char lo;
    unsigned char *p;
    unsigned char v;
    unsigned char m;
    unsigned char r;

    if (DAT_EXTMEM_a735.mode == 0) return;
    now = FUN_CODE_d94a();
    if (DAT_EXTMEM_a735.mode == 1) {
        p = (unsigned char xdata *)DAT_EXTMEM_a735.u.addr;
        if (*p == DAT_EXTMEM_a735.c[0].hi) {
            if ((now - DAT_EXTMEM_a735.last) / 100 <= DAT_EXTMEM_a735.c[0].lo) return;
            m = DAT_EXTMEM_a735.c[0].hi ^ DAT_EXTMEM_a735.c[1].hi;
            v = *p;
            *p = (DAT_EXTMEM_a735.c[1].hi & m) | (v & ~m);
        } else {
            if ((now - DAT_EXTMEM_a735.last) / 100 <= DAT_EXTMEM_a735.c[1].lo) return;
            m = DAT_EXTMEM_a735.c[0].hi ^ DAT_EXTMEM_a735.c[1].hi;
            v = *p;
            *p = (DAT_EXTMEM_a735.c[0].hi & m) | (v & ~m);
        }
        DAT_EXTMEM_a735.last = now;
    } else {
        if (now - DAT_EXTMEM_a735.last <= 100) return;
        DAT_EXTMEM_a735.last = now;
        for (i = 0; i < 2; i++) {
            if (((DAT_EXTMEM_a735.u.b[i] & 0xe0) >> 5) == 7) continue;
            k = DAT_EXTMEM_a735.u.b[0] & 0x1f;
            hi = DAT_EXTMEM_a735.c[i].hi;
            lo = DAT_EXTMEM_a735.c[i].lo;
            p = DAT_EXTMEM_e84b[((DAT_EXTMEM_a735.u.b[i] & 0xe0) >> 5)].b;
            cur = *p;
            step = (unsigned int)((DAT_EXTMEM_a735.s[i] & 0x7f) * k) / 10;
            if (step == 0) step = 1;
            r = (hi - lo) / ((DAT_EXTMEM_a735.u.b[1] & 0x1f) * 5);
            if (!(DAT_EXTMEM_a735.s[i] & 0x80)) {
                if ((unsigned char)(hi - cur) < step) {
                    *p = hi;
                    DAT_EXTMEM_a735.s[i] = r + 0x80;
                } else {
                    *p = cur + step;
                    DAT_EXTMEM_a735.s[i] = step;
                }
            } else {
                if ((unsigned char)(cur - lo) < step) {
                    *p = lo;
                    DAT_EXTMEM_a735.s[i] = r;
                } else {
                    *p = cur - step;
                    DAT_EXTMEM_a735.s[i] = step + 0x80;
                }
            }
        }
    }
}
