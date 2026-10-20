/* leon2m FUN_a01382b0 @ 0xa01382b0 (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x7F, 4, buffer, 0) with the 4-byte buffer {0x3C, 0, 0, 0}. The source zero-initialises the
 * buffer and then ORs 0x3C into byte 0.
 */
extern int FUN_a01370dc();

void FUN_a01382b0(void)
{
    unsigned char local_10[4] = {0};
    local_10[0] |= 0x3c;
    FUN_a01370dc(0x7f, 4, local_10, 0);
}
