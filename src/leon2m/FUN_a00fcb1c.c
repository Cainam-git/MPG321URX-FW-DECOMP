/* leon2m FUN_a00fcb1c @ 0xa00fcb1c-0xa00fcbec (52 words).
 * Template FUN_a00fca4c: Starts a transfer on registers 0xcf0120xx (or through the hook 0xa802c970) and waits up
 * to 1000 ticks for status bits 0x2e.
 * This function is the same code as FUN_a00fca4c (its source comment explains the details), compiled with
 * other constants (template -> this function):
 * 0x36 -> 0x82
 */
#define REG(a) (*(volatile unsigned int *)(a))
extern void (*_DAT_a802c970)(int, int);
extern unsigned short func_0x4008d588(void);
extern void func_0x4008ced8(void);
extern unsigned short func_0x4008d594(unsigned short);

void FUN_a00fcb1c(void)
{
    unsigned short t;

    REG(0xcf012084) = 0x82;
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
