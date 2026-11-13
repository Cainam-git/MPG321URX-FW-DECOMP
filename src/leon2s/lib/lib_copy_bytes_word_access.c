/* lib_copy_bytes_word_access  (FUN_a0061608)
 *
 * Copy bytes, writing the middle part as aligned 32-bit words.
 *   dst: destination
 *   src: source
 *   count: byte count
 * Note: For a source offset of 2 or 3 the word loop reads a halfword or a byte at the aligned source address
 *   besides the next word.
 * Name basis: derived - byte read-modify-write until the destination is aligned, word loop per source
 *   alignment, byte tail; no direct caller
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0061608 @ 0xa0061608, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the leading byte loop is written out in the routine with the function-scope temporaries word, shift and
 *    byte; word and shift are then reused as the loop counter and the word count of the word loops;
 *  - the trailing bytes go through the static helper copy_byte() with its own locals;
 *  - every byte move: source shift first, then the word read, then the masked merge into the destination word.
 */

/*
 * Byte numbering used here: byte i of an aligned word is bits 8i..8i+7, so the byte at address a is
 * (word at a & ~3) >> ((a & 3) * 8). reg_write8 counts the bytes of a word the same way.
 */

/* Move one byte from address src to address dst: read the source word, rewrite the destination word. */
static void copy_byte(unsigned int dst, unsigned int src)
{
    unsigned int word, shift, byte;

    shift = (src & 3) << 3;
    word = *(unsigned int *)(src & ~3);
    byte = (word >> shift) & 0xff;
    shift = (dst & 3) << 3;
    word = *(unsigned int *)(dst & ~3);
    word = (word & ~(0xff << shift)) | (byte << shift);
    *(unsigned int *)(dst & ~3) = word;
}

/*
 * Copy count bytes from address src to address dst. Every write is a whole aligned word (a single byte is
 * merged into the word it lies in); the reads are aligned words too, except that the word loops for a source
 * offset of 2 or 3 read a halfword or a byte at the source word's address.
 *
 *   dst    destination address
 *   src    source address; it need not have the same alignment as dst
 *   count  number of bytes
 *
 * Three steps:
 *   1. bytes one at a time until dst is word aligned (the copy ends here when count runs out);
 *   2. count / 4 whole words to dst; each one is put together from two neighbouring source words according to
 *      the source's offset inside its word (src & 3);
 *   3. the last count & 3 bytes one at a time.
 * Returns nothing. No routine of the input program calls it directly.
 */
void lib_copy_bytes_word_access(unsigned int dst, unsigned int src, unsigned int count)
{
    unsigned int *src_word;
    unsigned int word, shift, byte;

    /* Step 1: same byte move as copy_byte(). */
    if (dst & 3) {
        do {
            shift = (src & 3) << 3;
            word = *(unsigned int *)(src & ~3);
            byte = (word >> shift) & 0xff;
            shift = (dst & 3) << 3;
            word = *(unsigned int *)(dst & ~3);
            word = (word & ~(0xff << shift)) | (byte << shift);
            *(unsigned int *)(dst & ~3) = word;
            dst++;
            src++;
            if (--count == 0)
                return;
        } while (dst & 3);
    }

    /* Step 2: shift now holds the number of whole words, word counts them. Each case leaves src just past the
       bytes it has copied. */
    shift = count >> 2;
    src_word = (unsigned int *)(src & ~3);
    switch (src & 3) {
    case 0:
        /* Source aligned too: plain word copy. */
        for (word = 0; word < shift; word++) {
            *(unsigned int *)dst = *src_word++;
            dst += 4;
        }
        src = (unsigned int)src_word;
        break;
    case 1:
        /* Bits 8..31 of this source word become bits 0..23, bits 0..7 of the next one bits 24..31. */
        for (word = 0; word < shift; word++) {
            *(unsigned int *)dst = (src_word[0] >> 8) + (src_word[1] << 24);
            dst += 4;
            src_word++;
        }
        src = (unsigned int)src_word + 1;
        break;
    case 2:
        /* The halfword read at this source word's address becomes bits 0..15, bits 0..15 of the next word
           bits 16..31. */
        for (word = 0; word < shift; word++) {
            *(unsigned int *)dst = *(unsigned short *)src_word + (src_word[1] << 16);
            dst += 4;
            src_word++;
        }
        src = (unsigned int)src_word + 2;
        break;
    case 3:
        /* The byte read at this source word's address becomes bits 0..7, bits 0..23 of the next word
           bits 8..31. */
        for (word = 0; word < shift; word++) {
            *(unsigned int *)dst = *(unsigned char *)src_word + (src_word[1] << 8);
            dst += 4;
            src_word++;
        }
        src = (unsigned int)src_word + 3;
        break;
    }

    /* Step 3: the bytes left over after the whole words. */
    while (count & 3) {
        copy_byte(dst, src);
        count--;
        src++;
        dst++;
    }
}
