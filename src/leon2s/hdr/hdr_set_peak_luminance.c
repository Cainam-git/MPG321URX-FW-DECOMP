/* hdr_set_peak_luminance  (FUN_a00d3eb0)
 *
 * Store the panel's peak luminance, limited to 10000 (1000 when 0 is given).
 * Name basis: derived - word at 0xA80779DC; set by a command from the main processor
 *
 * Matching notes
 * --------------
 * FUN_a00d3eb0 (leon2s 0xa00d3eb0-0xa00d3ef0, 64 bytes, leaf), flags -mcpu=v8 -Os -g.
 * It lies in the code range 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c
 * (byte tables and '[HDR]' format strings).
 */
extern unsigned short hdr_peak_luminance;

#define HDR_LUMINANCE_LIMIT   10000     /* largest peak luminance stored */
#define HDR_LUMINANCE_DEFAULT 1000      /* stored for a value of 0 */

/*
 * Store the peak luminance for the HDR code: 10000 for a value above 10000, 1000 for 0, else the value itself.
 * The mailbox command IPC_CMD_SET_HDR_PEAK_LUMINANCE calls it with the low half of the message data.
 */
void hdr_set_peak_luminance(unsigned short luminance)
{
    if (luminance > HDR_LUMINANCE_LIMIT)
        hdr_peak_luminance = HDR_LUMINANCE_LIMIT;
    else if (luminance == 0)
        hdr_peak_luminance = HDR_LUMINANCE_DEFAULT;
    else
        hdr_peak_luminance = luminance;
}
