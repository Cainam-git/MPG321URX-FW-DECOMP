/* startup_init_display_output  (FUN_a0141964)
 *
 * Build the working panel timing row and set up the output at power-on.
 * Name basis: derived - same steps as panel_transform_row; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0141964 @ 0xa0141964, flags -mcpu=v8 -O3 -g (gcc 3.4.4).
 * Start-up path: nothing in the code may change. Source form: the row is copied byte by byte (u8 counter, 0..0x57)
 * into a local struct that is then passed by value; the link field is a 3-bit bit-field that is set by a switch
 * with the cases 0, 1 and 2 only (no default); the source pointer is read through the row struct for the switch.
 */

#define PANEL_POWER_OFF  1          /* panel_power_state.state: panel off */
#define PANEL_ROW_BYTES  0x58       /* size of a panel timing row */

/* One panel timing row (0x58 bytes); only the fields used here are named. */
struct panel_mode_row {
    unsigned int word0_hi:9;            /* +0, bits 31..23 */
    unsigned int link_type:3;           /* +0, bits 22..20: the row's link type */
    unsigned int word0_lo:20;
    unsigned short half_4;
    unsigned char display_mode;         /* +6: read by DispModeTransform */
    unsigned char rest[81];
};
/* The sequencer record of the panel power state; only its first bytes are written here. */
struct panel_power_record { unsigned char state; unsigned char pad; unsigned short ticks; };
extern struct panel_power_record panel_power_state;
extern unsigned char *panel_get_active_row(void);
extern int DispModeTransform(void);
extern void panel_set_working_row(struct panel_mode_row row);
extern void panel_setup_output_after_row_change(void);

/*
 * Power-on set-up of the display output, called once by the system start-up (startup_bring_up_system) before System_Initialize.
 * Marks the panel power sequencer as off (state PANEL_POWER_OFF, time stamp 0), then builds the working panel
 * timing row: a copy of the active row in which the link type is swapped between 1 and 2 (0 stays 0, any other
 * value stays as copied) and the display mode byte is the one DispModeTransform derives from the active row. The
 * copy becomes the working row (panel_set_working_row), and panel_setup_output_after_row_change sets up the output
 * path. panel_transform_row does the same row steps when the row changes.
 */
void startup_init_display_output(void)
{
    struct panel_mode_row row;
    unsigned char *active_row;
    unsigned char i;
    panel_power_state.ticks = 0;
    panel_power_state.state = PANEL_POWER_OFF;
    active_row = panel_get_active_row();
    for (i = 0; i <= PANEL_ROW_BYTES - 1; i++) ((unsigned char *)&row)[i] = active_row[i];
    switch (((struct panel_mode_row *)active_row)->link_type) {
    case 0: row.link_type = 0; break;
    case 1: row.link_type = 2; break;
    case 2: row.link_type = 1; break;
    }
    row.display_mode = DispModeTransform();
    panel_set_working_row(row);
    panel_setup_output_after_row_change();
}
