/* leon2m FUN_a00baef8 @ 0xa00baef8..0xa00bb1c4 (716 bytes)  UART frame reader / classifier for one port (UART command path).
 * BYTE-EXACT: jf 100 match=True and rawcmp 0 / 179 words at -mcpu=v8 -O3 -g (also at -mcpu=v8 -O3 -g -msoft-float).
 * No compiler aids. Hand, from a 95.53 % draft.
 *
 * What the code does (code facts; only caller FUN_a00ce348 passes port 4):
 *   n = 0; FUN_a01487cc(port, 0x30 - DAT_a802b09c, &DAT_a802d0d0[DAT_a802b09c], &n) appends at most 0x30 - count bytes to the
 *   receive buffer at DAT_a802d0d0 (FUN_a01487cc = UART ring read wrapper, n = bytes read).
 *   n == 0 and timer 0xf expired (FUN_a0086a3c(0xf) == 0) and DAT_a802b096 == 1 -> DAT_a802b096 = 0, return 0x40
 *     (receive timeout -> caller clears the buffer).
 *   DAT_a802b09c += n. First byte neither '5' nor 0 and timer expired -> DAT_a802b096 = 1, FUN_a00869b0(0xf, 0x32).
 *   First byte != '5' or fewer than 6 bytes -> return 8 (incomplete).
 *   Timer expired -> DAT_a802b096 = 1, FUN_a00869b0(0xf, 0xfa).
 *   Expected frame length k: byte1 '8' -> 7; byte1 'b' -> by byte5 (0xa6: 0x29; 0xa5/0xa7/0xa8: 10;
 *     0x3c+'6', 0x3c/0x3e/0x3f+'2', 0x65..0x67+'1' (byte4), or (byte5 & 0xf0) > 0x5f: 0x19; else 10); other: 0.
 *   count <= (k & 0x3f) -> 8; byte[k & 0x3f] != '\r' -> 0x10 (bad frame); else DAT_a802b096 = 0 and return
 *     2 ('8' frame: tool command, e.g. "580040:" = update entry), 4 ('b' frame) or 0x10.
 * Types from the asm: k is unsigned int (bleu compare, and 0x3f index), n is the u16 stack local at %fp-10,
 *   FUN_a0086a3c returns unsigned short (sll 16 test), FUN_a01487cc(u8, u16, u8 *, u16 *) as FUN_a0133950.
 * Matching facts: the four 0x19 conditions are SEPARATE else-if arms (one || chain gives the opposite
 *   prediction on the c4 == '2' test and lets ce2 hoist the k = 10 sets); a5/a7/a8 are ONE arm
 *   (c5 == 0xa5 || c5 == 0xa7 || c5 == 0xa8); a separate a8 arm = 6 words off.
 */
extern void FUN_a01487cc(unsigned char, unsigned short, unsigned char *, unsigned short *);
extern unsigned short FUN_a0086a3c(int);
extern void FUN_a00869b0(int, int);

extern unsigned char DAT_a802b09c, DAT_a802b096;
extern unsigned char DAT_a802d0d0[];

unsigned char FUN_a00baef8(unsigned char port)
{
    unsigned short n = 0;
    unsigned int k = 0;
    unsigned char c4, c5;

    FUN_a01487cc(port, 0x30 - DAT_a802b09c, &DAT_a802d0d0[DAT_a802b09c], &n);
    if (n == 0 && FUN_a0086a3c(0xf) == 0 && DAT_a802b096 == 1) {
        DAT_a802b096 = 0;
        return 0x40;
    }
    DAT_a802b09c += n;
    if (DAT_a802d0d0[0] != '5' && DAT_a802d0d0[0] != 0 && FUN_a0086a3c(0xf) == 0) {
        DAT_a802b096 = 1;
        FUN_a00869b0(0xf, 0x32);
    }
    if (DAT_a802d0d0[0] != '5' || DAT_a802b09c < 6)
        return 8;
    if (FUN_a0086a3c(0xf) == 0) {
        DAT_a802b096 = 1;
        FUN_a00869b0(0xf, 0xfa);
    }
    c4 = DAT_a802d0d0[4];
    c5 = DAT_a802d0d0[5];
    if (DAT_a802d0d0[1] == '8')
        k = 7;
    else if (DAT_a802d0d0[1] == 'b') {
        if (c5 == 0xa6)
            k = 0x29;
        else if (c5 == 0xa5 || c5 == 0xa7 || c5 == 0xa8)
            k = 0xa;
        else if (c5 == 0x3c && c4 == '6')
            k = 0x19;
        else if ((c5 == 0x3c || c5 == 0x3e || c5 == 0x3f) && c4 == '2')
            k = 0x19;
        else if ((unsigned char)(c5 - 0x65) < 3 && c4 == '1')
            k = 0x19;
        else if ((c5 & 0xf0) > 0x5f)
            k = 0x19;
        else
            k = 0xa;
    }
    if (DAT_a802b09c <= (k & 0x3f))
        return 8;
    if (DAT_a802d0d0[k & 0x3f] != '\r')
        return 0x10;
    DAT_a802b096 = 0;
    if (DAT_a802d0d0[1] == '8')
        return 2;
    return DAT_a802d0d0[1] == 'b' ? 4 : 0x10;
}
