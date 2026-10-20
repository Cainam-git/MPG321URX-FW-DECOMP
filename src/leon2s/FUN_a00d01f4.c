/*
 * FUN_a00d01f4 (leon2s, 0xa00d01f4-0xa00d0260, 108 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/27.
 * Code facts: 2-bit state field (bits 16..17 of word 0) of the 24-byte record DAT_a8078bb0[ch] = 1
 * (andn/or word RMW), then if FUN_a00cfb20(ch + 8) != 0 the field = 3 (or 0x30000), else sibcall
 * FUN_a00c85b8(ch). Uses the accepted Rec18 bit-field layout of src/leon2s/FUN_a00cd4fc.c.
 * FUN_a00cfb20 takes 1 argument (the draft passed param_2). void. Aids: none.
 */
struct Rec18 { unsigned int hi : 14; unsigned int f16 : 2; unsigned int lo : 16; unsigned char pad[0x14]; };
extern struct Rec18 DAT_a8078bb0[];
extern int FUN_a00cfb20(unsigned int);
extern void FUN_a00c85b8(unsigned int);

void FUN_a00d01f4(unsigned char ch)
{
    DAT_a8078bb0[ch].f16 = 1;
    if (FUN_a00cfb20(ch + 8) != 0) {
        DAT_a8078bb0[ch].f16 = 3;
        return;
    }
    FUN_a00c85b8(ch);
}
