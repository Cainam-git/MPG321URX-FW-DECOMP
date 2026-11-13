/* dp_run_link_state  (DP_GetClrSpace)
 *
 * Run one step of the DisplayPort receiver link state machine for one port.
 *   rec: port record
 *   port: port 0 or 1
 *   stream: MST stream
 * Note: The old label is a text this routine prints after it has read the colour space in the stable state.
 * Name basis: proven - prints 'DP(%d) Go to PHY_POWERON', 'DP(%d) stream(%d) Go to LINK_STANDBY', 'MST2SST' /
 *   'SST2MST'
 *
 * Matching notes
 * --------------
 * leon2s DP_GetClrSpace @ 0xa006ed54-0xa006fa28 (3284 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - old-style parameter declarations (unsigned char port, stream);
 *  - the end-of-pass prints pass the new state and the new flags byte through one local (now);
 *  - the "Fifo Abnormal" prints take dp_is_reg44_low_bits_set(port) and dp_reg_read8(port, 0x44) as direct
 *    call arguments;
 *  - in LINK_STABLE the result of dp_is_link_trained is kept in an unsigned int (trained) and that value is
 *    what goes into dp_link_slice_states;
 *  - the halfword at +0x12 is a union: the colour depth is its high byte, the force flag a bit field.
 */

/* Link states (byte +0 of a port record). The firmware's own texts name 2..5: PHY_POWERON, LINK_STANDBY,
   LINK_STABLE and LINK_READY. */
enum link_state {
    LINK_STATE_POWER_OFF = 1,
    LINK_STATE_POWER_ON  = 2,       /* 'PHY_POWERON' */
    LINK_STATE_STANDBY   = 3,       /* 'LINK_STANDBY' */
    LINK_STATE_STABLE    = 4,       /* 'LINK_STABLE' */
    LINK_STATE_READY     = 5        /* 'LINK_READY' */
};

/* Bits of published_flags (+0xD, printed as ucPHYStatus), set by dp_update_port_status_flags. */
#define PORT_FLAG_TRAINED       0x01    /* the link passes dp_is_link_trained; always set above POWER_ON */
#define PORT_FLAG_DSC           0x02    /* printed as 'ucPHYStatus _DPDSCen' by dp_check_timing_change */
#define PORT_FLAGS_CHANGED_MASK 0x48    /* bits 3 and 6: a change of these also marks the port as changed */

#define DP_REG_SCDT             0xF2    /* bit 6 clear is reported as 'Lost SCDT' */
#define DP_SCDT_BIT             0x40
#define DP_REG_44               0x44    /* printed with 'Fifo Abnormal' */

/* Pixel clock values (usLINKClk) taken in LINK_STANDBY: above PIXEL_CLOCK_LOW, at most PIXEL_CLOCK_HIGH. */
#define PIXEL_CLOCK_LOW         0x14
#define PIXEL_CLOCK_HIGH        0xD47
/* The receiver set-up in LINK_STABLE has three clock bands: above 0x3A2, above 0x1C2, and the rest. */
#define CLOCK_BAND_HIGH         0x3A2
#define CLOCK_BAND_MID          0x1C2

#define READY_CHECK_TICKS       0x95    /* LINK_STABLE step 1: checks before LINK_READY */
#define READY_POLL_TICKS        300     /* LINK_READY: interval of the register 0x40 bit 7 write */
#define STATUS_EVENT_COUNT      10      /* status events cleared when LINK_READY is left */

/* Port record (20 bytes, input_port_records): one per input stream. Fields +2..+0xE and +0x12 are what
   ipc_build_port_descriptor sends to the main processor; +0xF and +0x10 ask ipc_publish_port_status to send. */
struct port_record {
    unsigned char state, byte_0x1;                  /* state: enum link_state */
    unsigned short htotal, vtotal, hactive, vactive, pixel_clock;  /* usLINKHtotal .. usLINKClk */
    unsigned char colour_space;                     /* +0xC: dp_get_color_format_code ('DP_GetClrSpace') */
    unsigned char published_flags;                  /* +0xD: PORT_FLAG_* */
    unsigned char byte_0xe;
    unsigned char publish;                          /* +0xF: 1 = send the record to the main processor */
    unsigned char changed;                          /* +0x10: 1 = send it and mark the port as changed */
    unsigned char step;                             /* +0x11: step inside LINK_STABLE; input_set_link_state clears it */
    union {
        unsigned short word;
        unsigned char colour_depth;                 /* high byte: bits per colour ('ucColordepth') */
        struct {
            unsigned short hi : 11;                 /* bit 7 = PORT_FLAG_COMMAND_BIT, bit 6 = range flag */
            unsigned short force_mode_change : 1;   /* bit 4: 'bForceModeChange' */
            unsigned short lo : 4;
        } bits;
    } flags;
};

extern unsigned char dp_link_flags[];
extern unsigned char dp_link_mst_flags[];
extern unsigned int dp_link_ticks[];
extern unsigned char dp_link_slice_states[];
extern unsigned char dp_block_event_handled_flags[];
extern unsigned char dp_link_counters[];

extern int dbg_printf(char *, ...);
extern void dp_set_port_record_byte_125(unsigned char, unsigned char);
extern unsigned char dp_get_port_record_byte_125(unsigned char);
extern void dp_mst_select_port(unsigned char);
extern void dp_mst_reset_port(void);
extern unsigned char dp_get_reg3a_bit6(unsigned char);
extern unsigned char dp_get_port_record_byte_129(unsigned char);
extern unsigned char dp_get_reg2a9_bit2(unsigned char);
extern void dp_set_reg226_bit2(unsigned char, unsigned char);
extern void dp_set_port_event_bit(unsigned char);
extern void irq_raise_software_irq_bit3(void);
extern void dp_set_reg3a_bit6(unsigned char);
extern unsigned char dp_get_regc1_bit0(unsigned char);
extern void dp_set_bank_registers(unsigned char, unsigned char);
extern void dp_update_fec_ready(unsigned char, unsigned char, unsigned char);
extern void input_set_link_state(struct port_record *, unsigned char);
extern unsigned char dp_mst_get_state_byte_47(void);
extern unsigned char dp_mst_get_state_byte_53(void);
extern unsigned char dp_mst_get_state_byte_52(void);
extern void dp_unit_restart(unsigned char, unsigned char);
extern void dp_stop_port(unsigned char);
extern void dp_start_port(unsigned char, unsigned char);
extern void dp_set_port_control_bit(unsigned char, unsigned char);
extern void dp_set_reg3_bit5(unsigned char, unsigned char);
extern void dp_update_port_status_flags(struct port_record *, unsigned char);
extern void dp_pulse_reg487_bit2(unsigned char);
extern void dp_tx_post_action_flags(unsigned char, unsigned short);
extern unsigned char dp_is_link_trained(unsigned char);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern unsigned short dp_calc_pixel_clock(unsigned char);
extern void dp_pulse_reg20_bit3(unsigned char);
extern unsigned int timer_get_ticks(void);
extern unsigned short dp_read_reg90_word(unsigned char);
extern unsigned short dp_read_reg92_word(unsigned char);
extern unsigned short dp_get_hactive(unsigned char);
extern unsigned short dp_get_vactive(unsigned char);
extern void dp_unit_set_bit3(unsigned char, unsigned char);
extern void dp_select_lane_mask(unsigned char);
extern unsigned char dp_update_reg46_bit2(unsigned char);
extern unsigned char dp_check_timing_change(struct port_record *, unsigned char);
extern unsigned char dp_has_slice_count(unsigned char);
extern unsigned char dp_get_color_format_code(unsigned char, unsigned char);
extern unsigned int dp_get_color_depth(unsigned char);
extern void dp_apply_format_code(unsigned char, unsigned char, unsigned char);
extern void dp_unit_set_bits_10_80(unsigned char, unsigned char);
extern void dp_unit_set_reg0b_field(unsigned char, unsigned char);
extern unsigned char dp_is_format_code_group_3(unsigned char);
extern void dp_set_unit_route_field(unsigned char, unsigned char);
extern void dp_enable_dsc(unsigned char, unsigned char);
extern void dp_toggle_status_bit(unsigned char, unsigned char);
extern void dp_set_reg44_high_bits(unsigned char, unsigned char);
extern void dp_store_port_register_value(unsigned char);
extern void dp_reprogram_clock_registers(unsigned char);
extern void dp_pulse_pll_unit_reg3(unsigned char);
extern void dp_set_reg44_low_bits(unsigned char);
extern unsigned char dp_is_reg44_low_bits_set(unsigned char);
extern void irq_empty_vector_handler_copy7(unsigned char);
extern void dp_update_reg46_bit3(unsigned char);
extern void dp_set_reg40_bit7(unsigned char);
extern void dp_ack_status_bit4(unsigned char);
extern void dp_clear_port_status_bytes(unsigned char);
extern void dp_clear_status_event(unsigned char, unsigned char);
extern void dp_flag_port_stream_reset(struct port_record *, unsigned char, unsigned char);

/*
 * One pass of the link state machine of a DisplayPort input.
 *
 *   rec     the input's port record (input_port_records[4] for port 0, [5] for port 1)
 *   port    DisplayPort input 0 or 1; any other value returns at once
 *   stream  index into dp_link_ticks / dp_link_counters; streams 1..3 are also gated by MST state bytes
 *
 * The only call in the program is input_run_link_tasks, every main-loop pass, with (records[4], 0, 0) and
 * (records[5], 1, 4). So the stream 1..3 tests and the "other stream" clock bands below are not reached from it.
 *
 * Phases of a pass:
 *   1. Remember state, published flags and byte 0xE, to report changes at the end.
 *   2. Housekeeping before the states: copy the main processor's port flag into byte 0x125 of the DP input
 *      record; reset the MST records of the port when that byte is 0; pass on a register 0x3A event.
 *   3. MST check: when bit 0 of register 0xC1 changes ('SST2MST' / 'MST2SST'), switch the bank registers and
 *      the FEC-ready state and go back to POWER_ON.
 *   4. One step of the state:
 *        POWER_OFF  restart the receiver unit and stop the port.
 *        POWER_ON   start the port; once the link is trained go to STANDBY.
 *        STANDBY    wait for training, SCDT and a pixel clock in range; capture the timing; go to STABLE.
 *        STABLE     step 0: wait 100 ticks (700 with DSC) for the timing to settle, then read colour space and
 *                   depth and set the receiver up for the clock band; step 1: wait 0x95 ticks for a mode change
 *                   or a FIFO error, then go to READY.
 *        READY      watch for lost training, lost SCDT, a colour space change, a mode change or a FIFO error;
 *                   on leaving READY clear the port's status events and flag a stream reset.
 *   5. Report: leaving READY marks the record as changed; a change of the published flags or byte 0xE asks
 *      for the record to be sent to the main processor.
 */
void dp_run_link_state(rec, port, stream)
    struct port_record *rec;
    unsigned char port, stream;
{
    /* 1. State at the start of the pass. */
    unsigned char old_state = rec->state;
    unsigned char old_flags = rec->published_flags;
    unsigned char old_byte_0xe = rec->byte_0xe;
    unsigned char mst[2];
    unsigned char i, now;
    unsigned int trained;

    if (port > 1)
        return;

    /* 2. Bit 7 of the flags halfword is the flag the main processor sends for this port
       (input_load_port_flag_bits); for port 0 it is copied only on stream 0. */
    if ((port == 0 && stream == 0) || port == 1)
        dp_set_port_record_byte_125(port, (rec->flags.word >> 7) & 1);
    if (dp_get_port_record_byte_125(port) == 0 && dp_link_flags[port] == 1 && dp_link_mst_flags[port] != 0) {
        dp_mst_select_port(port);
        dp_mst_reset_port();
    }
    /* Register 0x3A bit 6 with byte 0x129 of the DP input record set: raise the port's event bit and software
       interrupt bit 3 for the main processor, then write bit 6 back. */
    if (dp_get_reg3a_bit6(port) && dp_get_port_record_byte_129(port)) {
        if (dp_get_reg2a9_bit2(port))
            dp_set_reg226_bit2(port, 1);
        dp_set_port_event_bit(port);
        irq_raise_software_irq_bit3();
        dp_set_reg3a_bit6(port);
    }

    /* 3. MST mode: bit 0 of register 0xC1, compared with the value of the last pass. */
    mst[port] = dp_get_regc1_bit0(port);
    if (dp_link_mst_flags[port] != mst[port]) {
        if (mst[port]) {
            dbg_printf("\033[1;31m---------------SST2MST %d---------------\r\n\033[m", port);
            dp_set_bank_registers(port, 1);
            dp_update_fec_ready(0, 1, 0);
        } else {
            dbg_printf("\033[1;31m>>>>>>>>>>>>>MST2SST %d>>>>>>>>>>>>>\r\n\033[m", port);
            dp_set_bank_registers(port, 0);
            dp_update_fec_ready(port, 0, 0);
        }
        input_set_link_state(rec, LINK_STATE_POWER_ON);
        dp_link_mst_flags[port] = mst[port];
    }
    /* Streams 1..3 run only while their MST state byte is set; otherwise they fall back to POWER_ON (or stay
       below it) and the pass ends here. */
    if ((stream == 1 && dp_mst_get_state_byte_47() == 0) || (stream == 2 && dp_mst_get_state_byte_53() == 0) ||
        (stream == 3 && dp_mst_get_state_byte_52() == 0)) {
        if (rec->state <= LINK_STATE_POWER_ON)
            return;
        input_set_link_state(rec, LINK_STATE_POWER_ON);
    }

    /* 4. One step of the current state. */
    switch (rec->state) {
    case LINK_STATE_POWER_OFF:
        dp_unit_restart(port, 1);
        dp_stop_port(port);
        break;

    case LINK_STATE_POWER_ON:
        dp_start_port(port, 0);
        dp_set_port_control_bit(port, 0);
        dp_unit_restart(port, 1);
        dp_set_reg3_bit5(port, 1);
        dp_update_port_status_flags(rec, port);
        if (rec->published_flags & PORT_FLAG_TRAINED) {
            dp_pulse_reg487_bit2(port);
            dp_tx_post_action_flags(0, 8);      /* action flag 8 for DP output 0 */
            input_set_link_state(rec, LINK_STATE_STANDBY);
            dbg_printf("DP(%d) stream(%d) Go to LINK_STANDBY 1\r\n", port, stream);
        }
        break;

    case LINK_STATE_STANDBY:
        /* dp_is_link_trained returns 1 while the link is trained; anything else is 'Lost Training'. */
        if (dp_is_link_trained(port) != 1) {
            input_set_link_state(rec, LINK_STATE_POWER_ON);
            dbg_printf("DP(%d) Go to PHY_POWERON 1\r\n", port);
            break;
        }
        if (!(dp_reg_read8(port, DP_REG_SCDT) & DP_SCDT_BIT))
            break;
        if (dp_calc_pixel_clock(port) <= PIXEL_CLOCK_LOW)
            break;
        if (dp_calc_pixel_clock(port) > PIXEL_CLOCK_HIGH)
            break;
        /* Signal present: capture the timing and start the settle time of LINK_STABLE. */
        dp_pulse_reg20_bit3(port);
        input_set_link_state(rec, LINK_STATE_STABLE);
        dp_link_ticks[stream] = timer_get_ticks();
        rec->htotal = dp_read_reg90_word(port);
        rec->vtotal = dp_read_reg92_word(port);
        rec->hactive = dp_get_hactive(port);
        rec->vactive = dp_get_vactive(port);
        rec->pixel_clock = dp_calc_pixel_clock(port);
        rec->flags.bits.force_mode_change = 0;
        dp_update_port_status_flags(rec, port);
        dp_set_port_control_bit(port, 0);
        dp_unit_restart(port, 1);
        dp_unit_set_bit3(port, 1);
        dp_select_lane_mask(port);
        dbg_printf("DP(%d) usLINKHtotal %d\r\n", port, rec->htotal);
        dbg_printf("DP(%d) usLINKVtotal %d\r\n", port, rec->vtotal);
        dbg_printf("DP(%d) usLINKHrtlDE %d\r\n", port, rec->hactive);
        dbg_printf("DP(%d) usLINKVrtlDE %d\r\n", port, rec->vactive);
        dbg_printf("DP(%d) usLINKClk %d\r\n", port, rec->pixel_clock);
        dbg_printf("DP(%d) Go to LINK_STABLE\r\n", port);
        dp_block_event_handled_flags[port] = 0;     /* lets dp_port_task handle the next block event */
        break;

    case LINK_STATE_STABLE:
        trained = dp_is_link_trained(port);
        if (trained != 1) {
            input_set_link_state(rec, LINK_STATE_POWER_ON);
            dbg_printf("Lost Training, DP(%d) Go to PHY_POWERON\r\n", port);
            break;
        }
        if (!(dp_reg_read8(port, DP_REG_SCDT) & DP_SCDT_BIT)) {
            input_set_link_state(rec, LINK_STATE_STANDBY);
            dbg_printf("Lost SCDT, DP(%d) Go to LINK_STANDBY\r\n", port);
            break;
        }
        if (dp_update_reg46_bit2(port)) {
            input_set_link_state(rec, LINK_STATE_POWER_ON);
            dbg_printf("FIFO Mode Changed, DP(%d) Go to PHY_POWERON\r\n", port);
            break;
        }
        switch (rec->step) {
        case 0:
            /* Settle time: 100 ticks, 700 with DSC. A timing change restarts it. A non-zero slice count
               (dp_has_slice_count) is noted in dp_link_slice_states (value 1). */
            if (timer_get_ticks() - dp_link_ticks[stream] < (rec->published_flags & PORT_FLAG_DSC) * 300 + 100) {
                if (dp_check_timing_change(rec, port) == 1)
                    dp_link_ticks[stream] = timer_get_ticks();
                if (dp_has_slice_count(port))
                    dp_link_slice_states[port] = trained;
                break;
            }
            /* Colour space and colour depth of the stream. */
            rec->colour_space = dp_get_color_format_code(port, (rec->published_flags >> 1) & 1);
            dbg_printf("DP_GetClrSpace(%d) %02x\r\n", port, rec->colour_space);
            rec->flags.colour_depth = dp_get_color_depth(port);
            dbg_printf("DP ucColordepth(%d) \r\n", rec->flags.colour_depth);
            /* Receiver unit set-up by clock band; streams 0 and 4 (the two the caller passes) use the first
               table, the other streams the second. */
            if (stream == 0 || stream == 4) {
                if (rec->pixel_clock > CLOCK_BAND_HIGH) {
                    dp_apply_format_code(port, 4, rec->colour_space);
                    dp_unit_set_bits_10_80(port, 0);
                    dp_unit_set_reg0b_field(port, 0);
                    dp_set_unit_route_field(port, 1);
                } else if (rec->pixel_clock > CLOCK_BAND_MID) {
                    dp_apply_format_code(port, 1, rec->colour_space);
                    dp_unit_set_bits_10_80(port, 0);
                    dp_unit_set_reg0b_field(port, 0);
                    dp_set_unit_route_field(port, 2);
                } else {
                    dp_apply_format_code(port, 1, rec->colour_space);
                    dp_unit_set_bits_10_80(port, 1);
                    dp_unit_set_reg0b_field(port, 0);
                    if (dp_is_format_code_group_3(rec->colour_space))
                        dp_set_unit_route_field(port, 4);
                    else
                        dp_set_unit_route_field(port, 2);
                }
            } else {
                if (rec->pixel_clock > CLOCK_BAND_HIGH) {
                    dp_apply_format_code(port, 4, rec->colour_space);
                    dp_unit_set_bits_10_80(port, 0);
                    dp_unit_set_reg0b_field(port, 0);
                    dp_set_unit_route_field(port, 1);
                } else if (rec->pixel_clock > CLOCK_BAND_MID) {
                    dp_apply_format_code(port, 1, rec->colour_space);
                    dp_unit_set_bits_10_80(port, 1);
                    dp_unit_set_reg0b_field(port, 1);
                    dp_set_unit_route_field(port, 2);
                } else {
                    dp_apply_format_code(port, 1, rec->colour_space);
                    dp_unit_set_bits_10_80(port, 0);
                    dp_unit_set_reg0b_field(port, 0);
                    if (dp_is_format_code_group_3(rec->colour_space))
                        dp_set_unit_route_field(port, 4);
                    else
                        dp_set_unit_route_field(port, 2);
                }
            }
            dp_update_port_status_flags(rec, port);
            if (dp_has_slice_count(port))
                dp_link_slice_states[port] = 2;
            /* DSC on when the flags say so or a slice count was seen (the callee prints 'DP DSC en= %d'). */
            if ((rec->published_flags & PORT_FLAG_DSC) || dp_link_slice_states[port] == 2) {
                dp_enable_dsc(port, 1);
                dp_toggle_status_bit(port, 1);
                dp_block_event_handled_flags[port] = 0;
            } else {
                dp_enable_dsc(port, 0);
                dp_toggle_status_bit(port, 0);
                dp_link_slice_states[port] = 0;
            }
            dp_set_reg44_high_bits(port, 0xb0);
            dp_set_reg3_bit5(port, 0);
            dp_set_port_control_bit(port, 1);
            dp_unit_restart(port, 0);
            dp_unit_set_bit3(port, 0);
            dp_store_port_register_value(port);
            dp_reprogram_clock_registers(port);
            dp_pulse_pll_unit_reg3(port);
            dp_link_ticks[stream] = timer_get_ticks();
            dp_set_reg44_low_bits(port);
            rec->step++;
            break;
        case 1:
            /* Check time after the set-up (skipped with DSC): a timing change starts LINK_STABLE again;
               the low bits of register 0x44 are set again whenever they read as set. */
            if ((rec->published_flags & PORT_FLAG_DSC) == 0 && timer_get_ticks() - dp_link_ticks[stream] <= READY_CHECK_TICKS) {
                if (dp_check_timing_change(rec, port) == 1) {
                    input_set_link_state(rec, LINK_STATE_STABLE);
                    dp_link_ticks[stream] = timer_get_ticks();
                    break;
                }
                if (dp_is_reg44_low_bits_set(port) == 1)
                    dp_set_reg44_low_bits(port);
                break;
            }
            if ((rec->published_flags & PORT_FLAG_DSC) == 0 && dp_is_reg44_low_bits_set(port) == 1) {
                dbg_printf("(%02x)Fifo Abnormal %02x, %02x\r\n", port, dp_is_reg44_low_bits_set(port), dp_reg_read8(port, DP_REG_44));
                input_set_link_state(rec, LINK_STATE_STABLE);
                dp_link_ticks[stream] = timer_get_ticks();
                break;
            }
            /* Ready: ask for the record to be sent. */
            input_set_link_state(rec, LINK_STATE_READY);
            dbg_printf("\033[1;32mDP(%d) stream(%d) Go to LINK_READY %d\r\n\033[m", port, stream, rec->pixel_clock);
            rec->publish = 1;
            dp_link_ticks[stream] = timer_get_ticks();
            dp_link_counters[stream] = 0;
            irq_empty_vector_handler_copy7(port);
            break;
        }
        break;

    case LINK_STATE_READY:
        /* The first condition found decides where the link goes. */
        if (dp_is_link_trained(port) != 1) {
            dbg_printf("Lost Training %d\r\n", port);
            input_set_link_state(rec, LINK_STATE_POWER_ON);
        } else if (!(dp_reg_read8(port, DP_REG_SCDT) & DP_SCDT_BIT)) {
            dbg_printf("Lost SCDT %d\r\n", port);
            input_set_link_state(rec, LINK_STATE_STANDBY);
        } else if (dp_get_color_format_code(port, (rec->published_flags >> 1) & 1) != rec->colour_space) {
            dbg_printf("color space changed %d\r\n", port);
            rec->colour_space = dp_get_color_format_code(port, (rec->published_flags >> 1) & 1);
            input_set_link_state(rec, LINK_STATE_STABLE);
            dp_link_ticks[stream] = timer_get_ticks();
        } else if (dp_check_timing_change(rec, port) == 1) {
            input_set_link_state(rec, LINK_STATE_STABLE);
            dp_link_ticks[stream] = timer_get_ticks();
            dbg_printf("DP mode change %lX\r\n", dp_link_ticks[stream]);
        } else if (!(rec->published_flags & PORT_FLAG_DSC) && dp_is_reg44_low_bits_set(port) == 1) {
            dbg_printf("(%02x)Fifo Abnormal %02x, %02x\r\n", port, dp_is_reg44_low_bits_set(port), dp_reg_read8(port, DP_REG_44));
            input_set_link_state(rec, LINK_STATE_STABLE);
            dp_link_ticks[stream] = timer_get_ticks();
        } else {
            /* Link stays ready. Every READY_POLL_TICKS: set register 0x40 bit 7; from the first of these on,
               dp_ack_status_bit4 runs on every pass. */
            dp_update_reg46_bit3(port);
            if (timer_get_ticks() - dp_link_ticks[stream] > READY_POLL_TICKS) {
                dp_link_ticks[stream] = timer_get_ticks();
                dp_set_reg40_bit7(port);
                dp_link_counters[stream] = 1;
            }
            if (dp_link_counters[stream] == 1)
                dp_ack_status_bit4(port);
        }
        /* Leaving READY: clear the port's status bytes and events and flag a stream reset. */
        if (rec->state != LINK_STATE_READY) {
            dp_clear_port_status_bytes(port);
            for (i = 0; i < STATUS_EVENT_COUNT; i++)
                dp_clear_status_event(port, i);
            dp_flag_port_stream_reset(rec, port, stream);
        }
        break;
    }

    /* 5. Report what changed in this pass. */
    now = rec->state;
    if (now != LINK_STATE_READY && old_state == LINK_STATE_READY) {
        rec->changed = 1;
        dbg_printf("DP linkidx %d ucLINKStatus %d\r\n", port, now);
        dp_link_slice_states[port] = 0;
    }
    now = rec->published_flags;
    if (now != old_flags || rec->byte_0xe != old_byte_0xe) {
        rec->publish = 1;
        if ((now & PORT_FLAGS_CHANGED_MASK) != (old_flags & PORT_FLAGS_CHANGED_MASK))
            rec->changed = 1;
        dbg_printf("DP linkidx %d ucPHYStatus (%02xh,%02xh)\r\n", port, now, rec->byte_0xe);
    }
}
