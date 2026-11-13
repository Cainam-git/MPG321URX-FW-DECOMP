/* i2c_write_eeprom_pages  (FUN_CODE_50c9)
 *
 * Write a buffer to an I2C EEPROM in pieces that do not cross 8-byte pages.
 *   channel: I2C channel
 *   device_addr: device address
 *   start_addr: start address
 *   buf: data
 *   count: byte count
 * Returns: 1 when all pieces succeeded
 * Name basis: derived - blocks end at multiples of 8 of the address, block address bits (addr >> 7) & 0x0E in
 *   the device byte, 10-tick pause per block; message type 2
 *
 * Matching notes
 * --------------
 * FUN_CODE_50c9, 8051_bank1, range 0x50C9..0x52BE (501 B).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source forms: the register addresses are written as casts of the numbers per channel; all locals are set to 0
 * at the start (the firmware stores each); the unused timer_get_ticks result is stored in ticks.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
bit i2c_master_write_at(unsigned char channel, unsigned char device_addr, unsigned int mem_addr, unsigned int count, unsigned char *buf);
extern unsigned int timer_get_ticks(void);
void timer_delay_ticks(unsigned int ticks);

#define EEPROM_PAGE_BYTES   8       /* no piece crosses a multiple of 8 of the address */
#define PIECE_PAUSE_TICKS   10      /* timer_delay_ticks after every piece */
#define ADDR_BITS_10_8(a)   (((a) >> 7) & 0x0e)  /* address bits 8..10 moved to bits 1..3 of the device byte */
#define I2C_MODE_AT_START   0x00
#define I2C_MODE_AT_END     0xf8
#define I2C_ADDRESS_VALUE   0x01

/*
 * i2c_write_eeprom_pages - write count bytes from buf to an I2C memory on a hardware I2C channel, starting at
 * start_addr, in pieces of at most 8 bytes that never cross a multiple of 8 of the address. Each piece goes out
 * with i2c_master_write_at: the device byte is device_addr with address bits 8..10 in bits 1..3, then the low byte
 * of the address, then the piece. After every piece the routine waits 10 ticks.
 *   channel      hardware I2C channel 0..5; its mode register (+2) is set to 0 and its address register (+7) to 1
 *                before the first piece, and the mode register to 0xF8 after the last
 *   device_addr  device byte for the write (bits 1..3 are ORed with the address bits)
 *   start_addr   memory address of the first byte
 *   buf, count   the bytes
 * Returns 1 when every piece was sent, 0 when any failed (the remaining pieces are still sent).
 * Called by ipc_run_message for the last piece of an I2C message (IPC_8051_TX_MSG_I2C) without the write-read
 * bit: buffer byte 0 = device_addr, byte 1 = start_addr, the rest = the data.
 */
bit i2c_write_eeprom_pages(unsigned char channel, unsigned char device_addr, unsigned char start_addr, unsigned char *buf, unsigned int count)
{
    unsigned int addr;
    unsigned char device_byte, piece;
    unsigned int ticks;
    unsigned char volatile *mode_reg, *address_reg;
    bit ok;

    ok = 1;
    addr = 0;
    device_byte = 0;
    piece = 0;
    ticks = 0;
    mode_reg = 0;
    address_reg = 0;
    /* The channel's reg_i2c<N>_mode and reg_i2c<N>_address. */
    switch (channel) {
    case 0:
        mode_reg = (unsigned char xdata *)0xf03b;
        address_reg = (unsigned char xdata *)0xf040;
        break;
    case 1:
        mode_reg = (unsigned char xdata *)0xf043;
        address_reg = (unsigned char xdata *)0xf048;
        break;
    case 2:
        mode_reg = (unsigned char xdata *)0xf08b;
        address_reg = (unsigned char xdata *)0xf090;
        break;
    case 3:
        mode_reg = (unsigned char xdata *)0xf093;
        address_reg = (unsigned char xdata *)0xf098;
        break;
    case 4:
        mode_reg = (unsigned char xdata *)0xf09d;
        address_reg = (unsigned char xdata *)0xf0a2;
        break;
    case 5:
        mode_reg = (unsigned char xdata *)0xf0ba;
        address_reg = (unsigned char xdata *)0xf0bf;
        break;
    }
    *mode_reg = I2C_MODE_AT_START;
    *address_reg = I2C_ADDRESS_VALUE;
    addr = start_addr;
    while (count != 0) {
        DAT_EXTMEM_f00a = 0x55;     /* the same write sys_main makes on every round of its loop */
        piece = EEPROM_PAGE_BYTES - (addr & 7);
        if (count < piece) piece = count;
        device_byte = device_addr | ADDR_BITS_10_8(addr);
        ok &= i2c_master_write_at(channel, device_byte, addr, piece, buf);
        addr += piece;
        buf += piece;
        count -= piece;
        ticks = timer_get_ticks();
        timer_delay_ticks(PIECE_PAUSE_TICKS);
    }
    *mode_reg = I2C_MODE_AT_END;
    return ok;
}
