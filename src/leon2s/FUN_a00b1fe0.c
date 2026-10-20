/* FUN_a00b1fe0 (leon2s 0xa00b1fe0-0xa00b2064, 132 bytes), flags -mcpu=v8 -Os -g.
 * When on is non-zero writes 0x10 / 0xffef / 0xfffd / 0xffff to the registers 0x9f100090 / 0x9f120028 /
 * 0x9f120044 / 0x9f120038 and then 0x9f100090 / 0x9f120028 / 0x9f120044 once more; otherwise writes 0 to
 * 0x9f100090 and 0xffff to 0x9f120028, 0x9f120044 and 0x9f120038.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00b1fe0(unsigned char on)
{
    if (on != 0) {
        R(0x9f100090) = 0x10;
        R(0x9f120028) = 0xffef;
        R(0x9f120044) = 0xfffd;
        R(0x9f120038) = 0xffff;
        R(0x9f100090) = 0x10;
        R(0x9f120028) = 0xffef;
        R(0x9f120044) = 0xfffd;
    } else {
        R(0x9f100090) = 0;
        R(0x9f120028) = 0xffff;
        R(0x9f120044) = 0xffff;
        R(0x9f120038) = 0xffff;
    }
}
