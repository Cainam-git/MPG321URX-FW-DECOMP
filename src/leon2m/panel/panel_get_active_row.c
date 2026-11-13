/* panel_get_active_row  (FUN_a01241fc)
 *
 * Return the address of the active panel timing row.
 * Returns: address of the 0x58-byte row at 0xA802E378
 * Name basis: derived - returns the address 0xA802E378 (panel_active_row)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01241fc @ 0xa01241fc (-mcpu=v8 -O2 -g)
 * Source form: returns the address of the data label as an unsigned char pointer; the label is declared as an
 * unsigned int.
 */
extern unsigned int panel_active_row;

/*
 * Return the address of the active panel timing row (0xA802E378). The row is 0x58 bytes long;
 * panel_api_set_active_row copies a new row into it.
 */
unsigned char *panel_get_active_row(void)
{
    return (unsigned char *)&panel_active_row;
}
