/* leon2m FUN_a00d79b0 @ 0xa00d79b0  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a00d7b20: same code, constants swapped; byte-exact.
 * See FUN_a00d7b20 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern void FUN_a00d6054(int, void *);
extern void FUN_a0149b8c(int, void *);
extern void FUN_a014a060(unsigned char);

void FUN_a00d79b0(int param_1, int param_2)
{
    unsigned long long buf1[2];
    unsigned long long buf2[2];

    FUN_a00d6054(1, buf1);
    buf2[0] = buf1[0];
    buf2[1] = buf1[1];
    FUN_a0149b8c(1, buf2);
    FUN_a014a060(1);
}
