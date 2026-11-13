/* fwupd_api_send_port_command  (FUN_a0147c6c)
 *
 * Send a command to the update port and switch the two output blocks.
 * Name basis: descriptive - forwards to the write of 0xCF03C668/0xCF03C660; unused
 *
 * Matching notes
 * --------------
 * FUN_a0147c6c (leon2m 0xa0147c6c-0xa0147c80, 20 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Tail call of fwupd_port_send_cmd_0x70; the nop after it is the -g line nop. Nothing in the image refers to it.
 */
extern void fwupd_port_send_cmd_0x70(unsigned char);

/*
 * Forward on to fwupd_port_send_cmd_0x70, which sends command 0x70 (host or device mode, see docs/MAP.md) to
 * the update port.
 *   mode  passed on unchanged; the port code stores it as the parameter of the command and treats 0 differently
 *         from every other value
 * Nothing in the image refers to this routine.
 */
void fwupd_api_send_port_command(unsigned char mode)
{
    fwupd_port_send_cmd_0x70(mode);
}
