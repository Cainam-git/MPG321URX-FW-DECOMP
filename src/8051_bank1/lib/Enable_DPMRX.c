/* Enable_DPMRX  (FUN_CODE_dd09)
 *
 * Log and enable both DisplayPort receivers for standby wake-up.
 * Name basis: proven - (original name printed: 'Enable_DPMRX'); calls DP_EnableMRX(0) and (1); mailbox command
 *   0x2A
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dd09 @ 0xdd09
 * Options: OPTIMIZE(8,SPEED). The last call is a tail LJMP. Twin of Disable_DPMRX.
 */
extern void lib_printf517(void *fmt, ...) large;
extern void DP_EnableMRX(unsigned char port);

/* Print "Enable_DPMRX" (text at code 0x6AD8), then call DP_EnableMRX for
 * receiver 0 and receiver 1. */
void Enable_DPMRX(void)
{
    lib_printf517((void code *)0x6ad8);
    DP_EnableMRX(0);
    DP_EnableMRX(1);
}
