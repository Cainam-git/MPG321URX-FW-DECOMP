/* leon2s FUN_a00da49c @ 0xa00da49c-0xa00da6ac, -mcpu=v8 -Os -g.
 * int (void). k = DAT_a8078832; per-k byte arrays: c = DAT_a8078800[k] (4-bit counter), flag = DAT_a80760b0[k],
 * DAT_a8078838[k], DAT_a8079c48[k], and the 16-byte rows DAT_a8079c62[k][c] (x) and DAT_a807a4f8[k][c] (v).
 * flag 1: DAT_a8078868 = 0x2a, DAT_a8079c48[k] = v; FUN_a00da288() != 0 gives FUN_a00da388(0) and returns 0;
 * v > 0x2a: FUN_a00d9edc(1, 0, 0x2b), FUN_a00da030(DAT_a8079c48[k]), DAT_a8078838[k] = 2, DAT_a8079c48[k] -=
 * DAT_a8078868, flag = 0; else FUN_a00d9edc(1, 1, v + 1), FUN_a00da030(..), the row counter c steps (mod 16) and
 * DAT_a8078838[k] / DAT_a8079c48[k] are cleared. flag 0: when DAT_a8079c48[k] < DAT_a8078868 the same with
 * FUN_a00d9edc(0, 1, DAT_a8079c48[k] + 1) and flag = 1, else FUN_a00d9edc(0, 0, DAT_a8078868 + 1),
 * FUN_a00da030(..) and DAT_a8079c48[k] -= DAT_a8078868. Then sets bit 4 (x == 0) or bit 5 of word 0xccc of the
 * block DAT_a80760a4[k], calls func_0xa0fbe1c0(k) and returns 1. k is re-read from DAT_a8078832 after each call.
 * Source form: the order of the four stores in each counter-step arm (DAT_a8079c48, flag, counter, DAT_a8078838).
 */
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078800[];
extern unsigned char DAT_a80760b0[];
extern unsigned char DAT_a8079c62[][16];
extern unsigned char DAT_a807a4f8[][16];
extern unsigned char DAT_a8079c48[];
extern unsigned char DAT_a8078838[];
extern unsigned char DAT_a8078868;
extern volatile unsigned int *DAT_a80760a4[];
extern unsigned char FUN_a00da288(void);
extern void FUN_a00da388(unsigned char);
extern void FUN_a00d9edc(unsigned char, unsigned char, unsigned char);
extern void FUN_a00da030(unsigned char);
extern void func_0xa0fbe1c0(unsigned char);

int FUN_a00da49c(void)
{
    unsigned char flag, x, v;

    x = DAT_a8079c62[DAT_a8078832][DAT_a8078800[DAT_a8078832]];
    flag = DAT_a80760b0[DAT_a8078832];
    if (flag == 1) {
        v = DAT_a807a4f8[DAT_a8078832][DAT_a8078800[DAT_a8078832]];
        DAT_a8078868 = 0x2a;
        DAT_a8079c48[DAT_a8078832] = v;
        if (FUN_a00da288()) {
            FUN_a00da388(0);
            return 0;
        }
        if (v > 0x2a) {
            FUN_a00d9edc(1, 0, 0x2b);
            FUN_a00da030(DAT_a8079c48[DAT_a8078832]);
            DAT_a8078838[DAT_a8078832] = 2;
            DAT_a8079c48[DAT_a8078832] -= DAT_a8078868;
            DAT_a80760b0[DAT_a8078832] = 0;
        } else {
            FUN_a00d9edc(1, 1, v + 1);
            FUN_a00da030(DAT_a8079c48[DAT_a8078832]);
            DAT_a8079c48[DAT_a8078832] = 0;
            DAT_a80760b0[DAT_a8078832] = flag;
            DAT_a8078800[DAT_a8078832] = (DAT_a8078800[DAT_a8078832] + 1) & 0xf;
            DAT_a8078838[DAT_a8078832] = 0;
        }
    } else if (DAT_a8079c48[DAT_a8078832] < DAT_a8078868) {
        FUN_a00d9edc(0, 1, DAT_a8079c48[DAT_a8078832] + 1);
        FUN_a00da030(DAT_a8079c48[DAT_a8078832]);
        DAT_a8079c48[DAT_a8078832] = 0;
        DAT_a80760b0[DAT_a8078832] = 1;
        DAT_a8078800[DAT_a8078832] = (DAT_a8078800[DAT_a8078832] + 1) & 0xf;
        DAT_a8078838[DAT_a8078832] = 0;
    } else {
        FUN_a00d9edc(0, 0, DAT_a8078868 + 1);
        FUN_a00da030(DAT_a8079c48[DAT_a8078832]);
        DAT_a8079c48[DAT_a8078832] -= DAT_a8078868;
    }
    if (x == 0)
        DAT_a80760a4[DAT_a8078832][0xccc / 4] |= 0x10;
    else
        DAT_a80760a4[DAT_a8078832][0xccc / 4] |= 0x20;
    func_0xa0fbe1c0(DAT_a8078832);
    return 1;
}
