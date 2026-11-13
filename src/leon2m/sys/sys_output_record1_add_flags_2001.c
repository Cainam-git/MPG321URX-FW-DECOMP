/* sys_output_record1_add_flags_2001  (FUN_a012c090)
 *
 * Add the flag bits 0x2001 to output record 1 and report them.
 * Name basis: descriptive - mailbox command 0x56; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012c090 @ 0xa012c090-0xa012c0f8 (26 words).
 * sys_output_record_add_flags is defined in this file and inlined.
 */
struct output_record {
    unsigned char pad0[0x1c];
    unsigned short request_flags;               /* +0x1c */
    unsigned char pad1e[0x24 - 0x1e];
};
extern struct output_record sys_output_records[];
extern void ipc_send_command(int, int, void *, int);

#define IPC_CMD_OUTPUT_REQUEST_FLAGS 0x56       /* mailbox command 0x56: set request bits of one DP transmitter */

/* Same routine as in sys_output_record_add_flags: set flags in the flag halfword of output record index and send it. */
void sys_output_record_add_flags(unsigned char index, unsigned short flags)
{
    unsigned char msg[12] = {0};

    sys_output_records[index].request_flags |= flags;
    msg[0] = index;
    msg[1] = sys_output_records[index].request_flags;
    msg[2] = sys_output_records[index].request_flags >> 8;
    ipc_send_command(IPC_CMD_OUTPUT_REQUEST_FLAGS, 0xc, msg, 0);
}

/* Set bits 0 and 13 (0x2001) in the flag halfword of output record 1 and send it (mailbox command 0x56). */
void sys_output_record1_add_flags_2001(void)
{
    sys_output_record_add_flags(1, 0x2001);
}
