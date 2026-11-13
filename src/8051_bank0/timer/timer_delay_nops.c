/* timer_delay_nops  (FUN_CODE_1873)
 *
 * Wait in a loop of n times eight idle instructions.
 * Name basis: proven - busy-wait used between flash command steps
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED).
 * Source form: eight _nop_() calls in the loop body; the exact build depends on their number.
 */
#include <intrins.h>

/* timer_delay_nops
 *
 * Busy-waits: rounds times eight NOP instructions, nothing else.
 *   rounds: number of rounds (0 = no wait)
 * The flash command routines flash_write_command_byte, flash_read_command_byte and flash_send_command call it with
 * 10 between two tests of the controller's busy bit.
 */
void timer_delay_nops(unsigned char rounds)
{
    unsigned char i;
    for (i = 0; i < rounds; i++) {
        _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    }
}
