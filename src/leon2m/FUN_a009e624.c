/* FUN_a009e624 (leon2m 0xa009e624-0xa009e65c, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When byte 0x1df of DAT_a802d290 is below 6, increments it and calls FUN_a00b7d14(1) as a tail call. Its CPU
 * address 0x3e624 is stored in the data word 0xa8025934 (initialised data, file offset 0x0ed934). It lies between
 * FUN_a009e5ac and FUN_a009e65c.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a00b7d14(int);

void FUN_a009e624(void)
{
    if (DAT_a802d290[0x1df] < 6) {
        DAT_a802d290[0x1df]++;
        FUN_a00b7d14(1);
    }
}
