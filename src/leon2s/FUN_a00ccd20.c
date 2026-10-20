/* leon2s FUN_a00ccd20 @ 0xa00ccd20-0xa00ccdb4 (148 bytes, 37 words)
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: void (u8 port). FUN_a00ccad4(port). The DAT_a8078bb0[port] st:2 bit-field (bits 16..17 of word 0)
 * is set to 1. r = (u8)FUN_a00c966c(port). When r == 0: st = 3 (a plain or 0x30000). Otherwise FUN_a00c8a1c(port, 0)
 * runs, and st = 2 when r == 0x22 (FUN_a00c966c returns 0, 0x14 or 0x22, src/leon2s/FUN_a00c966c.c).
 * BEHAVIOUR fixes against the draft: FUN_a00c966c takes the port, and the function is void. No aids.
 */
struct Rec24 {
    unsigned int top:4;
    unsigned int cnt:4;
    unsigned int mid:6;
    unsigned int st:2;
    unsigned int low:16;
    unsigned char b4[20];
};
extern struct Rec24 DAT_a8078bb0[];
extern void FUN_a00ccad4(unsigned char);
extern unsigned int FUN_a00c966c(unsigned char);
extern void FUN_a00c8a1c(unsigned char, int);

void FUN_a00ccd20(unsigned char port)
{
    unsigned char r;

    FUN_a00ccad4(port);
    DAT_a8078bb0[port].st = 1;
    r = FUN_a00c966c(port);
    if (r == 0) {
        DAT_a8078bb0[port].st = 3;
    } else {
        FUN_a00c8a1c(port, 0);
        if (r == 0x22)
            DAT_a8078bb0[port].st = 2;
    }
}
