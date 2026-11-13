/* input_api_select_ports  (FUN_a01439d8)
 *
 * Map the selected sources to ports and switch those ports on.
 * Name basis: derived - port selector map, then input_power_on_ports_by_mask; last start-up call before the
 *   third wait
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01439d8 @ 0xa01439d8..0xa0143bc4 (123 words), flags -mcpu=v8 -O3 -g. Called by startup_bring_up_system
 * (startup_bring_up_system) with (0, 1) just before its third wait.
 * Source form: an if/else-if chain on (selector & 0xf0), compared with 0x10, 0x20, 0x40 in this order. The
 * selectors 0 and 1 call input_power_on_ports_by_mask through a local function pointer: the fw makes those two
 * plain calls ('call; nop; b ret', shared by crossjumping) while every other call is a sibcall, and gcc 3.4 on
 * SPARC refuses a sibcall only when the call has no known function decl (sparc_function_ok_for_sibcall); cse
 * then turns the pointer into the direct call. 'default' first in the channel switch and case 0x27 before 0x26
 * fix the block order.
 */
/* A channel record, up to the first word: the port is in bits 12..15. */
struct channel_record { unsigned int status_word; unsigned char rest[0x74]; };
extern struct channel_record channel_records[];
extern void ipc_8051_wait_tx_queue(unsigned char, unsigned char);
extern unsigned char input_block_get_signal_code(unsigned char);
extern unsigned char sys_get_active_port_code(void);
extern void input_power_on_ports_by_mask(unsigned char, unsigned char);

/*
 * Turn on the input ports named by a selector. First waits until the queue to the 8051 is empty
 * (ipc_8051_wait_tx_queue(3, 0)), then calls input_power_on_ports_by_mask(mask, on) with the mask the
 * selector gives:
 *
 *   selector 0                 mask 0xff (all)
 *   selector 1 / 2             mask 0x0f / 0xf0
 *   selector 0x20..0x27        mask 1 << (selector - 0x20)
 *   selector 0x40..0x45        mask 1 << (selector - 0x40)
 *   selector 0x10..0x1f        the port of a channel: channel 1, 2 or 3 for selector 0x11, 0x12, 0x13, else
 *                              channel 0. The signal code of the channel's port (input_block_get_signal_code,
 *                              with 0xb1 replaced by sys_get_active_port_code()) gives the mask: 0x31 -> 1,
 *                              0x41 -> 2, 0x51 -> 4, 0x61 -> 8, 0x71 -> 0x10, 0x81 -> 0x20; any other code
 *                              switches nothing.
 *   any other selector         nothing.
 *
 *   selector  as above
 *   on        handed on unchanged to input_power_on_ports_by_mask
 *
 * No result. Callers: the start-up code (selector 0, on 1), UserSwitchEDID (selectors 0, 1, 2 after it has
 * loaded the EDIDs), the power-off routine APPSetPowerOff (selector 2, on 0) and the menu and PC-tool code for the PIP/PBP
 * modes and HDMI CEC (selectors 1 and 0x10, on 1).
 */
void input_api_select_ports(unsigned char selector, unsigned char on)
{
    unsigned char channel, signal_code;
    void (*power_on)(unsigned char, unsigned char);

    ipc_8051_wait_tx_queue(3, 0);
    if ((selector & 0xf0) == 0x10) {
        switch (selector) {
        default: channel = 0; break;
        case 0x11: channel = 1; break;
        case 0x12: channel = 2; break;
        case 0x13: channel = 3; break;
        }
        signal_code = input_block_get_signal_code((channel_records[channel].status_word >> 12) & 0xf);
        if (signal_code == 0xb1)
            signal_code = sys_get_active_port_code();
        switch (signal_code) {
        case 0x31: input_power_on_ports_by_mask(1, on); break;
        case 0x41: input_power_on_ports_by_mask(2, on); break;
        case 0x51: input_power_on_ports_by_mask(4, on); break;
        case 0x61: input_power_on_ports_by_mask(8, on); break;
        case 0x71: input_power_on_ports_by_mask(0x10, on); break;
        case 0x81: input_power_on_ports_by_mask(0x20, on); break;
        }
    } else if ((selector & 0xf0) == 0x20) {
        switch (selector) {
        case 0x20: input_power_on_ports_by_mask(1, on); break;
        case 0x21: input_power_on_ports_by_mask(2, on); break;
        case 0x22: input_power_on_ports_by_mask(4, on); break;
        case 0x23: input_power_on_ports_by_mask(8, on); break;
        case 0x24: input_power_on_ports_by_mask(0x10, on); break;
        case 0x25: input_power_on_ports_by_mask(0x20, on); break;
        case 0x27: input_power_on_ports_by_mask(0x80, on); break;
        case 0x26: input_power_on_ports_by_mask(0x40, on); break;
        }
    } else if ((selector & 0xf0) == 0x40) {
        switch (selector) {
        case 0x40: input_power_on_ports_by_mask(1, on); break;
        case 0x41: input_power_on_ports_by_mask(2, on); break;
        case 0x42: input_power_on_ports_by_mask(4, on); break;
        case 0x43: input_power_on_ports_by_mask(8, on); break;
        case 0x44: input_power_on_ports_by_mask(0x10, on); break;
        case 0x45: input_power_on_ports_by_mask(0x20, on); break;
        }
    } else if (selector == 0) {
        power_on = input_power_on_ports_by_mask;
        power_on(0xff, on);
    } else if (selector == 1) {
        power_on = input_power_on_ports_by_mask;
        power_on(0x0f, on);
    } else if (selector == 2) {
        input_power_on_ports_by_mask(0xf0, on);
    }
}
