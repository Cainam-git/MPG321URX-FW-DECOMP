/* sys_output_record_set_flag  (FUN_a012be4c)
 *
 * Store one flag of an output record and optionally report it to the input processor.
 * Name basis: descriptive - flag chosen by a selector that is also the command number; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012be4c, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - `value` is an unsigned int;
 *  - the case order (0x52, 0x53, 0x54, 0x24, 0x55, 0x5b) decides the block layout and registers.
 */
/* First word of an output record (the record is 0x24 bytes): one flag per bit 25, 27..31. */
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

/* Selector values: the mailbox command that reports the flag, and the bit it sets in the record. */
#define OUTPUT_FLAG_CMD_BIT29 0x24
#define OUTPUT_FLAG_CMD_BIT27 0x52
#define OUTPUT_FLAG_CMD_BIT28 0x53
#define OUTPUT_FLAG_CMD_BIT30 0x54
#define OUTPUT_FLAG_CMD_BIT31 0x55
#define OUTPUT_FLAG_CMD_BIT25 0x5b

/*
 * Store one flag of output record `id` and, if wanted, tell the input processor.
 *
 *   id      output record index
 *   sel     which flag, and at the same time the mailbox command used to send it: 0x52 bit 27, 0x53 bit 28,
 *           0x54 bit 30, 0x24 bit 29, 0x55 bit 31, 0x5b bit 25; any other value stores nothing
 *   value   the flag value (the low bit is stored)
 *   send    non-zero: send the 4-byte message {id, value, 0, 0} with command `sel`
 *
 * Bit 31 (0x55) is written only when it differs from `value`, and then the message is sent whatever `send` says.
 * No direct caller was found.
 */
void sys_output_record_set_flag(unsigned char id, unsigned char sel, unsigned int value, unsigned char send)
{
    unsigned char msg[4] = {0};

    switch (sel) {
    case OUTPUT_FLAG_CMD_BIT27:
        sys_output_records[id].bit27 = value;
        break;
    case OUTPUT_FLAG_CMD_BIT28:
        sys_output_records[id].bit28 = value;
        break;
    case OUTPUT_FLAG_CMD_BIT30:
        sys_output_records[id].bit30 = value;
        break;
    case OUTPUT_FLAG_CMD_BIT29:
        sys_output_records[id].bit29 = value;
        break;
    case OUTPUT_FLAG_CMD_BIT31:
        if (sys_output_records[id].bit31 != (value & 1)) {
            sys_output_records[id].bit31 = value;
            send = 1;
        }
        break;
    case OUTPUT_FLAG_CMD_BIT25:
        sys_output_records[id].bit25 = value;
        break;
    }
    if (send) {
        msg[0] = id;
        msg[1] = value;
        ipc_send_command(sel, 4, msg, 0);
    }
}
