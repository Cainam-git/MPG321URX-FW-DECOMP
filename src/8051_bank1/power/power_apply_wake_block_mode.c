/* power_apply_wake_block_mode  (FUN_CODE_b802)
 *
 * Program the wake block for the current wake-up table entry.
 * Name basis: descriptive - entry 0xA62F[0xA64D] kind 0..12 to power_set_wake_block_mode
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_b802, OPTIMIZE(8,SPEED) (the LARGE and REGFILE(R.ORC) option sets give the same bytes).
 * Source form: 'kind = (unsigned long)(entry.a & 0x1f);': the value passes through the long conversion into R7 and
 * Keil loads A from R7 again for the switch; a plain char assignment switches on A.
 */
struct ent3 { unsigned char a, b, c; };
extern struct ent3 xdata power_wake_port_table[10];
extern unsigned char xdata power_wake_table_index;
void power_set_wake_block_mode(unsigned char n);

/*
 * power_apply_wake_block_mode - take byte 0 of the current wake table entry (power_wake_port_table[
 * power_wake_table_index], 3 bytes per entry), keep its low five bits (the kind, as in the wake table list record)
 * and, for kinds 0..12, pass the kind to power_set_wake_block_mode. Other kinds do nothing.
 * Caller: power_poll_wake_sources (twice).
 */
void power_apply_wake_block_mode(void)
{
    unsigned char kind;

    kind = (unsigned long)(power_wake_port_table[power_wake_table_index].a & 0x1f);
    switch (kind) {
    case 0: kind = 0; break;
    case 1: kind = 1; break;
    case 2: kind = 2; break;
    case 3: kind = 3; break;
    case 4: kind = 4; break;
    case 5: kind = 5; break;
    case 6: kind = 6; break;
    case 7: kind = 7; break;
    case 8: kind = 8; break;
    case 9: kind = 9; break;
    case 10: kind = 10; break;
    case 11: kind = 11; break;
    case 12: kind = 12; break;
    default: return;
    }
    power_set_wake_block_mode(kind);
}
