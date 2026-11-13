/* pq_block8_set_mode  (FUN_a0118628)
 *
 * Set the mode fields of picture block 8 for a mode 1..4.
 * Name basis: descriptive - bit 0 of 0xCF012E44 and the low bits of 0xCF012E40
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0118628, flags -mcpu=v8 -O3 -g.
 * Source form: a switch with the default arm written first and separate (identical) bodies for cases 1 and 2;
 * this case order gives the firmware's register choice and block layout.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define BLOCK8_MODE         0xcf012e40      /* bits 0..1: the mode field */
#define BLOCK8_MODE_FLAGS   0xcf012e44      /* bit 0: mode 1 */
#define MODE_FLAG_MODE1     1
#define MODE_FIELD_KEEP     0xfc            /* the value is also cut to its low byte */

/*
 * Write the mode field of block 8 for a mode number:
 *
 *   mode    1 or 2 -> field 1, 3 -> field 2, 4 -> field 3, any other value -> field 0;
 *           bit 0 of BLOCK8_MODE_FLAGS is set for mode 1 only
 *
 * Callers: pq_apply_response_level and SYSAPI_ConfigSystemPIPMode, with 2 in picture mode 0
 * (device_settings_pip_mode) and 3 in every other picture mode. pq_load_block8_config writes the same field
 * from its stored mode.
 */
void pq_block8_set_mode(unsigned int mode)
{
    if (mode == 1)
        R(BLOCK8_MODE_FLAGS) |= MODE_FLAG_MODE1;
    else
        R(BLOCK8_MODE_FLAGS) &= ~MODE_FLAG_MODE1;

    switch (mode) {
    default:
        R(BLOCK8_MODE) = R(BLOCK8_MODE) & MODE_FIELD_KEEP;
        break;
    case 1:
        R(BLOCK8_MODE) = (R(BLOCK8_MODE) & MODE_FIELD_KEEP) | 1;
        break;
    case 2:
        R(BLOCK8_MODE) = (R(BLOCK8_MODE) & MODE_FIELD_KEEP) | 1;
        break;
    case 3:
        R(BLOCK8_MODE) = (R(BLOCK8_MODE) & MODE_FIELD_KEEP) | 2;
        break;
    case 4:
        R(BLOCK8_MODE) = (R(BLOCK8_MODE) & MODE_FIELD_KEEP) | 3;
        break;
    }
}
