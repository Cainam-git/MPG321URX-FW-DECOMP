# Input processor (leon2s): the source folders

The source of this program: 1,659 files, one per function, each named after its function and sorted into a folder for its subject. The first line of every file gives the function's name and its label (its address in the firmware).

| Folder | Subject | Files |
|---|---|---:|
| [`startup/`](startup/) | [Start-up](../../docs/names/leon2s.md#startup) | 17 |
| [`trap/`](trap/) | [Traps and crash handling](../../docs/names/leon2s.md#trap) | 108 |
| [`irq/`](irq/) | [Interrupts](../../docs/names/leon2s.md#irq) | 165 |
| [`timer/`](timer/) | [Timers and delays](../../docs/names/leon2s.md#timer) | 5 |
| [`sys/`](sys/) | [System control: channels, modes, configuration](../../docs/names/leon2s.md#sys) | 54 |
| [`input/`](input/) | [Video inputs: detection, measurement, routing](../../docs/names/leon2s.md#input) | 31 |
| [`hdmi/`](hdmi/) | [HDMI](../../docs/names/leon2s.md#hdmi) | 536 |
| [`dp/`](dp/) | [DisplayPort](../../docs/names/leon2s.md#dp) | 393 |
| [`hdcp/`](hdcp/) | [Copy protection (HDCP)](../../docs/names/leon2s.md#hdcp) | 147 |
| [`hdr/`](hdr/) | [HDR](../../docs/names/leon2s.md#hdr) | 59 |
| [`osd/`](osd/) | [On-screen menu](../../docs/names/leon2s.md#osd) | 6 |
| [`audio/`](audio/) | [Sound](../../docs/names/leon2s.md#audio) | 60 |
| [`ipc/`](ipc/) | [Messages between the processors](../../docs/names/leon2s.md#ipc) | 18 |
| [`uart/`](uart/) | [Serial ports](../../docs/names/leon2s.md#uart) | 7 |
| [`reg/`](reg/) | [Register access](../../docs/names/leon2s.md#reg) | 23 |
| [`dbg/`](dbg/) | [Debug facilities](../../docs/names/leon2s.md#dbg) | 20 |
| [`lib/`](lib/) | [Library routines](../../docs/names/leon2s.md#lib) | 10 |

The [index page](../../docs/names/leon2s.md) lists every function of the program with a one-line description (1,702 entries, with the jump tables, library members and entry points that have no file of their own); the subject in the table above links to its part of that page. [Function names](../../docs/NAMES.md) describes how the names were given, and [How the firmware works: a guided tour](../../docs/TOUR.md) says what the programs do.
