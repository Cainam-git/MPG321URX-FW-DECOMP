/* leon2m FUN_a0134394 @ 0xa0134394-0xa0134428 (37 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a01405d0,
 * FUN_a0140b78. When FUN_a00dd614(0x20) returns non-zero, prints "MailBox_LoadFE2P : 0x%04X 0x%04X\r\n" with the
 * halfword a and the byte b. Then calls func_0x4008f3f4(0x14, b, high byte of a, low byte of a, 1) and tail-calls
 * func_0x4008f3f4(0x12, 0, 0, 0, 2) (the RAM copy of FUN_a002f3f4). The callee returns void (an int return changes
 * the delay-slot filling of the first call).
 */
extern unsigned char FUN_a00dd614(int);
extern int FUN_a00df170();
extern char s_001a5488[];
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a0134394(unsigned short a, unsigned char b)
{
    if (FUN_a00dd614(0x20))
        FUN_a00df170(s_001a5488, a, b);
    func_0x4008f3f4(0x14, b, a >> 8, (unsigned char)a, 1);
    func_0x4008f3f4(0x12, 0, 0, 0, 2);
}
