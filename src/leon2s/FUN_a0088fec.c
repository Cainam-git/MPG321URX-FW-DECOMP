/* leon2s FUN_a0088fec @ 0xa0088fec-0xa0089058 (27 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/27 mismatches.
 * Code facts: leaf hysteresis on the signed word DAT_a8078a30 with the byte flag DAT_a8078a0f,
 * only when busy == 0: a30 < 40 and flag clear -> flag = 1, return 1; a30 >= 40 and flag set ->
 * flag = 0, return 1; else return 0. a30 is read once per test (two reads on the flag-set path).
 * Fix vs the autoc draft (83.33 band): the two tests are separate '&&' ifs inside 'if (busy == 0)'
 * (the draft's nested re-test needed a volatile on a RAM word; it is not volatile). Aids: none.
 */
extern unsigned char DAT_a8078a0f;
extern int DAT_a8078a30;

unsigned int FUN_a0088fec(unsigned char busy)
{
    if (busy == 0) {
        if (DAT_a8078a30 < 40 && DAT_a8078a0f == 0) {
            DAT_a8078a0f = 1;
            return 1;
        }
        if (DAT_a8078a30 >= 40 && DAT_a8078a0f != 0) {
            DAT_a8078a0f = 0;
            return 1;
        }
    }
    return 0;
}
