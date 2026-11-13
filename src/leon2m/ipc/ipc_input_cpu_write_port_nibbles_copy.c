/* ipc_input_cpu_write_port_nibbles_copy  (FUN_a0138ae8)
 *
 * Pack eight 4-bit port values into one word and write it to the input processor.
 * Note: Identical copy of ipc_input_cpu_write_port_nibbles.
 * Name basis: descriptive - bytes 0xA802A450..57 to mailbox portal 1 offset 4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0138ae8 @ 0xa0138ae8, flags -mcpu=v8 -O3 -g.
 * Note: identical copy of ipc_input_cpu_write_port_nibbles (the same code, at another address).
 */
#define IPC_PORTAL_INPUT_CPU 1          /* mailbox portal of the input processor */
#define NIBBLES_OFFSET       4          /* byte offset of word 1 of the portal */
#define BYTE2_OFFSET         8          /* byte offset of word 2 of the portal */
extern unsigned char ipc_input_cpu_port_nibbles[];
extern unsigned char ipc_input_cpu_word_byte2;
extern void ipc_mailbox_write();

/*
 * Write two words to the mailbox portal of the input processor. Word 1 packs the eight bytes of
 * ipc_input_cpu_port_nibbles as 4-bit fields (byte n at bit 4 * n; only the low four bits of a byte matter).
 * Word 2 holds ipc_input_cpu_word_byte2 in bits 16..23. The last of the eight bytes is that same byte.
 *
 * Called from startup_bring_up_system.
 */
void ipc_input_cpu_write_port_nibbles_copy(void)
{
    unsigned int nibbles;
    unsigned int byte2_word = 0;

    nibbles = ipc_input_cpu_port_nibbles[0] | (ipc_input_cpu_port_nibbles[1] << 4) |
              (ipc_input_cpu_port_nibbles[2] << 8) | (ipc_input_cpu_port_nibbles[3] << 12) |
              (ipc_input_cpu_port_nibbles[4] << 16) | (ipc_input_cpu_port_nibbles[5] << 20) |
              (ipc_input_cpu_port_nibbles[6] << 24) | (ipc_input_cpu_port_nibbles[7] << 28);

    ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, NIBBLES_OFFSET, &nibbles, 1);

    byte2_word = (unsigned int)ipc_input_cpu_word_byte2 << 16;
    ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, BYTE2_OFFSET, &byte2_word, 1);
}
