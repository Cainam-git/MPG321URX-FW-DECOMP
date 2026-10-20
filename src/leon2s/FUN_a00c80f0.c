/* leon2s FUN_a00c80f0 @ 0xa00c80f0 (-mcpu=v8 -Os -g)
 * 
 */
extern int func_0xa0fb7fd8();
extern void func_0xa0fb8054();
extern int func_0xa0fc1794();

int FUN_a00c80f0(unsigned char param_1, unsigned char *param_2,
                 unsigned char param_3, unsigned char param_4, unsigned short param_5)
{
    unsigned int tmp;
    unsigned short s;
    unsigned char c;
    unsigned int u;
    unsigned short i;

    s = (unsigned short)param_5;
    if (s != 0) {
        c = param_1 & 0xff;
        func_0xa0fb8054(c, 0, 0xed, param_3);
        func_0xa0fb8054(c, 0, 0xee, 0);
        func_0xa0fb8054(c, 0, 0xef, param_4);
        func_0xa0fb8054(c, 0, 0xf0, (unsigned char)param_5);
        func_0xa0fb8054(c, 0, 0xf1, (unsigned char)(param_5 >> 8));
        func_0xa0fb8054(c, 0, 0xf3, 7);

        for (i = 0; i < s; i++) {
            c = param_1 & 0xff;
            func_0xa0fb8054(c, 0, 0xf4, *param_2);
            param_2++;
            do {
                u = func_0xa0fb7fd8(c, 0, 0xf2);
            } while ((u & 8) != 0);
        }
        func_0xa0fc1794(2);
        return 0;
    }
    return 1;
}
