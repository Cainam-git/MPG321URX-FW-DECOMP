/* edid_is_internal_edid_enabled  (FUN_a0125350)
 *
 * Return whether the internal EDID of a port is switched on.
 * Returns: 0 or 1
 * Name basis: derived - bit per port in the byte at 0xA802C9FB, set by edid_enable_internal_edid
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125350 @ 0xa0125350, flags -mcpu=v8 -O2 -g.
 * Source form: the shift count is used unmasked (`sra` by the parameter), so the source shifts by the parameter
 * directly. Parameter and result are unsigned char: the callers test the low byte of the result.
 */
extern unsigned char edid_internal_enabled_bits;

/*
 * Return 1 when the internal EDID of the input with this bus id is switched on, else 0. The bits are set and
 * cleared by edid_enable_internal_edid.
 * Called by edid_set_port_internal_edid and input_api_set_port_signal.
 */
unsigned char edid_is_internal_edid_enabled(unsigned char bus_id)
{
    return (edid_internal_enabled_bits >> bus_id) & 1;
}
