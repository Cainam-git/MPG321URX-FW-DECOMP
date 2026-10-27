/* 8051_bank1 FUN_CODE_d4b0 @ 0xd4b0 (49 B)
 * When XDATA 0xD511 is 0x20: XDATA 0xF40E = (1 << n) | (0x10 << n); then, when bit 0 of XDATA 0x7E7A is set,
 * writes the byte back (read again) and returns 1. Returns 0 otherwise.
 * The three XDATA bytes are volatile: 0x7E7A is read twice and written back unchanged.
 * Options: OPTIMIZE(7,SPEED) (also level 8).
 * Source form: each shifted constant is written to ACC (reg51.h) and the shift reads ACC, so Keil loads A
 * ('MOV A,#10H', 'MOV A,#01H') before the count ('MOV R0,AR7'); the 0x10 term is computed first into a local.
 */
#include <reg51.h>

extern unsigned char volatile xdata DAT_EXTMEM_d511, DAT_EXTMEM_f40e, DAT_EXTMEM_7e7a;

bit FUN_CODE_d4b0(unsigned char n)
{
    unsigned char t;

    if (DAT_EXTMEM_d511 == 0x20) {
        ACC = 0x10;
        t = ACC << n;
        ACC = 1;
        DAT_EXTMEM_f40e = (ACC << n) | t;
        if (DAT_EXTMEM_7e7a & 1) {
            DAT_EXTMEM_7e7a = DAT_EXTMEM_7e7a;
            return 1;
        }
    }
    return 0;
}
