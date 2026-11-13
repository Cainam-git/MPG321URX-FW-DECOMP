/* dp_tx_aux_request_copy  (FUN_a0086400)
 *
 * Run an AUX transaction (byte-sized arguments).
 * Returns: 1 on success
 * Note: Identical copy of dp_tx_aux_request.
 * Name basis: derived - forwards to dp_tx_aux_transfer with the output and command masked to bytes
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0086400 @ 0xa0086400 (-mcpu=v8 -Os -g)
 * Source form: the port is masked in the parameter itself; the length is passed sign-extended.
 */
extern int dp_tx_aux_transfer();

/*
 * Identical copy of dp_tx_aux_request: do an AUX transfer with the output and the command masked to one byte
 * each. Returns 1 on success.
 *   port:    link output
 *   mode:    AUX command
 *   address: address in the sink
 *   count:   length - 1
 *   buf:     data to send / place for the reply data
 */
unsigned char dp_tx_aux_request_copy(unsigned int port, unsigned int mode, unsigned int address, char count, unsigned int buf)
{
  port = port & 0xff;
  return dp_tx_aux_transfer(port,mode & 0xff,address,(int)count,buf);
}
