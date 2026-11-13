/* timer_delay_nop_rounds  (FUN_a002d23c)
 *
 * Busy-wait n rounds of 200 nop instructions.
 *   rounds
 * Note: Needs no timer or interrupt; used as the software I2C bit delay.
 * Name basis: proven - code: nop loop; header
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002d23c @ 0xa002d23c..0xa002d588 (211 words), flags -mcpu=v8 -O2 -g (section default).
 * Source form: the 200 nops are the routine's own instructions in the firmware, written as 200 separate asm
 * statements (NOP_10 expands to ten of them); the round counter is an unsigned short.
 */

/* Ten nop instructions, one asm statement each. */
#define NOP_10 \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop"); \
        __asm__ __volatile__("nop")

/*
 * Wait by running rounds of 200 nop instructions; n = 0 returns at once.
 *
 *   rounds  number of rounds, 0..0xFFFF
 *
 * Unlike timer_sleep_ticks, the wait uses no timer, no hardware register and no interrupt. It always ends
 * after the given number of rounds.
 *
 * Callers: the software I2C routines (i2c_gpio_start, i2c_gpio_send_byte, i2c_gpio_read_byte, the block read
 * and write routines and i2c_gpio_probe_device), which pass the delay of their bus descriptor or twice it, and
 * ipc_send_command_nop_wait, which passes 1.
 */
void timer_delay_nop_rounds(unsigned short rounds)
{
    unsigned short i;

    for (i = 0; i < rounds; i++) {
        /* One round: 200 nops. */
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
        NOP_10;
    }
}
