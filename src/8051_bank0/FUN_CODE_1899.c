/* 8051_bank0 FUN_CODE_1899 @ 0x1899..0x18AB (18 bytes)  STBC boot loader: "partition table failed?".
 * Options: OPTIMIZE(7,SPEED).
 * What it does (code): clears result bit 0x20.1, calls FUN_CODE_0003(NULL) (the partition-table loader: table at CODE
 *   0x6000 -> share structure XDATA 0x3000, see src/8051_bank0/FUN_CODE_0003.c) and sets bit 0x20.1 when 0003 returns
 *   0 (carry clear). It returns that bit in carry: 1 = failure.
 * Only caller FUN_CODE_151c at 0x1570: 'LCALL 1899 / JNC 1586'. Carry 0 -> "Re-booting STBC code...", 0xF1D0 = 0x87
 *   (start the next image); carry 1 -> "Can't find valid partition table!!!" and an endless 0xF00A = 0x55 loop.
 * The NULL argument is the generic pointer 00:0000 (MOV R3/R2/R1,#0); 0003 does not use it for the copy (its
 *   destination is the fixed share structure).
 */
unsigned char bdata _bdata_20 _at_ 0x20;
sbit _0_1 = _bdata_20 ^ 1;

bit FUN_CODE_0003(void *);

bit FUN_CODE_1899(void)
{
    _0_1 = 0;
    if (!FUN_CODE_0003((void *)0)) {
        _0_1 = 1;
    }
    return _0_1;
}
