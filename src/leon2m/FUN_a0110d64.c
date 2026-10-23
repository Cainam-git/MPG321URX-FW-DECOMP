/* leon2m FUN_a0110d64 @ 0xa0110d64-0xa0110f44 (480 bytes). Flags -mcpu=v8 -O3 -g.
 *
 * void FUN_a0110d64(t, mode): t points to {u16 n (+0), u8 b2 (+2), u32 *data (+4)}. Writes t->b2 to 0xD0030404 and
 * 0xD0038404 and 0x14 to 0xD0030410/0xD0038410. mode 0..3 writes 0x03210000 / 0x10320000 / 0x21030000 /
 * 0x32100000 to 0xD0030420 and 0xD0038420 (other modes write nothing). When DAT_a8027a88 == 1 it writes 0x40 to
 * 0xD003B000 and waits until that register reads 0 or 100 ticks of func_0x4008d588 have passed (as FUN_a011023c).
 * Then copies n / 4 words of data to 0xD0030408 and 0xD0038408 (each word read twice), writes 0x32100000 to
 * 0xD0030420/0xD0038420 and repeats the 0x40 write and wait when DAT_a8027a88 == 1. No direct callers in asm/leon2m.
 * Source form: each switch case writes both registers with its constant (the firmware's per-case address set-up
 *   and shared store tail); the loop limit n / 4 is kept in a local.
 */
#define R(a) (*(volatile unsigned int *)(a))
struct Tbl { unsigned short n; unsigned char b2; unsigned char pad3; unsigned int *data; };
extern unsigned char DAT_a8027a88;
extern unsigned short func_0x4008d588(void);

void FUN_a0110d64(struct Tbl *t, unsigned char mode)
{
    unsigned int i, n;
    unsigned short t0;

    R(0xd0030404) = t->b2;
    R(0xd0038404) = t->b2;
    R(0xd0030410) = 0x14;
    R(0xd0038410) = 0x14;
    switch (mode) {
    case 0: R(0xd0030420) = 0x3210000; R(0xd0038420) = 0x3210000; break;
    case 1: R(0xd0030420) = 0x10320000; R(0xd0038420) = 0x10320000; break;
    case 2: R(0xd0030420) = 0x21030000; R(0xd0038420) = 0x21030000; break;
    case 3: R(0xd0030420) = 0x32100000; R(0xd0038420) = 0x32100000; break;
    }
    if (DAT_a8027a88 == 1) {
        R(0xd003b000) = 0x40;
        t0 = func_0x4008d588();
        while (R(0xd003b000) != 0 && (unsigned short)(func_0x4008d588() - t0) < 100)
            ;
    }
    n = t->n >> 2;
    for (i = 0; i < n; i++) {
        R(0xd0030408) = t->data[i];
        R(0xd0038408) = t->data[i];
    }
    R(0xd0030420) = 0x32100000;
    R(0xd0038420) = 0x32100000;
    if (DAT_a8027a88 == 1) {
        R(0xd003b000) = 0x40;
        t0 = func_0x4008d588();
        while (R(0xd003b000) != 0 && (unsigned short)(func_0x4008d588() - t0) < 100)
            ;
    }
}
