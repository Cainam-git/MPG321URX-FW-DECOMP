/* FUN_a0085888 (leon2s 0xa0085888-0xa00858cc, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Maps mode 0 / 1 / other to 1 / 2 / 4 and stores the result into byte 1 of DAT_a807cd68 when port is 0, otherwise
 * into byte 1 of DAT_a807cd00. GCC merges the two stores into one store through a selected address.
 * Both byte arrays are volatile, like DAT_a807cd02 in FUN_a00858cc and FUN_a0087734: the
 * firmware never places accesses to the bytes at 0xa807cd00-02 and 0xa807cd68-69 in a delay slot (also
 * FUN_a0085830), which GCC does only for volatile objects.
 */
extern volatile unsigned char DAT_a807cd00[];
extern volatile unsigned char DAT_a807cd68[];

void FUN_a0085888(unsigned char port, unsigned char mode)
{
    unsigned char v;

    switch (mode) {
    case 0: v = 1; break;
    case 1: v = 2; break;
    default: v = 4; break;
    }
    if (port == 0)
        DAT_a807cd68[1] = v;
    else
        DAT_a807cd00[1] = v;
}
