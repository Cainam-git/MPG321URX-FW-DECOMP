/* 8051_bank1 module FUN_CODE_bd1b: FUN_CODE_d086, FUN_CODE_bd1b, FUN_CODE_97c4, FUN_CODE_c6ec, FUN_CODE_8c5d,
 * FUN_CODE_6781 in this order. Options: OPTIMIZE(8,SPEED) LARGE.
 * Byte data through the generic pointers at XDATA 0xA6FE (target) / 0xA706 (source) with mask XDATA 0xA704, and
 * 0xA701 (target) / 0xA709 (source) with mask XDATA 0xA705; each update is '*target = (*target | *source) | mask'
 * or '& ~mask'; below, 'set T' / 'clear T' name these two updates of target T.
 * FUN_CODE_d086 @ 0xd086 (15 B): delay, empty loop i = 0..99 (unsigned int). In front of it the firmware has the Keil
 *   OPTIMIZE(8) common-entry chain 0xD05B..0xD085, which Keil builds here from the call sites: 0xD05B
 *   'LCALL FUN_CODE_d086', 0xD05E 'clear *0xA701', 0xD07E 'ORL A,R7; MOV R7,A', 0xD080
 *   'MOVX A,@DPTR; CPL A; ANL A,R7; LCALL ?C?CSTPTR', each falling into the next and into FUN_CODE_d086. Callers
 *   enter it at 0xD05B ('FUN_CODE_d086(); <0xA705 update>; FUN_CODE_d086();'), 0xD05E, 0xD07E (DPTR = 0xA704 set
 *   before the OR) or 0xD080 (the OR done by the caller).
 * FUN_CODE_bd1b @ 0xbd1b (102 B): set *0xA701, then waits until *0xA701 & 0xA705 reads
 *   non-zero, at most 65535 rounds with a 10-step busy loop each; the round counter is the 16-bit IDATA variable
 *   0x60..0x61. In front of it the common-entry block 0xBD18 'LCALL FUN_CODE_d086' (entered from FUN_CODE_6781).
 * FUN_CODE_97c4 @ 0x97c4 (217 B): set *0xA6FE, FUN_CODE_bd1b(), *0xA706 |= 0xA704 value, delay; while
 *   *0xA6FE & 0xA704 value reads 0 and XDATA 0xA77B < 9: clear *0xA701, delay, FUN_CODE_bd1b(), 0xA77B += 1; then
 *   *0xA706 &= ~0xA704 value, clear *0xA6FE, delay, clear *0xA701.
 * FUN_CODE_c6ec @ 0xc6ec (82 B): clear *0xA6FE, delay, FUN_CODE_bd1b(), delay, set *0xA6FE.
 * FUN_CODE_8c5d (last) and FUN_CODE_6781 (x): written from the firmware logic; they do not yet compile to the
 *   firmware's bytes (not recorded as matched); their calls give the common-entry blocks.
 * Source forms:
 *  - The 0xA705 updates followed by FUN_CODE_d086() are written in place as one statement,
 *    '*DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;', at five call sites; Keil
 *    factors them into the chain in front of FUN_CODE_d086. There is no separate function at 0xD05E.
 *  - The other updates use a byte local per update ('t1 = *source; t1 = *target | t1; *target = t1 | mask;'):
 *    one local per site keeps each in R7 (a local reused across the calls is placed in XDATA). FUN_CODE_97c4's
 *    second 0xA704 clear is one statement ('t2 = *source; *target = (*target | t2) & ~mask;').
 *  - The function order above decides which call sites Keil merges into the blocks.
 *  - FUN_CODE_8c5d: the firmware does not initialise b (its 8 bits are all shifted in by the loop); here b = 0.
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
    unsigned char t1;
    unsigned int j;

    t1 = *DAT_EXTMEM_a709; t1 = *DAT_EXTMEM_a701 | t1; *DAT_EXTMEM_a701 = t1 | DAT_EXTMEM_a705;
    DAT_INTMEM_60 = 0;
    while (!(*DAT_EXTMEM_a701 & DAT_EXTMEM_a705)) {
        if (--DAT_INTMEM_60 == 0) break;
        for (j = 0; j < 10; j++) ;
    }
}

void FUN_CODE_97c4(void)
{
    unsigned char t1, t2;
    t1 = *DAT_EXTMEM_a706; t1 = *DAT_EXTMEM_a6fe | t1; *DAT_EXTMEM_a6fe = t1 | DAT_EXTMEM_a704;
    FUN_CODE_bd1b();
    *DAT_EXTMEM_a706 |= DAT_EXTMEM_a704;
    FUN_CODE_d086();
    DAT_EXTMEM_a77b = 0;
    while (!(*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704) && DAT_EXTMEM_a77b < 9) {
        *DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;
        FUN_CODE_d086();
        FUN_CODE_bd1b();
        DAT_EXTMEM_a77b++;
    }
    *DAT_EXTMEM_a706 &= ~DAT_EXTMEM_a704;
    t2 = *DAT_EXTMEM_a706; *DAT_EXTMEM_a6fe = (*DAT_EXTMEM_a6fe | t2) & ~DAT_EXTMEM_a704;
    FUN_CODE_d086();
    *DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;
}

void FUN_CODE_c6ec(void)
{
    unsigned char t1, t2;
    t1 = *DAT_EXTMEM_a706; t1 = *DAT_EXTMEM_a6fe | t1; *DAT_EXTMEM_a6fe = t1 & ~DAT_EXTMEM_a704;
    FUN_CODE_d086();
    FUN_CODE_bd1b();
    FUN_CODE_d086();
    t2 = *DAT_EXTMEM_a706; t2 = *DAT_EXTMEM_a6fe | t2; *DAT_EXTMEM_a6fe = t2 | DAT_EXTMEM_a704;
}

unsigned char FUN_CODE_8c5d(unsigned char last)
{
    unsigned char i;
    unsigned char b = 0;
    unsigned char t1, t2, t3;
    last &= 1;
    *DAT_EXTMEM_a706 |= DAT_EXTMEM_a704;
    t1 = *DAT_EXTMEM_a706; t1 = *DAT_EXTMEM_a6fe | t1; *DAT_EXTMEM_a6fe = t1 | DAT_EXTMEM_a704;
    for (i = 0; i < 8; i++) {
        b <<= 1;
        FUN_CODE_bd1b();
        FUN_CODE_d086();
        if (!(*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704)) b &= 0xfe;
        else b |= 1;
        *DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;
        FUN_CODE_d086();
    }
    *DAT_EXTMEM_a706 &= ~DAT_EXTMEM_a704;
    if (last == 0) {
        t2 = *DAT_EXTMEM_a706; t2 = *DAT_EXTMEM_a6fe | t2; *DAT_EXTMEM_a6fe = t2 & ~DAT_EXTMEM_a704;
    } else {
        t3 = *DAT_EXTMEM_a706; t3 = *DAT_EXTMEM_a6fe | t3; *DAT_EXTMEM_a6fe = t3 | DAT_EXTMEM_a704;
    }
    FUN_CODE_d086();
    FUN_CODE_bd1b();
    FUN_CODE_d086();
    *DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;
        FUN_CODE_d086();
    return b;
}

unsigned char FUN_CODE_6781(unsigned char x)
{
    unsigned char t1, t2, t3, t4, t5;
    unsigned char idata i;
    unsigned char idata r;
    for (i = 0; i < 8; i++) {
        FUN_CODE_d086();
        *DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;
        FUN_CODE_d086();
        if (x & DAT_CODE_ded4[i]) {
            t1 = *DAT_EXTMEM_a706; t1 = *DAT_EXTMEM_a6fe | t1; *DAT_EXTMEM_a6fe = t1 | DAT_EXTMEM_a704;
        } else {
            t2 = *DAT_EXTMEM_a706; t2 = *DAT_EXTMEM_a6fe | t2; *DAT_EXTMEM_a6fe = t2 & ~DAT_EXTMEM_a704;
        }
        FUN_CODE_d086();
        FUN_CODE_bd1b();
    }
    FUN_CODE_d086();
    *DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;
        FUN_CODE_d086();
    t3 = *DAT_EXTMEM_a706; t3 = *DAT_EXTMEM_a6fe | t3; *DAT_EXTMEM_a6fe = t3 & ~DAT_EXTMEM_a704;
    *DAT_EXTMEM_a706 |= DAT_EXTMEM_a704;
    t4 = *DAT_EXTMEM_a706; t4 = *DAT_EXTMEM_a6fe | t4; *DAT_EXTMEM_a6fe = t4 | DAT_EXTMEM_a704;
    FUN_CODE_d086();
    FUN_CODE_bd1b();
    FUN_CODE_d086();
    if (!(*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704)) r = 0;
    else {
        i = 7;
        while ((*DAT_EXTMEM_a6fe & DAT_EXTMEM_a704) && i) {
            FUN_CODE_d086();
            i--;
        }
        if (i == 0) r = 1;
        else r = 0;
    }
    *DAT_EXTMEM_a701 = (*DAT_EXTMEM_a701 | *DAT_EXTMEM_a709) & ~DAT_EXTMEM_a705;
    *DAT_EXTMEM_a706 &= ~DAT_EXTMEM_a704;
    t5 = *DAT_EXTMEM_a706; t5 = *DAT_EXTMEM_a6fe | t5; *DAT_EXTMEM_a6fe = t5 & ~DAT_EXTMEM_a704;
    FUN_CODE_d086();
    return r;
}
