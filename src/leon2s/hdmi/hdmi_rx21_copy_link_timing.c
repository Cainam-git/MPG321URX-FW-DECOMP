/* hdmi_rx21_copy_link_timing  (FUN_a006e2c4)
 *
 * Copy and print the link timing of an HDMI 2.1 port into its port record.
 * Name basis: proven - prints 'usLINKHtotal(%d)' .. 'ucPHYStatus(%d)'; doubles values in one link mode
 *
 * Matching notes
 * --------------
 * leon2s hdmi_rx21_copy_link_timing (FUN_a006e2c4) @ 0xa006e2c4-0xa006e430 (364 bytes), flags -mcpu=v8 -Os
 * -g (section default).
 * Source forms the exact build depends on:
 *  - the receiver record pointer is taken from a local pointer to the array (base before the multiply);
 *  - three arms (cvtem_present == 1, colour-format call, else) with the plain copy written twice;
 *  - the vertical values are read through the array again, not through rec.
 */
/* Port record (20 bytes, input_port_records[2 + receiver]); the fields of LINK_STANDBY_2's record. */
struct port_record {
    unsigned char state, byte_0x1;
    unsigned short htotal, vtotal, hactive, vactive, pixel_clock;  /* printed usLINKHtotal .. usLINKClk */
    unsigned char colour_space;                     /* +0xC: 'ucClrSpace' */
    unsigned char published_flags;                  /* +0xD: 'ucPHYStatus' */
    unsigned char byte_0xe;
    unsigned char publish;                          /* +0xF: 1 = send the record to the main processor */
    unsigned char changed;                          /* +0x10 */
    unsigned char step;                             /* +0x11 */
    union {
        unsigned short word;
        unsigned char colour_depth;                 /* high byte: 'ucColordepth' */
    } flags;
};
/* HDMI 2.1 receiver record (400 bytes, hdmi_rx21_input_records); the fields used here. */
struct rx21_record {
    unsigned char bytes_0x0[0x19];
    unsigned char colour_depth;                     /* +0x19 */
    unsigned short htotal, vtotal, hactive, vactive;    /* +0x1A..+0x20: the mode info's timing */
    unsigned char bytes_0x22[0x2d - 0x22];
    unsigned char cvtem_present;                    /* +0x2D */
    unsigned char bytes_0x2e[4];
    unsigned short pixel_clock;                     /* +0x32: in 0.1 MHz */
    unsigned char rest[400 - 0x34];
};
extern struct rx21_record hdmi_rx21_input_records[];
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_update_port_status_flags(struct port_record *, unsigned char, struct rx21_record *);
extern int hdmi_rx21_is_format_420(unsigned int);

/*
 * Copies the timing of an HDMI 2.1 receiver from its receiver record into the port record and prints it
 * ("usLINKHtotal" .. "ucPHYStatus"). In order: colour depth, the status flags
 * (hdmi_rx21_update_port_status_flags), then the horizontal values and the clock:
 *  - copied as they are when the record's cvtem_present is 1, or when hdmi_rx21_is_format_420 returns 0;
 *  - doubled (htotal, hactive, and the clock after its division) otherwise.
 * The vertical total and active lines are copied as they are, the clock is the record's pixel clock
 * divided by 10. At the end publish is set to 1 (the record is to be sent to the main processor).
 *   out:  the port record
 *   port: HDMI 2.1 receiver 0 or 1
 */
void hdmi_rx21_copy_link_timing(struct port_record *out, unsigned char port)
{
    struct rx21_record *t = hdmi_rx21_input_records;
    struct rx21_record *rec = t + port;

    out->flags.colour_depth = rec->colour_depth;
    hdmi_rx21_update_port_status_flags(out, port, rec);
    if (rec->cvtem_present == 1) {
        out->htotal = rec->htotal;
        out->hactive = rec->hactive;
        out->pixel_clock = rec->pixel_clock / 10;
    } else if ((unsigned char)hdmi_rx21_is_format_420(port)) {
        out->htotal = rec->htotal * 2;
        out->hactive = rec->hactive * 2;
        out->pixel_clock = rec->pixel_clock / 10 * 2;
    } else {
        out->htotal = rec->htotal;
        out->hactive = rec->hactive;
        out->pixel_clock = rec->pixel_clock / 10;
    }
    out->vtotal = hdmi_rx21_input_records[port].vtotal;
    out->vactive = hdmi_rx21_input_records[port].vactive;
    dbg_printf("usLINKHtotal(%d)\r\n", out->htotal);
    dbg_printf("usLINKVtotal(%d)\r\n", out->vtotal);
    dbg_printf("usLINKHrtlDE(%d)\r\n", out->hactive);
    dbg_printf("usLINKVrtlDE(%d)\r\n", out->vactive);
    dbg_printf("usLINKClk(%d)\r\n", out->pixel_clock);
    dbg_printf("ucClrSpace(%d)\r\n", out->colour_space);
    dbg_printf("ucColordepth(%d)\r\n", out->flags.colour_depth);
    dbg_printf("ucPHYStatus(%d)\r\n\r\n", out->published_flags);
    out->publish = 1;
}
