/* FUN_a006370c (leon2s 0xa006370c-0xa00638a0, 404 bytes), flags -mcpu=v8 -Os -g.
 * Returns unless hardware register 0xcf03c80c reads 0x99, bit DAT_a8078c37 of DAT_a8078c36 is clear, the byte read
 * by the function pointer DAT_a807cd74(DAT_a8078a38, DAT_a8076274) has a bit of DAT_a8076272 set and the reads
 * at DAT_a807626e, DAT_a807626c and DAT_a807626a give 0x8b, 0x84 and 0x90. Then stores FUN_a00b2064() in
 * DAT_a8078a3c and 1 in DAT_a8078a3a. Returns when the read at DAT_a8076270 equals DAT_a8078a40[0] and the low
 * byte of FUN_a0061528(0xd0013ffc) is 0xaa; otherwise calls FUN_a0061d60(), copies the 0x8a-byte record
 * DAT_a8078aa0 to a local and writes FUN_a0061534(0xd0013ffc, DAT_a8078a39 << 16 | 0xaa) when
 * FUN_a0062fc8(DAT_a8078a90, &copy) is non-zero, else FUN_a0061534(0xd0013ffc, 0xff).
 * The local copy is a structure assignment; GCC emits it as a call of the firmware memcpy FUN_a00b15d8 (declared
 * with that link name). volatile only on the hardware register.
 */
struct Cal { unsigned char b0, b1; unsigned short h[0x2b]; unsigned char b58, b59; unsigned short w[9]; unsigned char pad[0x88 - 0x6c]; unsigned short h88; };
extern struct Cal DAT_a8078aa0;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char DAT_a8078c36;
extern unsigned char DAT_a8078c37;
extern unsigned char DAT_a8078a38;
extern unsigned char DAT_a8078a39;
extern unsigned char DAT_a8078a3a;
extern unsigned int DAT_a8078a3c;
extern unsigned char DAT_a8078a40[];
extern unsigned int DAT_a8078a90;
extern unsigned short DAT_a807626a;
extern unsigned short DAT_a807626c;
extern unsigned short DAT_a807626e;
extern unsigned short DAT_a8076270;
extern unsigned char DAT_a8076272;
extern unsigned short DAT_a8076274;
extern unsigned char (*DAT_a807cd74)(unsigned char, unsigned short);
extern unsigned int FUN_a0061528(volatile unsigned int *);
extern void FUN_a0061534(volatile unsigned int *, unsigned int);
extern unsigned char FUN_a0062fc8(unsigned int, struct Cal *);
extern unsigned int FUN_a00b2064(void);
extern void FUN_a0061d60(void);

void FUN_a006370c(void)
{
    struct Cal c;

    if (R(0xcf03c80c) != 0x99)
        return;
    if ((DAT_a8078c36 >> DAT_a8078c37) & 1)
        return;
    if (!(DAT_a807cd74(DAT_a8078a38, DAT_a8076274) & DAT_a8076272))
        return;
    if (DAT_a807cd74(DAT_a8078a38, DAT_a807626e) != 0x8b)
        return;
    if (DAT_a807cd74(DAT_a8078a38, DAT_a807626c) != 0x84)
        return;
    if (DAT_a807cd74(DAT_a8078a38, DAT_a807626a) != 0x90)
        return;
    DAT_a8078a3c = FUN_a00b2064();
    DAT_a8078a3a = 1;
    if (DAT_a807cd74(DAT_a8078a38, DAT_a8076270) == DAT_a8078a40[0]
        && (unsigned char)FUN_a0061528((volatile unsigned int *)0xd0013ffc) == 0xaa)
        return;
    FUN_a0061d60();
    c = DAT_a8078aa0;
    if (FUN_a0062fc8(DAT_a8078a90, &c))
        FUN_a0061534((volatile unsigned int *)0xd0013ffc, DAT_a8078a39 << 16 | 0xaa);
    else
        FUN_a0061534((volatile unsigned int *)0xd0013ffc, 0xff);
}
