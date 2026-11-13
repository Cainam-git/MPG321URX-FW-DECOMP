/* pq_color_matrix_rebuild  (FUN_a013ae00)
 *
 * Build the three rows of the colour matrix from the stored settings and program them.
 * Name basis: proven - Q12 coefficients from the ROM tables and the stored gains, written by the matrix
 *   register routine
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013ae00 @ 0xa013ae00-0xa013b42c, flags -mcpu=v8 -O3 -g -msoft-float (the float arithmetic is libgcc
 * soft-float calls: __floatsisf, __mulsf3, __extendsfdf2, __adddf3, __fixdfsi).
 * Source forms the exact build depends on:
 *  - sine_q12 and the 3x3 product are static helpers inlined by GCC (the product as mul3(a, b, r): GCC then keeps
 *    the bases of a and r in registers in that order); pq_color_matrix_set_scale is an inlined static copy of the
 *    routine of that name;
 *  - the arrays are declared m2, m1, h, out (the firmware's stack order fp-48, fp-88, fp-128, fp-152);
 *  - the second parameter is read into a local before the sign test, and the test is written 'first >= 0' first;
 *  - 'chroma_scale << 5' and 'first << 5' (a multiplication by 32 is reassociated by GCC);
 *  - scale is converted as (float)(int)scale (an unsigned char operand gives a signed conversion plus a 256.0f
 *    correction);
 *  - the sine table and the third parameter are declared as DAT_001a56b4_w and pq_color_matrix_param_third: these spellings set
 *    the GCSE hash order of their address registers, which decides the register allocation of the sine block
 *    (%o7 for 0xa802cbbd, %o1 for chroma_scale << 16, %o0 for the table address).
 */

/* Fixed-point scales used in the matrix. */
#define Q12            4096    /* 1.0 in Q12 */
#define Q12_HALF       0x800   /* rounding term (half of Q12) */
#define MATRIX_ROWS    3
#define MATRIX_OUTPUT_GAIN_SHIFT 4   /* each stored gain is scaled up by this (the entry is scaled down by 4) */
#define MATRIX_WEIGHT_SHIFT      5   /* chroma_scale and the first parameter (both x / 128) are scaled up by this */
#define TRIG_TABLE_SIZE 0x40    /* steps in a quarter turn of the sine table */

extern unsigned char pq_color_matrix_scale;
extern signed char pq_color_matrix_param_first;
extern unsigned char pq_color_matrix_param_second;
extern unsigned short pq_color_gains[];
extern unsigned char pq_color_matrix_flags;
extern unsigned char pq_color_matrix_param_third;
extern const int pq_color_matrix_pre[3][3];
extern const int pq_color_matrix_post[3][3];
extern const int DAT_001a56b4_w[];
union matrix_value { unsigned short w; struct { unsigned char hi, lo; } b; };
extern void pq_color_matrix_write(unsigned char en, int mode, union matrix_value *m, unsigned int mask);

static void pq_color_matrix_set_scale(unsigned char v)
{
    pq_color_matrix_scale = v;
}

/* Sine of angle a in Q12, 256 steps per turn (sine_q12(a + 0x40) is the cosine). The 65-word table at 0x1A56B4
   holds a rising quarter of a sine (0, 100, 201, ..., 4094, 4096); the two top bits of a select the quarter:
   0 -> tab[i], 0x40 -> tab[0x40 - i], 0x80 -> -tab[i], otherwise -> -tab[0x40 - i], with i = a & 0x3F. */
static int sine_q12(unsigned char a)
{
    unsigned char i = a & 0x3f;

    switch (a & 0xc0) {
    case 0x00:
        return DAT_001a56b4_w[i];
    case 0x40:
        return DAT_001a56b4_w[TRIG_TABLE_SIZE - i];
    case 0x80:
        return -DAT_001a56b4_w[i];
    default:
        return -DAT_001a56b4_w[TRIG_TABLE_SIZE - i];
    }
}

/* 3x3 product r = a x b, each entry rounded to Q12. */
static void mul3(const int (*a)[3], const int (*b)[3], int (*r)[3])
{
    unsigned char i, j, k;
    int s;

    for (i = 0; i < MATRIX_ROWS; i++) {
        for (j = 0; j < MATRIX_ROWS; j++) {
            s = 0;
            for (k = 0; k < MATRIX_ROWS; k++)
                s += a[i][k] * b[k][j];
            r[i][j] = (s + Q12_HALF) >> 12;
        }
    }
}

/*
 * Rebuild the 3x3 colour matrix from the three stored parameters and the three gains, and program it.
 *
 *   scale  the overall scale, x / 128 (0x80 = 1.0); stored to pq_color_matrix_scale first
 *
 * All values are Q12 (4096 = 1.0). The fixed matrix pq_color_matrix_pre holds the RGB to YCbCr coefficients
 * (row 0 = 1051, 2064, 401 = 0.257, 0.504, 0.098), pq_color_matrix_post the YCbCr to RGB ones (4769 = 1.164).
 * The result is post x m1, where m1 = h x pre with row 0 replaced:
 *  - row 0 (Y) is the pre row scaled by the first parameter / 128 (the byte read unsigned);
 *  - rows 1 and 2 (Cb, Cr) are turned by the angle in the third parameter (256 steps per turn) and scaled by
 *    chroma_scale = second * |first| / 128 (h has zero row and column 0).
 * Each entry is then scaled by scale / 128 (soft-float) and multiplied by the gain of its row
 * (pq_color_gains[row], 4096 = 1.0). A negative entry is written as its magnitude with bits 10..15 set
 * (| 0xF400). Rows 0..2 go to pq_color_matrix_write with bits 0 and 1 of pq_color_matrix_flags.
 *
 * Callers: ShowLogo (scale 0x80), the setters of the three parameters and the gains
 * (pq_color_matrix_set_param_*, pq_color_matrix_set_*_gain(s), pq_api_set_color_gain) and sys_api_config,
 * which pass the stored pq_color_matrix_scale.
 */
void pq_color_matrix_rebuild(unsigned char scale)
{
    int m2[3][3];
    int m1[3][3];
    int h[3][3];
    unsigned short out[3][4];
    unsigned char i, j;
    unsigned char second;
    unsigned short chroma_scale;
    int s;

    pq_color_matrix_set_scale(scale);
    for (i = 0; i < MATRIX_ROWS; i++)
        h[i][0] = 0;
    for (i = 0; i < MATRIX_ROWS; i++)
        h[0][i] = 0;
    second = pq_color_matrix_param_second;
    /* Both arms give second * |first| / 128 (256 - byte = |first| for a negative first parameter). */
    if (pq_color_matrix_param_first >= 0)
        chroma_scale = second * (unsigned char)pq_color_matrix_param_first >> 7;
    else
        chroma_scale = second * (0x100 - (unsigned char)pq_color_matrix_param_first) / 128;
    /* Rotation of Cb / Cr by the third parameter: cos, sin / -sin, cos. */
    h[1][1] = ((chroma_scale << MATRIX_WEIGHT_SHIFT) * sine_q12(pq_color_matrix_param_third + 0x40) + Q12_HALF) >> 12;
    h[1][2] = ((chroma_scale << MATRIX_WEIGHT_SHIFT) * sine_q12(pq_color_matrix_param_third) + Q12_HALF) >> 12;
    h[2][1] = (-sine_q12(pq_color_matrix_param_third) * (chroma_scale << MATRIX_WEIGHT_SHIFT) + Q12_HALF) >> 12;
    h[2][2] = (sine_q12(pq_color_matrix_param_third + 0x40) * (chroma_scale << MATRIX_WEIGHT_SHIFT) + Q12_HALF) >> 12;
    mul3(h, pq_color_matrix_pre, m1);
    /* Row 0 (Y) does not pass through h: the pre row scaled by the first parameter, read as an unsigned byte. */
    for (j = 0; j < MATRIX_ROWS; j++)
        m1[0][j] = (pq_color_matrix_pre[0][j] * ((unsigned char)pq_color_matrix_param_first << MATRIX_WEIGHT_SHIFT) + Q12_HALF) >> 12;
    mul3(pq_color_matrix_post, m1, m2);
    /* Scale the whole matrix by scale / 128 (soft-float). */
    for (i = 0; i < MATRIX_ROWS; i++)
        for (j = 0; j < MATRIX_ROWS; j++)
            m2[i][j] = (int)((float)m2[i][j] * (float)(int)scale * 0.0078125f + 0.5);
    /* Multiply by the gain of the row (4096 = 1.0); a negative value becomes magnitude | 0xF400. */
    for (i = 0; i < MATRIX_ROWS; i++) {
        for (j = 0; j < MATRIX_ROWS; j++) {
            s = (((m2[i][j] + 8) >> 4) * (pq_color_gains[i] << MATRIX_OUTPUT_GAIN_SHIFT) + Q12_HALF) >> 12;
            if (s < 0)
                s = ((s ^ 0xffff) + 1) | 0xf400;
            out[i][j] = s;
        }
    }
    pq_color_matrix_write(pq_color_matrix_flags & 1, (pq_color_matrix_flags >> 1) & 1, (union matrix_value *)out, 7);
}
