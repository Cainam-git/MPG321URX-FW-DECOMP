/* leon2s FUN_a0062434 @ 0xa0062434-0xa00624b4 (32 words), flags -mcpu=v8 -Os -g.
 * Hardware registers: 0x9f120048 &= ~0x10; 0x9f120028 &= ~0x20; 0x9f100090 |= 0x20. Word +0x20 of the
 * record DAT_a8078a70 (0xa8078a90) = (u16)func_0x9f1c3ef0() * 10; FUN_a0061534(hardware address 0xd0013ffc,
 * 0xff); tail call FUN_a0062308() with no arguments (it never reads %i0..). void.
 * The word is +0x20 of a record at 0xa8078a70 (the firmware stores to [rec + 0x20]; an absolute symbol at
 * 0xa8078a90 folds to its own %lo). volatile only on the 0x9f.../0xd0... hardware registers.
 */
struct R70 { unsigned char pad[0x20]; unsigned int w20; };
extern struct R70 DAT_a8078a70;
extern void FUN_a0061534(volatile unsigned int *, unsigned int);
extern void FUN_a0062308(void);
extern unsigned short func_0x9f1c3ef0(void);

#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0062434(void)
{
    R(0x9f120048) &= ~0x10;
    R(0x9f120028) &= ~0x20;
    R(0x9f100090) |= 0x20;
    DAT_a8078a70.w20 = func_0x9f1c3ef0() * 10;
    FUN_a0061534((volatile unsigned int *)0xd0013ffc, 0xff);
    FUN_a0062308();
}
