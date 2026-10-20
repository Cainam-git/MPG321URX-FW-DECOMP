/* 8051_bank0 FUN_CODE_18e8 @ 0x18e8  STBC boot loader: number of flash-chip records (byte-exact
 * with OPTIMIZE(7,SPEED)).
 * Returns 57 (0x39) in R7: the number of 6-byte records in the JEDEC flash-chip table at CODE 0x4000 that the
 * flash identification FUN_CODE_111f (its only caller, LCALL at 0x111f) walks. Ghidra's decompiler shows this
 * function as an empty "return;" because the value travels in R7; read the listing, not the decompilation.
 */
unsigned char FUN_CODE_18e8(void)
{
    return 0x39;    /* 57 table records */
}
