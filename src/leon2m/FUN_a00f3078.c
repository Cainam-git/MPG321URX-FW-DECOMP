/* leon2m FUN_a00f3078 @ 0xa00f3078-0xa00f308c (5 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf; reads the 32-bit hardware register word at p (ld [%o0] -> %g1) and then the word at p + 4,
 * returns (p[1] << 8) | p[0] as a full int (no extension at the retl). Callers pass 0xcf01xxxx register addresses
 * (FUN_a010a9e8: 0xcf011ae0/ae8/af0), so p points at MMIO and the two reads are volatile hardware reads in fw order
 * [0] then [4].
 * Source form: volatile u32 register pointer (with a plain pointer gcc schedules the loads freely), int return, low
 * word read first in its own statement. Compiler aids: none.
 */
unsigned int FUN_a00f3078(volatile unsigned int *p)
{
    unsigned int lo = p[0];

    return (p[1] << 8) | lo;
}
