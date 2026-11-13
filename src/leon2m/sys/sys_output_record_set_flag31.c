/* sys_output_record_set_flag31  (FUN_a012c004)
 *
 * Store flag bit 31 of an output record and report it when it changed.
 * Name basis: descriptive - mailbox command 0x55; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012c004 @ 0xa012c004-0xa012c088 (33 words).
 */
/* First word of an output record (0x24 bytes, table sys_output_records): one flag per bit, as in sys_output_record_set_flag. */
struct output_record_flags {
    unsigned int bit31 : 1;
    unsigned int bit30 : 1;
    unsigned int bit29 : 1;
    unsigned int bit28 : 1;
    unsigned int bit27 : 1;
    unsigned int bit26 : 1;
    unsigned int bit25 : 1;
    unsigned int rest : 25;
    unsigned char pad4[0x24 - 4];
};
extern struct output_record_flags sys_output_records[];
extern void ipc_send_command(int, int, void *, int);

#define IPC_CMD_OUTPUT_FLAG_BIT31 0x55          /* mailbox command 0x55: switch a DP transmitter output function on or off */

/*
 * Set bit 31 of output record index to the low bit of value. Only when that changes the bit, send the 4-byte
 * message {index, value, 0, 0} to the input processor with mailbox command 0x55.
 */
void sys_output_record_set_flag31(unsigned char index, unsigned int value)
{
    unsigned char msg[4] = {0};
    unsigned char send = 0;

    if (sys_output_records[index].bit31 != (value & 1)) {
        sys_output_records[index].bit31 = value;
        send = 1;
    }
    if (send) {
        msg[0] = index;
        msg[1] = value;
        ipc_send_command(IPC_CMD_OUTPUT_FLAG_BIT31, 4, msg, 0);
    }
}
