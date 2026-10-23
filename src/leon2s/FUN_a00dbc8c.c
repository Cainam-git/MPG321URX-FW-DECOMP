/* leon2s FUN_a00dbc8c @ 0xa00dbc8c-0xa00dbe74, -mcpu=v8 -Os -g.
 * void. Bytes: e = DAT_a8078840, st = DAT_a8076099, sel = DAT_a8076098, f = DAT_a807883f, act = DAT_a807883d;
 * word T = DAT_a807a518. e == 0: f = 1 for st 0, f = 0 for st 1; return. st != 2: func_0xa0f83044(s_9f1ccbd8, f)
 * (ROM print and string, outside the image); for st 0 with f 0: print(s_9f1ccbf8, 0), FUN_a00db9d4(),
 * r = FUN_a00dba70(1), sel = 0, f = 1; for st 1 with f 1: print(s_9f1ccbf8, 1), FUN_a00db9d4(),
 * r = FUN_a00dba70(0), sel = 1, f = 0; in both cases act = 1 and T = func_0xa0fc2064() when r == 0, else
 * act = 0; then st = 2. st == 2: when act != 0 and func_0xa0fc2064() - T > 500: for sel 0 / 1 the same
 * FUN_a00db9d4 / FUN_a00dba70(1 / 0) step (r stays 0 for other sel), then act = 1 and T = time when r == 0,
 * else act = 0.
 * Source form: '&&' conditions for the two st cases; the r == 0 arms first.
 */
extern unsigned char DAT_a8078840;
extern unsigned char DAT_a8076099;
extern unsigned char DAT_a8076098;
extern unsigned char DAT_a807883f;
extern unsigned char DAT_a807883d;
extern unsigned int DAT_a807a518;
extern const char s_9f1ccbd8[];
extern const char s_9f1ccbf8[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned int func_0xa0fc2064(void);
extern void FUN_a00db9d4(void);
extern unsigned char FUN_a00dba70(unsigned char);

void FUN_a00dbc8c(void)
{
    unsigned char r = 0;
    unsigned char t;

    if (DAT_a8078840 == 0) {
        if (DAT_a8076099 == 0)
            DAT_a807883f = 1;
        else if (DAT_a8076099 == 1)
            DAT_a807883f = 0;
        return;
    }
    if (DAT_a8076099 != 2) {
        func_0xa0f83044(s_9f1ccbd8, DAT_a807883f);
        if (DAT_a8076099 == 0 && DAT_a807883f == 0) {
            {
                func_0xa0f83044(s_9f1ccbf8, 0);
                FUN_a00db9d4();
                r = FUN_a00dba70(1);
                DAT_a8076098 = 0;
                DAT_a807883f = 1;
                if (r == 0) {
                    DAT_a807883d = 1;
                    DAT_a807a518 = func_0xa0fc2064();
                } else
                    DAT_a807883d = 0;
            }
        } else if (DAT_a8076099 == 1 && (t = DAT_a807883f) == 1) {
            {
                func_0xa0f83044(s_9f1ccbf8, 1);
                FUN_a00db9d4();
                r = FUN_a00dba70(0);
                DAT_a8076098 = t;
                DAT_a807883f = 0;
                if (r == 0) {
                    DAT_a807883d = t;
                    DAT_a807a518 = func_0xa0fc2064();
                } else
                    DAT_a807883d = 0;
            }
        }
        DAT_a8076099 = 2;
        return;
    }
    if (DAT_a807883d == 0)
        return;
    if (func_0xa0fc2064() - DAT_a807a518 <= 500)
        return;
    if (DAT_a8076098 == 0) {
        FUN_a00db9d4();
        r = FUN_a00dba70(1);
    } else if (DAT_a8076098 == 1) {
        FUN_a00db9d4();
        r = FUN_a00dba70(0);
    }
    if (r == 0) {
        DAT_a807883d = 1;
        DAT_a807a518 = func_0xa0fc2064();
    } else
        DAT_a807883d = 0;
}
