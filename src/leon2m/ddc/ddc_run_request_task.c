/* ddc_run_request_task  (FUN_a008a174)
 *
 * Run the DDC/CI request handler.
 * Note: Last of the application main-loop steps.
 * Name basis: proven - calls ddc_handle_request
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008a174, flags -mcpu=v8 -O2 -g.
 */
extern int ddc_handle_request();

/* Main-loop step: call ddc_handle_request, which takes one DDC/CI request from the 8051 and answers it. */
void ddc_run_request_task(void)
{
    ddc_handle_request();
}
