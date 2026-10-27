/* 8051_bank1 FUN_CODE_d9ff @ 0xd9ff..0xda1d (30 B)
 * FUN_CODE_d9ff(n): writes 7 to the byte that entry n of the CODE table of 28 3-byte generic pointers at 0xB13E..0xB191
 * points to (?C?CSTPTR, tail jump). The bytes after it (0xDA1D..0xDA3A) are a string.
 * No LCALL or LJMP to 0xD9FF occurs in the bank-1 image; FUN_CODE_d56d uses the same table.
 */
extern unsigned char volatile * code DAT_CODE_b13e[28];

void FUN_CODE_d9ff(unsigned char n)
{
    *DAT_CODE_b13e[n] = 7;
}
