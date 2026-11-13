# 8051 boot loader (bank 0): the source folders

The source of this program: 45 files, one per function (a few files hold a Keil module of several functions), each named after its function and sorted into a folder for its subject. The first line of every file gives the function's name and its label (its address in the firmware).

| Folder | Subject | Files |
|---|---|---:|
| [`startup/`](startup/) | [Start-up](../../docs/names/8051_bank0.md#startup) | 8 |
| [`timer/`](timer/) | [Timers and delays](../../docs/names/8051_bank0.md#timer) | 1 |
| [`flash/`](flash/) | [Flash memory](../../docs/names/8051_bank0.md#flash) | 12 |
| [`uart/`](uart/) | [Serial ports](../../docs/names/8051_bank0.md#uart) | 1 |
| [`lib/`](lib/) | [Library routines](../../docs/names/8051_bank0.md#lib) | 23 |

The [index page](../../docs/names/8051_bank0.md) lists every function of the program with a one-line description (52 entries, with the jump tables, library members and entry points that have no file of their own); the subject in the table above links to its part of that page. [Function names](../../docs/NAMES.md) describes how the names were given, and [How the firmware works: a guided tour](../../docs/TOUR.md) says what the programs do.
