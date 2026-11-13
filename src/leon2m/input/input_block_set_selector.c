/* input_block_set_selector  (FUN_a01003b4)
 *
 * Write the 2-bit selector of an input block when the block is active.
 * Name basis: descriptive - bits 2-3 of register 4 and bits of register 0x16
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01003b4 @ 0xa01003b4, flags -mcpu=v8 -O3 -g.
 * Source form: the two update calls differ only in their last argument but are written as separate calls in an
 * if/else.
 */
extern unsigned char input_capture_read8(unsigned char blk, unsigned char reg);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

/*
 * Store a 2-bit selector in bits 2..3 of register 4 of an input block. Nothing is written unless bits 0..1 of
 * that register are both set. After the write, bits 4 and 6 (mask 0x50) of register 0x16 are set to 1 when the
 * selector is not 0 and cleared when it is 0.
 *
 *   blk  input block
 *   sel  selector, 0..3
 *
 * Called from input_api_set_block_selector. input_block_get_selector reads the value back.
 */
void input_block_set_selector(unsigned char blk, unsigned char sel)
{
    unsigned char reg4 = input_capture_read8(blk, 4);

    if ((reg4 & 3) == 3) {
        input_capture_write8(blk, 4, (reg4 & ~0xc) | (sel << 2));
        if (sel != 0)
            input_capture_update_bits(blk, 0x16, 0x50, 1);
        else
            input_capture_update_bits(blk, 0x16, 0x50, 0);
    }
}
