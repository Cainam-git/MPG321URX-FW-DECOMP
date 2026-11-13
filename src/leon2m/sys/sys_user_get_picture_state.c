/* sys_user_get_picture_state  (FUN_a00d7d48)
 *
 * Return a code for the current picture state.
 * Returns: state code
 * Name basis: descriptive - 4, or the status field mapped to 1, 2, 3, 5 when port flag 6 is set, else 0; many
 *   callers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d7d48 @ 0xa00d7d48-0xa00d7de0 (38 words), flags -mcpu=v8 -O3 -g.
 * Source form: an int result initialised to 5 and set in each arm of the switch.
 */
extern unsigned char sys_api_get_channel_port_flag9(unsigned char channel);
extern unsigned char sys_api_get_channel_port_flag6(unsigned char channel);
extern unsigned char ipc_api_get_status_field(void);

/*
 * Return a code for the state of channel 0:
 *   4 when flag bit 9 of its port record is set;
 *   otherwise, when flag bit 6 is set, the mailbox status field (ipc_api_get_status_field) mapped as
 *   1 -> 1, 2 -> 2, 3 -> 3, 4 -> 5, anything else -> 0;
 *   otherwise 0.
 * Called from many routines (for example osd_accept_optix_scope and osd_run_navi_key_right).
 */
int sys_user_get_picture_state(void)
{
    int state = 5;

    if (sys_api_get_channel_port_flag9(0) == 1)
        state = 4;
    else if (sys_api_get_channel_port_flag6(0) == 1) {
        switch (ipc_api_get_status_field()) {
        case 1: state = 1; break;
        case 2: state = 2; break;
        case 3: state = 3; break;
        case 4: state = 5; break;
        default: state = 0; break;
        }
    } else
        state = 0;
    return state;
}
