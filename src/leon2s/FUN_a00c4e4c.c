/* leon2s FUN_a00c4e4c @ 0xa00c4e4c (-mcpu=v8 -Os -g)
 * Returns 1 when bit 5 of FUN_a0fb7e98(p1 & 0xff, 0x2e) is set, otherwise 0. Same code as FUN_a0088f28 with other
 * constants.
 * See FUN_a0088f28 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned int FUN_a0fb7e98(unsigned int param_1, unsigned short param_2);

unsigned int FUN_a00c4e4c(unsigned int param_1)
{
    unsigned int x = FUN_a0fb7e98(param_1 & 0xff, 0x2e) & 0x20;
    return x != 0;
}
