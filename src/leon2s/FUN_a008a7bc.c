/* FUN_a008a7bc (leon2s 0xa008a7bc-0xa008a824, 104 bytes), flags -mcpu=v8 -Os -g.
 * Writes 0 to the seven hardware registers 0xcf01125c-0xcf011274 (one word apart), then writes 0x88 to the same
 * seven registers, in ascending order both times.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a008a7bc(void)
{
    R(0xcf01125c) = 0;
    R(0xcf011260) = 0;
    R(0xcf011264) = 0;
    R(0xcf011268) = 0;
    R(0xcf01126c) = 0;
    R(0xcf011270) = 0;
    R(0xcf011274) = 0;
    R(0xcf01125c) = 0x88;
    R(0xcf011260) = 0x88;
    R(0xcf011264) = 0x88;
    R(0xcf011268) = 0x88;
    R(0xcf01126c) = 0x88;
    R(0xcf011270) = 0x88;
    R(0xcf011274) = 0x88;
}
