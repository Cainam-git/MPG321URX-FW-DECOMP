/* 8051_bank1 FUN_CODE_ba6d @ 0xba6d (117 B)  Byte-exact with OPTIMIZE(7,SPEED).
 * For channel ch (values above 1 are treated as 1): stores hi and lo as the pair XDATA 0xA73C + 2 * ch
 * (byte 0 = hi, byte 1 = lo; FUN_CODE_dec2 writes the pair of channel 0), then sets XDATA 0xA737[ch] to
 * (hi - lo) / (k * 5) with k = XDATA 0xA73B & 0x1F (k = 0 counts as 1; ?C?UIDIV), and to 1 if that is 0.
 * Only caller: the command switch FUN_CODE_224f, command 49 (bytes 1, 2, 3).
 * The pairs are a two-dimensional array [2][2]: Keil scales the row index with 'ADD A,ACC' and recomputes it for
 * each access (a struct of two bytes gives MUL AB, a flat array with 'ch * 2' a 16-bit index).
 */
extern unsigned char xdata DAT_EXTMEM_a73c[2][2];
extern unsigned char xdata DAT_EXTMEM_a737[];
extern unsigned char xdata DAT_EXTMEM_a73b;

void FUN_CODE_ba6d(unsigned char ch, unsigned char hi, unsigned char lo)
{
    unsigned char k;

    if (ch > 1) ch = 1;
    DAT_EXTMEM_a73c[ch][1] = lo;
    DAT_EXTMEM_a73c[ch][0] = hi;
    k = DAT_EXTMEM_a73b & 0x1f;
    if (k == 0) k = 1;
    DAT_EXTMEM_a737[ch] = (unsigned int)(hi - lo) / (k * 5);
    if (DAT_EXTMEM_a737[ch] == 0) DAT_EXTMEM_a737[ch] = 1;
}
