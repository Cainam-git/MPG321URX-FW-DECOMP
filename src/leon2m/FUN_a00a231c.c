/* FUN_a00a231c (leon2m 0xa00a231c-0xa00a23a4, 136 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When the byte DAT_a8025c56 is 2: copies DAT_a802d479, DAT_a802d47b or DAT_a802d47d to the byte DAT_a8025c55 for
 * DAT_a802afec = 0xc0, 0xc1 or 0xc2, then calls FUN_a00a1a68() as a tail call. Its CPU address 0x4231c is stored in
 * the data word 0xa802543c (initialised data, file offset 0x0ed43c) and data word 0xa8025454 (initialised data,
 * file offset 0x0ed454) and data word 0xa802546c (initialised data, file offset 0x0ed46c). It lies between
 * FUN_a00a2264 and FUN_a00a23a4.
 */
extern unsigned char DAT_a8025c56, DAT_a8025c55;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a802d479, DAT_a802d47b, DAT_a802d47d;
extern void FUN_a00a1a68(void);

void FUN_a00a231c(void)
{
    if (DAT_a8025c56 == 2) {
        if (DAT_a802afec == 0xc0)
            DAT_a8025c55 = DAT_a802d479;
        else if (DAT_a802afec == 0xc1)
            DAT_a8025c55 = DAT_a802d47b;
        else if (DAT_a802afec == 0xc2)
            DAT_a8025c55 = DAT_a802d47d;
        FUN_a00a1a68();
    }
}
