/* leon2m FUN_a0138180 @ 0xa0138180 (-mcpu=v8 -O2 -g)
 * Prints the two byte parameters with FUN_a00df170(0x1a55e8, p1, p2) (format string at 0x1A55E8), then sends
 * command 0x63 with the 4-byte buffer {p1, p2, 0, 0}: FUN_a01370dc(0x63, 4, buf, 0). The `unsigned char
 * local_10[4]` initializer produces the clr of the word followed by the two stb stores. The print result is not
 * used.
 */
extern int FUN_a00df170();
extern int FUN_a01370dc();

void FUN_a0138180(unsigned char param_1, unsigned char param_2)
{
    unsigned char local_10[4] = {param_1, param_2};
    FUN_a00df170(0x1a55e8, param_1 & 0xff, param_2 & 0xff);
    FUN_a01370dc(0x63, 4, local_10, 0);
}
