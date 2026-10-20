/* FUN_a00a2230 (leon2s 0xa00a2230-0xa00a22d4, 164 bytes), flags -mcpu=v8 -Os -g.
 * Rate-limited range check for one port (param_2 & 0xff). reset != 0: clears the flag byte DAT_a80791a0[port]
 * and stores the current time FUN_a00b2064() in DAT_a8079194[port]. Otherwise, when more than 40 time units
 * passed since that stamp: restamps it and sets the flag to 1 when FUN_a00a211c(port) is in 301..1929, else 0.
 * Returns the flag byte.
 * Source forms: port is an unsigned char local; the final read goes through the static helper get_flag()
 * called with the raw parameter, so the 'and 0xff' is redone there as in the firmware.
 */
extern unsigned char DAT_a80791a0[];
extern unsigned int DAT_a8079194[];
extern unsigned int FUN_a00b2064(void);
extern unsigned short FUN_a00a211c(unsigned int);

static unsigned char get_flag(unsigned char port)
{
    return DAT_a80791a0[port];
}

unsigned int FUN_a00a2230(unsigned char reset, unsigned int param_2)
{
    unsigned char port = param_2;

    if (reset) {
        DAT_a80791a0[port] = 0;
        DAT_a8079194[port] = FUN_a00b2064();
    } else if (FUN_a00b2064() - DAT_a8079194[port] > 0x28) {
        DAT_a8079194[port] = FUN_a00b2064();
        if ((unsigned short)(FUN_a00a211c(port) - 301) <= 0x65c)
            DAT_a80791a0[port] = 1;
        else
            DAT_a80791a0[port] = 0;
    }
    return get_flag(param_2);
}
