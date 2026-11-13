/* osd_user_apply_menu_option  (FUN_a00d47c8)
 *
 * Apply settings byte +6 as a 2-bit option, with the menu layers switched off meanwhile.
 * Name basis: descriptive - osd_api_enable(0) / (1) around pq_api_set_two_bit_option; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d47c8 @ 0xa00d47c8-0xa00d4888 (48 words), flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the default arm written first; m starts at 2 and case 2 leaves it unchanged.
 */
#define OPTION_MAX 4                            /* settings byte +6 is limited to this */

struct user_settings_record {
    unsigned char pad0[6];
    unsigned char option_byte;                  /* +6: limited to 4 here, then mapped to a 2-bit option */
};
extern struct user_settings_record user_settings;
extern void osd_api_enable(int, int);
extern void pq_api_set_two_bit_option(unsigned char);

/*
 * Limit settings byte +6 to 4, store it back and apply it as a 2-bit option: 1, 2 and 3 give option 1, 2 and 3,
 * every other value gives 0. Menu layer 0 is switched off, then the option is applied with
 * pq_api_set_two_bit_option, then menu layer 1 is switched off.
 */
void osd_user_apply_menu_option(void)
{
    unsigned char value = user_settings.option_byte;
    unsigned char option = 2;

    if (value > OPTION_MAX)
        value = OPTION_MAX;
    user_settings.option_byte = value;
    switch (value) {
    default:
        option = 0;
        break;
    case 1:
        option = 1;
        break;
    case 2:
        break;
    case 3:
        option = 3;
        break;
    }
    osd_api_enable(0, 0);
    pq_api_set_two_bit_option(option & 3);
    osd_api_enable(1, 0);
}
