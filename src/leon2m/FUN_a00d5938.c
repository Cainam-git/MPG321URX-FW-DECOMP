/* leon2m FUN_a00d5938 @ 0xa00d5938-0xa00d59d4 (39 words).
 * When bit 14 of word DAT_a802d290+0xa8 is set: FUN_a01479ec(1). Then for port 1, 2 or 3:
 * FUN_a0149978(port, byte DAT_a802d290+0x20 / +0x21 / +0x22); other ports do nothing more.
 */
struct G290 {
    unsigned char p000[0x20];
    unsigned char b020;
    unsigned char b021;
    unsigned char b022;
    unsigned char p023[0xa8 - 0x23];
    unsigned int w0a8;
};
extern struct G290 DAT_a802d290;
extern void FUN_a01479ec(unsigned char);
extern void FUN_a0149978(unsigned char ch, unsigned char p);

void FUN_a00d5938(unsigned char port)
{
    if (DAT_a802d290.w0a8 & 0x4000)
        FUN_a01479ec(1);
    switch (port) {
    case 1:
        FUN_a0149978(1, DAT_a802d290.b020);
        break;
    case 2:
        FUN_a0149978(2, DAT_a802d290.b021);
        break;
    case 3:
        FUN_a0149978(3, DAT_a802d290.b022);
        break;
    }
}
