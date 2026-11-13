/* dp_tx_aux_transfer  (FUN_a00862e4)
 *
 * Run an AUX transaction with up to 10 attempts.
 * Returns: 1 on success
 * Name basis: derived - dp_tx_aux_send_request then dp_tx_aux_read_reply until ACK
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00862e4 @ 0xa00862e4 (-mcpu=v8 -Os -g)
 * Source form: the result is 'attempts != 10' (emitted as addx %g0, 0, %i0). The length is passed
 * sign-extended (char parameter).
 */
extern void dp_tx_aux_send_request();
extern unsigned char dp_tx_aux_read_reply();

/*
 * Do an AUX transfer: send the request and read the reply, up to 10 times, until dp_tx_aux_read_reply
 * returns 0. Returns 1 when an attempt succeeded, 0 when all 10 failed.
 *   port:    link output
 *   mode:    AUX command
 *   address: address in the sink
 *   count:   length - 1, passed on as a signed byte
 *   buf:     data to send / place for the reply data
 */
int dp_tx_aux_transfer(unsigned int port, unsigned int mode, unsigned int address, char count, unsigned int buf)
{
    unsigned char attempts = 0;
    unsigned int output;
    do {
        output = port & 0xff;
        dp_tx_aux_send_request(output, mode & 0xff, address, (int)count, buf);
        if (dp_tx_aux_read_reply(output, mode & 0xff, (int)count, buf) == 0)
            break;
        attempts = attempts + 1;
    } while (attempts < 10);
    return (attempts != 10) ? 1 : 0;
}
