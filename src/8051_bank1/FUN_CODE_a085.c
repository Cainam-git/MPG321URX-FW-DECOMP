/* 8051_bank1 FUN_CODE_a085 @ 0xa085 (189 B)
 * Over the six 2-byte entries of XDATA 0xA611 while entry byte 0 is 0x10..0x1F: e = the entry, and when the bit
 * result of FUN_CODE_af47(e[0] - 0x10, 1 << (e[1] & 0x0F)) equals bit 4 of e[1], FUN_CODE_2820 is called with the
 * string at CODE 0x98D2 ("Key%02X : %02X %02X\r\n") and i, e[0], e[1], and i is returned. Otherwise returns 0xFF.
 * LARGE locals: i at XDATA 0xA473, r at 0xA474, e at 0xA475..0xA476.
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * volatile: the firmware reads the entry again after the range test (same in FUN_CODE_b881, FUN_CODE_5a39, FUN_CODE_a142).
 * Source form: the call arguments go to locals first (n, c), then the value 1 is written to ACC (reg51.h) and the
 * mask is 'ACC << c', so Keil loads A ('MOV A,#01H') before the count ('MOV R0,AR6'). The comparison is cast to
 * unsigned char (its 0/1 value goes to R7 before the test).
 */
#include <reg51.h>
extern volatile unsigned char xdata DAT_EXTMEM_a611[6][2];
extern void FUN_CODE_2820(void *fmt, ...) large;
bit FUN_CODE_af47(unsigned char n, unsigned char mask);

unsigned char FUN_CODE_a085(void)
{
    unsigned char i, r;
    unsigned char e[2];
    unsigned char n, c;

    r = 0xff;
    for (i = 0; i < 6; i++) {
        if ((unsigned char)(DAT_EXTMEM_a611[i][0] + 0xf0) <= 0x0f) {
            e[0] = DAT_EXTMEM_a611[i][0];
            e[1] = DAT_EXTMEM_a611[i][1];
            n = e[0] - 0x10;
            c = e[1] & 0x0f;
            ACC = 1;
            if ((unsigned char)(FUN_CODE_af47(n, ACC << c) == ((e[1] & 0x10) >> 4))) {
                FUN_CODE_2820((void code *)0x98d2, i, e[0], e[1]);
                r = i;
                break;
            }
        } else break;
    }
    return r;
}
