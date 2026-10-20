/* DRV_HDMI_DbgMenu (leon2s 0xa00a32d0-0xa00a338c, 188 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00734c4(DAT_a006b9a0), then by cmd: 6: FUN_a0073044(DAT_a006b9e0, s_a00b4ce0) (s_a00b4ce0 is the
 * function name "DRV_HDMI_DbgMenu") and EN_HDMI_MSG_INIT_INFO with a stack block {a (word), b (byte)};
 * 7: DRV_HDMI_DbgHDMITaskCtrl with a 3-word stack block {a, b, (unset)}; 10: FUN_a0073044(s_a006b9e8, b) (string
 * starting "10") and DAT_a8079052 = 1 when b is 1, else 0; 100: FUN_a00a1df0(a != 0). Other values do nothing.
 * The 3-word block is declared before the 2-field one (frame layout: block 7 at fp-24, block 6 at fp-32).
 */
struct Arg6 { unsigned int a; unsigned char b; };
struct Arg7 { unsigned int a; unsigned int b; unsigned int c; };
extern char DAT_a006b9a0[], DAT_a006b9e0[], s_a00b4ce0[], s_a006b9e8[];
extern unsigned char DAT_a8079052;
extern int FUN_a00734c4(const char *);
extern int FUN_a0073044(const char *, ...);
extern void EN_HDMI_MSG_INIT_INFO(struct Arg6 *);
extern int DRV_HDMI_DbgHDMITaskCtrl(struct Arg7 *);
extern void FUN_a00a1df0(unsigned int);

void DRV_HDMI_DbgMenu(unsigned int cmd, unsigned int a, unsigned int b)
{
    struct Arg7 t;
    struct Arg6 m;

    FUN_a00734c4(DAT_a006b9a0);
    switch (cmd) {
    case 6:
        FUN_a0073044(DAT_a006b9e0, s_a00b4ce0);
        m.a = a;
        m.b = b;
        EN_HDMI_MSG_INIT_INFO(&m);
        break;
    case 7:
        t.a = a;
        t.b = b;
        DRV_HDMI_DbgHDMITaskCtrl(&t);
        break;
    case 10:
        FUN_a0073044(s_a006b9e8, b);
        if (b == 1)
            DAT_a8079052 = 1;
        else
            DAT_a8079052 = 0;
        break;
    case 100:
        FUN_a00a1df0(a != 0);
        break;
    }
}
