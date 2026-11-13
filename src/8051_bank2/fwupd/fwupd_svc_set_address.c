/* fwupd_svc_set_address  (FUN_CODE_d53d)
 *
 * Send a 24-bit flash address to the main chip over the service link.
 *   address
 * Returns: 0 when every byte was acknowledged
 * Name basis: derived - frame 6E 04 4A + three address bytes + XOR sum; caller fwupd_pick_valid_region
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). Without REGFILE(R.ORC) it is 251 B: the firmware keeps no_ack in
 * R2 and checksum in R3 across every i2c_write_byte call, which Keil only does when the register-usage file says
 * i2c_write_byte leaves R2/R3 alone. The ulong parameter lives in its LARGE home 0x08F0..0x08F3 (?C?LSTXDATA at
 * entry); the >> 16 and >> 8 bytes go through ?C?ULSHR, the low byte is read straight from 0x08F3.
 */
void i2c_start(void);
void i2c_stop(void);
unsigned char i2c_write_byte(unsigned char b);

#define SVC_ADDRESS         0x6e
#define SVC_ADDRESS_BYTES   0x04    /* count of the bytes after it: the command and three address bytes */
#define SVC_CMD_SET_ADDRESS 0x4a

/* fwupd_svc_set_address: send address (bits 0..23) to the main chip with service command SVC_CMD_SET_ADDRESS.
 *
 * One packet between i2c_start and i2c_stop: SVC_ADDRESS, SVC_ADDRESS_BYTES, SVC_CMD_SET_ADDRESS, address bits
 * 16..23, 8..15, 0..7, then the XOR of those six bytes.
 * Returns the OR of the seven acknowledge results (0 = every byte acknowledged).
 * Caller: fwupd_pick_valid_region, before it reads a tag byte. */
unsigned char fwupd_svc_set_address(unsigned long address)
{
    unsigned char no_ack;
    unsigned char checksum;
    unsigned char next;
    checksum = 0;
    i2c_start();
    no_ack = i2c_write_byte(SVC_ADDRESS);
    checksum ^= SVC_ADDRESS;
    no_ack |= i2c_write_byte(SVC_ADDRESS_BYTES);
    checksum ^= SVC_ADDRESS_BYTES;
    no_ack |= i2c_write_byte(SVC_CMD_SET_ADDRESS);
    checksum ^= SVC_CMD_SET_ADDRESS;
    next = address >> 16;
    no_ack |= i2c_write_byte(next);
    checksum ^= next;
    next = address >> 8;
    no_ack |= i2c_write_byte(next);
    checksum ^= next;
    next = address;
    no_ack |= i2c_write_byte(next);
    checksum ^= next;
    no_ack |= i2c_write_byte(checksum);
    i2c_stop();
    return no_ack;
}
