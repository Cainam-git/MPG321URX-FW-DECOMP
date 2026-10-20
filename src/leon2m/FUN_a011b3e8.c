/* FUN_a011b3e8: writes the byte v to register 0xcf01178c (sel == 0) or 0xcf0117a0 (sel != 0), then runs a
 * 160-iteration nop delay loop. Caller: FUN_a014648c.
 * The register is picked with an if (sel == 0) / else of two stores (that arm order gives the firmware branch); the delay loop is the documented
 * 'for (i = 0; i < 0xa0; i++) __asm__("nop");' form.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011b3e8(unsigned char sel, unsigned char v)
{
    int i;

    if (sel == 0)
        R(0xcf01178c) = v;
    else
        R(0xcf0117a0) = v;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}
