/* 8051_bank0 FUN_CODE_151c @ 0x151c  STBC boot loader main (byte-exact with OPTIMIZE(8,SPEED)
 * REGFILE(R.ORC); entered from the Keil start-up FUN_CODE_13f7 after reset vector LJMP 0x13F7).
 * Order of work: interrupts off (EA = 0; the boot loader takes no interrupt); XDATA 0xD929 = FUN_CODE_17e2() + 1;
 * SPI bus mode 0xF0E6 = FUN_CODE_18c9() * 4 (by chip variant); 0xF00A = 0xF0E0 = 0xAA; UART 4800 8N1
 * (FUN_CODE_1616); 0xF1A8 |= 2 then &= ~1; prints "\r\n------STBC Boot Loader -----\n"; 0xF1DF = 0x80;
 * FUN_CODE_18d6 (SPI FIFO reset pulse); 0xF152 = 0x40; reads the flash JEDEC ID (FUN_CODE_1777), identifies the
 * flash and sets the bus mode (FUN_CODE_111f), loads the partition table (FUN_CODE_1899 -> FUN_CODE_0003).
 * If that reports failure: prints "Can't find valid partition table!!!" and spins writing 0xF00A = 0x55 forever;
 * that branch is unreachable in this build (FUN_CODE_0003 sets its result bit 0x20.2 and nothing clears it:
 * no "CLR 20.2" exists in 0x0000..0x18EB). Otherwise prints "Re-booting STBC code...\r\n", 0xF00A = 0x55,
 * 0xF1D0 = 0x87 and spins writing 0xF00A = 0x55.
 * Register meanings beyond the code (from the public MPG 341CQPX write-up, measured there, not here): 0xF0E0 is the
 * watchdog (0xAA = off, 0x55 = arm/feed); 0xF00A's purpose is unknown; 0xF1D0 = 0x87 starts the hardware copy of the
 * next image (partition descriptors in 0xF1D1..0xF1D8), it is not a jump.
 */
unsigned char bdata _bdata_20 _at_ 0x20;
sbit _0_0 = _bdata_20 ^ 0;
sfr IE = 0xA8;
sbit EA = IE ^ 7;
extern unsigned char volatile xdata DAT_EXTMEM_f0e6, DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0, DAT_EXTMEM_f1a8, DAT_EXTMEM_f1df, DAT_EXTMEM_f152, DAT_EXTMEM_f1d0;
extern void FUN_CODE_0989(void *fmt, ...);
unsigned char FUN_CODE_17e2(void);
unsigned char FUN_CODE_18c9(void);
void FUN_CODE_1616(void);
void FUN_CODE_18d6(void);
void FUN_CODE_1777(void);
void FUN_CODE_111f(void);
bit FUN_CODE_1899(void);
void FUN_CODE_151c(void)
{
    unsigned char xdata *p;
    _0_0 = 0;
    EA = 0;
    p = (unsigned char xdata *)0xd929;
    *p = FUN_CODE_17e2() + 1;
    DAT_EXTMEM_f0e6 = FUN_CODE_18c9() * 4;
    DAT_EXTMEM_f00a = 0xaa;
    DAT_EXTMEM_f0e0 = 0xaa;
    FUN_CODE_1616();
    DAT_EXTMEM_f1a8 |= 0x02;
    DAT_EXTMEM_f1a8 &= ~0x01;
    FUN_CODE_0989((void code *)0x167d);
    DAT_EXTMEM_f1df = 0x80;
    FUN_CODE_18d6();
    DAT_EXTMEM_f152 = 0x40;
    FUN_CODE_1777();
    FUN_CODE_111f();
    if (FUN_CODE_1899()) {
        FUN_CODE_0989((void code *)0x169d);
        for (;;) DAT_EXTMEM_f00a = 0x55;
    }
    FUN_CODE_0989((void code *)0x16c1);
    DAT_EXTMEM_f00a = 0x55;
    DAT_EXTMEM_f1d0 = 0x87;
    for (;;) DAT_EXTMEM_f00a = 0x55;
}
