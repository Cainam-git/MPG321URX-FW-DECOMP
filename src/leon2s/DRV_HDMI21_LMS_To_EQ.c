/* leon2s DRV_HDMI21_LMS_To_EQ @ 0xa0079f80 (-mcpu=v8 -Os -g)
 * The function programs HDMI LMS equalizer tables: it writes halfword values from two tables through register-write helper FUN_a00a7488, with a conditional debug call at the start gated by a hardware flag. The statement order puts `i = 0` before the conditional, and a `goto` gives the exact branch structure. Whether `param_1` needs a separate local to produce the `mov %i0, %l1` in the delay slot is not determined.
 */
extern unsigned int _DAT_a8078634;
extern unsigned short DAT_a00b3b0a[4];
extern unsigned short DAT_a00b3b10[4];
extern unsigned short DAT_a00b3b18[4];
extern void FUN_a0073044(unsigned int, const char *);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a0079e00(unsigned char);

void DRV_HDMI21_LMS_To_EQ(unsigned int param_1, unsigned int param_2)
{
    int i;
    unsigned int u;
    unsigned int p1 = param_1;

    i = 0;
    if ((_DAT_a8078634 & 0x800) == 0) {
        goto skip;
    }
    FUN_a0073044(0xa0067868, "DRV_HDMI21_LMS_To_EQ");
skip:
    do {
        u = p1 & 0xff;
        FUN_a00a7488(u, DAT_a00b3b0a[i], 0xffffff, 0x18000000);
        i++;
    } while (i <= 2);

    i = 0;
    do {
        FUN_a00a7488(u, DAT_a00b3b18[i], 0xfffffff0, 0xf);
        if (i <= 3) {
            FUN_a00a7488(u, DAT_a00b3b10[i], 0xffffff, 0x18000000);
        }
        i++;
    } while (i <= 3);

    FUN_a0079e00(u);
}
