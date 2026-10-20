/* leon2m FUN_a00be250 @ 0xa00be250-0xa00be2a0 (20 words), flags -mcpu=v8 -O3 -g.
 * Code facts: DAT_a802d078[7] = DAT_a802d078[8] = '0', DAT_a802d078[9] = bits 18..19 of the word
 * DAT_a802d290 + 0xac (srl 18, and 3) + '0'; FUN_a00bac3c(0x6a); FUN_a00ba950(port); sibcall
 * FUN_a00babe4(port, 0xb). port is a u8 param. Same shape as FUN_a00bc86c.
 * Fixes vs the autoc draft (50.00): real bases (d290 record word +0xac, d078 buffer), the stores in
 * ascending index order in the source (sched gives the fw 9, 8, 7), 1-arg bac3c. Aids: none.
 */
struct Rec290 { unsigned char pad[0xac]; unsigned int wac; };
extern struct Rec290 DAT_a802d290;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00babe4(unsigned char, unsigned char);

void FUN_a00be250(unsigned char port)
{
    DAT_a802d078[7] = '0';
    DAT_a802d078[8] = '0';
    DAT_a802d078[9] = ((DAT_a802d290.wac >> 18) & 3) + '0';
    FUN_a00bac3c(0x6a);
    FUN_a00ba950(port);
    FUN_a00babe4(port, 0xb);
}
