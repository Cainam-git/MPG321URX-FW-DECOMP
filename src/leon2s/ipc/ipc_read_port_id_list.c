/* ipc_read_port_id_list  (FUN_a006fca8)
 *
 * Read the seven port ids the main processor assigned to the mailbox slots.
 *   ids: seven ids
 * Name basis: derived - nibbles 0..6 of slot 0 word 1, which the main program writes at start-up
 *   (ipc_input_cpu_write_port_nibbles_copy, portal 1 offset 4); caller ipc_publish_port_status
 *
 * Matching notes
 * --------------
 * FUN_a006fca8 (leon2s 0xa006fca8, 92 bytes), flags -mcpu=v8 -Os -g.
 * The count is a variable (gives 'cmp 7; bcs').
 */
extern void ipc_read_mailbox_slot(unsigned char slot, int word, unsigned int *buf, unsigned char n);

#define PORT_ID_COUNT 7                 /* nibbles 0..6 of the word */

/*
 * Read slot 0 of the input-processor mailbox (4 words) and split word 1 into nibbles: nibble i (bits 4i..4i+3)
 * goes to ids[i], for i = 0..6. The caller (ipc_publish_port_status) takes ids[i] as the port id for mailbox
 * slot i + 1.
 *
 *   ids  receives seven ids
 */
void ipc_read_port_id_list(unsigned char *ids)
{
    unsigned int words[4] = { 0, 0, 0, 0 };
    unsigned char i;
    unsigned char count = PORT_ID_COUNT;

    ipc_read_mailbox_slot(0, 0, words, 4);
    for (i = 0; i < count; i++)
        ids[i] = (words[1] >> (i * 4)) & 0xf;
}
