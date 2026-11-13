/* startup_init_display_clocks  (FUN_a0112db0)
 *
 * Set up the display clocks, reset the blocks and load the ROM settings.
 * Name basis: derived - start-up step 5: clocks, block reset with a delay, memory select, ROM settings
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0112db0 @ 0xa0112db0..0xa0112fb8 (130 words), flags -mcpu=v8 -O3 -g.
 * Source form: the register stores stay in source order and the 12 stores of 0xC0 are written out one by one;
 * the table index is an unsigned char counted with i <= 20.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned char sys_frc_config_index, sys_frc_config_index2;
extern const unsigned char sys_frc_bit_group_table[][2][22];
extern void reg_write24_bytes_settle(unsigned int, unsigned int);
extern void timer_sleep_ticks(int);
extern void sys_ddr_init(void);
extern void sys_frc_apply_bit_groups(unsigned char, unsigned char);
extern void sys_frc_load_rom_settings(void);

/* Registers cleared first (named by address). 0xCF011A00 is the register the firmware calls FRC_CTRL. */
#define REG_11800        0xcf011800     /* cleared first */
#define FRC_CTRL         0xcf011a00
#define REG_15A00        0xcf015a00
#define REG_11670        0xcf011670
#define REG_12440        0xcf012440     /* bits 1, 6 and 7 set */
#define REG_14780        0xcf014780     /* bit 2 set */

/* Four clock values written through reg_write24_bytes_settle. The first three sit in register sets that have a
   control byte 4 bytes below the value (set to 0x80 before) and a register 0x10 above it (bit 7 set after). */
#define CLK1_CTRL        0xcf0129c0
#define CLK1_VALUE       0xcf0129c4
#define CLK1_ENABLE      0xcf0129d4
#define CLK2_CTRL        0xcf014080
#define CLK2_VALUE       0xcf014084
#define CLK2_ENABLE      0xcf014094
#define CLK3_CTRL        0xcf012b00
#define CLK3_VALUE       0xcf012b04
#define CLK3_ENABLE      0xcf012b14
#define CLK4_VALUE       0xcf012b44     /* no control byte and no enable bit are written for this one */
#define CLK_VALUE_A      0x2b2aaa       /* values of CLK1 / CLK2 / CLK3 */
#define CLK4_VALUE_B     0x4b8000
#define CLK_CTRL_START   0x80

/* Block reset: these three registers get 0x3F, register 0xCF013408 is cleared and, after a wait, set to 0x4F. */
#define BLOCK_RESET_A    0xcf013410
#define BLOCK_RESET_B    0xcf013414
#define BLOCK_RESET_C    0xcf01341c
#define BLOCK_RESET_CTRL 0xcf013408
#define BLOCK_RESET_MASK 0x3f
#define BLOCK_RESET_RUN  0x4f

#define BIT_GROUPS       21             /* entries of one row of sys_frc_bit_group_table used here (0..20) */
#define FRC_CHANNEL_INIT 0xc0

/*
 * Start-up step 5: set up the clocks and resets of the display pipe and load the frame-rate converter from
 * ROM. Called once by the start-up routine, after the frame-rate converter's first config index has been set
 * (sys_frc_set_config_index), with mode 0.
 *   mode  stored as the second config index (sys_frc_config_index2) that picks the row of ROM bit groups
 *
 * Order:
 *   1. clear 0xCF011800, FRC_CTRL, 0xCF015A00 and 0xCF011670; set bits in 0xCF012440 (0xC2) and 0xCF014780 (4);
 *      store mode;
 *   2. write four 24-bit clock values (reg_write24_bytes_settle): the first three each between a control byte
 *      of 0x80 and an enable bit 7, the fourth alone;
 *   3. block reset: write 0x3F to three registers, clear 0xCF013408, wait timer_sleep_ticks(2), then write
 *      0x4F to 0xCF013408. The wait ends only when the timer interrupt counts it down, so it never returns
 *      with the timer interrupt off;
 *   4. set up the working memory (sys_ddr_init);
 *   5. for entries 0..20 of the row sys_frc_bit_group_table[config index][mode]: sys_frc_apply_bit_groups
 *      (entry number, entry byte);
 *   6. write 0xC0 to the twelve registers 0xCF011A40..0xCF011A6C, load the ROM settings
 *      (sys_frc_load_rom_settings), then 0xFF to 0xCF011804 and 0x3F to 0xCF011F30 and 0xCF011F3C.
 */
void startup_init_display_clocks(unsigned char mode)
{
    unsigned char i;

    R(REG_11800) = 0;
    R(FRC_CTRL) = 0;
    R(REG_15A00) = 0;
    R(REG_11670) = 0;
    R(REG_12440) |= 0xc2;
    R(REG_14780) |= 4;
    sys_frc_config_index2 = mode;
    R(CLK1_CTRL) = CLK_CTRL_START;
    reg_write24_bytes_settle(CLK1_VALUE, CLK_VALUE_A);
    R(CLK1_ENABLE) |= 0x80;
    R(CLK2_CTRL) = CLK_CTRL_START;
    reg_write24_bytes_settle(CLK2_VALUE, CLK_VALUE_A);
    R(CLK2_ENABLE) |= 0x80;
    R(CLK3_CTRL) = CLK_CTRL_START;
    reg_write24_bytes_settle(CLK3_VALUE, CLK_VALUE_A);
    R(CLK3_ENABLE) |= 0x80;
    reg_write24_bytes_settle(CLK4_VALUE, CLK4_VALUE_B);
    R(BLOCK_RESET_A) = BLOCK_RESET_MASK;
    R(BLOCK_RESET_B) = BLOCK_RESET_MASK;
    R(BLOCK_RESET_C) = BLOCK_RESET_MASK;
    R(BLOCK_RESET_CTRL) = 0;
    timer_sleep_ticks(2);
    R(BLOCK_RESET_CTRL) = BLOCK_RESET_RUN;
    sys_ddr_init();
    for (i = 0; i <= BIT_GROUPS - 1; i++)
        sys_frc_apply_bit_groups(i, sys_frc_bit_group_table[sys_frc_config_index][sys_frc_config_index2][i]);
    R(0xcf011a40) = FRC_CHANNEL_INIT;
    R(0xcf011a44) = FRC_CHANNEL_INIT;
    R(0xcf011a48) = FRC_CHANNEL_INIT;
    R(0xcf011a4c) = FRC_CHANNEL_INIT;
    R(0xcf011a50) = FRC_CHANNEL_INIT;
    R(0xcf011a54) = FRC_CHANNEL_INIT;
    R(0xcf011a58) = FRC_CHANNEL_INIT;
    R(0xcf011a5c) = FRC_CHANNEL_INIT;
    R(0xcf011a60) = FRC_CHANNEL_INIT;
    R(0xcf011a64) = FRC_CHANNEL_INIT;
    R(0xcf011a68) = FRC_CHANNEL_INIT;
    R(0xcf011a6c) = FRC_CHANNEL_INIT;
    sys_frc_load_rom_settings();
    R(0xcf011804) = 0xff;
    R(0xcf011f30) = 0x3f;
    R(0xcf011f3c) = 0x3f;
}
