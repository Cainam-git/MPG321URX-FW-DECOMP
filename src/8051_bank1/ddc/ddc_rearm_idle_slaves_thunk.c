/* ddc_rearm_idle_slaves_thunk  (thunk_FUN_CODE_568f)
 *
 * Forward to ddc_rearm_idle_slaves.
 * Name basis: derived - single LJMP to ddc_rearm_idle_slaves (ddc_rearm_idle_slaves); called from
 *   sys_service_ddc_and_cec
 *
 * Matching notes
 * --------------
 * 8051_bank1 thunk_FUN_CODE_568f @ 0xdeff (3 bytes), OPTIMIZE(8,SPEED): level 8 turns the call into a tail jump,
 * so the whole routine is one LJMP 0x568F.
 */
extern void ddc_rearm_idle_slaves(void);

/*
 * Jump on to ddc_rearm_idle_slaves. Only caller: sys_service_ddc_and_cec (LCALL 0xDEFF), on every call.
 */
void ddc_rearm_idle_slaves_thunk(void)
{
    ddc_rearm_idle_slaves();
}
