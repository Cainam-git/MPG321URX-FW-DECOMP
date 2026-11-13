/* hdr_request_reload  (FUN_a00d3f54)
 *
 * Mark the HDR settings as changed and request a reload of the curve table.
 * Name basis: derived - byte at 0xA8078C34 = 1, then hdr_request_curve_table_reload
 *
 * Matching notes
 * --------------
 * FUN_a00d3f54 (leon2s 0xa00d3f54-0xa00d3f70, 28 bytes), flags -mcpu=v8 -Os -g.
 * The call of hdr_request_curve_table_reload (a call linked 0xF10000 above hdr_request_curve_table_reload) is a tail call.
 */
extern unsigned char hdr_settings_changed_flag;
extern void hdr_request_curve_table_reload(void);

/*
 * Set hdr_settings_changed_flag (hdr_has_metadata_changed then reports a change at the next step of hdr_task)
 * and request the reload of the curve table. Called by the mailbox command IPC_CMD_REQUEST_HDR_RELOAD.
 */
void hdr_request_reload(void)
{
    hdr_settings_changed_flag = 1;
    hdr_request_curve_table_reload();
}
