/* MODEDET_handler (leon2s 0xa009c8b0-0xa009c9b4, 260 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * Only for port p 0 or 1 (k = 2 or 3; other ports return). Returns when word +0 of the 0x18-byte record
 * DAT_a807d650[p] is 0 or byte +1 of the 0x18-byte record ARR_a807cc64[k] is 1. Otherwise clears that word,
 * prints "[MODEDET]: Port%c EQ Not Ready Force Back To StandBy\n" ('A' + p) when bit 2 of DAT_a8078634 is
 * set and, when byte +1 of the 400-byte port record ARR_a807d7e0[p] is not 0, calls FUN_a00a0b10(p, 0) and
 * DRV_HDMI_Setup_IntIRQ_Events(p, 0) and prints "[MODEDET]: Port%c Sync Lost Alarm and Disable Interrupt\n"
 * under the same bit. Ends with the sibling call FUN_a009c87c(p).
 */
struct eq_state {
    unsigned int st;
    unsigned char cnt;
    unsigned char _5[0x18 - 5];
};
struct sel_rec {
    unsigned char b0;
    unsigned char b1;
    unsigned char _2[0x18 - 2];
};
extern struct eq_state DAT_a807d650[];
extern struct sel_rec ARR_a807cc64[];
extern unsigned char ARR_a807d7e0[];
extern unsigned int DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a0b10(unsigned char, unsigned char);
extern void DRV_HDMI_Setup_IntIRQ_Events(unsigned int, unsigned int);
extern void FUN_a009c87c(unsigned char);

void MODEDET_handler(unsigned char p)
{
    unsigned char k;

    if (p == 0)
        k = 2;
    else if (p == 1)
        k = 3;
    else
        return;
    if (DAT_a807d650[p].st == 0)
        return;
    if (ARR_a807cc64[k].b1 == 1)
        return;
    DAT_a807d650[p].st = 0;
    if (DAT_a8078634 & 4)
        FUN_a0073044("[MODEDET]: Port%c EQ Not Ready Force Back To StandBy\n", (char)(p + 0x41));
    if (ARR_a807d7e0[p * 400 + 1]) {
        FUN_a00a0b10(p, 0);
        DRV_HDMI_Setup_IntIRQ_Events(p, 0);
        if (DAT_a8078634 & 4)
            FUN_a0073044("[MODEDET]: Port%c Sync Lost Alarm and Disable Interrupt\n", (char)(p + 0x41));
    }
    FUN_a009c87c(p);
}
