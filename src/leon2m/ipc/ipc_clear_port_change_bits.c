/* ipc_clear_port_change_bits  (FUN_a013730c)
 *
 * Ask the input processor to clear the given port change bits of its state word (command 0x81).
 * Note: Sends 12 data bytes, only byte 0 (the bits) is not zero; does not wait; no routine calls it.
 * Name basis: derived - command 0x81 through ipc_send_command; the handler in the input program clears the
 *   bits of data byte 0 from bits 16..23 of slot 0 word 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013730c, flags -mcpu=v8 -O2 -g. ipc_send_command is declared without a prototype, as the firmware's own
 * calls need. The initializer compiles to a std (two words) plus a word store; the byte store through the
 * (unsigned char *) cast then overwrites the first byte with stb, as in the target.
 */
extern int ipc_send_command();

#define IPC_CMD_ACK_PORT_CHANGE  0x81   /* command number in the input program's dispatcher */
#define IPC_SEND_NO_WAIT         0      /* send and return at once */
#define ACK_DATA_BYTES           12     /* length of the data sent: three words, only byte 0 is not zero */

/*
 * Send command 0x81 (IPC_CMD_ACK_PORT_CHANGE) to the input processor. The input program clears the port change bits
 * named in data byte 0 from bits 16..23 of its state word. Nothing in the firmware calls this routine.
 *   bits: data byte 0, the port change bits to clear
 */
void ipc_clear_port_change_bits(unsigned char bits)
{
    unsigned int data[3] = {0, 0, 0};
    ((unsigned char *)data)[0] = bits;
    ipc_send_command(IPC_CMD_ACK_PORT_CHANGE, ACK_DATA_BYTES, data, IPC_SEND_NO_WAIT);
}
