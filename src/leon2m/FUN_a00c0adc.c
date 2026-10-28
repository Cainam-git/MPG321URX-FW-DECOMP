/* leon2m FUN_a00c0adc @ 0xa00c0adc-0xa00c0b34 (22 words), flags -mcpu=v8 -O3 -g.
 * Reads byte 7 of the receive record of the port (2 -> 0xa802d040, 3 -> 0xa802d098, any other -> 0xa802d0d0),
 * subtracts '0' and returns the low byte of the difference, or 0xff when that byte is above 100.
 * FUN_a00c0adc, FUN_a00c0b34 and FUN_a00c0b8c are the same code for bytes 7, 8 and 9.
 * Source form: as in FUN_a00ca878, the difference goes into an unsigned short local; the test reads it as
 * (unsigned char)diff and the return as diff & 0xff, from an int function.
 */
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];

int FUN_a00c0adc(unsigned char port)
{
    unsigned int value;
    unsigned short diff;

    if (port == 2)
        value = DAT_a802d040[7];
    else if (port == 3)
        value = DAT_a802d098[7];
    else
        value = DAT_a802d0d0[7];
    diff = value - 0x30;
    if ((unsigned char)diff > 100)
        return 0xff;
    return diff & 0xff;
}
