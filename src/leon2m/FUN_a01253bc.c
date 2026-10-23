/* leon2m FUN_a01253bc @ 0xa01253bc-0xa01254b8 (63 words, the last word is a nop after the final tail call).
 * Port i: on == 0 -> bit i of DAT_a802c9fb cleared and FUN_a0133f84(1 << i). Otherwise bit i set,
 * x = the FUN_a0125380(i) value (0xffff when DAT_a802d880[i] is 0xff, else halfword +6 of the 22-byte ROM row
 * DAT_001a42a8[DAT_a802d880[i]]), k = byte 0xA802E1A0[0x1b + i], len = DAT_001a6ad8[k] or FUN_a012c16c(i) when
 * k == 0xff, then FUN_a0133fbc(1 << i, len, x >> 7). Called by FUN_a014b65c.
 * Source form: FUN_a0125380's body is an inlined static helper here (the firmware has no call to it).
 */
struct rec { unsigned char b00[6]; unsigned short h06; unsigned char b08[14]; };
extern unsigned char DAT_a802d880[];
extern struct rec DAT_001a42a8[];
extern unsigned char DAT_a802c9fb;
extern unsigned char DAT_a802e1a0[];
extern const unsigned short DAT_001a6ad8[];
extern int FUN_a012c16c(unsigned int);
extern void FUN_a0133f84(unsigned char);
extern void FUN_a0133fbc(unsigned char, unsigned short, unsigned char);

static unsigned short rd_h06(unsigned char id)
{
    unsigned char n = DAT_a802d880[id];
    unsigned short r = 0xffff;
    if (n != 0xff)
        r = DAT_001a42a8[n].h06;
    return r;
}

void FUN_a01253bc(unsigned char i, unsigned char on)
{
    unsigned short x, len;

    if (on) {
        DAT_a802c9fb |= 1 << i;
        x = rd_h06(i);
        if (DAT_a802e1a0[0x1b + i] == 0xff)
            len = FUN_a012c16c(i);
        else
            len = DAT_001a6ad8[DAT_a802e1a0[0x1b + i]];
        FUN_a0133fbc(1 << i, len, x >> 7);
    } else {
        DAT_a802c9fb &= ~(1 << i);
        FUN_a0133f84(1 << i);
    }
}
