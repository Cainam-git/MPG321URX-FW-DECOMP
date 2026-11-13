/* sys_set_key_long_press_alt  (FUN_a008edb8)
 *
 * Give one key a second event code that it sends when held long.
 *   id: key event code, 0xFF = clear all
 *   on: alternate key code, 0 = off
 * Note: Mask 0xA802AFD8, codes 0xA802AFC8[]; a short press still sends the key's own code on release.
 * Name basis: derived - mode 3 in sys_scan_keys_post_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008edb8 @ 0xa008edb8-0xa008ee6c (45 words), flags -mcpu=v8 -O3 -g.
 * Keeps a 16-bit mask in sys_key_long_alt_mask. id == 0xff with on == 0 clears the mask first. Then it searches the 16
 * two-byte ROM entries at 0x10051f for the one whose second byte (offset +1) equals id; the found index (& 0xf,
 * 16 = not found wraps to 0) selects entry idx: index 0 changes nothing (early return), otherwise
 * sys_key_long_codes[idx] = on and mask bit idx is set (on != 0) or cleared.
 * Source form: as sys_set_key_repeat (same table search): two loop counters, unsigned int i and the u8-truncated idx.
 */
extern const unsigned char sys_key_code_table[];
extern unsigned char sys_key_long_codes[];
extern unsigned short sys_key_long_alt_mask;

#define KEY_ID_ALL 0xff                 /* key event code meaning every key */

/*
 * Give a key a second event code that it sends when held for the long-press time, or take it away.
 *
 *   id   key event code (0x40..0x4E); KEY_ID_ALL with on == 0 clears the whole mask
 *   on   the second key code; 0 = none
 *
 * sys_key_long_alt_mask holds one bit per entry of sys_key_code_table, bit 0 being entry 0. The table is searched
 * for the entry whose second byte is id; entry 0 and a code that is not in the table change nothing more. For
 * the entry found, sys_key_long_codes[entry] = on and its mask bit is set when on is not 0, else cleared.
 * Called by sys_set_key_modes_for_menu and App_Initialize.
 */
void sys_set_key_long_press_alt(unsigned char id, unsigned char on)
{
    unsigned int i;
    unsigned int idx;           /* table entry found; 16 (not found) wraps to 0 below */

    if (id == KEY_ID_ALL) {
        if (on == 0)
            sys_key_long_alt_mask = 0;
    }

    i = 0;
    idx = 0;
    do {
        if (sys_key_code_table[idx * 2 + 1] == id)
            break;
        i++;
        idx = (unsigned char)i;
    } while (idx <= 15);

    idx &= 0xf;
    if (idx == 0)
        return;

    sys_key_long_codes[idx] = on;
    if (on) {
        sys_key_long_alt_mask |= (1 << idx);
    } else {
        sys_key_long_alt_mask &= ~(1 << idx);
    }
}
