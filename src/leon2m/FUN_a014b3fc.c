/* FUN_a014b3fc: copies the field sel of a byte record into the area 0xa802e1c2 (DAT_a802e1a0 + 0x22):
 * sel 0: 2 bytes at offset 0, 1: 2 bytes at offset 2, 2: 4 bytes at offset 4, 3: 1 byte at offset 8,
 * 4: 1 byte at offset 9 (bytes taken from src[0..n-1]); other sel values copy nothing. Then tail-calls
 * FUN_a0153970(DAT_a802e1a0, 0). No direct callers were found.
 */
extern unsigned char DAT_a802e1a0[];
extern void FUN_a0153970(void *, unsigned int);

void FUN_a014b3fc(unsigned char sel, const unsigned char *src)
{
    unsigned char n = 0, off = 0, i;

    switch (sel) {
    case 0: n = 2; off = 0; break;
    case 1: n = 2; off = 2; break;
    case 2: n = 4; off = 4; break;
    case 3: n = 1; off = 8; break;
    case 4: n = 1; off = 9; break;
    }
    for (i = 0; i < n; i++)
        DAT_a802e1a0[0x22 + off + i] = src[i];
    FUN_a0153970(DAT_a802e1a0, 0);
}
