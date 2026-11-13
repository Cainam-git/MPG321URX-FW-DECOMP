/* IsAnyACRAvailable  (FUN_a014eb14)
 *
 * Return the first free ACR unit (1 or 3), or 4 when both are taken.
 * Returns: unit index or 4
 * Name basis: proven - prints 'IsAnyACRAvailable %d' (original name from the text); unused copy
 *
 * Matching notes
 * --------------
 * FUN_a014eb14 (leon2m 0xa014eb14), flags -mcpu=v8 -O3 (no -g: the firmware has no nop after the final call).
 * Source form: the two unit numbers sit in a local table; a for loop breaks at the first free one.
 */
extern unsigned short audio_unit_owners;
extern int dbg_printf();

#define UNIT_FIELD_BITS 4       /* audio_unit_owners holds one 4-bit field per audio unit */
#define NO_UNIT_FREE    4      /* result when both units are taken */

/*
 * Return the first of the audio units 1 and 3 whose owner field in audio_unit_owners is 0, or 4 when neither is
 * free. Prints the result ("IsAnyACRAvailable %d", between two terminal colour escape sequences).
 *
 * No direct caller was found.
 */
unsigned char IsAnyACRAvailable(void)
{
    unsigned char units[2] = {1, 3};
    unsigned char i, result = NO_UNIT_FREE;

    for (i = 0; i < 2; i++)
        if (((audio_unit_owners >> (units[i] * UNIT_FIELD_BITS)) & 0xf) == 0)
            break;
    if (i < 2)
        result = units[i];
    dbg_printf("\033[0;33mIsAnyACRAvailable %d\r\n\033[m", result);
    return result;
}
