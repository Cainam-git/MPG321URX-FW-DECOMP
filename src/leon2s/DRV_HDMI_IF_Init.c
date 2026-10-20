/* leon2s DRV_HDMI_IF_Init @ 0xa00a1758 (-mcpu=v8 -Os)
 * If the initialised flag is already set, prints the verbose trace "Init Again!!"; otherwise clears the
 * 800-byte state buffer, runs three sub-inits, configures item 0x15 and sets the initialised flag.
 * Always returns 0.
 * Source form: the trace function FUN_a0073044 is declared to return int (printf-style); declared void,
 * gcc swaps the two string-address ORs around the call.
 */
extern unsigned char DAT_a807db68;                    /* 0xa807db68 */
extern unsigned char DAT_a807d7e0[];                  /* 0xa807d7e0, 800-byte buffer */
extern int FUN_a0073044(const char *, ...); /* 0xa0073044 */
extern void FUN_a00b15ac(void *, int, int);     /* 0xa00b15ac */
extern void FUN_a0096a6c(void);                       /* 0xa0096a6c */
extern void FUN_a00a303c(void);                       /* 0xa00a303c */
extern void FUN_a009c188(int);                        /* 0xa009c188 */

int DRV_HDMI_IF_Init(void)
{
    if (DAT_a807db68 != 0) {
        FUN_a0073044("[VERBOSE]: %s Init Again!!\n", __FUNCTION__);
    } else {
        FUN_a00b15ac(DAT_a807d7e0, 0, 800);
        FUN_a0096a6c();
        FUN_a00a303c();
        FUN_a009c188(0x15);
        DAT_a807db68 = 1;
    }
    return 0;
}
