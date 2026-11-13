/* input_port_table_find_code  (FUN_a0125198)
 *
 * Return the index of the input with a given port code.
 * Returns: index, 0xFC..0xFE for the virtual ports, else 0xFF
 * Name basis: derived - search of byte 0 of the eight port table entries
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0125198 @ 0xa0125198-0xa0125230 (38 words, leaf), flags -mcpu=v8 -O2 -g (-O3 -g gives the same code).
 * Source form: the index is stored into 'found' inside the loop before the break; after the loop 'if (i > 7)' selects
 * the code switch (the found path keeps its own i > 7 test and a copy of the first compare node, as in the firmware).
 * 'found' is a signed char (-1, -4, -3, -2) returned as unsigned char.
 */
/* Byte +0 of an entry of the port table in ROM (0x16 bytes each); see docs/DATA.md. */
struct port_table_entry { unsigned char code; unsigned char unused_01[0x15]; };
extern const struct port_table_entry port_table[];

/*
 * Return the index of the port table entry whose port code is `code`. When no entry has it, the virtual codes
 * 0x12, 0x13 and 0x14 give 0xFC, 0xFD and 0xFE, and any other code gives 0xFF.
 * Inverse of input_port_table_get_code.
 */
unsigned char input_port_table_find_code(unsigned char code)
{
    unsigned char i;
    signed char found = -1;

    for (i = 0; i <= 7; i++)
        if (port_table[i].code == code) {
            found = i;
            break;
        }
    if (i > 7)
        switch (code) {
        case 0x12:
            found = -4;
            break;
        case 0x13:
            found = -3;
            break;
        case 0x14:
            found = -2;
            break;
        }
    return found;
}
