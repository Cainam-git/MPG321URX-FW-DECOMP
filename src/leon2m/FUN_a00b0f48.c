/* leon2m FUN_a00b0f48 @ 0xa00b0f48-0xa00b0fc0 (30 words).
 * Fixed call sequence: FUN_a0090fd8(), func_0x4008e2a4() four times, FUN_a00b50d8(3), FUN_a00b52f8(0x28, 0xb, 0x792),
 * FUN_a00b0a90(), FUN_a0146518(0x32, 0x32, 0), FUN_a00b05d8(), FUN_a00d4780() and the tail call
 * FUN_a0146dc0(1, 0). The function ends at 0xa00b0fc0, where FUN_a00b0fc0 begins.
 */
extern void FUN_a0090fd8(void);
extern void func_0x4008e2a4(void);
extern void FUN_a00b50d8(unsigned int);
extern void FUN_a00b52f8(int, int, int);
extern void FUN_a00b0a90(void);
extern void FUN_a0146518(unsigned short, unsigned short, unsigned char);
extern void FUN_a00b05d8(void);
extern void FUN_a00d4780(void);
extern void FUN_a0146dc0(int, int);

void FUN_a00b0f48(void)
{
    FUN_a0090fd8();
    func_0x4008e2a4();
    func_0x4008e2a4();
    func_0x4008e2a4();
    func_0x4008e2a4();
    FUN_a00b50d8(3);
    FUN_a00b52f8(0x28, 0xb, 0x792);
    FUN_a00b0a90();
    FUN_a0146518(0x32, 0x32, 0);
    FUN_a00b05d8();
    FUN_a00d4780();
    FUN_a0146dc0(1, 0);
}
