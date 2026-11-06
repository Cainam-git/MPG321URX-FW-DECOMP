/* leon2s FUN_a0096204 @ 0xa0096204-0xa00962ec (58 words), flags -mcpu=v8 -Os -g -msoft-float.
 * For i = 0 and 1, stores word k (k = 0..12) of the 0x34-byte record DAT_a807db00[i] as
 * (i << 12) + 0xce009000 + k * 0x100, i.e. 0xce009000 .. 0xce009c00 for i = 0 and 0xce00a000 .. 0xce00ac00 for i = 1.
 * Source form: the 13 words are separate named members r0..r12, stored in ascending order. With an array
 * member the word-0 store ([base + i * 0x34]) is ordered against the other twelve stores and is scheduled
 * early; as separate members the stores are independent, which gives the firmware's register pressure and
 * spill choices. -msoft-float gives the firmware's set of constants moved out of the loop.
 */
struct port_regs {
    unsigned int r0;
    unsigned int r1;
    unsigned int r2;
    unsigned int r3;
    unsigned int r4;
    unsigned int r5;
    unsigned int r6;
    unsigned int r7;
    unsigned int r8;
    unsigned int r9;
    unsigned int r10;
    unsigned int r11;
    unsigned int r12;
};
extern struct port_regs DAT_a807db00[];

void FUN_a0096204(void)
{
    unsigned char i;

    for (i = 0; i < 2; i++) {
        DAT_a807db00[i].r0 = (i << 12) + 0xce009000;
        DAT_a807db00[i].r1 = (i << 12) + 0xce009100;
        DAT_a807db00[i].r2 = (i << 12) + 0xce009200;
        DAT_a807db00[i].r3 = (i << 12) + 0xce009300;
        DAT_a807db00[i].r4 = (i << 12) + 0xce009400;
        DAT_a807db00[i].r5 = (i << 12) + 0xce009500;
        DAT_a807db00[i].r6 = (i << 12) + 0xce009600;
        DAT_a807db00[i].r7 = (i << 12) + 0xce009700;
        DAT_a807db00[i].r8 = (i << 12) + 0xce009800;
        DAT_a807db00[i].r9 = (i << 12) + 0xce009900;
        DAT_a807db00[i].r10 = (i << 12) + 0xce009a00;
        DAT_a807db00[i].r11 = (i << 12) + 0xce009b00;
        DAT_a807db00[i].r12 = (i << 12) + 0xce009c00;
    }
}
