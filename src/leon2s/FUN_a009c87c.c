/* FUN_a009c87c (leon2s 0xa009c87c-0xa009c8ac, 48 bytes, leaf with sibling call), flags -mcpu=v8 -Os -g.
 * Clears bytes +4, +1 and +0x2d of the 400-byte port record ARR_a807d7e0[port] and calls
 * DRV_HDMI_Set_AudStatus(port, 0) (sibling call). Called by Jay_EQ_End.
 * Source form: the three clears are written in the order +1, +0x2d, +4; the scheduler moves the +4 store first,
 * as in the firmware.
 */
extern unsigned char ARR_a807d7e0[];
extern void DRV_HDMI_Set_AudStatus(unsigned char, unsigned char);

void FUN_a009c87c(unsigned char port)
{
    unsigned char *rec = ARR_a807d7e0 + port * 400;

    rec[1] = 0;
    rec[0x2d] = 0;
    rec[4] = 0;
    DRV_HDMI_Set_AudStatus(port, 0);
}
