# Contributing

## Rules

1. **Matched means byte-exact at the real address.** Use `tools/diff.py` and `tools/exact.py` for the LEON
   processors, `tools/diff8051.py` for the 8051, and `tools/xtensa_check.py` for the Tensilica program. Drafts do not belong in
   `src/`.
2. **One file per function** in `src/<section>/`. Each file starts with a comment that explains:
   - What the function does, and who calls it.
   - The data layouts it relies on.
   - Any source form or documented compiler aid it needs for a byte-exact build.

   Comments describe the code only.
3. **Accept functions through the tools** (`tools/handaccept.py`, `tools/accept8051.py` or `tools/check/acc*.sh`).
   They check the file again and record its name, status, method, compiler flags and a one-line description in
   `symbols/<section>.json`.
4. **Keep Ghidra's names for external symbols** (`FUN_…`, `DAT_…`), because the checking tools link by those
   names. Descriptive names go into `symbols/<section>.json` and into the file's comment.
5. **Name the section and the function in commit messages**, for example
   `leon2m FUN_a00dac38: byte-exact (-O3 -g)`.
6. **Never commit** `toolchains/`, `parts/`, `ghidra_proj/`, `build/` or `work/`.
