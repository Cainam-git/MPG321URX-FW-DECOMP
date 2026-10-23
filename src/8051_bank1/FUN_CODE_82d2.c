/* 8051_bank1 FUN_CODE_82d2 @ 0x82d2..0x83f3 (289 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Bit-pattern matcher over a 3-byte state at XDATA 0xA5E6 (st, acc, cnt) and the table at XDATA 0xA5F9 (cfg).
 * Each pass: returns 0 when FUN_CODE_dce3() is nonzero; v = FUN_CODE_d697(). With st == 0 the state starts
 * (st = 2, acc = cnt = 0, FUN_CODE_db05(2, 0)) when FUN_CODE_d969(cfg[0], v, 8) is nonzero. Otherwise cnt counts
 * the samples and acc shifts in one bit per sample (right with the new bit at bit 7 when bit 7 of cfg[1] is set,
 * else left with it at bit 0); the bit is 1 when (cfg[1] & 0x7F) < v (16-bit compare). After 8 samples the byte
 * is accepted when it equals cfg[st] or cfg[st] is 0xFF (FUN_CODE_db05(acc, st - 1), st++, cnt = acc = 0), else
 * st = 0. When st reaches 6, or is at least 2 with cfg[st] == 0, st = 0 and 1 is returned.
 * LARGE locals: v at XDATA 0xA474, buf[16] at 0xA475 (initialised from its 16 zero bytes at CODE 0x9955 with
 * ?C?COPY, not used further).
 * volatile on the cfg table: the firmware reads cfg[1] again after the store to acc and cfg[st] again for the 0xFF
 * test. st, acc and cnt are one 3-byte object (INC DPTR between them).
 * Source form: the 16-bit compare is '(unsigned int)(cfg[1] & 0x7f) < v'; the loop is 'for (;;)' with 'break' to
 * the shared 'return 0' at the end.
 * Caller: FUN_CODE_d2e9 (LCALL at 0xD2FA).
 */
struct match_state { unsigned char st, acc, cnt; };
extern struct match_state xdata DAT_EXTMEM_a5e6;
extern unsigned char volatile xdata DAT_EXTMEM_a5f9[6];
unsigned char FUN_CODE_dce3(void);
unsigned char FUN_CODE_d697(void);
unsigned char FUN_CODE_d969(unsigned char a, unsigned char b, unsigned char c);
void FUN_CODE_db05(unsigned char v, unsigned char i);

unsigned char FUN_CODE_82d2(void)
{
    unsigned char v;
    unsigned char buf[16] = {0};

    for (;;) {
        if (FUN_CODE_dce3())
            break;
        v = FUN_CODE_d697();
        if (DAT_EXTMEM_a5e6.st == 0) {
            if (FUN_CODE_d969(DAT_EXTMEM_a5f9[0], v, 8)) {
                DAT_EXTMEM_a5e6.st = 2;
                DAT_EXTMEM_a5e6.acc = 0;
                DAT_EXTMEM_a5e6.cnt = 0;
                FUN_CODE_db05(2, 0);
            }
        } else {
            DAT_EXTMEM_a5e6.cnt++;
            if (DAT_EXTMEM_a5f9[1] & 0x80) {
                DAT_EXTMEM_a5e6.acc >>= 1;
                if ((unsigned int)(DAT_EXTMEM_a5f9[1] & 0x7f) < v)
                    DAT_EXTMEM_a5e6.acc |= 0x80;
            } else {
                DAT_EXTMEM_a5e6.acc <<= 1;
                if ((unsigned int)(DAT_EXTMEM_a5f9[1] & 0x7f) < v)
                    DAT_EXTMEM_a5e6.acc |= 0x01;
            }
            if (DAT_EXTMEM_a5e6.cnt == 8) {
                if (DAT_EXTMEM_a5e6.acc == DAT_EXTMEM_a5f9[DAT_EXTMEM_a5e6.st] || DAT_EXTMEM_a5f9[DAT_EXTMEM_a5e6.st] == 0xff) {
                    FUN_CODE_db05(DAT_EXTMEM_a5e6.acc, DAT_EXTMEM_a5e6.st - 1);
                    DAT_EXTMEM_a5e6.st++;
                    DAT_EXTMEM_a5e6.cnt = 0;
                    DAT_EXTMEM_a5e6.acc = 0;
                } else {
                    DAT_EXTMEM_a5e6.st = 0;
                }
            }
        }
        if (DAT_EXTMEM_a5e6.st >= 6 || (DAT_EXTMEM_a5e6.st >= 2 && DAT_EXTMEM_a5f9[DAT_EXTMEM_a5e6.st] == 0)) {
            DAT_EXTMEM_a5e6.st = 0;
            return 1;
        }
    }
    return 0;
}
