/* DRV_HDMI_IF_Disconnect (leon2s 0xa00a1b08-0xa00a1b58, 80 bytes), flags -mcpu=v8 -Os -g.
 * Port 2 is rejected: prints "[VERBOSE]: %s: Port%c \n" with the function name and 'C' and returns 0x16.
 * Any other port: clears byte +3 of the 400-byte port record ARR_a807d7e0[port], calls FUN_a00a1a80()
 * and returns 0. Same source form as DRV_HDMI_IF_Enable_RxPort (function-name string as a separate
 * read-only object).
 */
extern unsigned char ARR_a807d7e0[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a1a80(void);
static const char fn_[] = "DRV_HDMI_IF_Disconnect";

unsigned int DRV_HDMI_IF_Disconnect(unsigned int a)
{
    if (a == 2) {
        FUN_a0073044("[VERBOSE]: %s: Port%c \n", fn_, 0x43);
        return 0x16;
    } else {
        ARR_a807d7e0[a * 0x190 + 3] = 0;
        FUN_a00a1a80();
        return 0;
    }
}
