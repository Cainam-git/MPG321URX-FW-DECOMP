/* FUN_a00ac138 (leon2m 0xa00ac138-0xa00ac388, 592 bytes), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a00a3844(table, entry) for item i of id, with e = i * 29 + byte DAT_a802d290+8: id 0x34 and 0xba
 * -> (0x18b5e0, e); 0x36 -> (0x18b29c, e); 0x37 -> (0x193248, e) for i 0..1, else (0x18b94c, e - 58);
 * 0x38..0x3a -> (0x16df60, e); 0x3b -> (0x185bc0, e); 0xbd -> (0x18a7ec, e); 0xbe -> (0x18a7ec, e + 0x3a);
 * 0xbf -> (0x18a794, i), i + 7 when byte DAT_a802d46f is above 6. Other ids return 0. Called by FUN_a00ac718.
 * Source form: one call per case into a result preset to 0 (the calls are merged into one call site); cases in
 * the order 0x37, 0x3b, 0x38..0x3a, 0x34, 0xba, 0xbd, 0xbf, 0xbe, 0x36, with 0x34 and 0xba as two identical
 * case bodies.
 */
struct St {
    unsigned char pad[8];
    unsigned char b08;
};
extern struct St DAT_a802d290;
extern unsigned char DAT_a802d46f;
extern unsigned int DAT_0016df60[], DAT_00185bc0[], DAT_0018a794[], DAT_0018a7ec[], DAT_0018b29c[];
extern unsigned int DAT_0018b5e0[], DAT_0018b94c[], DAT_00193248[];
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);

unsigned int FUN_a00ac138(unsigned short id, unsigned char i)
{
    unsigned int r = 0;

    switch (id) {
    case 0x37:
        if (i <= 1)
            r = FUN_a00a3844(DAT_00193248, i * 29 + DAT_a802d290.b08);
        else
            r = FUN_a00a3844(DAT_0018b94c, i * 29 + DAT_a802d290.b08 - 58);
        break;
    case 0x3b:
        r = FUN_a00a3844(DAT_00185bc0, i * 29 + DAT_a802d290.b08);
        break;
    case 0x38:
    case 0x39:
    case 0x3a:
        r = FUN_a00a3844(DAT_0016df60, i * 29 + DAT_a802d290.b08);
        break;
    case 0x34:
        r = FUN_a00a3844(DAT_0018b5e0, i * 29 + DAT_a802d290.b08);
        break;
    case 0xba:
        r = FUN_a00a3844(DAT_0018b5e0, i * 29 + DAT_a802d290.b08);
        break;
    case 0xbd:
        r = FUN_a00a3844(DAT_0018a7ec, i * 29 + DAT_a802d290.b08);
        break;
    case 0xbf:
        if (DAT_a802d46f <= 6)
            r = FUN_a00a3844(DAT_0018a794, i);
        else
            r = FUN_a00a3844(DAT_0018a794, i + 7);
        break;
    case 0xbe:
        r = FUN_a00a3844(DAT_0018a7ec, i * 29 + DAT_a802d290.b08 + 0x3a);
        break;
    case 0x36:
        r = FUN_a00a3844(DAT_0018b29c, i * 29 + DAT_a802d290.b08);
        break;
    }
    return r;
}
