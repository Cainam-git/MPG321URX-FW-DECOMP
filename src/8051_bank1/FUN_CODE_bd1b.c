/* 8051_bank1 FUN_CODE_bd1b @ 0xbd1b (102 B)  Options: OPTIMIZE(8,SPEED) LARGE.
 * Through the generic pointers at XDATA 0xA709 (source) and 0xA701 (target): *target = *target | *source | mask,
 * mask = XDATA 0xA705. Then waits until *target & mask reads non-zero, at most 65535 rounds with a short
 * 10-step busy loop each; the round counter is the 16-bit IDATA variable 0x60..0x61 (MOV R0,#60H / @R0).
 * Callers: FUN_CODE_8c5d (0x8CB0, 0x8D54), FUN_CODE_97c4 (0x97EB, 0x982F), FUN_CODE_c6ec (0xC711).
 * The OR is two statements on a byte temporary, 'v = *source; v = *target | v;': this keeps the target pointer in
 * R1..R3 for the store ('v |= *target' gives ORL direct,A; one expression reloads the pointer).
  * This file is one Keil MODULE: FUN_CODE_d086, FUN_CODE_bd1b, FUN_CODE_d05e, FUN_CODE_c6ec, FUN_CODE_97c4,
 * FUN_CODE_8c5d, FUN_CODE_6781. Reason (code): the firmware has the Keil OPTIMIZE(8) common-entry block 0xBD18
 * 'LCALL FUN_CODE_d086' in front of FUN_CODE_bd1b (entered from FUN_CODE_6781 at 0x67E7 and 0x685C); Keil builds
 * such a block only from the 'FUN_CODE_d086(); FUN_CODE_bd1b();' call sequences inside one module. FUN_CODE_d086 is
 * the body of src/8051_bank1/FUN_CODE_d086.c. FUN_CODE_d05e, c6ec, 97c4, 8c5d and 6781 are written from the
 * firmware logic and are not byte-exact (not matched in symbols); their calls give the block.
 */
extern unsigned char * xdata DAT_EXTMEM_a6fe;
extern unsigned char * xdata DAT_EXTMEM_a701;
extern unsigned char xdata DAT_EXTMEM_a704;
extern unsigned char xdata DAT_EXTMEM_a705;
extern unsigned char * xdata DAT_EXTMEM_a706;
extern unsigned char * xdata DAT_EXTMEM_a709;
extern unsigned char xdata DAT_EXTMEM_a77b;
extern unsigned int idata DAT_INTMEM_60;
extern unsigned char code DAT_CODE_ded4[];
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata DAT_EXTMEM_a70c;

void FUN_CODE_d086(void)
{
    unsigned int i;
    for (i = 0; i != 100; i++) ;
}

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

void FUN_CODE_d05e(void)
{
    unsigned char v;
    v = *DAT_EXTMEM_a709;
    v = *DAT_EXTMEM_a701 | v;
    *DAT_EXTMEM_a701 = v & ~DAT_EXTMEM_a705;
    FUN_CODE_d086();
}

void FUN_CODE_c6ec(void)
{
    unsigned char v;
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v & ~DAT_EXTMEM_a704;
    FUN_CODE_d086();
    FUN_CODE_bd1b();
    FUN_CODE_d086();
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v | DAT_EXTMEM_a704;
}

void FUN_CODE_97c4(void)
{
    unsigned char v;
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v | DAT_EXTMEM_a704;
    FUN_CODE_bd1b();
    *DAT_EXTMEM_a706 |= DAT_EXTMEM_a704;
    FUN_CODE_d086();
    DAT_EXTMEM_a77b = 0;
    while (!(*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704) && DAT_EXTMEM_a77b < 9) {
        FUN_CODE_d05e();
        FUN_CODE_bd1b();
        DAT_EXTMEM_a77b++;
    }
    *DAT_EXTMEM_a706 &= ~DAT_EXTMEM_a704;
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v & ~DAT_EXTMEM_a704;
    FUN_CODE_d086();
    v = *DAT_EXTMEM_a709;
    v = *DAT_EXTMEM_a701 | v;
    *DAT_EXTMEM_a701 = v & ~DAT_EXTMEM_a705;
}

unsigned char FUN_CODE_8c5d(unsigned char last)
{
    unsigned char i;
    unsigned char b = 0;
    unsigned char v;
    last &= 1;
    *DAT_EXTMEM_a706 |= DAT_EXTMEM_a704;
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v | DAT_EXTMEM_a704;
    for (i = 0; i < 8; i++) {
        b <<= 1;
        FUN_CODE_bd1b();
        FUN_CODE_d086();
        if (*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704) b |= 1;
        else b &= 0xfe;
        FUN_CODE_d05e();
    }
    *DAT_EXTMEM_a706 &= ~DAT_EXTMEM_a704;
    if (last == 0) {
        v = *DAT_EXTMEM_a706;
        v = *DAT_EXTMEM_a6fe | v;
        *DAT_EXTMEM_a6fe = v & ~DAT_EXTMEM_a704;
    } else {
        v = *DAT_EXTMEM_a706;
        v = *DAT_EXTMEM_a6fe | v;
        *DAT_EXTMEM_a6fe = v | DAT_EXTMEM_a704;
    }
    FUN_CODE_d086();
    FUN_CODE_bd1b();
    FUN_CODE_d086();
    FUN_CODE_d05e();
    return b;
}

unsigned char FUN_CODE_6781(unsigned char x)
{
    unsigned char idata i;
    unsigned char idata r;
    unsigned char v;
    for (i = 0; i < 8; i++) {
        FUN_CODE_d086();
        FUN_CODE_d05e();
        if (x & DAT_CODE_ded4[i]) {
            v = *DAT_EXTMEM_a706;
            v = *DAT_EXTMEM_a6fe | v;
            *DAT_EXTMEM_a6fe = v | DAT_EXTMEM_a704;
        } else {
            v = *DAT_EXTMEM_a706;
            v = *DAT_EXTMEM_a6fe | v;
            *DAT_EXTMEM_a6fe = v & ~DAT_EXTMEM_a704;
        }
        FUN_CODE_d086();
        FUN_CODE_bd1b();
    }
    FUN_CODE_d086();
    FUN_CODE_d05e();
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v & ~DAT_EXTMEM_a704;
    *DAT_EXTMEM_a706 |= DAT_EXTMEM_a704;
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v | DAT_EXTMEM_a704;
    FUN_CODE_d086();
    FUN_CODE_bd1b();
    FUN_CODE_d086();
    if (*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704) {
        i = 7;
        while ((*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704) && i) {
            FUN_CODE_d086();
            i--;
        }
        if (i == 0) r = 1;
        else r = 0;
    } else r = 0;
    v = *DAT_EXTMEM_a709;
    v = *DAT_EXTMEM_a701 | v;
    *DAT_EXTMEM_a701 = v & ~DAT_EXTMEM_a705;
    *DAT_EXTMEM_a706 &= ~DAT_EXTMEM_a704;
    v = *DAT_EXTMEM_a706;
    v = *DAT_EXTMEM_a6fe | v;
    *DAT_EXTMEM_a6fe = v & ~DAT_EXTMEM_a704;
    FUN_CODE_d086();
    return r;
}
