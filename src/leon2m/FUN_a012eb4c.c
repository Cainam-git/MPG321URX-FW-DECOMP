/* leon2m FUN_a012eb4c @ 0xa012eb4c
 * Reads one byte from settings storage and returns it. The location comes from the RAM settings record at
 * 0xA802E1A0: dev = byte +0x34, addr = 16-bit field +0x35..0x36, sel = byte +0x37. The byte is read with
 * FUN_a0140360(dev, addr + fga_off(0), 1, &mark) into a cleared local, where fga_off(sub) is
 * ((sel <= 1 ? 0x120 : 0x240) & 0x360) + sub (the same static helper as in FUN_a012cfac). Called by FUN_a0149268.
 * Source form: fga_off as an inlined static helper with if/else, so the & 0x360 stays in the code.
 */
struct FgaLoc { unsigned char dev; unsigned int addr : 16; unsigned char sel; };
struct Rec1a0 { unsigned char a[0x34]; struct FgaLoc fga; unsigned char rest[0x18]; };
extern struct Rec1a0 DAT_a802e1a0;
extern void FUN_a0140360(unsigned char, unsigned short, unsigned short, void *);

static unsigned short fga_off(unsigned short sub)
{
    unsigned short o;
    if (DAT_a802e1a0.fga.sel <= 1)
        o = 0x120;
    else
        o = 0x240;
    return (o & 0x360) + sub;
}

unsigned char FUN_a012eb4c(void)
{
    unsigned char mark = 0;

    FUN_a0140360(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0), 1, &mark);
    return mark;
}
