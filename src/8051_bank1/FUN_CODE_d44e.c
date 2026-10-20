/* 8051_bank1 FUN_CODE_d44e @ 0xd44e (no draft)
 * Delay of n + 1 ticks: t0 = FUN_CODE_d94a() (consistent snapshot of the IDATA tick counter 0x57, returned in R6:R7),
 * then while (d94a() - t0 < n + 1) XDATA 0xF00A = 0x55 (the same 0xF00A = 0x55 write as in cfad and d511).
 * n and t0 are DATA locals 0x24..0x27 (SMALL model overlay: MOV 24H,R6 / INC 25H).
 * Callers 0x4225 (3fe7), 0x52a5 (50c9), 0x88a5 (883d), 0xa1f1 (a142), 0xc0ca (c0a1), 0xcf4b (cf38), 0xd7b9 (d7ac).
 * Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 49/49).
 */
extern unsigned char xdata DAT_EXTMEM_f00a;
unsigned int FUN_CODE_d94a(void);
void FUN_CODE_d44e(unsigned int n)
{
    unsigned int t0;
    n++;
    t0 = FUN_CODE_d94a();
    while (FUN_CODE_d94a() - t0 < n) DAT_EXTMEM_f00a = 0x55;
}
