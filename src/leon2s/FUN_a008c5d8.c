/* FUN_a008c5d8 (leon2s 0xa008c5d8-0xa008c6f8, 288 bytes, including the ret/restore tail), flags -mcpu=v8 -Os -g.
 * sel 4 gives idx 0, sel 6 gives idx 1; any other sel returns. v = FUN_a008c538(idx). When (DAT_a8078b30 == 1)
 * differs from (28000 < v < 36000): calls FUN_a008ae18(idx), clears bit 6 of halfword +0x12 of the 20-byte
 * record ARR_a807a824[idx + 4], and then for v < 36000 sets DAT_a8078b30 to 1 and calls FUN_a00a71fc(port,
 * 2, 8, 0) and FUN_a00a71fc(port, 1, 0x40, 0); otherwise clears DAT_a8078b30 and calls FUN_a00a71fc(port,
 * 2, 8, 8) and FUN_a00a71fc(port, 1, 0x40, 0x40).
 * Source form: the comparison result goes through a byte flag chg (0, set to 1 when the two tests differ).
 */
struct Rec { unsigned char pad[0x12]; unsigned short h12; };
extern struct Rec ARR_a807a824[];
extern unsigned char DAT_a8078b30;
extern unsigned int FUN_a008c538(unsigned char);
extern void FUN_a008ae18(unsigned char);
extern void FUN_a00a71fc(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a008c5d8(unsigned char sel, unsigned char port)
{
    unsigned char idx;
    unsigned char chg = 0;
    unsigned int v;

    if (sel == 4)
        idx = 0;
    else if (sel == 6)
        idx = 1;
    else
        return;
    v = FUN_a008c538(idx);
    if ((DAT_a8078b30 == 1) != (v > 28000 && v < 36000))
        chg = 1;
    if (chg) {
        FUN_a008ae18(idx);
        ARR_a807a824[idx + 4].h12 &= ~0x40;
        if (v < 36000) {
            DAT_a8078b30 = 1;
            FUN_a00a71fc(port, 2, 8, 0);
            FUN_a00a71fc(port, 1, 0x40, 0);
        } else {
            DAT_a8078b30 = 0;
            FUN_a00a71fc(port, 2, 8, 8);
            FUN_a00a71fc(port, 1, 0x40, 0x40);
        }
    }
}
