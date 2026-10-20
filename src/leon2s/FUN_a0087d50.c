/* leon2s FUN_a0087d50 @ 0xa0087d50  MATCH (-mcpu=v8 -Os -g)
 * Calls FUN_a00a7940(port, 0x70, 0x20, 1) when param_2 is non-zero, else FUN_a00a7940(port, 0x70, 0x20, 0): sets
 * or clears field 0x20 of register 0x70 of the port. Both parameters are unsigned char (the port is masked with
 * and 0xff).
 */
extern int FUN_a00a7940();

void FUN_a0087d50(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00a7940(param_1, 0x70, 0x20, 1);
    else
        FUN_a00a7940(param_1, 0x70, 0x20, 0);
    return;
}
