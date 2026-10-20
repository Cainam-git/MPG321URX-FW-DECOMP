/* leon2s FUN_a0091204 @ 0xa0091204  MATCH (-mcpu=v8 -Os -g)
 * Fills the 0xB0-byte entry (param_1 & 0xFF) of the table at 0xA807D3E4: the u16 fields +0x96..+0xA4 from eight
 * getters FUN_a0090010..FUN_a0090180, byte +0x8F = bit 0 and +0x90 = bit 1 of FUN_a00a657c(port, 0x55), +0x8D = bit 4
 * of FUN_a00a657c(port, 0x30), u16 +0x94 = FUN_a00911bc, u16 +0x92 = FUN_a00910ec, byte +0x8E = FUN_a0090dec. The
 * eight getters take one argument ('mov %i0, %o0').
 */
extern unsigned short FUN_a0090010(unsigned int);
extern unsigned short FUN_a0090078(unsigned int);
extern unsigned short FUN_a0090098(unsigned int);
extern unsigned short FUN_a0090100(unsigned int);
extern unsigned short FUN_a0090120(unsigned int);
extern unsigned short FUN_a0090140(unsigned int);
extern unsigned short FUN_a0090160(unsigned int);
extern unsigned short FUN_a0090180(unsigned int);
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern unsigned short FUN_a00911bc(unsigned int);
extern unsigned short FUN_a00910ec(unsigned int);
extern int FUN_a0090dec(unsigned char);

void FUN_a0091204(unsigned int param_1)
{
    unsigned char *tbl;
    unsigned char *base;
    unsigned char v;

    param_1 = param_1 & 0xff;
    tbl = (unsigned char *)0xa807d3e4;
    base = tbl + param_1 * 0xb0;

    *(unsigned short *)(base + 0x98) = FUN_a0090010(param_1);
    *(unsigned short *)(base + 0x96) = FUN_a0090098(param_1);
    *(unsigned short *)(base + 0x9a) = FUN_a0090120(param_1);
    *(unsigned short *)(base + 0x9c) = FUN_a0090140(param_1);
    *(unsigned short *)(base + 0xa0) = FUN_a0090078(param_1);
    *(unsigned short *)(base + 0x9e) = FUN_a0090100(param_1);
    *(unsigned short *)(base + 0xa2) = FUN_a0090160(param_1);
    *(unsigned short *)(base + 0xa4) = FUN_a0090180(param_1);

    v = FUN_a00a657c(param_1, 0x55);
    base[0x8f] = (unsigned char)(v & 1);

    v = FUN_a00a657c(param_1, 0x55);
    base[0x90] = (unsigned char)((v & 2) >> 1);

    v = FUN_a00a657c(param_1, 0x30);
    base[0x8d] = (unsigned char)((v & 0x10) >> 4);

    *(unsigned short *)(base + 0x94) = FUN_a00911bc(param_1);
    *(unsigned short *)(base + 0x92) = FUN_a00910ec(param_1);
    base[0x8e] = (unsigned char)FUN_a0090dec(param_1);
}
