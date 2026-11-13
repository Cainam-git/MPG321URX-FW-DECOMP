/* osd_request_unzip  (FUN_a006cfac)
 *
 * Queue an OSD unpack request and report it busy to the main processor.
 *   packed_words: word count
 *   src: source
 *   arg: offset
 *   dst: target
 *   mode: 1 = packed words read low byte first, result written directly to OSD memory; else high byte first
 *       and written through the register port
 * Name basis: proven - stores the four words and mode used by osd_run_pending_unzip, sets the busy flag,
 *   publishes status bit 0
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g. The request words, the mode byte and the busy flag are three separate symbols (each
 * byte store has its own sethi; the words go through one base). Source form: the request as a struct, and the
 * store order words[0], mode, words[1..3], flag. The last call is a tail call.
 */
/* The four words osd_unzip_data takes, in its parameter order. */
struct UnzipRequest { unsigned int packed_words, src, arg, dst; };
extern struct UnzipRequest osd_unzip_request;
extern unsigned char osd_unzip_mode;
extern unsigned char osd_unzip_busy_flag;
extern void ipc_publish_status_flags(void);

/*
 * Mailbox command 0xFA: queue an OSD unpack job. Only stores the request and sets the busy flag; the work is
 * done later by osd_run_pending_unzip. The new flag state is then published to the main processor.
 *
 *   packed_words, src, arg, dst  the arguments of osd_unzip_data
 *   mode                         kept in osd_unzip_mode; osd_read_memory_blocks reads it for the byte order
 */
void osd_request_unzip(unsigned int packed_words, unsigned int src, unsigned int arg, unsigned int dst,
                       unsigned char mode)
{
    osd_unzip_request.packed_words = packed_words;
    osd_unzip_mode = mode;
    osd_unzip_request.src = src;
    osd_unzip_request.arg = arg;
    osd_unzip_request.dst = dst;
    osd_unzip_busy_flag = 1;
    ipc_publish_status_flags();
}
