/* DRV_HDMI_Set_AudStatus (leon2s 0xa009c7e8-0xa009c87c, 148 bytes), flags -mcpu=v8 -Os -g.
 * When bit 2 of DAT_a8078634 is set, prints "[MODEDET]: Port%c %s Audio Stable = %d\n" with 'A' + port,
 * the function name and on. on == 1: sets byte +5 of the 400-byte port record ARR_a807d7e0[port] to 1 and
 * calls FUN_a009c718(port, record + 0x38); otherwise clears byte +5. Ends with the sibling call
 * FUN_a009c794(port, on == 0). Called by FUN_a009c87c.
 * Source form: port is a raw unsigned int parameter cast to unsigned char at each use; the record is indexed
 * directly in each access.
 */
extern unsigned int DAT_a8078634;
extern unsigned char ARR_a807d7e0[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a009c718(unsigned int, unsigned int *);
extern void FUN_a009c794(unsigned char, unsigned char);
static const char fn_[] = "DRV_HDMI_Set_AudStatus";

void DRV_HDMI_Set_AudStatus(unsigned int port, unsigned char on)
{
    if (DAT_a8078634 & 4)
        FUN_a0073044("[MODEDET]: Port%c %s Audio Stable = %d\n", (char)(port + 0x41), fn_, on);
    if (on == 1) {
        ARR_a807d7e0[(unsigned char)port * 400 + 5] = 1;
        FUN_a009c718((unsigned char)port, (unsigned int *)(ARR_a807d7e0 + (unsigned char)port * 400 + 0x38));
    } else
        ARR_a807d7e0[(unsigned char)port * 400 + 5] = 0;
    FUN_a009c794(port, on == 0);
}
