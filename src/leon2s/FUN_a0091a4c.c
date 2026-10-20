/* FUN_a0091a4c (leon2s 0xa0091a4c-0xa0091a88, 60 bytes), flags -mcpu=v8 -Os -g.
 * Sets bit 14 (0x4000) of word 5 of the 7-word (28-byte) record ARR_a807d580[idx], idx = arg & 0xff;
 * idx values above 1 return without a change.
 * Same code shape as FUN_a0091ac4 (which sets bit 31 of word 1); the record pointer is formed before
 * the range test.
 */
extern unsigned int ARR_a807d580[];

void FUN_a0091a4c(unsigned int param_1)
{
    unsigned int idx = param_1 & 0xff;
    unsigned int *p = &ARR_a807d580[idx * 7];

    if (idx > 1) {
        return;
    }
    p[5] |= 0x4000;
}
