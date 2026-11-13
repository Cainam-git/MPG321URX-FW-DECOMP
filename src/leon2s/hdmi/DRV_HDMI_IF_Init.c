/* DRV_HDMI_IF_Init  (DRV_HDMI_IF_Init)
 *
 * Initialise the HDMI receiver interface state once.
 * Returns: 0
 * Name basis: proven - original name printed ('[VERBOSE]: %s Init Again!!'); clears the 800-byte state
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_IF_Init @ 0xa00a1758, flags -mcpu=v8 -Os.
 * Source form: the print routine is declared int-returning (printf style); declared void, gcc swaps the
 * two string-address ORs around the call. The two unnamed callees are declared with their labels.
 */
#define HDMI_TIMER_BOTH 0x15    /* timer type: mode-detect and receive-detect tasks */

extern unsigned char hdmi_rx_if_init_flag;
extern unsigned char hdmi_rx21_input_records[];                  /* the two 400-byte receiver records */
extern int dbg_printf(const char *, ...);
extern void lib_memset(void *, int, int);
extern void hdmi_rx21_reset_mode_detect_state(void);
extern void _hdmi21_Initialize(void);
extern void DRV_HDMI_Init_Timer(int);                        /* DRV_HDMI_Init_Timer */

/* Initialises the HDMI receiver interface the first time it is called: clears the 800 bytes of
 * receiver records, resets the mode-detect state, calls FUN_a00a303c, calls DRV_HDMI_Init_Timer with
 * type 0x15 (both tasks) and sets the done flag. When the flag is already set it prints
 * "Init Again!!" and does nothing else.
 * Returns 0. */
int DRV_HDMI_IF_Init(void)
{
    if (hdmi_rx_if_init_flag != 0) {
        dbg_printf("[VERBOSE]: %s Init Again!!\n", __FUNCTION__);
    } else {
        lib_memset(hdmi_rx21_input_records, 0, 800);
        hdmi_rx21_reset_mode_detect_state();
        _hdmi21_Initialize();
        DRV_HDMI_Init_Timer(HDMI_TIMER_BOTH);
        hdmi_rx_if_init_flag = 1;
    }
    return 0;
}
