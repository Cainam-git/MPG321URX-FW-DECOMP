/* sys_call_frc_callbacks  (FUN_a013d0ec)
 *
 * Call the two registered callbacks for case 0, or clear the two FRC mode bits.
 * Name basis: descriptive - callback table at 0xA802CC1C; bits 26/27 of stSysConfig; unused
 *
 * Matching notes
 * --------------
 * FUN_a013d0ec (leon2m 0xa013d0ec-0xa013d178, 140 bytes), flags -mcpu=v8 -O3 -g.
 */
#define SYS_CONFIG_BIT26 0x4000000u
#define SYS_CONFIG_BIT27 0x8000000u

/* Callback table: two function pointers at +0x24 and +0x28 (the rest is not used here). */
struct callback_table { unsigned char p0[0x24]; void (*callback_0x24)(void); void (*callback_0x28)(void); };
extern struct callback_table sys_callback_table;
extern unsigned int sys_config;

/* Only for mode 0: call the callback at +0x28, then the one at +0x24. A slot that holds no callback
 * instead clears its bit in sys_config (+0x28: bit 26, +0x24: bit 27). Any other mode does nothing. */
void sys_call_frc_callbacks(unsigned char mode)
{
    if (mode == 0) {
        if (sys_callback_table.callback_0x28)
            sys_callback_table.callback_0x28();
        else
            sys_config &= ~SYS_CONFIG_BIT26;
        if (sys_callback_table.callback_0x24)
            sys_callback_table.callback_0x24();
        else
            sys_config &= ~SYS_CONFIG_BIT27;
    }
}
