/* 8051_bank2 FUN_CODE_999f @ 0x999f  BYTE-EXACT under OPTIMIZE(8,SPEED) LARGE (first C, MATCH exact
 * None 494/494).
 * Byte-order swap of 32-bit words: dst[4k + n] = src[4k + 3 - n] for every whole word (k < len >> 2), then ONE
 * more word when len is not a multiple of 4 ('if (i * 4 < len)': i keeps its loop end value; this extra word
 * reads/writes up to 3 bytes past len - code fact). Generic pointers (?C?CLDOPTR 0x3192 / ?C?CSTOPTR 0x31f3).
 * LARGE-model XDATA block: dst 0x095A (from R1..R3), src 0x095D and len 0x0960 (memory parameters, set by the
 * callers), i 0x0961, j 0x0962.
 * Callers: FUN_CODE_520d (0x524d, 0x54e1, LJMP 0x55f1), FUN_CODE_768a (0x76d6 next to the "USBC" signature bytes
 * 55 53 42 43 = USB mass-storage command block wrapper, 0x775b, 0x79ae), FUN_CODE_d2fb (0xd372): converts the
 * big-endian 32-bit fields of USB mass-storage / SCSI blocks.
 * Tail 'LCALL 31f3; RET': the false test of the 'if' jumps to the RET (LJMP 0x9b8c), no aid needed.
 * Also MATCH: 'len / 4' and 'j = i * 4' (same code).
 */
void FUN_CODE_999f(unsigned char *dst, unsigned char *src, unsigned char len)
{
    unsigned char i;
    unsigned char j;
    for (i = 0; i < (len >> 2); i++) {
        j = i << 2;
        dst[j] = src[j + 3];
        dst[j + 1] = src[j + 2];
        dst[j + 2] = src[j + 1];
        dst[j + 3] = src[j];
    }
    if (i * 4 < len) {
        j = i << 2;
        dst[j] = src[j + 3];
        dst[j + 1] = src[j + 2];
        dst[j + 2] = src[j + 1];
        dst[j + 3] = src[j];
    }
}
