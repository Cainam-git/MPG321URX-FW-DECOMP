/* 8051_bank1 FUN_CODE_de20 @ 0xde20  MATCH (OPTIMIZE(7,SPEED))
 * `using 3` corresponds to register bank 3 (PSW bits RS0=1, RS1=1), which gives PSW value 0x18. This should match the target exactly.
 */
extern unsigned char code DAT_CODE_dc89[];

unsigned char FUN_CODE_de20(unsigned char param_1) using 3 {
    return DAT_CODE_dc89[param_1];
}
