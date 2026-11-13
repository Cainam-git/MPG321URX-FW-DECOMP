/* osd_run_pending_unzip  (FUN_a006cfe8)
 *
 * Run a queued OSD unpack request and report completion.
 * Name basis: proven - prints 'unzip osd GO!!' and 'unzip osd finish!!' around osd_unzip_data; called from the
 *   main loop
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g. The last dbg_printf call is a tail call.
 */
struct UnzipRequest { unsigned int packed_words, src, arg, dst; };
extern struct UnzipRequest osd_unzip_request;
extern unsigned char osd_unzip_mode;
extern unsigned char osd_unzip_busy_flag;
extern int dbg_printf(const char *, ...);
extern void osd_unzip_data(unsigned int, unsigned int, unsigned int, unsigned int);
extern void ipc_publish_status_flags(void);

/*
 * Run the OSD unpack job queued by osd_request_unzip, if there is one (busy flag is 1). The job is run with
 * osd_unzip_data, the flag is cleared and the new state published to the main processor. The debug port gets
 * "unzip osd GO!!" before and "unzip osd finish!!" after, each with the mode byte.
 */
void osd_run_pending_unzip(void)
{
    if (osd_unzip_busy_flag == 1) {
        dbg_printf("\r\nunzip osd GO!! %d\r\n", osd_unzip_mode);
        osd_unzip_data(osd_unzip_request.packed_words, osd_unzip_request.src, osd_unzip_request.arg,
                       osd_unzip_request.dst);
        osd_unzip_busy_flag = 0;
        ipc_publish_status_flags();
        dbg_printf("\r\nunzip osd finish!! %d\r\n", osd_unzip_mode);
    }
}
