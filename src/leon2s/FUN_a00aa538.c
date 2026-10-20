/* FUN_a00aa538 (leon2s 0xa00aa538-0xa00aa5e8, 176 bytes), flags -mcpu=v8 -Os -g.
 * on non-zero: port 0 writes 0xb0 to hardware register 0xcf012ad8, 1 to 0xcf012adc and sets bit 0 of 0xcf012ad0;
 * other ports write 0xf to 0xcf012a94, 0xb0 to 0xcf012a98, 3 to 0xcf012a9c and set bit 0 of 0xcf012a90.
 * on zero: clears bit 0 of 0xcf012ad0 (port 0) or 0xcf012a90 (other ports).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00aa538(unsigned char port, unsigned char on)
{
    if (on != 0) {
        if (port == 0) {
            R(0xcf012ad8) = 0xb0;
            R(0xcf012adc) = 1;
            R(0xcf012ad0) |= 1;
        } else {
            R(0xcf012a94) = 0xf;
            R(0xcf012a98) = 0xb0;
            R(0xcf012a9c) = 3;
            R(0xcf012a90) |= 1;
        }
    } else {
        if (port == 0)
            R(0xcf012ad0) &= ~1;
        else
            R(0xcf012a90) &= ~1;
    }
}
