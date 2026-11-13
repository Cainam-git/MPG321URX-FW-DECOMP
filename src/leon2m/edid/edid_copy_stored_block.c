/* edid_copy_stored_block  (FUN_a00ce9c0)
 *
 * Copy 16 bytes of one stored EDID record.
 *   n: record number
 *   dst: destination
 *   blk: 16-byte block number
 * Note: Same records as LoadCustomerEDIDData.
 * Name basis: derived - caller ddc_tool_answer_read_request (factory tool table read)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ce9c0 @ 0xa00ce9c0-0xa00cea18 (22 words).
 * Source form: the record address is an unsigned int computed from the table symbol (the %lo part of the symbol
 * is an `or` with offset 0); the block offset is computed before the record address.
 */

#define EDID_RECORD_SIZE   0x200    /* bytes per stored record */
#define EDID_RECORD_COUNT  0x38     /* records in the table */
#define EDID_BLOCK_SIZE    16

extern const unsigned char edid_stored_records[];

/*
 * Copy one 16-byte block of a stored EDID record to dst.
 *
 *   n    record number (0..0x37); a larger number is replaced by 0
 *   dst  receives EDID_BLOCK_SIZE bytes
 *   blk  block number inside the record (byte offset = blk * 16)
 *
 * Called from ddc_tool_answer_read_request. There is no check that blk stays inside the 512-byte record.
 */
void edid_copy_stored_block(unsigned short n, unsigned char *dst, unsigned char blk)
{
    unsigned int addr;
    int off;
    int i;

    if (n >= EDID_RECORD_COUNT)
        n = 0;
    off = blk * EDID_BLOCK_SIZE;
    addr = (unsigned int)edid_stored_records + n * EDID_RECORD_SIZE;
    for (i = 0; i < EDID_BLOCK_SIZE; i++)
        dst[i] = *(const unsigned char *)(addr + off + i);
}
