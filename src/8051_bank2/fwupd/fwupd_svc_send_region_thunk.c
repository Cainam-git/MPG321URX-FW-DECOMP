/* fwupd_svc_send_region_thunk  (FUN_CODE_00fc)
 *
 * Forward to fwupd_svc_send_region.
 * Returns: 0 on success
 * Name basis: derived - returns fwupd_svc_send_region(); last step of fwupd_run_isp_write
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(7,SPEED) LARGE. At this level Keil keeps LCALL + RET here instead of a tail jump.
 */
unsigned char fwupd_svc_send_region(void);

/* fwupd_svc_send_region_thunk: call fwupd_svc_send_region and pass its result back unchanged.
 * fwupd_run_isp_write calls it as its last step, after clearing mailbox byte 0xF19A, and makes a result of 0 into
 * its own result 1. */
unsigned char fwupd_svc_send_region_thunk(void)
{
    return fwupd_svc_send_region();
}
