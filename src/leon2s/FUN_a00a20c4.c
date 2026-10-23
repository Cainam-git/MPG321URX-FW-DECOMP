/* leon2s FUN_a00a20c4 @ 0xa00a20c4 (-mcpu=v8 -Os -g)
 * Table 0xA807D7E0 holds records of 400 bytes. For record idx returns ((halfword +0x32 * byte +0x19) >> 3) * (byte
 * +0x2E + 1), truncated to 16 bits.
 * Source form: Ghidra's type and symbol names are kept.
 */
extern unsigned short DAT_a807d7e0[];  // table at 0xa807d7e0, 400-byte records

unsigned short FUN_a00a20c4(unsigned char idx) {
    unsigned char *rec = (unsigned char *)((unsigned int)idx * 400 + (unsigned int)DAT_a807d7e0);
    unsigned int result = ((unsigned int)*(unsigned short *)(rec + 0x32) * rec[0x19]) >> 3;
    return (unsigned short)(result * (rec[0x2e] + 1));
}
