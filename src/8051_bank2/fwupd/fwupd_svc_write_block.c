/* fwupd_svc_write_block  (FUN_CODE_c52f)
 *
 * Write one 512-byte block to the flash through the ISP port.
 *   block_number: low 8 bits of the block number (0x77 for the DUALFW tag)
 *   block_data: the 512 data bytes
 * Returns: 0 on success
 * Name basis: derived - packet 6E 00 3C v F0 0F 6E 91 13 EC + 512 bytes + XOR checksum
 *
 * Matching notes
 * --------------
 * 8051_bank2 module FUN_CODE_c52f: i2c_start @ 0xe423..0xe432, fwupd_svc_write_block @ 0xc52f..0xc60e and
 * i2c_read_packet @ 0xbba9..0xbcb3, with the Keil common-entry block i2c_start_entry @ 0xe419..0xe423 in front of
 * i2c_start. One Keil C51 module, compiled with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). The block is the identical
 * entry of fwupd_svc_write_block and i2c_read_packet before their first call (i2c_start): store the generic pointer
 * parameter (R3:R2:R1) at the DPTR the caller loads (0x08FD resp. 0x0909) and keep the char parameter in R6
 * (MOV R6,AR7).
 * fwupd_svc_write_block: LARGE parameters block_number (R6 after the block) and block_data (XDATA 0x08FD..0x08FF);
 * locals status (0x0900) and checksum (0x0901). Keil folds the constants of the checksum expression into one
 * XRL A,#0ADH.
 * i2c_read_packet: LARGE parameter reply (0x0909..0x090B), local index (unsigned int, 0x090C).
 * Source forms the bytes depend on: the loop limit and the last-index test cast reply[0] to unsigned int (Keil then
 * zero-extends into R6:R7 with MOV R6,#0 and subtracts 1 with ADD/ADDC #0FFH); each arm has its own
 * 'reply[index + 2] = i2c_read_byte(k);' (Keil cross-jumps the shared tail).
 */
#include <intrins.h>

/* The service bus is driven by hand on port 1: P1.7 = SCL, P1.6 = SDA. */
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;
sbit SCL = P1 ^ 7;

#define SVC_ADDRESS          0x6e        /* the service device on the bus */
#define SVC_READ_BIT         0x01
#define ADDRESS_TRIES        10          /* i2c_read_packet: address sends before giving up */
#define REPLY_MAX_LENGTH     10          /* a longer length byte fails the read */
#define BLOCK_BYTES          0x200
#define READ_ACK             0           /* i2c_read_byte argument: more bytes follow */
#define READ_LAST            1           /* i2c_read_byte argument: last byte */
#define I2C_ACKED            0           /* i2c_write_byte result when the byte was acknowledged */

extern unsigned char xdata i2c_bit_delay_count;
void i2c_bit_delay(void);

/* i2c_start: start condition (SCL high, SDA low, SCL low), with a bit delay after each step. */
void i2c_start(void)
{
    SCL = 1;
    i2c_bit_delay();
    SDA = 0;
    i2c_bit_delay();
    SCL = 0;
    i2c_bit_delay();
}

void i2c_stop(void);
void timer_delay_units(unsigned char n);
unsigned char i2c_write_byte(unsigned char b);
unsigned char i2c_read_byte(unsigned char last);

/* fwupd_svc_write_block: send one 512-byte block to the service device as one bus message.
 *
 * block_number: the byte placed fourth in the message. fwupd_write_flash_blocks passes the low 8 bits of its block
 *               number (it sends the upper bits before with service command 0x0F); fwupd_write_dualfw_tag passes
 *               0x77.
 * block_data:   the 512 bytes (both callers pass fwupd_block_buffer).
 * Returns 0 when every head byte and the checksum were acknowledged, else 1. Neither caller tests it.
 *
 * Message: start, the ten head bytes 6E 00 3C block_number F0 0F 6E 91 13 EC, the 512 data bytes, one checksum
 * byte = XOR of all head and data bytes, stop. The acknowledge of each data byte is not looked at.
 */
unsigned char fwupd_svc_write_block(unsigned char block_number, unsigned char *block_data)
{
    unsigned char status, checksum;
    unsigned int byte_index;
    i2c_start();
    status = i2c_write_byte(SVC_ADDRESS);
    status |= i2c_write_byte(0);
    status |= i2c_write_byte(0x3c);
    status |= i2c_write_byte(block_number);
    status |= i2c_write_byte(0xf0);
    status |= i2c_write_byte(0x0f);
    status |= i2c_write_byte(0x6e);
    status |= i2c_write_byte(0x91);
    status |= i2c_write_byte(0x13);
    status |= i2c_write_byte(0xec);
    checksum = 0x6e ^ 0x00 ^ 0x3c ^ block_number ^ 0xf0 ^ 0x0f ^ 0x6e ^ 0x91 ^ 0x13 ^ 0xec;
    for (byte_index = 0; byte_index < BLOCK_BYTES; byte_index++) {
        i2c_write_byte(block_data[byte_index]);
        checksum ^= block_data[byte_index];
    }
    status |= i2c_write_byte(checksum);
    i2c_stop();
    return status;
}

/* i2c_read_packet: read a reply from device 'device' into reply.
 *
 * device: bus address (every caller passes SVC_ADDRESS 0x6E); bit 0 is set for the read.
 * reply:  receives the length byte (reply[0], at most 10), a second byte (reply[1]) and then reply[0] bytes from
 *         reply[2] on.
 * Returns 0 when the packet was read, 1 when the address was not acknowledged in 10 tries or the length byte is
 * above 10 (the bus is stopped in both cases).
 * Before the last byte there are six bit delays; that byte is read with READ_LAST.
 */
unsigned char i2c_read_packet(unsigned char device, unsigned char *reply)
{
    unsigned int index;
    i2c_start();
    for (index = 0; index < ADDRESS_TRIES; index++) {
        if (i2c_write_byte(device | SVC_READ_BIT) == I2C_ACKED) break;
        i2c_bit_delay();
    }
    if (index == ADDRESS_TRIES) {
        i2c_stop();
        return 1;
    }
    timer_delay_units(1);
    reply[0] = i2c_read_byte(READ_ACK);
    reply[1] = i2c_read_byte(READ_ACK);
    if (reply[0] > REPLY_MAX_LENGTH) {
        i2c_stop();
        return 1;
    }
    for (index = 0; index < (unsigned int)reply[0]; index++) {
        if (index == (unsigned int)reply[0] - 1) {
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            i2c_bit_delay();
            reply[index + 2] = i2c_read_byte(READ_LAST);
        } else reply[index + 2] = i2c_read_byte(READ_ACK);
    }
    i2c_stop();
    return 0;
}
