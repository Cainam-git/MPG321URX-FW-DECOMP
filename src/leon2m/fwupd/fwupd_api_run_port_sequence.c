/* fwupd_api_run_port_sequence  (FUN_a0147c5c)
 *
 * Run the register sequence of the update port and wait for it to finish.
 * Name basis: descriptive - forwards to the sequence on 0xCF03C780/0xCF03C66x; unused
 *
 * Matching notes
 * --------------
 * FUN_a0147c5c (leon2m 0xa0147c5c-0xa0147c6c, 16 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Tail call of fwupd_port_run_sequence ('mov %o7, %g1; call; mov %g1, %o7'); the nop after it is the -g line nop.
 * Nothing in the image refers to it. Source form: a void wrapper.
 */
extern void fwupd_port_run_sequence(void);

/*
 * Forward on to fwupd_port_run_sequence, which runs the start sequence of the update port and waits until
 * the port has answered command 0x31. Nothing in the image refers to this routine.
 */
void fwupd_api_run_port_sequence(void)
{
    fwupd_port_run_sequence();
}
