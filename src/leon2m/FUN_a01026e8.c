/* leon2m FUN_a01026e8 @ 0xa01026e8  GPLL display / FRC clock programmer, flags -mcpu=v8 -O3 -g.
 * Real size 0x884 bytes (Ghidra's list says 164: it stops at the jump table).
 *
 * FUN_a01026e8(ch, freq): programs output clock 'ch' of the GPLL to 'freq' Hz.
 *   Post-divider k: freq < 470 MHz -> k = 0; < 940 MHz -> k = 1 (f = freq / 2); < 1870 MHz -> k = 2 (freq / 4);
 *   else k = 3 (freq / 8). PLL value n = f * 2^17 / 12,000,000 (12 MHz reference crystal; 17-bit fraction),
 *   computed in 64 bits (__udivdi3).
 *   ch 0 GPLL_DISPM, 1 GPLL_DISP1, 2 GPLL_DISP2, 3 GPLL_DISP3: value registers 0xCF012884 / 8C4 / 904 / 944
 *   (24 bits over three byte registers, FUN_a00f30a8 reads, FUN_a00f30f0 writes), divider field in 0xCF014740 bits
 *   7..6 / 5..4 / 3..2 / 1..0, gate bit 0/1/2/3 set in 0xCF012444 and cleared in 0xCF01477C, control register
 *   value register + 0x10 written with 0x20 before the new value.
 *   ch 4 GPLL_FRC: value register 0xCF012984, divider field 0xCF014744 bits 7..6 (read and written under the
 *   lock), 0xCF012440 bit 0 set, 0xCF01477C bit 4 cleared, 0xCF012994 = 0x20.
 *   Prints "GPLL_<name> = %ld (x 2^%d)" with f and k; when the value register already holds n and the divider
 *   field already holds k nothing is reprogrammed, otherwise "--><name>" is printed and the clock reprogrammed.
 *   Any other ch: nothing after the computation.
 * Lock: 0xCF03C840 is a hardware semaphore shared with another processor: write 1 unless it reads 2 (held by the
 * other side), done when it reads back 1; after 65536 tries it is taken anyway; released by writing 0.
 * Callers include FUN_a0106d64 (output path set-up: DISPM = x, DISP1 = DISP2 = x/2, DISP3 = x/4 from the panel row)
 * and FUN_a0102f6c. The FRC chip's clock (ch 4) and the output pixel clocks come from here; the
 * frequencies themselves are computed by the callers from the active panel row.
 */
#define R(a) (*(volatile unsigned int *)(a))
#define SEM R(0xcf03c840)
extern int FUN_a00df170();
extern unsigned int FUN_a00f30a8(unsigned int);
extern void FUN_a00f30f0(unsigned int, unsigned int);
extern unsigned long long __udivdi3(unsigned long long, unsigned long long);
extern char s_0019a6e0[], s_0019a700[], s_0019a710[], s_0019a730[], s_0019a740[], s_0019a760[], s_0019a770[], s_0019a790[], s_0019a7a0[], s_0019a6d0[];
static void lock(void)
{
    unsigned short t = 0xffff;
    do {
        if (SEM != 2) SEM = 1;
        if (SEM == 1) break;
    } while (--t != 0xffff);
    SEM = 1;
}
static void unlock(void) { SEM = 0; }
void FUN_a01026e8(unsigned char ch, unsigned int freq)
{
    unsigned int f, n;
    unsigned char k;
    if (freq < 470000000) { k = 0; f = freq; }
    else if (freq < 940000000) { k = 1; f = freq >> 1; }
    else if (freq < 1870000000) { k = 2; f = freq >> 2; }
    else { k = 3; f = freq >> 3; }
    n = (unsigned long long)f * 0x20000 / 12000000;
    switch (ch) {
    case 0:
        FUN_a00df170(s_0019a6e0, f, k);
        if (FUN_a00f30a8(0xcf012884) == n && ((R(0xcf014740) >> 6) & 3) == k) break;
        FUN_a00df170(s_0019a700);
        lock(); R(0xcf012444) |= 1; unlock();
        lock(); R(0xcf01477c) &= ~1; unlock();
        R(0xcf014740) &= ~0xc0;
        R(0xcf014740) |= k << 6;
        R(0xcf012894) = 0x20;
        FUN_a00f30f0(0xcf012884, n);
        break;
    case 1:
        FUN_a00df170(s_0019a710, f, k);
        if (FUN_a00f30a8(0xcf0128c4) == n && ((R(0xcf014740) >> 4) & 3) == k) break;
        FUN_a00df170(s_0019a730);
        lock(); R(0xcf012444) |= 2; unlock();
        lock(); R(0xcf01477c) &= ~2; unlock();
        R(0xcf014740) &= ~0x30;
        R(0xcf014740) |= k << 4;
        R(0xcf0128d4) = 0x20;
        FUN_a00f30f0(0xcf0128c4, n);
        break;
    case 2:
        FUN_a00df170(s_0019a740, f, k);
        if (FUN_a00f30a8(0xcf012904) == n && ((R(0xcf014740) >> 2) & 3) == k) break;
        FUN_a00df170(s_0019a760);
        lock(); R(0xcf012444) |= 4; unlock();
        lock(); R(0xcf01477c) &= ~4; unlock();
        R(0xcf014740) &= ~0x0c;
        R(0xcf014740) |= k << 2;
        R(0xcf012914) = 0x20;
        FUN_a00f30f0(0xcf012904, n);
        break;
    case 3:
        FUN_a00df170(s_0019a770, f, k);
        if (FUN_a00f30a8(0xcf012944) == n && (R(0xcf014740) & 3) == k) break;
        FUN_a00df170(s_0019a790);
        lock(); R(0xcf012444) |= 8; unlock();
        lock(); R(0xcf01477c) &= ~8; unlock();
        R(0xcf014740) &= ~3;
        R(0xcf014740) |= k;
        R(0xcf012954) = 0x20;
        FUN_a00f30f0(0xcf012944, n);
        break;
    case 4:
        FUN_a00df170(s_0019a7a0, f, k);
        if (FUN_a00f30a8(0xcf012984) == n) {
            unsigned char cur;
            lock(); cur = (unsigned char)R(0xcf014744) >> 6; unlock();
            if (cur == k) break;
        }
        FUN_a00df170(s_0019a6d0);
        R(0xcf012440) |= 1;
        lock(); R(0xcf01477c) &= ~0x10; unlock();
        lock(); R(0xcf014744) &= ~0xc0; unlock();
        lock(); R(0xcf014744) |= k << 6; unlock();
        R(0xcf012994) = 0x20;
        FUN_a00f30f0(0xcf012984, n);
        break;
    }
}
