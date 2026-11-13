/* ddc_get_first_pending_channel  (FUN_CODE_d90a)
 *
 * Return the lowest DDC/CI channel with a message waiting, 0xFF if none.
 * Returns: channel 0..7 or 0xFF
 * Name basis: derived - lowest set bit of 0xA0F3; the report builder ipc_fill_report_record sends that
 *   channel's 0x3C-byte row as type 4
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d90a @ 0xd90a (32 B)  Options: OPTIMIZE(7,SPEED) (also level 8).
 * Source form: the loop is 'do { } while (++i != 8)', compiled as 'INC R5; MOV A,R5; CJNE A,#08H'.
 */
#define DDC_NO_CHANNEL 0xff

extern unsigned char ddc_get_pending_channels(void);

/*
 * Return the number (0..7) of the lowest DDC/CI channel that has a message waiting (lowest set bit of the pending
 * mask), or 0xFF when none has. Called by ipc_fill_report_record, which reports that channel to the main processor.
 */
unsigned char ddc_get_first_pending_channel(void)
{
    unsigned char pending, channel, first;

    pending = ddc_get_pending_channels();
    first = DDC_NO_CHANNEL;
    channel = 0;
    do {
        if ((pending >> channel) & 1) {
            first = channel;
            break;
        }
    } while (++channel != 8);
    return first;
}
