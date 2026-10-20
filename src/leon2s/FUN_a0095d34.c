/* FUN_a0095d34 (leon2s 0xa0095d34-0xa0095d78, 68 bytes), flags -mcpu=v8 -Os -g.
 * Port 0 calls FUN_a0083648(5), port 1 calls FUN_a0083648(6); returns 1 when that call returned 0, else 0.
 * Any other port returns 0 without a call. Same source form as FUN_a0088af0 (if/else chain on the port,
 * result local starting at 0, returned as l0 & 1).
 */
extern int FUN_a0083648(int param_1);

int FUN_a0095d34(unsigned char param_1)
{
    unsigned char l0;

    param_1 = param_1 & 0xff;
    l0 = 0;
    if (param_1 == 0) {
        if (FUN_a0083648(5) == 0) {
            l0 = 1;
        }
    } else if (param_1 == 1) {
        if (FUN_a0083648(6) == 0) {
            l0 = 1;
        }
    }
    return l0 & 1;
}
