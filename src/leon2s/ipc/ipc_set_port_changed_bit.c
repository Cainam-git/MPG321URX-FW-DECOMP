/* ipc_set_port_changed_bit  (FUN_a006fc58)
 *
 * Set the changed bit of one port in the mailbox status word.
 *   p1: port slot
 * Name basis: derived - bit 16 + port of slot 0 word 3; caller ipc_publish_port_status
 *
 * Matching notes
 * --------------
 * FUN_a006fc58 (leon2s 0xa006fc58), flags -mcpu=v8 -Os -g.
 * The port number is first copied to a local ('t'); the second parameter is not used.
 */
extern void ipc_read_mailbox_slot(unsigned int slot, int word, unsigned int *buffer, unsigned int count);
extern void ipc_write_mailbox_slot(unsigned int slot, int word, unsigned int *buffer, unsigned int count);

#define IPC_SLOT_STATE     0            /* slot 0: state words the input processor publishes */
#define IPC_STATUS_WORD    3            /* its word 3: bits 16..23 = port change bits */
#define PORT_CHANGED_FIRST_BIT 16

/*
 * Mark one port as changed: set bit (16 + port) of slot 0 word 3, by reading the word, setting the bit and
 * writing it back. The main processor clears the bits again with mailbox command 0x81.
 *
 *   port   port slot number 0..6 (the caller passes the index into the port id list)
 *   unused not used
 */
void ipc_set_port_changed_bit(unsigned int port, unsigned int unused)
{
    unsigned int status;
    unsigned int bit;

    bit = port & 0xff;
    ipc_read_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &status, 1);
    status = status | (0x10000 << bit);
    ipc_write_mailbox_slot(IPC_SLOT_STATE, IPC_STATUS_WORD, &status, 1);
}
