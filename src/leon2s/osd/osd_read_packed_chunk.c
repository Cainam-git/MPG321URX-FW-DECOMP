/* osd_read_packed_chunk  (FUN_a006cb98)
 *
 * Read one chunk of up to 480 packed words for the OSD unpacker.
 * Name basis: derived - computes block address and length (last chunk shorter) and calls
 *   osd_read_memory_blocks; caller osd_unzip_data
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g. The seventh parameter arrives on the stack. Source form: the || is written as an
 * if/else (the firmware compiles it to subx/addx + orcc with 0x1e0 in the delay slot). The call is a tail call.
 */
extern void osd_read_memory_blocks(unsigned int, unsigned int, unsigned int);

/*
 * Read one chunk of packed words into out[] (osd_unzip_data calls this when its walk reaches a multiple of 480).
 *
 *   out         buffer for the chunk
 *   src         where the packed data lies; src >> 3 is added to the block number
 *   last_chunk  number of the last chunk
 *   has_tail    1 when the last chunk is shorter than 480 words
 *   tail_words  length of that short last chunk
 *   chunk       number of the chunk to read
 *   arg         offset; arg >> 5 is added to the block number
 *
 * The chunk is 480 words, except the last one when has_tail is set: that is tail_words long. It is read as
 * words / 8 blocks starting at block (arg >> 5) + (src >> 3) + chunk * 60 (60 blocks = 480 words). Nothing is
 * read when the length is above 480.
 */
void osd_read_packed_chunk(unsigned int out, unsigned int src, unsigned short last_chunk,
                  unsigned char has_tail, unsigned short tail_words, unsigned short chunk,
                  unsigned int arg)
{
    unsigned short words;

    if (has_tail == '\0' || chunk < last_chunk)
        words = 0x1e0;
    else
        words = tail_words;
    if (words < 0x1e1) {
        osd_read_memory_blocks(out, (arg >> 5) + (src >> 3) + chunk * 0x3c, words >> 3);
    }
}
