/* leon2m FUN_a0127898 @ 0xa0127898-0xa01278e4 (19 words).
 * Clears the state record at 0xa802d896: bytes +0x00, +0x16, +0x01, +0x09, +0x0a, +0x0b, +0x0c, +0x0d, +0x10, +0x12,
 * +0x11, +0x13 and halfwords +0x06, +0x14 are set to 0, byte +0x0f is set to 2. Callers: FUN_a0080978,
 * FUN_a0081ea8 (twice), FUN_a0087020. The fields are members of one structure (one base register for all stores).
 * The source order of the stores (+0x16 last) decides the scheduler's order and which store fills the retl slot.
 */
struct St {
    unsigned char b00, b01, b02, b03;
    unsigned short h04, h06;
    unsigned char b08, b09, b0a, b0b, b0c, b0d, b0e, b0f;
    unsigned char b10, b11, b12, b13;
    unsigned short h14;
    unsigned char b16;
};
extern struct St DAT_a802d896;

void FUN_a0127898(void)
{
    DAT_a802d896.b00 = 0;
    DAT_a802d896.b0f = 2;
    DAT_a802d896.b01 = 0;
    DAT_a802d896.b09 = 0;
    DAT_a802d896.b0a = 0;
    DAT_a802d896.b0b = 0;
    DAT_a802d896.h06 = 0;
    DAT_a802d896.b0c = 0;
    DAT_a802d896.b0d = 0;
    DAT_a802d896.b10 = 0;
    DAT_a802d896.b12 = 0;
    DAT_a802d896.b11 = 0;
    DAT_a802d896.b13 = 0;
    DAT_a802d896.h14 = 0;
    DAT_a802d896.b16 = 0;
}
