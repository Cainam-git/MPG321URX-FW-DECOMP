/* hdmi_tx_ddc_start_edid_tail  (FUN_a00c87c0)
 *
 * Program the DDC master to read eight bytes near the end of an EDID block.
 * Name basis: descriptive - device 0xA0, offset block * 0x80 + 0x78
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c87c0, flags -mcpu=v8 -Os -g.
 * Source form: the routine keeps the decompiler's form; it returns the block number shifted left by 32 bits,
 * which no caller uses.
 */
extern int hdmi_tx_ddc_start();

#define EDID_DEVICE 0xa0        /* device address programmed into the DDC master */
#define EDID_BLOCK_BYTES 0x80   /* offset step per block number */
#define EDID_TAIL_OFFSET 0x78   /* offset within the block: 8 bytes before its end */
#define EDID_TAIL_BYTES 8

/*
 * Program the DDC master of an HDMI output (hdmi_tx_ddc_start) to read 8 bytes from device 0xA0 at offset
 * block * 0x80 + 0x78. It only starts the transfer; the caller fetches the bytes afterwards.
 *   port:  HDMI TX port
 *   block: block number (low 8 bits)
 */
unsigned int hdmi_tx_ddc_start_edid_tail(unsigned char port,unsigned int block)

{
  hdmi_tx_ddc_start(port,EDID_DEVICE,(block & 0xff) * EDID_BLOCK_BYTES + EDID_TAIL_OFFSET,EDID_TAIL_BYTES);
  return (unsigned long long)block << 0x20;
}
