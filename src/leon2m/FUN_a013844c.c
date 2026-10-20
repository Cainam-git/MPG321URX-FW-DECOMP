/* leon2m FUN_a013844c @ 0xa013844c-0xa01384ac (24 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 24 words.
 * Code facts: builds a 12-byte message at %fp-24: buf[0] = p1, buf[4..11] = src[0..7] (4 byte pairs, loop
 * i = 0..3 u8), then FUN_a01370dc(0x59, 0xc, buf, 0). buf[1..3] are not written.
 * Fix vs the autoc draft (75.00): BEHAVIOUR - the draft stored an uninitialised b1 one round late; the copy is
 * plain buf[4 + 2i] = src[2i]; buf[5 + 2i] = src[2i + 1] (sched2 puts the +1 store first). One 12-byte buffer
 * (the draft had two locals). Aids: none.
 */
extern void FUN_a01370dc(int, int, unsigned char *, int);

void FUN_a013844c(unsigned char p1, const unsigned char *src)
{
    unsigned char buf[12];
    unsigned char i;

    buf[0] = p1;
    for (i = 0; i <= 3; i++) {
        buf[4 + i * 2] = src[i * 2];
        buf[5 + i * 2] = src[i * 2 + 1];
    }
    FUN_a01370dc(0x59, 0xc, buf, 0);
}
