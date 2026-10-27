/* FUN_a009e9a8 (leon2m 0xa009e9a8-0xa009ea08, 96 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When the halfword at DAT_a802d290 + 0x1f6 is not 0x55aa, bit 14 of the word at DAT_a802d290 + 0 is clear and bit
 * 10 of the halfword DAT_a802cff8 is clear, stores 0x10e to the word DAT_a802afec and calls FUN_a00b8774() as a
 * tail call. Its CPU address 0x3e9a8 is stored in the data word 0xa80241d4 (initialised data, file offset
 * 0x0ec1d4). It lies between FUN_a009e91c and FUN_a009ea08.
 */
struct R290 { unsigned int w000; unsigned char p004[0x1f6 - 4]; unsigned short h1f6; };
extern struct R290 DAT_a802d290;
extern unsigned short DAT_a802cff8;
extern unsigned int DAT_a802afec;
extern void FUN_a00b8774(void);

void FUN_a009e9a8(void)
{
    if (DAT_a802d290.h1f6 != 0x55aa && !(DAT_a802d290.w000 & 0x4000) && !(DAT_a802cff8 & 0x400)) {
        DAT_a802afec = 0x10e;
        FUN_a00b8774();
    }
}
