/* 8051_bank1 FUN_CODE_6db5 @ 0x6db5  bit FUN_CODE_6db5(ch) (OPTIMIZE(8,SPEED) LARGE).
 * Caller: FUN_CODE_3c4d (0x3FDB). ch selects a register block with base R = 0xF039 (ch 0), 0xF041 (1), 0xF089 (2), 0xF091 (3), 0xF09B (4), 0xF0B8 (5); any other ch leaves the
 * pointers 0. LARGE slots: t 0xA4CF..D0, pc, pd, ps (generic pointers to volatile bytes)
 * 0xA4D1..D9 = R+0, R+4, R+1 (pd is set and not used).
 * R+0 |= 0x20; then up to 12000 passes: return 1 when R+1 bit 0 is set. Returns 0 after 12000 passes.
 * Pointer accesses go through ?C?CLDPTR (0x06A4) / ?C?CSTPTR (0x06EA). Same shape as the wait in FUN_CODE_644f
 * (src/8051_bank1/FUN_CODE_482e.c). No aids.
 */
bit FUN_CODE_6db5(unsigned char ch)
{
    unsigned int t;
    unsigned char volatile *pc, *pd, *ps;

    t = 12000;
    pc = 0;
    pd = 0;
    ps = 0;
    switch (ch) {
    case 0:
        pc = (unsigned char xdata *)0xf039;
        pd = (unsigned char xdata *)0xf03d;
        ps = (unsigned char xdata *)0xf03a;
        break;
    case 1:
        pc = (unsigned char xdata *)0xf041;
        pd = (unsigned char xdata *)0xf045;
        ps = (unsigned char xdata *)0xf042;
        break;
    case 2:
        pc = (unsigned char xdata *)0xf089;
        pd = (unsigned char xdata *)0xf08d;
        ps = (unsigned char xdata *)0xf08a;
        break;
    case 3:
        pc = (unsigned char xdata *)0xf091;
        pd = (unsigned char xdata *)0xf095;
        ps = (unsigned char xdata *)0xf092;
        break;
    case 4:
        pc = (unsigned char xdata *)0xf09b;
        pd = (unsigned char xdata *)0xf09f;
        ps = (unsigned char xdata *)0xf09c;
        break;
    case 5:
        pc = (unsigned char xdata *)0xf0b8;
        pd = (unsigned char xdata *)0xf0bc;
        ps = (unsigned char xdata *)0xf0b9;
        break;
    }
    *pc |= 0x20;
    while (t) {
        t--;
        if (*ps & 0x01) return 1;
    }
    return 0;
}
