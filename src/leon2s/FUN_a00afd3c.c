/* leon2s FUN_a00afd3c @ 0xa00afd3c (-mcpu=v8 -Os -g)
 * k = p1 & 0xff. Stores p2 in byte +0x116 of record k of the 300-byte records at 0xA807DC18, then calls
 * FUN_a00abff0(k), FUN_a00ac66c(k) and FUN_a00af98c(k). Same code as FUN_a00afd04 with other constants.
 */
extern int FUN_a00abff0(int);
extern int FUN_a00ac66c(int);
extern int FUN_a00af98c(int);
extern char ARR_a807dc18[];

void FUN_a00afd3c(unsigned int param_1, unsigned char param_2)
{
    param_1 = param_1 & 0xff;
    ARR_a807dc18[param_1 * 300 + 0x116] = (char)param_2;
    FUN_a00abff0(param_1);
    FUN_a00ac66c(param_1);
    FUN_a00af98c(param_1);
}
