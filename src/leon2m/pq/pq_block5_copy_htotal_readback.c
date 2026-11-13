/* pq_block5_copy_htotal_readback  (FUN_a0105d20)
 *
 * Copy the 16-bit register 0x82 of picture block 5 into its registers 0x5E and 0x79.
 * Note: 0x5E is the block's horizontal total; 0x82 is read with pq_block_read16_stable.
 * Name basis: descriptive - register 0x82 to 0x5E (horizontal total) and 0x79; only caller
 *   sys_channel_apply_output_timing
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0105d20 @ 0xa0105d20, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the '& 0xffff' on the unsigned short value does not change the bytes.
 */
#define BLOCK_5 5
#define BLK_HTOTAL_READBACK 0x82   /* picture block register: horizontal total read back */
#define BLK_HTOTAL 0x5e            /* picture block register: horizontal total */

extern int pq_block_write16();
extern int pq_block_read16_stable();

/*
 * Copy the horizontal total that picture block 5 reads back into two of its registers: the value of
 * BLK_HTOTAL_READBACK (0x82, read with pq_block_read16_stable) goes to BLK_HTOTAL (0x5E) and to register 0x79.
 *
 * Only caller: sys_channel_apply_output_timing.
 */
void pq_block5_copy_htotal_readback(void)
{
  unsigned short measured_htotal;
  
  measured_htotal = pq_block_read16_stable(BLOCK_5, BLK_HTOTAL_READBACK);
  pq_block_write16(BLOCK_5, BLK_HTOTAL, measured_htotal & 0xffff);
  pq_block_write16(BLOCK_5, 0x79, measured_htotal & 0xffff);
  return;
}
