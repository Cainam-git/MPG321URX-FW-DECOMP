/* leon2m FUN_a01344f4 @ 0xa01344f4 (-mcpu=v8 -O2 -g)
 * The function extracts bytes from two 16-bit-like parameters and makes two calls to a common helper with constant first arguments (0x14 and 0x15). The second call's last argument is 2 (from `restore %g0, 2, %o4` in the delay slot). The first call has 1. The first parameter is shifted right 8 bits and masked, and the third parameter is a byte passed directly to the second call.
 */
extern int func_0x4008f3f4();

void FUN_a01344f4(short param_1, short param_2, unsigned char param_3)
{
    func_0x4008f3f4(0x14, 0, (param_1 >> 8) & 0xff, param_1 & 0xff, 1);
    func_0x4008f3f4(0x15, param_3, (param_2 >> 8) & 0xff, param_2 & 0xff, 2);
}
