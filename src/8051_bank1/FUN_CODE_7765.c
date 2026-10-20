/* 8051_bank1 FUN_CODE_7765 @ 0x7765..0x78ba (341 B)  SPI flash: save the status register(s) into p[0..1] and then
 * clear the block-protect bits by a Write Status Register, per flash family (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC)).
 * Input: p (R1..R3, generic pointer; caller FUN_CODE_8b58 passes its sr[] at XDATA 0xA4BA). Keil LARGE block:
 * p 0xA4C6..0xA4C8, buf[4] 0xA4C9..0xA4CC, id 0xA4CD.
 * id = XDATA 0x3066 (flash family code; only the high nibble is tested: 0x30, 0x40, 0x50, 0x80).
 * Steps: p[0] = Read Status (FUN_CODE_cf73(0x05)); p[1] = second status read with opcode 0x15 (family 0x3x) or
 * 0x35 (0x4x, 0x8x), none for 0x5x; any other family prints "error flash!!!\r\n" (bank 1 string 0xA31B) and
 * hangs (for (;;)). Then Write Enable (FUN_CODE_d5f3(0x06)), wait for WEL (bit 1); buf = {0x01 (WRSR),
 * status1, status2} with status1 = p[0] & 0x40 for 0x3x else 0, status2 = p[1] & 0x02 for 0x4x/0x8x, p[1] for
 * 0x5x, else 0 (so all protect bits are cleared, only bit 6 / bit 1 = QE-type bits are kept); wait for WEL;
 * FUN_CODE_7df1(2 bytes for 0x5x else 3, buf, 0, buf + 3) sends it; wait while WIP (bit 0), then while WEL.
 * FUN_CODE_b456 is the mirror (writes p[0..1] back). Changes the flash status register: update path only.
 */
extern unsigned char xdata DAT_EXTMEM_3066;
extern void FUN_CODE_d5f3(unsigned char cmd);
extern unsigned char FUN_CODE_cf73(unsigned char cmd);
extern void FUN_CODE_7df1(unsigned int n, unsigned char *buf, unsigned int a, unsigned char *b);
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_7765(unsigned char *p)
{
    unsigned char buf[4];
    unsigned char id;

    id = DAT_EXTMEM_3066;
    p[0] = FUN_CODE_cf73(5);
    if ((id & 0xf0) == 0x30) p[1] = FUN_CODE_cf73(0x15);
    else if ((id & 0xf0) == 0x40) p[1] = FUN_CODE_cf73(0x35);
    else if ((id & 0xf0) == 0x50) ;
    else if ((id & 0xf0) == 0x80) p[1] = FUN_CODE_cf73(0x35);
    else {
        FUN_CODE_2820((void code *)0xa31b);
        for (;;) ;
    }
    FUN_CODE_d5f3(6);
    while (!(FUN_CODE_cf73(5) & 2)) ;
    buf[0] = 1;
    if ((id & 0xf0) == 0x30) {
        buf[1] = p[0] & 0x40;
        buf[2] = 0;
    } else if ((id & 0xf0) == 0x40) {
        buf[1] = 0;
        buf[2] = p[1] & 0x02;
    } else if ((id & 0xf0) == 0x50) {
        buf[1] = 0;
        buf[2] = p[1];
    } else if ((id & 0xf0) == 0x80) {
        buf[1] = 0;
        buf[2] = p[1] & 0x02;
    } else {
        buf[1] = 0;
        buf[2] = 0;
    }
    while (!(FUN_CODE_cf73(5) & 2)) ;
    if ((id & 0xf0) == 0x50)
        FUN_CODE_7df1(2, buf, 0, buf + 3);
    else
        FUN_CODE_7df1(3, buf, 0, buf + 3);
    while (FUN_CODE_cf73(5) & 1) ;
    while (FUN_CODE_cf73(5) & 2) ;
}
