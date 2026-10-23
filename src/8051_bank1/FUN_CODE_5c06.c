/* 8051_bank1 FUN_CODE_5c06 @ 0x5C06..0x5DCB (453 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_5c06(p): p is a generic pointer to 5 unsigned long words (LARGE parameter at XDATA 0xA48E..0xA490);
 * locals i 0xA491, n 0xA492, w 0xA493. Clears p[0..4] (?C?LSTKPTR / ?C?LSTKOPTR with the inline constant 0),
 * calls FUN_CODE_38a7 when FUN_CODE_de12() is set, writes 0x55 to XDATA 0xF00A. When FUN_CODE_de12() is then clear:
 * takes up to 0x10 bytes of the count in the structure at XDATA 0xA3E3 (uint 0xA3EA): more than 0x10 left:
 * n = 0x10, count -= 0x10, bit 0 of 0xA3E9 cleared; else n = count, bit 0 of 0xA3E9 set, count = 0. Then
 * w = 0xA3E6 / 4 and p[0] = (w << 24) + (n << 16) + (0xA3E8 << 8) + (0xA3E7 & 0x0F) + ((0xA3E9 * 16) & 0xF0),
 * and p[1..4] = the next four words of the unsigned long array at 0xA3EC, indexed by 0xA3E6 (incremented per
 * word). Finally FUN_CODE_38a7 again when FUN_CODE_de12() is set. The structure layout is the one of
 * src/8051_bank1/FUN_CODE_5868.c (FUN_CODE_38a7 fills it). 0xF00A is a hardware register (volatile).
 * Source form: the last term is cast to unsigned int, '(unsigned int)((e9 * 16) & 0xF0)', which gives the
 * firmware's zero extension to long (CLR A); without the cast Keil sign-extends the int.
 */
struct rec_a3e3 {
    unsigned char mask;         /* 0xA3E3 */
    unsigned char e4;           /* 0xA3E4 */
    unsigned char words;        /* 0xA3E5 */
    unsigned char e6;           /* 0xA3E6 */
    unsigned char type;         /* 0xA3E7 */
    unsigned char ch;           /* 0xA3E8 */
    unsigned char e9;           /* 0xA3E9 */
    unsigned int len;           /* 0xA3EA */
    unsigned long d[32];        /* 0xA3EC */
};
extern struct rec_a3e3 xdata DAT_EXTMEM_a3e3;
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
bit FUN_CODE_de12(void);
void FUN_CODE_38a7(void);

void FUN_CODE_5c06(unsigned long *p)
{
    unsigned char i, n, w;

    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    if (FUN_CODE_de12()) FUN_CODE_38a7();
    DAT_EXTMEM_f00a = 0x55;
    if (!FUN_CODE_de12()) {
        if (DAT_EXTMEM_a3e3.len > 0x10) {
            n = 0x10;
            DAT_EXTMEM_a3e3.len -= 0x10;
            DAT_EXTMEM_a3e3.e9 &= 0xfe;
        } else {
            n = DAT_EXTMEM_a3e3.len;
            DAT_EXTMEM_a3e3.e9 |= 1;
            DAT_EXTMEM_a3e3.len = 0;
        }
        w = DAT_EXTMEM_a3e3.e6 / 4;
        p[0] = ((unsigned long)w << 24) + ((unsigned long)n << 16) + ((unsigned long)DAT_EXTMEM_a3e3.ch << 8)
             + (DAT_EXTMEM_a3e3.type & 0x0f) + (unsigned int)((DAT_EXTMEM_a3e3.e9 * 16) & 0xf0);
        for (i = 0; i < 4; i++)
            p[i + 1] = DAT_EXTMEM_a3e3.d[DAT_EXTMEM_a3e3.e6++];
    }
    if (FUN_CODE_de12()) FUN_CODE_38a7();
}
