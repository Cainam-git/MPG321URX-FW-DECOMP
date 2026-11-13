/* input_csc_map_format_code  (FUN_a0100990)
 *
 * Map the stored format byte through a table of 42 cases.
 * Returns: code
 * Name basis: descriptive - 0x28 for an argument other than 4; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0100990 @ 0xa0100990-0xa0100a40 (176 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on (jump table at 0xa0584, 42 entries):
 *  - the result is an int initialised to 0x28 and returned as 'if (block != KEPT_FORMAT_BLOCK) return result;'
 *    (0xa0100998: bne to the shared exit with mov 0x28 in the delay slot);
 *  - one case body per value, cases 38 and 39 included, case 36 written before case 26;
 *  - the code is read into an unsigned short, and the codes returned unchanged are written '(unsigned char)code'
 *    (the 'and 0xff' of the default block);
 *  - case 41 keeps result = code without an assignment (its own jump table entry, 0xa01009d4).
 */
extern unsigned char input_csc_last_format_code;

#define KEPT_FORMAT_BLOCK 4     /* input_csc_write_mode_regs keeps the format code of block 4 only */
#define NOT_KEPT_RESULT   0x28  /* returned for every other block */

/*
 * Return the colour format code last programmed for block 4, folded onto a smaller set of codes.
 *
 *   block  input block; only block 4 has a kept format code (input_csc_last_format_code)
 *
 * Phases: any block other than 4 returns 0x28 at once; for block 4 the kept code is read and mapped:
 *   0, 1, 27 -> 2            2, 14, 16, 17, 18 -> 15      4, 5, 6 -> 3          8, 10, 11, 12 -> 9
 *   20, 22, 23, 24 -> 21     26, 36 -> 34                 28, 30..33 -> 29      34, 37, 38, 39 -> 35
 * Every other code (among them 3, 9, 15, 21, 29, 35, 41 and the codes above 41) is returned unchanged.
 * What the groups stand for is not shown by the code.
 *
 * Nothing in the firmware calls this routine.
 */
unsigned char input_csc_map_format_code(unsigned char block)
{
    unsigned short code;
    int result = NOT_KEPT_RESULT;

    if (block != KEPT_FORMAT_BLOCK)
        return result;
    code = input_csc_last_format_code;
    result = code;
    switch (result) {
    case 0:
        result = 2;
        break;
    case 1:
        result = 2;
        break;
    case 2:
        result = 15;
        break;
    case 3:
        result = (unsigned char)code;
        break;
    case 4:
        result = 3;
        break;
    case 5:
        result = 3;
        break;
    case 6:
        result = 3;
        break;
    case 7:
        result = (unsigned char)code;
        break;
    case 8:
        result = 9;
        break;
    case 9:
        result = (unsigned char)code;
        break;
    case 10:
        result = 9;
        break;
    case 11:
        result = 9;
        break;
    case 12:
        result = 9;
        break;
    case 13:
        result = (unsigned char)code;
        break;
    case 14:
        result = 15;
        break;
    case 15:
        result = (unsigned char)code;
        break;
    case 16:
        result = 15;
        break;
    case 17:
        result = 15;
        break;
    case 18:
        result = 15;
        break;
    case 19:
        result = (unsigned char)code;
        break;
    case 20:
        result = 21;
        break;
    case 21:
        result = (unsigned char)code;
        break;
    case 22:
        result = 21;
        break;
    case 23:
        result = 21;
        break;
    case 24:
        result = 21;
        break;
    case 25:
        result = (unsigned char)code;
        break;
    case 36:
        result = 34;
        break;
    case 26:
        result = 34;
        break;
    case 27:
        result = 2;
        break;
    case 28:
        result = 29;
        break;
    case 29:
        result = (unsigned char)code;
        break;
    case 30:
        result = 29;
        break;
    case 31:
        result = 29;
        break;
    case 32:
        result = 29;
        break;
    case 33:
        result = 29;
        break;
    case 34:
        result = 35;
        break;
    case 35:
        result = (unsigned char)code;
        break;
    case 37:
        result = 35;
        break;
    case 38:
        result = 35;
        break;
    case 39:
        result = 35;
        break;
    case 40:
        result = (unsigned char)code;
        break;
    case 41:
        /* result already holds the code */
        break;
    default:
        result = (unsigned char)code;
        break;
    }
    return result;
}
