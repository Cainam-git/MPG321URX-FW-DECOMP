/* ipc_input_cpu_test_port_mask_alt  (FUN_a01377e8)
 *
 * Return whether a port mask overlaps bits 8-15 of the word at offset 0xCC.
 * Returns: 0 or 1
 * Name basis: descriptive - mailbox portal 1; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01377e8, flags -mcpu=v8 -O3 -g. ipc_mailbox_read is declared without a prototype, as the firmware's
 * own calls need. The second parameter is declared and not used.
 */
extern void ipc_mailbox_read();

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define WORD_OFFSET           0xcc  /* a word of the input processor's portal; the same test as
                                       ipc_input_cpu_test_port_mask, which reads offset 0xC */

/*
 * Return 1 when any bit of the mask is set in bits 8..15 of the word at offset 0xCC of the input processor's portal,
 * else 0. Nothing in the firmware calls this routine.
 *   mask:   bits to test
 *   unused: not used
 */
unsigned int ipc_input_cpu_test_port_mask_alt(unsigned short mask, unsigned int unused)
{
    unsigned int word;
    
    word = 0;
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, WORD_OFFSET, &word, 1);
    return (mask & ((word & 0xff00) >> 8)) != 0;
}
