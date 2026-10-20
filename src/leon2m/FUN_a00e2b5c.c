/* leon2m FUN_a00e2b5c @ 0xa00e2b5c  MATCH (-mcpu=v8 -O2 -g)
 * FUN_a00e05d8(param_1, 0x1E2, 1, 0), then polls FUN_a00e0514(param_1, 0x213, 1) until it has returned zero six
 * times in a row (a nonzero return restarts the count). Returns (FUN_a00e02ec(param_1, 0x202) << 8) |
 * FUN_a00e02ec(param_1, 0x201).
 */
/* FUN_a00e05d8 at 0xa00e05d8 */
extern int FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);
/* FUN_a00e0514 at 0xa00e0514 */
extern int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
/* FUN_a00e02ec at 0xa00e02ec */
extern int FUN_a00e02ec(unsigned int, unsigned int);

unsigned int FUN_a00e2b5c(unsigned int param_1, unsigned int param_2)
{
    int i;
    int u;

    FUN_a00e05d8(param_1, 0x1e2, 1, 0);
    do {
        i = 0;
        while (1) {
            u = FUN_a00e0514(param_1, 0x213, 1);
            i++;
            if (u != 0)
                break;
            if (i > 5)
                return (FUN_a00e02ec(param_1, 0x202) << 8) |
                       FUN_a00e02ec(param_1, 0x201);
        }
    } while (1);
}
