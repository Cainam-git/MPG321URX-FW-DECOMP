/* leon2m FUN_a01302e0 @ 0xa01302e0-0xa0130438 (86 words).
 * Channel record c = DAT_a802df30[ch] (0x78 bytes, word-0 fields as in FUN_a01518c8): bit 24 of word +0x70 = bit 0
 * of on. When on != 0: a state field of 0 becomes 5, and byte +2 of the port record DAT_a802e224[c.port]
 * (0x2a bytes) becomes 2 when it is 1; and when FUN_a0141ce0(port record byte +0x0a) == 1, FUN_a0141d50(that
 * byte, 2). Then FUN_a00f67d0(c.f4) unless the f4 field (bits 4..7) is 4; state = 0 when on == 0; finally
 * FUN_a0109474(FUN_a013cda8(ch), 0). Called by FUN_a013c944.
 * Source form: the two combined conditions are int flags joined with '&' (the on != 0 flag is reused for the
 * second test).
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x70 - 0x04];
    union { unsigned int w; struct { unsigned int r31:7, b24:1, rest:24; } b; } w70;
    unsigned char p74[0x78 - 0x74];
};
struct Port { unsigned char b00, b01, b02; unsigned char p03[7]; unsigned char b0a; unsigned char rest[0x2a - 0x0b]; };
extern struct Chan DAT_a802df30[4];
extern struct Port DAT_a802e224[];
extern unsigned char FUN_a0141ce0(unsigned char t);
extern void FUN_a0141d50(unsigned char t, unsigned char v);
extern void FUN_a00f67d0(int p);
extern unsigned char FUN_a013cda8(unsigned char ch);
extern void FUN_a0109474(unsigned char sel, unsigned char on);

void FUN_a01302e0(unsigned char ch, unsigned char on)
{
    int a, b;

    DAT_a802df30[ch].w70.b.b24 = on & 1;
    a = DAT_a802df30[ch].u.b.state == 0;
    b = on != 0;
    if (a & b)
        DAT_a802df30[ch].u.b.state = 5;
    a = DAT_a802e224[DAT_a802df30[ch].u.b.port].b02 == 1;
    if (a & b)
        DAT_a802e224[DAT_a802df30[ch].u.b.port].b02 = 2;
    if (FUN_a0141ce0(DAT_a802e224[DAT_a802df30[ch].u.b.port].b0a) == 1 && on)
        FUN_a0141d50(DAT_a802e224[DAT_a802df30[ch].u.b.port].b0a, 2);
    if (DAT_a802df30[ch].u.b.f4 != 4)
        FUN_a00f67d0(DAT_a802df30[ch].u.b.f4);
    if (!on)
        DAT_a802df30[ch].u.b.state = 0;
    FUN_a0109474(FUN_a013cda8(ch), 0);
}
