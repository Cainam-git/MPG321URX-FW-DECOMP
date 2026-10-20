/* leon2m FUN_a01381c4 @ 0xa01381c4  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x75, 4, buf, 0) with a 4-byte buffer holding param_1 in byte 0 and zeros. Sibling functions
 * with the same form use 0x78 and 0x86.
 */
extern int FUN_a01370dc();

void FUN_a01381c4(unsigned char param_1)
{
    unsigned char local_10[4] = {param_1};
    FUN_a01370dc(0x75, 4, local_10, 0);
}
