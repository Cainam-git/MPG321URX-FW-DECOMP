/* leon2s FUN_a00ad828 @ 0xa00ad828 (-mcpu=v8 -Os -g)
 * Returns 1 when p1 is one of 0x06, 0x07, 0x0C, 0x0D, 0x12, 0x13, 0x18, 0x19, 0x20, 0x21, 0x26, 0x27; otherwise 0.
 * Source form: Ghidra's type and symbol names are kept.
 */
// FUN_a00ad828 at 0xa00ad828
extern int FUN_a00ad828(unsigned char param_1);

int FUN_a00ad828(unsigned char param_1)
{
    unsigned int uVar1;
    
    if (((((unsigned char)(param_1 - 0xcU) < 2U) || (param_1 == 0x06)) ||
         (param_1 == 0x07) || (param_1 == 0x12)) ||
        ((param_1 == 0x13) || (param_1 == 0x18) || (param_1 == 0x19) ||
         (param_1 == 0x20) || (param_1 == 0x21) || (param_1 == 0x26) ||
         (param_1 == 0x27))) {
        uVar1 = 1;
    } else {
        uVar1 = 0;
    }
    return uVar1;
}
