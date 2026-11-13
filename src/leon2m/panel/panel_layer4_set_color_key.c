/* panel_layer4_set_color_key  (FUN_a010e0f4)
 *
 * Store a selector and two values of the fourth layer and write its control bits.
 * Name basis: descriptive - register pairs at 0xD0032xxx / 0xD003Axxx, control bits 5-6; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010e0f4 @ 0xa010e0f4-0xa010e448 (213 words), flags -mcpu=v8 -O3 -g.
 * Source form: select is an unsigned int parameter (the byte store uses the unmasked register); each channel has
 * its own switch.
 */
/* Stored settings of the fourth layer; only the bytes at +0x27..+0x37 are used here. */
struct layer_context {
    unsigned char pad[0x27];
    unsigned char key_select;           /* +0x27: last selector passed in */
    unsigned int pair1_first;           /* +0x28 */
    unsigned int pair1_second;          /* +0x2C */
    unsigned int pair2_first;           /* +0x30 */
    unsigned int pair2_second;          /* +0x34 */
};
extern struct layer_context panel_layer4_context_ch0, panel_layer4_context_ch1;

#define REG(address) (*(volatile unsigned int *)(address))

/* Registers of the fourth layer, for each channel in the first half (0xD0032xxx) and the second (0xD003Axxx). */
#define LAYER4_CH0_CTRL_HALF0          0xd0032004
#define LAYER4_CH0_CTRL_HALF1          0xd003a004
#define LAYER4_CH1_CTRL_HALF0          0xd0032008
#define LAYER4_CH1_CTRL_HALF1          0xd003a008
#define LAYER4_CH0_PAIR1_FIRST_HALF0   0xd0032120
#define LAYER4_CH0_PAIR1_FIRST_HALF1   0xd003a120
#define LAYER4_CH0_PAIR1_SECOND_HALF0  0xd0032124
#define LAYER4_CH0_PAIR1_SECOND_HALF1  0xd003a124
#define LAYER4_CH1_PAIR1_FIRST_HALF0   0xd0032128
#define LAYER4_CH1_PAIR1_FIRST_HALF1   0xd003a128
#define LAYER4_CH1_PAIR1_SECOND_HALF0  0xd003212c
#define LAYER4_CH1_PAIR1_SECOND_HALF1  0xd003a12c
#define LAYER4_CH0_PAIR2_FIRST_HALF0   0xd00321dc
#define LAYER4_CH0_PAIR2_FIRST_HALF1   0xd003a1dc
#define LAYER4_CH0_PAIR2_SECOND_HALF0  0xd00321e0
#define LAYER4_CH0_PAIR2_SECOND_HALF1  0xd003a1e0
#define LAYER4_CH1_PAIR2_FIRST_HALF0   0xd00321e4
#define LAYER4_CH1_PAIR2_FIRST_HALF1   0xd003a1e4
#define LAYER4_CH1_PAIR2_SECOND_HALF0  0xd00321e8
#define LAYER4_CH1_PAIR2_SECOND_HALF1  0xd003a1e8
#define CTRL_PAIR1_ON                  0x20     /* bit 5 of the control word */
#define CTRL_PAIR2_ON                  0x40     /* bit 6 */

/* Selector values, as in panel_layer_set_color_key. */
enum {
    KEY_SELECT_ALL_OFF  = 0,            /* both pairs off and cleared */
    KEY_SELECT_PAIR1_ON = 1,
    KEY_SELECT_PAIR1_OFF = 2,
    KEY_SELECT_PAIR2_ON = 3,
    KEY_SELECT_PAIR2_OFF = 4
};

/*
 * The fourth-layer version of panel_layer_set_color_key: switch one of the two value pairs on or off.
 *
 *   channel  0 for the channel-0 registers and context, 1 for channel 1; any other number uses the channel-0
 *            context and the channel-1 registers
 *   select   KEY_SELECT_*: which pair, on or off
 *   first    first value of the pair, used when a pair is switched on
 *   second   second value of the pair
 *
 * The selector and the pair are kept in the context and written to the pair's registers in both halves (0 when
 * switched off). The control word is read from the first half, bit 5 (pair 1) or bit 6 (pair 2) set or cleared,
 * and written to both halves; for a selector above 4 it is written back unchanged. Nothing in the image calls this
 * routine.
 */
void panel_layer4_set_color_key(unsigned char channel, unsigned int select, unsigned int first, unsigned int second)
{
    struct layer_context *context;
    unsigned int control;

    context = &panel_layer4_context_ch0;
    if (channel == 1) context = &panel_layer4_context_ch1;
    context->key_select = select;
    /* Each channel has its own registers; the control word is read once from the first half and written to both. */
    if (channel == 0) {
        control = REG(LAYER4_CH0_CTRL_HALF0);
        switch ((unsigned char)select) {
        case KEY_SELECT_ALL_OFF:
            context->pair1_first = 0;
            context->pair1_second = 0;
            context->pair2_first = 0;
            context->pair2_second = 0;
            REG(LAYER4_CH0_PAIR1_FIRST_HALF0) = 0;
            REG(LAYER4_CH0_PAIR1_FIRST_HALF1) = 0;
            REG(LAYER4_CH0_PAIR2_FIRST_HALF0) = 0;
            REG(LAYER4_CH0_PAIR2_FIRST_HALF1) = 0;
            REG(LAYER4_CH0_PAIR1_SECOND_HALF0) = 0;
            REG(LAYER4_CH0_PAIR1_SECOND_HALF1) = 0;
            REG(LAYER4_CH0_PAIR2_SECOND_HALF0) = 0;
            REG(LAYER4_CH0_PAIR2_SECOND_HALF1) = 0;
            control &= ~(CTRL_PAIR1_ON | CTRL_PAIR2_ON);
            break;
        case KEY_SELECT_PAIR1_ON:
            context->pair1_first = first;
            context->pair1_second = second;
            REG(LAYER4_CH0_PAIR1_FIRST_HALF0) = first;
            REG(LAYER4_CH0_PAIR1_FIRST_HALF1) = first;
            REG(LAYER4_CH0_PAIR1_SECOND_HALF0) = second;
            REG(LAYER4_CH0_PAIR1_SECOND_HALF1) = second;
            control |= CTRL_PAIR1_ON;
            break;
        case KEY_SELECT_PAIR1_OFF:
            context->pair1_first = 0;
            context->pair1_second = 0;
            REG(LAYER4_CH0_PAIR1_FIRST_HALF0) = 0;
            REG(LAYER4_CH0_PAIR1_FIRST_HALF1) = 0;
            REG(LAYER4_CH0_PAIR1_SECOND_HALF0) = 0;
            REG(LAYER4_CH0_PAIR1_SECOND_HALF1) = 0;
            control &= ~CTRL_PAIR1_ON;
            break;
        case KEY_SELECT_PAIR2_ON:
            context->pair2_first = first;
            context->pair2_second = second;
            REG(LAYER4_CH0_PAIR2_FIRST_HALF0) = first;
            REG(LAYER4_CH0_PAIR2_FIRST_HALF1) = first;
            REG(LAYER4_CH0_PAIR2_SECOND_HALF0) = second;
            REG(LAYER4_CH0_PAIR2_SECOND_HALF1) = second;
            control |= CTRL_PAIR2_ON;
            break;
        case KEY_SELECT_PAIR2_OFF:
            context->pair2_first = 0;
            context->pair2_second = 0;
            REG(LAYER4_CH0_PAIR2_FIRST_HALF0) = 0;
            REG(LAYER4_CH0_PAIR2_FIRST_HALF1) = 0;
            REG(LAYER4_CH0_PAIR2_SECOND_HALF0) = 0;
            REG(LAYER4_CH0_PAIR2_SECOND_HALF1) = 0;
            control &= ~CTRL_PAIR2_ON;
            break;
        }
        REG(LAYER4_CH0_CTRL_HALF0) = control;
        REG(LAYER4_CH0_CTRL_HALF1) = control;
    } else {
        control = REG(LAYER4_CH1_CTRL_HALF0);
        switch ((unsigned char)select) {
        case KEY_SELECT_ALL_OFF:
            context->pair1_first = 0;
            context->pair1_second = 0;
            context->pair2_first = 0;
            context->pair2_second = 0;
            REG(LAYER4_CH1_PAIR1_FIRST_HALF0) = 0;
            REG(LAYER4_CH1_PAIR1_FIRST_HALF1) = 0;
            REG(LAYER4_CH1_PAIR2_FIRST_HALF0) = 0;
            REG(LAYER4_CH1_PAIR2_FIRST_HALF1) = 0;
            REG(LAYER4_CH1_PAIR1_SECOND_HALF0) = 0;
            REG(LAYER4_CH1_PAIR1_SECOND_HALF1) = 0;
            REG(LAYER4_CH1_PAIR2_SECOND_HALF0) = 0;
            REG(LAYER4_CH1_PAIR2_SECOND_HALF1) = 0;
            control &= ~(CTRL_PAIR1_ON | CTRL_PAIR2_ON);
            break;
        case KEY_SELECT_PAIR1_ON:
            context->pair1_first = first;
            context->pair1_second = second;
            REG(LAYER4_CH1_PAIR1_FIRST_HALF0) = first;
            REG(LAYER4_CH1_PAIR1_FIRST_HALF1) = first;
            REG(LAYER4_CH1_PAIR1_SECOND_HALF0) = second;
            REG(LAYER4_CH1_PAIR1_SECOND_HALF1) = second;
            control |= CTRL_PAIR1_ON;
            break;
        case KEY_SELECT_PAIR1_OFF:
            context->pair1_first = 0;
            context->pair1_second = 0;
            REG(LAYER4_CH1_PAIR1_FIRST_HALF0) = 0;
            REG(LAYER4_CH1_PAIR1_FIRST_HALF1) = 0;
            REG(LAYER4_CH1_PAIR1_SECOND_HALF0) = 0;
            REG(LAYER4_CH1_PAIR1_SECOND_HALF1) = 0;
            control &= ~CTRL_PAIR1_ON;
            break;
        case KEY_SELECT_PAIR2_ON:
            context->pair2_first = first;
            context->pair2_second = second;
            REG(LAYER4_CH1_PAIR2_FIRST_HALF0) = first;
            REG(LAYER4_CH1_PAIR2_FIRST_HALF1) = first;
            REG(LAYER4_CH1_PAIR2_SECOND_HALF0) = second;
            REG(LAYER4_CH1_PAIR2_SECOND_HALF1) = second;
            control |= CTRL_PAIR2_ON;
            break;
        case KEY_SELECT_PAIR2_OFF:
            context->pair2_first = 0;
            context->pair2_second = 0;
            REG(LAYER4_CH1_PAIR2_FIRST_HALF0) = 0;
            REG(LAYER4_CH1_PAIR2_FIRST_HALF1) = 0;
            REG(LAYER4_CH1_PAIR2_SECOND_HALF0) = 0;
            REG(LAYER4_CH1_PAIR2_SECOND_HALF1) = 0;
            control &= ~CTRL_PAIR2_ON;
            break;
        }
        REG(LAYER4_CH1_CTRL_HALF0) = control;
        REG(LAYER4_CH1_CTRL_HALF1) = control;
    }
}
