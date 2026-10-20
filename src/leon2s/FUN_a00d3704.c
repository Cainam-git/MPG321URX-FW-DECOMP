/* leon2s FUN_a00d3704 @ 0xa00d3704-0xa00d378c (34 words), flags -mcpu=v8 -Os -g.
 * mode param_2 == 1: acc = word 0xa80785e0; acc != level -> acc = FUN_a00d36e4(level << 8, acc, 0x28) (two
 * compares, bgu / bcc); level = (acc + 0x80) >> 8. Else acc = level << 8. Clamp: level > 0x514 -> 0x514,
 * else max(level, u16 0xa80783dc). Tail call FUN_a00d2378((u16)level).
 * The tail callee takes one argument (the firmware sets only %i0 before call+restore).
 */
typedef unsigned int uint;

extern unsigned int _DAT_a80785e0;
extern unsigned short _DAT_a80783dc;
extern uint FUN_a00d36e4(int param_1, int param_2, int param_3);
extern void FUN_a00d2378(unsigned short param_1);

void FUN_a00d3704(uint param_1, int param_2)
{
    uint uVar1;
    uint local;
    
    if (param_2 == 1) {
        local = _DAT_a80785e0;
        if (local > param_1) {
            _DAT_a80785e0 = FUN_a00d36e4(param_1 << 8, local, 0x28);
        } else if (local < param_1) {
            _DAT_a80785e0 = FUN_a00d36e4(param_1 << 8, local, 0x28);
        }
        param_1 = (_DAT_a80785e0 + 0x80) >> 8;
    } else {
        _DAT_a80785e0 = param_1 << 8;
    }
    
    uVar1 = 0x514;
    if (param_1 < 0x515) {
        uVar1 = _DAT_a80783dc;
        if (param_1 >= _DAT_a80783dc) {
            uVar1 = param_1;
        }
    }
    
    FUN_a00d2378((unsigned short)uVar1);
}
