/* 8051_bank1 FUN_CODE_9f04 @ 0x9f04  OPTIMIZE(7,SPEED)
 * The key change is that the call to FUN_CODE_2820 now passes a single generic pointer (0xffdd52) rather than three separate byte arguments. This should make Keil generate the MOV R3,#0xff; MOV R2,#0xdd; MOV R1,#0x52 sequence to load the pointer into R1:R2:R3 (the generic pointer registers) before the LCALL.
 */
extern unsigned char xdata DAT_EXTMEM_f040 _at_ 0xf040;
extern unsigned char xdata DAT_EXTMEM_f03d _at_ 0xf03d;
extern unsigned char xdata DAT_EXTMEM_f03b _at_ 0xf03b;
extern unsigned char xdata DAT_EXTMEM_f048 _at_ 0xf048;
extern unsigned char xdata DAT_EXTMEM_f045 _at_ 0xf045;
extern unsigned char xdata DAT_EXTMEM_f043 _at_ 0xf043;
extern unsigned char xdata DAT_EXTMEM_f090 _at_ 0xf090;
extern unsigned char xdata DAT_EXTMEM_f08d _at_ 0xf08d;
extern unsigned char xdata DAT_EXTMEM_f08b _at_ 0xf08b;
extern unsigned char xdata DAT_EXTMEM_f098 _at_ 0xf098;
extern unsigned char xdata DAT_EXTMEM_f095 _at_ 0xf095;
extern unsigned char xdata DAT_EXTMEM_f093 _at_ 0xf093;
extern unsigned char xdata DAT_EXTMEM_f0a2 _at_ 0xf0a2;
extern unsigned char xdata DAT_EXTMEM_f09f _at_ 0xf09f;
extern unsigned char xdata DAT_EXTMEM_f09d _at_ 0xf09d;
extern unsigned char xdata DAT_EXTMEM_f0bf _at_ 0xf0bf;
extern unsigned char xdata DAT_EXTMEM_f0bc _at_ 0xf0bc;
extern unsigned char xdata DAT_EXTMEM_f0ba _at_ 0xf0ba;
extern unsigned char xdata DAT_EXTMEM_f147 _at_ 0xf147;
extern unsigned char xdata DAT_EXTMEM_f144 _at_ 0xf144;
extern unsigned char xdata DAT_EXTMEM_f142 _at_ 0xf142;
extern unsigned char xdata DAT_EXTMEM_f01b _at_ 0xf01b;
extern unsigned char xdata DAT_EXTMEM_f018 _at_ 0xf018;
extern unsigned char xdata DAT_EXTMEM_f016 _at_ 0xf016;

extern void FUN_CODE_2820(void *fmt, ...) large; // at 0x2820

void FUN_CODE_9f04(unsigned char param_1) 
{
    unsigned char mask = param_1;
    
    if (mask & 0x01) {
        DAT_EXTMEM_f040 |= 0x01;
        DAT_EXTMEM_f03d = 0xff;
        DAT_EXTMEM_f03b = 0xf8;
    }
    if (mask & 0x02) {
        DAT_EXTMEM_f048 |= 0x01;
        DAT_EXTMEM_f045 = 0xff;
        DAT_EXTMEM_f043 = 0xf8;
    }
    if (mask & 0x04) {
        DAT_EXTMEM_f090 |= 0x01;
        DAT_EXTMEM_f08d = 0xff;
        DAT_EXTMEM_f08b = 0xf8;
    }
    if (mask & 0x08) {
        DAT_EXTMEM_f098 |= 0x01;
        DAT_EXTMEM_f095 = 0xff;
        DAT_EXTMEM_f093 = 0xf8;
    }
    if (mask & 0x10) {
        DAT_EXTMEM_f0a2 |= 0x01;
        DAT_EXTMEM_f09f = 0xff;
        DAT_EXTMEM_f09d = 0xf8;
    }
    if (mask & 0x20) {
        DAT_EXTMEM_f0bf |= 0x01;
        DAT_EXTMEM_f0bc = 0xff;
        DAT_EXTMEM_f0ba = 0xf8;
    }
    if (mask & 0x40) {
        DAT_EXTMEM_f147 |= 0x01;
        DAT_EXTMEM_f144 = 0xff;
        DAT_EXTMEM_f142 = 0xf8;
    }
    if (mask & 0x80) {
        FUN_CODE_2820((void code *)0xffdd52);
        DAT_EXTMEM_f01b |= 0x01;
        DAT_EXTMEM_f018 = 0xff;
        DAT_EXTMEM_f016 = 0xf8;
    }
}
