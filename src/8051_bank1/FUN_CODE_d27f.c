/* 8051_bank1 FUN_CODE_d27f @ 0xd27f (53 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Looks up key in a table of ten 3-byte entries at XDATA 0xA62F: for each entry in order, the low five bits of
 * byte 0 are compared; 0x1F ends the table, a value equal to key returns byte 2 of that entry. Returns 0xFF when
 * the key is not found. Callers: FUN_CODE_52be (four calls) and FUN_CODE_883d (four calls).
 * The entry is a 3-byte struct: Keil indexes it with 'MUL AB' by 3 and adds the member offset to the base.
 */
struct ent3 { unsigned char a, b, c; };
extern struct ent3 xdata DAT_EXTMEM_a62f[10];

unsigned char FUN_CODE_d27f(unsigned char key)
{
    unsigned char i, k;

    for (i = 0; i < 10; i++) {
        k = DAT_EXTMEM_a62f[i].a & 0x1f;
        if (k == 0x1f) break;
        if (k == key) return DAT_EXTMEM_a62f[i].c;
    }
    return 0xff;
}
