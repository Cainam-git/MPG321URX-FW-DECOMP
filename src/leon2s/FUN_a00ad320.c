/* leon2s FUN_a00ad320 @ 0xa00ad320..0xa00ad38c (108 bytes, 27 words)
 * Flags: -mcpu=v8 -Os -g.
 * What it does (code facts): returns 0 when byte 0x115 of the 300-byte (0x12c) record
 * param_1 of ARR_a807dc18 is 0; otherwise returns 1 only when FUN_a00ad27c(param_1) == 1 AND
 * bit 7 of FUN_a00a6bb8(param_1, 0x223) is set, else 0.
 * Callers: FUN_a006e820, FUN_a00b06e0.
 * Aids: none. Draft cap was the name ARR_a807dd2d (= 0xa807dc18 + 0x115); the fw base is
 * 0xa807dc18 (sethi 0xa807dc00 | 0x18, ldub [+0x115]), the name src/leon2s uses. Draft body kept.
 */
extern unsigned int FUN_a00ad27c(unsigned char param_1);
extern unsigned int FUN_a00a6bb8(unsigned char param_1, unsigned short param_2);
extern unsigned char ARR_a807dc18[];

unsigned char FUN_a00ad320(unsigned char param_1)
{
    unsigned char result;
    
    param_1 = param_1 & 0xff;
    result = 0;
    if (ARR_a807dc18[param_1 * 300 + 0x115] == 0) {
        return result;
    }
    if ((FUN_a00ad27c(param_1) & 0xff) == 1) {
        if ((FUN_a00a6bb8(param_1, 0x223) & 0x80) != 0) {
            result = 1;
        }
    }
    return result;
}
