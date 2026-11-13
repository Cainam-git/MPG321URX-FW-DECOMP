/* sys_is_on_crystal_clock  (FUN_CODE_df0b)
 *
 * Report whether the 8051 runs on its slow crystal clock.
 * Returns: 1 on the crystal clock
 * Name basis: derived - bit 0x0E set on power saving / power off, cleared at start-up; sys_get_cpu_clock_hz
 *   returns 12 MHz when set
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_df0b @ 0xdf0b (3 bytes), default OPTIMIZE(7,SPEED): MOV C,0EH; RET.
 */
extern bit sys_on_crystal_clock_flag;

/*
 * Return sys_on_crystal_clock_flag (bit 0x0E): 1 while the 8051 runs on the crystal clock.
 * power_setup_power_saving and power_off_sequence set the flag, power_leave_power_saving clears it.
 * Callers: sys_get_cpu_clock_hz (12 MHz when set) and hdmi_cec_receive_message, which answers a message with
 * opcode 0x8F by a reply of opcode 0x90 and this bit as its second byte.
 */
bit sys_is_on_crystal_clock(void)
{
    return sys_on_crystal_clock_flag;
}
