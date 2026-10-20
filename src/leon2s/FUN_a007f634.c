/* leon2s FUN_a007f634 @ 0xa007f634  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: 
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
        return uVar2 ^ 2;
    }
    return DRV_HDMI_Config_BCH((uVar2 ^ 2) != 0, 1);
}
