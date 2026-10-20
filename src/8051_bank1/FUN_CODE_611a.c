/* 8051_bank1 FUN_CODE_611a @ 0x611a  bit FUN_CODE_611a(ch, buf) (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * Callers: FUN_CODE_3c4d (0x3EEA, 0x3F06, 0x3FBE). ch selects a register block with base R = 0xF039 (ch 0), 0xF041 (1), 0xF089 (2), 0xF091 (3), 0xF09B (4), 0xF0B8 (5); any other ch leaves the
 * pointers 0. LARGE slots: buf 0xA4CF..D1 (generic pointer), t 0xA4D2..D3,
 * ps, pd, pc (generic pointers to volatile bytes) 0xA4D4..DC = R+3, R+6, R+4.
 * Up to 1000 passes: return 0 when R+3 bit 3 is set; when R+3 bit 5 is set: *buf = R+6, R+4 = 0x20, return 1.
 * Returns 0 after 1000 passes. R+3 is read again for every test (volatile pointee). The early exit is 'break'
 * (Keil jumps to the shared CLR C / RET). Pointer accesses go through ?C?CLDPTR (0x06A4) / ?C?CSTPTR (0x06EA).
 * Same shape as FUN_CODE_62c6 in src/8051_bank1/FUN_CODE_482e.c. No aids.
 */
bit FUN_CODE_611a(unsigned char ch, unsigned char *buf)
{
    unsigned int t;
    unsigned char volatile *ps, *pd, *pc;

    t = 1000;
    ps = 0;
    pd = 0;
    pc = 0;
    switch (ch) {
    case 0:
        ps = (unsigned char xdata *)0xf03c;
        pd = (unsigned char xdata *)0xf03f;
        pc = (unsigned char xdata *)0xf03d;
        break;
    case 1:
        ps = (unsigned char xdata *)0xf044;
        pd = (unsigned char xdata *)0xf047;
        pc = (unsigned char xdata *)0xf045;
        break;
    case 2:
        ps = (unsigned char xdata *)0xf08c;
        pd = (unsigned char xdata *)0xf08f;
        pc = (unsigned char xdata *)0xf08d;
        break;
    case 3:
        ps = (unsigned char xdata *)0xf094;
        pd = (unsigned char xdata *)0xf097;
        pc = (unsigned char xdata *)0xf095;
        break;
    case 4:
        ps = (unsigned char xdata *)0xf09e;
        pd = (unsigned char xdata *)0xf0a1;
        pc = (unsigned char xdata *)0xf09f;
        break;
    case 5:
        ps = (unsigned char xdata *)0xf0bb;
        pd = (unsigned char xdata *)0xf0be;
        pc = (unsigned char xdata *)0xf0bc;
        break;
    }
    while (t) {
        t--;
        if (*ps & 0x08) break;
        if (*ps & 0x20) {
            *buf = *pd;
            *pc = 0x20;
            return 1;
        }
    }
    return 0;
}
