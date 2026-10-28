/* leon2m FUN_a0155bdc @ 0xa0155bdc-0xa0155c40 (100 bytes), flags -mcpu=v8 -O2 -g.
 * Copies the floats a and b into locals, unpacks them with FUN_a0156f34 into two 4-word local buffers; returns -1
 * when word 0 of either buffer is <= 1, otherwise FUN_a015700c(buf1, buf2). Same code as FUN_a0155b78; single-precision
 * form of FUN_a01566b0 (which uses 6-word buffers and returns 1).
 * Source form: the parameters are copied into float locals before their addresses are taken (the firmware stores
 * them in the local frame, not in the incoming argument slots).
 */

extern void FUN_a0156f34(const float *src, unsigned int *dst);
extern int FUN_a015700c(const unsigned int *a, const unsigned int *b);

int FUN_a0155bdc(float a, float b)
{
    unsigned int buf1[4];
    unsigned int buf2[4];
    float ua, ub;

    ua = a;
    ub = b;
    FUN_a0156f34(&ua, buf1);
    FUN_a0156f34(&ub, buf2);

    if (buf1[0] <= 1 || buf2[0] <= 1)
        return -1;

    return FUN_a015700c(buf1, buf2);
}
