/* DRV_HDMI_Setup_IntIRQ_Events (leon2s, 0xa0096344-0xa0096428, 57 words). Flags -mcpu=v8 -Os -g.
 Code facts: void (port, enable). If bit 2 of _DAT_a8078634: print '[MODEDET]: Port%c ... Enable = %d' with (char)(port+'A') and enable&0xff.
 If (u8)enable == 1: FUN_a00a0b98(port, n, 1) for n = 0x10, 0x15, 0x12, 0xd, 0x11; q = word +4 of the 0x34-byte record port of ARR_a807db00;
 the 400-byte record port of ARR_a807d7e0 gets +0xc = q[+0x40], +0x10 = q[+0x44], byte +0x16 = 0, +0x14 = 4, +8 = 0.
 Fixes vs draft: BEHAVIOUR (the draft read an uninitialised pointer for +0xc; both words come from q), void (draft returned 0),
 a local record pointer r for the [r+4] load, store source order 0x16/0x14/8 (0x14/0x16/8 is also exact). Aids: none.
 */
extern unsigned int _DAT_a8078634;
extern unsigned char ARR_a807db00[];
extern unsigned char ARR_a807d7e0[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a0b98(unsigned int, unsigned int, unsigned int);

void DRV_HDMI_Setup_IntIRQ_Events(unsigned int param_1, unsigned int param_2)
{
    unsigned int port;
    unsigned char *r;
    unsigned char *q;
    unsigned char *rec;

    port = param_1 & 0xff;
    if ((_DAT_a8078634 & 4) != 0) {
        FUN_a0073044("[MODEDET]: Port%c DRV_HDMI_Setup_IntIRQ_Events Enable = %d\n",
                     (char)(param_1 + 0x41), param_2 & 0xff);
    }
    if (((unsigned char)param_2) == 1) {
        FUN_a00a0b98(port, 0x10, 1);
        FUN_a00a0b98(port, 0x15, 1);
        FUN_a00a0b98(port, 0x12, 1);
        FUN_a00a0b98(port, 0xd, 1);
        FUN_a00a0b98(port, 0x11, 1);
        r = ARR_a807db00 + port * 0x34;
        q = *(unsigned char **)(r + 4);
        rec = ARR_a807d7e0 + port * 0x190;
        *(unsigned int *)(rec + 0xc) = *(unsigned int *)(q + 0x40);
        *(unsigned int *)(rec + 0x10) = *(unsigned int *)(q + 0x44);
        rec[0x16] = 0;
        rec[0x14] = 4;
        rec[8] = 0;
    }
}
