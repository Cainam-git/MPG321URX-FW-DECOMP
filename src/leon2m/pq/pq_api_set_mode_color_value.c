/* pq_api_set_mode_color_value  (FUN_a014ce84)
 *
 * Store one colour value of a picture mode and re-apply the mode if it is active.
 * Name basis: derived - ids 6..35 map to bytes of the 3-byte colour entries; re-applies when the mode is the
 *   current one
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014ce84 @ 0xa014ce84-0xa014d3d4, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: one case per id in ascending order (jump table at 0xe3628 for ids
 * 6..35); GCC shares the call blocks of the three ids of a triple, and the call is a tail call.
 */

#define SYS_CONFIG_PICTURE_MODE 0xb     /* stSysConfig +0xB: the current picture mode */

/* Picture modes whose triple is changed here (see pq_apply_picture_mode). */
#define PICTURE_MODE_WARM       1       /* part record +6..8, the factory menu row Warm 50 */
#define PICTURE_MODE_NORMAL     4       /* +9..0xB, Normal 65 */
#define PICTURE_MODE_COOL       7       /* +0x12..0x14, Cool 93 */

extern unsigned char part_record[];
extern unsigned char sys_config[];
extern void pq_apply_picture_mode(unsigned char);

/*
 * Store colour value number id in the part record and, when asked to and the value belongs to the current picture
 * mode, apply that mode again.
 *
 *   id     6..35, numbered as in pq_api_get_mode_color_value; any other id does nothing
 *   value  the new value
 *   apply  non-zero: re-apply the mode when it is the current one
 *
 * The values form red / green / blue triples, one per picture mode:
 *
 *   ids     bytes        picture mode
 *   6..8    6..8         1 (Warm 50)
 *   9..11   9..0xB       4 (Normal 65)
 *   12..14  0xC..0xE     5
 *   15..17  0xF..0x11    6
 *   18..20  0x12..0x14   7 (Cool 93)
 *   21..23  0x15..0x17   8
 *   24..26  0x21..0x23   15
 *   27..29  0x18..0x1A   9
 *   30..32  0x1B..0x1D   10
 *   33..35  0x1E..0x20   11
 *
 * pq_user_apply_mode_colors calls it with ids 0..5, for which nothing happens.
 */
void pq_api_set_mode_color_value(int id, unsigned char value, unsigned char apply)
{
    switch (id) {
    case 6:
        part_record[0x6] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_WARM)
            pq_apply_picture_mode(PICTURE_MODE_WARM);
        break;
    case 7:
        part_record[0x7] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_WARM)
            pq_apply_picture_mode(PICTURE_MODE_WARM);
        break;
    case 8:
        part_record[0x8] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_WARM)
            pq_apply_picture_mode(PICTURE_MODE_WARM);
        break;
    case 9:
        part_record[0x9] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_NORMAL)
            pq_apply_picture_mode(PICTURE_MODE_NORMAL);
        break;
    case 10:
        part_record[0xa] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_NORMAL)
            pq_apply_picture_mode(PICTURE_MODE_NORMAL);
        break;
    case 11:
        part_record[0xb] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_NORMAL)
            pq_apply_picture_mode(PICTURE_MODE_NORMAL);
        break;
    case 12:
        part_record[0xc] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x5)
            pq_apply_picture_mode(0x5);
        break;
    case 13:
        part_record[0xd] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x5)
            pq_apply_picture_mode(0x5);
        break;
    case 14:
        part_record[0xe] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x5)
            pq_apply_picture_mode(0x5);
        break;
    case 15:
        part_record[0xf] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x6)
            pq_apply_picture_mode(0x6);
        break;
    case 16:
        part_record[0x10] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x6)
            pq_apply_picture_mode(0x6);
        break;
    case 17:
        part_record[0x11] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x6)
            pq_apply_picture_mode(0x6);
        break;
    case 18:
        part_record[0x12] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_COOL)
            pq_apply_picture_mode(PICTURE_MODE_COOL);
        break;
    case 19:
        part_record[0x13] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_COOL)
            pq_apply_picture_mode(PICTURE_MODE_COOL);
        break;
    case 20:
        part_record[0x14] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == PICTURE_MODE_COOL)
            pq_apply_picture_mode(PICTURE_MODE_COOL);
        break;
    case 21:
        part_record[0x15] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x8)
            pq_apply_picture_mode(0x8);
        break;
    case 22:
        part_record[0x16] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x8)
            pq_apply_picture_mode(0x8);
        break;
    case 23:
        part_record[0x17] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x8)
            pq_apply_picture_mode(0x8);
        break;
    case 24:
        part_record[0x21] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xf)
            pq_apply_picture_mode(0xf);
        break;
    case 25:
        part_record[0x22] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xf)
            pq_apply_picture_mode(0xf);
        break;
    case 26:
        part_record[0x23] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xf)
            pq_apply_picture_mode(0xf);
        break;
    case 27:
        part_record[0x18] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x9)
            pq_apply_picture_mode(0x9);
        break;
    case 28:
        part_record[0x19] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x9)
            pq_apply_picture_mode(0x9);
        break;
    case 29:
        part_record[0x1a] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0x9)
            pq_apply_picture_mode(0x9);
        break;
    case 30:
        part_record[0x1b] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xa)
            pq_apply_picture_mode(0xa);
        break;
    case 31:
        part_record[0x1c] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xa)
            pq_apply_picture_mode(0xa);
        break;
    case 32:
        part_record[0x1d] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xa)
            pq_apply_picture_mode(0xa);
        break;
    case 33:
        part_record[0x1e] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xb)
            pq_apply_picture_mode(0xb);
        break;
    case 34:
        part_record[0x1f] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xb)
            pq_apply_picture_mode(0xb);
        break;
    case 35:
        part_record[0x20] = value;
        if (apply && sys_config[SYS_CONFIG_PICTURE_MODE] == 0xb)
            pq_apply_picture_mode(0xb);
        break;
    }
}
