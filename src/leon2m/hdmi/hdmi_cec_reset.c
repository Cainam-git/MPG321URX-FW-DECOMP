/* hdmi_cec_reset  (FUN_a00fc2fc)
 *
 * Clear the CEC control register.
 * Name basis: derived - 0 to 0xCF012000
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc2fc @ 0xa00fc2fc, flags -mcpu=v8 -O2 -g (the section default).
 */
#define CEC_REG_00 (*(volatile unsigned int *)0xcf012000)   /* the register hdmi_cec_init sets to 1 */

/* Write 0 to CEC_REG_00. Called only by hdmi_cec_api_reset. */
void hdmi_cec_reset(void)
{
  CEC_REG_00 = 0;
}
