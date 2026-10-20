/* leon2m FUN_a0110f5c @ 0xa0110f5c (-mcpu=v8 -O2 -g)
 * So the C should have `func_0x4008c25c(0xb7080168,
 */
extern int func_0x4008c25c();

void FUN_a0110f5c(unsigned char param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
{
    if (param_1 != 0) {
        func_0x4008c25c(0xb7080168, 0x5003814);
        func_0x4008c25c(0xb7080388, 4, param_3, param_4, param_5, param_6);
    } else {
        func_0x4008c25c(0xb7080168, 0x500ae16);
        func_0x4008c25c(0xb7080388, 4, param_3, param_4, param_5, param_6);
    }
}
