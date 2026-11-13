/* dbg_hdmi_menu_wrapper  (FUN_a00a1e18)
 *
 * Run the HDMI debug menu command.
 * Name basis: derived - forwards its three arguments to DRV_HDMI_DbgMenu
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a1e18 @ 0xa00a1e18-0xa00a1e28 (4 words), flags -mcpu=v8 -Os -g.
 * The call is a tail call: the caller's return address is handed on, so DRV_HDMI_DbgMenu returns straight to
 * this routine's caller. The last word is the nop the compiler places behind such a call sequence.
 */
extern void DRV_HDMI_DbgMenu(unsigned int cmd, unsigned int a, unsigned int b);

/*
 * Pass its three arguments unchanged to DRV_HDMI_DbgMenu.
 * No call instruction targets it. Its address is stored at file offset 0xa4eec, in a table of 36-byte entries
 * {routine address, 32-byte name} ("mww", "hrx21", "maild", "rt", ""), in the entry named "maild".
 */
void dbg_hdmi_menu_wrapper(unsigned int cmd, unsigned int a, unsigned int b)
{
    DRV_HDMI_DbgMenu(cmd, a, b);
}
