/* leon2s DRV_HDMI21_RXDetect_FSM_LTS_4 @ 0xa00983ec (-mcpu=v8 -Os -g)
 * k = p1 & 0xff. When word k of the table 0xA807D648 differs from word +0x30 of record k of the 0xB0-byte records
 * at 0xA807D680, passes the format at 0xA00678C8 ("[HDMI21]: ESC[1m\n=%s=\nESC[m") and the function name to
 * FUN_a0073044 when bit 11 of word 0xA8078634 is set, and copies the word into +0x30. Then stores 7 in word k of
 * 0xA807D648. Returns 0.
 * Source form: Ghidra's type and symbol names are kept.
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
