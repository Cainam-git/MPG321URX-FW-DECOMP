/* leon2s DRV_HDMI21_PHY_PICDR_Reset @ 0xa0080244 (-mcpu=v8 -Os -g)
 */
extern unsigned int _DAT_a8078634;
extern void DRV_HDMI21_PHY_INV_PICDR_Reset(unsigned char param_1);
extern int FUN_a0073044(const char *, ...);
extern void FUN_a007f9d0(unsigned char param_1);
extern unsigned char DAT_a807d680[];

static const char fn_[] = "DRV_HDMI21_PHY_PICDR_Reset";   /* function name kept as a separate .rodata object by the firmware */

void DRV_HDMI21_PHY_PICDR_Reset(unsigned char param_1)
{
    unsigned char uVar2;
    unsigned char iVar1;
    
    if ((_DAT_a8078634 & 0x800) != 0) {
        FUN_a0073044("[HDMI21]: %s\n\n", fn_);
    }
    
    uVar2 = param_1 & 0xff;
    iVar1 = 0;
    if (uVar2 == 2) {

    } else if (uVar2 == 3) {
        iVar1 = 1;
    } else {
        return;
    }
    
    if (DAT_a807d680[iVar1 * 0xb0 + 2] > 3) {
        FUN_a007f9d0(param_1);
        return;
    } else {
        DRV_HDMI21_PHY_INV_PICDR_Reset(param_1);
        return;
    }
}
