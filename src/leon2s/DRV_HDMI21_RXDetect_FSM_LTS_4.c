/* leon2s DRV_HDMI21_RXDetect_FSM_LTS_4 @ 0xa00983ec (-mcpu=v8 -Os -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned int DAT_a8078634;              /* 0xa8078634 */
extern unsigned int ARR_a807d648[];            /* 0xa807d648 */

struct S_a807d680 {
    unsigned char pad0[0x30];
    unsigned int field_30;
    unsigned char pad1[0x7c];
};
extern struct S_a807d680 ARR_a807d680[];       /* 0xa807d680 */

extern char DAT_a00678c8[];                    /* 0xa00678c8 */
extern int FUN_a0073044(const char *, ...);    /* 0xa0073044 */

int DRV_HDMI21_RXDetect_FSM_LTS_4(unsigned char param1, unsigned int param2)
{
    param1 &= 0xff;

    if (ARR_a807d648[param1] != ARR_a807d680[param1].field_30) {
        if (DAT_a8078634 & 0x800) {
            FUN_a0073044(DAT_a00678c8, "DRV_HDMI21_RXDetect_FSM_LTS_4");
        }
        ARR_a807d680[param1].field_30 = ARR_a807d648[param1];
    }

    ARR_a807d648[param1] = 7;
    return 0;
}
