/* leon2s FUN_a00afd04 @ 0xa00afd04  MATCH (-mcpu=v8 -Os -g)
 * For the port byte p = param_1 & 0xff: stores param_2 to byte 0x115 of the 300-byte per-port record p in
 * ARR_a807dc18, then calls FUN_a00abff0(p), FUN_a00ac66c(p) and tail-calls FUN_a00af98c(p). Each callee takes one
 * argument (only %o0 is set before each call).
 */
extern int FUN_a00abff0(int);
extern int FUN_a00ac66c(int);
extern int FUN_a00af98c(int);
extern char ARR_a807dc18[];

void FUN_a00afd04(unsigned int param_1, unsigned char param_2)
{
    param_1 = param_1 & 0xff;
    ARR_a807dc18[param_1 * 300 + 0x115] = (char)param_2;
    FUN_a00abff0(param_1);
    FUN_a00ac66c(param_1);
    FUN_a00af98c(param_1);
}
