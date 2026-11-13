/* hdmi_tx_ddc_read_fifo  (FUN_a00c7fec)
 *
 * Read a number of bytes from one register of the DDC master into a buffer, then wait.
 * Name basis: derived - one register read per byte
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c7fec, flags -mcpu=v8 -Os -g.
 * Source form: the routine keeps the decompiler's six-parameter form (the last two are not used); the count
 * and the loop index are unsigned shorts.
 */
extern int hdmi_tx_reg_read8();
extern int timer_delay_long_units();

#define HDMI_TX_BANK_CORE 0             /* bank 0 of an HDMI transmitter's registers */

/*
 * Read `count` bytes from one register of the DDC master (one register read per byte) into `buffer`, then
 * wait timer_delay_long_units(1). Called by hdmi_tx_ddc_read with the data register 0xF4, 16 bytes at a time.
 *   port:   HDMI TX port
 *   buffer: where the bytes go
 *   count:  number of bytes (low 8 bits are used)
 *   reg:    register to read (bank 0)
 * param_5 and param_6 are not used.
 */
void hdmi_tx_ddc_read_fifo(unsigned char port,int buffer,unsigned short count, unsigned short reg,unsigned int param_5,
                 unsigned int param_6)

{
  unsigned char byte_value;
  unsigned short next;
  unsigned short i;
  
  count = count & 0xff;
  i = 0;
  if (count != 0) {
    do {
      byte_value = hdmi_tx_reg_read8(port,HDMI_TX_BANK_CORE,reg & 0xffff);
      *(unsigned char *)(buffer + (unsigned int)i) = byte_value;
      next = i + 1;
      i = next;
    } while (next < count);
  }
  timer_delay_long_units(1,buffer);
  return;
}
