/* ipc_input_cpu_write_port_nibbles  (FUN_a0136e9c)
 *
 * Pack eight 4-bit port values into one word and write it to the input processor.
 * Name basis: descriptive - bytes 0xA802A450..57 to mailbox portal 1 offset 4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136e9c, flags -mcpu=v8 -O3 -g. ipc_mailbox_write is declared without a prototype, as the firmware's
 * own calls need.
 */
extern unsigned char ipc_input_cpu_port_nibbles[];
extern unsigned char ipc_input_cpu_word_byte2;
extern void ipc_mailbox_write();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define PORT_IDS_OFFSET       4     /* word 1 of slot 0: the port ids, one nibble each */
#define BYTE2_OFFSET          8     /* word 2 of slot 0 */

/*
 * Write two words to slot 0 of the input processor's mailbox portal. Word 1 packs the eight bytes of
 * ipc_input_cpu_port_nibbles as 4-bit fields (byte n at bit 4 * n); the input program reads the low seven nibbles as
 * the port ids assigned to its mailbox slots (ipc_read_port_id_list). Word 2 holds ipc_input_cpu_word_byte2, the
 * last of the eight bytes, in bits 16..23 and 0 elsewhere. Nothing in the firmware calls this routine; the identical
 * copy ipc_input_cpu_write_port_nibbles_copy is the one startup_bring_up_system calls.
 */
void ipc_input_cpu_write_port_nibbles(void)
{
    unsigned int port_ids;
    unsigned int byte2_word = 0;

    port_ids = ipc_input_cpu_port_nibbles[0] | (ipc_input_cpu_port_nibbles[1] << 4) |
              (ipc_input_cpu_port_nibbles[2] << 8) | (ipc_input_cpu_port_nibbles[3] << 12) |
              (ipc_input_cpu_port_nibbles[4] << 16) | (ipc_input_cpu_port_nibbles[5] << 20) |
              (ipc_input_cpu_port_nibbles[6] << 24) | (ipc_input_cpu_port_nibbles[7] << 28);

    ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, PORT_IDS_OFFSET, &port_ids, 1);

    byte2_word = (unsigned int)ipc_input_cpu_word_byte2 << 16;
    ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, BYTE2_OFFSET, &byte2_word, 1);
}
