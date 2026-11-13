/* i2c_sw_match_device_id  (FUN_CODE_7f36)
 *
 * Read an ID from a device on the software I2C bus and compare it with the stored one.
 * Returns: 1 when the ID matches
 * Note: No caller in the bank-1 image.
 * Name basis: derived - pins from the standby table words 0xA5FF..0xA608, device/register 0xA609/0xA60A, six
 *   expected bytes 0xA60B; i2c_sw_read_regs
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_7f36 @ 0x7f36..0x8072 (316 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals: answer 0xA6C4..0xA6C9, id_length 0xA6CA, copy 0xA6CB..0xA6DA (initialised to zero from CODE).
 * volatile on the ID record: no 8051 code or init record writes 0xA609..0xA610; the firmware reads the entry again
 *   for the 0xFF test.
 * Source form: the compare is written 'expected_id[i] != answer[i]' (record first); the unused copy stays.
 */
extern unsigned int xdata power_key_table_i2c_0x12, power_key_table_i2c_0x14, power_key_table_i2c_0x17, power_key_table_i2c_0x19;
extern unsigned char xdata power_key_table_i2c_0x16, power_key_table_i2c_0x1b;
/* The device and the expected ID; filled from outside the 8051 program. */
struct i2c_sw_id_record {
    unsigned char device;          /* 0xA609: bus address (write form; | 1 to read) */
    unsigned char reg;             /* 0xA60A: first register of the ID */
    unsigned char expected_id[6];  /* 0xA60B..0xA610: ends early at the first 0x00 or 0xFF byte */
};
extern volatile struct i2c_sw_id_record xdata power_key_table_i2c_id_record;

void i2c_sw_select_pins(unsigned char *scl_ctrl, unsigned char *sda_ctrl, unsigned char *scl_port, unsigned char *sda_port, unsigned char scl_mask, unsigned char sda_mask);
void sys_set_match_flag(char c);
void i2c_sw_read_regs(unsigned char dev, unsigned int reg, unsigned int n, unsigned char *buf);

#define ID_BYTES_MAX       6
#define ID_END_ZERO        0x00
#define ID_END_FF          0xff
#define ONE_BYTE_REGISTER  0     /* sys_set_match_flag(0): i2c_sw_read_regs sends one register byte */
#define COPY_FIRST_BYTE    3

/*
 * i2c_sw_match_device_id - read the ID of a device on the software I2C bus and compare it with the expected ID.
 * Returns 1 when every byte matches, 0 when a byte differs or when no pins are given (the SCL or the SDA port
 * word is 0).
 * The pins come from the words at 0xA5FF..0xA608: SCL control 0xA606, port 0xA604, mask 0xA608; SDA control
 * 0xA601, port 0xA5FF, mask 0xA603. The ID is read with a one-byte register number.
 * At the end the answer is copied behind a 3 into a local table that nothing reads.
 * Nothing in the bank 1 program calls this routine.
 */
unsigned char i2c_sw_match_device_id(void)
{
    unsigned char answer[6];
    unsigned char id_length;
    unsigned char copy[16] = {0};
    unsigned char i;

    if (power_key_table_i2c_0x17 == 0 || power_key_table_i2c_0x12 == 0) return 0;
    i2c_sw_select_pins((unsigned char *)power_key_table_i2c_0x19, (unsigned char *)power_key_table_i2c_0x14, (unsigned char *)power_key_table_i2c_0x17,
                  (unsigned char *)power_key_table_i2c_0x12, power_key_table_i2c_0x1b, power_key_table_i2c_0x16);
    sys_set_match_flag(ONE_BYTE_REGISTER);
    /* The expected ID ends at its first 0x00 or 0xFF byte, or after six bytes. */
    for (i = 0; i < ID_BYTES_MAX; i++) {
        if (power_key_table_i2c_id_record.expected_id[i] == ID_END_ZERO) break;
        if (power_key_table_i2c_id_record.expected_id[i] == ID_END_FF) break;
    }
    id_length = i;
    i2c_sw_read_regs(power_key_table_i2c_id_record.device, power_key_table_i2c_id_record.reg, id_length, answer);
    for (i = 0; i < id_length; i++) {
        if (power_key_table_i2c_id_record.expected_id[i] != answer[i]) return 0;
    }
    copy[0] = COPY_FIRST_BYTE;
    for (i = 0; i < id_length; i++) copy[i + 1] = answer[i];
    return 1;
}
