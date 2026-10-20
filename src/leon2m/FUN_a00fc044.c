/* leon2m FUN_a00fc044 @ 0xa00fc044  output picture-path register set-up using the active row size (hand;
 * BYTE-EXACT at -mcpu=v8 -O3 -g -msoft-float).
 *
 * 0xCF00EFC0 = 0xC0; FUN_a00fb434(3, &v, 0xF00, 0x870) (3840 x 2160), FUN_a00fb434(6, &v, row +0x08, row +0x0A)
 * (transformed active row DAT_a802d6a4); FUN_a00fbdcc(0, 1, 0); 0xA802B7EA = 1; FUN_a00fbdcc(0, 4, 0);
 * 0xD0040000 bit 31 set; func_0x4008a880(0xC, 0x100, 0x9A814); func_0x40089820(0xC, 0x100); then the register
 * block 0xCF010300..0x330 = C0 40 0 0 80 80 13 0 / +0x30 = 80, bracketed by 0xCF00ED80 = 8 ... = 0.
 * Panel-row reader: it passes the row's +0x08 / +0x0A size to FUN_a00fb434 id 6.
 * BYTE-EXACT key: FUN_a00fbdcc declared int-returning (with void the delay slot is filled differently).
 */
#define R(a) (*(volatile unsigned int *)(a))
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; };
extern struct PanelParam *DAT_a802d6a4;
extern unsigned short DAT_a802b7ea;
extern unsigned int FUN_a00fb434(unsigned int, unsigned int *, unsigned int, unsigned int);
extern int FUN_a00fbdcc(unsigned int, unsigned int, unsigned int);
extern void func_0x4008a880(int, int, unsigned int);
extern void func_0x40089820(int, int);

void FUN_a00fc044(void)
{
    unsigned int v = 0;

    R(0xcf00efc0) = 0xc0;
    FUN_a00fb434(3, &v, 0xf00, 0x870);
    FUN_a00fb434(6, &v, DAT_a802d6a4->h08, DAT_a802d6a4->h0a);
    FUN_a00fbdcc(0, 1, 0);
    DAT_a802b7ea = 1;
    FUN_a00fbdcc(0, 4, 0);
    R(0xd0040000) |= 0x80000000;
    func_0x4008a880(0xc, 0x100, 0x9a814);
    func_0x40089820(0xc, 0x100);
    R(0xcf00ed80) = 8;
    R(0xcf010300) = 0xc0;
    R(0xcf010304) = 0x40;
    R(0xcf010308) = 0;
    R(0xcf01030c) = 0;
    R(0xcf010310) = 0x80;
    R(0xcf010314) = 0x80;
    R(0xcf010318) = 0x13;
    R(0xcf01031c) = 0;
    R(0xcf010330) = 0x80;
    R(0xcf00ed80) = 0;
}
