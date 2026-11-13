/* panel_layer_strobe_update  (FUN_a011023c)
 *
 * Trigger the update of a layer and wait until the hardware has taken it.
 * Name basis: derived - update bit in 0xD003B000, wait for it to clear for up to 100 ticks; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011023c @ 0xa011023c, flags -mcpu=v8 -O3 -g.
 * Source form: the layer number is tested in an if/else chain in the order 8, 0, 1, ..., 7. The same body is
 * inlined in panel_channel_layer_setup_window; the declarations of that routine's source are kept here.
 */
/* Declarations of panel_channel_layer_setup_window, which carries this routine inline; not used here. */
struct layer_context;
struct panel_timing_row;
extern struct panel_timing_row *panel_working_row_ptr;
extern struct layer_context panel_layer_context_ch0, panel_layer_context_ch2, panel_layer_context_ch1;
extern volatile unsigned int *panel_channel_blocks_first_half[], *panel_channel_blocks_second_half[];
extern unsigned char panel_layer_position_offset;
extern void panel_layer_set_buffer(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void panel_layer_set_output_size(unsigned char, unsigned char, unsigned short, unsigned short);

/* Used here. */
extern unsigned char panel_layer_update_strobe_enabled;      /* 1: write the update register and wait */
extern unsigned short timer_get_ticks16(void);

#define REG(address) (*(volatile unsigned int *)(address))
#define LAYER_UPDATE      0xd003b000    /* one bit per layer; reads 0 once the hardware has taken the update */
#define UPDATE_ALL_LAYERS 8             /* layer number for all nine bits (0x1FF) */
#define UPDATE_TIMEOUT    100           /* ticks of timer_get_ticks16 */

/*
 * Ask the output layer hardware to take the new settings of one layer, and wait until it has.
 *
 *   layer  0..6: bit 0..6 of the update register; 7: bit 8; 8: all of bits 0..8; any other number writes
 *          nothing but still waits
 *
 * Does nothing unless panel_layer_update_strobe_enabled is 1 (set by panel_layer_set_update_strobe_enabled). The wait ends when the
 * register reads 0 or after 100 ticks, whichever comes first; a timeout is not reported. No routine calls it
 * directly; panel_channel_layer_setup_window carries the same steps in its own body.
 */
void panel_layer_strobe_update(unsigned char layer)
{
    unsigned short start;

    if (panel_layer_update_strobe_enabled == 1) {
        if (layer == UPDATE_ALL_LAYERS)
            REG(LAYER_UPDATE) = 0x1ff;
        else if (layer == 0)
            REG(LAYER_UPDATE) = 1;
        else if (layer == 1)
            REG(LAYER_UPDATE) = 2;
        else if (layer == 2)
            REG(LAYER_UPDATE) = 4;
        else if (layer == 3)
            REG(LAYER_UPDATE) = 8;
        else if (layer == 4)
            REG(LAYER_UPDATE) = 0x10;
        else if (layer == 5)
            REG(LAYER_UPDATE) = 0x20;
        else if (layer == 6)
            REG(LAYER_UPDATE) = 0x40;
        else if (layer == 7)
            REG(LAYER_UPDATE) = 0x100;
        start = timer_get_ticks16();
        while (REG(LAYER_UPDATE) != 0 && (unsigned short)(timer_get_ticks16() - start) < UPDATE_TIMEOUT)
            ;
    }
}
