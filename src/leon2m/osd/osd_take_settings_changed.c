/* osd_take_settings_changed  (FUN_a00b5014)
 *
 * Return and clear the settings-changed request (bit 1 of 0xA802B08E)
 * Returns: 1 when it was set
 * Note: Bit 1 is set after every value change; posted as menu event 0x80.
 * Name basis: derived - set by '|= 2' in every value handler; read by osd_run_task_post_redraw_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00b5014 @ 0xa00b5014, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the shifted value is held in a local int, the masked byte is stored back, and the low bit of
 * the shifted value is returned (same form as osd_take_request_bit2).
 */
extern unsigned char osd_request_bits;   // 0xa802b08e

#define OSD_REQUEST_SETTINGS_CHANGED_BIT 1      /* bit 1 of osd_request_bits (mask 0x02) */

/* Return whether the settings-changed request (bit 1 of osd_request_bits) was set, and clear it.
 * The bit is set by the value handlers after a setting was changed; osd_run_task_post_redraw_event posts
 * it as menu event 0x80. Returns 1 when the bit was set, otherwise 0. */
int osd_take_settings_changed(void)
{
    int shifted;

    shifted = osd_request_bits >> OSD_REQUEST_SETTINGS_CHANGED_BIT;
    osd_request_bits = osd_request_bits & 0xfd;
    return shifted & 1;
}
