/* dp_mst_handle_connection_status  (FUN_a00d82c8)
 *
 * Answer the MST request 0x02 (CONNECTION_STATUS_NOTIFY).
 * Name basis: proven - case 0x02 = CONNECTION_STATUS_NOTIFY, request number of the DisplayPort MST sideband
 *   message set; called from dp_mst_dispatch_request
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d82c8 @ 0xa00d82c8 (-mcpu=v8 -Os -g)
 * The reply byte is a local whose bit 7 is not written (stack contents), as the firmware does. The result is
 * the first parameter, returned unchanged.
 */
extern int dp_mst_send_reply();
#define MST_REPLY_ONE_BYTE 1    /* reply type 1: dp_mst_pack_request_number packs one byte, the request number */

/*
 * Answer the request CONNECTION_STATUS_NOTIFY (0x02): the reply is one byte holding the request number.
 * Bit 7 of that byte is not written and is whatever the stack held.
 *
 * The parameters are not used; the routine returns the first one unchanged. Called by dp_mst_dispatch_request.
 */
int dp_mst_handle_connection_status(unsigned int param_1, unsigned int param_2)
{
    unsigned char reply[1];

    reply[0] = reply[0] & 0x80 | 2;
    dp_mst_send_reply(reply, 2, 1, MST_REPLY_ONE_BYTE, 1);
    return param_1;
}
