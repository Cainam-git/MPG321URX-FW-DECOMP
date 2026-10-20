/* 8051_bank1 FUN_CODE_b56a @ 0xb56a (136 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Register set-up of the XDATA block 0xDCB0..0xDCEA: 0xDCB0..0xDCB3 = 01 2D 37 06, 0xDCB8 = 0xB2, 0xDCCA = 0xDCDA = 4,
 * 0xDCE0..0xDCEA = 0B 17 0B 0C 36 D9 B5 04 0E 08 0E. Then, depending on bit 0x00 (BITS_20_0), sets or clears bit 0 of
 * 0xDCE8 and 0xDCEA and bit 6 of 0xDCDE and 0xDCCE. Only caller FUN_CODE_8a51 (0x8B31).
 * 0xDCB0.. and 0xDCE0.. are written as arrays (one MOV DPTR, then INC DPTR); Keil loads 0x0C as INC A after 0x0B.
 */
extern unsigned char xdata DAT_EXTMEM_dcb0[];
extern unsigned char xdata DAT_EXTMEM_dce0[];
extern unsigned char xdata DAT_EXTMEM_dcb8, DAT_EXTMEM_dcca, DAT_EXTMEM_dcda, DAT_EXTMEM_dcde, DAT_EXTMEM_dcce;
extern bit BITS_20_0;

void FUN_CODE_b56a(void)
{
    DAT_EXTMEM_dcb0[0] = 0x01;
    DAT_EXTMEM_dcb0[1] = 0x2d;
    DAT_EXTMEM_dcb0[2] = 0x37;
    DAT_EXTMEM_dcb0[3] = 0x06;
    DAT_EXTMEM_dcb8 = 0xb2;
    DAT_EXTMEM_dcca = 0x04;
    DAT_EXTMEM_dcda = 0x04;
    DAT_EXTMEM_dce0[0] = 0x0b;
    DAT_EXTMEM_dce0[1] = 0x17;
    DAT_EXTMEM_dce0[2] = 0x0b;
    DAT_EXTMEM_dce0[3] = 0x0c;
    DAT_EXTMEM_dce0[4] = 0x36;
    DAT_EXTMEM_dce0[5] = 0xd9;
    DAT_EXTMEM_dce0[6] = 0xb5;
    DAT_EXTMEM_dce0[7] = 0x04;
    DAT_EXTMEM_dce0[8] = 0x0e;
    DAT_EXTMEM_dce0[9] = 0x08;
    DAT_EXTMEM_dce0[10] = 0x0e;
    if (BITS_20_0) {
        DAT_EXTMEM_dce0[8] |= 0x01;
        DAT_EXTMEM_dcde |= 0x40;
        DAT_EXTMEM_dce0[10] |= 0x01;
        DAT_EXTMEM_dcce |= 0x40;
    } else {
        DAT_EXTMEM_dce0[8] &= ~0x01;
        DAT_EXTMEM_dcde &= ~0x40;
        DAT_EXTMEM_dce0[10] &= ~0x01;
        DAT_EXTMEM_dcce &= ~0x40;
    }
}
