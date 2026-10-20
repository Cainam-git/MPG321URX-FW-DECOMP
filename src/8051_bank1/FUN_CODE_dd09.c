/* 8051_bank1 FUN_CODE_dd09 @ 0xdd09
 * printf "Enable_DPMRX\r\n" (code string at 0x6ad8, through FUN_CODE_2820 like 4a85 / 6c34), then FUN_CODE_8a51(0) and
 * FUN_CODE_8a51(1) (tail LJMP). Byte-exact with OPTIMIZE(8,SPEED) (MATCH exact None 19/19). Twin of the accepted
 * FUN_CODE_de2e ("Disable_DPMRX\r\n" at 0x6ae7).
 */
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_8a51(unsigned char arg);

void FUN_CODE_dd09(void)
{
    FUN_CODE_2820((void code *)0x6ad8);
    FUN_CODE_8a51(0);
    FUN_CODE_8a51(1);
}
