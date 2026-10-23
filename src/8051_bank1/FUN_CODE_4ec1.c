/* 8051_bank1 FUN_CODE_4ec1 @ 0x4ec1..0x50c9 (520 bytes), OPTIMIZE(8,SPEED) LARGE.
 * State machine on XDATA 0xA35E (0..3); every exit path that gives up writes XDATA 0xF17D = 1 and 0xA35E = 0
 * (one shared tail).
 *   0: p1 / p2 = byte 1 of entry 0xA3E0 / 0xA3E1 of the 2-byte register table at XDATA 0xF180 (only for an index
 *      below 7; otherwise the pointer stays 0). Gives up when neither pointer is usable (pointee bits 6..0 zero or
 *      pointer 0, p2 also must not be 0); the usable one (p2 wins) goes to the pointer at XDATA 0xA6C1. Then bit 0
 *      of 0xDCB0 is set, 0xF17D = 0x81, state 1, and the FUN_CODE_d94a count is stored to 0xA6AA and 0xA6AD,
 *      XDATA 0xA6AC = 0.
 *   1: state 2 after more than 600 counts since 0xA6AA, else state 3 after more than 500 since 0xA6AD, else when
 *      FUN_CODE_db7d(0) or (1) is set 0xA6AD is restarted and bit 1 of 0xDCB0 pulsed; gives up when bits 6..0 of
 *      the byte at the 0xA6C1 pointer are 0.
 *   2: gives up when that byte's bits 6..0 are 0.  3: the same, but only after more than 1200 counts.
 * LARGE locals: p1 at XDATA 0xA473, p2 at 0xA476 (generic pointers, both initialised to 0).
 * volatile: the pointees (register bytes, read again for each test) and 0xDCB0 (read back between the set and
 *   the clear of bit 1).
 * Source form: the pointer tests are written 'p != (void *)0' / 'p == (void *)0' after the pointee test (the
 *   firmware tests the pointee first and then the pointer with the low byte reloaded).
 * Caller: FUN_CODE_3fe7 (LCALL at 0x40CC). The bodies of cases 2 and 3 start at 0x5079 and 0x5091.
 */
struct reg2 { unsigned char lo, hi; };
extern struct reg2 xdata DAT_EXTMEM_f180[7];
extern unsigned char xdata DAT_EXTMEM_a35e;
extern unsigned char xdata DAT_EXTMEM_a3e0, DAT_EXTMEM_a3e1;
extern unsigned char volatile * xdata DAT_EXTMEM_a6c1;
extern unsigned int xdata DAT_EXTMEM_a6aa, DAT_EXTMEM_a6ad;
extern unsigned char xdata DAT_EXTMEM_a6ac;
extern unsigned char xdata DAT_EXTMEM_f17d;
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned int FUN_CODE_d94a(void);
extern bit FUN_CODE_db7d(unsigned char n);

void FUN_CODE_4ec1(void)
{
    unsigned char volatile *p1 = 0;
    unsigned char volatile *p2 = 0;

    switch (DAT_EXTMEM_a35e) {
    case 0:
        if (DAT_EXTMEM_a3e0 < 7)
            p1 = &DAT_EXTMEM_f180[DAT_EXTMEM_a3e0].hi;
        if (DAT_EXTMEM_a3e1 < 7)
            p2 = &DAT_EXTMEM_f180[DAT_EXTMEM_a3e1].hi;
        if ((((*p1 & 0x7f) == 0 || p1 == (void *)0) && (*p2 & 0x7f) == 0) || p2 == (void *)0) {
            DAT_EXTMEM_f17d = 1;
            DAT_EXTMEM_a35e = 0;
            break;
        }
        if ((*p1 & 0x7f) && p1 != (void *)0)
            DAT_EXTMEM_a6c1 = p1;
        if ((*p2 & 0x7f) && p2 != (void *)0)
            DAT_EXTMEM_a6c1 = p2;
        DAT_EXTMEM_dcb0 |= 0x01;
        DAT_EXTMEM_f17d = 0x81;
        DAT_EXTMEM_a35e = 1;
        DAT_EXTMEM_a6aa = FUN_CODE_d94a();
        DAT_EXTMEM_a6ad = FUN_CODE_d94a();
        DAT_EXTMEM_a6ac = 0;
        break;
    case 1:
        if (FUN_CODE_d94a() - DAT_EXTMEM_a6aa > 600)
            DAT_EXTMEM_a35e = 2;
        else if (FUN_CODE_d94a() - DAT_EXTMEM_a6ad > 500)
            DAT_EXTMEM_a35e = 3;
        else if (FUN_CODE_db7d(0) || FUN_CODE_db7d(1)) {
            DAT_EXTMEM_a6ad = FUN_CODE_d94a();
            DAT_EXTMEM_dcb0 |= 0x02;
            DAT_EXTMEM_dcb0 &= ~0x02;
        }
        if ((*DAT_EXTMEM_a6c1 & 0x7f) == 0) {
            DAT_EXTMEM_f17d = 1;
            DAT_EXTMEM_a35e = 0;
        }
        break;
    case 2:
        if ((*DAT_EXTMEM_a6c1 & 0x7f) == 0) {
            DAT_EXTMEM_f17d = 1;
            DAT_EXTMEM_a35e = 0;
        }
        break;
    case 3:
        if (FUN_CODE_d94a() - DAT_EXTMEM_a6aa > 1200) {
            if ((*DAT_EXTMEM_a6c1 & 0x7f) == 0) {
                DAT_EXTMEM_f17d = 1;
                DAT_EXTMEM_a35e = 0;
            }
        }
        break;
    }
}
