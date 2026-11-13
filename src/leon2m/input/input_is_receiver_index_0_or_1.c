/* input_is_receiver_index_0_or_1  (FUN_a01422f4)
 *
 * Return whether a value is 0 or 1.
 * Returns: 0 or 1
 * Name basis: descriptive - plain range test
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01422f4 @ 0xa01422f4, flags -mcpu=v8 -O2 -g (the section default; no cflags entry).
 * Source form the exact build depends on: the parameter is unsigned int (gives the unsigned branch bleu; a signed
 * parameter gives ble); the "1" sits in the branch delay slot, one return point.
 */

/*
 * Return 1 when index is 0 or 1, else 0.
 */
int input_is_receiver_index_0_or_1(unsigned int index)
{
    if (index <= 1)
        return 1;
    return 0;
}
