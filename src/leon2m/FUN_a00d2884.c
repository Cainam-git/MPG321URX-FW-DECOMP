/* leon2m FUN_a00d2884 @ 0xa00d2884-0xa00d28d4 (20 words), flags -mcpu=v8 -O2 -g. Command handler without direct callers.
 * When command byte 7 is 1 or 0, that value is stored in byte 0x14 of the record DAT_a802d274 (other values
 * leave it unchanged); then FUN_a014aed0(0x30, DAT_a802d274, 0x2e0, 0x1c) saves the 0x1c-byte record, and
 * the function returns 0xe0. Same form as FUN_a00d2384 (record DAT_a802d290, 0x1fc bytes at offset 0).
 */
extern unsigned char DAT_a802d274[];
extern int FUN_a014aed0();

int FUN_a00d2884(unsigned char *param_1)
{
    if (param_1[7] == 1)
        DAT_a802d274[0x14] = 1;
    else if (param_1[7] == 0)
        DAT_a802d274[0x14] = 0;
    FUN_a014aed0(0x30, DAT_a802d274, 0x2e0, 0x1c);
    return 0xe0;
}
