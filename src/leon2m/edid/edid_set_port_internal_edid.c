/* edid_set_port_internal_edid  (FUN_a012cd68)
 *
 * Switch the internal EDID of one port on or off as its stored flag says.
 * Name basis: derived - ipc_8051_enable_internal_edid or ipc_8051_disable_internal_edid for the port
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012cd68 @ 0xa012cd68-0xa012ce18 (44 words).
 * edid_is_internal_edid_enabled returns 0 or 1; it is declared here with an unsigned char result (the code tests the low byte).
 */
#define EDID_CHOICE_OFFSET 0x1b                 /* device_settings[0x1b + port]: the stored EDID choice of the port */
#define EDID_VARIANT_NONE  0xff                 /* no stored choice: the size comes from edid_port_size_codes */
#define SIZE_CODE_SHIFT    7                    /* 128-byte units */

extern unsigned int edid_port_size_codes;
extern unsigned char device_settings[];
extern const unsigned short edid_variant_lengths[];
extern unsigned char edid_is_internal_edid_enabled(unsigned char);
extern unsigned short edid_get_port_memory_base(unsigned char);
extern void ipc_8051_disable_internal_edid(unsigned char);
extern void ipc_8051_enable_internal_edid(unsigned char, unsigned short, unsigned char);

/*
 * Apply the internal EDID of one port, but only when its bit in the "internal EDID switched on" bits is set
 * (edid_is_internal_edid_enabled). With on = 0 the 8051 is told to switch the port's internal EDID off. Otherwise
 * it is told to switch it on with its length in bytes and its memory base in 128-byte units. The length is
 * edid_variant_lengths[stored choice] or, when the stored choice is 0xff, the port's size code times 128.
 * Called by sys_service_ports_by_mask and input_power_on_ports_by_mask. startup_load_port_edids does the same per-port step in a loop.
 */
void edid_set_port_internal_edid(unsigned char port, unsigned char on)
{
    unsigned short memory_base, length;

    if (edid_is_internal_edid_enabled(port)) {
        if (on) {
            memory_base = edid_get_port_memory_base(port);
            if (device_settings[EDID_CHOICE_OFFSET + port] == EDID_VARIANT_NONE)
                length = ((edid_port_size_codes >> (port * 4)) & 0xf) << SIZE_CODE_SHIFT;
            else
                length = edid_variant_lengths[device_settings[EDID_CHOICE_OFFSET + port]];
            ipc_8051_enable_internal_edid(1 << port, length, memory_base >> SIZE_CODE_SHIFT);
        } else
            ipc_8051_disable_internal_edid(1 << port);
    }
}
