/* sys_user_apply_config_field  (FUN_a00d5e0c)
 *
 * Apply a 4-bit settings field and restart all channels.
 * Name basis: descriptive - sys_api_set_config_field_restart_all; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d5e0c @ 0xa00d5e0c-0xa00d5e84 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: the 4-bit value is a bit-field (it promotes to int, so the switch compares are signed); the
 * call to sys_api_set_config_field_restart_all is a tail call.
 */
extern void sys_api_set_config_field_restart_all(unsigned char value);
/* The word user_settings_image_enhancement (the four bits at 12..15 are the field used here). */
struct image_enhancement_word {
    unsigned int upper_bits : 16;
    unsigned int field : 4;                 /* bits 12..15 */
    unsigned int lower_bits : 12;
};
extern struct image_enhancement_word user_settings_image_enhancement;

/*
 * Take bits 12..15 of the word user_settings_image_enhancement; the values 1, 2 and 3 are kept, any other
 * value becomes 0. The result goes to sys_api_set_config_field_restart_all, which stores it in bits 28..31
 * of the first system configuration word and restarts channels 0 to 3. Nothing calls this routine.
 */
void sys_user_apply_config_field(void)
{
    unsigned char value;

    switch (user_settings_image_enhancement.field) {
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    default: value = 0; break;
    }
    sys_api_set_config_field_restart_all(value & 3);
}
