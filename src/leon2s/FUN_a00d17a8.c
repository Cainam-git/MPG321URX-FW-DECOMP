/* FUN_a00d17a8 (leon2s 0xa00d17a8-0xa00d1b04, 860 bytes), flags -mcpu=v8 -Os -g.
 * void (void). For each port i = 0..2 (u8): skips the port when func_0xa0f803b8(i) returns 0 (one call per
 * port, with the constant 0 / 1 / 2). Uses the byte flags DAT_a8078ba0[i], the times DAT_a8078ba4[i] (from
 * func_0xa0fc2064()) and bit 31 (b31, set by FUN_a00c7a4c) of word 0 of the 24-byte record DAT_a8078bb0[i].
 * - port 2: func_0xa0f98af0(0) non-zero: when the flag is 0 and (more than 1 time unit passed since the stored
 *   time, or the stored time is 0) FUN_a00c7a4c(2, 1); the flag = 1. Otherwise: a flag of 1 stores the time;
 *   with b31 set and more than 5000 units passed: FUN_a00c7a4c(2, 1), b31 = 0, time = 0; else with b31 set the
 *   flag = 0; then the next port.
 * - ports 0 and 1: bit 1 of func_0xa0fb7fd8(i, 0, 9) set and FUN_a00cc9ac(i) == 1: when the flag is 0 and (more
 *   than 0x5a units passed or the stored time is 0) prints s_9f1c21c8 ("link[%02X] short pulse") with i, calls
 *   FUN_a00c7a4c(i, 1) and FUN_a00c5fb0(ARR_a807d580[i][1]); the flag = 1. Otherwise: a flag of 1 calls
 *   FUN_a00ccad4(i) and stores the time; with b31 set and more than 5000 units passed: time = 0,
 *   FUN_a00c7a4c(i, 1), b31 = 0; else with b31 set the flag = 0; then the next port.
 * - after the flag = 1 paths (and for i > 1): FUN_a00d12e4(i).
 * Source form: the port 2 block indexes its data and calls with i (inside 'if (i == 2)'), as the port 0/1
 * block does; the timeout test is 'b31 && elapsed > 5000' with 'else if (b31)'.
 */
struct Rec24 {
    unsigned int b31 : 1;
    unsigned int rest : 31;
    unsigned char _4[0x18 - 4];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char DAT_a8078ba0[];
extern unsigned int DAT_a8078ba4[];
extern unsigned char ARR_a807d580[][0x1c];
extern const char s_9f1c21c8[];
extern unsigned char func_0xa0f803b8(unsigned char);
extern unsigned char func_0xa0f98af0(unsigned char);
extern unsigned int func_0xa0fc2064(void);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);
extern int func_0xa0f83044(const char *, ...);
extern unsigned char FUN_a00cc9ac(unsigned char);
extern void FUN_a00c7a4c(unsigned char, unsigned char);
extern unsigned char FUN_a00c5fb0(unsigned char);
extern void FUN_a00ccad4(unsigned char);
extern void FUN_a00d12e4(unsigned char);

void FUN_a00d17a8(void)
{
    unsigned char i;

    for (i = 0; i <= 2; i++) {
        if (i == 0) {
            if (!func_0xa0f803b8(0))
                continue;
        }
        if (i == 1) {
            if (!func_0xa0f803b8(1))
                continue;
        }
        if (i == 2) {
            if (!func_0xa0f803b8(2))
                continue;
        }
        if (i == 2) {
            if (func_0xa0f98af0(0)) {
                if (DAT_a8078ba0[i] == 0) {
                    if (func_0xa0fc2064() - DAT_a8078ba4[i] > 1 || DAT_a8078ba4[i] == 0)
                        FUN_a00c7a4c(i, 1);
                }
                DAT_a8078ba0[i] = 1;
            } else {
                if (DAT_a8078ba0[i] == 1)
                    DAT_a8078ba4[i] = func_0xa0fc2064();
                if (DAT_a8078bb0[i].b31 && func_0xa0fc2064() - DAT_a8078ba4[i] > 5000) {
                    FUN_a00c7a4c(i, 1);
                    DAT_a8078bb0[i].b31 = 0;
                    DAT_a8078ba4[i] = 0;
                } else if (DAT_a8078bb0[i].b31)
                    DAT_a8078ba0[i] = 0;
                continue;
            }
        }
        if (i <= 1) {
            if ((func_0xa0fb7fd8(i, 0, 9) & 2) && FUN_a00cc9ac(i) == 1) {
                if (DAT_a8078ba0[i] == 0) {
                    if (func_0xa0fc2064() - DAT_a8078ba4[i] > 0x5a || DAT_a8078ba4[i] == 0) {
                        func_0xa0f83044(s_9f1c21c8, i);
                        FUN_a00c7a4c(i, 1);
                        FUN_a00c5fb0(ARR_a807d580[i][1]);
                    }
                }
                DAT_a8078ba0[i] = 1;
            } else {
                if (DAT_a8078ba0[i] == 1) {
                    FUN_a00ccad4(i);
                    DAT_a8078ba4[i] = func_0xa0fc2064();
                }
                if (DAT_a8078bb0[i].b31 && func_0xa0fc2064() - DAT_a8078ba4[i] > 5000) {
                    DAT_a8078ba4[i] = 0;
                    FUN_a00c7a4c(i, 1);
                    DAT_a8078bb0[i].b31 = 0;
                } else if (DAT_a8078bb0[i].b31)
                    DAT_a8078ba0[i] = 0;
                continue;
            }
        }
        FUN_a00d12e4(i);
    }
}
