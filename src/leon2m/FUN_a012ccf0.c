/* leon2m FUN_a012ccf0 @ 0xa012ccf0-0xa012cd68 (30 words), flags -mcpu=v8 -O3 -g.
 * Code facts: p = 128-byte block. Copies 10 bytes DAT_a802e1a0[0x22..0x2b] to p[8..17]; then sum = u8 sum of
 * p[0..0x7e]; p[0x7f] = sum ? -sum : 0 (checksum byte so the whole block sums to 0, EDID-style). void (%i0 is not
 * changed but no caller value is produced).
 * The source bytes are the record DAT_a802e1a0 at +0x22. Plain for loops, void. Compiler aids: none.
 */
extern unsigned char DAT_a802e1a0[];

void FUN_a012ccf0(unsigned char *p)
{
    unsigned char i;
    unsigned char sum;
    unsigned char c;

    sum = 0;
    for (i = 0; i < 10; i++)
        p[i + 8] = DAT_a802e1a0[i + 0x22];
    for (i = 0; i < 0x7f; i++)
        sum += p[i];
    c = 0;
    if (sum != 0)
        c = -sum;
    p[0x7f] = c;
}
