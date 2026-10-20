/* leon2m FUN_a00d2994 @ 0xa00d2994 (-mcpu=v8 -O2 -g)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
typedef unsigned char uchar;
typedef unsigned short ushort;

struct reg_block {
    uchar pad[0x15];      // 0x00-0x14
    uchar byte_15;        // 0x15
    ushort half_16;       // 0x16
};

extern struct reg_block DAT_a802d274;
extern int FUN_a014aed0();

int FUN_a00d2994(void)
{
    DAT_a802d274.byte_15 = 0;
    DAT_a802d274.half_16 = 0;
    FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    return 0xe0;
}
