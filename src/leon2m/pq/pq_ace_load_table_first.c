/* pq_ace_load_table_first  (FUN_a00f7534)
 *
 * Set the ACE control bits and stream a 16-bit table to the block (first form).
 * Name basis: descriptive - default table at 0x19A334; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f7534 @ 0xa00f7534, flags -mcpu=v8 -O3 -g.
 * Source form: the table is selected with if (p == 0) / else (other forms keep one register base for all addresses).
 */
#define R(a) (*(volatile unsigned int *)(a))

/* ACE registers (names as in pq_ace_init). */
#define ACE_CTRL       0xcf00ee80   /* bits 1..2: window for ACE access */
#define ACE_CONFIG     0xcf00eec0
#define ACE_CURVE_CTRL 0xcf00eec4
#define ACE_CURVE_DATA 0xcf00eec8

/* A table: count, then count 16-bit values (from offset 2). */
struct ace_table {
    unsigned char count;
    unsigned short values[1];
};

extern unsigned char pq_selected_window;
extern struct ace_table pq_ace_default_table;
extern void panel_wait_sync_pulse(void);

/*
 * Stream a table of 16-bit values into the ACE block of the selected picture window.
 *
 *   table  count and values; 0 = pq_ace_default_table
 *
 * Steps: bits 1..2 of ACE_CTRL = pq_selected_window; in ACE_CONFIG bit 2 cleared and bits 3, 5 and 7 set; bits 4
 * and 6 of ACE_CURVE_CTRL set; each of the count values written whole to ACE_CURVE_DATA (count itself is not
 * written); then bit 7 of ACE_CURVE_CTRL is set for one sync pulse and cleared again.
 *
 * The masked writes of ACE_CTRL and ACE_CONFIG also clear bits 8..31.
 *
 * pq_ace_load_table_second does the same with other ACE_CONFIG / ACE_CURVE_CTRL bits. Nothing calls either.
 */
void pq_ace_load_table_first(struct ace_table *table)
{
    unsigned char i;
    struct ace_table *selected_table;

    R(ACE_CTRL) = (R(ACE_CTRL) & 0xf9) | (pq_selected_window << 1);
    R(ACE_CONFIG) = (R(ACE_CONFIG) & 0xf3) | 0xa8;
    R(ACE_CURVE_CTRL) |= 0x50;
    if (table == 0)
        selected_table = &pq_ace_default_table;
    else
        selected_table = table;
    for (i = 0; i < selected_table->count; i++)
        R(ACE_CURVE_DATA) = selected_table->values[i];
    R(ACE_CURVE_CTRL) |= 0x80;
    panel_wait_sync_pulse();
    R(ACE_CURVE_CTRL) &= ~0x80;
}
