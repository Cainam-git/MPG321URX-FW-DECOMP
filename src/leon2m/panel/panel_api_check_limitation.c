/* panel_api_check_limitation  (FUN_a014e8d8)
 *
 * Run the panel limit check (drv_PanelLimitation).
 * Returns: always 0
 * Name basis: derived - forwards to drv_PanelLimitation; called from APPActionDispatcher
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014e8d8 @ 0xa014e8d8, flags -mcpu=v8 -O2.
 */

extern void drv_PanelLimitation(void);

/* Run the panel limit check; called from APPActionDispatcher. Always returns 0. */
unsigned int panel_api_check_limitation(void)
{
    drv_PanelLimitation();
    return 0;
}
