/* FUN_a00cea60 (leon2s, 0xa00cea60-0xa00cec18, 440 bytes, 110 words).
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: port = (u8)param_1; bits 16..17 of the word at DAT_a8078bb0 + port*24 := 01;
 * FUN_a00c87e8(port, 9, 0x8000); 32 bytes DAT_a807d088[i] = (u8)FUN_a00c7770(port, 1); two
 * func_0xa0f96400(0, 0x90, 0x692f8 / 0x69308, 0xf, buf) reads, each copied (16 bytes) into
 * DAT_a807cd88[0..15] and DAT_a807cd88[16..31]; then if any of the 32 bytes of d088 differs from
 * cd88, bits 16..17 of that word := 10 (and the compare loop stops). u16 loop counters.
 * Fix vs draft: the second copy goes to DAT_a807cd88[i + 0x10] (the same 32-byte table: fw reloads
 * the cd88 base and stores at +0x10); the draft used a separate symbol DAT_a807cd98. Aids: none.
 */
extern unsigned char DAT_a8078bb0[];
extern unsigned char DAT_a807d088[];
extern int FUN_a00c7770(unsigned char, int);
extern void FUN_a00c87e8(unsigned char, int, unsigned short);
extern int func_0xa0f96400(int, int, int, int, void *);

extern unsigned char DAT_a807cd88[];

void FUN_a00cea60(unsigned char param_1)
{
    unsigned char uVar5;
    unsigned short uVar4;
    unsigned char local_18[16];

    uVar5 = param_1 & 0xff;
    *(unsigned int *)(DAT_a8078bb0 + uVar5 * 24) =
        (*(unsigned int *)(DAT_a8078bb0 + uVar5 * 24) & 0xfffcffff) | 0x10000;

    FUN_a00c87e8(uVar5, 9, 0x8000);

    uVar4 = 0;
    do {
        DAT_a807d088[uVar4] = (unsigned char)FUN_a00c7770(uVar5, 1);
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x20);

    func_0xa0f96400(0, 0x90, 0x692f8, 0xf, local_18);

    uVar4 = 0;
    do {
        DAT_a807cd88[uVar4] = local_18[uVar4];
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);

    func_0xa0f96400(0, 0x90, 0x69308, 0xf, local_18);

    uVar4 = 0;
    do {
        DAT_a807cd88[uVar4 + 0x10] = local_18[uVar4];
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);

    uVar4 = 0;
    do {
        if (DAT_a807d088[uVar4] != DAT_a807cd88[uVar4]) {
            *(unsigned int *)(DAT_a8078bb0 + uVar5 * 24) =
                (*(unsigned int *)(DAT_a8078bb0 + uVar5 * 24) & 0xfffcffff) | 0x20000;
            break;
        }
        uVar4 = uVar4 + 1;
    } while (uVar4 < 0x20);
}
