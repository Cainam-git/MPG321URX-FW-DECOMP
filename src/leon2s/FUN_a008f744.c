/* leon2s FUN_a008f744 @ 0xa008f744-0xa008f79c (22 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s.py 0/22 mismatches.
 * Code facts: m = RX reg 0x281 & 0xf (FUN_a00a657c(port, reg) = low byte of 0xcf000000 | (base[port] + reg) * 4);
 * if (reg 0x282 & m) != 0: FUN_a00a67b8(port, 0x137, 2, 1) (set bit 1 of reg 0x137), else FUN_a00a67b8(port, 0x137,
 * 2, 0) (clear it); both arms are one tail call (call + restore). One parameter: the fw never reads %i1.
 * Caller: FUN_a00908d0 when RX status reg 0x74 bit 7 is set (LINK_STANDBY state 5). Not the source of the Big chip's
 * keep-going bit (that is rec+0xa6 in FUN_a00908d0). Matching form: the reg 0x282 read written first in the '&'
 * ('read & m' gives the fw 'btst %o0, %l0'). Aids: none.
 */
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern void FUN_a00a67b8(unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a008f744(unsigned char port)
{
    unsigned int m = FUN_a00a657c(port, 0x281) & 0xf;
    if (FUN_a00a657c(port, 0x282) & m)
        FUN_a00a67b8(port, 0x137, 2, 1);
    else
        FUN_a00a67b8(port, 0x137, 2, 0);
}
