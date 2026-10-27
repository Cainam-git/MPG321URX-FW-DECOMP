/* 8051_bank1 FUN_CODE_9d75 @ 0x9d75 (202 B)
 * k = FUN_CODE_dee2(); for the ten 3-byte records at XDATA 0xA62F (fields a, b, c): when (a & 0x1F) is 1..6,
 * r is set if bit (c & 0x0F) or bit (c >> 4) of k is set; when (a & 0x1F) is 7..10, r is set if bit (c & 0x0F)
 * of k is set. Returns r (bit, cleared first).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: each shift count goes to its own local (c, d, e), then the value 1 is written to ACC (reg51.h);
 * Keil then knows A = 1 and the shift starts 'MOV A,#01H; MOV R6,#00H; MOV R0,AR7'.
 */
#include <reg51.h>
struct ent3 { unsigned char a, b, c; };
extern struct ent3 xdata DAT_EXTMEM_a62f[10];
extern unsigned char FUN_CODE_dee2(void);

bit FUN_CODE_9d75(void)
{
    bit r;
    unsigned char k, i, c, d, e;

    r = 0;
    k = FUN_CODE_dee2();
    for (i = 0; i != 10; i++) {
        if ((DAT_EXTMEM_a62f[i].a & 0x1f) >= 1 && (DAT_EXTMEM_a62f[i].a & 0x1f) < 7) {
            c = DAT_EXTMEM_a62f[i].c & 0x0f;
            ACC = 1;
            if ((1 << c) & k) r = 1;
            else {
                d = DAT_EXTMEM_a62f[i].c >> 4;
                ACC = 1;
                if ((1 << d) & k) r = 1;
            }
        } else if ((DAT_EXTMEM_a62f[i].a & 0x1f) >= 7 && (DAT_EXTMEM_a62f[i].a & 0x1f) < 11) {
            e = DAT_EXTMEM_a62f[i].c & 0x0f;
            ACC = 1;
            if ((1 << e) & k) r = 1;
        }
    }
    return r;
}
