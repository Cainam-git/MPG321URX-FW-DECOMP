/* power_core_sleep_sequence_alt  (FUN_a00de604)
 *
 * Write two core registers with short waits in between.
 * Name basis: descriptive - reg_write32, five idle instructions, second write, then a 1024-round wait; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de604 @ 0xa00de604-0xa00de65c, 88 bytes, flags -mcpu=v8 -O3 -g.
 * Source form: the nops are real instructions, written as __asm__ __volatile__("nop") (the same form as the
 * delay loops elsewhere); the wait is a for loop counting i from 0x3ff down to 0 with one nop per pass.
 */

#define CORE_REG_E0        0x9f0200e0   /* core registers written by this sequence */
#define CORE_REG_14        0x9f000014
#define CORE_WAIT_ROUNDS   0x400        /* passes of the final wait loop */

extern void reg_write32(unsigned int addr, unsigned int val);

/*
 * Write 0xC0 to core register 0x9F0200E0, wait five instructions, write 0x210003 to core register 0x9F000014
 * and wait 1024 passes of a loop. These are the same writes and waits as step 1 of startup_init_core.
 * Nothing in the image calls this routine; power_core_sleep_sequence is the variant that SYSAPI_PowerOff and
 * SYSAPI_PowerSaving use.
 */
void power_core_sleep_sequence_alt(void)
{
  int i;

  reg_write32(CORE_REG_E0, 0xc0);
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  __asm__ __volatile__("nop");
  reg_write32(CORE_REG_14, 0x210003);
  for (i = CORE_WAIT_ROUNDS - 1; i >= 0; i--)
    __asm__ __volatile__("nop");
}
