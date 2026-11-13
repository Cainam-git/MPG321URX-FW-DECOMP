/* ddc_send_vcp_e6_reply  (FUN_a0089f6c)
 *
 * Send a VCP reply for code 0xE6 carrying settings bit 7 of +0xA8.
 * Note: Message 6E 88 02 00 E6 00 00 01 00 v + XOR checksum seeded with 0x50.
 * Name basis: derived - message layout = DDC/CI VCP reply (source 0x6E, opcode 0x02)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0089f6c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the Adaptive-Sync flag is formed as a 0/1 int and the last reply byte is stored by an if/else with the zero
 *    arm first;
 *  - the buffer is reached through a pointer, reply, that the firmware keeps in a register across the calls;
 *  - the body length, 10, is held in an unsigned char local: the checksum loop runs to it and the send passes
 *    length + 1 bytes (body plus checksum).
 */
/* Only the parts of the user settings record this routine reads. */
struct user_settings_view {
    unsigned char pad[0x1e];
    unsigned char input_source;                     /* +0x1e */
    unsigned char pad2[0xa8 - 0x1f];
    unsigned int gaming_flags;                      /* +0xa8 */
};
extern struct user_settings_view user_settings;
extern unsigned char ddc_reply_checksum;
extern void ddc_api_queue_reply(unsigned char, unsigned short, unsigned char *);
extern int input_find_slot_by_port_code(unsigned int);

#define GAMING_FLAG_ADAPTIVE_SYNC 0x80      /* bit 7 of gaming_flags (docs/RECORDS.md) */
#define DDC_ADDRESS               0x6e      /* byte 0 of every reply */
#define DDC_CHECKSUM_SEED         0x50      /* first value of the reply XOR checksum */
#define REPLY_VCP_E6_LENGTH       10        /* reply bytes before the checksum */

/*
 * Queue an unasked GetVCP-style reply for the setting code 0xE6 (the layout is that of ddc_handle_request's
 * GetVCP answers): 6E 88 02, result 0, code E6, 0, largest value 0x0001, present value 0 or 1. The present
 * value is the Adaptive-Sync switch of the user settings. The reply goes to the input slot whose port code is
 * the selected input source. Called from sys_user_apply_adaptive_sync_setting.
 */
void ddc_send_vcp_e6_reply(void)
{
    unsigned char reply_buf[40];
    unsigned char i;
    unsigned char length;
    unsigned char *reply;
    int adaptive_sync;

    reply_buf[0] = DDC_ADDRESS;
    reply_buf[1] = 0x88;                /* 0x80 + the 8 bytes after it, before the checksum */
    reply_buf[2] = 2;
    reply_buf[4] = 0xe6;
    adaptive_sync = (user_settings.gaming_flags & GAMING_FLAG_ADAPTIVE_SYNC) != 0;
    reply_buf[3] = 0;                   /* result: no error */
    reply_buf[5] = 0;
    reply_buf[6] = 0;                   /* largest value, high and low */
    reply_buf[7] = 1;
    reply_buf[8] = 0;                   /* present value, high and low */
    if (!adaptive_sync)
        reply_buf[9] = 0;
    else
        reply_buf[9] = 1;
    ddc_reply_checksum = DDC_CHECKSUM_SEED;
    reply = reply_buf;
    length = REPLY_VCP_E6_LENGTH;
    for (i = 0; i < length; i++)
        ddc_reply_checksum = reply[i] ^ ddc_reply_checksum;
    reply[i] = ddc_reply_checksum;
    ddc_api_queue_reply(input_find_slot_by_port_code(user_settings.input_source), length + 1, reply);
}
