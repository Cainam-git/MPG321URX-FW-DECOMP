/* pq_window_set_item6  (FUN_a00f6f54)
 *
 * Write picture item 6 of the selected picture window.
 * Note: 0x80..0xFF are written as value & 0x7F, 0x00..0x7F as 0xFF - value (0x7F gives 0x80).
 * Name basis: descriptive - value with bit 7 inverted, below 0x80 the low seven bits inverted too, to register
 *   0xCF00EF1C; item number as in pq_api_set_window_item
 *
 * Matching notes
 * --------------
 * FUN_a00f6f54 (leon2m 0xa00f6f54-0xa00f6f7c, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: result = ~value as the default, overridden when bit 7 is set (the xnor sits in the branch delay slot).
 */
#define BIT7 0x80
#define MASK_7BITS 0x7f
#define PICTURE_ITEM6_REGISTER (*(volatile unsigned int *)0xcf00ef1c)

/*
 * Set picture item 6 of the selected picture window. The register gets a byte that depends on bit 7 of value:
 *   value 0x80..0xFF  ->  value & 0x7F        (0x80 gives 0, 0xFF gives 0x7F)
 *   value 0x00..0x7F  ->  0xFF - value        (0x7F gives 0x80, 0x00 gives 0xFF)
 * so bit 7 of the result is the inverse of bit 7 of value. Item 6 does not go through pq_window_item_hook.
 *
 * Only caller: pq_api_set_window_item (item 6), which passes an unsigned char.
 */
void pq_window_set_item6(unsigned int value)
{
    unsigned char result = ~value;

    if (value & BIT7)
        result = value & MASK_7BITS;
    PICTURE_ITEM6_REGISTER = result;
}
