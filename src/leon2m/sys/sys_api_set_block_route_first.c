/* sys_api_set_block_route_first  (FUN_a0132770)
 *
 * Select route 1, 2 or 3 of the first block for a value 0, 1 or 2/4.
 * Name basis: descriptive - tail call with the mapped value
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132770 @ 0xa0132770-0xa01327e0 (28 words), flags -mcpu=v8 -O2 -g (section default).
 * Leaf with tail calls. Exact form: the callee is declared without a prototype (the argument is passed as int).
 * With an unsigned char prototype GCC keeps the argument in %g1 instead of %o0 and fills the first delay slot
 * with it.
 */
extern void Set_INTERNAL_1_INPUT_Path();

/*
 * Select the source of internal signal path 1 from a value: 0 -> 1, 1 -> 2, 2 and 4 -> 3; other values do
 * nothing. sys_api_set_block_route_second is the same for path 2. Caller: sys_api_set_secondary_channel_enable.
 */
void sys_api_set_block_route_first(unsigned char value)
{
    switch (value) {
    case 0:
        Set_INTERNAL_1_INPUT_Path(1);
        break;
    case 1:
        Set_INTERNAL_1_INPUT_Path(2);
        break;
    case 2:
    case 4:
        Set_INTERNAL_1_INPUT_Path(3);
        break;
    }
}
