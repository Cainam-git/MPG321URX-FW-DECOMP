/* fwupd_port_send_cmd_0x70  (FUN_a01236e8)
 *
 * Write the mode to the update port, start command 0x70, then write 7 or 0xF to two registers.
 * Note: Mode 0 writes 7, any other mode 0xF, to 0xCF01C100 and 0xCF01C500; what these two registers are is not
 *   shown.
 * Name basis: descriptive - registers 0xCF03C668 / 0xCF03C660 (waits until the command byte changes), then
 *   0xCF01C100 and 0xCF01C500
 *
 * Matching notes
 * --------------
 * FUN_a01236e8 (leon2m 0xa01236e8-0xa0123744, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: both register writes are repeated in each arm of the if/else.
 */
#define UPDATE_PARAM_668 (*(volatile unsigned int *)0xcf03c668)
#define UPDATE_COMMAND   (*(volatile unsigned int *)0xcf03c660)
#define OUTPUT_REG_C100  (*(volatile unsigned int *)0xcf01c100)
#define OUTPUT_REG_C500  (*(volatile unsigned int *)0xcf01c500)

#define UPDATE_CMD_0X70 0x70            /* docs/MAP.md: "host or device mode" */

/*
 * Send command 0x70 to the update port, wait for it, and then write to the registers 0xCF01C100 and 0xCF01C500.
 *   mode: stored in register 0xCF03C668 as the parameter of the command. With mode 0, 7 is written to both
 *         registers after the command; with any other value, 0xF.
 * The routine waits, with no time limit, until the command register no longer reads 0x70.
 * Callers: fwupd_enter_update, fwupd_api_send_port_command.
 */
void fwupd_port_send_cmd_0x70(unsigned char mode)
{
    UPDATE_PARAM_668 = mode;
    UPDATE_COMMAND = UPDATE_CMD_0X70;
    while (UPDATE_COMMAND == UPDATE_CMD_0X70)
        ;
    if (mode == 0) {
        OUTPUT_REG_C100 = 7;
        OUTPUT_REG_C500 = 7;
    } else {
        OUTPUT_REG_C100 = 0xf;
        OUTPUT_REG_C500 = 0xf;
    }
}
