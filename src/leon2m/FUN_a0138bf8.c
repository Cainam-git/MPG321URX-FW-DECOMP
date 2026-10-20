/* leon2m FUN_a0138bf8 @ 0xa0138bf8  MATCH (-mcpu=v8 -O2 -g)
 * Sends command 0x77 with the byte parameter as its single data byte: the parameter is stored to its stack slot
 * and FUN_a01370dc(0x77, 1, &param_1, 0) is called. The call result is ignored and %i0 is not set before ret;
 * restore, so the function is void (the stray `return 0` compiles to nothing).
 */
extern int FUN_a01370dc();

void FUN_a0138bf8(unsigned char param_1)
{
    FUN_a01370dc(0x77, 1, &param_1, 0);
    return 0;
}
