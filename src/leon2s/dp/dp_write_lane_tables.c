/* dp_write_lane_tables  (FUN_a00b0e54)
 *
 * Build two nibble tables from the stored lane data and write them to the port's registers.
 * Name basis: descriptive - from the table at 0xA8078768
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0e54 @ 0xa00b0e54-0xa00b1028, -mcpu=v8 -Os -g.
 * The two tables are initialised from the constants at 0xa00b4e0c / 0xa00b4e14 with memcpy (lib_memcpy). The
 * unused local x keeps its place in the declarations.
 * Source form: table_b[v] is stored directly in each arm, the i <= 3 test written first in both arms.
 */
extern unsigned char dp_port_lane_units[];
extern unsigned char dp_get_port_swap(void);
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");

#define LANE_MAP_REG(o) (*(volatile unsigned int *)(0xcf0117c0 + (o)))

/* Writes the lane registers 0xcf0117c0..0xcf0117ec from the five-entry table dp_port_lane_units.
 *
 * Two eight-byte tables start as table_a = {0, 1, 2, 3, 4, 5, 8, 9} and table_b = {0, 1, 2, 3, 4, 5, 6, 7}.
 * For every entry i = 0..4 of dp_port_lane_units whose value v is 0..7: table_a[v] = i + 4, and table_b[v] is
 * 6 or 4 by the port swap (dp_get_port_swap) and by i: with the swap set 6 for i <= 3 and 4 for i = 4, without
 * it 4 for i <= 3 and 6 for i = 4. The registers then get two table entries each, the odd entry in the high
 * nibble: +0x00..+0x0c from table_b, +0x10..+0x1c from table_a; +0x20 = (units[3] << 4) | units[2];
 * +0x24 = 0x13; +0x28 = (units[1] << 4) | units[0]; +0x2c = units[4] | 0x70.
 *
 * Called by dp_init_port and dp_port_task.
 */
void dp_write_lane_tables(void)
{
    unsigned char table_a[8] = { 0, 1, 2, 3, 4, 5, 8, 9 };
    unsigned char table_b[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    unsigned char i, j, v, x;

    for (j = 0; j <= 7; j++) {
        for (i = 0; i <= 4; i++) {
            v = dp_port_lane_units[i];
            if (v == j) {
                table_a[v] = i + 4;
                if (dp_get_port_swap()) {
                    if (i <= 3)
                        table_b[v] = 6;
                    else
                        table_b[v] = 4;
                } else {
                    if (i <= 3)
                        table_b[v] = 4;
                    else
                        table_b[v] = 6;
                }
            }
        }
    }
    LANE_MAP_REG(0x00) = table_b[1] << 4 | table_b[0];
    LANE_MAP_REG(0x04) = table_b[3] << 4 | table_b[2];
    LANE_MAP_REG(0x08) = table_b[5] << 4 | table_b[4];
    LANE_MAP_REG(0x0c) = table_b[7] << 4 | table_b[6];
    LANE_MAP_REG(0x10) = table_a[1] << 4 | table_a[0];
    LANE_MAP_REG(0x14) = table_a[3] << 4 | table_a[2];
    LANE_MAP_REG(0x18) = table_a[5] << 4 | table_a[4];
    LANE_MAP_REG(0x1c) = table_a[7] << 4 | table_a[6];
    LANE_MAP_REG(0x20) = dp_port_lane_units[3] << 4 | dp_port_lane_units[2];
    LANE_MAP_REG(0x24) = 0x13;
    LANE_MAP_REG(0x28) = dp_port_lane_units[1] << 4 | dp_port_lane_units[0];
    LANE_MAP_REG(0x2c) = dp_port_lane_units[4] | 0x70;
}
