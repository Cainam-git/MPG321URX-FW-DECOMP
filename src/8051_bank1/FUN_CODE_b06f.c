/* 8051_bank1 FUN_CODE_b06f @ 0xb06f  MATCH (OPTIMIZE(7,SPEED))
 * Calls FUN_CODE_a142(0), clears bit 0x21.6 (bit address 0x0E), then sets the xdata registers 0xD910, 0xD911 and
 * 0xE1D8 to 0xFF and ORs fixed masks into 0xD904, 0xD90F, 0xD92D, 0xDA00, 0xE1BF, 0xE1CF, 0xE1E0 and 0xE1E2.
 * When the chip ID at xdata 0xD511 is 0x20 it also ORs masks into 0xE1EC, 0xE1EE, 0xE19F, 0xE1AF and 0xE12B.
 * Finally writes 0xA3 to 0xD523, clears bits 2-3 of 0xD52C and bits 1 and 7 of 0xD52D, and calls FUN_CODE_cd07.
 * All data objects are declared xdata.
 */
extern void FUN_CODE_a142(unsigned char);
extern void FUN_CODE_cd07(void);

extern unsigned char xdata DAT_EXTMEM_d910;
extern unsigned char xdata DAT_EXTMEM_d904;
extern unsigned char xdata DAT_EXTMEM_d911;
extern unsigned char xdata DAT_EXTMEM_d90f;
extern unsigned char xdata DAT_EXTMEM_d92d;
extern unsigned char xdata DAT_EXTMEM_da00;
extern unsigned char xdata DAT_EXTMEM_e1bf;
extern unsigned char xdata DAT_EXTMEM_e1cf;
extern unsigned char xdata DAT_EXTMEM_e1d8;
extern unsigned char xdata DAT_EXTMEM_e1e0;
extern unsigned char xdata DAT_EXTMEM_e1e2;
extern unsigned char xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_e1ec;
extern unsigned char xdata DAT_EXTMEM_e1ee;
extern unsigned char xdata DAT_EXTMEM_e19f;
extern unsigned char xdata DAT_EXTMEM_e1af;
extern unsigned char xdata DAT_EXTMEM_e12b;
extern unsigned char xdata DAT_EXTMEM_d523;
extern unsigned char xdata DAT_EXTMEM_d52c;
extern unsigned char xdata DAT_EXTMEM_d52d;

unsigned char bdata byte_0x21 _at_ 0x21;
sbit BIT_0x0E = byte_0x21 ^ 6;

void FUN_CODE_b06f(void)
{
    FUN_CODE_a142(0);
    BIT_0x0E = 0;
    
    DAT_EXTMEM_d910 = 0xff;
    DAT_EXTMEM_d904 |= 0xfe;
    DAT_EXTMEM_d911 = 0xff;
    DAT_EXTMEM_d90f |= 0x80;
    DAT_EXTMEM_d92d |= 0xc0;
    DAT_EXTMEM_da00 |= 0x01;
    DAT_EXTMEM_e1bf |= 0x80;
    DAT_EXTMEM_e1cf |= 0x80;
    DAT_EXTMEM_e1d8 = 0xff;
    DAT_EXTMEM_e1e0 |= 0x7f;
    DAT_EXTMEM_e1e2 |= 0x70;
    
    if (DAT_EXTMEM_d511 == 0x20) {
        DAT_EXTMEM_e1ec |= 0x7f;
        DAT_EXTMEM_e1ee |= 0x7f;
        DAT_EXTMEM_e19f |= 0x80;
        DAT_EXTMEM_e1af |= 0x80;
        DAT_EXTMEM_e12b |= 0x80;
    }
    
    DAT_EXTMEM_d523 = 0xa3;
    DAT_EXTMEM_d52c &= 0xf3;
    DAT_EXTMEM_d52d &= 0x7d;
    
    FUN_CODE_cd07();
}
