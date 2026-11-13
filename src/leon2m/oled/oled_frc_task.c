/* oled_frc_task  (FUN_a01295e4)
 *
 * Send the refresh-rate row index to the OLED panel controller and resend it on request.
 * Name basis: proven - state machine; I2C device 0x60 register 0xB2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01295e4 @ 0xa01295e4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the state record is a non-volatile struct with a bitfield state word: { state:4, row_sent:1 (0x800),
 *    send_request:1 (0x400), :2; u8 row_index; u16 timestamp }. The firmware reads the row byte as one byte
 *    load and merges "row_sent = 1; send_request = 0" into one or/and; only this struct reproduces that;
 *  - each state has its own 'panel power pin low -> state 0' reset (the compiler merges them; a shared goto does
 *    not give the firmware's layout);
 *  - the idle state is the default arm and is written first in the switch;
 *  - the double halfword load at the case-3 test is a scheduling copy of the state-0 target's load into the
 *    delay slot, not a second read in the source.
 */
/* States of the machine (oled_frc_state.state). Names 1..3 are the firmware's own texts ("OLED_FRC_DVDD_ON",
   "OLED_FRC_FRC_READY", "OLED_FRC_IIC_READY"). Any other value (4..15) is handled like 0. */
enum {
    FRC_STATE_IDLE      = 0,    /* the panel power pin was seen low */
    FRC_STATE_DVDD_ON   = 1,    /* the pin was seen high; waiting 500 ticks for the controller to be enabled */
    FRC_STATE_FRC_READY = 2,    /* the row index is sent here, then 500 ticks are waited */
    FRC_STATE_IIC_READY = 3     /* sent; waits for a send request */
};

#define FRC_WAIT_TICKS  500     /* wait before leaving state 1 and state 2 */

#define FORCE_120HZ_MODE 1      /* third argument of SYSAPI_GetPanelParamStruct */

/* The state record (oled_frc_state at 0xA802D892; the first byte holds the state and the two flags). */
struct oled_frc_state_record {
    unsigned short state:4;         /* FRC_STATE_* */
    unsigned short row_sent:1;      /* 0x800: the row index was sent and no new send was requested since */
    unsigned short send_request:1;  /* 0x400: set by oled_frc_request_send; send the row index again */
    unsigned short pad:2;
    unsigned char row_index;        /* +1 (0xA802D893): the row sent to the controller (panel mode row, see oled_frc_set_row) */
    unsigned short timestamp;       /* +2: tick count at the last state change that starts a wait */
};

extern struct oled_frc_state_record oled_frc_state;
extern unsigned char gpio_is_port13_bit5_high(void);
extern unsigned char oled_is_controller_enabled(void);
extern unsigned char sys_frc_is_active(void);
extern int dbg_printf();
extern void oled_set_frame_rate_control(unsigned char);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern unsigned char input_used_ports_settled(void);
extern void SYSAPI_GetPanelParamStruct(int, int, int);
extern void panel_output_apply_timing(int);
extern void panel_set_clock_from_row(void);
extern int sys_get_channel_source_class(int);
extern void sys_frc_set_channel_bit_triple(unsigned char, int);
extern void sys_frc_set_active(int);

/*
 * One step of the machine that sends the panel mode row index to the OLED panel controller. Called again and
 * again from the main loop task (sys_run_app_timer_task) and from the wait loops of SYSAPI_PanelOnOffControl. No
 * arguments, no return value.
 *
 * The machine follows the pin that PanelPowerOn drives (gpio_is_port13_bit5_high): in every state, when the
 * pin is low the state goes back to FRC_STATE_IDLE.
 *   idle      pin high -> state 1, take a time stamp, clear row_sent and send_request. When all used inputs have
 *             settled (input_used_ports_settled): if the frame-rate converter is active, clear its bit for the
 *             channel of the main source and switch it off; then SYSAPI_GetPanelParamStruct(1, 1, 1) puts the
 *             panel into the 120 Hz mode, and the output timing and the clocks are programmed for that row.
 *             Always prints "OLED_FRC_DVDD_ON".
 *   state 1   after 500 ticks, once the controller is enabled (oled_is_controller_enabled): state 2.
 *   state 2   when the row was not sent yet, or a send was requested since: write row_index to the controller
 *             (oled_set_frame_rate_control), set row_sent, clear send_request, take a time stamp. Otherwise,
 *             after 500 ticks: state 3.
 *   state 3   when send_request is set (oled_frc_request_send, called after a mode change): back to state 2.
 */
void oled_frc_task(void)
{
    switch (oled_frc_state.state) {
    default:
        if (gpio_is_port13_bit5_high() != 1) break;
        oled_frc_state.state = FRC_STATE_DVDD_ON; oled_frc_state.row_sent = 0; oled_frc_state.send_request = 0;
        oled_frc_state.timestamp = timer_get_ticks16();
        if ((unsigned char)input_used_ports_settled() == 1) {
            if ((unsigned char)sys_frc_is_active() == 1) {
                sys_frc_set_channel_bit_triple(sys_get_channel_source_class(0), 0);
                sys_frc_set_active(0);
            }
            /* Force the 120 Hz panel mode; the clock and the output timing then follow the new row. */
            SYSAPI_GetPanelParamStruct(1, 1, FORCE_120HZ_MODE);
            panel_output_apply_timing(0);
            panel_set_clock_from_row();
        }
        dbg_printf("\033[1;32mOLED_FRC_DVDD_ON\r\n\033[m");
        break;
    case FRC_STATE_DVDD_ON:
        if (!gpio_is_port13_bit5_high()) { oled_frc_state.state = FRC_STATE_IDLE; break; }
        if (timer_ticks_since(oled_frc_state.timestamp) > FRC_WAIT_TICKS && (unsigned char)oled_is_controller_enabled() == 1) {
            oled_frc_state.state = FRC_STATE_FRC_READY;
            dbg_printf("\033[1;32mOLED_FRC_FRC_READY\r\n\033[m");
        }
        break;
    case FRC_STATE_FRC_READY:
        if (!gpio_is_port13_bit5_high()) { oled_frc_state.state = FRC_STATE_IDLE; break; }
        if (!(oled_frc_state.row_sent == 1 && oled_frc_state.send_request == 0)) {
            dbg_printf("\033[1;32mOLED_FRC_Handler %d\r\n\033[m", oled_frc_state.row_index);
            oled_set_frame_rate_control(oled_frc_state.row_index);
            oled_frc_state.row_sent = 1; oled_frc_state.send_request = 0;
            oled_frc_state.timestamp = timer_get_ticks16();
        } else if (timer_ticks_since(oled_frc_state.timestamp) > FRC_WAIT_TICKS) {
            oled_frc_state.state = FRC_STATE_IIC_READY;
            dbg_printf("\033[1;32mOLED_FRC_IIC_READY\r\n\033[m");
        }
        break;
    case FRC_STATE_IIC_READY:
        if (!gpio_is_port13_bit5_high()) { oled_frc_state.state = FRC_STATE_IDLE; break; }
        if (oled_frc_state.send_request) {
            oled_frc_state.state = FRC_STATE_FRC_READY;
            dbg_printf("\033[1;32mOLED_FRC_FRC_READY\r\n\033[m");
        }
        break;
    }
}
