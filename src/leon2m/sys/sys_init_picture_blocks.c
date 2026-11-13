/* sys_init_picture_blocks  (FUN_a0150da4)
 *
 * Run the picture-block initialisers and set the two mode bits in 0xA802A4B8.
 * Name basis: descriptive - sequence of initialiser calls; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150da4 @ 0xa0150da4-0xa0150df8 (21 words), flags -mcpu=v8 -O3 -g.
 * Source form: the byte at the record label is a struct of two 4-bit fields (big-endian: hi = bits 7..4) and the
 * last step is 'record.hi |= 3;' (the bit-field form gives ldub / and 0xf0 / or 0x30 / and 0xf / or / stb; the mask
 * form gives 'and -16' or another register order).
 */
extern unsigned char ipc_8051_option_byte_entry[];
extern void pq_ace_init(void);
extern void pq_window_set_item_hook(unsigned int);
extern void pq_select_window(unsigned int);
extern void pq_color_matrix_set_enable_flag(unsigned int);
extern void pq_color_matrix_set_option(unsigned char);
/* The record at the label sys_picture_init_record: two 4-bit fields, the high one is written here. */
struct picture_init_record { unsigned char hi:4, lo:4; };
extern struct picture_init_record sys_picture_init_record;

/*
 * Run the initialisers of the picture blocks and set the two low bits of the high 4-bit field of the byte at
 * sys_picture_init_record.
 *
 * Steps: initialise the ACE blocks; give the window item hook the address ipc_8051_option_byte_entry; select
 * picture window 0; switch the colour matrix enable flag and its option off.
 *
 * Called from System_Initialize (System_Initialize).
 */
void sys_init_picture_blocks(void)
{

    pq_ace_init();
    pq_window_set_item_hook(ipc_8051_option_byte_entry);
    pq_select_window(0);
    pq_color_matrix_set_enable_flag(0);
    pq_color_matrix_set_option(0);
    sys_picture_init_record.hi |= 3;
}
