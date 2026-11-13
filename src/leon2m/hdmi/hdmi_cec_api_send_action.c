/* hdmi_cec_api_send_action  (FUN_a014782c)
 *
 * Send one of six CEC actions (1, 2, 3, 5, 6, 7); other action numbers do nothing.
 * Name basis: derived - switch with cases 1, 2, 3, 5, 6, 7 to the CEC send routines; action 1 only while
 *   channel 0 has a state
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014782c @ 0xa014782c, flags -mcpu=v8 -O3 -g.
 * The switch is an 8-entry jump table; values above 7 do nothing. All calls are tail calls.
 */
extern unsigned char sys_get_channel_state(unsigned char ch);
extern void hdmi_cec_send_message_first(void);
extern void hdmi_cec_send_message_second(void);
extern void hdmi_cec_send_message_third(void);
extern void hdmi_cec_request_vendor_id(void);
extern void hdmi_cec_send_user_control(unsigned char operand);
extern void hdmi_cec_request_osd_name(void);

/* CEC actions. 0 and 4 have no case, and nothing is done for them (or for values above 7). */
#define CEC_ACTION_MESSAGE_FIRST  1     /* only when channel 0 has a state */
#define CEC_ACTION_MESSAGE_SECOND 2
#define CEC_ACTION_MESSAGE_THIRD  3
#define CEC_ACTION_4              4     /* no case: sends nothing */
#define CEC_ACTION_REQUEST_VENDOR_ID 5
#define CEC_ACTION_USER_CONTROL   6
#define CEC_ACTION_REQUEST_OSD_NAME  7

#define MAIN_CHANNEL              0
#define CEC_USER_CONTROL_OPERAND  0x6d  /* the operand action 6 sends */

/*
 * Run one CEC action: call the send routine that belongs to it. Actions 1 to 3 send the three fixed one-byte
 * messages; action 1 is sent only when the state field of channel 0 is not 0 (sys_get_channel_state). 5 requests
 * the vendor ID, 6 sends message code 0x44 with operand 0x6D, 7 requests the OSD name.
 *
 * Called from APPActionDispatcher (action 1 on power on/off, 5 and 7 together), power_enter_app_state and App_Initialize
 * (2 and 3), and from hdmi_user_send_cec_action4 (4).
 */
void hdmi_cec_api_send_action(unsigned char action)
{
    switch (action) {
    case CEC_ACTION_MESSAGE_FIRST:
        if (sys_get_channel_state(MAIN_CHANNEL))
            hdmi_cec_send_message_first();
        break;
    case CEC_ACTION_MESSAGE_SECOND: hdmi_cec_send_message_second(); break;
    case CEC_ACTION_MESSAGE_THIRD: hdmi_cec_send_message_third(); break;
    case CEC_ACTION_REQUEST_VENDOR_ID: hdmi_cec_request_vendor_id(); break;
    case CEC_ACTION_USER_CONTROL: hdmi_cec_send_user_control(CEC_USER_CONTROL_OPERAND); break;
    case CEC_ACTION_REQUEST_OSD_NAME: hdmi_cec_request_osd_name(); break;
    }
}
