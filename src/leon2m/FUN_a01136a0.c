/* leon2m FUN_a01136a0 @ 0xa01136a0-0xa0113810 (92 words).
 * Hardware register sequence on 0xcf0118xx / 0xcf011axx: 0xc0 to 0xcf011a40 and 0xcf011a44, then one of two
 * fixed value sets chosen by the byte DAT_a802c98f (0 / not 0): 0xcf011840..84c, 0xcf011a40..a5c, 0xcf011a70,
 * 0xcf011a74 and 0xcf011a7c (values below). Called by FUN_a012fcf4. volatile: hardware registers only.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern unsigned char DAT_a802c98f;

void FUN_a01136a0(void)
{
    R(0xcf011a40) = 0xc0;
    R(0xcf011a44) = 0xc0;
    if (DAT_a802c98f == 0) {
        R(0xcf011840) = 0x60;
        R(0xcf011844) = 0x60;
        R(0xcf011848) = 0x60;
        R(0xcf01184c) = 0x40;
        R(0xcf011a40) = 0x80;
        R(0xcf011a44) = 0xe0;
        R(0xcf011a48) = 0x60;
        R(0xcf011a4c) = 0xe0;
        R(0xcf011a50) = 0x80;
        R(0xcf011a54) = 0xff;
        R(0xcf011a58) = 0;
        R(0xcf011a5c) = 0xff;
        R(0xcf011a70) = 0xc;
        R(0xcf011a74) = 0xc;
        R(0xcf011a7c) = 0xf;
    } else {
        R(0xcf011840) = 0x40;
        R(0xcf011844) = 0x60;
        R(0xcf011848) = 0x60;
        R(0xcf01184c) = 0x40;
        R(0xcf011a40) = 0;
        R(0xcf011a44) = 0xff;
        R(0xcf011a48) = 0x60;
        R(0xcf011a4c) = 0xe0;
        R(0xcf011a50) = 0x80;
        R(0xcf011a54) = 0xff;
        R(0xcf011a58) = 0;
        R(0xcf011a5c) = 0xff;
        R(0xcf011a70) = 9;
        R(0xcf011a74) = 0xf;
        R(0xcf011a7c) = 0xf;
    }
}
