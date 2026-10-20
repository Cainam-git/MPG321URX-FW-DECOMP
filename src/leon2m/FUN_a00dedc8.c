/* FUN_a00dedc8 (leon2m, 0xa00dedc8-0xa00dee6c, 164 bytes, 41 words).
 * Flags: -mcpu=v8 -O3 -g. Judge: jf 100.00 match=True, rawcmp 0/41 mismatches.
 * Code facts: q = param_1 / 0x1c2000 (umul 0x91a2b3c5, rd %y, srl 20); clears the bytes at +0x80 and
 * +0x81 of the record DAT_a802b0ec (fw base sethi/or 0xa802b0ec); then func_0x4008c25c writes to the
 * 0xc00b00xx registers: (0c,0x80) (00,q) (04,0) (0c,0) (0c,3) (08,6) (08,0) (04,1); tail call
 * func_0x4008a880(4, 0x20, FUN_a002e238) (3 args, as at its other call sites).
 * Fixes vs draft: record base DAT_a802b0ec + 0x80/0x81 bytes (the draft had a short at a802b16c);
 * one parameter, void, 3-arg tail call; source store order 0x81 then 0x80 (fw emits 0x80, 0x81).
 * Aids: none.
 */
extern struct { unsigned char pad[0x80]; unsigned char b80; unsigned char b81; } DAT_a802b0ec;
extern int FUN_a002e238();
extern void func_0x4008a880();
extern void func_0x4008c25c();

void FUN_a00dedc8(unsigned int param_1)
{
    unsigned int div_result = param_1 / 0x1c2000;
    DAT_a802b0ec.b81 = 0;
    DAT_a802b0ec.b80 = 0;
    func_0x4008c25c(0xc00b000c, 0x80);
    func_0x4008c25c(0xc00b0000, div_result);
    func_0x4008c25c(0xc00b0004, 0);
    func_0x4008c25c(0xc00b000c, 0);
    func_0x4008c25c(0xc00b000c, 3);
    func_0x4008c25c(0xc00b0008, 6);
    func_0x4008c25c(0xc00b0008, 0);
    func_0x4008c25c(0xc00b0004, 1);
    func_0x4008a880(4, 0x20, FUN_a002e238);
}
