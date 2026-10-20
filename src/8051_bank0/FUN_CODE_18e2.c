/* 8051_bank0 FUN_CODE_18e2 @ 0x18e2  STBC boot loader: read the flash Extended Address Register
 * (byte-exact with OPTIMIZE(7,SPEED); replaces the earlier mechanical void stub, same bytes).
 * Returns FUN_CODE_172d(0xC8): SPI opcode 0xC8 = Read Extended Address Register of a 32 MiB flash (which 16 MiB
 * half 3-byte addresses reach). Caller: FUN_CODE_111f (halts the boot when it is not 0).
 */
unsigned char FUN_CODE_172d(unsigned char cmd);
unsigned char FUN_CODE_18e2(void)
{
    return FUN_CODE_172d(0xc8);
}
