/* 8051_bank1 FUN_CODE_b192 @ 0xb192  MATCH (OPTIMIZE(7,SPEED))
 * Here's the fix:
 */
extern void FUN_CODE_dc51(void);
extern void FUN_CODE_dc67(void);

extern volatile unsigned char DAT_EXTMEM_f0e6;
extern volatile unsigned char DAT_EXTMEM_f0ea;
extern volatile unsigned char DAT_EXTMEM_f0eb;
extern volatile unsigned char DAT_EXTMEM_f0ec;
extern volatile unsigned char DAT_EXTMEM_f0ed;
extern volatile unsigned char DAT_EXTMEM_f0f0;
extern volatile unsigned char DAT_EXTMEM_f0f1;
extern volatile unsigned char DAT_EXTMEM_f0f2;
extern volatile unsigned char DAT_EXTMEM_f0f4;
extern volatile unsigned char DAT_EXTMEM_f0e5;
extern volatile unsigned char DAT_EXTMEM_f1c0;

void FUN_CODE_b192(unsigned char a, unsigned char b, unsigned char c) large {
    unsigned char i = 0;
    unsigned char v;
    unsigned char xdata *buf;
    
    FUN_CODE_dc51();
    buf = (unsigned char xdata *)0x3200;
    
    DAT_EXTMEM_f0ea = 0x0B;
    v = (DAT_EXTMEM_f0e6 & 0x0C) | 0x01;
    DAT_EXTMEM_f0e6 = v;
    DAT_EXTMEM_f0eb = 0;
    DAT_EXTMEM_f0ec = 1;
    DAT_EXTMEM_f0ed = 0;
    
    DAT_EXTMEM_f0f0 = a;
    DAT_EXTMEM_f0f1 = b;
    DAT_EXTMEM_f0f2 = c;
    
    DAT_EXTMEM_f0f4 = 0x0B;
    DAT_EXTMEM_f1c0 = 0x81;
    DAT_EXTMEM_f0e5 = 0x02;
    
    while ((unsigned int)(DAT_EXTMEM_f0e5 & 0x02));
    
    DAT_EXTMEM_f1c0 = 0x82;
    v = DAT_EXTMEM_f1c0;
    i = 0;
    
    do {
        v = DAT_EXTMEM_f1c0;
        buf[i] = v;
        i++;
    } while (i != 0);
    
    FUN_CODE_dc67();
}
