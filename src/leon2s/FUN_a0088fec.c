/* leon2s FUN_a0088fec @ 0xa0088fec-0xa0089058 (27 words), flags -mcpu=v8 -Os -g.
 * Leaf test of the signed word DAT_a8078a30 with the byte flag DAT_a8078a0f, only when busy == 0:
 * a30 < 40 and flag clear -> flag = 1, return 1; a30 >= 40 and flag set -> flag = 0, return 1; else
 * return 0. a30 is read once per test (two reads on the flag-set path); it is not volatile.
 * Source form: the two tests are separate '&&' ifs inside 'if (busy == 0)'.
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
