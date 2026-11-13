/* SetFRCCHRW  (FUN_a01086fc)
 *
 * Program the converter's read and write windows for a channel.
 * Name basis: proven - prints '---->SetFRCCHRW(%d) %d' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01086fc @ 0xa01086fc-0xa0108e4c (468 words), flags -mcpu=v8 -O3 -g -msoft-float (float code).
 * Libgcc and libm callees: __floatsisf __floatsisf, __addsf3 __addsf3 (the +65536.0f fix-up of an unsigned
 * short, ROM 0x19a2d0 = 0x47800000), __mulsf3 __mulsf3, __divsf3 __divsf3, __extendsfdf2 __extendsfdf2,
 * __fixunsdfsi __fixunsdfsi, ceil ceil (declared with its real name).
 * Source forms the exact build depends on:
 *  - the FRC_REG_1DDC value is an unsigned char local set in an if ('pad_to_32 = 0; if (width & 0x1f) pad_to_32 =
 *    ...;') and stored after it. A '?:' store, a '?:' into the local or an if/else all move the store address
 *    above the branch and change the register choices;
 *  - the float result is converted with '(unsigned int)ceil(...)' (__fixunsdfsi); '(int)' would call __fixdfsi;
 *  - on_request is copied into the plain unsigned char local `on`, which the register allocator spills to
 *    [%fp-9]. Taking its address would block the two tail calls of reg_write16_bytes;
 *  - one test '(size matches) || bit15' clears `on`, giving one block with two predecessors;
 *  - original_lines = lines is taken after the line width read, right before the first
 *    input_block_get_status_bit2 test; the rounding is written 'lines / 2 * 2 + 2' and 'width / 8 * 8 + 8';
 *  - line_ratio = ratio / 100 and line_ratio / 2 are two statements;
 *  - frame_lines = lines + 0x14 comes before the second input_block_get_status_bit2 call, and both arms of the
 *    line length are written in full (the compiler shares only the '/ frame_lines' conversion);
 *  - 'if (line_length % 2 == 1) line_length++;' keeps the increment out of line ('& 1' keeps it inline);
 *  - gap is rounded with two full arms and written as (unsigned short)gap; gap and rest are unsigned short;
 *  - the on / off tails are written in full in each of the three arms (the compiler merges the two 'on' tails
 *    into one print(4, 1) block);
 *  - bit 15 of +0x3A is a bit-field in a nested struct (first field = most significant bit): the struct alias set
 *    keeps the FRC_REG_1CC0 store before the re-load of that halfword;
 *  - volatile only on the 0xcf... registers.
 */

/* The input timing of a channel (a copy of channel record +6, 0x3C bytes); fields as in struct input_timing. */
struct input_timing {
    unsigned short line_rate;           /* +0x00: 100 Hz units (timing field 0) */
    unsigned short refresh_rate;        /* +0x02: tenths of a hertz (timing field 1) */
    unsigned short half_0x04, half_0x06;
    unsigned short half_0x08;           /* +0x08: timing field 4 */
    unsigned short half_0x0a;
    unsigned short half_0x0c;           /* +0x0C: timing field 7 */
    unsigned short half_0x0e;           /* +0x0E: timing field 8 */
    unsigned char pad10[0x3a - 0x10];
    struct { unsigned short bit15 : 1, low_bits : 15; } flags_0x3a;     /* +0x3A */
};
extern int dbg_printf(const char *fmt, ...);
extern unsigned short input_adc_get_line_width(void);
extern unsigned char input_block_get_status_bit2(unsigned char ch);
extern void reg_write16_bytes(volatile unsigned int *r, unsigned int v);
extern void pq_block_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern int timer_sleep_ticks(int ms);
extern double ceil(double);

#define R(a) (*(volatile unsigned int *)(a))
#define RP(a) ((volatile unsigned int *)(a))

/* Converter channel 4: bit 4 of these three registers is set and cleared together. */
#define FRC_CTRL            R(0xcf011a00)
#define FRC_CHANNEL4_ON     0x10
#define REG_CF011800        R(0xcf011800)
#define REG_CF011BF8        R(0xcf011bf8)
#define FRC_REG_16D0        R(0xcf0116d0)       /* line_ratio - 1 when switched on by request, else 0 */

/* Bit 4 of these four registers depends on bit 15 of timing +0x3A. */
#define REG_CF011A84        R(0xcf011a84)
#define REG_CF011A88        R(0xcf011a88)
#define REG_CF011A8C        R(0xcf011a8c)
#define FRC_REG_1DC8        R(0xcf011dc8)
#define FRC_REG_1DDC        R(0xcf011ddc)       /* pixels from width up to the next multiple of 32 */

#define FRC_REG_1C00        R(0xcf011c00)
#define FRC_1C00_LOW_RATE   0x40                /* bit 6: rate term / line_ratio below LOW_RATE_LIMIT */
#define LOW_RATE_LIMIT      40
#define FRC_REG_1CC0        R(0xcf011cc0)
#define FRC_REG_1CC4        R(0xcf011cc4)
#define FRC_REG_1CC8        R(0xcf011cc8)
#define FRC_REG_1EC0        R(0xcf011ec0)

/* 16-bit register pairs (reg_write16_bytes): the line and the frame of the window. */
#define FRC_LINE_LENGTH     RP(0xcf011ce0)      /* line_length = 8 + gap + width + rest */
#define FRC_REG_1CD0        RP(0xcf011cd0)
#define FRC_REG_1CD8        RP(0xcf011cd8)
#define FRC_REG_1CE8        RP(0xcf011ce8)
#define FRC_REG_1CF0        RP(0xcf011cf0)
#define FRC_FRAME_LINES     RP(0xcf011cf8)      /* frame_lines = 8 + 4 + 8 + lines */
#define FRC_H_PART0         RP(0xcf011e80)      /* the line in four parts: 8, rest, gap, width */
#define FRC_H_PART1         RP(0xcf011e88)
#define FRC_H_PART2         RP(0xcf011e90)
#define FRC_H_PART3         RP(0xcf011e98)
#define FRC_V_PART0         RP(0xcf011ea0)      /* the frame in four parts: 8, 4, 8, lines */
#define FRC_V_PART1         RP(0xcf011ea8)
#define FRC_V_PART2         RP(0xcf011eb0)
#define FRC_V_PART3         RP(0xcf011eb8)
#define FRC_REG_1D00        RP(0xcf011d00)
#define FRC_REG_1D08        RP(0xcf011d08)
#define FRC_REG_1D10        RP(0xcf011d10)
#define FRC_REG_1D18        RP(0xcf011d18)

#define FRC_CHANNEL         4                   /* the converter channel named in the print */
#define LINE_FRONT_PART     8
#define FRAME_EXTRA_LINES   0x14                /* 8 + 4 + 8 lines added to the frame */
#define REST_MAX            8000
#define BLK_REG_90          0x90

/*
 * Set up the converter's window (line and frame lengths and their parts) for an input and switch converter
 * channel 4 on or off.
 *
 *   channel       picture block / input block of the channel; the callers pass 0
 *   timing        a copy of the channel's input timing (channel record +6)
 *   width, lines  size of the picture; width is rounded up to a multiple of 8 and lines to an even number when
 *                 status bit 2 of the input block is set
 *   double_lines  with status bit 2 set: timing +0xA counts twice in the line length
 *   on_request    1: switch channel 4 on; the callers pass 0
 *   mode          1: take the line width from input_adc_get_line_width and write only the line registers; the
 *                 callers pass 0
 *
 * Called from sys_channel0_apply_timing_block and sys_channel_apply_output_timing.
 *
 * Phases:
 *  1. The line width (timing +8, or the analog line width in mode 1); rounding of width and lines.
 *  2. on_request is dropped when timing +0xC / +0xE already equal width and the original lines, or when bit 15
 *     of timing +0x3A is set.
 *  3. A rate term (line width * timing +0xA / 1000 * refresh rate / 10000) and line_ratio (half of timing +0xE
 *     over the original lines, at least 1).
 *  4. line_length = ceil(line width * timing +0xA (doubled, see double_lines) / line_ratio / frame_lines), made
 *     even; it is split into 8, gap (a third of line_length - width, rounded up to even), width and rest (at
 *     most 8000; the excess goes into gap). FRC_REG_1C00 bit 6 is set when rate term / line_ratio is below 40.
 *  5. Mode 1 stops after writing the line registers. Otherwise all line and frame registers are written.
 *  6. Bit 15 of timing +0x3A picks the values of 0xCF011CC4 and of bit 7 of 0xCF011EC0; after a wait of 100
 *     ticks channel 4 is switched on (on_request or bit 15) or off, with the print '---->SetFRCCHRW(4) 1 / 0'.
 *  7. Bit 15 set: the bit-4 settings of 0xCF011A84..A8C and the padding to 32 pixels; else other bit-4
 *     settings and bit 5 of register 0x90 of the channel's picture block. Last, a quarter of timing +0xA goes to
 *     0xCF011D08 and 0 to 0xCF011D00 / D18 / D10.
 */
void SetFRCCHRW(unsigned char channel, struct input_timing *timing, unsigned short width, unsigned short lines, unsigned char double_lines,
                  unsigned char on_request, unsigned char mode)
{
    unsigned char on = on_request;
    unsigned char pad_to_32;
    unsigned short frame_lines, line_width, original_lines, line_ratio, line_length, rest, rate_term, gap;

    /* 1. The line width and the rounding of the size. */
    if (mode == 1)
        line_width = input_adc_get_line_width();
    else
        line_width = timing->half_0x08;
    original_lines = lines;
    if (input_block_get_status_bit2(channel) == 1) {
        if (lines & 1)
            lines = lines / 2 * 2 + 2;
        if (width & 7)
            width = width / 8 * 8 + 8;
    }

    /* 2. No switch-on when the size is unchanged or bit 15 is set (bit 15 switches it on by itself below). */
    if ((timing->half_0x0c == width && timing->half_0x0e == original_lines) || timing->flags_0x3a.bit15)
        on = 0;

    /* 3. The rate term and the line ratio. */
    rate_term = (unsigned int)line_width * timing->half_0x0a / 1000 * timing->refresh_rate / 10000;
    if (mode == 0)
        REG_CF011800 &= ~FRC_CHANNEL4_ON;
    line_ratio = (unsigned short)((unsigned int)(timing->half_0x0e * 100) / original_lines) / 100;
    line_ratio = line_ratio / 2;
    if (line_ratio == 0)
        line_ratio = 1;

    /* 4. The line length and its parts. */
    frame_lines = lines + FRAME_EXTRA_LINES;
    if (input_block_get_status_bit2(channel) && double_lines)
        line_length = (unsigned int)ceil((double)((float)line_width * (timing->half_0x0a * 2) / line_ratio / frame_lines));
    else
        line_length = (unsigned int)ceil((double)((float)line_width * timing->half_0x0a / line_ratio / frame_lines));
    if (line_length % 2 == 1)
        line_length++;
    if ((unsigned short)(line_length - width) % 6 == 0)
        gap = (unsigned short)(line_length - width) / 6 * 2;
    else
        gap = (unsigned short)(line_length - width) / 6 * 2 + 2;
    rest = line_length - LINE_FRONT_PART; rest = rest - gap - width;
    if (rate_term / line_ratio < LOW_RATE_LIMIT)
        FRC_REG_1C00 |= FRC_1C00_LOW_RATE;
    else
        FRC_REG_1C00 &= ~FRC_1C00_LOW_RATE;
    if (rest > REST_MAX) {
        gap = gap + rest - REST_MAX;
        rest = REST_MAX;
    }

    /* 5. Mode 1: only the line. */
    if (mode == 1) {
        reg_write16_bytes(FRC_LINE_LENGTH, line_length);
        reg_write16_bytes(FRC_REG_1CD0, (unsigned short)gap);
        reg_write16_bytes(FRC_H_PART0, LINE_FRONT_PART);
        reg_write16_bytes(FRC_H_PART1, rest);
        reg_write16_bytes(FRC_H_PART2, (unsigned short)gap);
        return;
    }
    reg_write16_bytes(FRC_LINE_LENGTH, line_length);
    reg_write16_bytes(FRC_FRAME_LINES, frame_lines);
    reg_write16_bytes(FRC_REG_1CD8, width);
    reg_write16_bytes(FRC_REG_1CF0, lines);
    reg_write16_bytes(FRC_REG_1CD0, (unsigned short)gap);
    reg_write16_bytes(FRC_REG_1CE8, 8);
    reg_write16_bytes(FRC_H_PART0, LINE_FRONT_PART);
    reg_write16_bytes(FRC_H_PART1, rest);
    reg_write16_bytes(FRC_H_PART2, (unsigned short)gap);
    reg_write16_bytes(FRC_H_PART3, width);
    reg_write16_bytes(FRC_V_PART0, 8);
    reg_write16_bytes(FRC_V_PART1, 4);
    reg_write16_bytes(FRC_V_PART2, 8);
    reg_write16_bytes(FRC_V_PART3, lines);

    /* 6. Switch channel 4 on or off. */
    FRC_REG_1CC0 = 0;
    if (timing->flags_0x3a.bit15) {
        FRC_REG_1CC4 = 0x20;
        FRC_REG_1EC0 &= ~0x80;
    } else {
        FRC_REG_1CC4 = 0xa0;
        FRC_REG_1EC0 |= 0x80;
    }
    FRC_REG_1CC8 = 0;
    timer_sleep_ticks(100);
    if (on) {
        FRC_REG_16D0 = line_ratio - 1;
        dbg_printf("\033[1;31m---->SetFRCCHRW(%d) %d\r\n\033[m", FRC_CHANNEL, 1);
        REG_CF011800 |= FRC_CHANNEL4_ON;
        FRC_CTRL |= FRC_CHANNEL4_ON;
        REG_CF011BF8 |= FRC_CHANNEL4_ON;
    } else if (timing->flags_0x3a.bit15) {
        FRC_REG_16D0 = 0;
        dbg_printf("\033[1;31m---->SetFRCCHRW(%d) %d\r\n\033[m", FRC_CHANNEL, 1);
        REG_CF011800 |= FRC_CHANNEL4_ON;
        FRC_CTRL |= FRC_CHANNEL4_ON;
        REG_CF011BF8 |= FRC_CHANNEL4_ON;
    } else {
        FRC_REG_16D0 = 0;
        dbg_printf("\033[1;31m---->SetFRCCHRW(%d) %d\r\n\033[m", FRC_CHANNEL, 0);
        REG_CF011BF8 &= ~FRC_CHANNEL4_ON;
        FRC_CTRL &= ~FRC_CHANNEL4_ON;
        REG_CF011800 &= ~FRC_CHANNEL4_ON;
    }

    /* 7. Settings that depend on bit 15. */
    if (timing->flags_0x3a.bit15) {
        REG_CF011A84 |= 0x10;
        REG_CF011A88 |= 0x10;
        REG_CF011A8C &= ~0x10;
        FRC_REG_1DC8 &= ~0x10;
        pad_to_32 = 0;
        if (width & 0x1f)
            pad_to_32 = width / 32 * 32 - width + 0x20;
        FRC_REG_1DDC = pad_to_32;
    } else {
        FRC_REG_1DC8 &= ~0x10;
        REG_CF011A84 |= 0x10;
        REG_CF011A88 &= ~0x10;
        REG_CF011A8C &= ~0x10;
        pq_block_update_bits(channel, BLK_REG_90, 0x20, 1);
    }
    reg_write16_bytes(FRC_REG_1D08, timing->half_0x0a >> 2);
    reg_write16_bytes(FRC_REG_1D00, 0);
    reg_write16_bytes(FRC_REG_1D18, 0);
    reg_write16_bytes(FRC_REG_1D10, 0);
}
