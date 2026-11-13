/* pq_api_set_window_item  (FUN_a01471a0)
 *
 * Select the picture window of a channel and set one of sixteen picture items.
 * Name basis: derived - 16-way switch on the item to thirteen setters; called from SetThemeMode
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01471a0 @ 0xa01471a0-0xa014737c (119 words), flags -mcpu=v8 -O3 -g.
 * Source form: the channel remap and the preset clamp are switches (jump tables at 0xe3398 for the item and
 * 0xe3380 for the preset); the 'index == 0xff' test after pq_select_window is part of the firmware's code.
 */

#define WINDOW_NONE 4       /* the window field of the channel record, 4 = no window */

/* The picture item numbers of pq_api_set_window_item. */
enum {
    PQ_ITEM_WINDOW0 = 0,         /* items 0..8 are the setters pq_window_set_item0..8 */
    PQ_ITEM_WINDOW1,
    PQ_ITEM_WINDOW2,
    PQ_ITEM_WINDOW3,
    PQ_ITEM_WINDOW4,
    PQ_ITEM_WINDOW5,
    PQ_ITEM_WINDOW6,
    PQ_ITEM_WINDOW7,
    PQ_ITEM_WINDOW8,
    PQ_ITEM_SCALED_LEVEL_TABLE = 9,
    PQ_ITEM_THREE_ENTRY0 = 10,   /* items 10..12: pq_set_three_entry_table entries 0..2 */
    PQ_ITEM_THREE_ENTRY1,
    PQ_ITEM_THREE_ENTRY2,
    PQ_ITEM_SHARPNESS = 13,      /* pq_block_set_sharpness_field(8, v) */
    PQ_ITEM_COLOR_MATRIX_PRESET = 15
};

struct channel_window { unsigned int hi24 : 24; unsigned int window : 4; unsigned int low4 : 4; unsigned char rest[0x74]; };
extern struct channel_window channel_records[4];
extern int dbg_printf();
extern void pq_select_window(unsigned char);
extern void pq_window_set_item0(unsigned char);
extern void pq_window_set_item1(unsigned char);
extern void pq_window_set_item2(unsigned char);
extern void pq_window_set_item3(unsigned char);
extern void pq_window_set_item4(unsigned char);
extern void pq_window_set_item5(unsigned char);
extern void pq_window_set_item6(unsigned char);
extern void pq_window_set_item7(unsigned char);
extern void pq_window_set_item8(unsigned char);
extern void pq_set_scaled_level_table(unsigned char);
extern void pq_set_three_entry_table(int, unsigned char);
extern void pq_block_set_sharpness_field(int, unsigned char);
extern void pq_set_color_matrix_preset(int);

static int channel_index(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/*
 * Select the picture window of a channel and set one of the sixteen picture items in it.
 *
 *   ch    channel 0..3; anything else prints a warning and falls back to channel 0
 *   item  a PQ_ITEM_* number, see the switch (items 14 and above 15 do nothing)
 *   v     the value of the item
 *
 * When the channel's window field (bits 4..7 of record word 0) is WINDOW_NONE (4), nothing is done. Otherwise the
 * window is selected with pq_select_window and the item applied to it.
 *
 * Callers: SetThemeMode, pq_user_apply_sharpness, UserSetProMode, UserSetGameMode.
 */
void pq_api_set_window_item(unsigned char ch, unsigned char item, unsigned char v)
{
    unsigned char index, preset;

    index = channel_index(ch);
    if (index > 3) { dbg_printf("SYS remapping channel OOR\r\n"); index = 0; }
    if (channel_records[index].window == WINDOW_NONE)
        return;
    pq_select_window(channel_records[index].window);
    /* index is 0..3 here, so this test never returns. */
    if (index == 0xff)
        return;
    switch (item) {
    case PQ_ITEM_WINDOW0: pq_window_set_item0(v); break;
    case PQ_ITEM_WINDOW1: pq_window_set_item1(v); break;
    case PQ_ITEM_WINDOW2: pq_window_set_item2(v); break;
    case PQ_ITEM_WINDOW3: pq_window_set_item3(v); break;
    case PQ_ITEM_WINDOW4: pq_window_set_item4(v); break;
    case PQ_ITEM_WINDOW5: pq_window_set_item5(v); break;
    case PQ_ITEM_WINDOW6: pq_window_set_item6(v); break;
    case PQ_ITEM_WINDOW7: pq_window_set_item7(v); break;
    case PQ_ITEM_WINDOW8: pq_window_set_item8(v); break;
    case PQ_ITEM_SCALED_LEVEL_TABLE: pq_set_scaled_level_table(v); break;
    case PQ_ITEM_THREE_ENTRY0: pq_set_three_entry_table(0, v); break;
    case PQ_ITEM_THREE_ENTRY1: pq_set_three_entry_table(1, v); break;
    case PQ_ITEM_THREE_ENTRY2: pq_set_three_entry_table(2, v); break;
    case PQ_ITEM_SHARPNESS: pq_block_set_sharpness_field(8, v); break;
    case PQ_ITEM_COLOR_MATRIX_PRESET:
        /* Presets 0..5 map to themselves; every value above 5 maps to preset 6. */
        switch (v) {
        case 0: preset = 0; break;
        case 1: preset = 1; break;
        case 2: preset = 2; break;
        case 3: preset = 3; break;
        case 4: preset = 4; break;
        case 5: preset = 5; break;
        default: preset = 6; break;
        }
        pq_set_color_matrix_preset(preset & 7);
        break;
    }
}
