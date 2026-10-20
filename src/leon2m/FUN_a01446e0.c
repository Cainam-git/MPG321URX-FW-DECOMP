/* leon2m FUN_a01446e0 @ 0xa01446e0-0xa0144768 (34 words).
 * Searches the five 3-byte records at 0x1a6da3 for the first whose byte 1 equals x and returns its byte 0; when
 * FUN_a012ad6c() returns 1, a byte 0 of 4 is returned as 6 and 6 as 4. Returns 0 when no record matches.
 * No direct callers were found.
 */
struct Map3 { unsigned char b0, b1, b2; };
extern const struct Map3 DAT_001a6da3[5];
extern unsigned char FUN_a012ad6c(void);

unsigned char FUN_a01446e0(unsigned char x)
{
    unsigned char i;
    unsigned char v;

    for (i = 0; i <= 4; i++) {
        if (DAT_001a6da3[i].b1 == x) {
            v = DAT_001a6da3[i].b0;
            if (FUN_a012ad6c() == 1) {
                if (v == 4)
                    v = 6;
                else if (v == 6)
                    v = 4;
            }
            return v;
        }
    }
    return 0;
}
