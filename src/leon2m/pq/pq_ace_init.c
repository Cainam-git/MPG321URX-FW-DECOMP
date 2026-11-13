/* pq_ace_init  (FUN_a00f793c)
 *
 * Initialise the four ACE selector blocks with their default tables.
 * Name basis: proven - prints 'Config ACE'; called from sys_init_picture_blocks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f793c @ 0xa00f793c, flags -mcpu=v8 -O3 -g.
 * Source form: the neighbouring routines pq_select_window (pq_select_window), pq_ace_configure (pq_ace_configure, here
 * with the record passed by value), pq_ace_write_curve (pq_ace_write_curve), pq_ace_disable_for_window (pq_ace_disable_for_window),
 * the three level-table writers (pq_window_write_level_table, pq_window_write_level_table_second, pq_window_write_level_table_third), pq_window_disable_stages
 * (pq_window_disable_stages) and pq_window_disable (pq_window_disable) are copied here as static functions so that GCC inlines
 * every call; the four windows are written out one after another; the configuration record is a local struct
 * filled field by field in the order value, bit6, bit7.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the picture-window and ACE blocks, as the routines copied below use them. */
#define WINDOW_SELECT_A    0xcf00ec84   /* bits 0..1: picture window that window settings go to */
#define WINDOW_SELECT_B    0xcf00e980   /* bits 0..1: the same window number */
#define WINDOW_CTRL_01     0xcf00ec80   /* bit 0 / 1: window 0 / 1 on (pq_window_enable / _disable) */
#define WINDOW_CTRL_23     0xcf00eca8   /* bit 0 / 1: window 2 / 3 on */
#define WINDOW_REG_EE40    0xcf00ee40   /* pq_window_enable sets bits 0..1 (window 0) or 2..3 (window 1) */
#define WINDOW_REG_EE68    0xcf00ee68   /* the same for windows 2 and 3 */
#define REG_EE50           0xcf00ee50
#define ACE_CTRL           0xcf00ee80   /* bits 1..2: window for ACE access; bit 4 + window: ACE on */
#define ACE_CONFIG         0xcf00eec0   /* bits 7, 6, 2..3 from struct ace_config; bit 5 cleared for a curve */
#define ACE_CURVE_CTRL     0xcf00eec4   /* low nibble kept; 0x5x before a curve, 0xDx after it, then bit 7 cleared */
#define ACE_CURVE_DATA     0xcf00eec8   /* curve points, low byte then high byte */
#define STAGE_ENABLE_A     0xcf00ef00   /* bits 6..2: stages 0..4 of pq_window_disable_stages */
#define LEVEL_TABLE_CTRL   0xcf00ef30   /* bit 1 cleared while a table is written; bits 7, 6, 4 = stages 5..7 */
#define LEVEL_TABLE_SELECT 0xcf00ef34   /* 1 = first 24-entry table, 2 = second, 0 = 17-entry table */
#define LEVEL_TABLE_INDEX  0xcf00ef38
#define LEVEL_TABLE_DATA   0xcf00ef3c

#define ACE_WINDOWS        4
#define LEVEL_NEUTRAL      0x80         /* value written to an entry when no table is given (second and third table) */
#define ALL_STAGES         0xff
#define ALL_MATRIX_PARTS   0xff         /* pq_color_matrix_write mask: three rows and three offsets */

/* A curve for the ACE block (pq_ace_default_curve has this form): points[0..last_point]. */
struct ace_curve {
    unsigned char last_point;
    unsigned short points[1];
};
/* A level table: entry i is written when bit i of mask is set. */
struct level_table {
    unsigned int mask;
    unsigned char values[24];
};
struct level_table17 {
    unsigned int mask;
    unsigned char values[17];
};
/* The ACE configuration handed to pq_ace_configure. */
struct ace_config {
    unsigned char bit7;                 /* to ACE_CONFIG bit 7 */
    unsigned char bit6;                 /* to ACE_CONFIG bit 6 */
    unsigned char value;                /* 0, 8 or 16: code 0, 1 or 2 in ACE_CONFIG bits 2..3; printed */
};

extern unsigned char pq_selected_window;
extern struct ace_curve pq_ace_default_curve;
extern void reg_table_port_delay(void);
extern void panel_wait_sync_pulse(void);
extern void pq_color_matrix_write(unsigned char, unsigned char, void *, unsigned char);
extern int dbg_printf(const char *fmt, ...);

/* The routines below are copies of the firmware's own routines next to this one; every call is inlined. */

/* pq_select_window: make window the target of the window settings. */
static void select_window(unsigned int window)
{
    if (pq_selected_window != window) {
        R(WINDOW_SELECT_A) = (R(WINDOW_SELECT_A) & 0xfc) | window;
        R(WINDOW_SELECT_B) = (R(WINDOW_SELECT_B) & 0xfc) | window;
        pq_selected_window = window;
    }
}

/* pq_ace_configure (here with the record passed by value). */
static void ace_configure(struct ace_config config)
{
    unsigned char code = 0;

    switch (config.value) {
    case 0:
        code = 0;
        break;
    case 8:
        code = 1;
        break;
    case 16:
        code = 2;
        break;
    }
    R(ACE_CTRL) = (R(ACE_CTRL) & 0xf9) | (pq_selected_window << 1);
    R(ACE_CONFIG) = (R(ACE_CONFIG) & 0x3a) | (config.bit7 << 7) | (config.bit6 << 6) | (code << 2);
    dbg_printf("Config ACE (%d) : (%d)\r\n", pq_selected_window, config.value);
}

/* pq_ace_write_curve: stream a curve (0 = the default curve) into the ACE block of the selected window, wait
   for a sync pulse, then switch ACE on for that window. */
static void ace_write_curve(struct ace_curve *curve)
{
    unsigned char i;
    unsigned char ctrl;
    struct ace_curve *source;

    R(ACE_CTRL) = (R(ACE_CTRL) & 0xf9) | (pq_selected_window << 1);
    R(ACE_CONFIG) &= ~0x20;
    ctrl = (R(ACE_CURVE_CTRL) & 0xf) | 0x50;
    R(ACE_CURVE_CTRL) = ctrl;
    if (curve == 0)
        source = &pq_ace_default_curve;
    else
        source = curve;
    i = 0;
    do {
        R(ACE_CURVE_DATA) = source->points[i] & 0xff;
        reg_table_port_delay();
        R(ACE_CURVE_DATA) = source->points[i] >> 8;
        i++;
        reg_table_port_delay();
    } while (i <= source->last_point);
    R(ACE_CURVE_CTRL) = ctrl | 0x90;
    panel_wait_sync_pulse();
    R(ACE_CTRL) = (R(ACE_CTRL) | (1 << (pq_selected_window + 4))) & 0xff;
    R(ACE_CURVE_CTRL) &= ~0x80;
}

/* pq_ace_disable_for_window: switch ACE off for the selected window. */
static void ace_disable_for_window(void)
{
    R(ACE_CTRL) = (unsigned char)(R(ACE_CTRL) & ~(1 << (pq_selected_window + 4)));
}

/* pq_window_write_level_table: the first 24-entry table, or zeros. */
static void write_level_table_first(struct level_table *table)
{
    unsigned char i;

    R(LEVEL_TABLE_CTRL) &= ~2;
    R(LEVEL_TABLE_SELECT) = 1;
    for (i = 0; i <= 0x17; i++) {
        if (table) {
            if ((table->mask >> i) & 1) {
                R(LEVEL_TABLE_INDEX) = i;
                R(LEVEL_TABLE_DATA) = table->values[i];
            }
        } else {
            R(LEVEL_TABLE_INDEX) = i;
            R(LEVEL_TABLE_DATA) = 0;
        }
    }
    R(LEVEL_TABLE_CTRL) |= 2;
}

/* pq_window_write_level_table_second: the second 24-entry table, or 0x80 in every entry. */
static void write_level_table_second(struct level_table *table)
{
    unsigned char i;

    R(LEVEL_TABLE_CTRL) &= ~2;
    R(LEVEL_TABLE_SELECT) = 2;
    for (i = 0; i <= 0x17; i++) {
        if (table) {
            if ((table->mask >> i) & 1) {
                R(LEVEL_TABLE_INDEX) = i;
                R(LEVEL_TABLE_DATA) = table->values[i];
            }
        } else {
            R(LEVEL_TABLE_INDEX) = i;
            R(LEVEL_TABLE_DATA) = LEVEL_NEUTRAL;
        }
    }
    R(LEVEL_TABLE_CTRL) |= 2;
}

/* pq_window_write_level_table_third: the 17-entry table, or 0x80 in every entry. */
static void write_level_table_third(struct level_table17 *table)
{
    unsigned char i;

    R(LEVEL_TABLE_CTRL) &= ~2;
    R(LEVEL_TABLE_SELECT) = 0;
    for (i = 0; i <= 0x10; i++) {
        if (table) {
            if ((table->mask >> i) & 1) {
                R(LEVEL_TABLE_INDEX) = i;
                R(LEVEL_TABLE_DATA) = table->values[i];
            }
        } else {
            R(LEVEL_TABLE_INDEX) = i;
            R(LEVEL_TABLE_DATA) = LEVEL_NEUTRAL;
        }
    }
    R(LEVEL_TABLE_CTRL) |= 2;
}

/* pq_window_disable_stages: clear the enable bit of each stage in mask; when none of stages 5..7 is left on,
   bit 0 of LEVEL_TABLE_CTRL is cleared too. */
static void disable_stages(unsigned int mask)
{
    if (mask & 1)
        R(STAGE_ENABLE_A) &= ~0x40u;
    if (mask & 2)
        R(STAGE_ENABLE_A) &= ~0x20u;
    if (mask & 4)
        R(STAGE_ENABLE_A) &= ~0x10u;
    if (mask & 8)
        R(STAGE_ENABLE_A) &= ~8u;
    if (mask & 0x10)
        R(STAGE_ENABLE_A) &= ~4u;
    if (mask & 0x20)
        R(LEVEL_TABLE_CTRL) &= ~0x80u;
    if (mask & 0x40)
        R(LEVEL_TABLE_CTRL) &= ~0x40u;
    if (mask & 0x80)
        R(LEVEL_TABLE_CTRL) &= ~0x10u;
    if ((R(LEVEL_TABLE_CTRL) & 0xe0) == 0)
        R(LEVEL_TABLE_CTRL) &= ~1u;
}

/* pq_window_disable: switch picture window 0..3 off. */
static void window_disable(int window)
{
    if (window == 0)
        R(WINDOW_CTRL_01) &= 0xfe;
    else if (window == 1)
        R(WINDOW_CTRL_01) &= 0xfd;
    else if (window == 2)
        R(WINDOW_CTRL_23) &= 0xfe;
    else if (window == 3)
        R(WINDOW_CTRL_23) &= 0xfd;
}

/*
 * Put the ACE (automatic contrast) block of all four picture windows into its start state.
 *
 * Called by sys_init_picture_blocks (part of System_Initialize).
 *
 * Phases, in order:
 *   1. For windows 3, 2, 1 and 0 in turn: select the window; write the default colour matrix in full
 *      (pq_color_matrix_write with no matrix: gains 0x100, offsets 0x80) with bit 6 of its control register
 *      set; configure ACE with {0, 0, 16}; stream the default curve (pq_ace_default_curve) and switch ACE on for
 *      the window; then switch it off again; fill the two 24-entry level tables with 0 and 0x80 and the
 *      17-entry table with 0x80; switch off all eight stages.
 *   2. Common bits: WINDOW_REG_EE40 bits 6..7 cleared and bit 4 set, WINDOW_REG_EE68 bit 6 set, REG_EE50
 *      cleared, and in both window control registers bits 2..3 and bits 4..5 set to 2.
 *   3. Switch all four picture windows off.
 */
void pq_ace_init(void)
{
    struct ace_config config;

    config.value = 16;
    config.bit6 = 0;
    config.bit7 = 0;

    /* 1. Each window, from 3 down to 0. */
    select_window(3);
    pq_color_matrix_write(1, 2, 0, ALL_MATRIX_PARTS);
    ace_configure(config);
    ace_write_curve(0);
    ace_disable_for_window();
    write_level_table_first(0);
    write_level_table_second(0);
    write_level_table_third(0);
    disable_stages(ALL_STAGES);
    select_window(2);
    pq_color_matrix_write(1, 2, 0, ALL_MATRIX_PARTS);
    ace_configure(config);
    ace_write_curve(0);
    ace_disable_for_window();
    write_level_table_first(0);
    write_level_table_second(0);
    write_level_table_third(0);
    disable_stages(ALL_STAGES);
    select_window(1);
    pq_color_matrix_write(1, 2, 0, ALL_MATRIX_PARTS);
    ace_configure(config);
    ace_write_curve(0);
    ace_disable_for_window();
    write_level_table_first(0);
    write_level_table_second(0);
    write_level_table_third(0);
    disable_stages(ALL_STAGES);
    select_window(0);
    pq_color_matrix_write(1, 2, 0, ALL_MATRIX_PARTS);
    ace_configure(config);
    ace_write_curve(0);
    ace_disable_for_window();
    write_level_table_first(0);
    write_level_table_second(0);
    write_level_table_third(0);
    disable_stages(ALL_STAGES);

    /* 2. Common bits. */
    R(WINDOW_REG_EE40) &= 0x3f;
    R(WINDOW_REG_EE40) |= 0x10;
    R(WINDOW_REG_EE68) = (R(WINDOW_REG_EE68) | 0x40) & 0xff;
    R(REG_EE50) = 0;
    R(WINDOW_CTRL_01) = (R(WINDOW_CTRL_01) & 0xf3) | 8;
    R(WINDOW_CTRL_01) = (R(WINDOW_CTRL_01) & 0xcf) | 0x20;
    R(WINDOW_CTRL_23) = (R(WINDOW_CTRL_23) & 0xf3) | 8;
    R(WINDOW_CTRL_23) = (R(WINDOW_CTRL_23) & 0xcf) | 0x20;

    /* 3. All windows off. */
    window_disable(0);
    window_disable(1);
    window_disable(2);
    window_disable(3);
}
