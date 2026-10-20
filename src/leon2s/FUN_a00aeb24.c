/* leon2s FUN_a00aeb24 @ 0xa00aeb24-0xa00aeb6c (18 words), flags -mcpu=v8 -Os -g.
 * Code facts: returns 1 when bit 7 of word +0x88 of the record that the pointer DAT_a807dc04
 * points to is set, else bit 2 of FUN_a00a6bb8(ch & 0xff, 0x463); 0 otherwise (u8 flag, '& 1').
 * Fix vs the autoc draft (83.33): the pointer is dereferenced as a struct pointer (word at +0x88)
 * with the bit-7 arm first ('r = 1' in both arms of an if / else if); u8 result. Aids: none.
 */
struct Cfg { unsigned char pad[0x88]; unsigned int w88; };
extern struct Cfg *DAT_a807dc04;
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);

unsigned char FUN_a00aeb24(unsigned char ch)
{
    unsigned char r = 0;

    if (DAT_a807dc04->w88 & 0x80)
        r = 1;
    else if (FUN_a00a6bb8(ch, 0x463) & 4)
        r = 1;
    return r & 1;
}
