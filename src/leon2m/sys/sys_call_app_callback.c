/* sys_call_app_callback  (FUN_a002f984)
 *
 * Call application callback k (0, 1 or 5) from table 0xA802CC1C when set.
 *   k: callback number
 * Note: Prints 'App Callback --> %d' for k other than 1 when debug mask bit 0x10 is on.
 * Name basis: proven - text 'App Callback --> %d'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002f984 @ 0xa002f984-0xa002fa34 (44 words).
 * Calls one of the function pointers at 0xa802cc1c (k 0), 0xa802cc20 (k 1) or 0xa802cc30 (k 5) when it is not null.
 * For k other than 1, "App Callback --> %d" is printed with k first when func_0x0007d614(0x10) returns nonzero.
 * Other k do nothing more.
 */
extern void (*sys_callback_table[15])(void);
extern unsigned char dbg_is_print_enabled(unsigned char);
extern int dbg_printf();

#define DEBUG_PRINT_MASK_APP_CALLBACK 0x10      /* debug mask bit tested before the text is printed */

/*
 * Call the application callback with the number k, when one is registered in sys_callback_table.
 *
 *   k   callback number; only 0, 1 and 5 call anything, other numbers do nothing
 *
 * For every number except 1 the text 'App Callback --> k' is printed first when the debug mask bit 0x10 is on
 * (the check is done before k is looked at, so it also happens for numbers that call nothing).
 */
void sys_call_app_callback(unsigned char k)
{
    if (k != 1 && dbg_is_print_enabled(DEBUG_PRINT_MASK_APP_CALLBACK))
        dbg_printf("App Callback --> %d\r\n", k);
    switch (k) {
    case 0:
        if (sys_callback_table[0])
            sys_callback_table[0]();
        break;
    case 1:
        if (sys_callback_table[1])
            sys_callback_table[1]();
        break;
    case 5:
        if (sys_callback_table[5])
            sys_callback_table[5]();
        break;
    }
}
