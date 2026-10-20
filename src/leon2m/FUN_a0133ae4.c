/* leon2m FUN_a0133ae4 @ 0xa0133ae4-0xa0133b54 (28 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0148698.
 * Copies out the record at 0xa802d9c6: byte +0 to *id, halfword +2 (n) to *len, and the n bytes from +4 to dst
 * (n read again on every step, halfword counter). Then clears byte +0x84 (0xa802da4a).
 */
struct Rec { unsigned char id; unsigned char pad1; unsigned short len; unsigned char data[0x80]; unsigned char b84; };
extern struct Rec DAT_a802d9c6;

void FUN_a0133ae4(unsigned char *id, unsigned short *len, unsigned char *dst)
{
    unsigned short i;

    *id = DAT_a802d9c6.id;
    *len = DAT_a802d9c6.len;
    for (i = 0; i < DAT_a802d9c6.len; i++)
        dst[i] = DAT_a802d9c6.data[i];
    DAT_a802d9c6.b84 = 0;
}
