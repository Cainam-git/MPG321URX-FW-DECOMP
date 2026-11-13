/* dbg_send_ldc_command  (FUN_a00dd628)
 *
 * Send a command to the dimming processor and print it.
 * Name basis: proven - prints '[DBG] Tensilica Cmd: 0x%02X_%02X_%04X'; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd628 @ 0xa00dd628, flags -mcpu=v8 -O2 -g.
 * Source form: the three masked copies are separate locals; the print uses the unmasked parameters. The last
 * three parameters are declared but not used.
 */
extern int ldc_send_command(unsigned int, unsigned int, unsigned short);
extern int dbg_printf();

/*
 * Debug aid: send one command to the dimming processor with ldc_send_command and print it as
 * "[DBG] Tensilica Cmd: 0x<command>_<sub_code>_<value>" on the debug serial port.
 *
 *   command, sub_code  one byte each (the high bits are cut off for the command, the print shows all of them)
 *   value              16 bits
 *   unused_1..3        not used
 *
 * Nothing in the image calls this routine.
 */
void dbg_send_ldc_command(unsigned int command, unsigned int sub_code, int value,
                  unsigned int unused_1, unsigned int unused_2, unsigned int unused_3)
{
    unsigned short value_half = (unsigned short)(value & 0xffff);
    unsigned int command_byte = command & 0xff;
    unsigned int sub_code_byte = sub_code & 0xff;

    ldc_send_command(command_byte, sub_code_byte, value_half);
    dbg_printf("[DBG] Tensilica Cmd: 0x%02X_%02X_%04X\n", command, sub_code, value);
}
