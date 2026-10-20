/* FUN_a00a4238 (leon2s 0xa00a4238-0xa00a4370, 312 bytes), flags -mcpu=v8 -Os -g. Returns 0.
 * HDMI TX FRL training step (its trace names DRV_HDMI21_TXDetect_FSM_LTS_4) for one port. Prints the trace
 * when the state word DAT_a807db6c[port] differs from the copy DAT_a807873c[port] and updates the copy; calls
 * FUN_a00919e0(port). While the FRL rate counter DAT_a80791fc[port] is non-zero it is decremented and applied
 * (FUN_a0091918, FUN_a0091b74). Counter 0: FUN_a0091988, FUN_a0091b74, state 6, FUN_a0091ac4, prints
 * "No lower FRL_RATE could be used"; otherwise state 3 and DAT_a80791e8[port] = 0. Both paths clear
 * DAT_a80791f0[port] and write the counter to SCDC register 0x31 (FUN_a0091cf4) with a trace print.
 * Source forms: the counter value is taken as (word & 0xff) into an unsigned int, the zero test reads the word
 * again; each arm has its own value variable and its own write and print (GCC shares only the print call).
 */
extern unsigned int DAT_a807db6c[];
extern unsigned int DAT_a807873c[];
extern unsigned int DAT_a80791fc[];
extern unsigned char DAT_a80791e8[];
extern unsigned char DAT_a80791f0[];
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern void FUN_a00919e0(unsigned int);
extern void FUN_a0091918(unsigned int, unsigned char);
extern void FUN_a0091b74(unsigned int);
extern void FUN_a0091988(unsigned int);
extern void FUN_a0091ac4(unsigned int);
extern void FUN_a0091cf4(unsigned int, char, unsigned char);

int FUN_a00a4238(unsigned int port)
{
    unsigned int r;
    unsigned int n;

    port &= 0xff;
    if (DAT_a807db6c[port] != DAT_a807873c[port]) {
        FUN_a0073044("\x1b[1;33m[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_4\n", port);
        DAT_a807873c[port] = DAT_a807db6c[port];
    }
    FUN_a00919e0(port);
    if (DAT_a80791fc[port] != 0) {
        DAT_a80791fc[port]--;
        FUN_a0091918(port, DAT_a80791fc[port]);
        FUN_a0091b74(port);
    }
    r = DAT_a80791fc[port] & 0xff;
    if (DAT_a80791fc[port] == 0) {
        FUN_a0091988(port);
        FUN_a0091b74(port);
        DAT_a807db6c[port] = 6;
        FUN_a0091ac4(port);
        FUN_a00734c4("\x1b[0;33m\t\t - No lower FRL_RATE could be used\n");
        n = DAT_a80791fc[port] & 0xff;
        DAT_a80791f0[port] = 0;
        FUN_a0091cf4(port, 0x31, n);
        FUN_a0073044("\x1b[0;33m\t\t - SCDC_Write 0x%02X = 0x%02X\n", 0x31, n);
    } else {
        DAT_a807db6c[port] = 3;
        DAT_a80791e8[port] = 0;
        DAT_a80791f0[port] = 0;
        FUN_a0091cf4(port, 0x31, r);
        FUN_a0073044("\x1b[0;33m\t\t - SCDC_Write 0x%02X = 0x%02X\n", 0x31, r);
    }
    return 0;
}
