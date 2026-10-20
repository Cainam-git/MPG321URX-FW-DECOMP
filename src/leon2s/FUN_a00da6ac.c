/*
 * FUN_a00da6ac (leon2s, 0xa00da6ac-0xa00da838, 396 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/99.
 * Code facts: k = byte 0xa80787fc selects a 0x30-byte record rec = 0xa8079c98 + k*0x30 and a flag
 * c = byte 0xa8079c50[k]. FUN_a00d6724(buf, rec) fills a stack buffer (frame -128: buf at %fp-32,
 * 17..24 bytes give the same frame). Unless the high nibble of buf[0] is 1, buf[1..] is shifted down
 * by one for (buf[0] & 0xf) - 1 bytes (signed compare) and buf[i+1] = 1. Then the 4-bit field at
 * bits 24..27 of word 0 (the low nibble of buf[0]) is decremented as a word RMW (ld/andn/or/st =
 * bit-field store). r = (u8)FUN_a00d68cc(buf, rec). Then r bytes of rec are copied, one byte per
 * 32-bit word, to the register block DAT_a807609c[byte 0xa8078832] (from word 0 when c == 0, from
 * word 0x30 = +0xc0 otherwise); table and index are reloaded on every pass.
 * Aids: volatile on the copy DESTINATION only: the DAT_a807609c[] entries are register-block
 * pointers (other users, e.g. FUN_a00d8714, write registers +0x2ac/+0x2b0 through them; one word
 * per byte is a register file). Non-volatile gives 91.92 (the store sinks into the bcs delay slot).
 * Symbols named by address.
 */
struct hdr { unsigned int hi:4; unsigned int n:4; unsigned int rest:24; };
union buf { struct hdr h; unsigned char b[24]; };

extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8079c50[];
extern unsigned char ARR_a8079c98[][0x30];
extern volatile unsigned int *DAT_a807609c[];
extern void FUN_a00d6724(unsigned char *, unsigned char *);
extern unsigned char FUN_a00d68cc(unsigned char *, unsigned char *);

void FUN_a00da6ac(void)
{
    union buf buf;
    unsigned char *rec;
    unsigned char c, i, r;

    rec = ARR_a8079c98[DAT_a80787fc];
    c = DAT_a8079c50[DAT_a80787fc];
    FUN_a00d6724(buf.b, rec);
    if ((buf.b[0] & 0xf0) != 0x10) {
        for (i = 0; i < (buf.b[0] & 0xf) - 1; i++)
            buf.b[i + 1] = buf.b[i + 2];
        buf.b[i + 1] = 1;
    }
    buf.h.n--;
    r = FUN_a00d68cc(buf.b, rec);
    if (c == 0) {
        for (i = 0; i < r; i++)
            DAT_a807609c[DAT_a8078832][i] = rec[i];
    } else {
        for (i = 0; i < r; i++)
            DAT_a807609c[DAT_a8078832][i + 0x30] = rec[i];
    }
}
