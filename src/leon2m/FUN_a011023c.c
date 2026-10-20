/* leon2m FUN_a011023c @ 0xa011023c  layer update strobe. BYTE-EXACT at -mcpu=v8 -O3 -g.
 *
 * FUN_a011023c(idx): when DAT_a8027a88 == 1, writes the update bit for layer idx to register 0xD003B000
 * (idx 0..6 -> bit idx, idx 7 -> 0x100, idx 8 -> 0x1FF = all layers) and waits until the register reads 0 or
 * 100 ticks of func_0x4008d588 (FUN_a002d588) have passed. Inlined by FUN_a01107b8 (window split per channel).
 * The record and callee declarations below are shared with that caller's source and are not used here.
 */
struct Ctx {
    unsigned int w0;             /* +0x00 base address */
    unsigned char pad4[8];
    unsigned short wc, we;       /* +0x0c, +0x0e */
    unsigned char pad10[4];
    unsigned short x, w;         /* +0x14, +0x16 */
    unsigned int w18:16, w1a:16;     /* +0x18, +0x1a */
    unsigned char pad1c[4];
    union { struct { unsigned short w20, w22; } h; struct { unsigned int w20:16, w22:16; } b; } u20; /* +0x20, +0x22 */
    unsigned char bpp, b25, b26; /* +0x24.. */
    unsigned char pad27[0x17];
    unsigned char b3e, pad3f;    /* +0x3e */
};
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08; };
extern struct PanelParam *DAT_a802d6a4;
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *DAT_0019aed8[], *DAT_0019aecc[];
extern unsigned char DAT_a802d700, DAT_a8027a88;
extern void FUN_a010baf4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned int);
extern void FUN_a010bee4(unsigned char, unsigned char, unsigned short, unsigned short);
extern unsigned short func_0x4008d588(void);
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011023c(unsigned char idx)
{
    unsigned short t0;

    if (DAT_a8027a88 == 1) {
        if (idx == 8)
            R(0xd003b000) = 0x1ff;
        else if (idx == 0)
            R(0xd003b000) = 1;
        else if (idx == 1)
            R(0xd003b000) = 2;
        else if (idx == 2)
            R(0xd003b000) = 4;
        else if (idx == 3)
            R(0xd003b000) = 8;
        else if (idx == 4)
            R(0xd003b000) = 0x10;
        else if (idx == 5)
            R(0xd003b000) = 0x20;
        else if (idx == 6)
            R(0xd003b000) = 0x40;
        else if (idx == 7)
            R(0xd003b000) = 0x100;
        t0 = func_0x4008d588();
        while (R(0xd003b000) != 0 && (unsigned short)(func_0x4008d588() - t0) < 100)
            ;
    }
}

