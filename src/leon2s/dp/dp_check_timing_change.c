/* dp_check_timing_change  (FUN_a006e990)
 *
 * Read the DP link timing, compare it with the saved values and report a mode change.
 * Returns: 1 when the mode changed or is invalid
 * Name basis: proven - prints 'bForceModeChange', 'usLINKHtotal', 'Color Depth Changed from %d to %d', 'Slice
 *   Number Changed'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006e990 @ 0xa006e990-0xa006ed40 (944 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the saved values are a local struct (saved_timing, in this field order) and the comparisons read them
 *    through a pointer to it (saved) that is set after changed = 0;
 *  - the colour depth result is kept as unsigned int and copied into an unsigned char before the compare;
 *  - the slice counts are a two-byte local array indexed by port, initialised to zero;
 *  - the clock range test is the single unsigned compare (unsigned short)(clock - 0x14) > 0xd34;
 *  - the same port_record layout as dp_run_link_state, with the union at +0x12.
 */

/* Port record (20 bytes, input_port_records); fields as in dp_run_link_state. */
struct port_record {
    unsigned char state, byte_0x1;
    unsigned short htotal, vtotal, hactive, vactive, pixel_clock;  /* usLINKHtotal .. usLINKClk */
    unsigned char colour_space, published_flags, byte_0xe, publish, changed, step;
    union {
        unsigned short word;
        unsigned char colour_depth;                 /* high byte: bits per colour */
        struct {
            unsigned short hi : 11;
            unsigned short force_mode_change : 1;   /* bit 4: 'bForceModeChange' */
            unsigned short lo : 4;
        } bits;
    } flags;
};

/* The record's values at entry, kept for the comparisons. */
struct saved_timing { unsigned short hactive, vactive, htotal, vtotal, pixel_clock; unsigned char published_flags; };

#define PORT_FLAG_DSC           0x02    /* published_flags bit 1, printed as 'ucPHYStatus _DPDSCen' */

#define TIMING_MIN_INVALID      9       /* a size or total of 9 or less makes the timing invalid */
#define PIXEL_CLOCK_MIN         0x14    /* valid clock range as printed: '<%d~%d>' */
#define PIXEL_CLOCK_MAX         0xD48

/* Differences that count as a mode change. */
#define HACTIVE_TOLERANCE       2
#define VACTIVE_TOLERANCE       1
#define HTOTAL_TOLERANCE        4
#define CLOCK_TOLERANCE_HIGH    0xF     /* when the old clock is above CLOCK_TOLERANCE_LIMIT */
#define CLOCK_TOLERANCE_LOW     5
#define CLOCK_TOLERANCE_LIMIT   0x32

extern unsigned char dp_saved_slice_values[];
extern int dbg_printf(char *, ...);
extern unsigned short dp_get_hactive(unsigned int);
extern unsigned short dp_get_vactive(unsigned int);
extern unsigned short dp_read_reg90_word(unsigned int);
extern unsigned short dp_read_reg92_word(unsigned int);
extern unsigned int dp_get_color_depth(unsigned int);
extern unsigned short dp_calc_pixel_clock(unsigned char);
extern void dp_update_port_status_flags(struct port_record *, unsigned char);
extern unsigned char dp_read_slice_count(unsigned char);
extern int abs(int);

/*
 * Read the timing of a DisplayPort input again and tell whether its mode changed.
 *
 *   rec   the input's port record; it receives the new values
 *   port  DisplayPort input 0 or 1
 *
 * Returns 1 when the mode changed or the new timing is not usable, else 0. Called by dp_run_link_state while the
 * link is LINK_STABLE (settle and check steps) and LINK_READY; a 1 starts the settle time of LINK_STABLE again.
 *
 * Phases:
 *   1. Save the record's timing and published flags; read the new values (hactive, vactive, htotal, vtotal,
 *      colour depth, pixel clock) and refresh the published flags.
 *   2. Hard reasons, each printed and returned at once, without storing the new values: the force flag
 *      (bForceModeChange, cleared here), a size or total of 9 or less, a clock outside 0x14..0xD48, a changed
 *      slice count ('Slice Number Changed', the new count is kept in dp_saved_slice_values).
 *   3. Soft reasons, which only set the result: a changed colour depth (stored at once), hactive / vactive /
 *      htotal off by more than 2 / 1 / 4, the clock off by more than 0xF (old clock above 0x32) or 5.
 *      vtotal is stored but not compared.
 *   4. Store the new values; a changed DSC bit of the published flags is a reason too.
 *   5. On a change print the new timing.
 */
unsigned char dp_check_timing_change(struct port_record *rec, unsigned char port)
{
    unsigned char slice[2] = {0, 0};
    struct saved_timing old;
    struct saved_timing *saved;
    unsigned short hactive, vactive, htotal, vtotal, clock;
    unsigned int depth;
    unsigned char changed;
    unsigned char new_depth;

    /* 1. Old values, then the new readings. */
    old.htotal = rec->htotal;
    old.vtotal = rec->vtotal;
    old.hactive = rec->hactive;
    old.vactive = rec->vactive;
    old.pixel_clock = rec->pixel_clock;
    old.published_flags = rec->published_flags;
    hactive = dp_get_hactive(port);
    vactive = dp_get_vactive(port);
    htotal = dp_read_reg90_word(port);
    vtotal = dp_read_reg92_word(port);
    depth = dp_get_color_depth(port);
    clock = dp_calc_pixel_clock(port);
    dp_update_port_status_flags(rec, port);
    changed = 0;
    saved = &old;

    /* 2. Reasons that end the check at once. */
    if (rec->flags.bits.force_mode_change) {
        dbg_printf("bForceModeChange  %d\r\n", rec->flags.bits.force_mode_change);
        rec->flags.bits.force_mode_change = 0;
        return 1;
    }
    if (hactive <= TIMING_MIN_INVALID) {
        dbg_printf("usLINKHrtlDE  %d\r\n", hactive);
        return 1;
    }
    if (vactive <= TIMING_MIN_INVALID) {
        dbg_printf("usLINKVrtlDE  %d\r\n", vactive);
        return 1;
    }
    if (htotal <= TIMING_MIN_INVALID) {
        dbg_printf("usLINKHtotal  %d\r\n", htotal);
        return 1;
    }
    if (vtotal <= TIMING_MIN_INVALID) {
        dbg_printf("usLINKVtotal  %d\r\n", vtotal);
        return 1;
    }
    /* Outside PIXEL_CLOCK_MIN..PIXEL_CLOCK_MAX. */
    if ((unsigned short)(clock - PIXEL_CLOCK_MIN) > 0xd34) {
        dbg_printf("usLINKClk  %d <%d~%d>\r\n", clock, PIXEL_CLOCK_MIN, PIXEL_CLOCK_MAX);
        return 1;
    }
    slice[port] = dp_read_slice_count(port);
    if (slice[port] != dp_saved_slice_values[port]) {
        dbg_printf("Link%d Slice Number Changed from %d to %d\r\n", port, dp_saved_slice_values[port], slice[port]);
        dp_saved_slice_values[port] = slice[port];
        return 1;
    }

    /* 3. Differences against the saved values. */
    new_depth = depth;
    if (new_depth != rec->flags.colour_depth) {
        dbg_printf("Color Depth Changed from %d to %d\r\n", rec->flags.colour_depth, new_depth);
        rec->flags.colour_depth = new_depth;
        changed = 1;
    }
    if (abs(hactive - saved->hactive) > HACTIVE_TOLERANCE) {
        dbg_printf("usLINKHrtlDE %d != %d\r\n", hactive, saved->hactive);
        changed = 1;
    }
    if (abs(vactive - saved->vactive) > VACTIVE_TOLERANCE) {
        dbg_printf("usLINKVrtlDE %d != %d\r\n", vactive, saved->vactive);
        changed = 1;
    }
    if (abs(htotal - saved->htotal) > HTOTAL_TOLERANCE) {
        dbg_printf("usLINKHtotal %d != %d\r\n", htotal, saved->htotal);
        changed = 1;
    }
    /* A larger clock allows a larger difference; this reason is not printed. */
    if (saved->pixel_clock > CLOCK_TOLERANCE_LIMIT) {
        if (abs(clock - saved->pixel_clock) > CLOCK_TOLERANCE_HIGH)
            changed = 1;
    } else {
        if (abs(clock - saved->pixel_clock) > CLOCK_TOLERANCE_LOW)
            changed = 1;
    }

    /* 4. Keep the new values. */
    rec->hactive = hactive;
    rec->vactive = vactive;
    rec->htotal = htotal;
    rec->vtotal = vtotal;
    rec->pixel_clock = clock;
    if ((rec->published_flags & PORT_FLAG_DSC) != (saved->published_flags & PORT_FLAG_DSC)) {
        dbg_printf("ucPHYStatus _DPDSCen %02x != %02x\r\n", rec->published_flags, saved->published_flags);
        changed = 1;
    }

    /* 5. Report. */
    if (changed == 1) {
        dbg_printf("\n ======= DP %d ModeChange   =======\r\n", port);
        dbg_printf("DP(%d) usLINKHtotal %d\r\n", port, rec->htotal);
        dbg_printf("DP(%d) usLINKVtotal %d\r\n", port, rec->vtotal);
        dbg_printf("DP(%d) usLINKHrtlDE %d\r\n", port, rec->hactive);
        dbg_printf("DP(%d) usLINKVrtlDE %d\r\n", port, rec->vactive);
        dbg_printf("DP(%d) usLINKClk %d\r\n\r\n", port, rec->pixel_clock);
    }
    return changed;
}
