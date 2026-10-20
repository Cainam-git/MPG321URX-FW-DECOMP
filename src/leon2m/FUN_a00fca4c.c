/* leon2m FUN_a00fca4c @ 0xa00fca4c-0xa00fcb1c (52 words).
 * Writes 0x36 to hardware register 0xcf012084 and 0x2e to 0xcf012034. When the hook word 0xa802c970 (set by
 * FUN_a00fc30c) is non-zero it calls hook(0xf, 1); otherwise it writes 0xf to 0xcf012080 and 1 to 0xcf012040. Then
 * t = func_0x4008d588() and, while none of the bits 0x2e of 0xcf012034 is set, func_0x4008ced8() runs until
 * func_0x4008d594(t) exceeds 1000. Finally 0xcf012034 is read and 0x2e is written to it.
 */
#define REG(a) (*(volatile unsigned int *)(a))
extern void (*_DAT_a802c970)(int, int);
extern unsigned short func_0x4008d588(void);
extern void func_0x4008ced8(void);
extern unsigned short func_0x4008d594(unsigned short);

void FUN_a00fca4c(void)
{
    unsigned short t;

    REG(0xcf012084) = 0x36;
    REG(0xcf012034) = 0x2e;
    if (_DAT_a802c970 != 0)
        _DAT_a802c970(0xf, 1);
    else {
        REG(0xcf012080) = 0xf;
        REG(0xcf012040) = 1;
    }
    t = func_0x4008d588();
    while (!(REG(0xcf012034) & 0x2e)) {
        func_0x4008ced8();
        if (func_0x4008d594(t) > 1000)
            break;
    }
    REG(0xcf012034);
    REG(0xcf012034) = 0x2e;
}
