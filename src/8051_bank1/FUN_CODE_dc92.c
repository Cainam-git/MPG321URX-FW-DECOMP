/* 8051_bank1 FUN_CODE_dc92 @ 0xdc92  OPTIMIZE(7,SPEED)
 * Calls FUN_CODE_2820 with the generic pointer 0xFFB545, then FUN_CODE_9522, FUN_CODE_8731, FUN_CODE_cdcd and
 * FUN_CODE_d13a. Keil passes a generic pointer in R3 (memory type, 0xFF = code), R2 (high address byte) and R1
 * (low address byte); the firmware loads R3 = 0xFF, R2 = 0xB5, R1 = 0x45, i.e. code address 0xB545.
 */
extern void FUN_CODE_2820(void *p);  // 0x2820
extern void FUN_CODE_9522(void);  // 0x9522
extern void FUN_CODE_8731(void);  // 0x8731
extern void FUN_CODE_cdcd(void);  // 0xcdcd
extern void FUN_CODE_d13a(void);  // 0xd13a

void FUN_CODE_dc92(void) 
{
    FUN_CODE_2820((void code *)0xffb545);
    FUN_CODE_9522();
    FUN_CODE_8731();
    FUN_CODE_cdcd();
    FUN_CODE_d13a();
}
