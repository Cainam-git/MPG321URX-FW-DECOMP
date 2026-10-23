/* leon2m FUN_a00ce958 @ 0xa00ce958-0xa00ce9c0 (26 words).
 * Prints "LoadCustomerEDIDData %d %d" with the port and the record number n (numbers of 0x38 and above select
 * record 0), then calls FUN_a014b280(port, 0, DAT_00010000 + n * 0x200, 0x180, 1) with the address of the
 * 512-byte record n of the table DAT_00010000, and finally func_0x4008ced8() (tail call).
 * Called from FUN_a00d99f8.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a014b280(unsigned char port, unsigned char b, unsigned int addr, unsigned short len,
                         unsigned char f);
extern void func_0x4008ced8(void);
extern const unsigned char DAT_00010000[];

void FUN_a00ce958(unsigned char port, unsigned short n)
{
    if (n >= 0x38)
        n = 0;
    FUN_a00df170("\x1b[1;35mLoadCustomerEDIDData %d %d \r\n\x1b[m", port, n);
    FUN_a014b280(port, 0, (unsigned int)DAT_00010000 + n * 0x200, 0x180, 1);
    func_0x4008ced8();
}
