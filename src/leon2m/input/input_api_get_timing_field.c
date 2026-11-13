/* input_api_get_timing_field  (FUN_a0145660)
 *
 * Return one field of a channel's measured input timing.
 * Returns: field value
 * Note: Field 0 = line rate (channel record +6, 100 Hz units), 1 = refresh rate (+8, tenths of Hz), 10 =
 *   halfword +0x18. The channel number is not range-checked.
 * Name basis: derived - field id selects a halfword of the channel record: 0 line rate, 1 refresh rate, 7 / 8
 *   width / height and others
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145660 @ 0xa0145660, flags -mcpu=v8 -O3 -g.
 * Source form: the cases are listed in the order of the original: case 23 stands between 21 and 22 (gcc emits the
 * second-to-last case block first, which is where the original has id 23).
 */
/* The channel record (0x78 bytes): fields up to +0x3d, named by offset except the ones that are named elsewhere. */
struct channel_record {
    unsigned int status_word;   /* +0: port in bits 12..15 */
    unsigned short word_0x4;
    unsigned short line_rate;       /* +6, 100 Hz units */
    unsigned short refresh_rate;    /* +8, tenths of Hz */
    unsigned char byte_0x0a, byte_0x0b;
    unsigned short word_0xc, word_0xe, word_0x10, word_0x12, word_0x14, word_0x16;
    unsigned short active_lines;    /* +0x18 */
    unsigned short word_0x1a, word_0x1c, word_0x1e, word_0x20, word_0x22, word_0x24;
    unsigned char byte_0x26, byte_0x27;
    unsigned short word_0x28, word_0x2a, word_0x2c, word_0x2e, word_0x30, word_0x32, word_0x34, word_0x36, word_0x38;
    unsigned char byte_0x3a, byte_0x3b;
    unsigned short mode_id;         /* +0x3c */
    unsigned char rest[0x3a];
};
/* A port record (0x2a bytes), up to the halfword used here. */
struct port_record { unsigned char pad[0x20]; unsigned short word_0x20; unsigned char rest[8]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern unsigned char DAT_a802e222;

/* Channel numbers 0..3 map to themselves; any other number gives -1. */
static int remap(int ch)
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
 * Return one field of the measured input timing of a channel.
 *
 *   channel  channel number 0..3. There is no range check here: another number indexes channel_records with
 *            (unsigned char)-1.
 *   field    which value to return; an unlisted number returns 0xffff.
 *
 * Field numbers and what they read, as halfword offsets of the channel record (word = halfword unless noted):
 *    0 +0x06 line rate (100 Hz units)        1 +0x08 refresh rate (tenths of Hz)
 *    2 halfword +0x20 of the port's record in port_records (the port is bits 12..15 of the record's first word)
 *    3 code from byte +0x0a: 2 gives 1, 4 gives 2, 8 gives 3, any other value 0
 *    4 +0x0e   5 +0x30   6 +0x2e   7 +0x12   8 +0x14   9 +0x16   10 +0x18 active lines   11 +0x1a   12 +0x1e
 *   13 +0x34  14 +0x32  15 +0x1c  16 +0x20  17 +0x2c  18 +0x38  19 +0x36
 *   20 byte +0x26   21 the byte at DAT_a802e222 (not a channel field)   22 byte +0x3a   23 +0x3c (mode id)
 * Fields 7 and 8 are printed together as "n%4dX%4d" by their callers.
 *
 * Called from the panel, FRC, OSD and PC-tool code. SYSAPI_GetPanelParamStruct reads fields 8, 7, 1, 0 and 10;
 * APPGetFRCMode reads fields 1, 0, 7 and 8.
 */
unsigned short input_api_get_timing_field(unsigned char channel, unsigned int field)
{
    struct channel_record *record = &channel_records[(unsigned char)remap(channel)];
    unsigned short value = 0xffff;
    switch (field) {
    case 0: value = record->line_rate; break;
    case 1: value = record->refresh_rate; break;
    case 2: value = port_records[(record->status_word >> 12) & 0xf].word_0x20; break;
    case 3:
        switch (record->byte_0x0a) {
        case 4: value = 2; break;
        case 8: value = 3; break;
        case 2: value = 1; break;
        default: value = 0; break;
        }
        break;
    case 4: value = record->word_0xe; break;
    case 5: value = record->word_0x30; break;
    case 6: value = record->word_0x2e; break;
    case 7: value = record->word_0x12; break;
    case 8: value = record->word_0x14; break;
    case 9: value = record->word_0x16; break;
    case 10: value = record->active_lines; break;
    case 11: value = record->word_0x1a; break;
    case 12: value = record->word_0x1e; break;
    case 13: value = record->word_0x34; break;
    case 14: value = record->word_0x32; break;
    case 15: value = record->word_0x1c; break;
    case 16: value = record->word_0x20; break;
    case 17: value = record->word_0x2c; break;
    case 18: value = record->word_0x38; break;
    case 19: value = record->word_0x36; break;
    case 20: value = record->byte_0x26; break;
    case 21: value = DAT_a802e222; break;
    case 23: value = record->mode_id; break;
    case 22: value = record->byte_0x3a; break;
    }
    return value;
}
