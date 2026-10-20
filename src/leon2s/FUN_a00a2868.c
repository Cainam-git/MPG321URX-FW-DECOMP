/* leon2s FUN_a00a2868 @ 0xa00a2868  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
// FUN_a00a2868 at 0xa00a2868
extern unsigned short DAT_a807d7e0[];  // table at 0xa807d7e0, 400-byte records

unsigned int FUN_a00a2868(unsigned char idx) {
    unsigned short *rec = (unsigned short *)((unsigned int)idx * 400 + (unsigned int)DAT_a807d7e0);
    unsigned int result = rec[13];  // +0x1a
    result -= rec[15];              // +0x1e
    result -= rec[20];              // +0x28
    result -= rec[18];              // +0x24
    return (unsigned short)result;
}
