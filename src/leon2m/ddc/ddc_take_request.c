/* ddc_take_request  (FUN_a0133ae4)
 *
 * Copy the received DDC/CI request out and mark the record free.
 * Name basis: derived - record at 0xA802D9C6; used by the DDC/CI request handler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133ae4 @ 0xa0133ae4-0xa0133b54 (28 words), flags -mcpu=v8 -O3 -g.
 * Source form: the request length is read from the record again on every step of the copy loop; the loop
 * counter is a halfword.
 */

/* A DDC/CI request received from the 8051 (filled by ipc_8051_decode_message). */
struct ddc_request {
    unsigned char port;             /* +0 */
    unsigned char pad;
    unsigned short length;          /* +2: number of request bytes */
    unsigned char data[0x80];       /* +4 */
    unsigned char ready;            /* +0x84: 1 = request complete; cleared here */
};
extern struct ddc_request ddc_rx_request;

/*
 * Copy the received DDC/CI request out of ddc_rx_request and mark the record free again.
 *
 *   port  (out) the port number stored in the record
 *   len   (out) number of request bytes
 *   dst   (out) the request bytes
 *
 * The caller is ddc_api_take_request. dst must hold up to 0x80 bytes.
 */
void ddc_take_request(unsigned char *port, unsigned short *len, unsigned char *dst)
{
    unsigned short i;

    *port = ddc_rx_request.port;
    *len = ddc_rx_request.length;
    for (i = 0; i < ddc_rx_request.length; i++)
        dst[i] = ddc_rx_request.data[i];
    ddc_rx_request.ready = 0;
}
