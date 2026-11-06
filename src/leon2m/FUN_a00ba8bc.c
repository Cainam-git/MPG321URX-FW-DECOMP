/* leon2m FUN_a00ba8bc @ 0xa00ba8bc-0xa00ba950 (37 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0087020.
 * Code facts: clears the 0x32 bytes of the port 1 receive record DAT_a802d0d0 (u8 loop counter, clrb [base + i]),
 * clears its index byte DAT_a802b09c, clears the 0x19 bytes of the port 1 send buffer DAT_a802d078, then calls
 * FUN_a0148794(1, 0x10, 4, 0x1c200) and FUN_a0148794(1, 4, 2, 0x1c200). void, no return value. The last call is not
 * a tail call (call; mov 2,%o2; nop; ret; restore); the frame is the minimum (save -104).
 * Source form: a per-port init helper uart_init(port) inlined for port 1. It finds the receive record and its
 * index byte with port_rx(port, &rx, &idx) (out-parameters, the port 2 / 3 / other chain of FUN_a00ba950) and the
 * send buffer with port_tx(port) (the chain of FUN_a00bab80); the records are structs holding the byte arrays, the
 * clear loops run to sizeof. The addresses of the out-parameter locals rx and idx keep the last call a normal call.
 */
struct RxRec { unsigned char b[0x32]; };
struct TxRec { unsigned char b[0x19]; };
extern struct RxRec DAT_a802d040, DAT_a802d098, DAT_a802d0d0;
extern struct TxRec DAT_a802d128, DAT_a802d108, DAT_a802d078;
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern void FUN_a0148794(unsigned char, unsigned char, unsigned char, unsigned int);

static void port_rx(unsigned char port, struct RxRec **rx, unsigned char **idx)
{
    if (port == 2) {
        *rx = &DAT_a802d040;
        *idx = &DAT_a802b09a;
    } else if (port == 3) {
        *rx = &DAT_a802d098;
        *idx = &DAT_a802b098;
    } else {
        *rx = &DAT_a802d0d0;
        *idx = &DAT_a802b09c;
    }
}

static struct TxRec *port_tx(unsigned char port)
{
    if (port == 2)
        return &DAT_a802d128;
    else if (port == 3)
        return &DAT_a802d108;
    else
        return &DAT_a802d078;
}

static void uart_init(unsigned char port)
{
    struct RxRec *rx;
    struct TxRec *tx;
    unsigned char *idx;
    unsigned char i;

    port_rx(port, &rx, &idx);
    for (i = 0; i < sizeof(rx->b); i++)
        rx->b[i] = 0;
    *idx = 0;
    tx = port_tx(port);
    for (i = 0; i < sizeof(tx->b); i++)
        tx->b[i] = 0;
    FUN_a0148794(port, 0x10, 4, 115200);
    FUN_a0148794(port, 4, 2, 115200);
}

void FUN_a00ba8bc(void)
{
    uart_init(1);
}
