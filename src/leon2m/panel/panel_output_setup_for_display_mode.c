/* panel_output_setup_for_display_mode  (FUN_a0101e9c)
 *
 * Program the output registers that depend on the display mode.
 * Name basis: derived - one branch per display mode; called when the output timing is applied
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101e9c @ 0xa0101e9c, flags -mcpu=v8 -O3 -g; jump table at 0xa0101cc8 (panel_output_setup_for_display_mode_jump_table), cases in number order.
 * Source forms the exact build depends on:
 *  - every field is written as a clear (&= ~bits) followed by a separate set (|= bits), each a volatile
 *    read-modify-write; a case that leaves the field 0 has only the clear;
 *  - the row's first word is declared volatile, so it is read again after the register writes of its case.
 */
#define R(a) (*(volatile unsigned long *)(a))

/* Output registers written here. Each holds a field that this routine sets to a value per display mode. */
#define OUT_REG_ED54  R(0xcf00ed54)     /* bit 3: set for display mode 16 only */
#define OUTPUT_SYNC_POLARITY  R(0xcf00ed58)     /* 0xCF00ED58; bit 4 is the sync polarity, the field here is
                                                 bits 0..3 (values 0, 1, 4, 5) */
#define OUT_REG_EDE0  R(0xcf00ede0)     /* field: bits 0..2 and 4..7 (mask 0xF7); bit 3 is not touched */
#define OUT_REG_116D4 R(0xcf0116d4)     /* field: bits 4, 6 and 7 (mask 0xD0; values 0, 0x40, 0x80) */

/* Bits 20..22 of the row's first word: the link type. In the working copy panel_transform_row has swapped
   the values 1 and 2 of the active row. */
#define ROW_LINK_TYPE_MASK 0x700000
#define ROW_LINK_TYPE_1    0x100000

/* The working copy of the active panel timing row; only its first word is read here. */
struct panel_working_row { volatile unsigned int flags; };   /* volatile: re-read after the register writes */
extern struct panel_working_row *panel_working_row_ptr;

/*
 * Set the output format fields for a display mode.
 *
 *   mode  the display mode, 0..17 (the one DispModeTransform derives from the row and
 *         panel_output_apply_timing passes on); larger values change nothing
 *
 * The only caller is panel_output_apply_timing. The three panel mode rows of this firmware give display mode
 * 11 (240 Hz and 120 Hz mode) and 5 (60 Hz mode).
 *
 * Field values per mode (ED58 / EDE0 / 116D4; 116D4 only when the working row's link type is 1):
 *    0, 1: 0 / 0x00       2: 0 / 0x01       3: 0 / 0x10       4: 4 / 0x20       5: 1 / 0x30 / 0x00
 *       6: 5 / 0x40       7: 5 / 0x54       8: 1 / 0x62       9: 5 / 0x72 / 0x40
 *      10: 5 / 0x86      11: 1 / 0x92      12: 5 / 0xA2      13: 5 / 0xB6 / 0x80
 *      14: 1 / 0xD2 / 0x00                 15: 5 / 0xC2 / 0x40
 *      16: 0 / 0x00, and bit 3 of 0xCF00ED54 set              17: 5 / 0xE2 / 0x40
 * Each case clears the field bits that end up 0 and then sets the bits that end up 1.
 */
void panel_output_setup_for_display_mode(unsigned char mode)
{
    switch (mode)
    {
    case 0:
    case 1:
        OUTPUT_SYNC_POLARITY &= ~0x0f;
        OUT_REG_EDE0 &= ~0xf7;
        break;
    case 2:
        OUTPUT_SYNC_POLARITY &= ~0x0f;
        OUT_REG_EDE0 &= ~0xf6; OUT_REG_EDE0 |= 0x01;
        break;
    case 3:
        OUTPUT_SYNC_POLARITY &= ~0x0f;
        OUT_REG_EDE0 &= ~0xe7; OUT_REG_EDE0 |= 0x10;
        break;
    case 4:
        OUTPUT_SYNC_POLARITY &= ~0x0b; OUTPUT_SYNC_POLARITY |= 0x04;
        OUT_REG_EDE0 &= ~0xd7; OUT_REG_EDE0 |= 0x20;
        break;
    case 5:     /* the 60 Hz panel mode */
        OUTPUT_SYNC_POLARITY &= ~0x0e; OUTPUT_SYNC_POLARITY |= 0x01;
        OUT_REG_EDE0 &= ~0xc7; OUT_REG_EDE0 |= 0x30;
        if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1) {
            OUT_REG_116D4 &= ~0xd0;
        }
        break;
    case 6:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0xb7; OUT_REG_EDE0 |= 0x40;
        break;
    case 7:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0xa3; OUT_REG_EDE0 |= 0x54;
        break;
    case 8:
        OUTPUT_SYNC_POLARITY &= ~0x0e; OUTPUT_SYNC_POLARITY |= 0x01;
        OUT_REG_EDE0 &= ~0x95; OUT_REG_EDE0 |= 0x62;
        break;
    case 9:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0x87; OUT_REG_EDE0 |= 0x72;
        if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1) {
            OUT_REG_116D4 &= ~0x90;
            OUT_REG_116D4 |= 0x40;
        }
        break;
    case 10:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0x71; OUT_REG_EDE0 |= 0x86;
        break;
    case 11:    /* the 240 Hz and the 120 Hz panel mode */
        OUTPUT_SYNC_POLARITY &= ~0x0e; OUTPUT_SYNC_POLARITY |= 0x01;
        OUT_REG_EDE0 &= ~0x65; OUT_REG_EDE0 |= 0x92;
        break;
    case 12:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0x55; OUT_REG_EDE0 |= 0xa2;
        break;
    case 13:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0x41; OUT_REG_EDE0 |= 0xb6;
        if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1) {
            OUT_REG_116D4 &= ~0x50;
            OUT_REG_116D4 |= 0x80;
        }
        break;
    case 14:
        OUTPUT_SYNC_POLARITY &= ~0x0e; OUTPUT_SYNC_POLARITY |= 0x01;
        OUT_REG_EDE0 &= ~0x35; OUT_REG_EDE0 |= 0xd2;
        if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1) {
            OUT_REG_116D4 &= ~0xd0;
        }
        break;
    case 15:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0x35; OUT_REG_EDE0 |= 0xc2;
        if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1) {
            OUT_REG_116D4 &= ~0x90;
            OUT_REG_116D4 |= 0x40;
        }
        break;
    case 16:
        OUTPUT_SYNC_POLARITY &= ~0x0f;
        OUT_REG_EDE0 &= ~0xf7;
        OUT_REG_ED54 |= 0x08;
        break;
    case 17:
        OUTPUT_SYNC_POLARITY &= ~0x0a; OUTPUT_SYNC_POLARITY |= 0x05;
        OUT_REG_EDE0 &= ~0x17; OUT_REG_EDE0 |= 0xe2;
        if ((panel_working_row_ptr->flags & ROW_LINK_TYPE_MASK) == ROW_LINK_TYPE_1) {
            OUT_REG_116D4 &= ~0x90;
            OUT_REG_116D4 |= 0x40;
        }
        break;
    }
}
