/* panel_vx1_start_transmitter  (FUN_a011149c)
 *
 * Run the start-up sequence of the V-by-One transmitter.
 * Name basis: proven - Vx1 transmitter start-up, link type 0; a step of the panel power sequencer
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011149c, flags -mcpu=v8 -O3 -g.
 * Source form: the table index is taken from the row word inside an inner block together with the const table;
 * the 24 final writes go through one unsigned int, value.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned int *panel_working_row_ptr;
extern unsigned char sys_request_byte;
extern int timer_sleep_ticks();

#define ROW_TABLE_INDEX_SHIFT 27    /* the table index is the top five bits of word 0 of the working row */
#define WAIT_TICKS            1     /* every wait of the sequence */

/*
 * Start-up sequence of the V-by-One transmitter, for a panel whose row says link type 0.
 *
 * Called by the panel power sequencer (panel_power_sequencer_task) in power-on state 4 when bits 20..22 of
 * word 0 of the active row are 0; for link type 1 it calls panel_vx1_setup_lanes instead.
 *
 * The routine writes a fixed series of values to the transmitter registers 0xCF01CCxx..0xCF01CFxx (the block
 * panel_vx1_setup_transmitter also writes), with three waits of WAIT_TICKS between groups of writes. What each
 * register does is not shown by the code. Two steps depend on something outside the series:
 *   - when the byte sys_request_byte (stored by sys_store_request_byte) is not 0, register 0xCF00EDE4 gets 0x20;
 *   - at the end the same value goes to 24 registers (the four lane groups): an entry of a 13-entry table,
 *     picked by the top five bits of word 0 of the working panel row. There is no range check on that index.
 */
void panel_vx1_start_transmitter(void)
{
    unsigned int value;

    R(0xcf01cf9c) = 0x70;
    R(0xcf01cf10) = 0x70;
    R(0xcf01cf94) = 0x8f;
    R(0xcf01cf08) = 0x8f;
    R(0xcf01cfa0) = 0x22;
    R(0xcf01cf9c) = 0x70;
    R(0xcf01cc98) = 0x30;
    R(0xcf01cc58) = 1;
    R(0xcf01cc6c) = 0x66;
    R(0xcf01cc70) = 0x66;
    R(0xcf01cfa4) = 5;
    R(0xcf01cc64) = 0xe;
    R(0xcf01cc68) = 0x26;
    timer_sleep_ticks(WAIT_TICKS);
    R(0xcf01cfa8) = 0x80;
    R(0xcf01ccec) = 0x80;
    R(0xcf01cd78) = 0x80;
    R(0xcf01ce90) = 0x80;
    R(0xcf01cf18) = 5;
    R(0xcf01cff8) = 5;
    R(0xcf01cf9c) = 0x71;
    R(0xcf01cf10) = 0x71;
    R(0xcf01cc14) = 0;
    R(0xcf01cc40) = 0;
    R(0xcf01cc20) = 0;
    R(0xcf01cf94) = 0xcf;
    timer_sleep_ticks(WAIT_TICKS);
    R(0xcf01cf94) = 0x4f;
    R(0xcf01cf08) = 0x4f;
    R(0xcf01cfa0) = 2;
    timer_sleep_ticks(WAIT_TICKS);
    R(0xcf01cff8) = 1;
    R(0xcf01ccc0) = 8;
    R(0xcf01cfac) = 8;
    R(0xcf01ccc4) = 3;
    R(0xcf01cfb0) = 3;
    R(0xcf01ccf0) = 0x20;
    R(0xcf01cd7c) = 0x20;
    R(0xcf01ce08) = 0x20;
    R(0xcf01ce94) = 0x20;
    R(0xcf01cd28) = 0;
    R(0xcf01cdb4) = 0;
    R(0xcf01ce40) = 0;
    R(0xcf01cecc) = 0;
    R(0xcf01ccf8) = 0xff;
    R(0xcf01cd84) = 0xf;
    R(0xcf01ce10) = 0xf0;
    R(0xcf01ce9c) = 0xff;
    R(0xcf01cd10) = 0xff;
    R(0xcf01cd9c) = 0xf;
    R(0xcf01ce28) = 0xf0;
    R(0xcf01ceb4) = 0xff;
    R(0xcf01cfa8) = 0x80;
    R(0xcf01ccec) = 0x80;
    R(0xcf01cd78) = 0x80;
    R(0xcf01ce04) = 0x80;
    R(0xcf01ce90) = 0x80;
    if (sys_request_byte != 0) R(0xcf00ede4) = 0x20;
    {
        unsigned int table_index = *panel_working_row_ptr >> ROW_TABLE_INDEX_SHIFT;
        const unsigned char value_table[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12, 13, 14 };
        value = value_table[table_index];
    }
    /* The same 24 registers as panel_vx1_set_group_table_value writes for all four groups. */
    R(0xcf01cd30) = value; R(0xcf01cd34) = value; R(0xcf01cd38) = value; R(0xcf01cd3c) = value;
    R(0xcf01cd40) = value; R(0xcf01cd44) = value; R(0xcf01cd48) = value; R(0xcf01cd4c) = value;
    R(0xcf01cdbc) = value; R(0xcf01cdc0) = value; R(0xcf01cdc4) = value; R(0xcf01cdc8) = value;
    R(0xcf01ce58) = value; R(0xcf01ce5c) = value; R(0xcf01ce60) = value; R(0xcf01ce64) = value;
    R(0xcf01ced4) = value; R(0xcf01ced8) = value; R(0xcf01cedc) = value; R(0xcf01cee0) = value;
    R(0xcf01cee4) = value; R(0xcf01cee8) = value; R(0xcf01ceec) = value; R(0xcf01cef0) = value;
}
