/* leon2s FUN_a007f634 @ 0xa007f634 (-mcpu=v8 -Os -g)
 * q = p & 0xff. When the low byte of FUN_a0073520(q) is non-zero, tail-calls DRV_HDMI_Config_BCH(q != 2, 1); otherwise
 * returns. The range includes the ret/restore at 0xa007f668 that the zero branch reaches; GCC computes q ^ 2 before
 * the test (the value of the q != 2 argument).
 */
extern int DRV_HDMI_Config_BCH();
extern int FUN_a0073520();

void FUN_a007f634(unsigned int param_1)
{
    unsigned int uVar1;
    unsigned int uVar2;
    
    uVar2 = param_1 & 0xff;
    uVar1 = FUN_a0073520(uVar2);
    if ((uVar1 & 0xff) == 0) {
        return;
    }
    DRV_HDMI_Config_BCH((uVar2 ^ 2) != 0, 1);
}
