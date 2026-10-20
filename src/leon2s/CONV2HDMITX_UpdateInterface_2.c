/*
 * CONV2HDMITX_UpdateInterface_2 (leon2s, 0xa00ad38c-0xa00ad3e0, 84 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: if byte +0x11e of the 300-byte port record ARR_a807dc18[port] is non-zero: port register
 * 0x21d = (u8)(v | 0x80) via FUN_a00a6c00, then the sibcall print FUN_a0073044(s_a006c4e8, v, port).
 * s_a006c4e8 in the image is "\x1b[0;38mNTL LCnt %d (link %d)\r\n\x1b[m" (2 %d args = %i1/%i2 after the
 * restore); the draft had another string and no args (BEHAVIOUR). Aids: none.
 */
struct port300 { unsigned char pad[0x11e]; unsigned char b11e; unsigned char rest[300 - 0x11f]; };
extern struct port300 ARR_a807dc18[];
extern void FUN_a00a6c00(unsigned int, unsigned short, unsigned char);
extern int FUN_a0073044(const char *, ...);
extern char s_a006c4e8[];

void CONV2HDMITX_UpdateInterface_2(unsigned char param_1, unsigned char param_2)
{
    if (ARR_a807dc18[param_1].b11e != 0) {
        FUN_a00a6c00(param_1, 0x21d, param_2 | 0x80);
        FUN_a0073044(s_a006c4e8, param_2, param_1);
    }
}
