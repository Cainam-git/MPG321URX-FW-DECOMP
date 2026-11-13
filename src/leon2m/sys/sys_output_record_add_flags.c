/* sys_output_record_add_flags  (FUN_a012bb94)
 *
 * Add flag bits to an output record and report them to the input processor.
 * Name basis: descriptive - halfword +0x1C; mailbox command 0x56; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012bb94 @ 0xa012bb94-0xa012bc00 (27 words).
 */
struct output_record {
    unsigned char pad0[0x1c];
    unsigned short request_flags;               /* +0x1c */
    unsigned char pad1e[0x24 - 0x1e];
};
extern struct output_record sys_output_records[];
extern void ipc_send_command(int, int, void *, int);

#define IPC_CMD_OUTPUT_REQUEST_FLAGS 0x56       /* mailbox command 0x56: set request bits of one DP transmitter */

/*
 * Set the bits of flags in the flag halfword (+0x1c) of output record index, and send the new halfword value
 * to the input processor as the 12-byte message {index, low byte, high byte, 0 ...} with mailbox command 0x56.
 */
void sys_output_record_add_flags(unsigned char index, unsigned short flags)
{
    unsigned char msg[12] = {0};

    sys_output_records[index].request_flags |= flags;
    msg[0] = index;
    msg[1] = sys_output_records[index].request_flags;
    msg[2] = sys_output_records[index].request_flags >> 8;
    ipc_send_command(IPC_CMD_OUTPUT_REQUEST_FLAGS, 0xc, msg, 0);
}
