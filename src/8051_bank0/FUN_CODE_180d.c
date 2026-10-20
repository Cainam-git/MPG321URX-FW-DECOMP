/* 8051_bank0 FUN_CODE_180d @ 0x180d  STBC boot loader: SetExtendedAddr(ear) (byte-exact with
 * OPTIMIZE(8,SPEED) REGFILE(R.ORC); semantics cross-checked with the public MPG 341CQPX boot loader write-up,
 * whose boot code is byte-identical to ours outside the partition table).
 * Selects the 16 MiB half of the 32 MiB SPI flash: 0x06 Write Enable (FUN_CODE_17af), poll 0x05 Read Status until
 * WEL (bit 1) is set, 0xC5 Write Extended Address Register = ear (FUN_CODE_16db), poll 0x05 until WIP (bit 0) clears,
 * then prints "SetExtendedAddr=%02bX\r\n" (format string at CODE 0x15A3) via printf FUN_CODE_0989 (tail call).
 * Callers: the partition-table loader FUN_CODE_0003 (only when the slot's bank byte is non-zero) and the flash
 * identification FUN_CODE_111f (ear 0 when a 32 MiB chip reports a non-zero EAR; that branch then halts).
 */
extern void FUN_CODE_0989(void *fmt, ...);
void FUN_CODE_17af(unsigned char cmd);
unsigned char FUN_CODE_172d(unsigned char cmd);
void FUN_CODE_16db(unsigned char cmd, unsigned char val);
void FUN_CODE_180d(unsigned char ear)
{
    FUN_CODE_17af(0x06);
    while (!(FUN_CODE_172d(0x05) & 0x02));
    FUN_CODE_16db(0xc5, ear);
    while (FUN_CODE_172d(0x05) & 0x01);
    FUN_CODE_0989((void code *)0x15a3, ear);
}
