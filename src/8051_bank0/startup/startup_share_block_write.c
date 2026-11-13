/* startup_share_block_write  (FUN_CODE_1346)
 *
 * Copy bytes into one entry of the share block for the next program.
 * Name basis: proven - XDATA 0x3000 plus the offset of the entry kind
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: the offset is chosen by a switch without a default (a kind of 10 or more leaves offset unset; no
 * caller passes one) and the copy indexes the block with i + offset.  The parameter order follows the registers
 * (kind in R7, len in R5, src in R1..R3).
 */

/* Offset of each entry kind in the share block (XDATA 0x3000).  The kind names are those of
 * startup_load_partition_table; kind 5 is written by flash_identify. */
#define SHARE_OFFSET_VERSION    0x00  /* kind 0 */
#define SHARE_OFFSET_USB_AGENT  0x02  /* kind 1 */
#define SHARE_OFFSET_LEON2M     0x0e  /* kind 2 */
#define SHARE_OFFSET_LEON2S     0x32  /* kind 3 */
#define SHARE_OFFSET_TENSILICA  0x5a  /* kind 4 */
#define SHARE_OFFSET_FLASH_INFO 0x66  /* kind 5 */
#define SHARE_OFFSET_6          0x6a
#define SHARE_OFFSET_7          0x76
#define SHARE_OFFSET_8          0x82
#define SHARE_OFFSET_9          0x8e

extern unsigned char xdata startup_share_block[];

/* startup_share_block_write
 *
 * Copies len bytes from src into the share block at XDATA 0x3000, at the fixed offset of entry kind (0..9).  The
 * next program reads the block (startup_load_core_images in the 8051 application).
 *   kind: entry kind 0..9;  len: bytes to copy;  src: where they come from (any memory)
 * Called by startup_load_partition_table (kinds 0..4 and 6..9) and flash_identify (kind 5).
 */
void startup_share_block_write(unsigned char kind, unsigned char len, unsigned char *src)
{
    unsigned int offset;
    unsigned char i;
    switch (kind) {
    case 0: offset = SHARE_OFFSET_VERSION; break;
    case 1: offset = SHARE_OFFSET_USB_AGENT; break;
    case 2: offset = SHARE_OFFSET_LEON2M; break;
    case 3: offset = SHARE_OFFSET_LEON2S; break;
    case 4: offset = SHARE_OFFSET_TENSILICA; break;
    case 5: offset = SHARE_OFFSET_FLASH_INFO; break;
    case 6: offset = SHARE_OFFSET_6; break;
    case 7: offset = SHARE_OFFSET_7; break;
    case 8: offset = SHARE_OFFSET_8; break;
    case 9: offset = SHARE_OFFSET_9; break;
    }
    for (i = 0; i < len; i++) {
        startup_share_block[i + offset] = src[i];
    }
}
