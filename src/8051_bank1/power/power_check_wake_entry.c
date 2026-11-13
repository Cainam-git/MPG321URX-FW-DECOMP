/* power_check_wake_entry  (FUN_CODE_52be)
 *
 * Check the input named by the current wake-up table entry for activity.
 * Returns: entry kind that fired, or 0x0D
 * Note: When the entry did not fire, DisplayPort receiver entries (kinds 7 to 10) found anywhere in the table
 *   are checked as well.
 * Name basis: derived - switch on the entry kind of table 0xA62F: sync meter checks, port flags,
 *   dp_check_mrx0_wake/_mrx1_wake; then the DisplayPort receiver kinds 7..10 looked up in the whole table
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_52be @ 0x52be..0x54af (497 B), built with OPTIMIZE(8,SPEED) LARGE (c51opts).
 * Locals: kind at XDATA 0xA474, result at XDATA 0xA475. Switch jump table at 0x52F4.
 * Source forms the exact build depends on:
 * - index_or_kind first holds the record index (power_wake_table_index), then the kind, which places header in R6
 *   and the kind in R7 as in the firmware.
 * - In each of the cases 1..6 a statement that compiles to no code stands after 'power_wake_entry_option_flag =
 *   option;' (DBG_OFF: a loop that never runs, the form a print call takes when it is switched off with a
 *   'while (0)' prefix macro). With it Keil keeps the equal bodies of cases 1, 2 and 4 as the three copies of the
 *   firmware (jump table 0x52F4: 1 -> 0x533D, 2 -> 0x5354, 4 -> 0x5382); without it every C51 release from 9.02a
 *   to 9.56 merges them into one (451 of 497 bytes). What the statement printed is not in the firmware.
 */
#include <reg51.h>
/* One entry of the wake-up port table (message type 9 from the main processor, 'SetZPArry'). */
struct list_record {
    unsigned char header;   /* bits 0..4 = kind, bit 5 = option for the port signal check */
    unsigned char byte_1;   /* time slot of the entry, read by power_poll_wake_sources */
    unsigned char byte_2;
};
extern struct list_record xdata power_wake_port_table[10];
extern unsigned char xdata power_wake_table_index;
extern bit power_wake_entry_option_flag;
bit power_check_sync_input(void);
bit power_check_sync_input_alt(void);
bit power_test_adc_key_level(void);
bit power_check_port_signal(unsigned char pg);
bit power_test_port_wake_flag(unsigned char n);
bit dp_mrx_detect_adc_rise(unsigned char ch);
bit dp_check_mrx0_wake(void);
bit dp_check_mrx1_wake(void);
bit power_test_wake_status_type11(void);
unsigned char power_find_wake_entry(unsigned char key);

#define RECORD_KIND_MASK   0x1F
#define RECORD_OPTION_BIT  5
#define NO_WAKE            0x0D  /* result when nothing fired */
#define ENTRY_ABSENT       0xFF  /* power_find_wake_entry: no entry of that kind */
/* Kinds that test a DP receiver: 7 and 8 receiver 0, 9 and 10 receiver 1. */
#define KIND_DP_RX0_A      7
#define KIND_DP_RX0_B      8
#define KIND_DP_RX1_A      9
#define KIND_DP_RX1_B      10

/* a print call switched off in this build */
#define DBG_OFF() while (0) { }

/* power_check_wake_entry - test the input named by the current entry of the wake-up port table
 * (power_wake_port_table[power_wake_table_index]).
 * Returns the entry's kind (0..12) when its test fired, else 0x0D. Called by power_poll_wake_sources (up to
 * twice per call); sys_main turns the kind into its wake code.
 *
 * Phases:
 *   1. Read the entry: kind = bits 0..4, option = bit 5.
 *   2. Test by kind:
 *        0       sync meter (power_check_sync_input, then the _alt set-up), then the ADC key level;
 *        1..6    port wake flag or port signal, with the option bit passed in power_wake_entry_option_flag;
 *                port 0 for kinds 1, 2 and 4, port 1 for kind 3, port 2 for kind 5, port 3 for kind 6;
 *        7, 8    DP receiver 0: analog level rise, else dp_check_mrx0_wake;
 *        9, 10   DP receiver 1: the same with dp_check_mrx1_wake;
 *        11, 12  power_test_wake_status_type11;
 *        other   nothing.
 *   3. When nothing fired, test the DP receivers anyway for each DP kind (7..10) that has an entry anywhere in the
 *      table; the last one that fires gives the result.
 */
unsigned char power_check_wake_entry(void)
{
    unsigned char header, index_or_kind, kind, result;
    bit option;

    /* 1. Current entry. */
    index_or_kind = power_wake_table_index;
    header = power_wake_port_table[index_or_kind].header;
    index_or_kind = header & RECORD_KIND_MASK;
    option = (header >> RECORD_OPTION_BIT) & 1;
    kind = index_or_kind;
    result = 0;
    /* 2. Test of the entry's kind. */
    switch (index_or_kind) {
    case 0:
        if ((result = power_check_sync_input()) != 0) break;
        if ((result = power_check_sync_input_alt()) != 0) break;
        result = power_test_adc_key_level();
        break;
    case 1:
        power_wake_entry_option_flag = option;
        DBG_OFF();
        result = power_test_port_wake_flag(0) | power_check_port_signal(0);
        break;
    case 2:
        power_wake_entry_option_flag = option;
        DBG_OFF();
        result = power_test_port_wake_flag(0) | power_check_port_signal(0);
        break;
    case 3:
        power_wake_entry_option_flag = option;
        DBG_OFF();
        result = power_test_port_wake_flag(1) | power_check_port_signal(1);
        break;
    case 4:
        power_wake_entry_option_flag = option;
        DBG_OFF();
        result = power_test_port_wake_flag(0) | power_check_port_signal(0);
        break;
    case 5:
        power_wake_entry_option_flag = option;
        DBG_OFF();
        result = power_test_port_wake_flag(2) | power_check_port_signal(2);
        break;
    case 6:
        power_wake_entry_option_flag = option;
        DBG_OFF();
        result = power_test_port_wake_flag(3) | power_check_port_signal(3);
        break;
    case KIND_DP_RX0_A:
        if ((result = dp_mrx_detect_adc_rise(0)) != 0) break;
        result = dp_check_mrx0_wake();
        break;
    case KIND_DP_RX0_B:
        if ((result = dp_mrx_detect_adc_rise(0)) != 0) break;
        result = dp_check_mrx0_wake();
        break;
    case KIND_DP_RX1_A:
        if ((result = dp_mrx_detect_adc_rise(1)) != 0) break;
        result = dp_check_mrx1_wake();
        break;
    case KIND_DP_RX1_B:
        if ((result = dp_mrx_detect_adc_rise(1)) != 0) break;
        result = dp_check_mrx1_wake();
        break;
    case 11:
    case 12:
        result = power_test_wake_status_type11();
        break;
    default:
        result = 0;
        break;
    }
    if (result == 1) result = kind;
    else result = NO_WAKE;
    /* 3. Nothing fired: DP receivers listed anywhere in the table. */
    if (result == NO_WAKE) {
        if (power_find_wake_entry(KIND_DP_RX0_A) != ENTRY_ABSENT) {
            if (dp_mrx_detect_adc_rise(0) == 0) { if (dp_check_mrx0_wake()) result = KIND_DP_RX0_A; } else { result = KIND_DP_RX0_A; }
        }
        if (power_find_wake_entry(KIND_DP_RX0_B) != ENTRY_ABSENT) {
            if (dp_mrx_detect_adc_rise(0) == 0) { if (dp_check_mrx0_wake()) result = KIND_DP_RX0_B; } else { result = KIND_DP_RX0_B; }
        }
        if (power_find_wake_entry(KIND_DP_RX1_A) != ENTRY_ABSENT) {
            if (dp_mrx_detect_adc_rise(1) == 0) { if (dp_check_mrx1_wake()) result = KIND_DP_RX1_A; } else { result = KIND_DP_RX1_A; }
        }
        if (power_find_wake_entry(KIND_DP_RX1_B) != ENTRY_ABSENT) {
            if (dp_mrx_detect_adc_rise(1) == 0) { if (dp_check_mrx1_wake()) result = KIND_DP_RX1_B; } else { result = KIND_DP_RX1_B; }
        }
    }
    return result;
}
