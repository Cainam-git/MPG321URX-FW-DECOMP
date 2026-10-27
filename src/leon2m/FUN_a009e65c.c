/* FUN_a009e65c (leon2m 0xa009e65c-0xa009e694, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When byte 0x1df of DAT_a802d290 is non-zero, decrements it and calls FUN_a00b7d14(1) as a tail call. Its CPU
 * address 0x3e65c is stored in the data word 0xa8025928 (initialised data, file offset 0x0ed928). It lies between
 * FUN_a009e624 and FUN_a009e694.
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a00b7d14(int);

void FUN_a009e65c(void)
{
    if (DAT_a802d290[0x1df] != 0) {
        DAT_a802d290[0x1df]--;
        FUN_a00b7d14(1);
    }
}
