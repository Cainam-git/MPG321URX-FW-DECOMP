/* input_init_receivers  (FUN_a006d31c)
 *
 * Initialise the HDMI and DP receivers and their PHYs at start-up.
 * Name basis: proven - called by main init; calls DRV_HDMIRx_Phy_Init and DRV_HDMI21_RX_Init
 *
 * Matching notes
 * --------------
 * leon2s FUN_a006d31c @ 0xa006d31c-0xa006d39c (32 words), flags -mcpu=v8 -Os -g.
 * Source form: the two arguments of dp_init_port are kept in two locals set before the first call
 * (the second is 1 for both calls); the last call is a tail call with the restore in its delay slot.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
extern void sys_otp_load_shared_data(void);
extern void sys_otp_load_local_data(void);
extern void input_init_phy_registers_wrapper(void);
extern void InitHDCP(void);
extern void DRV_HDMIRx_Phy_Init(void);
extern void hdmi_init_receivers(void);
extern void DRV_HDMI21_RX_Init(void);
extern void dp_init_port_settings(uint param_1);
extern void dp_init_port(uint param_1, uint param_2);
extern void sys_dsc_dec_init(void);
extern void dp_tx_init_ports(void);
extern void hdmi_tx_init(void);

/*
 * Start-up initialisation of all receivers of the input program, run once from the start-up sequence
 * (sys_main_part2) after ipc_init_mailbox. Order: load the factory data records (into shared memory, then into
 * the local tables), set up the PHY registers (input_init_phy_registers), the unnamed routine FUN_9f1b1c18, the HDMI
 * receiver PHY (DRV_HDMIRx_Phy_Init), the HDMI receivers, the HDMI 2.1 receiver (DRV_HDMI21_RX_Init), the DP
 * port settings of port 0 and 1, the DP ports 0 and 1 themselves, the DSC decoder, the DP transmitter ports and
 * the HDMI transmitter. No parameters, no return value.
 */
void input_init_receivers(void)
{
    uint port;
    uint init_arg;
    sys_otp_load_shared_data();
    sys_otp_load_local_data();
    input_init_phy_registers_wrapper();
    InitHDCP();
    DRV_HDMIRx_Phy_Init();
    hdmi_init_receivers();
    DRV_HDMI21_RX_Init();
    dp_init_port_settings(0);
    dp_init_port_settings(1);
    port = 0;
    init_arg = 1;
    dp_init_port(port, init_arg);
    port = 1;
    dp_init_port(port, init_arg);
    sys_dsc_dec_init();
    dp_tx_init_ports();
    hdmi_tx_init();
}
