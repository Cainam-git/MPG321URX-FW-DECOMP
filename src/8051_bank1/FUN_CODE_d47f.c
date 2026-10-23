/* 8051_bank1 FUN_CODE_d47f @ 0xD47F..0xD4B0 (49 bytes), OPTIMIZE(8,SPEED) LARGE. Returns a bit (carry).
 * FUN_CODE_d47f(x): LARGE parameter x at XDATA 0xA77D; bit local r (BIT 0x12). Calls FUN_CODE_97c4,
 * FUN_CODE_c6ec, FUN_CODE_d086, FUN_CODE_97c4; r = 1 when FUN_CODE_6781(x) returns 0, else r = 0; then
 * FUN_CODE_c6ec, FUN_CODE_d086, FUN_CODE_97c4, FUN_CODE_c6ec; returns r. No LCALL/LJMP to 0xD47F appears in
 * the bank-1 listing (the bytes were not disassembled by Ghidra). No aids.
 */
void FUN_CODE_97c4(void);
void FUN_CODE_c6ec(void);
void FUN_CODE_d086(void);
unsigned char FUN_CODE_6781(unsigned char x);

bit FUN_CODE_d47f(unsigned char x)
{
    bit r;

    FUN_CODE_97c4();
    FUN_CODE_c6ec();
    FUN_CODE_d086();
    FUN_CODE_97c4();
    if (FUN_CODE_6781(x)) r = 0;
    else r = 1;
    FUN_CODE_c6ec();
    FUN_CODE_d086();
    FUN_CODE_97c4();
    FUN_CODE_c6ec();
    return r;
}
