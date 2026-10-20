/* leon2m FUN_a0138edc @ 0xa0138edc  MATCH (-mcpu=v8 -O2 -g)
 * Stores the byte param_1 in its stack slot and calls FUN_a01370dc(0x88, 1, &param_1, 0).
 */
extern int FUN_a01370dc();

void FUN_a0138edc(unsigned char param_1)
{
    FUN_a01370dc(0x88, 1, &param_1, 0);
    return 0;
}
