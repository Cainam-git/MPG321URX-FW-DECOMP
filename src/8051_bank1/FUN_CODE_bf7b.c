/* FUN_CODE_bf7b, 8051_bank1, range 0xBF7B..0xBFDD (98 B).
 * Options: OPTIMIZE(8,SPEED) (also with REGFILE(R.ORC) added).
 * Code facts: one transfer on the register block at 0xD800: 0xD80D = 0x2E (status / command), 0xD820 = a (R7),
 * 0xD810 = d (R5). The start tick FUN_CODE_d94a() (uint tick counter) is kept in the global uint 0xA484. It then
 * waits while none of the status bits 0x2E of 0xD80D is set, writing 0x55 to 0xF00A and 0xF0E0 on every pass,
 * for at most 1000 ticks (d94a() - start <= 1000, test after each pass). Then it reads 0xD80D once, writes 0x2E
 * back, and returns 3 when a bit of 0x2C was set, 0 when bit 1 was set, else 3 (timeout).
 * Same bytes without volatile (Keil re-reads XDATA in the loop), so none is used. Caller: FUN_CODE_78ba (0x79EC).
 * No aids.
 */
extern unsigned char xdata DAT_EXTMEM_d80d;
extern unsigned char xdata DAT_EXTMEM_d810;
extern unsigned char xdata DAT_EXTMEM_d820;
extern unsigned char xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_f0e0;
extern unsigned int xdata DAT_EXTMEM_a484;
unsigned int FUN_CODE_d94a(void);
unsigned char FUN_CODE_bf7b(unsigned char a, unsigned char d)
{
    unsigned char s;
    DAT_EXTMEM_d80d = 0x2e;
    DAT_EXTMEM_d820 = a;
    DAT_EXTMEM_d810 = d;
    DAT_EXTMEM_a484 = FUN_CODE_d94a();
    do {
        if (DAT_EXTMEM_d80d & 0x2e) break;
        DAT_EXTMEM_f00a = 0x55;
        DAT_EXTMEM_f0e0 = 0x55;
    } while (FUN_CODE_d94a() - DAT_EXTMEM_a484 <= 1000);
    s = DAT_EXTMEM_d80d;
    DAT_EXTMEM_d80d = 0x2e;
    if (s & 0x2c) return 3;
    if (s & 0x02) return 0;
    return 3;
}
