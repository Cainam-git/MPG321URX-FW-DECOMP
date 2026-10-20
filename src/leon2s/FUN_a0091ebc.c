/* leon2s FUN_a0091ebc @ 0xa0091ebc-0xa0091eec (12 words), flags -mcpu=v8 -Os -g.
 * Leaf sibling call. Byte +2 of the 0x1c-byte channel record ARR_a807d580[ch] = v; tail FUN_a0091e70(ch, v)
 * (both u8). void.
 * The base is ARR_a807d580 (the 0x1c-byte record of FUN_a0091b00) with the byte field at +2. The compiled
 * object has a trailing alignment nop after the range.
 */
struct Ch1c { unsigned char b0, b1, b2, b3; unsigned int w[6]; };
extern struct Ch1c ARR_a807d580[];
extern void FUN_a0091e70(unsigned char, unsigned char);

void FUN_a0091ebc(unsigned char ch, unsigned char v)
{
    ARR_a807d580[ch].b2 = v;
    FUN_a0091e70(ch, v);
}
