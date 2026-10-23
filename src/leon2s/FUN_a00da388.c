/* leon2s FUN_a00da388 @ 0xa00da388-0xa00da49c, -mcpu=v8 -Os -g.
 * (u8 on), void. k = byte DAT_a8078832. When DAT_a8079c48[k] == 0, the 4-bit index DAT_a8078800[k] steps
 * down (0 wraps to 15). v = byte ARR_a8079c62[k][DAT_a8078800[k]] (16-byte rows). v == 1: DAT_a807883d = 1
 * and DAT_a807a518 = func_0xa0fc2064(). Then ARR_a807880a[k] += DAT_a8079c48[k] (kept to 9 bits),
 * DAT_a8078800[k] = (DAT_a8078800[k] + 1) & 0xf, DAT_a8078838[k] = 0. on != 0: bit 4 (v == 0) or bit 5
 * (v != 0) of word +0xccc of the register block DAT_a80760a4[k] is cleared.
 * DAT_a80760a4[] holds register-block pointers (volatile, as in the other users of the table).
 * Source form: v is an unsigned int (no and 0xff after the ldub); the wrap test is written '== 0' first.
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078800[];
extern unsigned char DAT_a8079c48[];
extern unsigned char ARR_a8079c62[][16];
extern unsigned short ARR_a807880a[];
extern unsigned char DAT_a8078838[];
extern unsigned char DAT_a807883d;
extern unsigned int DAT_a807a518;
extern volatile unsigned int *DAT_a80760a4[];
extern unsigned int func_0xa0fc2064(void);

void FUN_a00da388(unsigned char on)
{
    unsigned int v;

    if (DAT_a8079c48[DAT_a8078832] == 0) {
        if (DAT_a8078800[DAT_a8078832] == 0)
            DAT_a8078800[DAT_a8078832] = 15;
        else
            DAT_a8078800[DAT_a8078832] = DAT_a8078800[DAT_a8078832] - 1;
    }
    v = ARR_a8079c62[DAT_a8078832][DAT_a8078800[DAT_a8078832]];
    if (v == 1) {
        DAT_a807883d = v;
        DAT_a807a518 = func_0xa0fc2064();
    }
    ARR_a807880a[DAT_a8078832] = (ARR_a807880a[DAT_a8078832] + DAT_a8079c48[DAT_a8078832]) & 0x1ff;
    DAT_a8078800[DAT_a8078832] = (DAT_a8078800[DAT_a8078832] + 1) & 0xf;
    DAT_a8078838[DAT_a8078832] = 0;
    if (on) {
        if (v == 0)
            DAT_a80760a4[DAT_a8078832][0xccc / 4] &= ~0x10;
        else
            DAT_a80760a4[DAT_a8078832][0xccc / 4] &= ~0x20;
    }
}
