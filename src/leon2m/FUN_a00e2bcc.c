/* leon2m FUN_a00e2bcc @ 0xa00e2bcc  MATCH (-mcpu=v8 -O2 -g)
 * The only change from the previous attempt is making the loop counter `i` a signed `int` instead of `unsigned int`. This forces the compiler to emit the signed `ble` instruction (branch if less than or equal) for the `i > 5` check, matching the target exactly. The rest of the code is unchanged and already aligned.
 */
extern int FUN_a00e02ec(unsigned int, unsigned int);
extern int FUN_a00e0514(unsigned int, unsigned int, unsigned int);
extern int FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);

unsigned int FUN_a00e2bcc(unsigned int param_1, unsigned int param_2)
{
    int i;

    FUN_a00e05d8(param_1, 0x216, 1, 0);

    do {
        i = 0;
        while (1) {
            unsigned int r = FUN_a00e0514(param_1, 0x23b, 1);
            i++;
            if (r != 0)
                break;
            if (i > 5) {
                unsigned int hi = FUN_a00e02ec(param_1, 0x227) << 8;
                unsigned int lo = FUN_a00e02ec(param_1, 0x226);
                return hi | lo;
            }
        }
    } while (1);
}
