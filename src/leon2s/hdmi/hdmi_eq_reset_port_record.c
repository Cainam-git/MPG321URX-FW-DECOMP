/* hdmi_eq_reset_port_record  (bch_en_flag)
 *
 * Reset the EQ scan record of a port; mode 0 also toggles the BCH enable flag.
 *   port: PHY
 *   mode: 0 toggle, 3 partial, other full
 * Name basis: derived - prints '[EQ]: Port%c bch_en_flag = %d'; 0x898-byte EQ records; the old label was the
 *   field name
 *
 * Matching notes
 * --------------
 * bch_en_flag (leon2s 0xa0075190-0xa0075278, 232 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Source form: switch on mode; the record is a byte row of a two-dimensional array indexed by an unsigned
 * char copy of the port (a structure form schedules the first stores differently).
 */
extern unsigned char hdmi_eq_port_records[][0x898];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void *lib_memset(void *, int, unsigned int);

#define HDMI_MSG_EQ_FLOW 2      /* dbg_hdmi_message_flags bit 1: the "[EQ]" lines */
#define EQ_RECORD_BYTES 0x898   /* size of the EQ scan record of one port */
#define EQ_BCH_EN_FLAG 0x29     /* record byte +0x29: the field the firmware prints as bch_en_flag */
#define EQ_CHANNEL_OK 0x31      /* record bytes +0x31..+0x33: channel_ok[3] */
#define EQ_MODE_TOGGLE 0        /* mode values */
#define EQ_MODE_CHANNELS 3

/*
 * Reset the EQ scan record of a port (hdmi_eq_port_records, 0x898 bytes per port).
 *   mode 0: clear the first three bytes (eq_table_index[3]) and the three channel_ok bytes, and flip the byte
 *           at +0x29 between 0 and 1; prints "[EQ]: Port<A..> bch_en_flag = <value>" when the EQ debug
 *           messages are on.
 *   mode 3: clear only the three channel_ok bytes at +0x31.
 *   other:  clear the whole record.
 *   port: PHY
 *   mode: as above
 */
void hdmi_eq_reset_port_record(unsigned int port, int mode)
{
    unsigned char row = port;

    switch (mode) {
    case EQ_MODE_TOGGLE:
        *(unsigned short *)hdmi_eq_port_records[row] = 0;
        hdmi_eq_port_records[row][2] = 0;
        lib_memset(&hdmi_eq_port_records[row][EQ_CHANNEL_OK], 0, 3);
        if (hdmi_eq_port_records[row][EQ_BCH_EN_FLAG])
            hdmi_eq_port_records[row][EQ_BCH_EN_FLAG] = 0;
        else
            hdmi_eq_port_records[row][EQ_BCH_EN_FLAG] = 1;
        if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
            dbg_printf("[EQ]: Port%c bch_en_flag = %d\n\n", (char)(port + 0x41), hdmi_eq_port_records[row][EQ_BCH_EN_FLAG]);
        break;
    case EQ_MODE_CHANNELS:
        lib_memset(&hdmi_eq_port_records[row][EQ_CHANNEL_OK], 0, 3);
        break;
    default:
        lib_memset(hdmi_eq_port_records[row], 0, EQ_RECORD_BYTES);
        break;
    }
}
