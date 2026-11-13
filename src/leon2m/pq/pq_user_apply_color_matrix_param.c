/* pq_user_apply_color_matrix_param  (FUN_a00d4660)
 *
 * Limit settings byte +0x0B to 100 and apply it to the colour matrix.
 * Name basis: descriptive - pq_api_set_color_matrix_param; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d4660 @ 0xa00d4660-0xa00d4690 (12 words), flags -mcpu=v8 -O2 -g (section default).
 * Source form: the limited value is held in an unsigned short (keeps the and 0xff before the tail call).
 */

#define COLOR_MATRIX_PARAM_MAX 100

/* The one field of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0xb];
    unsigned char byte_0x0b;                    /* +0x0B */
};
extern struct user_settings_record user_settings;
extern void pq_api_set_color_matrix_param(unsigned char);

/*
 * Limit user settings byte +0x0B to 100, store the limited value back and hand it to
 * pq_api_set_color_matrix_param, which keeps it as the colour parameter of sys_config and rebuilds the
 * colour matrix with it. No caller of this routine is found in the firmware.
 */
void pq_user_apply_color_matrix_param(void)
{
    unsigned short value = user_settings.byte_0x0b;

    if (value > COLOR_MATRIX_PARAM_MAX)
        value = COLOR_MATRIX_PARAM_MAX;
    user_settings.byte_0x0b = value;
    pq_api_set_color_matrix_param(value);
}
