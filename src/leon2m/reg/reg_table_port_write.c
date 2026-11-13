/* reg_table_port_write  (FUN_a00f2e98)
 *
 * Write a block of bytes to one of the chip's internal tables through the table port.
 * Name basis: proven - command, offset and length to 0xCF011780..0xCF011788, data bytes to 0xCF01178C, with
 *   short delays
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f2e98 @ 0xa00f2e98, flags -mcpu=v8 -O3 -g.
 * Source form: the delay is a static helper (unsigned char counter) inlined at each use; the low byte of the
 * offset is written as (unsigned char)offset.
 */

/* The table port. */
#define TABLE_PORT_DEVICE      (*(volatile unsigned int *)0xcf011780)    /* device number */
#define TABLE_PORT_OFFSET_LOW  (*(volatile unsigned int *)0xcf011784)    /* low byte of the offset */
#define TABLE_PORT_OFFSET_HIGH (*(volatile unsigned int *)0xcf011788)    /* high byte of the offset */
#define TABLE_PORT_UNKNOWN_BFCC (*(volatile unsigned int *)0xcf00bfcc)   /* cleared before the data */
#define TABLE_PORT_DELAY_NOPS  0x20

/* Wait for 32 nop instructions. */
static void delay(void)
{
    unsigned char i;

    for (i = 0; i < TABLE_PORT_DELAY_NOPS; i++)
        __asm__("nop");
}
#define TABLE_PORT_DATA        (*(volatile unsigned int *)0xcf01178c)    /* data register of this routine */

/*
 * Write 'length' bytes to the table port: the device number, then the offset (low byte, high byte), then 0 to
 * register 0xCF00BFCC, then the bytes one by one to the data register 0xCF01178C. A delay of 32 nops follows
 * each of these steps.
 *
 *   device  value written to the device register 0xCF011780
 *   offset  16-bit offset, written as two bytes
 *   length  number of bytes in 'data'
 *   data    the bytes to write
 *
 * Called by the pq_gamma_* routines that load the gamma tables and by pq_block8_set_timing.
 */
void reg_table_port_write(unsigned char device, unsigned short offset, unsigned short length, const unsigned char *data)
{
    unsigned short i;

    delay();
    TABLE_PORT_DEVICE = device;
    delay();
    TABLE_PORT_OFFSET_LOW = (unsigned char)offset;
    TABLE_PORT_OFFSET_HIGH = offset >> 8;
    TABLE_PORT_UNKNOWN_BFCC = 0;
    delay();
    for (i = 0; i < length; i++) {
        TABLE_PORT_DATA = data[i];
        delay();
    }
}
