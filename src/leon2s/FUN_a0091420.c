/* FUN_a0091420 (leon2s 0xa0091420-0xa00914c4, 164 bytes), flags -mcpu=v8 -Os -g.
 * Rate-limited range check for one port (param_2 & 0xff). reset != 0: clears the flag byte DAT_a8078c18[port]
 * and stores the current time FUN_a00b2064() in DAT_a8078c0c[port]. Otherwise, when more than 40 time units
 * passed since that stamp: restamps it and sets the flag to 1 when FUN_a0091388(port) is in 301..1929, else 0.
 * Returns the flag byte.
 * Source forms: port is an unsigned char local; the final read goes through the static helper get_flag()
 * called with the raw parameter, so the 'and 0xff' is redone there as in the firmware.
 */
extern unsigned char DAT_a8078c18[];
extern unsigned int DAT_a8078c0c[];
extern unsigned int FUN_a00b2064(void);
extern unsigned short FUN_a0091388(unsigned int);

static unsigned char get_flag(unsigned char port)
{
    return DAT_a8078c18[port];
}

unsigned int FUN_a0091420(unsigned char reset, unsigned int param_2)
{
    unsigned char port = param_2;

    if (reset) {
        DAT_a8078c18[port] = 0;
        DAT_a8078c0c[port] = FUN_a00b2064();
    } else if (FUN_a00b2064() - DAT_a8078c0c[port] > 0x28) {
        DAT_a8078c0c[port] = FUN_a00b2064();
        if ((unsigned short)(FUN_a0091388(port) - 301) <= 0x65c)
            DAT_a8078c18[port] = 1;
        else
            DAT_a8078c18[port] = 0;
    }
    return get_flag(param_2);
}
