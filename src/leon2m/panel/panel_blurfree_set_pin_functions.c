/* panel_blurfree_set_pin_functions  (FUN_a0150768)
 *
 * Set the pin function (10 or 0) of each pin whose bit is set in either blur-reduction channel mask.
 * Note: All three callers pass pin group 0xFF, for which gpio_set_pin_function does nothing, so no pin
 *   changes.
 * Name basis: derived - gpio_set_pin_function(group, bit, 10 or 0) for the bits of the two channel masks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150768 @ 0xa0150768-0xa0150a98 (204 words incl. the unreachable ret/restore pair
 * FUN_a0150a90), flags -mcpu=v8 -O3 -g.
 * Source form: two unrolled copies of the eight bit tests, one for enable == 1 and one for every other value (the
 * fall-through). The channel mask byte is not volatile and is read again before each test (the calls in between
 * may change it). The group parameter is an unsigned char; gpio_set_pin_function is declared (u8, u32, u32).
 */
extern unsigned char panel_blurfree_channel_mask;
extern unsigned char panel_blurfree_second_channel_mask;
extern void gpio_set_pin_function(unsigned char, unsigned int, unsigned int);

/*
 * For each bit 0..7 that is set in the channel mask or in the second channel mask of the blur reduction, set the
 * pin function (gpio_set_pin_function) of that pin bit in pin group "pin_group": function value 10 when
 * "enable" is 1, function value 0 otherwise. No return value.
 *
 * Callers: APPBlurFree_AfterMute and panel_blurfree_apply_user_mode, all with enable 1 and pin_group 0xFF. The
 * pin-function routine does nothing for a group number above 17, so these calls change no pin.
 */
void panel_blurfree_set_pin_functions(unsigned char enable, unsigned char pin_group)
{
    if (enable == 1) {
        if ((panel_blurfree_channel_mask & 0x1) || (panel_blurfree_second_channel_mask & 0x1))
            gpio_set_pin_function(pin_group, 0x1, 10);
        if ((panel_blurfree_channel_mask & 0x2) || (panel_blurfree_second_channel_mask & 0x2))
            gpio_set_pin_function(pin_group, 0x2, 10);
        if ((panel_blurfree_channel_mask & 0x4) || (panel_blurfree_second_channel_mask & 0x4))
            gpio_set_pin_function(pin_group, 0x4, 10);
        if ((panel_blurfree_channel_mask & 0x8) || (panel_blurfree_second_channel_mask & 0x8))
            gpio_set_pin_function(pin_group, 0x8, 10);
        if ((panel_blurfree_channel_mask & 0x10) || (panel_blurfree_second_channel_mask & 0x10))
            gpio_set_pin_function(pin_group, 0x10, 10);
        if ((panel_blurfree_channel_mask & 0x20) || (panel_blurfree_second_channel_mask & 0x20))
            gpio_set_pin_function(pin_group, 0x20, 10);
        if ((panel_blurfree_channel_mask & 0x40) || (panel_blurfree_second_channel_mask & 0x40))
            gpio_set_pin_function(pin_group, 0x40, 10);
        if ((panel_blurfree_channel_mask & 0x80) || (panel_blurfree_second_channel_mask & 0x80))
            gpio_set_pin_function(pin_group, 0x80, 10);
    } else {
        if ((panel_blurfree_channel_mask & 0x1) || (panel_blurfree_second_channel_mask & 0x1))
            gpio_set_pin_function(pin_group, 0x1, 0);
        if ((panel_blurfree_channel_mask & 0x2) || (panel_blurfree_second_channel_mask & 0x2))
            gpio_set_pin_function(pin_group, 0x2, 0);
        if ((panel_blurfree_channel_mask & 0x4) || (panel_blurfree_second_channel_mask & 0x4))
            gpio_set_pin_function(pin_group, 0x4, 0);
        if ((panel_blurfree_channel_mask & 0x8) || (panel_blurfree_second_channel_mask & 0x8))
            gpio_set_pin_function(pin_group, 0x8, 0);
        if ((panel_blurfree_channel_mask & 0x10) || (panel_blurfree_second_channel_mask & 0x10))
            gpio_set_pin_function(pin_group, 0x10, 0);
        if ((panel_blurfree_channel_mask & 0x20) || (panel_blurfree_second_channel_mask & 0x20))
            gpio_set_pin_function(pin_group, 0x20, 0);
        if ((panel_blurfree_channel_mask & 0x40) || (panel_blurfree_second_channel_mask & 0x40))
            gpio_set_pin_function(pin_group, 0x40, 0);
        if ((panel_blurfree_channel_mask & 0x80) || (panel_blurfree_second_channel_mask & 0x80))
            gpio_set_pin_function(pin_group, 0x80, 0);
    }
}
