/* leon2m FUN_a0133564 @ 0xa0133564  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a0133514: same code, constants swapped; byte-exact.
 */
extern int func_0x4008c4d0();

int FUN_a0133564(void)
{
    unsigned int local_c;

    local_c = 0;
    func_0x4008c4d0(0, 0xb8, &local_c, 1);
    return (local_c >> 8) & 0xff;
}
