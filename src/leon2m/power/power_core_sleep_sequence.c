/* power_core_sleep_sequence  (FUN_a00de65c)
 *
 * Write the two core registers that precede power saving or power off.
 * Name basis: derived - 0x9F0200E0 = 0x60 and 0x9F000014 = 0 with short waits; called from SYSAPI_PowerOff and
 *   SYSAPI_PowerSaving
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de65c @ 0xa00de65c-0xa00de6a8 (19 words), flags -mcpu=v8 -O3 -g.
 * Source form: the nops are inline asm (they are real instructions in the firmware); the wait is
 * 'i = 0x3ff; do { nop } while (--i >= 0)'.
 */

#define CORE_REG_E0        0x9f0200e0   /* core registers written by this sequence */
#define CORE_REG_14        0x9f000014
#define CORE_WAIT_ROUNDS   0x400        /* passes of the final wait loop */

extern void reg_write32(unsigned int addr, unsigned int value);

/*
 * Write 0x60 to core register 0x9F0200E0, wait three instructions, write 0 to core register 0x9F000014 and
 * wait 1024 passes of a loop.
 * Called from SYSAPI_PowerOff and SYSAPI_PowerSaving.
 */
void power_core_sleep_sequence(void)
{
    int i;

    reg_write32(CORE_REG_E0, 0x60);
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    reg_write32(CORE_REG_14, 0);
    i = CORE_WAIT_ROUNDS - 1;
    do {
        __asm__ __volatile__("nop");
    } while (--i >= 0);
}
