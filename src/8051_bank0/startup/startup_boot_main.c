/* startup_boot_main  (FUN_CODE_151c)
 *
 * Boot loader main: identify the flash, load the partition table and start the next program.
 * Name basis: proven - prints '------STBC Boot Loader -----' and 'Re-booting STBC code...'; then writes the
 *   start command to the copy hardware
 *
 * Matching notes
 * --------------
 * 8051_bank0 FUN_CODE_151c @ 0x151c, built with OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * Source form kept as in the exact build: XDATA 0xD929 is written through the local pointer reg_d929, the clock
 * variant is turned into the bus-mode bits with "* 4", and both ends of the routine are a "for (;;)" loop that
 * stores 0x55 to XDATA 0xF00A on every round. The printed texts are passed as CODE addresses.
 */
#define COPY_START_NEXT_PROGRAM 0x87    /* reg_copy_start: start the hardware copy of the next program */
unsigned char bdata _bdata_20 _at_ 0x20;
sbit _0_0 = _bdata_20 ^ 0;
sfr IE = 0xA8;
sbit EA = IE ^ 7;
extern unsigned char volatile xdata reg_flash_spi_mode, DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0, DAT_EXTMEM_f1a8, DAT_EXTMEM_f1df, DAT_EXTMEM_f152, reg_copy_start;
extern void lib_printf(void *fmt, ...);
unsigned char startup_find_marker_index(void);
unsigned char startup_get_clock_variant(void);
void uart_init(void);
void flash_reset_fifo(void);
void flash_read_jedec_id(void);
void flash_identify(void);
bit startup_run_partition_loader(void);

/* The boot loader's main routine, the first C code that runs after power-on. The compiler start-up code
 * (startup_entry) calls it after clearing memory and setting the stack; it never returns and has no parameters.
 *
 * In this order it:
 *   1. clears bit 0x20.0 and turns all interrupts off (EA = 0);
 *   2. stores startup_find_marker_index() + 1 at XDATA 0xD929;
 *   3. sets the bus-mode bits (bits 2-3) of the SPI mode register from the clock variant: 0 on the fast clock
 *      (reg_sys_clock_variant 0x20), 4 otherwise;
 *   4. writes 0xAA to XDATA 0xF00A and 0xF0E0, sets the serial port up (4800 baud, 8 data bits, no parity), sets
 *      bit 1 and clears bit 0 of XDATA 0xF1A8, and prints the banner "------STBC Boot Loader -----";
 *   5. writes 0x80 to XDATA 0xF1DF, pulses the reset bit of the SPI FIFO and writes 0x40 to XDATA 0xF152;
 *   6. reads the flash chip's JEDEC id, looks the chip up in the table of known chips and sets its bus mode
 *      (flash_identify), then reads the partition table, which fills the share block and hands the address and
 *      size of the next program to the copy registers (startup_load_partition_table);
 *   7. prints "Re-booting STBC code...", writes 0x55 to XDATA 0xF00A and 0x87 to reg_copy_start, which starts the
 *      hardware copy of the next program (the bank 1 application, docs/MAP.md), and then keeps storing 0x55 to
 *      XDATA 0xF00A for ever.
 *
 * The error branch after step 6 cannot be taken: startup_run_partition_loader returns 1 only when
 * startup_load_partition_table reports failure, and that routine sets its result to 1 (success) and never clears
 * it. Nothing in the boot loader checks the table or the program it starts.
 */
void startup_boot_main(void)
{
    unsigned char xdata *reg_d929;
    _0_0 = 0;
    EA = 0;
    reg_d929 = (unsigned char xdata *)0xd929;
    *reg_d929 = startup_find_marker_index() + 1;
    /* bits 2-3 = bus mode: variant 0 (fast clock) -> 0, variant 1 -> 4 */
    reg_flash_spi_mode = startup_get_clock_variant() * 4;
    DAT_EXTMEM_f00a = 0xaa;
    DAT_EXTMEM_f0e0 = 0xaa;
    uart_init();
    DAT_EXTMEM_f1a8 |= 0x02;
    DAT_EXTMEM_f1a8 &= ~0x01;
    lib_printf((void code *)0x167d);    /* "\r\n------STBC Boot Loader -----\n" */
    DAT_EXTMEM_f1df = 0x80;
    flash_reset_fifo();
    DAT_EXTMEM_f152 = 0x40;
    flash_read_jedec_id();
    flash_identify();
    if (startup_run_partition_loader()) {
        /* table loader reported failure: never the case in this build (see above) */
        lib_printf((void code *)0x169d);    /* "Can't find valid partition table!!!" */
        for (;;) DAT_EXTMEM_f00a = 0x55;
    }
    lib_printf((void code *)0x16c1);    /* "Re-booting STBC code...\r\n" */
    DAT_EXTMEM_f00a = 0x55;
    reg_copy_start = COPY_START_NEXT_PROGRAM;
    for (;;) DAT_EXTMEM_f00a = 0x55;
}
