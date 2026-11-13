/* dp_mst_dispatch_request  (FUN_a00d9698)
 *
 * Call the handler for the request number of a received MST message.
 * Name basis: proven - switch on 0x01, 0x02, 0x10, 0x11, 0x14, 0x20..0x25 and 0x38, the request numbers of the
 *   DisplayPort standard
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00d9698 @ 0xa00d9698-0xa00d97bc (292 bytes, 73 words), flags -mcpu=v8 -Os -g.
 * The handlers take no argument: their entries never read %i0, and the firmware 'call; restore' leaves the
 * request number in %o0 only as a left-over (constant arguments would give 'restore %g0, K, %o0'). The default
 * calls dp_mst_send_nak(request, 4, 0) as a tail call.
 * Source form: the cases in ascending order (the stub order in the firmware); the switch is a signed compare
 * tree with its root at 0x20.
 */
extern void dp_mst_handle_link_address(void);
extern void dp_mst_handle_connection_status(void);
extern void dp_mst_handle_enum_path_resources(void);
extern void dp_mst_handle_allocate_payload(void);
extern void dp_mst_handle_clear_payload_table(void);
extern void dp_mst_handle_remote_dpcd_read(void);
extern void dp_mst_handle_remote_dpcd_write(void);
extern void dp_mst_handle_remote_i2c_read(void);
extern void dp_mst_handle_remote_i2c_write(void);
extern void dp_mst_handle_power_up_phy(void);
extern void dp_mst_handle_power_down_phy(void);
extern void dp_mst_handle_query_stream_enc_status(void);
extern void dp_mst_send_nak(unsigned char, int, int);
extern unsigned int dp_mst_get_request_number(void);
/* Request numbers handled here. */
#define MST_REQUEST_LINK_ADDRESS              0x01
#define MST_REQUEST_CONNECTION_STATUS_NOTIFY  0x02
#define MST_REQUEST_ENUM_PATH_RESOURCES       0x10
#define MST_REQUEST_ALLOCATE_PAYLOAD          0x11
#define MST_REQUEST_CLEAR_PAYLOAD_TABLE       0x14
#define MST_REQUEST_REMOTE_DPCD_READ          0x20
#define MST_REQUEST_REMOTE_DPCD_WRITE         0x21
#define MST_REQUEST_REMOTE_I2C_READ           0x22
#define MST_REQUEST_REMOTE_I2C_WRITE          0x23
#define MST_REQUEST_POWER_UP_PHY              0x24
#define MST_REQUEST_POWER_DOWN_PHY            0x25
#define MST_REQUEST_QUERY_STREAM_ENC_STATUS   0x38

/* NAK reasons passed for a request number without a handler. */
#define NAK_REASON_1  4
#define NAK_REASON_2  0

/*
 * Run the handler of the received message that is being processed: the request number comes from
 * dp_mst_get_request_number, and each of the twelve numbers above calls its own dp_mst_handle_* routine.
 * Any other number is answered with dp_mst_send_nak. Called by dp_mst_receive_task.
 */
void dp_mst_dispatch_request(void)
{
    unsigned char request = dp_mst_get_request_number();

    switch (request) {
    case MST_REQUEST_LINK_ADDRESS: dp_mst_handle_link_address(); break;
    case MST_REQUEST_CONNECTION_STATUS_NOTIFY: dp_mst_handle_connection_status(); break;
    case MST_REQUEST_ENUM_PATH_RESOURCES: dp_mst_handle_enum_path_resources(); break;
    case MST_REQUEST_ALLOCATE_PAYLOAD: dp_mst_handle_allocate_payload(); break;
    case MST_REQUEST_CLEAR_PAYLOAD_TABLE: dp_mst_handle_clear_payload_table(); break;
    case MST_REQUEST_REMOTE_DPCD_READ: dp_mst_handle_remote_dpcd_read(); break;
    case MST_REQUEST_REMOTE_DPCD_WRITE: dp_mst_handle_remote_dpcd_write(); break;
    case MST_REQUEST_REMOTE_I2C_READ: dp_mst_handle_remote_i2c_read(); break;
    case MST_REQUEST_REMOTE_I2C_WRITE: dp_mst_handle_remote_i2c_write(); break;
    case MST_REQUEST_POWER_UP_PHY: dp_mst_handle_power_up_phy(); break;
    case MST_REQUEST_POWER_DOWN_PHY: dp_mst_handle_power_down_phy(); break;
    case MST_REQUEST_QUERY_STREAM_ENC_STATUS: dp_mst_handle_query_stream_enc_status(); break;
    default: dp_mst_send_nak(request, NAK_REASON_1, NAK_REASON_2); break;
    }
}
