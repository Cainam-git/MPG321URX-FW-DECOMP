/* FUN_a0085830 (leon2s 0xa0085830-0xa0085888, 88 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Maps mode 0 / 1 / 3 / other to 6 / 0xa / 0x1e / 0x14 and stores the result into byte 0 of DAT_a807cd68 when
 * port is 0, otherwise into byte 0 of DAT_a807cd00.
 * Both byte arrays are volatile, as in FUN_a0085888 and FUN_a00858cc: the firmware keeps every access to them out
 * of branch delay slots, which GCC does only for volatile objects.
 */
extern volatile unsigned char DAT_a807cd00[];
extern volatile unsigned char DAT_a807cd68[];

void FUN_a0085830(unsigned char port, unsigned char mode)
{
    unsigned char v;

    switch (mode) {
    case 0: v = 6; break;
    case 1: v = 0xa; break;
    case 3: v = 0x1e; break;
    default: v = 0x14; break;
    }
    if (port == 0)
        DAT_a807cd68[0] = v;
    else
        DAT_a807cd00[0] = v;
}
