/* fwupd_verify_file_sum  (FUN_CODE_ad56)
 *
 * Check the update file's 16-bit byte sum against the CONFIG.bin record.
 * Returns: 0 when the sums differ; 1 otherwise (sum matches, no CONFIG.bin, or no AA 55 04 record)
 * Note: Without a CONFIG.bin, or without the AA 55 04 record in its first block, the file is accepted
 *   unchecked.
 * Name basis: derived - record AA 55 04 in the config file, expected sum at +0x10; sum of size/512 blocks;
 *   result to 0xF19A/B
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_ad56 @ 0xad56..0xaed9, compiled with OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals in XDATA declaration order: port (0x08FE, stored and not read again), offset (0x08FF),
 * file_blocks (0x0901), file_sum (0x0903), block (0x0905); k stays in R6:R7.
 * usb_disk_read_to_port_mem's second argument goes to its parameter block 0x090B through ?C?LSTKXDATA.
 * Source form: the word fwupd_config_sum is built in two statements (first the byte at +0x10, then
 * '(sum << 8) + byte at +0x11').
 */
#include <absacc.h>

#define SECTOR_BYTES         0x200
#define RECORD_STEP          0x10        /* the record mark is looked for at every 16th offset */
#define RECORD_MARK_0        0xaa        /* record mark: AA 55 04 at offsets +0..+2 */
#define RECORD_MARK_1        0x55
#define RECORD_MARK_2        0x04
#define RECORD_SUM_AT        0x10        /* expected sum: byte +0x10 = bits 8..15, byte +0x11 = bits 0..7 */
#define FWUPD_MAILBOX_F19A   0xF19A      /* answer: computed sum bits 0..7 */
#define FWUPD_MAILBOX_F19B   0xF19B      /* answer: computed sum bits 8..15 */

extern unsigned char xdata fwupd_config_record_flag;
extern unsigned int xdata fwupd_config_sum;
extern unsigned long xdata fwupd_entry_first_sector;
extern unsigned long xdata fwupd_file_size;
extern unsigned char xdata fwupd_sector_buffer[];
unsigned char usb_get_current_port(void);
void usb_disk_read_to_port_mem(unsigned long a, unsigned long b);
void usb_port_read_sector_swapped(unsigned char k, unsigned char *p);
void fwupd_read_file_block16(unsigned int off, unsigned char *buf);

/* fwupd_verify_file_sum: compare the byte sum of the loaded update file with the sum in CONFIG.bin.
 *
 * Caller: fwupd_find_update_file, as its last step after fwupd_copy_file_to_dram; its result decides what
 * fwupd_find_update_file returns.
 * Returns 1 = accepted, 0 = the sums differ.
 *
 * Order:
 *   1. No CONFIG.bin entry was found (fwupd_config_record_flag 0): return 1 at once, nothing is checked.
 *   2. fwupd_config_sum = 0; read the first block of CONFIG.bin (fwupd_entry_first_sector, set by
 *      fwupd_take_config_entry) into fwupd_sector_buffer.
 *   3. Look for the mark AA 55 04 at offsets 0, 0x10, 0x20 .. 0x1F0. No mark: return 1, nothing is checked.
 *   4. At the first mark: fwupd_config_sum = the 16-bit value at mark + 0x10 (first byte = bits 8..15). Sum every
 *      byte of the first (file size / 512) blocks of the loaded file into 16 bits; a last part block is not summed.
 *      The computed sum goes to mailbox bytes 0xF19A (bits 0..7) and 0xF19B (bits 8..15) in either case; return 1
 *      when it equals fwupd_config_sum, else 0.
 */
unsigned char fwupd_verify_file_sum(void)
{
    unsigned char port;
    unsigned int offset;
    unsigned int file_blocks;
    unsigned int file_sum;
    unsigned int block;
    unsigned int k;
    port = usb_get_current_port();
    if (fwupd_config_record_flag == 0) return 1;
    fwupd_config_sum = 0;
    usb_disk_read_to_port_mem(fwupd_entry_first_sector, SECTOR_BYTES);
    usb_port_read_sector_swapped(0, fwupd_sector_buffer);
    for (offset = 0; offset < SECTOR_BYTES; offset += RECORD_STEP) {
        if (fwupd_sector_buffer[offset] == RECORD_MARK_0 && fwupd_sector_buffer[offset + 1] == RECORD_MARK_1 && fwupd_sector_buffer[offset + 2] == RECORD_MARK_2) {
            fwupd_config_sum = fwupd_sector_buffer[offset + RECORD_SUM_AT];
            fwupd_config_sum = (fwupd_config_sum << 8) + fwupd_sector_buffer[offset + RECORD_SUM_AT + 1];
            file_blocks = fwupd_file_size / SECTOR_BYTES;
            file_sum = 0;
            for (block = 0; block < file_blocks; block++) {
                fwupd_read_file_block16(block, fwupd_sector_buffer);
                for (k = 0; k < SECTOR_BYTES; k++) file_sum += fwupd_sector_buffer[k];
            }
            XBYTE[FWUPD_MAILBOX_F19A] = file_sum;
            XBYTE[FWUPD_MAILBOX_F19B] = file_sum >> 8;
            if (file_sum == fwupd_config_sum) return 1;
            return 0;
        }
    }
    return 1;
}
