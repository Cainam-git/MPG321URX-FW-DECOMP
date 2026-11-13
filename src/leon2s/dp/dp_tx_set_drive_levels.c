/* dp_tx_set_drive_levels  (FUN_a00aaf94)
 *
 * Set the voltage swing and pre-emphasis of the lanes of a DP output.
 *   port: output
 *   level
 *   mode: swing / pre-emphasis kind
 * Name basis: derived - level/mode pick an offset from table 0xA00B4DCC added to the base values 0xA80792B4
 *   (max 0x1F / 0xF); callers link training
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00aaf94 @ 0xa00aaf94-0xa00ab4a8 (1300 bytes), flags -mcpu=v8 -Os -g.
 * Source form: every output arm indexes the record with the variable port (the firmware materialises the
 * record address of the constant port the compare established); dp_tx_phy_reg_read8 is called inside each
 * level arm and its result passed straight to dp_tx_phy_reg_write8 (u8 value parameter); add_swing is an int
 * local, add_emphasis a u8 local; one u8 scratch sum holds each addition and the limit is written into the
 * record as 'sum > 0x1f ? 0x1f : sum' / 'sum > 0xf ? 0xf : sum'. The last write is a tail call.
 */
/* Per-output record of 16 bytes at dp_tx_drive_level_records: the values written to the lane registers, and the
 * base values they are computed from (the base values are stored by dp_tx_set_drive_level_base). */
struct dp_tx_drive_record {
    unsigned char swing[4];                     /* +0: swing of lanes 0..3 as written to the registers */
    unsigned char base_swing[4];                /* +4 */
    unsigned char pre_emphasis[4];              /* +8: pre-emphasis of lanes 0..3 as written to the registers */
    unsigned char base_pre_emphasis[4];         /* +0xC */
};
extern struct dp_tx_drive_record dp_tx_drive_level_records[];
extern const unsigned short dp_tx_drive_level_table[2][10];
extern unsigned int dp_tx_phy_reg_read8(unsigned int, unsigned short);
extern void dp_tx_phy_reg_write8(unsigned char, unsigned short, unsigned char);

#define record dp_tx_drive_level_records[port]
#define LANES_PER_OUTPUT 4                         /* lanes per output */

/*
 * Set the lane drive values of one DP output.
 *
 * The table dp_tx_drive_level_table has one row for output 0 and one for the other outputs. mode and level pick
 * the entry: mode 0 uses entries 0..3 (level 0..3), mode 1 entries 4..6 (level 0..2), mode 2 entries 7..8
 * (level 0..1), any other mode entry 9; a level out of range for its mode gives entry 0. The high byte of the
 * entry is added to the base swing of each lane, the low nibble to the base pre-emphasis of each lane; the sums
 * are limited to 0x1F and 0xF and kept in the record of the output.
 *
 * Then the registers of the output are written: its shared control register gets its low or high nibble
 * set to 0xF when level is not 0 and cleared when it is 0, followed by the four swing registers and the
 * pre-emphasis registers (output 0: one register per lane; the other outputs: two lanes per register, lane 1 or
 * 3 in the high nibble). Output 0 is in PHY unit 0, all others in PHY unit 1; outputs 1 and 2 share one control
 * register (low nibble for 1, high for 2) as do 3 and 4.
 *   port: output 0..4
 *   level: 0..3, see above; 0 also clears the control nibble
 *   mode: selects the group of table entries, see above
 */
void dp_tx_set_drive_levels(unsigned char port, unsigned char level, unsigned char mode)
{
    unsigned char row = port != 0;              /* table row: output 0, or the others */
    unsigned char idx = 0;
    unsigned char lane;
    unsigned char sum;
    int add_swing;
    unsigned char add_emphasis;

    if (mode == 0) {
        if (level <= 3)
            idx = level;
    } else if (mode == 1) {
        if (level <= 2)
            idx = level + 4;
    } else if (mode == 2) {
        if (level <= 1)
            idx = level + 7;
    } else
        idx = 9;
    add_swing = (dp_tx_drive_level_table[row][idx] & 0xff00) >> 8;
    add_emphasis = dp_tx_drive_level_table[row][idx] & 0xf;
    for (lane = 0; lane < LANES_PER_OUTPUT; lane++) {
        sum = record.base_swing[lane] + add_swing;
        record.swing[lane] = sum > 0x1f ? 0x1f : sum;
        sum = add_emphasis + record.base_pre_emphasis[lane];
        record.pre_emphasis[lane] = sum > 0xf ? 0xf : sum;
    }
    /* Output 0: PHY unit 0, one pre-emphasis register per lane. */
    if (port == 0) {
        if (level) {
            dp_tx_phy_reg_write8(0, 0x49, dp_tx_phy_reg_read8(0, 0x49) | 0xf);
        } else
            dp_tx_phy_reg_write8(0, 0x49, dp_tx_phy_reg_read8(0, 0x49) & 0xf0);
        dp_tx_phy_reg_write8(0, 0x4b, record.swing[0]);
        dp_tx_phy_reg_write8(0, 0x4c, record.swing[1]);
        dp_tx_phy_reg_write8(0, 0x4d, record.swing[2]);
        dp_tx_phy_reg_write8(0, 0x4e, record.swing[3]);
        dp_tx_phy_reg_write8(0, 0x45, record.pre_emphasis[0]);
        dp_tx_phy_reg_write8(0, 0x46, record.pre_emphasis[1]);
        dp_tx_phy_reg_write8(0, 0x47, record.pre_emphasis[2]);
        dp_tx_phy_reg_write8(0, 0x48, record.pre_emphasis[3]);
    } else if (port == 1) {  /* outputs 1..4: PHY unit 1, two lanes per pre-emphasis register */
        if (level)
            dp_tx_phy_reg_write8(1, 0x66, dp_tx_phy_reg_read8(1, 0x66) | 0xf);
        else
            dp_tx_phy_reg_write8(1, 0x66, dp_tx_phy_reg_read8(1, 0x66) & 0xf0);
        dp_tx_phy_reg_write8(1, 0x6f, record.swing[0]);
        dp_tx_phy_reg_write8(1, 0x70, record.swing[1]);
        dp_tx_phy_reg_write8(1, 0x71, record.swing[2]);
        dp_tx_phy_reg_write8(1, 0x72, record.swing[3]);
        dp_tx_phy_reg_write8(1, 0x62, (unsigned char)((record.pre_emphasis[1] << 4) + record.pre_emphasis[0]));
        dp_tx_phy_reg_write8(1, 0x63, (unsigned char)((record.pre_emphasis[3] << 4) + record.pre_emphasis[2]));
    } else if (port == 2) {  /* control register 0x66 again, high nibble */
        if (level)
            dp_tx_phy_reg_write8(1, 0x66, dp_tx_phy_reg_read8(1, 0x66) | 0xf0);
        else
            dp_tx_phy_reg_write8(1, 0x66, dp_tx_phy_reg_read8(1, 0x66) & 0xf);
        dp_tx_phy_reg_write8(1, 0x73, record.swing[0]);
        dp_tx_phy_reg_write8(1, 0x74, record.swing[1]);
        dp_tx_phy_reg_write8(1, 0x75, record.swing[2]);
        dp_tx_phy_reg_write8(1, 0x76, record.swing[3]);
        dp_tx_phy_reg_write8(1, 0x64, (unsigned char)((record.pre_emphasis[1] << 4) + record.pre_emphasis[0]));
        dp_tx_phy_reg_write8(1, 0x65, (unsigned char)((record.pre_emphasis[3] << 4) + record.pre_emphasis[2]));
    } else if (port == 3) {
        if (level)
            dp_tx_phy_reg_write8(1, 0x89, dp_tx_phy_reg_read8(1, 0x89) | 0xf);
        else
            dp_tx_phy_reg_write8(1, 0x89, dp_tx_phy_reg_read8(1, 0x89) & 0xf0);
        dp_tx_phy_reg_write8(1, 0x92, record.swing[0]);
        dp_tx_phy_reg_write8(1, 0x93, record.swing[1]);
        dp_tx_phy_reg_write8(1, 0x94, record.swing[2]);
        dp_tx_phy_reg_write8(1, 0x95, record.swing[3]);
        dp_tx_phy_reg_write8(1, 0x85, (unsigned char)((record.pre_emphasis[1] << 4) + record.pre_emphasis[0]));
        dp_tx_phy_reg_write8(1, 0x86, (unsigned char)((record.pre_emphasis[3] << 4) + record.pre_emphasis[2]));
    } else {
        if (level)
            dp_tx_phy_reg_write8(1, 0x89, dp_tx_phy_reg_read8(1, 0x89) | 0xf0);
        else
            dp_tx_phy_reg_write8(1, 0x89, dp_tx_phy_reg_read8(1, 0x89) & 0xf);
        dp_tx_phy_reg_write8(1, 0x96, record.swing[0]);
        dp_tx_phy_reg_write8(1, 0x97, record.swing[1]);
        dp_tx_phy_reg_write8(1, 0x98, record.swing[2]);
        dp_tx_phy_reg_write8(1, 0x99, record.swing[3]);
        dp_tx_phy_reg_write8(1, 0x87, (unsigned char)((record.pre_emphasis[1] << 4) + record.pre_emphasis[0]));
        dp_tx_phy_reg_write8(1, 0x88, (unsigned char)((record.pre_emphasis[3] << 4) + record.pre_emphasis[2]));
    }
}

#undef record
