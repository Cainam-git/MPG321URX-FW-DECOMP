/* FUN_a00f6dd8 (leon2m 0xa00f6dd8-0xa00f6e30, 88 bytes), flags -mcpu=v8 -O3 -g.
 * Computes v = c & 0x7f when bit 7 of c is set, otherwise c | 0x80; calls the function pointer _DAT_a802b7b8(1, v)
 * when it is set, otherwise writes v to the word register 0xcf00ef08. Called by FUN_a01471a0. Source form: v = c |
 * 0x80 as default, overridden when bit 7 is set (the counterpart of FUN_a00f6f54).
 */
#define REG (*(volatile unsigned int *)0xcf00ef08)
extern void (*_DAT_a802b7b8)(int, unsigned int);
void FUN_a00f6dd8(unsigned char c)
{
    unsigned char v;

    v = c | 0x80;
    if (c & 0x80)
        v = c & 0x7f;
    if (_DAT_a802b7b8)
        _DAT_a802b7b8(1, v);
    else
        REG = v;
}
