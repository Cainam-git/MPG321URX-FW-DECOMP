/* leon2m FUN_a0138eb4 @ 0xa0138eb4  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a01370dc(0x7B, 4, buffer, 0) with a zeroed 4-byte buffer.
 */
extern int FUN_a01370dc();

void FUN_a0138eb4(void)
{
    unsigned char buf[4] = {0, 0, 0, 0};
    FUN_a01370dc(0x7b, 4, buf, 0);
}
