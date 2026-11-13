/* oled_frc_apply_default_row  (FUN_a0129810)
 *
 * Make ROM row 1 the active panel timing row when the converter runs and no row was sent.
 * Name basis: descriptive - conditions: FRC running, bypass bit clear, row byte 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129810 @ 0xa0129810-0xa01298d8 (50 words), flags -mcpu=v8 -O3 -g.
 * Source form:
 *  - the row is passed BY VALUE: panel_api_set_active_row(panel_mode_rows[v], 1) with a struct parameter. The
 *    32-bit SPARC ABI passes it as a pointer to a copy made by the caller; making the copy in the call gives the
 *    firmware's order of the eleven doubleword moves, a named local copy gives another order;
 *  - the byte oled_frc_state.ch is read BEFORE the call to sys_frc_is_active (the firmware loads it in the delay
 *    slot of that call);
 *  - v is an unsigned int and indexes the table (not the constant 1); the conditions are nested ifs, because an
 *    && chain is turned into conditional code.
 */
struct PanelRow {
    unsigned char b00[8];
    unsigned short f08;
    unsigned char b0a[6];
    unsigned long long clk_min;
    unsigned long long clk_max;
    unsigned short htot_min, htot_typ, htot_max;
    unsigned short f26, f28;
    unsigned short vtot_min, vtot_typ, vtot_max;
    unsigned char b30[0x18];
    unsigned short vf_at_min_clk, hf_min, hf_max, vf_min, vf_max;
    unsigned char b52[6];
};
struct FrcSm { unsigned short state:4; unsigned short sent:1; unsigned short req:1; unsigned short pad:2; unsigned char ch; unsigned short t; };
extern struct FrcSm oled_frc_state;
extern const struct PanelRow panel_mode_rows[3];
extern unsigned int sys_config;
extern unsigned char sys_frc_is_active(void);
extern void panel_api_set_active_row(struct PanelRow, unsigned char);

#define SYS_CONFIG_BIT26 0x4000000      /* bit 26 of the word at sys_config */

/*
 * Make row 1 of panel_mode_rows (the 120 Hz mode) the active timing row, once.
 *
 * It does so only when the frame-rate converter is active (sys_frc_is_active() == 1), bit 26 of the
 * word sys_config is clear and the row index in the handler state is still 0. The index is then set to 1 and
 * the row is made active and applied to the output.
 *
 * Returns 1 when it switched the row, else 0. No routine calls it.
 */
unsigned char oled_frc_apply_default_row(void)
{
    unsigned char was_index, switched;
    unsigned int active;

    was_index = oled_frc_state.ch;
    active = sys_frc_is_active();
    switched = 0;
    if (active == 1) {
        if (!(sys_config & SYS_CONFIG_BIT26)) {
            if (was_index == 0) {
                oled_frc_state.ch = active;
                panel_api_set_active_row(panel_mode_rows[active], 1);
                switched = 1;
            }
        }
    }
    return switched & 1;
}
