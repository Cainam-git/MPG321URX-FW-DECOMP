/* FUN_a00aba14 (leon2s 0xa00aba14-0xa00aba4c, 56 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Clears the bytes at offsets 0, 0x2e, 0xb5, 0xdc, 0xef, 2, 4 and 6 of the 300-byte record port of
 * ARR_a807dc18. Source order of the stores as written; the scheduler moves the offset 6 store up.
 */
extern unsigned char ARR_a807dc18[][300];

void FUN_a00aba14(unsigned char port)
{
    ARR_a807dc18[port][0] = 0;
    ARR_a807dc18[port][0x2e] = 0;
    ARR_a807dc18[port][0xb5] = 0;
    ARR_a807dc18[port][0xdc] = 0;
    ARR_a807dc18[port][0xef] = 0;
    ARR_a807dc18[port][2] = 0;
    ARR_a807dc18[port][4] = 0;
    ARR_a807dc18[port][6] = 0;
}
