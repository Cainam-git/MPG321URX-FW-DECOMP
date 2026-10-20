/* EN_HDMI_MSG_INIT_INFO (leon2s 0xa00a317c-0xa00a3250, 212 bytes), flags -mcpu=v8 -Os -g.
 * Argument block {n (word), on (byte)}. n > 15: tail-calls FUN_a00734c4(DAT_a006b940). n == 15: clears the word
 * DAT_a8078634 and calls FUN_a00734c4(DAT_a006b960). Otherwise sets (on == 1) or clears bit n of DAT_a8078634.
 * Then for i = 0..14 calls FUN_a0073044(s_a006b980, PTR_a00b4c80[i], DAT_a006b990 or, when bit i of
 * DAT_a8078634 is clear, DAT_a006b998); s_a006b980 is a format string with two %s fields. PTR_a00b4c80 is a table of string
 * pointers whose first entry is the function name.
 */
struct Arg6 { unsigned int n; unsigned char on; };
extern unsigned int DAT_a8078634;
extern char DAT_a006b940[], DAT_a006b960[], DAT_a006b990[], DAT_a006b998[], s_a006b980[];
extern char *PTR_a00b4c80[];
extern int FUN_a00734c4(const char *);
extern int FUN_a0073044(const char *, ...);

void EN_HDMI_MSG_INIT_INFO(struct Arg6 *arg)
{
    unsigned int n = arg->n;
    unsigned int i;

    if (n > 15) {
        FUN_a00734c4(DAT_a006b940);
        return;
    }
    if (n == 15) {
        DAT_a8078634 = 0;
        FUN_a00734c4(DAT_a006b960);
    } else if (arg->on == 1) {
        DAT_a8078634 |= 1 << n;
    } else {
        DAT_a8078634 &= ~(1 << n);
    }
    for (i = 0; i < 15; i++)
        FUN_a0073044(s_a006b980, PTR_a00b4c80[i], (DAT_a8078634 & (1 << i)) ? DAT_a006b990 : DAT_a006b998);
}
