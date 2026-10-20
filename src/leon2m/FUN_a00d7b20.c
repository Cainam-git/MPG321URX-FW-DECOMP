/* leon2m FUN_a00d7b20 @ 0xa00d7b20  MATCH (-mcpu=v8 -O2 -g)
 * Fills a 16-byte local buffer with FUN_a00d6054(1, buf1), copies it to a second 16-byte local, passes the copy to
 * FUN_a0149b8c(1, buf2) and calls FUN_a0149e8c(1). The two parameters are unused and nothing is returned.
 */
extern void FUN_a00d6054(int, void *);
extern void FUN_a0149b8c(int, void *);
extern void FUN_a0149e8c(unsigned char);

void FUN_a00d7b20(int param_1, int param_2)
{
    unsigned long long buf1[2];
    unsigned long long buf2[2];

    FUN_a00d6054(1, buf1);
    buf2[0] = buf1[0];
    buf2[1] = buf1[1];
    FUN_a0149b8c(1, buf2);
    FUN_a0149e8c(1);
}
