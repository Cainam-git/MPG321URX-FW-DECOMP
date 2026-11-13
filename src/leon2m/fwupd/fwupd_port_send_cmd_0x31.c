/* fwupd_port_send_cmd_0x31  (FUN_a012367c)
 *
 * Write a 32-bit value to the update port and start command 0x31.
 * Name basis: descriptive - registers 0xCF03C670..0xCF03C67C, command register 0xCF03C660; unused
 *
 * Matching notes
 * --------------
 * FUN_a012367c (leon2m 0xa012367c-0xa01236e8, 108 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: each of the four bytes goes to its own volatile word register; the wait loop has an empty body.
 */
/* Registers of the update port (word registers 0xCF03C660.. = XDATA 0xF198..). */
#define UPDATE_COMMAND  (*(volatile unsigned int *)0xcf03c660)
#define UPDATE_PARAM_664 (*(volatile unsigned int *)0xcf03c664)
#define UPDATE_VALUE_0  (*(volatile unsigned int *)0xcf03c670)
#define UPDATE_VALUE_1  (*(volatile unsigned int *)0xcf03c674)
#define UPDATE_VALUE_2  (*(volatile unsigned int *)0xcf03c678)
#define UPDATE_VALUE_3  (*(volatile unsigned int *)0xcf03c67c)

#define UPDATE_CMD_0X31 0x31

/*
 * Pass a 32-bit value to the update port and start command 0x31.
 *   value: stored as four bytes, most significant first, in the registers 0xCF03C670, 674, 678 and 67C.
 * Then 0xFF goes to register 0xCF03C664 and the command to 0xCF03C660; the routine waits, with no time limit,
 * until that register no longer reads the command. Nothing calls this routine; fwupd_port_run_sequence contains
 * the same steps.
 */
void fwupd_port_send_cmd_0x31(unsigned int value)
{
    UPDATE_VALUE_0 = value >> 24;
    UPDATE_VALUE_1 = (value >> 16) & 0xff;
    UPDATE_VALUE_2 = (value >> 8) & 0xff;
    UPDATE_VALUE_3 = value & 0xff;
    UPDATE_PARAM_664 = 0xff;
    UPDATE_COMMAND = UPDATE_CMD_0X31;
    while (UPDATE_COMMAND == UPDATE_CMD_0X31)
        ;
}
