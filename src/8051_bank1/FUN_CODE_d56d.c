/* 8051_bank1 FUN_CODE_d56d @ 0xd56d..0xd59b (46 B)
 * bit FUN_CODE_d56d(n, mask): p = entry n of the CODE table of 28 3-byte generic pointers at 0xB13E..0xB191; v = *p;
 * returns 1 when a second read of *p has a bit of mask set, else 0; then writes v back to *p.
 * volatile on the pointed-to byte: the code reads it twice and writes it (register access through the table).
 * No LCALL or LJMP to 0xD56D occurs in the bank-1 image; FUN_CODE_d9ff uses the same table.
 */
extern unsigned char volatile * code DAT_CODE_b13e[28];

bit FUN_CODE_d56d(unsigned char n, unsigned char mask)
{
    bit r;
    unsigned char v;
    unsigned char volatile *p;

    r = 0;
    p = DAT_CODE_b13e[n];
    v = *p;
    if (*p & mask) r = 1;
    *p = v;
    return r;
}
