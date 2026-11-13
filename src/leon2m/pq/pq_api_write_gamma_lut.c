/* pq_api_write_gamma_lut  (FUN_a014e26c)
 *
 * Write a block of gamma table data to one colour channel, or to all three.
 * Name basis: derived - channel 0..2, or 3 for channels 0, 1 and 2; table end at entry 0x100; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e26c @ 0xa014e26c-0xa014e2f0 (33 words), flags -mcpu=v8 -O3 -g.
 * Source form: in front of the single call an if / else-if chain of three tests of channel with empty arms
 * (reconstructed). The firmware zero-extends first_entry and byte_count at entry for the three calls, but the
 * single call extends them again from copies of the incoming registers. Without the chain the compiler's first
 * common-subexpression pass carries the entry values into the single-call path and the bytes differ; with it,
 * two jumps to the single call are still there at that pass, and they are removed later without leaving an
 * instruction. A chain of three, four or five tests gives these bytes; none, one or two tests, a switch,
 * separate ifs or one combined test do not. The bytes do not show what was tested or what the arms held: other
 * values, '<' tests and tests of the other parameters give the same bytes. 'channel == 0, 1, 2' is a chosen
 * spelling (the channel numbers of the all-colours path).
 */
extern void pq_gamma_write_primary_lut(unsigned int channel, unsigned short first_entry, unsigned short byte_count, unsigned char *data);

#define GAMMA_ALL_COLORS 3              /* write the same block to colour channels 0, 1 and 2 */

/*
 * Write a block of gamma table data through pq_gamma_write_primary_lut (table port device channel << 4 | 4).
 *
 *   channel      colour channel 0..2, or GAMMA_ALL_COLORS for all three
 *   first_entry  the first table entry written
 *   byte_count   the number of data bytes (two per entry)
 *   data         the bytes
 *
 * Nothing in the firmware calls this routine.
 */
void pq_api_write_gamma_lut(unsigned char channel, unsigned short first_entry, unsigned short byte_count, unsigned char *data)
{
    if (channel == GAMMA_ALL_COLORS) {
        pq_gamma_write_primary_lut(0, first_entry, byte_count, data);
        pq_gamma_write_primary_lut(1, first_entry, byte_count, data);
        pq_gamma_write_primary_lut(2, first_entry, byte_count, data);
    } else {
        /* Empty tests kept for the exact build, see the matching notes. */
        if (channel == 0) {
        } else if (channel == 1) {
        } else if (channel == 2) {
        }
        pq_gamma_write_primary_lut(channel, first_entry, byte_count, data);
    }
}
