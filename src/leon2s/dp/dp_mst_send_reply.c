/* dp_mst_send_reply  (FUN_a00d791c)
 *
 * Build the reply body for a request type and queue it as a down reply.
 * Name basis: derived - one of 14 fill routines by type, then the message is packed and queued
 *
 * Matching notes
 * --------------
 * FUN_a00d791c (leon2s 0xa00d791c-0xa00d7bf8, 732 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - old-style definition with unsigned char queue, direction, type and unsigned short length;
 *  - dp_mst_message_state_port is named directly as the index in the first store and in the copy loop and read
 *    once into port for the closing updates (this keeps a separate address computation for that read);
 *  - the kind store comes before the write index update.
 */

/* Body formats, chosen by the caller. The names give the caller (dp_mst_handle_<request>, dp_mst_send_nak,
   dp_mst_send_status_message). */
enum mst_reply_type {
    MST_REPLY_LINK_ADDRESS        = 0x00,   /* dp_mst_pack_link_address_reply */
    MST_REPLY_CONNECTION_STATUS   = 0x01,   /* one byte, the request number */
    MST_REPLY_ENUM_PATH_RESOURCES = 0x02,
    MST_REPLY_ALLOCATE_PAYLOAD    = 0x03,
    MST_REPLY_CLEAR_PAYLOAD_TABLE = 0x06,   /* one byte, the request number */
    MST_REPLY_REMOTE_DPCD_READ    = 0x07,
    MST_REPLY_REMOTE_DPCD_WRITE   = 0x08,
    MST_REPLY_I2C_READ            = 0x09,
    MST_REPLY_I2C_WRITE           = 0x0a,
    MST_REPLY_POWER_UP_PHY        = 0x0b,
    MST_REPLY_POWER_DOWN_PHY      = 0x0c,
    MST_REPLY_NAK                 = 0x0f,
    MST_STATUS_MESSAGE            = 0x11,   /* dp_mst_send_status_message; the only kind-1 message */
    MST_REPLY_QUERY_STREAM_ENC_STATUS = 0x38
};

/* Message kind kept per ring entry (dp_mst_reply_chunk_rows). The chunk writers put a kind-0 message at word 0
   of the port's message registers with ready bit 4, a kind-1 message at word 0x30 with ready bit 5; when a
   kind-1 message leaves the ring, dp_mst_advance_tx_index sets the notify action. */
#define MST_KIND_0              0
#define MST_KIND_1              1

#define MST_QUEUE_REPLY         2           /* every caller passes 2 and 1 */
#define MST_DIRECTION_DOWN      1

#define MST_BODY_RING_SIZE      512         /* bytes of each port's body ring */
#define MST_RING_ENTRIES        16          /* messages in each port's reply ring */

extern unsigned char dp_mst_message_state_port;                  /* the port being served */
extern unsigned char dp_mst_message_state_reply_write_indexes[]; /* per port: next free ring entry */
extern unsigned short dp_mst_reply_body_write_offsets[];                            /* per port: write position in the body ring */
extern unsigned char dp_mst_reply_headers[][16];                 /* per port and entry: body length */
extern unsigned char dp_mst_reply_chunk_rows[][16];              /* per port and entry: message kind */
extern unsigned char dp_mst_reply_bodies[][0x200];               /* per port: body ring */
extern void dp_mst_pack_link_address_reply(void *, unsigned char *);
extern void dp_mst_pack_request_number(void *, unsigned char *);
extern void dp_mst_pack_19_byte_record(void *, unsigned char *);
extern void dp_mst_pack_enum_path_reply(void *, unsigned char *);
extern void dp_mst_pack_allocate_payload_reply(void *, unsigned char *);
extern void dp_mst_pack_request_number_copy(void *, unsigned char *);
extern void dp_mst_pack_dpcd_read_reply(void *, unsigned char *);
extern void dp_mst_pack_port_reply(void *, unsigned char *);
extern void dp_mst_pack_i2c_read_reply(void *, unsigned char *);
extern void dp_mst_pack_port_reply_copy(void *, unsigned char *);
extern void dp_mst_pack_port_reply_high(void *, unsigned char *);
extern void dp_mst_pack_port_reply_high_copy(void *, unsigned char *);
extern void dp_mst_pack_24_byte_record(void *, unsigned char *);
extern void dp_mst_pack_byte_run(void *, unsigned char *);

/*
 * Pack a message body and put it into the reply ring of the current MST port (dp_mst_message_state_port), from
 * where dp_mst_send_down_reply_step sends it in chunks.
 *
 *   source     what the fill routine packs (the caller's message record)
 *   queue      MST_QUEUE_REPLY; any other value queues nothing
 *   direction  MST_DIRECTION_DOWN; any other value queues nothing
 *   type       enum mst_reply_type: selects the fill routine; a type without a case leaves the body zero
 *   length     body length in bytes; must stay below 256 (the loop counter is a byte)
 *
 * Called by dp_mst_handle_link_address, the other dp_mst_handle_<request> routines, dp_mst_send_nak and
 * dp_mst_send_status_message, all with queue 2 and direction 1.
 *
 * Phases, in order:
 *   1. Clear the first `length` bytes of the body buffer and let the fill routine of `type` write it; type
 *      MST_STATUS_MESSAGE makes it a kind-1 message, every other type kind 0.
 *   2. Ring entry at the port's write index: its length (dp_mst_reply_headers) gets `length`.
 *   3. Copy the body into the port's body ring from its write position on (wrapping at 512) and move the
 *      write position on by `length`.
 *   4. The entry's kind (dp_mst_reply_chunk_rows) is set and the write index steps on (wrapping at 16).
 */
void dp_mst_send_reply(source, queue, direction, type, length)
    void *source;
    unsigned char queue;
    unsigned char direction;
    unsigned char type;
    unsigned short length;
{
    unsigned char body[256];
    unsigned char i;
    unsigned char port;
    unsigned char kind = MST_KIND_0;
    unsigned char entry;

    /* Phase 1. */
    for (i = 0; i < length; i++)
        body[i] = 0;
    switch (type) {
    case MST_REPLY_LINK_ADDRESS:
        dp_mst_pack_link_address_reply(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_CONNECTION_STATUS:
        dp_mst_pack_request_number(source, body);
        kind = MST_KIND_0;
        break;
    case MST_STATUS_MESSAGE:
        dp_mst_pack_19_byte_record(source, body);
        kind = MST_KIND_1;
        break;
    case MST_REPLY_ENUM_PATH_RESOURCES:
        dp_mst_pack_enum_path_reply(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_ALLOCATE_PAYLOAD:
        dp_mst_pack_allocate_payload_reply(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_CLEAR_PAYLOAD_TABLE:
        dp_mst_pack_request_number_copy(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_REMOTE_DPCD_READ:
        dp_mst_pack_dpcd_read_reply(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_REMOTE_DPCD_WRITE:
        dp_mst_pack_port_reply(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_I2C_READ:
        dp_mst_pack_i2c_read_reply(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_I2C_WRITE:
        dp_mst_pack_port_reply_copy(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_POWER_UP_PHY:
        dp_mst_pack_port_reply_high(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_POWER_DOWN_PHY:
        dp_mst_pack_port_reply_high_copy(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_QUERY_STREAM_ENC_STATUS:
        dp_mst_pack_24_byte_record(source, body);
        kind = MST_KIND_0;
        break;
    case MST_REPLY_NAK:
        dp_mst_pack_byte_run(source, body);
        kind = MST_KIND_0;
        break;
    }
    if (queue == MST_QUEUE_REPLY) {
      if (direction == MST_DIRECTION_DOWN) {
        /* Phase 2. */
        dp_mst_reply_headers[dp_mst_message_state_port][dp_mst_message_state_reply_write_indexes[dp_mst_message_state_port]] = length;
        /* Phase 3. */
        for (i = 0; i < length; i++)
            dp_mst_reply_bodies[dp_mst_message_state_port][(dp_mst_reply_body_write_offsets[dp_mst_message_state_port] + i) % MST_BODY_RING_SIZE] = body[i];
        port = dp_mst_message_state_port;
        dp_mst_reply_body_write_offsets[port] = (dp_mst_reply_body_write_offsets[port] + length) % MST_BODY_RING_SIZE;
        /* Phase 4. */
        entry = dp_mst_message_state_reply_write_indexes[port];
        dp_mst_reply_chunk_rows[port][entry] = kind;
        dp_mst_message_state_reply_write_indexes[port] = (entry + 1) % MST_RING_ENTRIES;
      }
    }
}
