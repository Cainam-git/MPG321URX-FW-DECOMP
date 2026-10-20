/* 8051_bank1 FUN_CODE_d81c @ 0xd81c  SPI flash "set extended address register" (byte-exact with
 * OPTIMIZE(8,SPEED) REGFILE(R.ORC): bank 1 was built with Keil whole-program register optimisation, see tools/regfile8051.py).
 *   1. FUN_CODE_d5f3(0x06): SPI command 06h = Write Enable.
 *   2. poll FUN_CODE_cf73(0x05) (05h = Read Status Register) until bit 1 (WEL, write-enable latch) is set.
 *   3. FUN_CODE_cad5(0xC5, ext): C5h = Write Extended Address Register, i.e. address bits 24..31 for flash
 *      parts above 16 MB that are driven with 3-byte addresses.
 *   4. poll status until bit 0 (WIP, write in progress) clears.
 * Boot/update path (flash access).
 * The (char) cast is what the original has: the value is kept in R6 across the status polls (cf73/d5f3/cad5 leave
 * R0..R6 alone per the register file) and is passed by way of R7 (MOV R7,R6; MOV R5,R7). Without the conversion
 * Keil keeps it in R5 directly; only a cast through another type reproduces the detour. */
extern void FUN_CODE_d5f3(unsigned char cmd);
extern unsigned char FUN_CODE_cf73(unsigned char cmd);
extern void FUN_CODE_cad5(unsigned char cmd, unsigned char val);

void FUN_CODE_d81c(unsigned char ext)
{
    FUN_CODE_d5f3(6);                       /* write enable */
    while (!(FUN_CODE_cf73(5) & 2)) ;       /* wait for WEL */
    FUN_CODE_cad5(0xc5, (char)ext);         /* write extended address register */
    while (FUN_CODE_cf73(5) & 1) ;          /* wait while WIP */
}
