/* FUN_a0091094 (leon2s, 0xa0091094-0xa00910d0, 60 bytes, 15 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * rec = DAT_a807d3e4 + (u8)idx * 0xb0; returns (u16)(h[+0x96] - h[+0x98] - h[+0x9c] - h[+0x9a]) of the
 * u16 fields of that record (smul by 0xb0). The record stride is 0xb0 = 176 bytes.
 */
// FUN_a0091094 at 0xa0091094
extern unsigned short DAT_a807d3e4[];  // table at 0xa807d3e4, 176-byte (0xb0) records

unsigned int FUN_a0091094(unsigned char idx) {
    unsigned short *rec = (unsigned short *)((unsigned int)idx * 0xb0 + (unsigned int)DAT_a807d3e4);
    unsigned int result = rec[0x4b];  // +0x96
    result -= rec[0x4c];              // +0x98
    result -= rec[0x4e];              // +0x9c
    result -= rec[0x4d];              // +0x9a
    return (unsigned short)result;
}
