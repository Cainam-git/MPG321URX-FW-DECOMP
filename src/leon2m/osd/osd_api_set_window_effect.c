/* osd_api_set_window_effect  (FUN_a014667c)
 *
 * Build a five-byte effect record for a window of a menu layer and apply it.
 * Name basis: descriptive - forwards to osd_set_effect_record; selects window 0..7 first when asked
 *
 * Matching notes
 * --------------
 * leon2m @ 0xa014667c-0xa0146870 (125 words), flags -mcpu=v8 -O3 -g.
 * The record is passed to osd_set_effect_record by value (the callee reads it through a byte pointer).
 * Source form: flags and position are cleared before the switch, and every case 0..8 clears byte1, byte3 and byte4
 * (GCC keeps these clears before the calls and drops them for case 8, which keeps its own jump table entry; the
 * jump table has 9 entries). position is written as two field updates (bits 4-7, then bits 0-3); their reads of
 * position keep its clear before the switch.
 */

/* Bits of the first byte of the record (osd_set_effect_record switches a single register bit for each). */
#define EFFECT_FLAG_BIT0 1
#define EFFECT_FLAG_BIT1 2
#define EFFECT_FLAG_BIT2 4
#define EFFECT_FLAG_BIT3 8

/* The five bytes handed to osd_set_effect_record. */
struct effect_record
{
    unsigned char flags;        /* bits 0..3 = EFFECT_FLAG_BIT0..3 */
    unsigned char byte1;
    unsigned char position;     /* bits 4-5 from the x argument (its low two bits), bits 0-3 from the y argument */
    unsigned char byte3;
    unsigned char byte4;
};

extern void osd_select_window(unsigned int window, unsigned char blk);
extern void osd_set_effect_record(struct effect_record rec, unsigned char blk);

/*
 * Apply one effect record to menu layer `blk`.
 *   select   : 0..7 = select that window first (osd_select_window), so the record goes to it;
 *              8 or more = no selection, the record goes to the window selected before
 *   bit0..3  : non-zero sets, zero clears the matching bit of the first byte of the record
 *              (the arguments come in the order bit0, bit2, bit1, bit3)
 *   v1       : second byte of the record
 *   x        : only its low two bits are used; they become bits 4-5 of the third byte
 *   y        : its low four bits become bits 0-3 of the third byte
 *   v3, v4   : fourth and fifth byte of the record
 *   blk      : menu layer 0 or 1
 * Example: the split-line editor calls it with select = 6 (SPLIT_WINDOW there), v1 = 2, everything else 0.
 */
void osd_api_set_window_effect(unsigned char select, unsigned char bit0, unsigned char bit2, unsigned char bit1, unsigned char bit3,
                  unsigned char v1, unsigned char x, unsigned char y, unsigned char v3, unsigned char v4,
                  unsigned char blk)
{
    struct effect_record rec;

    rec.flags = 0;
    rec.position = 0;
    switch (select) {
    case 0:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(0, blk);
        break;
    case 1:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(1, blk);
        break;
    case 2:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(2, blk);
        break;
    case 3:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(3, blk);
        break;
    case 4:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(4, blk);
        break;
    case 5:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(5, blk);
        break;
    case 6:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(6, blk);
        break;
    case 7:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        osd_select_window(7, blk);
        break;
    case 8:
        rec.byte1 = 0;
        rec.byte3 = 0;
        rec.byte4 = 0;
        break;
    }

    if (bit0)
        rec.flags |= EFFECT_FLAG_BIT0;
    else
        rec.flags &= ~EFFECT_FLAG_BIT0;
    if (bit2)
        rec.flags |= EFFECT_FLAG_BIT2;
    else
        rec.flags &= ~EFFECT_FLAG_BIT2;
    if (bit1)
        rec.flags |= EFFECT_FLAG_BIT1;
    else
        rec.flags &= ~EFFECT_FLAG_BIT1;
    if (bit3)
        rec.flags |= EFFECT_FLAG_BIT3;
    else
        rec.flags &= ~EFFECT_FLAG_BIT3;
    rec.byte1 = v1;
    rec.position = (rec.position & ~0xf0) | ((x << 4) & 0x30);
    rec.position = (rec.position & ~0x0f) | (y & 0x0f);
    rec.byte3 = v3;
    rec.byte4 = v4;
    osd_set_effect_record(rec, blk);
}
