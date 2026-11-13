/* input_enable_four_port_items  (FUN_a0083adc)
 *
 * Enable the port items 5, 6, 12 and 13 through the port item setter.
 * Note: No direct caller; setter is edid_api_enable_internal_edid.
 * Name basis: descriptive - code only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0083adc @ 0xa0083adc, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the six parameters are kept although only the first two calls ignore them; the fourth call passes
 * parameters 3 to 6 on to the setter (declared without a parameter list), as the firmware does.
 */

extern void edid_api_enable_internal_edid();

/*
 * Switch on the internal EDID of the inputs with port codes 5, 6, 12 and 13.
 * Nothing calls this routine. Its parameters 3 to 6 are handed on to the last call.
 */
void input_enable_four_port_items(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4,
                 unsigned int param_5, unsigned int param_6)

{
  edid_api_enable_internal_edid(5,1);
  edid_api_enable_internal_edid(6,1);
  edid_api_enable_internal_edid(0xc,1);
  edid_api_enable_internal_edid(0xd,1,param_3,param_4,param_5,param_6);
  return;
}