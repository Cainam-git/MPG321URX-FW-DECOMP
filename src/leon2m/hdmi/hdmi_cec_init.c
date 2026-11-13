/* hdmi_cec_init  (FUN_a00fc200)
 *
 * Set up the CEC block and give one pin, chosen by the parameter, the CEC function.
 *   pin_index: which of four pins carries CEC, 0..3
 * Name basis: derived - fixed values to the block at 0xCF012000; pin function 1 of group 3 for the pin 0..3
 *   given by the parameter; called from System_Initialize with 0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc200 @ 0xa00fc200, flags -mcpu=v8 -O3 -g.
 * Source form: volatile only on the 0xcf0xxxxx registers. The three bytes are stored in the order own_address,
 * sender, operand (the store order decides the register choice). The divider is written in two arms, with
 * shift == 0 tested first. The pin switch has one case per value; other values skip the call.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the CEC block at 0xCF012000 written here (CEC_STATUS is the one hdmi_cec_receive_and_reply uses). */
#define CEC_REG_00       0xcf012000     /* also the register hdmi_cec_reset clears */
#define CEC_DIVIDER_REG  0xcf012004     /* 0x78 >> shift, as in hdmi_cec_set_clock_divider */
#define CEC_REG_1C       0xcf01201c
#define CEC_STATUS       0xcf012034
#define CEC_REG_44       0xcf012044
#define REG_1480         0xcf011480     /* bits 0..1: shift count for the divider */

#define CEC_PIN_GROUP    3              /* gpio_set_pin_function: pin group and function code of the CEC pin */
#define CEC_PIN_FUNCTION 1
#define CEC_DIVIDER_BASE 0x78

extern void gpio_set_pin_function(unsigned char, unsigned char, unsigned int);
extern unsigned char hdmi_cec_peer_address;
extern unsigned char hdmi_cec_sender;
extern unsigned char hdmi_cec_operand;

/*
 * Start the CEC block and select its pin.
 *
 *   pin_index  0..3: which pin of group 3 gets the CEC function (pin mask 1, 2, 4 or 8); another value selects
 *              none. System_Initialize passes 0.
 *
 * Writes fixed values to three registers, switches the pin, writes 0xFF to CEC_STATUS, sets the stored
 * own address and sender to 0xF and the operand to 0xFF, and finally writes the divider register.
 */
void hdmi_cec_init(unsigned char pin_index)
{
    unsigned int shift;

    R(CEC_REG_1C) = 0x28;
    R(CEC_REG_00) = 1;
    R(CEC_REG_44) = 0x53;
    switch (pin_index) {
    case 0:
        gpio_set_pin_function(CEC_PIN_GROUP, 1, CEC_PIN_FUNCTION);
        break;
    case 1:
        gpio_set_pin_function(CEC_PIN_GROUP, 2, CEC_PIN_FUNCTION);
        break;
    case 2:
        gpio_set_pin_function(CEC_PIN_GROUP, 4, CEC_PIN_FUNCTION);
        break;
    case 3:
        gpio_set_pin_function(CEC_PIN_GROUP, 8, CEC_PIN_FUNCTION);
        break;
    }
    R(CEC_STATUS) = 0xff;
    hdmi_cec_peer_address = 0xf;
    hdmi_cec_sender = 0xf;
    hdmi_cec_operand = 0xff;
    shift = R(REG_1480) & 3;
    if (shift == 0)
        R(CEC_DIVIDER_REG) = CEC_DIVIDER_BASE;
    else
        R(CEC_DIVIDER_REG) = CEC_DIVIDER_BASE >> shift;
}
