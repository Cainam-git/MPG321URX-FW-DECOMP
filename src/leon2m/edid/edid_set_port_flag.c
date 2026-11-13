/* edid_set_port_flag  (FUN_a01254b8)
 *
 * Set or clear the per-port flag that accompanies the internal EDID.
 * Name basis: descriptive - bit per port in the byte at 0xA802C9FA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01254b8 @ 0xa01254b8, flags -mcpu=v8 -O3 -g.
 * Source form: each arm writes its own `1 << bus_id` expression; GCC hoists the shift above the test and keeps
 * two copies of it. A mask variable shared by both arms gives one copy and other registers.
 */
extern unsigned char edid_port_flags;

/*
 * Set (on != 0) or clear (on == 0) bit `bus_id` of edid_port_flags, the per-input flag that edid_get_port_flag
 * reads back.
 * Called by edid_api_set_port_flag.
 */
void edid_set_port_flag(unsigned char bus_id, unsigned char on)
{
    if (on)
        edid_port_flags |= 1 << bus_id;
    else
        edid_port_flags &= ~(1 << bus_id);
}
