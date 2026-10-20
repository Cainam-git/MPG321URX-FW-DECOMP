/* FUN_a00cf6bc (leon2s, 0xa00cf6bc-0xa00cf7b4, 62 words). Flags -mcpu=v8 -Os -g.
 * void (u8 port). Word 0 of the 24-byte record port of DAT_a8078bb0: 2-bit field bits 16..17 = 1;
 * func_0xa0f96400(0, 0x90, 0x69493, 0, buf); FUN_a00c87e8(port, 0xc, 0x8000); 16 bytes buf[i] =
 * FUN_a00c7770(port, 1) (u16 i); func_0xa0f963d4(0, 0x80, 0x693e0, 0xf, buf); if bit 21 of the record word
 * is set, the bits 16..17 field = 2.
 * The record word is a big-endian bit-field (bit 21 flag tested by 'srl 0x15; btst 1'; the mask form gives
 * sethi/btst); the two ROM calls return int (void prototypes reorder the argument set-up).
 */
struct st {
    unsigned int hi : 10;
    unsigned int f21 : 1;
    unsigned int mid : 3;
    unsigned int mode : 2;
    unsigned int lo : 16;
};
struct rec { struct st w; unsigned int pad[5]; };
extern struct rec DAT_a8078bb0[];
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern int func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int func_0xa0f96400(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);

void FUN_a00cf6bc(unsigned char port)
{
    unsigned char buf[16];
    unsigned short i;

    DAT_a8078bb0[port].w.mode = 1;
    func_0xa0f96400(0, 0x90, 0x69493, 0, buf);
    FUN_a00c87e8(port, 0xc, 0x8000);
    i = 0;
    do {
        buf[i] = FUN_a00c7770(port, 1);
        i++;
    } while (i <= 0xf);
    func_0xa0f963d4(0, 0x80, 0x693e0, 0xf, buf);
    if (DAT_a8078bb0[port].w.f21)
        DAT_a8078bb0[port].w.mode = 2;
}
