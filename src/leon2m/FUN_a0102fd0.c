/* leon2m FUN_a0102fd0 @ 0xa0102fd0  (-mcpu=v8 -O3 -g, jump table included)
 *
 * Clock meter: frequency of measured clock 'id' in MHz (prints "clock %d = %ld", string 0x19A7C0).
 * The hardware counts the measured clock for 2^17 cycles of the 12 MHz crystal into a 24-bit counter (three byte
 * registers, low byte first), with a 2^div prescaler; so MHz = cnt * 2^div * 12,000,000 / (2^17 * 1,000,000).
 *   id 0:  counter 0xCF012884..8C, div = bits 7:6 of 0xCF014740
 *   id 1:  counter 0xCF0128C4..CC, div = bits 5:4 of 0xCF014740
 *   id 2:  counter 0xCF012904..0C, div = bits 3:2 of 0xCF014740
 *   id 3:  counter 0xCF012944..4C, div = bits 1:0 of 0xCF014740
 *   id 4:  counter 0xCF012984..8C, then a request/acknowledge handshake on 0xCF03C840 (write 1 unless it reads 2,
 *          wait until it reads 1, at most 65535 tries), div = bits 7:6 of 0xCF014744, then 0xCF03C840 = 0
 *   id 13: counter 0xCF012BC4..CC, no prescaler
 *   other: 0
 * FUN_a0155208 is the 64-bit unsigned divide.
 * Caller FUN_a01070b4 (advisory panel limit check) calls FUN_a0102fd0(0), or (4) when FUN_a010a864()
 * is set, and compares the result with the 0x58-byte row's clock limits (row +0x10/+0x18, Hz, divided by 10^6).
 * The value is a clock in MHz, not an hfreq.
 */
#define R(a) (*(volatile unsigned int *)(a))                          /* 8-bit register in a 32-bit word */
#define CNT(a) (((R((a) + 8) << 8 | R((a) + 4)) << 8) | R(a))     /* 24-bit counter, low byte at a */
extern unsigned long long FUN_a0155208(unsigned long long, unsigned long long);
extern int FUN_a00df170();
extern char s_0019a7c0[];                                       /* "clock %d = %ld\r\n" */

unsigned short FUN_a0102fd0(unsigned char id)
{
    unsigned int cnt = 0, div = 0;
    unsigned short t;
    unsigned int clk;
    switch (id) {
    case 0: cnt = CNT(0xcf012884); div = R(0xcf014740) >> 6; break;
    case 1: cnt = CNT(0xcf0128c4); div = (R(0xcf014740) >> 4) & 3; break;
    case 2: cnt = CNT(0xcf012904); div = (R(0xcf014740) >> 2) & 3; break;
    case 3: cnt = CNT(0xcf012944); div = R(0xcf014740) & 3; break;
    case 4:
        cnt = CNT(0xcf012984);
        t = 0xffff;
        do {
            if (R(0xcf03c840) != 2) R(0xcf03c840) = 1;
            if (R(0xcf03c840) == 1) break;
            t--;
        } while (t != 0xffff);
        R(0xcf03c840) = 1;
        div = (R(0xcf014744) & 0xff) >> 6;
        R(0xcf03c840) = 0;
        break;
    case 13: cnt = CNT(0xcf012bc4); break;
    }
    clk = FUN_a0155208((unsigned long long)cnt * (unsigned char)(1 << div) * 12000000, 131072000000ULL);
    FUN_a00df170(s_0019a7c0, id, clk);
    return clk;
}
