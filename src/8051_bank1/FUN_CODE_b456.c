/* 8051_bank1 FUN_CODE_b456 @ 0xb456..0xb4e0 (138 B)  SPI flash: write the saved status register bytes p[0..1] back
 * with a Write Status Register command. Byte-exact: 138 of 138 bytes, OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC),
 * Keil C51 9.60.7.
 *
 * Input: p (R1..R3, generic pointer). Callers: FUN_CODE_8b58 passes its status buffer at XDATA 0xA4BA,
 * FUN_CODE_6c34 passes XDATA 0xA776; both call it as 'LCALL b456; LJMP dc67' (no return value).
 * Keil LARGE block: buf[8] at 0xA4C6..0xA4CD (buf + 3 = 0xA4C9 is the 4th argument of FUN_CODE_7df1, whose XDATA
 * parameter block starts at 0xA4CE). id stays in R6 across the SPI calls (register file: d5f3 and cf73 do not use R6).
 * id = XDATA 0x3066, the flash family code; only its high nibble is tested: 0x5x sends 2 bytes, all others 3.
 * Steps: Write Enable (FUN_CODE_d5f3(0x06)); wait for WEL (Read Status FUN_CODE_cf73(0x05), bit 1);
 * buf = {0x01 (WRSR), p[0], p[1]}; wait for WEL; FUN_CODE_7df1(2 for family 0x5x, else 3, buf, 0, buf + 3) sends it;
 * wait while WIP (bit 0), then while WEL (bit 1). Counterpart of FUN_CODE_7765.
 *
 * Family test (firmware 0xB489..0xB491: 'MOV R7,AR6; MOV A,R6; ANL A,#0F0H; MOV R7,A; CJNE R7,#50H'):
 *  - A comparison through a char cast, '(char)id == C', places the cast value in a temporary register and compares
 *    that register directly: 'MOV R7,AR6; CJNE R7,#C'. 'MOV R7,AR6' is that temporary.
 *  - Both outcomes of the '?:' compile to the same code ('MOV A,R6; ANL A,#0F0H; MOV R7,A'). Keil merges them late,
 *    which removes the CJNE and its jumps after the pass that deletes unused register stores, so the temporary copy
 *    remains without a reader. The family test '(char)fam == 0x50' is again a register compare: 'CJNE R7,#50H'.
 *  - An empty branch body is removed before code generation and leaves no copy; an if/else that stores fam in both
 *    branches places fam in XDATA. Only a '?:' with two identical, non-empty outcomes gives the firmware's bytes.
 *  - The compared constant does not appear in the firmware: any value gives the same bytes. -1 is used here.
 *  - The '?:' behaves exactly like 'fam = id & 0xf0'.
 */
extern unsigned char xdata DAT_EXTMEM_3066;
extern void FUN_CODE_d5f3(unsigned char cmd);
extern unsigned char FUN_CODE_cf73(unsigned char cmd);
extern void FUN_CODE_7df1(unsigned int n, unsigned char *buf, unsigned int a, unsigned char *b);

void FUN_CODE_b456(unsigned char *p)
{
    unsigned char id;
    unsigned char buf[8];
    unsigned char fam;

    id = DAT_EXTMEM_3066;
    FUN_CODE_d5f3(6);
    while (!(FUN_CODE_cf73(5) & 2)) ;
    buf[0] = 1;
    buf[1] = p[0];
    buf[2] = p[1];
    while (!(FUN_CODE_cf73(5) & 2)) ;
    fam = ((char)id == -1) ? (id & 0xf0) : (id & 0xf0);
    if ((char)fam == 0x50)
        FUN_CODE_7df1(2, buf, 0, buf + 3);
    else
        FUN_CODE_7df1(3, buf, 0, buf + 3);
    while (FUN_CODE_cf73(5) & 1) ;
    while (FUN_CODE_cf73(5) & 2) ;
}
