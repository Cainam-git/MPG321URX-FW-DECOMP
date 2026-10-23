/* leon2m FUN_a00c17e8 @ 0xa00c17e8-0xa00c18cc (57 words), flags -mcpu=v8 -O3 -g.
 * Command handler: converts the three ASCII digits at bytes 7-9 of the port's receive record (0xa802d040 for
 * port 2, 0xa802d098 for port 3, 0xa802d0d0 otherwise) with FUN_a00bae38. A result above 30 (including the 0xff
 * error value) returns 0xff. Otherwise the value is stored in byte 0xa802d29c, FUN_a00b88cc() runs, the reply is
 * written (FUN_a00baa6c), the port's receive state is cleared (FUN_a00ba950), the 6-byte reply is sent
 * (FUN_a00bab80) and the function returns 0.
 * Source form: FUN_a00bae38 is defined in this file and inlined by GCC at -O3; the other helpers are called.
 */
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d29c;
extern void FUN_a00b88cc(void);
extern void FUN_a00baa6c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00bab80(unsigned char, unsigned char);

unsigned char FUN_a00bae38(unsigned char port)
{
    unsigned char h, t, o;
    unsigned short r;

    if (port == 2) {
        h = DAT_a802d040[7];
        t = DAT_a802d040[8];
        o = DAT_a802d040[9];
    } else if (port == 3) {
        h = DAT_a802d098[7];
        t = DAT_a802d098[8];
        o = DAT_a802d098[9];
    } else {
        h = DAT_a802d0d0[7];
        t = DAT_a802d0d0[8];
        o = DAT_a802d0d0[9];
    }
    if (h < '0' || h > '1')
        return 0xff;
    if (t < '0' || t > '9')
        return 0xff;
    if (o < '0' || o > '9')
        return 0xff;
    h -= '0';
    t -= '0';
    o -= '0';
    r = h * 100 + t * 10 + o;
    return r;
}
int FUN_a00c17e8(unsigned char port)
{
    unsigned char v;

    v = FUN_a00bae38(port);
    if (v > 30)
        return 0xff;
    DAT_a802d29c = v;
    FUN_a00b88cc();
    FUN_a00baa6c(port);
    FUN_a00ba950(port);
    FUN_a00bab80(port, 6);
    return 0;
}
