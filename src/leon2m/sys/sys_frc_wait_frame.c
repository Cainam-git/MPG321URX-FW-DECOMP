/* sys_frc_wait_frame  (FUN_a010ac68)
 *
 * Wait for one frame pulse of the converter, with time limits.
 * Name basis: descriptive - bit 0 of 0xCF011FF4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010ac68 @ 0xa010ac68-0xa010ace4 (31 words), flags -mcpu=v8 -O3 -g.
 * Source form: each loop is a counter test with a break on the bit test; a combined && condition gives other
 * registers.
 */
#define REG_cf011ff4 (*(volatile unsigned int *)0xcf011ff4)

extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);

#define WAIT_CLEAR_TICKS 0x32   /* limit, in timer ticks, of the wait for the bit to clear */
#define WAIT_SET_TICKS   0x64   /* limit of both waits together, counted from the start */

/*
 * Wait for bit 0 of register 0xCF011FF4 to go clear and then set again (one pulse). Each wait is cut off by a
 * time limit; both limits count from the first reading of the timer. Same as sys_frc_wait_channel_frame, which
 * tests bit channel + 4 instead of bit 0. No return value: a timeout is not reported.
 */
void sys_frc_wait_frame(void)
{
    unsigned short start = timer_get_ticks16();

    while (timer_ticks_since(start) < WAIT_CLEAR_TICKS) {
        if (!(REG_cf011ff4 & 1))
            break;
    }
    while (timer_ticks_since(start) < WAIT_SET_TICKS) {
        if (REG_cf011ff4 & 1)
            break;
    }
}
