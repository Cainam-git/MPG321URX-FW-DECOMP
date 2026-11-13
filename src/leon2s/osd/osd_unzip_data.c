/* osd_unzip_data  (FUN_a006cc24)
 *
 * Expand run-length packed OSD data into 256-word blocks and write them to OSD memory.
 *   packed_words: packed word count
 *   src: packed data block
 *   arg: offset
 *   dst: target block
 * Name basis: proven - run between the prints 'unzip osd GO!!' / 'unzip osd finish!!'; (count, value) pairs;
 *   prints error1!!/error2!!
 *
 * Matching notes
 * --------------
 * leon2s 0xa006cc24-0xa006cfac (904 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: has_tail initialised to 0 at its declaration and set again in both
 * arms of 'if (tail_words == 0)' (the firmware's 'mov %l7,%i1' copy of failed's zero); last_chunk, failed,
 * out_count, tail_words assigned in that order; 'unpacked[out_count] = ...; out_count++;' and 'page++' as
 * their own statements.
 */
#define REG_CF011F80 (*(volatile unsigned int *)0xcf011f80)

#define CHUNK_WORDS      480        /* packed words read per chunk */
#define PAGE_WORDS       0x100      /* unpacked words collected before they are written */

extern void *lib_memset(void *, int, unsigned int);
extern int dbg_printf(const char *, ...);
extern void osd_read_packed_chunk(unsigned int *, unsigned int, unsigned short, unsigned char, unsigned short,
                         unsigned short, unsigned int);
extern void osd_write_memory_blocks(unsigned int *, unsigned int, unsigned int);

/*
 * Expand run-length packed data and write it to OSD memory.
 *
 *   packed_words  number of packed words
 *   src           where the packed data lies; passed on to osd_read_packed_chunk
 *   arg           offset; passed on to osd_read_packed_chunk, which adds arg >> 5 to the block number it reads
 *   dst           target in OSD memory; the first block written is dst >> 5
 *
 * The packed data is read in chunks of 480 words (osd_read_packed_chunk; the last chunk may be shorter) into
 * packed[], a new chunk each time the walk reaches a multiple of 480. It is made of triples of words: the first
 * word holds two 16-bit run lengths, the second is the value repeated by the low length, the third the value
 * repeated by the high length. The values are collected in unpacked[]; whenever it holds 256 words it is
 * written out as 32 blocks (osd_write_memory_blocks) and the target moves on by one page. Run length 0xffff in
 * either half is an error: it is printed (error1 for the low half, error2 for the high half) and the walk
 * ends. After a walk without error a partly filled unpacked[] is written out too, rounded up to whole blocks.
 *
 * Called from osd_run_pending_unzip with the four words stored by osd_request_unzip.
 */
void osd_unzip_data(unsigned int packed_words, unsigned int src, unsigned int arg, unsigned int dst)
{
    unsigned int packed[CHUNK_WORDS];
    unsigned int unpacked[PAGE_WORDS];
    unsigned short tail_words, last_chunk, chunk, out_count, page, run_length;
    unsigned char has_tail = 0, failed;
    unsigned int i, j, pair;

    lib_memset(packed, 0, sizeof packed);
    lib_memset(unpacked, 0, sizeof unpacked);
    last_chunk = (packed_words + 479) / 480 - 1;
    failed = 0;
    out_count = 0;
    tail_words = packed_words % 480;
    /* has_tail: the last chunk is shorter than 480 words. */
    if (tail_words == 0)
        has_tail = 0;
    else
        has_tail = 1;
    REG_CF011F80 = 0x81;
    chunk = 0;
    page = 0;
    for (i = 0; i < packed_words; i += 3) {
        if (i % 480 == 0) {
            if (chunk <= last_chunk) {
                osd_read_packed_chunk(packed, src, last_chunk, has_tail, tail_words, chunk, arg);
                chunk++;
            }
        }
        pair = packed[i % 480];
        run_length = pair;
        /* Low half: repeat the second word of the triple. */
        if (run_length == 0xffff) {
            dbg_printf("error1!! (0x%08lX) (%ld)\r\n", pair, i);
            failed = 1;
            break;
        }
        for (j = 0; j < run_length; j++) {
            unpacked[out_count] = packed[(i + 1) % 480];
            out_count++;
            if (out_count == 0x100) {
                out_count = 0;
                osd_write_memory_blocks(unpacked, (dst >> 5) + page * 32, 32);
                page++;
            }
        }
        /* High half: repeat the third word of the triple. */
        run_length = pair >> 16;
        if (run_length == 0xffff) {
            dbg_printf("error2!! (0x%08lX) (%ld) (0x%08lX)\r\n", pair, i, packed[(i + 1) % 480]);
            failed = 1;
            break;
        }
        for (j = 0; j < run_length; j++) {
            unpacked[out_count] = packed[(i + 2) % 480];
            out_count++;
            if (out_count == 0x100) {
                out_count = 0;
                osd_write_memory_blocks(unpacked, (dst >> 5) + page * 32, 32);
                page++;
            }
        }
    }
    /* Write what is left of the last page, in whole blocks. */
    if (out_count != 0 && !failed)
        osd_write_memory_blocks(unpacked, (dst >> 5) + page * 32, (out_count + 7) >> 3);
}
