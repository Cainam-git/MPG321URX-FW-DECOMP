/* i2c_master_write_read  (FUN_CODE_83f3)
 *
 * Run an I2C write followed by a read on one hardware I2C channel.
 *   ch: I2C channel
 *   device: device address
 *   reg: register number; its low byte is the one byte written before the read
 *   buf: buffer
 *   read_count
 * Returns: 1 on success
 * Name basis: derived - switches the channel to master, i2c_master_write then i2c_master_read, back to slave
 *   mode (0xF8); message type 2 read
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_83f3 @ 0x83f3..0x8512 (287 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Source form: ok is a bit, combined with '&='; the initialised local array reg_byte is copied with ?C?COPY from
 *   its 2-byte initializer at CODE 0xDD61 (00 00); mode_reg starts as a null pointer (a channel above 5 writes
 *   through it).
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
bit i2c_master_write(unsigned char ch, unsigned char ctl, unsigned int n, unsigned char *buf);
bit i2c_master_read(unsigned char ch, unsigned char ctl, unsigned int n, unsigned char *buf);

#define I2C_MODE_MASTER        0x00  /* reg_i2c<N>_mode value written for the master transfer */
#define I2C_MODE_SLAVE_ENABLE  0xf8  /* reg_i2c<N>_mode value written when the slave is switched on */

/*
 * i2c_master_write_read - on hardware I2C channel ch, write one register number to a device, then read bytes back.
 *   ch          channel 0..5
 *   device      device address
 *   reg         register number; its low byte is the one byte written
 *   buf         receives the bytes read
 *   read_count  number of bytes read
 * Returns 1 when both transfers succeeded.
 * The channel's mode register (+2 of its block) is set to 0 for the transfer and to 0xF8 (the slave value)
 * afterwards.
 * Only caller: ipc_run_message, for an I2C message from the main processor with bit 7 of its channel byte set;
 * the bytes read go back in report type 2.
 */
bit i2c_master_write_read(unsigned char ch, unsigned char device, unsigned int reg, unsigned char *buf, unsigned int read_count)
{
    bit ok = 1;
    unsigned char reg_byte[2] = {0, 0};
    unsigned char *mode_reg = 0;

    DAT_EXTMEM_f00a = 0x55;
    switch (ch) {
    case 0: mode_reg = (unsigned char xdata *)0xf03b; break;
    case 1: mode_reg = (unsigned char xdata *)0xf043; break;
    case 2: mode_reg = (unsigned char xdata *)0xf08b; break;
    case 3: mode_reg = (unsigned char xdata *)0xf093; break;
    case 4: mode_reg = (unsigned char xdata *)0xf09d; break;
    case 5: mode_reg = (unsigned char xdata *)0xf0ba; break;
    }
    reg_byte[0] = reg;
    *mode_reg = I2C_MODE_MASTER;
    ok &= i2c_master_write(ch, device, 1, reg_byte);
    ok &= i2c_master_read(ch, device, read_count, buf);
    *mode_reg = I2C_MODE_SLAVE_ENABLE;
    return ok;
}
