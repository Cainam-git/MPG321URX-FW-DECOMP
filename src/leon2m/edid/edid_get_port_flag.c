/* edid_get_port_flag  (FUN_a012536c)
 *
 * Return the per-port flag that accompanies the internal EDID.
 * Returns: 0 or 1
 * Name basis: descriptive - bit per port in the byte at 0xA802C9FA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012536c @ 0xa012536c, flags -mcpu=v8 -O2 -g.
 * Source form: the shift count is used unmasked (no `& 0x1f`), since the firmware has no `and` before the shift.
 */
extern unsigned char edid_port_flags;

/*
 * Return bit `bus_id` of edid_port_flags (0 or 1): the flag that edid_set_port_flag stores for the input with
 * this bus id.
 * Called by edid_read_port_edid, edid_write_port_edid and startup_load_port_edids.
 */
int edid_get_port_flag(int bus_id)
{
    return (edid_port_flags >> bus_id) & 1;
}
