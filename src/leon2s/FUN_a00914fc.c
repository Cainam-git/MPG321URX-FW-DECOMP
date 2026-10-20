/* leon2s FUN_a00914fc @ 0xa00914fc (-mcpu=v8 -Os -g)
 * The function clears a specific bit in a peripheral register at 0xcf03c890. The bit position is given by the parameter. This matches the target exactly: it loads the register value, computes the mask by shifting 1 left by the parameter, performs an AND-NOT operation, and stores the result back. Ghidra's cleaned version already captures the correct structure; the only difference is the parameter type (byte vs. int), which the automated tooling handles.
 */
#define _DAT_cf03c890 (*(volatile unsigned int *)0xcf03c890)

void FUN_a00914fc(unsigned char param_1)
{
    _DAT_cf03c890 = _DAT_cf03c890 & ~(1 << param_1);
    return;
}
