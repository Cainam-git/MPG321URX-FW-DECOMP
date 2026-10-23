/* leon2m FUN_a0138e8c @ 0xa0138e8c (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x7a, 1, &p1, 0) with the address of its byte parameter. Same code as FUN_a0138bf8 with other
 * constants.
 */
extern int FUN_a01370dc();

void FUN_a0138e8c(unsigned char param_1)
{
    FUN_a01370dc(0x7a, 1, &param_1, 0);
    return 0;
}
