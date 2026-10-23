/* leon2m FUN_a00dd904 @ 0xa00dd904 (-mcpu=v8 -O2 -g)
 * Hardware registers (volatile): 0xCF03CF00 = 0, 0xCF03CF04 = 0x1b, 0xCF03CF08 = 0x80, 0xCF03CF0C = 1; bits 0..3 of p
 * are ORed into 0xCF03C02C and bits 4..7 of p into bits 0..3 of 0xCF03C200 (one test per bit); then 0xCF03CF04 = 0x19
 * and 0xCF03CF04 = 0x1b. Caller: FUN_a0124448.
 */
#define DAT_cf03cf00 (*(volatile unsigned int *)0xcf03cf00)
#define DAT_cf03cf04 (*(volatile unsigned int *)0xcf03cf04)
#define DAT_cf03cf08 (*(volatile unsigned int *)0xcf03cf08)
#define DAT_cf03cf0c (*(volatile unsigned int *)0xcf03cf0c)
#define DAT_cf03c02c (*(volatile unsigned int *)0xcf03c02c)
#define DAT_cf03c200 (*(volatile unsigned int *)0xcf03c200)

void FUN_a00dd904(unsigned char param_1)
{
    unsigned int input;
    
    DAT_cf03cf00 = 0;
    DAT_cf03cf04 = 0x1b;
    DAT_cf03cf08 = 0x80;
    
    input = param_1 & 0xff;
    
    DAT_cf03cf0c = 1;
    
    if (input & 1) DAT_cf03c02c |= 1;
    if (input & 2) DAT_cf03c02c |= 2;
    if (input & 4) DAT_cf03c02c |= 4;
    if (input & 8) DAT_cf03c02c |= 8;
    if (input & 0x10) DAT_cf03c200 |= 1;
    if (input & 0x20) DAT_cf03c200 |= 2;
    if (input & 0x40) DAT_cf03c200 |= 4;
    if (param_1 & 0x80) DAT_cf03c200 |= 8;
    
    DAT_cf03cf04 = 0x19;
    DAT_cf03cf04 = 0x1b;
}
