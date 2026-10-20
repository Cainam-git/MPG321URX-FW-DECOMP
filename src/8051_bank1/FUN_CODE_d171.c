/* 8051_bank1 FUN_CODE_d171 @ 0xd171 (55 B)  Byte-exact with OPTIMIZE(7,SPEED).
 * Saves XDATA 0xD5E0 and sets it to 0x22, clears 0xD5E1, 0xD5E2 and 0xBFF3, then writes the 0x11A bytes of
 * XDATA 0x3E00..0x3F19 one after another to the same byte 0xD5E3, and finally restores 0xD5E0.
 * The index is a 16-bit counter in R4:R5 ('i < 0x11a' compiles to the two CJNE tests on R4 and R5).
 * The bank 1 listing has no LCALL or LJMP to this address.
 */
extern unsigned char xdata DAT_EXTMEM_d5e0, DAT_EXTMEM_d5e1, DAT_EXTMEM_d5e2, DAT_EXTMEM_d5e3, DAT_EXTMEM_bff3;
extern unsigned char xdata DAT_EXTMEM_3e00[];

void FUN_CODE_d171(void)
{
    unsigned char save;
    unsigned int i;

    save = DAT_EXTMEM_d5e0;
    DAT_EXTMEM_d5e0 = 0x22;
    DAT_EXTMEM_d5e1 = 0;
    DAT_EXTMEM_d5e2 = 0;
    DAT_EXTMEM_bff3 = 0;
    for (i = 0; i < 0x11a; i++)
        DAT_EXTMEM_d5e3 = DAT_EXTMEM_3e00[i];
    DAT_EXTMEM_d5e0 = save;
}
