/* sys_frc_set_lock_mode  (FUN_a01085f8)
 *
 * Set the lock mode bits of a converter channel.
 * Name basis: derived - mode 1 or 2 sets the channel bit in 0xCF011A84; the rate flag picks the 0xCF011A8C bit
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01085f8 @ 0xa01085f8, flags -mcpu=v8 -O3 -g.
 * Source form: channel is an int (no 'and 0xff'), mode and rate_ok are unsigned chars. A switch with the default
 * arm first ('default: clear; case 1; case 2'): the case dispatch makes the mode-2 test block the fall-through of
 * the mode-1 test, which drops that block's repeated address set-up and gives the firmware's register
 * allocation (an if/else chain reaches only one of the two conditions). volatile only on the three registers.
 */
#define FRC_LOCK_A (*(volatile unsigned int *)0xcf011a84)
#define FRC_LOCK_B (*(volatile unsigned int *)0xcf011a88)
#define FRC_LOCK_C (*(volatile unsigned int *)0xcf011a8c)

/*
 * Set the lock mode of channel `channel` in the registers 0xCF011A84 (A), 0xCF011A88 (B) and 0xCF011A8C (C);
 * bit `channel` of each register belongs to the channel.
 *
 *   mode 1     A set, B clear
 *   mode 2     A set, B set
 *   other      A, B and C clear (the channel is taken out of all three)
 *
 * In modes 1 and 2 bit C is set when `rate_ok` is non-zero and cleared otherwise.
 *
 * Called by input_channel_bring_up_task (with the port of a channel, mode 0, 1 or 2 and a rate flag) and by
 * System_Initialize (mode 0 for channels 0 to 3).
 */
void sys_frc_set_lock_mode(int channel, unsigned char mode, unsigned char rate_ok)
{
    switch (mode) {
    default:
        FRC_LOCK_A &= ~(1 << channel);
        FRC_LOCK_B &= ~(1 << channel);
        FRC_LOCK_C &= ~(1 << channel);
        break;
    case 1:
        FRC_LOCK_A |= 1 << channel;
        FRC_LOCK_B &= ~(1 << channel);
        if (rate_ok)
            FRC_LOCK_C |= 1 << channel;
        else
            FRC_LOCK_C &= ~(1 << channel);
        break;
    case 2:
        FRC_LOCK_A |= 1 << channel;
        FRC_LOCK_B |= 1 << channel;
        if (rate_ok)
            FRC_LOCK_C |= 1 << channel;
        else
            FRC_LOCK_C &= ~(1 << channel);
        break;
    }
}
