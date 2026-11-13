/* i2c_write_byte  (FUN_CODE_d275)
 *
 * Send one byte on the update agent's I2C bus and read the acknowledge.
 *   value: byte
 * Returns: 0 = acknowledged, 1 = not acknowledged
 * Name basis: proven - bit-banged on P1.6 (data) / P1.7 (clock)
 *
 * Matching notes
 * --------------
 * One Keil C51 module, OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC), with three pieces of code: i2c_write_byte
 * @ 0xd275..0xd2fb, fwupd_svc_write_tag_block @ 0xc6ea..0xc7c5, and the Keil common-entry block
 * i2c_write_byte_entry (i2c_write_byte_entry) @ 0xd261..0xd275 in front of i2c_write_byte. The block is built from two
 * call sites in fwupd_svc_write_tag_block: it ORs the previous result into status (R3), loads flash_addr
 * (XDATA 0x08EF) into R4..R7, shifts it right by R0 (?C?ULSHR; the caller loads R0 = 16 or 8 before the LCALL) and
 * falls into i2c_write_byte.
 * i2c_write_byte keeps its locals in IDATA (declared idata, in this order).
 * fwupd_svc_write_tag_block: LARGE parameters flash_addr (XDATA 0x08EF..0x08F2) and tag (0x08F3); status, checksum
 * and index stay in R3, R6 and R4:R5 across the calls through the register file. Source forms the bytes depend on:
 * - the checksum of the header bytes is ONE expression written after the header is sent; Keil folds its constant
 *   part: SVC_ADDRESS ^ 0x00 ^ 0x3C = 0x52 (XRL A,#52H), the six bytes 0xF0..0xEC XOR to 0xFF (CPL A), and each
 *   FILL_BYTE data byte is a CPL A;
 * - the 16-bit index counts up to SVC_BLOCK_BYTES (Keil tests index != 0x200 at the loop end).
 */
#include <intrins.h>
sfr P1 = 0x90;
sbit SDA = P1 ^ 6;      /* data line of the bus the update agent drives by hand */
sbit SCL = P1 ^ 7;      /* clock line */
extern unsigned char xdata i2c_bit_delay_count;
void i2c_bit_delay(void);
void i2c_start(void);
void i2c_stop(void);

#define I2C_SW_ACK      0       /* return value: the receiver held SDA low after the byte */
#define I2C_SW_NACK     1       /* return value: SDA stayed high */
#define SCL_WAIT_READS  0xff    /* reads of SCL while it is held low before the code goes on */
#define ACK_LATE_TRIES  7       /* count of the second look at SDA for the acknowledge */

/* i2c_write_byte: send one byte on the bit-banged bus (P1.6 = SDA, P1.7 = SCL) and read the acknowledge.
 *
 * value: the byte to send, most significant bit first.
 * Returns I2C_SW_ACK (0) or I2C_SW_NACK (1).
 *
 * Each data bit: clock low, set SDA, clock high, with i2c_bit_delay between the steps. Then the acknowledge clock:
 * SDA set to 1 and read back, SCL set high, and while SCL still reads low the code reads it again, at most
 * SCL_WAIT_READS times; it goes on after that whether or not SCL went high. SDA low at the first look is an
 * acknowledge. Otherwise SDA is read again after each further i2c_bit_delay; a low level seen within six of them
 * still counts as an acknowledge, and the routine gives I2C_SW_NACK only when the count of ACK_LATE_TRIES runs out.
 * The byte ends with SCL low and SDA high, followed by two bit delays.
 * Every byte the update agent sends on this bus goes through here (i2c_write_packet, fwupd_svc_write_block,
 * fwupd_svc_write_tag_block below and others). The delay length comes from i2c_bit_delay_count (i2c_bit_delay).
 */
unsigned char i2c_write_byte(unsigned char value)
{
    unsigned char idata count;          /* bit counter, then the second-look counter */
    unsigned char idata no_ack;
    unsigned char idata shift;          /* the byte being shifted out, then the SCL read counter */
    shift = value;
    for (count = 0; count < 8; count++) {
        i2c_bit_delay();
        SCL = 0;
        i2c_bit_delay();
        if (shift & 0x80) SDA = 1; else SDA = 0;
        i2c_bit_delay();
        SCL = 1;
        shift <<= 1;
    }
    /* Acknowledge clock: SDA set to 1 so the receiver's level can be read. */
    i2c_bit_delay();
    SCL = 0;
    i2c_bit_delay();
    SDA = 1;
    i2c_bit_delay();
    SCL = 1;
    i2c_bit_delay();
    /* While SCL is held low, read it again; give up after SCL_WAIT_READS reads and carry on. */
    shift = SCL_WAIT_READS;
    while (!SCL && --shift);
    if (!SDA) no_ack = I2C_SW_ACK;
    else {
        /* Late acknowledge: look at SDA again after each bit delay until the count runs out. */
        count = ACK_LATE_TRIES;
        while (SDA && count) {
            i2c_bit_delay();
            count--;
        }
        if (count == 0) no_ack = I2C_SW_NACK; else no_ack = I2C_SW_ACK;
    }
    SCL = 0;
    SDA = 1;
    i2c_bit_delay();
    i2c_bit_delay();
    return no_ack;
}

#define SVC_ADDRESS     0x6e    /* slave address of the service packets (docs/MAP.md, update path) */
#define SVC_BLOCK_BYTES 0x200   /* data bytes after the 12 header bytes */
#define SVC_TAG_INDEX   0x1ff   /* the last data byte carries the tag */
#define FILL_BYTE       0xff    /* every other data byte */

/* fwupd_svc_write_tag_block: send one 512-byte block that is all FILL_BYTE except its last byte, the tag.
 *
 * flash_addr: the flash address the block goes to, sent as three bytes (bits 23..16, 15..8, 7..0).
 * tag:        the last byte of the block.
 * Returns the OR of the acknowledge results (I2C_SW_ACK 0 / I2C_SW_NACK 1) of the 12 header bytes and of the
 * checksum byte; the results of the 512 data bytes are not counted. The only caller, fwupd_tag_new_region, does not
 * use the result.
 *
 * Packet, between i2c_start and i2c_stop: SVC_ADDRESS, 0x00, 0x3C, the three address bytes, 0xF0, 0x0F, 0x6E,
 * 0x91, 0x13, 0xEC, the 512 data bytes, and an XOR of every byte sent before it. This is the packet of
 * fwupd_svc_write_block with three address bytes in place of its one block-number byte; the meaning of the other
 * header bytes is not shown. fwupd_tag_new_region sends tag 0xAA to (region start + 0x0E00) of the region just
 * written and tag 0 to that of the other region, so the tag lands at region start + 0x0FFF, the byte
 * fwupd_pick_valid_region reads and compares with 0xAA.
 */
unsigned char fwupd_svc_write_tag_block(unsigned long flash_addr, unsigned char tag)
{
    unsigned char status, checksum;
    unsigned int index;
    i2c_start();
    status = i2c_write_byte(SVC_ADDRESS);
    status |= i2c_write_byte(0);
    status |= i2c_write_byte(0x3c);
    status |= i2c_write_byte((unsigned char)(flash_addr >> 16));
    status |= i2c_write_byte((unsigned char)(flash_addr >> 8));
    status |= i2c_write_byte((unsigned char)flash_addr);
    status |= i2c_write_byte(0xf0);
    status |= i2c_write_byte(0x0f);
    status |= i2c_write_byte(0x6e);
    status |= i2c_write_byte(0x91);
    status |= i2c_write_byte(0x13);
    status |= i2c_write_byte(0xec);
    checksum = SVC_ADDRESS ^ 0x00 ^ 0x3c ^ (unsigned char)(flash_addr >> 16) ^ (unsigned char)(flash_addr >> 8)
        ^ (unsigned char)flash_addr ^ 0xf0 ^ 0x0f ^ 0x6e ^ 0x91 ^ 0x13 ^ 0xec;
    for (index = 0; index < SVC_BLOCK_BYTES; index++) {
        if (index == SVC_TAG_INDEX) {
            i2c_write_byte(tag);
            checksum ^= tag;
        } else {
            i2c_write_byte(FILL_BYTE);
            checksum ^= FILL_BYTE;
        }
    }
    status |= i2c_write_byte(checksum);
    i2c_stop();
    return status;
}
