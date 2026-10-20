/* leon2m FUN_a0139b90 @ 0xa0139b90
 * Tensilica mailbox command 0x2A001020: post one command word into mailbox portal 2 (0xB7091000) at offset 0x20.
 *   1. read the word at portal 2 + 0x20 (MailBox_Read, func_0x4008c4d0 = RAM alias of FUN_a002c4d0);
 *   2. while it is non-zero (slot still busy), wait with func_0x4008d1a0(1) and read again, at most 100 times;
 *   3. if the slot became 0, write 0x2A001020 there (MailBox_Write, func_0x4008c5f8). On timeout nothing is sent.
 * The command word is built as (unsigned char 0x2A << 24) | (unsigned short 0x1020); that spelling is what gives the
 * firmware's sethi/srl/or sequence.
 * Callers: System_Initialize FUN_a015209c (+0x374) and FUN_a014e050. Template for the 172-byte sibling family.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(int ms);
void FUN_a0139b90(void)
{
    unsigned int v = 0xffffffff;
    int n = 100;
    func_0x4008c4d0(2, 0x20, &v, 1);
    while (v != 0) { n--; func_0x4008d1a0(1); func_0x4008c4d0(2, 0x20, &v, 1); if (n == 0) break; }
    if (v == 0) { unsigned short a = 0x1020; unsigned char c = 0x2a; v = (c << 24) | a; func_0x4008c5f8(2, 0x20, &v, 1); }
}
