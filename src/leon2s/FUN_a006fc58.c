/* leon2s FUN_a006fc58 @ 0xa006fc58 (-mcpu=v8 -Os -g)
 * Reads one word through FUN_a006faa8(0, 3, &w, 1), sets bit 16 + (p1 & 0xff) in it and writes it back through
 * FUN_a006fad4(0, 3, &w, 1).
 * Source form: Ghidra's type and symbol names are kept.
 */
extern void FUN_a006faa8(unsigned int param_1, int param_2, unsigned int *param_3, unsigned int param_4);
extern void FUN_a006fad4(unsigned int param_1, int param_2, unsigned int *param_3, unsigned int param_4);

void FUN_a006fc58(unsigned int param_1, unsigned int param_2)
{
    unsigned int local_c;
    unsigned int t;
    
    t = param_1 & 0xff;
    FUN_a006faa8(0, 3, &local_c, 1);
    local_c = local_c | (0x10000 << t);
    FUN_a006fad4(0, 3, &local_c, 1);
}
