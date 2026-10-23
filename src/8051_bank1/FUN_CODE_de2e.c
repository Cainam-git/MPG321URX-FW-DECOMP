/* 8051_bank1 FUN_CODE_de2e @ 0xde2e  OPTIMIZE(8,SPEED)
 * Calls FUN_CODE_2820 with a generic pointer to CODE 0x6AE7, then FUN_CODE_d75e. The pointer is held in a local
 * `void *` so that it is passed as a three-byte generic pointer.
 */
extern void FUN_CODE_2820(void *ptr);
extern void FUN_CODE_d75e(void);

void FUN_CODE_de2e(void) 
{
    void *p = (void code *)0x6ae7;
    FUN_CODE_2820(p);
    FUN_CODE_d75e();
}
