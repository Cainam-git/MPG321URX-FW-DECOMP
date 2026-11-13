/* nvram_api_store_by_selector  (FUN_a0145360)
 *
 * Store what the argument selects: 0 part record, 1 device settings, 2 one channel's mode row.
 * Note: 2 stores the mode row of the first channel in state 0xC whose port record byte +9 is not 5; 3 does
 *   nothing; other values write both records. Writes the EEPROM.
 * Name basis: derived - switch on the argument: nvram_write_part_record, nvram_write_settings_record,
 *   nvram_store_mode_row
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0145360 @ 0xa0145360, flags -mcpu=v8 -O3 -g -msoft-float (plain -O3 -g gives 81.11: the loop hoists
 * the sethi of the printed text into a register, while the firmware builds it again in the delay slot of the 'bgu').
 * Required forms: the switch (gcc decision tree: 1 first, ble, 2, 3), the struct records and -msoft-float.
 * The argument of nvram_store_mode_row is the array channel_records_mode_row (channel_records_mode_row, the channel records
 * seen from +6, same 0x78 stride): the firmware loads that address as a constant of its own (sethi|or) and adds
 * i * 0x78. remap_channel is the same static function as in sys_api_get_channel_flag28.
 */
/* Channel record, only word 0 (state bits 28..31, port bits 12..15). */
struct channel_record { unsigned int status_word; unsigned short half_0x04, half_0x06; unsigned char rest[0x70]; };
/* Port record (0x2A bytes), only byte +9. */
struct port_record { unsigned char before[9]; unsigned char byte_0x09; unsigned char rest[0x20]; };
extern struct channel_record channel_records[4];
struct mode_row_slot { unsigned char byte[0x78]; };
extern struct mode_row_slot channel_records_mode_row[4];
extern struct port_record port_records[];
extern unsigned char device_settings[], part_record[];
extern int dbg_printf();
extern unsigned char sys_get_channel_state(int);
extern void nvram_write_settings_record(void *, unsigned char);
extern void nvram_write_part_record(void *, unsigned char);
extern void nvram_store_mode_row(void *);

#define CH_STATE_WAITMODECHANGE 12      /* channel state 0xC */
#define CHANNELS 4

/* Channel number 0..3 of a channel, or -1 for anything else. */
static int remap_channel(int ch)
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
 * Save records to the EEPROM. Writes the EEPROM.
 *
 *   mode  0: the part record (nvram_write_part_record)
 *         1: the device settings record (nvram_write_settings_record)
 *         2: the mode row of the first suitable channel (see below)
 *         3: nothing
 *         anything else: both the part record and the device settings record
 *
 * Mode 2: the channels 0..3 are looked at in order. A channel in state 12 (waiting for a mode change) is
 * checked through the port it shows (bits 12..15 of its status word): if byte +9 of that port's record is not 5,
 * the mode row of that channel (channel record from +6) is stored with nvram_store_mode_row and the search
 * stops; if it is 5 the search goes on with the next channel. A channel number outside 0..3 would print
 * "SYS remapping channel OOR" and use channel 0; with the channel numbers used here this cannot happen.
 * Called with 0, 1 and 2 by the application's timer task (one value per pending-store flag), and with 1 from
 * many settings code paths.
 */
void nvram_api_store_by_selector(unsigned char mode)
{
    unsigned char i, ch;

    switch (mode) {
    case 0:
        nvram_write_part_record(part_record, 0);
        break;
    case 1:
        nvram_write_settings_record(device_settings, 0);
        break;
    case 2:
        for (i = 0; i < CHANNELS; i++) {
            if (sys_get_channel_state(i) == CH_STATE_WAITMODECHANGE) {
                ch = remap_channel(i);
                if (ch > 3) {
                    dbg_printf("SYS remapping channel OOR\r\n");
                    ch = 0;
                }
                if (port_records[(channel_records[ch].status_word >> 12) & 0xf].byte_0x09 != 5) {
                    nvram_store_mode_row(&channel_records_mode_row[i]);
                    break;
                }
            }
        }
        break;
    case 3:
        break;
    default:
        nvram_write_part_record(part_record, 0);
        nvram_write_settings_record(device_settings, 0);
        break;
    }
}
