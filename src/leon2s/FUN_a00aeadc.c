/* leon2s FUN_a00aeadc @ 0xa00aeadc-0xa00aeb24 (18 words), flags -mcpu=v8 -Os -g.
 * Returns 1 when bit 15 of word +0x88 of the record that the pointer DAT_a807dc04 points to is set AND
 * bit 0 of FUN_a00a6bb8(ch, 0x463) is set; else 0. Neighbour of src/leon2s/FUN_a00aeb24.c (same record,
 * same register 0x463, bit 7 / bit 2 there).
 * Source form: bit 15 is a 1-bit bit-field (firmware 'srl 15; btst 1'; the mask form gives one
 * 'sethi 0x8000; btst'), one '&&' condition with r = 1 / r = 0 arms and 'return r & 1' (as FUN_a00aeb24).
 */
struct Cfg { unsigned char pad[0x88]; struct { unsigned int hi : 16, b15 : 1, lo : 15; } w88; };
extern struct Cfg *DAT_a807dc04;
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);

unsigned char FUN_a00aeadc(unsigned char ch)
{
    unsigned char r;

    if (DAT_a807dc04->w88.b15 && (FUN_a00a6bb8(ch, 0x463) & 1))
        r = 1;
    else
        r = 0;
    return r & 1;
}
