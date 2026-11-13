/* UartSetI2CEnable  (FUN_a00bf110)
 *
 * Answer command 580040: and open the I2C path MSI's PC tool uses (slave 0x6E)
 *   port: command port (2, 3 or 4)
 * Note: Reply value = Brightness. Then: 8051 closes serial port mask 0x10 (command 0x06), one pin of group 0
 *   becomes an input, internal EDID of input port 0 off, its DDC/CI slave 0x6E on.
 * Name basis: proven - prints '--->UartSetI2CEnable' (original name); docs/MAP.md update path step 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bf110 @ 0xa00bf110..0xa00bf2c8 (440 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the three digits are computed into their own unsigned char locals first and stored afterwards;
 * writing the digit expressions straight into the stores gives the same instructions with other registers.
 * The last call (ipc_8051_enable_ddc_slave) is a tail call.
 */
extern unsigned char user_settings_brightness, port_entry2_bus_id;  /* user settings byte +9; port entry 2 +0x10 */
extern unsigned char uart_cmd_tx_frame[11];
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern int dbg_printf();
extern void ipc_api_open_or_close_uart_ports(int, int, int, int);
extern unsigned char input_port_table_get_bus_id(unsigned char);
extern void gpio_setup_pin(int, unsigned char, int, int);
extern void ipc_8051_disable_internal_edid(int);
extern void ipc_8051_enable_ddc_slave(int, int);

#define GET_ROW_I2C_ENABLE  0x02    /* row of uart_cmd_get_rows: "580040:" */
#define GET_REPLY_LENGTH    11      /* "5b" + 5-character id + 3 value characters + CR */

#define SERIAL_PORTS_CLOSE  0       /* ipc_api_open_or_close_uart_ports: 0 = close (8051 command 0x06), else open */
#define SERIAL_PORT_BIT4    0x10    /* 8051 serial port mask, one bit per port (as uart_cmd_init_ports) */
#define GPIO_GROUP_0        0       /* gpio_setup_pin: pin-mux group 0 */
#define PIN_OUTPUT_OFF      0       /* gpio_setup_pin: output enable 0 */
#define PIN_LEVEL_LOW       0       /* gpio_setup_pin: level bit 0 */
#define INPUT_PORT_BIT0     0x01    /* 8051 input port mask, one bit per input port */
#define DDC_ADDRESS         0x6e    /* DDC/CI slave address for MSI's tool (docs/MAP.md, update path step 4) */

/*
 * Answer the get command "580040:" and open the path MSI's PC tool uses to reach the monitor over I2C: the
 * update command of the update path (docs/MAP.md, step 3).
 *   port: the command port the frame came in on. The only caller, uart_cmd_dispatch_get, passes the port of
 *         uart_cmd_run_tool_task, which is 4.
 *
 * In this order:
 *   1. The reply: bytes 7, 8 and 9 of uart_cmd_tx_frame get the hundreds, tens and ones digit of the Brightness
 *      setting (user settings byte +9); bytes 0 and 2..6 are copied from the table row ('5' and the id "0040:"),
 *      byte 1 is 'b', byte 10 is CR.
 *   2. The received frame is forgotten: the port's receive state byte and bytes 0, 1, 7, 10 and 0x19 of its receive
 *      record are set to 0 (the same stores as uart_cmd_clear_rx). Ports 2 and 3 have their own byte and record,
 *      every other port uses uart_cmd_rx_count and uart_cmd_rx_record.
 *   3. GET_REPLY_LENGTH bytes go out on `port`, then "--->UartSetI2CEnable" is printed.
 *   4. The 8051 closes serial port SERIAL_PORT_BIT4, one of the two serial ports uart_cmd_init_ports opens for the
 *      PC tool at start-up.
 *   5. gpio_setup_pin sets up one pin of group 0 with output enable and level 0. The pin number is the byte
 *      input_port_table_get_bus_id returns for the port table entry numbered by port_entry2_bus_id (pin 15 makes
 *      gpio_setup_pin return at once).
 *   6. The 8051 switches the internal EDID of input port 0 off (commands 0x02 and 0x0F), then sets the DDC/CI
 *      slave address DDC_ADDRESS on that port and switches the slave on (command 0x07).
 */
void UartSetI2CEnable(unsigned char port)
{
    {
        unsigned char value = user_settings_brightness, hundreds, rest, tens, ones;
        hundreds = value / 100;
        rest = value - hundreds * 100;
        tens = rest / 10;
        ones = rest - tens * 10;
        uart_cmd_tx_frame[7] = hundreds + '0';
        uart_cmd_tx_frame[8] = tens + '0';
        uart_cmd_tx_frame[9] = ones + '0';
    }
    uart_cmd_tx_frame[0] = sys_cmd_frame8_get_char(GET_ROW_I2C_ENABLE, 0);
    uart_cmd_tx_frame[1] = 'b';
    uart_cmd_tx_frame[2] = sys_cmd_frame8_get_char(GET_ROW_I2C_ENABLE, 2);
    uart_cmd_tx_frame[3] = sys_cmd_frame8_get_char(GET_ROW_I2C_ENABLE, 3);
    uart_cmd_tx_frame[4] = sys_cmd_frame8_get_char(GET_ROW_I2C_ENABLE, 4);
    uart_cmd_tx_frame[5] = sys_cmd_frame8_get_char(GET_ROW_I2C_ENABLE, 5);
    uart_cmd_tx_frame[6] = sys_cmd_frame8_get_char(GET_ROW_I2C_ENABLE, 6);
    uart_cmd_tx_frame[10] = '\r';
    if (port == 2) {
        uart_cmd_rx_state_port2 = 0;
        uart_cmd_rx_record_port2[0] = 0;
        uart_cmd_rx_record_port2[1] = 0;
        uart_cmd_rx_record_port2[7] = 0;
        uart_cmd_rx_record_port2[10] = 0;
        uart_cmd_rx_record_port2[0x19] = 0;
    } else if (port == 3) {
        uart_cmd_rx_state_port3 = 0;
        uart_cmd_rx_record_port3[0] = 0;
        uart_cmd_rx_record_port3[1] = 0;
        uart_cmd_rx_record_port3[7] = 0;
        uart_cmd_rx_record_port3[10] = 0;
        uart_cmd_rx_record_port3[0x19] = 0;
    } else {
        uart_cmd_rx_count = 0;
        uart_cmd_rx_record[0] = 0;
        uart_cmd_rx_record[1] = 0;
        uart_cmd_rx_record[7] = 0;
        uart_cmd_rx_record[10] = 0;
        uart_cmd_rx_record[0x19] = 0;
    }
    uart_api_send_bytes(port, GET_REPLY_LENGTH, uart_cmd_tx_frame);
    dbg_printf("--->UartSetI2CEnable\r\n");
    ipc_api_open_or_close_uart_ports(SERIAL_PORTS_CLOSE, SERIAL_PORT_BIT4, 0, 0);
    gpio_setup_pin(GPIO_GROUP_0, input_port_table_get_bus_id(port_entry2_bus_id), PIN_OUTPUT_OFF, PIN_LEVEL_LOW);
    ipc_8051_disable_internal_edid(INPUT_PORT_BIT0);
    ipc_8051_enable_ddc_slave(INPUT_PORT_BIT0, DDC_ADDRESS);
}
