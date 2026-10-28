/* FUN_a006fedc (leon2s 0xa006fedc-0xa006ffb4, 216 bytes), flags -mcpu=v8 -Os -g.
 * Reads a word through FUN_a006faa8(0, 3, &buf, 1), replaces its top byte with the flags DAT_a80787f4 (bit 0),
 * DAT_a8078c5c (bit 1), DAT_a8078c00 (bit 2), DAT_a8078c48[0] (bit 3), DAT_a8078c48[1] (bit 4), DAT_a8078a0a
 * (bit 5), DAT_a80788dc (bit 6) and the low byte of FUN_a0088ea0(0) (bit 7), and writes it back with
 * FUN_a006fad4(0, 3, &buf, 1).
 * Source form: the flag byte is built one statement per bit; the clear of the top byte of buf sits between the
 * bit-1 and bit-2 statements, which gives the firmware's load order.
 */
extern unsigned char DAT_a80787f4;
extern unsigned char DAT_a8078c5c;
extern unsigned char DAT_a8078c00;
extern unsigned char DAT_a8078c48[];
extern unsigned char DAT_a8078a0a;
extern unsigned char DAT_a80788dc;
extern void FUN_a006faa8(unsigned int param_1, int param_2, unsigned int *param_3, unsigned int param_4);
extern void FUN_a006fad4(unsigned int param_1, int param_2, unsigned int *param_3, unsigned int param_4);
extern unsigned int FUN_a0088ea0(unsigned char param_1);


void FUN_a006fedc(void)
{
    unsigned int buf = 0;
    unsigned int v;

    FUN_a006faa8(0, 3, &buf, 1);
    v = DAT_a80787f4;
    v |= DAT_a8078c5c << 1;
    buf &= 0xffffff;
    v |= DAT_a8078c00 << 2;
    v |= DAT_a8078c48[0] << 3;
    v |= DAT_a8078c48[1] << 4;
    v |= DAT_a8078a0a << 5;
    v |= DAT_a80788dc << 6;
    v |= (unsigned char)FUN_a0088ea0(0) << 7;
    buf |= v << 24;
    FUN_a006fad4(0, 3, &buf, 1);
}
