/* leon2s FUN_a009facc @ 0xa009facc-0xa009faf0 (9 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches / 9 words.
 * Code facts: leaf: r = &ARR_a807db00[port] (0x34-byte records); returns the low byte of the word at +0x40 of the
 * object that r's pointer at +4 points to.
 * Fix vs the autoc draft (77.78): records as a 52-byte struct; the pointer at +4 is the per-port REGISTER block
 * (volatile, the accepted convention of src/leon2s/FUN_a00a211c.c: the fw reads the full word with ld + and 0xff;
 * a plain pointer lets gcc narrow it to ldub +0x43, 77.78); u8 param / u8 return. Aids: none.
 */
struct Obj { unsigned char pad[0x40]; unsigned int w40; };
struct Rec { unsigned int w0; volatile struct Obj *p4; unsigned char rest[0x2c]; };
extern struct Rec ARR_a807db00[];

unsigned char FUN_a009facc(unsigned char port)
{
    return ARR_a807db00[port].p4->w40;
}
