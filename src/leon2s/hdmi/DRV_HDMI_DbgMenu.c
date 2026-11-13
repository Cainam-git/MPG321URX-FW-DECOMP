/* DRV_HDMI_DbgMenu  (DRV_HDMI_DbgMenu)
 *
 * Run one HDMI debug menu command (messages, tasks, LTP force pass, PHY bit).
 * Name basis: proven - original name printed ('====DRV_HDMI_DbgMenu===='); commands 6, 7, 10 ('LTP force
 *   pass'), 100
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_DbgMenu @ 0xa00a32d0, flags -mcpu=v8 -Os -g.
 * Source form: the 3-word block (t) is declared before the 2-field one (m): frame layout, block 7 at
 * fp-24, block 6 at fp-32.
 */
struct Arg6 { unsigned int a; unsigned char b; };
struct Arg7 { unsigned int a; unsigned int b; unsigned int c; };
extern char DAT_a006b9a0[], DAT_a006b9e0[];
extern unsigned char hdmi_rx21_ltp_force_pass;
extern int dbg_print_string(const char *);
extern int dbg_printf(const char *, ...);
extern void dbg_set_hdmi_message_flags(struct Arg6 *);
extern int DRV_HDMI_DbgHDMITaskCtrl(struct Arg7 *);
extern void hdmi_rx21_write_reg1f0c_bit18(unsigned int);

/* One command of the HDMI debug menu.
 *   cmd 6:   switch debug message group a on or off (b = 1 on), then list the groups
 *   cmd 7:   hand {a, b} to DRV_HDMI_DbgHDMITaskCtrl (start or stop a task)
 *   cmd 10:  set the "LTP force pass" flag to 1 when b is 1, else to 0
 *   cmd 100: hdmi_rx21_write_reg1f0c_bit18(a != 0)
 * Other commands do nothing. */
void DRV_HDMI_DbgMenu(unsigned int cmd, unsigned int a, unsigned int b)
{
    struct Arg7 t;
    struct Arg6 m;

    dbg_print_string(DAT_a006b9a0);
    switch (cmd) {
    case 6:
        dbg_printf(DAT_a006b9e0, "DRV_HDMI_DbgMenu");
        m.a = a;
        m.b = b;
        dbg_set_hdmi_message_flags(&m);
        break;
    case 7:
        t.a = a;
        t.b = b;
        DRV_HDMI_DbgHDMITaskCtrl(&t);
        break;
    case 10:
        dbg_printf("10 - LTP force pass = %d\n\n", b);
        if (b == 1)
            hdmi_rx21_ltp_force_pass = 1;
        else
            hdmi_rx21_ltp_force_pass = 0;
        break;
    case 100:
        hdmi_rx21_write_reg1f0c_bit18(a != 0);
        break;
    }
}
