/* 8051_bank1 FUN_CODE_d1de @ 0xd1de
 * XDATA 0xF04F = 0x10 then 0x11; 0xD570 = 0x80, 0x60, 0x40; 0xD571..0xD577 = 00 00 20 00 00 00 00 (INC DPTR run, so
 * one array); 0xCC8B &= 0xF7; tail printf "0x4570[5] toggle ==> warm Rese..." (code string 0xcec2, FUN_CODE_2820).
 * volatile is real for 0xF04F and 0xD570: the firmware writes them two / three times in a row.
 * Options: OPTIMIZE(8,SPEED).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f04f;
extern unsigned char volatile xdata DAT_EXTMEM_d570[];
extern unsigned char xdata DAT_EXTMEM_cc8b;
extern void FUN_CODE_2820(void *fmt, ...) large;
void FUN_CODE_d1de(void)
{
    DAT_EXTMEM_f04f = 0x10;
    DAT_EXTMEM_f04f = 0x11;
    DAT_EXTMEM_d570[0] = 0x80;
    DAT_EXTMEM_d570[0] = 0x60;
    DAT_EXTMEM_d570[0] = 0x40;
    DAT_EXTMEM_d570[1] = 0;
    DAT_EXTMEM_d570[2] = 0;
    DAT_EXTMEM_d570[3] = 0x20;
    DAT_EXTMEM_d570[4] = 0;
    DAT_EXTMEM_d570[5] = 0;
    DAT_EXTMEM_d570[6] = 0;
    DAT_EXTMEM_d570[7] = 0;
    DAT_EXTMEM_cc8b &= 0xf7;
    FUN_CODE_2820((void code *)0xcec2);
}
