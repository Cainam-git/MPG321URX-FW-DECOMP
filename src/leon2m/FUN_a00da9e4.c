/* leon2m FUN_a00da9e4 @ 0xa00da9e4-0xa00daa7c (38 words).
 * Sets bit 15 of the halfword at 0xa802cff4+0x14 and sends the 11-byte command "5b00;30000" + digit + '\r' built at
 * 0xa802d268 with FUN_a01487e8(2, 11, buf); the digit is '0' + n, with n values above 10 replaced by 1.
 * Source form: the halfword is updated through a pointer local set just before the update, after the buffer
 * stores (byte 0 stored last).
 */
struct Rcff4 {
    unsigned char pad[0x14];
    unsigned short h14;
};
extern struct Rcff4 DAT_a802cff4;
extern unsigned char DAT_a802d268[11];
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00da9e4(unsigned char n)
{
    struct Rcff4 *s;

    if (n > 10)
        n = 1;
    DAT_a802d268[1] = 'b';
    DAT_a802d268[2] = '0';
    DAT_a802d268[3] = '0';
    DAT_a802d268[4] = ';';
    DAT_a802d268[5] = '3';
    DAT_a802d268[6] = '0';
    DAT_a802d268[7] = '0';
    DAT_a802d268[8] = '0';
    DAT_a802d268[9] = n + '0';
    DAT_a802d268[10] = '\r';
    DAT_a802d268[0] = '5';
    s = &DAT_a802cff4;
    s->h14 |= 0x8000;
    FUN_a01487e8(2, 11, DAT_a802d268);
}
