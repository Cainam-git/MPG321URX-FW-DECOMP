/* leon2s DRV_HDMI_IF_Enable_RxPort @ 0xa00a16cc  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): firmware format string; function name as static const char[]; callees by Ghidra name
 */
extern int FUN_a0073044(const char *, ...);          /* trace printf */
extern void FUN_a00a2c94(unsigned int, unsigned int); /* register write */
static const char fn_[] = "DRV_HDMI_IF_Enable_RxPort";   /* function name kept as a separate .rodata object by the firmware */

unsigned int DRV_HDMI_IF_Enable_RxPort(unsigned int a, unsigned int b)
{
    if (a == 2) {
        FUN_a0073044("[VERBOSE]: %s: Port%c \n", fn_, 0x43);
        return 0x16;
    } else {
        FUN_a00a2c94(a & 0xff, b & 0xff);
        return 0;
    }
}
