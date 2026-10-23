/* 8051_bank1 FUN_CODE_d1a8 @ 0xd1a8
 * 16-entry ring buffer put: head IDATA 0x43, tail IDATA 0x45, data XDATA 0xA1F8[]; returns 0xFF when full; else with
 * EA off stores c, advances the head (wrap above 0x0F), and when IDATA 0x46 is set clears it and sets TI (restarts the
 * serial transmit interrupt); returns 0. Only caller 0xd517. Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 */
#include <reg51.h>
extern unsigned char idata DAT_INTMEM_43, DAT_INTMEM_45, DAT_INTMEM_46;
extern unsigned char xdata DAT_EXTMEM_a1f8[];
unsigned char FUN_CODE_d1a8(unsigned char c)
{
    unsigned char h;
    h = DAT_INTMEM_43;
    if (((h + 1) & 0x0f) == DAT_INTMEM_45) return 0xff;
    EA = 0;
    DAT_EXTMEM_a1f8[h] = c;
    if (++DAT_INTMEM_43 > 0x0f) DAT_INTMEM_43 = 0;
    if (DAT_INTMEM_46) {
        DAT_INTMEM_46 = 0;
        TI = 1;
    }
    EA = 1;
    return 0;
}
