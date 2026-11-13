/* dp_tx_set_sink_power  (FUN_a00865b8)
 *
 * Switch the sink to normal (D0) or power-save (D3) state, with retries.
 *   port: output
 *   on: 1 = on
 * Returns: 1 on success
 * Name basis: proven - writes 1 or 2 to DPCD 0x600 SET_POWER, up to 5 tries
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00865b8 @ 0xa00865b8 (-mcpu=v8 -Os -g)
 * Source form: the try counter is an unsigned char.
 */
extern int dp_tx_aux_write_byte(int, int, int, int);

/*
 * Set the power state of the sink: write 1 (on) or 2 (any other value of on) to DPCD 0x600 (SET_POWER) with a
 * single-byte write. Tries up to 5 times; returns 1 as soon as one write succeeds, 0 when all 5 fail.
 *   port: link output
 *   on:   1 = power on
 */
int dp_tx_set_sink_power(int port, int on)
{
    unsigned char tries = 0;
    unsigned char state;
    
    if ((unsigned char)on == 1)
        state = 1;
    else
        state = 2;
    
    do {
        int result = dp_tx_aux_write_byte((unsigned char)port, 0x80, 0x600, state);
        tries++;
        if ((result & 0xff) == 0)
            return 1;
    } while (tries <= 4);
    
    return 0;
}
