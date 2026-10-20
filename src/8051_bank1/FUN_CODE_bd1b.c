/* 8051_bank1 FUN_CODE_bd1b @ 0xbd1b (102 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Through the generic pointers at XDATA 0xA709 (source) and 0xA701 (target): *target = *target | *source | mask,
 * mask = XDATA 0xA705. Then waits until *target & mask reads non-zero, at most 65535 rounds with a short
 * 10-step busy loop each; the round counter is the 16-bit IDATA variable 0x60..0x61 (MOV R0,#60H / @R0).
 * Callers: FUN_CODE_8c5d (0x8CB0, 0x8D54), FUN_CODE_97c4 (0x97EB, 0x982F), FUN_CODE_c6ec (0xC711).
 * The OR is two statements on a byte temporary, 'v = *source; v = *target | v;': this keeps the target pointer in
 * R1..R3 for the store ('v |= *target' gives ORL direct,A; one expression reloads the pointer).
 */
extern unsigned char * xdata DAT_EXTMEM_a709;
extern unsigned char * xdata DAT_EXTMEM_a701;
extern unsigned char xdata DAT_EXTMEM_a705;
extern unsigned int idata DAT_INTMEM_60;

void FUN_CODE_bd1b(void)
{
    unsigned int j;
    unsigned char v;

    v = *DAT_EXTMEM_a709;
    v = *DAT_EXTMEM_a701 | v;
    *DAT_EXTMEM_a701 = v | DAT_EXTMEM_a705;
    DAT_INTMEM_60 = 0;
    while (!(*DAT_EXTMEM_a701 & DAT_EXTMEM_a705)) {
        if (--DAT_INTMEM_60 == 0) break;
        for (j = 0; j < 10; j++) ;
    }
}
