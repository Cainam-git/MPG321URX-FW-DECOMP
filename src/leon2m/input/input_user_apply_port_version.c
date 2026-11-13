/* input_user_apply_port_version  (FUN_a00d80b0)
 *
 * Apply the port version setting to both inputs of the pair.
 * Name basis: descriptive - input_api_set_port_version_field for sources 0x0C and 0x0D with settings byte
 *   +0x1D; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d80b0 @ 0xa00d80b0, flags -mcpu=v8 -O3 -g.
 * Source form: the settings are reached through a local pointer.
 */

/* The start of the user settings record; only the port version byte is used here. */
struct user_settings_record {
    unsigned char pad[0x1d];
    unsigned char port_version;                 /* +0x1D */
};
extern struct user_settings_record user_settings;
extern void input_api_set_port_version_field(unsigned char, unsigned char);

/*
 * Hand the port version setting (settings byte +0x1D) to input_api_set_port_version_field for the
 * inputs with port codes 0x0C and 0x0D. That routine stores it per port and writes the settings record.
 * No code calls this routine.
 */
void input_user_apply_port_version(void)
{
  struct user_settings_record *settings = &user_settings;

  input_api_set_port_version_field(0xc, settings->port_version);
  input_api_set_port_version_field(0xd, settings->port_version);
}
