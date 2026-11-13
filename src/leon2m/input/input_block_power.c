/* input_block_power  (FUN_a0121714)
 *
 * Switch the receiver block of one input port on or off.
 * Name basis: derived - masks its interrupt source around the register writes
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0121714 @ 0xa0121714, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: one input_capture_write8 call per case group of the register-0x54 choice (gcc cross-jumps them),
 * not a value variable; the capture write/update routines are declared with int register and value parameters.
 */
/* The working copy of the active panel timing row (panel_working_row_ptr); only the fields that are named are used. */
struct panel_timing_row {
    unsigned int flags;
    unsigned short half_0x4;
    unsigned char display_mode, bpc;
    unsigned short active_size0, active_size1;
    unsigned char bytes_0x0c[0x14];
    unsigned short htotal_min, htotal;      /* htotal: +0x22, the middle of the three values printed as 'Htoal' */
};
struct input_block_config { unsigned int word_0, word_4, word_8; };
extern struct panel_timing_row *panel_working_row_ptr;
extern unsigned int sys_unit_event_bits;
extern struct input_block_config input_block_configs[];
extern void irq_mask_sources(int, int);
extern void input_capture_write16(unsigned char, int, int);
extern void input_adc_set_line_width(unsigned char, unsigned short);
extern void input_capture_write8(unsigned char, int, int);
extern void input_capture_update_bits(unsigned char, int, int, int);
extern unsigned char input_block_get_signal_code(unsigned char);

#define IRQ_LEVEL_UNIT_EVENTS  5            /* interrupt level whose sources latch the unit events */
#define IRQ_SOURCES_UNITS      0xf          /* sources 0..3 of that level */

/*
 * Switch one input block on (the state input_adc_calibrate_internal works in) or off (the state input_blocks_init
 * gives every block).
 *
 *   block  input block (0..7)
 *   on     non-zero: switch on; 0: switch off
 *
 * On: masks the four sources of interrupt level 5, clears the block's bit in sys_unit_event_bits (the flag
 * input_block_is_change_pending reads), writes 0xb0 to capture register 0x57 and 0x464 to 0x59,
 * passes the horizontal total (htotal) of the working panel timing row to input_adc_set_line_width, writes 0xb2
 * to register 0x55 and 1 to register 0x54 and sets bit 5 of register 0x94.
 * Off: writes 0xc0 to register 0x55 and a value to register 0x54 that depends on the signal code of the block
 * (0x20 for 0x11, 0x71 and 0x81; 0x21 for 0x12, 0x13 and 0x21; for 0x31, 0x41, 0x51 and 0x61 0x20 when word_0 of
 * the block's input_block_configs entry is 1; 0x90 for everything else), clears bit 5 of register 0x94 and sets
 * the block's bit in sys_unit_event_bits.
 *
 * Called by input_adc_calibrate_internal (on before the measurement, off after it) and by input_blocks_init
 * (off, for blocks 0..7).
 */
void input_block_power(unsigned char block, unsigned char on)
{
    if (on) {
        irq_mask_sources(IRQ_LEVEL_UNIT_EVENTS, IRQ_SOURCES_UNITS);
        sys_unit_event_bits &= ~(1 << block);
        input_capture_write16(block, 0x57, 0xb0);
        input_capture_write16(block, 0x59, 0x464);
        input_adc_set_line_width(block, panel_working_row_ptr->htotal);
        input_capture_write8(block, 0x55, 0xb2);
        input_capture_write8(block, 0x54, 1);
        input_capture_update_bits(block, 0x94, 0x20, 1);
        return;
    }
    input_capture_write8(block, 0x55, 0xc0);
    switch (input_block_get_signal_code(block)) {
    case 0x11: case 0x71: case 0x81:
        input_capture_write8(block, 0x54, 0x20); break;
    case 0x12: case 0x13: case 0x21:
        input_capture_write8(block, 0x54, 0x21); break;
    case 0x31: case 0x41: case 0x51: case 0x61:
        if (input_block_configs[block].word_0 == 1) input_capture_write8(block, 0x54, 0x20); else input_capture_write8(block, 0x54, 0x90);
        break;
    default:
        input_capture_write8(block, 0x54, 0x90); break;
    }
    input_capture_update_bits(block, 0x94, 0x20, 0);
    sys_unit_event_bits |= 1 << block;
}
