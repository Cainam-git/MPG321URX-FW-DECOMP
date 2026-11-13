/* ipc_input_cpu_write_flags_word  (FUN_a0136f4c)
 *
 * Build a flags word from a 16-bit value and write it to the input processor.
 * Name basis: descriptive - mailbox portal 1
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136f4c, flags -mcpu=v8 -O3 -g. ipc_mailbox_write is declared without a prototype, as the firmware's
 * own calls need.
 */
extern unsigned char ipc_input_cpu_word_byte2;
extern int ipc_mailbox_write();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define BYTE2_OFFSET          8     /* word 2 of slot 0 */

/*
 * Write word 2 of slot 0 of the input processor's mailbox portal: ipc_input_cpu_word_byte2 in bits 16..23 and, in
 * the top byte, the bits of the argument moved up: bit 0 -> 0x04, bit 1 -> 0x08, bit 2 -> 0x10, bit 3 -> 0x20.
 * The input program copies bit n of that top byte into bit 7 of the flags of its port record n
 * (input_load_port_flag_bits). Caller: input_report_present_ports, with port_present_mask.
 *   port_bits: bits 0..3 are used
 */
void ipc_input_cpu_write_flags_word(unsigned short port_bits)
{
    unsigned int flags = 0;
    unsigned int word;
    
    if (port_bits & 1)  flags = 4;
    if (port_bits & 2)  flags |= 8;
    if (port_bits & 4)  flags |= 0x10;
    if (port_bits & 8)  flags |= 0x20;
    
    word = ((unsigned int)ipc_input_cpu_word_byte2 << 16) | (flags << 24);
    ipc_mailbox_write(IPC_PORTAL_INPUT_CPU, BYTE2_OFFSET, &word, 1);
}
