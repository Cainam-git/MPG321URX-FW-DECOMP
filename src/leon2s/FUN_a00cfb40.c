/* FUN_a00cfb40 (leon2s, 0xa00cfb40-0xa00cfd38, 504 bytes), flags -mcpu=v8 -Os -g.
 * port = (u8)param_1; DAT_a8078bb0 is an array of 24-byte records (word 0 = state word, word 4 at offset 16).
 * Sets bits 16..17 of the state word of record port to 01. If FUN_a00cfb20(0xd) > 0x32, sets them to 11 and
 * returns. Otherwise two func_0xa0f96400(0, 0x90, 0x69473 / 0x69483, 0xf, buf) reads are copied (16 bytes each)
 * into DAT_a807cd88[0..15] and DAT_a807cd88[16..31]; FUN_a00c87e8(port, 0xe, 0x8000); 32 bytes
 * DAT_a807d088[i] = (u8)FUN_a00c7770(port, 1). At the first i where d088[i] != cd88[i], bits 16..17 := 00 when
 * word 4 of the record is 0xffffff, else := 10, and the compare loop stops. u16 loop counters.
 * Same layout as FUN_a00cea60.
 */
struct Rec {
    unsigned int w;
    unsigned int _4[3];
    unsigned int f16;
    unsigned int _20;
};
extern struct Rec DAT_a8078bb0[];
extern unsigned char DAT_a807d088[];
extern unsigned char DAT_a807cd88[];
extern int FUN_a00c7770(unsigned char, int);
extern void FUN_a00c87e8(unsigned char, int, unsigned short);
extern unsigned int FUN_a00cfb20(int);
extern int func_0xa0f96400(int, int, int, int, void *);

void FUN_a00cfb40(unsigned char param_1)
{
    unsigned char uVar5;
    unsigned short uVar4;
    unsigned char local_18[16];

    uVar5 = param_1 & 0xff;
    DAT_a8078bb0[uVar5].w =
        (DAT_a8078bb0[uVar5].w & 0xfffcffff) | 0x10000;

    if (FUN_a00cfb20(0xd) > 0x32) {
        DAT_a8078bb0[uVar5].w |= 0x30000;
        return;
    }

    func_0xa0f96400(0, 0x90, 0x69473, 0xf, local_18);

    uVar4 = 0;
    do {
        DAT_a807cd88[uVar4] = local_18[uVar4];
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);

    func_0xa0f96400(0, 0x90, 0x69483, 0xf, local_18);

    uVar4 = 0;
    do {
        DAT_a807cd88[uVar4 + 0x10] = local_18[uVar4];
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);

    FUN_a00c87e8(uVar5, 0xe, 0x8000);

    uVar4 = 0;
    do {
        DAT_a807d088[uVar4] = (unsigned char)FUN_a00c7770(uVar5, 1);
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x20);

    uVar4 = 0;
    do {
        if (DAT_a807d088[uVar4] != DAT_a807cd88[uVar4]) {
            if (DAT_a8078bb0[uVar5].f16 == 0xffffff)
                DAT_a8078bb0[uVar5].w &= ~0x30000;
            else
                DAT_a8078bb0[uVar5].w =
                    (DAT_a8078bb0[uVar5].w & 0xfffcffff) | 0x20000;
            break;
        }
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x20);
}
