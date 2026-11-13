/* fwupd_port_run_sequence  (FUN_a0123744)
 *
 * Run the start sequence of the update port and wait for it to finish.
 * Name basis: descriptive - registers 0xCF03C780/0xCF03C66x; waits while the command register reads 0x31
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123744 @ 0xa0123744-0xa0123840 (63 words), flags -mcpu=v8 -O3 -g. All accesses are
 * volatile hardware registers.
 * Source form: the registers are written through macros; the port register loop counts an unsigned char.
 */
#define REG(a) (*(volatile unsigned int *)(a))
/* Port register n of the update port window (n = 0xF190..0xF19F; address 0xCF000000 | n << 2). */
#define PORT_REG(n) REG(0xcf000000 | ((n) << 2))

#define UPDATE_CONTROL_REG   0xcf03c780         /* bit 0 and bit 1 are set and cleared around the clear loop */
#define UPDATE_PORT_FIRST    0xf190
#define UPDATE_PORT_COUNT    16
#define UPDATE_CMD_0X31      0x31
#define REGION_ADDRESS_ID    0x13               /* argument of sys_get_region_address */

extern unsigned int sys_get_region_address(unsigned int);

/*
 * Run the start sequence of the update port. Steps:
 *  1. write 0x80 to register 0xCF011F80;
 *  2. in 0xCF03C780 set bit 0 and clear bit 1;
 *  3. clear the 16 port registers 0xF190..0xF19F;
 *  4. in 0xCF03C780 clear bit 0 and set bit 1;
 *  5. send command 0x31 as fwupd_port_send_cmd_0x31 does, with the value sys_get_region_address(0x13), then wait
 *     with no time limit until the command register 0xCF03C660 no longer reads 0x31.
 * Caller: fwupd_api_run_port_sequence.
 */
void fwupd_port_run_sequence(void)
{
    unsigned char i;
    unsigned int value;

    REG(0xcf011f80) = 0x80;
    REG(UPDATE_CONTROL_REG) |= 1;
    REG(UPDATE_CONTROL_REG) &= ~2;
    for (i = 0; i < UPDATE_PORT_COUNT; i++)
        PORT_REG(UPDATE_PORT_FIRST + i) = 0;
    REG(UPDATE_CONTROL_REG) &= ~1;
    REG(UPDATE_CONTROL_REG) |= 2;
    value = sys_get_region_address(REGION_ADDRESS_ID);
    REG(0xcf03c670) = value >> 24;
    REG(0xcf03c674) = (value >> 16) & 0xff;
    REG(0xcf03c678) = (value >> 8) & 0xff;
    REG(0xcf03c67c) = value & 0xff;
    REG(0xcf03c664) = 0xff;
    REG(0xcf03c660) = UPDATE_CMD_0X31;
    while (REG(0xcf03c660) == UPDATE_CMD_0X31)
        ;
}
