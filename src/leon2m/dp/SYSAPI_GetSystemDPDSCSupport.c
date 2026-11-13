/* SYSAPI_GetSystemDPDSCSupport  (FUN_a014a6e0)
 *
 * Return whether DSC is enabled for the DisplayPort input of a source.
 * Returns: 0 or 1
 * Name basis: proven - prints '-->SYSAPI_GetSystemDPDSCSupport %x,%x' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a014a6e0 @ 0xa014a6e0, flags -mcpu=v8 -O3 (no -g: the firmware has no nop after the final call).
 * The three lookup results are each used as an unsigned char.
 */
extern int input_port_table_find_code(unsigned char);
extern int input_entry_index_to_port_code(unsigned char);
extern int input_find_port_entry_by_bus_id(unsigned char);
extern unsigned char dp_get_port_dsc_support(unsigned char dp_port);
extern int dbg_printf();

#define PORT_CODE_DP0 0x71      /* port code mapped to DisplayPort number 0 */
#define PORT_CODE_DP1 0x81      /* port code mapped to DisplayPort number 1 */
#define NO_DP_PORT    0xff

/*
 * Return the DSC flag of the DisplayPort input behind a source, and log it.
 *
 *   source  source (input) number
 *
 * The source is turned into a port code. Port code 0x71 is DisplayPort number 0 and 0x81 is number 1; any other
 * code gives 0. The result is printed with the source.
 */
unsigned char SYSAPI_GetSystemDPDSCSupport(unsigned char source)
{
    unsigned char port_code, dp_port, result = 0;

    port_code = input_entry_index_to_port_code(input_find_port_entry_by_bus_id(input_port_table_find_code(source)));
    switch (port_code) {
    case PORT_CODE_DP0:
        dp_port = 0;
        break;
    case PORT_CODE_DP1:
        dp_port = 1;
        break;
    default:
        dp_port = NO_DP_PORT;
        break;
    }
    if (dp_port != NO_DP_PORT)
        result = dp_get_port_dsc_support(dp_port);
    dbg_printf("-->SYSAPI_GetSystemDPDSCSupport %x,%x\r\n", source, result);
    return result;
}
