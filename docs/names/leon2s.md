# Function names: Input processor (leon2s)

1,702 entries from `symbols/leon2s.names.json`, grouped by subject and listed by name; the label of each entry gives its address. [Function names](../NAMES.md) describes how the names were given and what the *basis* column means. A name with a link has a source file of its own, in the folder of its subject (`src/leon2s/<subject>/`); the other entries are jump tables, library members and entry points inside another function's file.

| Basis | Entries |
|---|---:|
| proven | 583 |
| derived | 519 |
| descriptive | 600 |

## Subjects

- [Start-up](#startup) (17)
- [Traps and crash handling](#trap) (108)
- [Interrupts](#irq) (165)
- [Timers and delays](#timer) (5)
- [System control: channels, modes, configuration](#sys) (55)
- [Video inputs: detection, measurement, routing](#input) (31)
- [HDMI](#hdmi) (549)
- [DisplayPort](#dp) (403)
- [Copy protection (HDCP)](#hdcp) (154)
- [HDR](#hdr) (60)
- [On-screen menu](#osd) (6)
- [Sound](#audio) (67)
- [Messages between the processors](#ipc) (22)
- [Serial ports](#uart) (7)
- [Register access](#reg) (23)
- [Debug facilities](#dbg) (20)
- [Library routines](#lib) (10)

<a id="startup"></a>
## Start-up

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`startup_clear_register_file_part1`](../../src/leon2s/startup/startup_clear_register_file_part1.S) | `FUN_a0060658` | Start the loop counter in %g1 and keep the return address in %g2. | descriptive |
| [`startup_clear_register_file_part2`](../../src/leon2s/startup/startup_clear_register_file_part2.S) | `FUN_a0060660` | Clear the global registers %g4..%g7. | descriptive |
| [`startup_clear_register_file_part3`](../../src/leon2s/startup/startup_clear_register_file_part3.S) | `FUN_a0060670` | Save WIM in %g7 and clear it so every window can be entered. | descriptive |
| [`startup_clear_register_file_part4`](../../src/leon2s/startup/startup_clear_register_file_part4.S) | `FUN_a0060680` | Clear %l0..%l2 of the current window (loop start). | descriptive |
| [`startup_clear_register_file_part5`](../../src/leon2s/startup/startup_clear_register_file_part5.S) | `FUN_a0060690` | Clear %l3..%l6 of the current window. | descriptive |
| [`startup_clear_register_file_part6`](../../src/leon2s/startup/startup_clear_register_file_part6.S) | `FUN_a00606a0` | Clear %l7 and %o0..%o2 of the current window. | descriptive |
| [`startup_clear_register_file_part7`](../../src/leon2s/startup/startup_clear_register_file_part7.S) | `FUN_a00606b0` | Clear %o3..%o5 and the stack pointer of the current window. | descriptive |
| [`startup_clear_register_file_part8`](../../src/leon2s/startup/startup_clear_register_file_part8.S) | `FUN_a00606c0` | Clear %o7, move to the next window and loop for eight windows. | descriptive |
| [`startup_clear_register_file_part9`](../../src/leon2s/startup/startup_clear_register_file_part9.S) | `FUN_a00606d0` | Count the window and, after the loop, restore the saved WIM. | descriptive |
| [`startup_clear_register_file_part10`](../../src/leon2s/startup/startup_clear_register_file_part10.S) | `FUN_a00606e0` | Return to the caller through the address kept in %g2. | descriptive |
| [`startup_init_system`](../../src/leon2s/startup/startup_init_system.c) | `FUN_a00b18d0` | Initialise the input processor's basic services and print the version banner. | proven |
| [`startup_reset_entry_part1`](../../src/leon2s/startup/startup_reset_entry_part1.S) | `FUN_a00602c0` | Flush the instruction cache, set PSR to 0xCF (supervisor, traps off), clear WIM and Y. | proven |
| [`startup_reset_entry_part2`](../../src/leon2s/startup/startup_reset_entry_part2.S) | `FUN_a00602d0` | Mark window 0 invalid and build the run-time PSR 0x10E0 (supervisor, FPU on, traps on). | proven |
| [`startup_reset_entry_part3`](../../src/leon2s/startup/startup_reset_entry_part3.S) | `FUN_a00602e0` | Load the run-time PSR and set the frame pointer near the top of data RAM. | proven |
| [`startup_reset_entry_part4`](../../src/leon2s/startup/startup_reset_entry_part4.S) | `FUN_a00602f0` | Set the stack pointer below the frame and point TBR at the trap table. | proven |
| [`startup_reset_entry_part5`](../../src/leon2s/startup/startup_reset_entry_part5.S) | `FUN_a0060300` | Call sys_main; the 'ta 1' loop behind the call is never reached. | proven |
| [`startup_reset_entry_part6`](../../src/leon2s/startup/startup_reset_entry_part6.S) | `FUN_a0060310` | Fill the delay slot of the reset entry's closing 'ta 1' loop. | proven |

<a id="trap"></a>
## Traps and crash handling

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`trap_breakpoint_step_over_part1`](../../src/leon2s/trap/trap_breakpoint_step_over_part1.S) | `FUN_a00604e0` | Copy the instruction at the breakpoint into a RAM slot. | proven |
| [`trap_breakpoint_step_over_part2`](../../src/leon2s/trap/trap_breakpoint_step_over_part2.S) | `FUN_a00604f0` | Run the copied instruction from RAM and continue at the trapped nPC (passed in %g1). | proven |
| [`trap_call_halt_handler_part1`](../../src/leon2s/trap/trap_call_halt_handler_part1.S) | `FUN_a0060314` | Copy the trap PC/nPC to %l5/%l6 and step back to the trapped window. | descriptive |
| [`trap_call_halt_handler_part2`](../../src/leon2s/trap/trap_call_halt_handler_part2.S) | `FUN_a0060320` | Open a new window and raise the interrupt level to 15. | descriptive |
| [`trap_call_halt_handler_part3`](../../src/leon2s/trap/trap_call_halt_handler_part3.S) | `FUN_a0060330` | Enable traps with all interrupts still masked. | descriptive |
| [`trap_call_halt_handler_part4`](../../src/leon2s/trap/trap_call_halt_handler_part4.S) | `FUN_a0060340` | Read PSR and start loading the halt-loop address. | descriptive |
| [`trap_call_halt_handler_part5`](../../src/leon2s/trap/trap_call_halt_handler_part5.S) | `FUN_a0060350` | Finish the handler address and save %g0/%g1 in locals. | descriptive |
| [`trap_call_halt_handler_part6`](../../src/leon2s/trap/trap_call_halt_handler_part6.S) | `FUN_a0060360` | Save %g2/%g3 in locals and call the handler (an endless halt loop). | descriptive |
| [`trap_call_halt_handler_part7`](../../src/leon2s/trap/trap_call_halt_handler_part7.S) | `FUN_a0060370` | Return to the trap window and restore %g0/%g1. | descriptive |
| [`trap_call_halt_handler_part8`](../../src/leon2s/trap/trap_call_halt_handler_part8.S) | `FUN_a0060380` | Restore %g2/%g3 and disable traps again. | descriptive |
| [`trap_call_halt_handler_part9`](../../src/leon2s/trap/trap_call_halt_handler_part9.S) | `FUN_a0060390` | Clear the interrupt level in PSR, traps still off. | descriptive |
| [`trap_call_halt_handler_part10`](../../src/leon2s/trap/trap_call_halt_handler_part10.S) | `FUN_a00603a0` | Return from the trap to the saved PC/nPC. | descriptive |
| [`trap_data_access_exception_entry`](../../src/leon2s/trap/trap_data_access_exception_entry.S) | `FUN_a0060090` | Trap table slot 0x09 (data access exception): reads %psr and %tbr and jumps to the handler at 0xa0060720. | proven |
| [`trap_division_by_zero_entry`](../../src/leon2s/trap/trap_division_by_zero_entry.S) | `FUN_a00602a0` | Trap table slot 0x2a (division by zero): reads %psr and %tbr and jumps to the handler at 0xa0060720. | proven |
| [`trap_dump_crash_and_halt`](../../src/leon2s/trap/trap_dump_crash_and_halt.c) | `CED_ALL` | Print the crash report (PC, trap name, registers, stack, code) and halt. | proven |
| [`trap_flush_windows_part1`](../../src/leon2s/trap/trap_flush_windows_part1.S) | `FUN_a00605e8` | Read PSR and build a copy with the interrupt level raised to 15. | descriptive |
| [`trap_flush_windows_part2`](../../src/leon2s/trap/trap_flush_windows_part2.S) | `FUN_a00605f0` | Step to the trapped window and enable traps with interrupts masked. | descriptive |
| [`trap_flush_windows_part3`](../../src/leon2s/trap/trap_flush_windows_part3.S) | `FUN_a0060600` | Start walking forward through the register windows (SAVE x3). | descriptive |
| [`trap_flush_windows_part4`](../../src/leon2s/trap/trap_flush_windows_part4.S) | `FUN_a0060610` | Finish the forward walk, forcing overflow spills, and start walking back. | descriptive |
| [`trap_flush_windows_part5`](../../src/leon2s/trap/trap_flush_windows_part5.S) | `FUN_a0060620` | Walk back to the starting window (RESTORE x4). | descriptive |
| [`trap_flush_windows_part6`](../../src/leon2s/trap/trap_flush_windows_part6.S) | `FUN_a0060630` | Restore the original PSR. | descriptive |
| [`trap_flush_windows_part7`](../../src/leon2s/trap/trap_flush_windows_part7.S) | `FUN_a0060640` | Return from the trap past the trapping instruction. | descriptive |
| [`trap_force_error_mode_part1`](../../src/leon2s/trap/trap_force_error_mode_part1.S) | `FUN_a0060648` | Load from the misaligned address 1 while traps are disabled. | descriptive |
| [`trap_force_error_mode_part2`](../../src/leon2s/trap/trap_force_error_mode_part2.S) | `FUN_a0060650` | Return from the trap past the trapping instruction (reached only if the load does not trap). | descriptive |
| [`trap_fp_disabled_unhandled`](../../src/leon2s/trap/trap_fp_disabled_unhandled.S) | `FUN_a0060040` | Trap table slot 0x04 (fp disabled): not handled, raises a software trap. | proven |
| [`trap_fp_exception_entry`](../../src/leon2s/trap/trap_fp_exception_entry.S) | `FUN_a0060080` | Trap table slot 0x08 (fp exception): reads %psr and %tbr and jumps to the handler at 0xa00604d0. | proven |
| [`trap_fp_exception_skip`](../../src/leon2s/trap/trap_fp_exception_skip.S) | `FUN_a00604d0` | Skip the instruction that raised an FPU exception and resume. | proven |
| [`trap_halt_forever`](../../src/leon2s/trap/trap_halt_forever.c) | `FUN_a0061224` | Stop the processor in an endless loop. | derived |
| [`trap_illegal_instruction_entry`](../../src/leon2s/trap/trap_illegal_instruction_entry.S) | `FUN_a0060020` | Trap table slot 0x02 (illegal instruction): reads %psr and %tbr and jumps to the handler at 0xa0060720. | proven |
| [`trap_instruction_access_exception_unhandled`](../../src/leon2s/trap/trap_instruction_access_exception_unhandled.S) | `FUN_a0060010` | Trap table slot 0x01 (instruction access exception): not handled, raises a software trap. | proven |
| [`trap_interrupt_level_1_entry`](../../src/leon2s/trap/trap_interrupt_level_1_entry.S) | `FUN_a0060110` | Trap table slot 0x11 (interrupt level 1): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_2_entry`](../../src/leon2s/trap/trap_interrupt_level_2_entry.S) | `FUN_a0060120` | Trap table slot 0x12 (interrupt level 2): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_3_entry`](../../src/leon2s/trap/trap_interrupt_level_3_entry.S) | `FUN_a0060130` | Trap table slot 0x13 (interrupt level 3): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_4_entry`](../../src/leon2s/trap/trap_interrupt_level_4_entry.S) | `FUN_a0060140` | Trap table slot 0x14 (interrupt level 4): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_5_entry`](../../src/leon2s/trap/trap_interrupt_level_5_entry.S) | `FUN_a0060150` | Trap table slot 0x15 (interrupt level 5): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_6_entry`](../../src/leon2s/trap/trap_interrupt_level_6_entry.S) | `FUN_a0060160` | Trap table slot 0x16 (interrupt level 6): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_7_entry`](../../src/leon2s/trap/trap_interrupt_level_7_entry.S) | `FUN_a0060170` | Trap table slot 0x17 (interrupt level 7): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_8_entry`](../../src/leon2s/trap/trap_interrupt_level_8_entry.S) | `FUN_a0060180` | Trap table slot 0x18 (interrupt level 8): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_9_entry`](../../src/leon2s/trap/trap_interrupt_level_9_entry.S) | `FUN_a0060190` | Trap table slot 0x19 (interrupt level 9): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_10_entry`](../../src/leon2s/trap/trap_interrupt_level_10_entry.S) | `FUN_a00601a0` | Trap table slot 0x1a (interrupt level 10): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_11_entry`](../../src/leon2s/trap/trap_interrupt_level_11_entry.S) | `FUN_a00601b0` | Trap table slot 0x1b (interrupt level 11): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_12_entry`](../../src/leon2s/trap/trap_interrupt_level_12_entry.S) | `FUN_a00601c0` | Trap table slot 0x1c (interrupt level 12): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_13_entry`](../../src/leon2s/trap/trap_interrupt_level_13_entry.S) | `FUN_a00601d0` | Trap table slot 0x1d (interrupt level 13): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_14_entry`](../../src/leon2s/trap/trap_interrupt_level_14_entry.S) | `FUN_a00601e0` | Trap table slot 0x1e (interrupt level 14): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_interrupt_level_15_entry`](../../src/leon2s/trap/trap_interrupt_level_15_entry.S) | `FUN_a00601f0` | Trap table slot 0x1f (interrupt level 15): reads %psr and %tbr and jumps to the handler at 0xa00603ac. | proven |
| [`trap_privileged_instruction_entry`](../../src/leon2s/trap/trap_privileged_instruction_entry.S) | `FUN_a0060030` | Trap table slot 0x03 (privileged instruction): reads %psr and %tbr and jumps to the handler at 0xa0060720. | proven |
| [`trap_raise_software_trap_2`](../../src/leon2s/trap/trap_raise_software_trap_2.S) | `FUN_a00606f0` | Return to the caller and raise software trap 2 in the delay slot. | descriptive |
| [`trap_reset_entry`](../../src/leon2s/trap/trap_reset_entry.S) | `FUN_a0060000` | Trap table slot 0x00 (reset): clears %l0 and jumps to the reset start-up at 0xa00602c0. | proven |
| [`trap_return_retry`](../../src/leon2s/trap/trap_return_retry.S) | `FUN_a00604c0` | Return from a trap and re-execute the trapped instruction. | descriptive |
| [`trap_return_skip`](../../src/leon2s/trap/trap_return_skip.S) | `FUN_a00604fc` | Return from a trap past the trapped instruction. | descriptive |
| [`trap_save_crash_state_part1`](../../src/leon2s/trap/trap_save_crash_state_part1.S) | `FUN_a0060720` | Capture WIM, the stack pointer and Y, and start addressing the crash save area. | proven |
| [`trap_save_crash_state_part2`](../../src/leon2s/trap/trap_save_crash_state_part2.S) | `FUN_a0060730` | Clear the %g0 slot and store %g1/%g2 in the crash area. | proven |
| [`trap_save_crash_state_part3`](../../src/leon2s/trap/trap_save_crash_state_part3.S) | `FUN_a0060740` | Store %g3..%g6 in the crash area. | proven |
| [`trap_save_crash_state_part4`](../../src/leon2s/trap/trap_save_crash_state_part4.S) | `FUN_a0060750` | Store %g7, keep the crash area address in %g3 and copy %fp to %l7. | proven |
| [`trap_save_crash_state_part5`](../../src/leon2s/trap/trap_save_crash_state_part5.S) | `FUN_a0060760` | Store the trap window's %l0..%l3 (PSR, PC, nPC, TBR). | proven |
| [`trap_save_crash_state_part6`](../../src/leon2s/trap/trap_save_crash_state_part6.S) | `FUN_a0060770` | Store %l4..%l7 (WIM, stack pointer, Y, frame pointer). | proven |
| [`trap_save_crash_state_part7`](../../src/leon2s/trap/trap_save_crash_state_part7.S) | `FUN_a0060780` | Store the trap window's %i0..%i3. | proven |
| [`trap_save_crash_state_part8`](../../src/leon2s/trap/trap_save_crash_state_part8.S) | `FUN_a0060790` | Store the trap window's %i4..%i7. | proven |
| [`trap_save_crash_state_part9`](../../src/leon2s/trap/trap_save_crash_state_part9.S) | `FUN_a00607a0` | Step to the trapped window and store its %i0..%i2. | proven |
| [`trap_save_crash_state_part10`](../../src/leon2s/trap/trap_save_crash_state_part10.S) | `FUN_a00607b0` | Store the trapped window's %i3..%i6. | proven |
| [`trap_save_crash_state_part11`](../../src/leon2s/trap/trap_save_crash_state_part11.S) | `FUN_a00607c0` | Store the trapped window's %i7 and %l0..%l2. | proven |
| [`trap_save_crash_state_part12`](../../src/leon2s/trap/trap_save_crash_state_part12.S) | `FUN_a00607d0` | Store the trapped window's %l3..%l6. | proven |
| [`trap_save_crash_state_part13`](../../src/leon2s/trap/trap_save_crash_state_part13.S) | `FUN_a00607e0` | Store %l7, return to the trap window and address the crash area again. | proven |
| [`trap_save_crash_state_part14`](../../src/leon2s/trap/trap_save_crash_state_part14.S) | `FUN_a00607f0` | Reload %g3 and load the crash hook pointer. | proven |
| [`trap_save_crash_state_part15`](../../src/leon2s/trap/trap_save_crash_state_part15.S) | `FUN_a0060800` | Save %g0..%g3 in locals before calling the crash hook. | proven |
| [`trap_save_crash_state_part16`](../../src/leon2s/trap/trap_save_crash_state_part16.S) | `FUN_a0060810` | Call the crash hook, which does not return. | proven |
| [`trap_save_crash_state_part17`](../../src/leon2s/trap/trap_save_crash_state_part17.S) | `FUN_a0060820` | Restore %g0..%g3 after the crash hook. | proven |
| [`trap_save_crash_state_part18`](../../src/leon2s/trap/trap_save_crash_state_part18.S) | `FUN_a0060830` | Rewrite PSR from the trap-time PSR with ET toggled and the interrupt level cleared. | proven |
| [`trap_save_crash_state_part19`](../../src/leon2s/trap/trap_save_crash_state_part19.S) | `FUN_a0060840` | Wait out the PSR write and start the return to the trapped instruction. | proven |
| [`trap_save_crash_state_part20`](../../src/leon2s/trap/trap_save_crash_state_part20.S) | `FUN_a0060850` | Finish the return from the trap (retry the trapped instruction). | proven |
| [`trap_set_irq_level_part1`](../../src/leon2s/trap/trap_set_irq_level_part1.S) | `FUN_a00606f8` | Read PSR and isolate the current interrupt level field. | descriptive |
| [`trap_set_irq_level_part2`](../../src/leon2s/trap/trap_set_irq_level_part2.S) | `FUN_a0060700` | Replace the PSR interrupt level with the value from %i0. | descriptive |
| [`trap_set_irq_level_part3`](../../src/leon2s/trap/trap_set_irq_level_part3.S) | `FUN_a0060710` | Write PSR, return the previous level in %i0 and resume past the trap. | descriptive |
| [`trap_tag_overflow_unhandled`](../../src/leon2s/trap/trap_tag_overflow_unhandled.S) | `FUN_a00600a0` | Trap table slot 0x0a (tag overflow): not handled, raises a software trap. | proven |
| [`trap_type_0b_entry`](../../src/leon2s/trap/trap_type_0b_entry.S) | `FUN_a00600b0` | Trap table slot 0x0b (type 0b): reads %psr and %tbr and jumps to the handler at 0xa00604e0. | proven |
| [`trap_type_0c_unhandled`](../../src/leon2s/trap/trap_type_0c_unhandled.S) | `FUN_a00600c0` | Trap table slot 0x0c (type 0c): not handled, raises a software trap. | proven |
| [`trap_type_0d_unhandled`](../../src/leon2s/trap/trap_type_0d_unhandled.S) | `FUN_a00600d0` | Trap table slot 0x0d (type 0d): not handled, raises a software trap. | proven |
| [`trap_type_0e_unhandled`](../../src/leon2s/trap/trap_type_0e_unhandled.S) | `FUN_a00600e0` | Trap table slot 0x0e (type 0e): not handled, raises a software trap. | proven |
| [`trap_type_0f_unhandled`](../../src/leon2s/trap/trap_type_0f_unhandled.S) | `FUN_a00600f0` | Trap table slot 0x0f (type 0f): not handled, raises a software trap. | proven |
| [`trap_type_2b_entry`](../../src/leon2s/trap/trap_type_2b_entry.S) | `FUN_a00602b0` | Trap table slot 0x2b (type 2b): reads %psr and %tbr and jumps to the handler at 0xa0060504. | proven |
| [`trap_type_10_unhandled`](../../src/leon2s/trap/trap_type_10_unhandled.S) | `FUN_a0060100` | Trap table slot 0x10 (type 10): not handled, raises a software trap. | proven |
| [`trap_type_20_unhandled`](../../src/leon2s/trap/trap_type_20_unhandled.S) | `FUN_a0060200` | Trap table slot 0x20 (type 20): not handled, raises a software trap. | proven |
| [`trap_type_21_unhandled`](../../src/leon2s/trap/trap_type_21_unhandled.S) | `FUN_a0060210` | Trap table slot 0x21 (type 21): not handled, raises a software trap. | proven |
| [`trap_type_22_unhandled`](../../src/leon2s/trap/trap_type_22_unhandled.S) | `FUN_a0060220` | Trap table slot 0x22 (type 22): not handled, raises a software trap. | proven |
| [`trap_type_23_unhandled`](../../src/leon2s/trap/trap_type_23_unhandled.S) | `FUN_a0060230` | Trap table slot 0x23 (type 23): not handled, raises a software trap. | proven |
| [`trap_type_24_unhandled`](../../src/leon2s/trap/trap_type_24_unhandled.S) | `FUN_a0060240` | Trap table slot 0x24 (type 24): not handled, raises a software trap. | proven |
| [`trap_type_25_unhandled`](../../src/leon2s/trap/trap_type_25_unhandled.S) | `FUN_a0060250` | Trap table slot 0x25 (type 25): not handled, raises a software trap. | proven |
| [`trap_type_26_unhandled`](../../src/leon2s/trap/trap_type_26_unhandled.S) | `FUN_a0060260` | Trap table slot 0x26 (type 26): not handled, raises a software trap. | proven |
| [`trap_type_27_unhandled`](../../src/leon2s/trap/trap_type_27_unhandled.S) | `FUN_a0060270` | Trap table slot 0x27 (type 27): not handled, raises a software trap. | proven |
| [`trap_type_28_unhandled`](../../src/leon2s/trap/trap_type_28_unhandled.S) | `FUN_a0060280` | Trap table slot 0x28 (type 28): not handled, raises a software trap. | proven |
| [`trap_type_29_unhandled`](../../src/leon2s/trap/trap_type_29_unhandled.S) | `FUN_a0060290` | Trap table slot 0x29 (type 29): not handled, raises a software trap. | proven |
| [`trap_unaligned_address_entry`](../../src/leon2s/trap/trap_unaligned_address_entry.S) | `FUN_a0060070` | Trap table slot 0x07 (unaligned address): reads %psr and %tbr and jumps to the handler at 0xa0060720. | proven |
| [`trap_window_overflow_entry`](../../src/leon2s/trap/trap_window_overflow_entry.S) | `FUN_a0060050` | Trap table slot 0x05 (window overflow): reads %psr and %tbr and jumps to the handler at 0xa0060538. | proven |
| [`trap_window_overflow_part1`](../../src/leon2s/trap/trap_window_overflow_part1.S) | `FUN_a0060530` | Begin the window-overflow handler: read the window mask and keep %g1. | proven |
| [`trap_window_overflow_part2`](../../src/leon2s/trap/trap_window_overflow_part2.S) | `FUN_a0060540` | Compute the new invalid-window mask (WIM rotated right by one) and enter the next window. | proven |
| [`trap_window_overflow_part3`](../../src/leon2s/trap/trap_window_overflow_part3.S) | `FUN_a0060550` | Write the new WIM and wait the three required cycles. | proven |
| [`trap_window_overflow_part4`](../../src/leon2s/trap/trap_window_overflow_part4.S) | `FUN_a0060560` | Spill the window's local registers to its stack frame. | proven |
| [`trap_window_overflow_part5`](../../src/leon2s/trap/trap_window_overflow_part5.S) | `FUN_a0060570` | Spill the window's in registers to its stack frame. | proven |
| [`trap_window_overflow_part6`](../../src/leon2s/trap/trap_window_overflow_part6.S) | `FUN_a0060580` | Return to the trap window, restore %g1 and retry the SAVE. | proven |
| [`trap_window_underflow_entry`](../../src/leon2s/trap/trap_window_underflow_entry.S) | `FUN_a0060060` | Trap table slot 0x06 (window underflow): reads %psr and %tbr and jumps to the handler at 0xa0060590. | proven |
| [`trap_window_underflow_part1`](../../src/leon2s/trap/trap_window_underflow_part1.S) | `FUN_a0060590` | Compute the new invalid-window mask (WIM rotated left by one). | proven |
| [`trap_window_underflow_part2`](../../src/leon2s/trap/trap_window_underflow_part2.S) | `FUN_a00605a0` | Write the new WIM and wait the three required cycles. | proven |
| [`trap_window_underflow_part3`](../../src/leon2s/trap/trap_window_underflow_part3.S) | `FUN_a00605b0` | Step back two windows and start reloading the local registers from the stack. | proven |
| [`trap_window_underflow_part4`](../../src/leon2s/trap/trap_window_underflow_part4.S) | `FUN_a00605c0` | Reload the remaining locals and the first in registers from the stack frame. | proven |
| [`trap_window_underflow_part5`](../../src/leon2s/trap/trap_window_underflow_part5.S) | `FUN_a00605d0` | Reload the last in registers and step forward to the trap window. | proven |
| [`trap_window_underflow_part6`](../../src/leon2s/trap/trap_window_underflow_part6.S) | `FUN_a00605e0` | Retry the RESTORE that trapped. | proven |
| [`trap_write_buffer_error_part1`](../../src/leon2s/trap/trap_write_buffer_error_part1.S) | `FUN_a0060500` | Load the write-buffer error budget counter. | proven |
| [`trap_write_buffer_error_part2`](../../src/leon2s/trap/trap_write_buffer_error_part2.S) | `FUN_a0060510` | Count the stored counter down; return to the interrupted code, or raise 'ta 0' when it drops below 0. | proven |

<a id="irq"></a>
## Interrupts

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`irq_disable_dp_port0`](../../src/leon2s/irq/irq_disable_dp_port0.c) | `FUN_a00b1b98` | Switch the interrupt sources of DisplayPort input 0 off. | derived |
| [`irq_disable_dp_port1`](../../src/leon2s/irq/irq_disable_dp_port1.c) | `FUN_a00b1c64` | Switch the interrupt sources of DisplayPort input 1 off. | derived |
| [`irq_disable_hdmi_port0`](../../src/leon2s/irq/irq_disable_hdmi_port0.c) | `FUN_a00b1a00` | Switch the interrupt sources of HDMI input 0 off. | derived |
| [`irq_disable_hdmi_port1`](../../src/leon2s/irq/irq_disable_hdmi_port1.c) | `FUN_a00b1acc` | Switch the interrupt sources of HDMI input 1 off. | derived |
| [`irq_empty_vector_handler`](../../src/leon2s/irq/irq_empty_vector_handler.c) | `FUN_a00608f0` | Return at once (its address stands in the word right after the interrupt vector table). | descriptive |
| [`irq_empty_vector_handler_copy3`](../../src/leon2s/irq/irq_empty_vector_handler_copy3.c) | `FUN_a0095c9c` | Return at once: an empty routine, identical in code to irq_empty_vector_handler. | descriptive |
| [`irq_empty_vector_handler_copy4`](../../src/leon2s/irq/irq_empty_vector_handler_copy4.c) | `FUN_a0096300` | Return at once: an empty routine, identical in code to irq_empty_vector_handler. | descriptive |
| [`irq_empty_vector_handler_copy5`](../../src/leon2s/irq/irq_empty_vector_handler_copy5.c) | `FUN_a00a0558` | Return at once: an empty routine, identical in code to irq_empty_vector_handler. | descriptive |
| [`irq_empty_vector_handler_copy6`](../../src/leon2s/irq/irq_empty_vector_handler_copy6.c) | `FUN_a00a0560` | Return at once: an empty routine, identical in code to irq_empty_vector_handler. | descriptive |
| [`irq_empty_vector_handler_copy7`](../../src/leon2s/irq/irq_empty_vector_handler_copy7.c) | `FUN_a00abb20` | Return at once: an empty routine, identical in code to irq_empty_vector_handler. | descriptive |
| [`irq_empty_vector_handler_copy8`](../../src/leon2s/irq/irq_empty_vector_handler_copy8.c) | `FUN_a00abb28` | Return at once: an empty routine, identical in code to irq_empty_vector_handler. | descriptive |
| [`irq_enable_dp_port0`](../../src/leon2s/irq/irq_enable_dp_port0.c) | `FUN_a00b1b18` | Switch the interrupt sources of DisplayPort input 0 on. | derived |
| [`irq_enable_dp_port1`](../../src/leon2s/irq/irq_enable_dp_port1.c) | `FUN_a00b1be4` | Switch the interrupt sources of DisplayPort input 1 on. | derived |
| [`irq_enable_hdmi_port0`](../../src/leon2s/irq/irq_enable_hdmi_port0.c) | `FUN_a00b1980` | Switch the interrupt sources of HDMI input 0 on. | derived |
| [`irq_enable_hdmi_port1`](../../src/leon2s/irq/irq_enable_hdmi_port1.c) | `FUN_a00b1a4c` | Switch the interrupt sources of HDMI input 1 on. | derived |
| [`irq_entry_nosave_part1`](../../src/leon2s/irq/irq_entry_nosave_part1.S) | `FUN_a006048c` | Set the stack pointer from the trap window's frame pointer. | descriptive |
| [`irq_entry_nosave_part2`](../../src/leon2s/irq/irq_entry_nosave_part2.S) | `FUN_a0060490` | Address the vector the handler table and extract the trap type from TBR. | descriptive |
| [`irq_entry_nosave_part3`](../../src/leon2s/irq/irq_entry_nosave_part3.S) | `FUN_a00604a0` | Index the vector table by trap type - 0x11 and call the level's service routine. | descriptive |
| [`irq_entry_nosave_part4`](../../src/leon2s/irq/irq_entry_nosave_part4.S) | `FUN_a00604b0` | Return from the interrupt trap to the saved PC/nPC. | descriptive |
| [`irq_entry_part1`](../../src/leon2s/irq/irq_entry_part1.S) | `FUN_a00603ac` | Copy the trap PC to %l5 on interrupt entry (trap types 0x11..0x1F). | proven |
| [`irq_entry_part2`](../../src/leon2s/irq/irq_entry_part2.S) | `FUN_a00603b0` | Copy the trap nPC and raise the interrupt level to 15. | proven |
| [`irq_entry_part3`](../../src/leon2s/irq/irq_entry_part3.S) | `FUN_a00603c0` | Enable traps with all interrupts still masked. | proven |
| [`irq_entry_part4`](../../src/leon2s/irq/irq_entry_part4.S) | `FUN_a00603d0` | Store TBR, PC and nPC in the interrupt save area. | proven |
| [`irq_entry_part5`](../../src/leon2s/irq/irq_entry_part5.S) | `FUN_a00603e0` | Store nPC and step back to the interrupted window. | proven |
| [`irq_entry_part6`](../../src/leon2s/irq/irq_entry_part6.S) | `FUN_a00603e8` | Reopen the trap window and start addressing the save area. | proven |
| [`irq_entry_part7`](../../src/leon2s/irq/irq_entry_part7.S) | `FUN_a00603f0` | Reload TBR, PC and nPC from the save area into the trap window. | proven |
| [`irq_entry_part8`](../../src/leon2s/irq/irq_entry_part8.S) | `FUN_a0060400` | Read PSR and extract the trap type from TBR. | proven |
| [`irq_entry_part9`](../../src/leon2s/irq/irq_entry_part9.S) | `FUN_a0060410` | Turn the trap type into an index (type - 0x11) into the vector the handler table. | proven |
| [`irq_entry_part10`](../../src/leon2s/irq/irq_entry_part10.S) | `FUN_a0060420` | Load the level's service routine and save %g2..%g5. | proven |
| [`irq_entry_part11`](../../src/leon2s/irq/irq_entry_part11.S) | `FUN_a0060430` | Save %g6, %g7, %g1 and the Y register. | proven |
| [`irq_entry_part12`](../../src/leon2s/irq/irq_entry_part12.S) | `FUN_a0060440` | Call the level's service routine and return to the trap window. | proven |
| [`irq_entry_part13`](../../src/leon2s/irq/irq_entry_part13.S) | `FUN_a0060450` | Restore %g2..%g7 and %g1 after the service routine. | proven |
| [`irq_entry_part14`](../../src/leon2s/irq/irq_entry_part14.S) | `FUN_a0060460` | Restore Y and disable traps before the return. | proven |
| [`irq_entry_part15`](../../src/leon2s/irq/irq_entry_part15.S) | `FUN_a0060470` | Clear the interrupt level in PSR, traps still off. | proven |
| [`irq_entry_part16`](../../src/leon2s/irq/irq_entry_part16.S) | `FUN_a0060480` | Return from the trap to the saved PC/nPC. | proven |
| [`irq_init_controller`](../../src/leon2s/irq/irq_init_controller.c) | `FUN_a00b17e8` | Mask and clear all interrupt levels, set up register 0x9F120038, then enable interrupt level 1. | derived |
| [`irq_raise_software_irq_bit0`](../../src/leon2s/irq/irq_raise_software_irq_bit0.c) | `FUN_a00b192c` | Write 1 to software interrupt register 0x9F020024 (bit 0). | descriptive |
| [`irq_raise_software_irq_bit1`](../../src/leon2s/irq/irq_raise_software_irq_bit1.c) | `FUN_a00b1948` | Raise software interrupt bit 1 for the main processor. | descriptive |
| [`irq_raise_software_irq_bit3`](../../src/leon2s/irq/irq_raise_software_irq_bit3.c) | `FUN_a00b1964` | Raise software interrupt bit 3 for the main processor. | descriptive |
| [`irq_service_level1_part1`](../../src/leon2s/irq/irq_service_level1_part1.S) | `FUN_a00608f8` | Enter the level-1 interrupt service routine. | proven |
| [`irq_service_level1_part2`](../../src/leon2s/irq/irq_service_level1_part2.S) | `FUN_a0060900` | Mask interrupt 1 (bit 0x2) in the LEON2 interrupt mask. | proven |
| [`irq_service_level1_part3`](../../src/leon2s/irq/irq_service_level1_part3.S) | `FUN_a0060910` | Set bit 0x2 in the second-level register 0x9F120028. | proven |
| [`irq_service_level1_part4`](../../src/leon2s/irq/irq_service_level1_part4.S) | `FUN_a0060920` | Read the interrupt-1 source status and address its source mask. | proven |
| [`irq_service_level1_part5`](../../src/leon2s/irq/irq_service_level1_part5.S) | `FUN_a0060930` | Drop masked sources and take the acknowledge-after-call flags from the mask's upper half. | proven |
| [`irq_service_level1_part6`](../../src/leon2s/irq/irq_service_level1_part6.S) | `FUN_a0060940` | Start the source loop and test the next pending source bit. | proven |
| [`irq_service_level1_part7`](../../src/leon2s/irq/irq_service_level1_part7.S) | `FUN_a0060950` | Skip idle sources and look up the source handler in the handler table. | proven |
| [`irq_service_level1_part8`](../../src/leon2s/irq/irq_service_level1_part8.S) | `FUN_a0060960` | Skip sources without a registered handler. | proven |
| [`irq_service_level1_part9`](../../src/leon2s/irq/irq_service_level1_part9.S) | `FUN_a0060970` | Choose the acknowledge order for the source and call its handler. | proven |
| [`irq_service_level1_part10`](../../src/leon2s/irq/irq_service_level1_part10.S) | `FUN_a0060980` | Acknowledge the source in the status register after its handler returned. | proven |
| [`irq_service_level1_part11`](../../src/leon2s/irq/irq_service_level1_part11.S) | `FUN_a0060990` | Acknowledge the source in the status register before calling its handler. | proven |
| [`irq_service_level1_part12`](../../src/leon2s/irq/irq_service_level1_part12.S) | `FUN_a00609a0` | Call the handler, advance to the next source and test the loop bound. | proven |
| [`irq_service_level1_part13`](../../src/leon2s/irq/irq_service_level1_part13.S) | `FUN_a00609b0` | Loop over the six sources, then address the second-level clear register. | proven |
| [`irq_service_level1_part14`](../../src/leon2s/irq/irq_service_level1_part14.S) | `FUN_a00609c0` | Write the clear to the second-level clear register and address the LEON2 interrupt clear register. | proven |
| [`irq_service_level1_part15`](../../src/leon2s/irq/irq_service_level1_part15.S) | `FUN_a00609d0` | Clear interrupt 1 in the LEON2 interrupt clear register and drop bit 0x2 from 0x9F120028. | proven |
| [`irq_service_level1_part16`](../../src/leon2s/irq/irq_service_level1_part16.S) | `FUN_a00609e0` | Finish 0x9F120028 and unmask interrupt 1 in the LEON2 interrupt mask. | proven |
| [`irq_service_level1_part17`](../../src/leon2s/irq/irq_service_level1_part17.S) | `FUN_a00609f0` | Finish the unmask and return. | proven |
| [`irq_service_level2_part1`](../../src/leon2s/irq/irq_service_level2_part1.S) | `FUN_a00609fc` | Enter the level-2 interrupt service routine (leaf, no handlers). | proven |
| [`irq_service_level2_part2`](../../src/leon2s/irq/irq_service_level2_part2.S) | `FUN_a0060a00` | Mask interrupt 2 (bit 0x4) in the LEON2 interrupt mask. | proven |
| [`irq_service_level2_part3`](../../src/leon2s/irq/irq_service_level2_part3.S) | `FUN_a0060a10` | Finish the mask and set bit 0x4 in the second-level register 0x9F120028. | proven |
| [`irq_service_level2_part4`](../../src/leon2s/irq/irq_service_level2_part4.S) | `FUN_a0060a20` | Finish 0x9F120028 and clear interrupt 2 in the second-level clear register. | proven |
| [`irq_service_level2_part5`](../../src/leon2s/irq/irq_service_level2_part5.S) | `FUN_a0060a30` | Clear interrupt 2 in the LEON2 interrupt clear register and start dropping bit 0x4. | proven |
| [`irq_service_level2_part6`](../../src/leon2s/irq/irq_service_level2_part6.S) | `FUN_a0060a40` | Drop bit 0x4 from 0x9F120028 and unmask interrupt 2 in the LEON2 interrupt mask. | proven |
| [`irq_service_level2_part7`](../../src/leon2s/irq/irq_service_level2_part7.c) | `FUN_a0060a50` | The 'retl; nop' ending of the level-2 interrupt service routine. | proven |
| [`irq_service_level3_part1`](../../src/leon2s/irq/irq_service_level3_part1.S) | `FUN_a0060a58` | Enter the level-3 interrupt service routine (leaf, no handlers). | proven |
| [`irq_service_level3_part2`](../../src/leon2s/irq/irq_service_level3_part2.S) | `FUN_a0060a60` | Mask interrupt 3 (bit 0x8) in the LEON2 interrupt mask. | proven |
| [`irq_service_level3_part3`](../../src/leon2s/irq/irq_service_level3_part3.S) | `FUN_a0060a70` | Set bit 0x8 in the second-level register 0x9F120028. | proven |
| [`irq_service_level3_part4`](../../src/leon2s/irq/irq_service_level3_part4.S) | `FUN_a0060a80` | Clear interrupt 3 in the second-level clear register and address the LEON2 interrupt clear register. | proven |
| [`irq_service_level3_part5`](../../src/leon2s/irq/irq_service_level3_part5.S) | `FUN_a0060a90` | Clear interrupt 3 in the LEON2 interrupt clear register and drop bit 0x8 from 0x9F120028. | proven |
| [`irq_service_level3_part6`](../../src/leon2s/irq/irq_service_level3_part6.S) | `FUN_a0060aa0` | Unmask interrupt 3 in the LEON2 interrupt mask and return. | proven |
| [`irq_service_level3_part7`](../../src/leon2s/irq/irq_service_level3_part7.S) | `FUN_a0060ab0` | Last word (a nop) of the level-3 interrupt service routine. | proven |
| [`irq_service_level4_part1`](../../src/leon2s/irq/irq_service_level4_part1.S) | `FUN_a0060ab4` | Enter the level-4 interrupt service routine and address the LEON2 interrupt mask. | proven |
| [`irq_service_level4_part2`](../../src/leon2s/irq/irq_service_level4_part2.S) | `FUN_a0060ac0` | Mask interrupt 4 (bit 0x10) in the LEON2 interrupt mask. | proven |
| [`irq_service_level4_part3`](../../src/leon2s/irq/irq_service_level4_part3.S) | `FUN_a0060ad0` | Set bit 0x10 in the second-level register 0x9F120028. | proven |
| [`irq_service_level4_part4`](../../src/leon2s/irq/irq_service_level4_part4.S) | `FUN_a0060ae0` | Read the interrupt-4 source status and its source mask. | proven |
| [`irq_service_level4_part5`](../../src/leon2s/irq/irq_service_level4_part5.S) | `FUN_a0060af0` | Drop masked sources, take the acknowledge-after-call flags and start the loop. | proven |
| [`irq_service_level4_part6`](../../src/leon2s/irq/irq_service_level4_part6.S) | `FUN_a0060b00` | Test the next pending source bit. | proven |
| [`irq_service_level4_part7`](../../src/leon2s/irq/irq_service_level4_part7.S) | `FUN_a0060b10` | Look up the source handler in the handler table. | proven |
| [`irq_service_level4_part8`](../../src/leon2s/irq/irq_service_level4_part8.S) | `FUN_a0060b20` | Skip sources without a handler and choose the acknowledge order. | proven |
| [`irq_service_level4_part9`](../../src/leon2s/irq/irq_service_level4_part9.S) | `FUN_a0060b30` | Call the source handler (acknowledge-after-call order). | proven |
| [`irq_service_level4_part10`](../../src/leon2s/irq/irq_service_level4_part10.S) | `FUN_a0060b40` | Acknowledge the source in the status register after its handler returned. | proven |
| [`irq_service_level4_part11`](../../src/leon2s/irq/irq_service_level4_part11.S) | `FUN_a0060b50` | Acknowledge the source in the status register, then call its handler. | proven |
| [`irq_service_level4_part12`](../../src/leon2s/irq/irq_service_level4_part12.S) | `FUN_a0060b60` | Advance to the next source and loop over the seven sources. | proven |
| [`irq_service_level4_part13`](../../src/leon2s/irq/irq_service_level4_part13.S) | `FUN_a0060b70` | Start clearing interrupt 4 in the second-level clear register. | proven |
| [`irq_service_level4_part14`](../../src/leon2s/irq/irq_service_level4_part14.S) | `FUN_a0060b80` | Clear interrupt 4 in the second-level clear register and the LEON2 interrupt clear register. | proven |
| [`irq_service_level4_part15`](../../src/leon2s/irq/irq_service_level4_part15.S) | `FUN_a0060b90` | Drop bit 0x10 from 0x9F120028. | proven |
| [`irq_service_level4_part16`](../../src/leon2s/irq/irq_service_level4_part16.S) | `FUN_a0060ba0` | Unmask interrupt 4 in the LEON2 interrupt mask. | proven |
| [`irq_service_level4_part17`](../../src/leon2s/irq/irq_service_level4_part17.S) | `FUN_a0060bb0` | Return from the level-4 service routine. | proven |
| [`irq_service_level5_part1`](../../src/leon2s/irq/irq_service_level5_part1.S) | `FUN_a0060bb8` | Enter the level-5 interrupt service routine. | proven |
| [`irq_service_level5_part2`](../../src/leon2s/irq/irq_service_level5_part2.S) | `FUN_a0060bc0` | Mask interrupt 5 (bit 0x20) in the LEON2 interrupt mask. | proven |
| [`irq_service_level5_part3`](../../src/leon2s/irq/irq_service_level5_part3.S) | `FUN_a0060bd0` | Set bit 0x20 in the second-level register 0x9F120028. | proven |
| [`irq_service_level5_part4`](../../src/leon2s/irq/irq_service_level5_part4.S) | `FUN_a0060be0` | Finish 0x9F120028 and read the interrupt-5 source status. | proven |
| [`irq_service_level5_part5`](../../src/leon2s/irq/irq_service_level5_part5.S) | `FUN_a0060bf0` | Drop masked sources and take the acknowledge-after-call flags from the mask's upper half. | proven |
| [`irq_service_level5_part6`](../../src/leon2s/irq/irq_service_level5_part6.S) | `FUN_a0060c00` | Start the source loop and test the next pending source bit. | proven |
| [`irq_service_level5_part7`](../../src/leon2s/irq/irq_service_level5_part7.S) | `FUN_a0060c10` | Skip idle sources and look up the source handler in the handler table. | proven |
| [`irq_service_level5_part8`](../../src/leon2s/irq/irq_service_level5_part8.S) | `FUN_a0060c20` | Load the source handler and skip sources without one. | proven |
| [`irq_service_level5_part9`](../../src/leon2s/irq/irq_service_level5_part9.S) | `FUN_a0060c30` | Choose the acknowledge order for the source and call its handler. | proven |
| [`irq_service_level5_part10`](../../src/leon2s/irq/irq_service_level5_part10.S) | `FUN_a0060c40` | Acknowledge the source in the status register after its handler returned. | proven |
| [`irq_service_level5_part11`](../../src/leon2s/irq/irq_service_level5_part11.S) | `FUN_a0060c50` | Acknowledge the source in the status register before calling its handler. | proven |
| [`irq_service_level5_part12`](../../src/leon2s/irq/irq_service_level5_part12.S) | `FUN_a0060c60` | Call the handler, advance to the next source and test the loop bound. | proven |
| [`irq_service_level5_part13`](../../src/leon2s/irq/irq_service_level5_part13.S) | `FUN_a0060c70` | Loop over the fourteen sources, then start clearing interrupt 5. | proven |
| [`irq_service_level5_part14`](../../src/leon2s/irq/irq_service_level5_part14.S) | `FUN_a0060c80` | Clear interrupt 5 in the second-level clear register and address the LEON2 interrupt clear register. | proven |
| [`irq_service_level5_part15`](../../src/leon2s/irq/irq_service_level5_part15.S) | `FUN_a0060c90` | Clear interrupt 5 in the LEON2 interrupt clear register and start dropping bit 0x20 from 0x9F120028. | proven |
| [`irq_service_level5_part16`](../../src/leon2s/irq/irq_service_level5_part16.S) | `FUN_a0060ca0` | Finish 0x9F120028 and start unmasking interrupt 5 in the LEON2 interrupt mask. | proven |
| [`irq_service_level5_part17`](../../src/leon2s/irq/irq_service_level5_part17.S) | `FUN_a0060cb0` | Finish the unmask and return. | proven |
| [`irq_service_level6_part1`](../../src/leon2s/irq/irq_service_level6_part1.S) | `FUN_a0060cbc` | Enter the level-6 interrupt service routine. | proven |
| [`irq_service_level6_part2`](../../src/leon2s/irq/irq_service_level6_part2.S) | `FUN_a0060cc0` | Mask interrupt 6 (bit 0x40) in the LEON2 interrupt mask. | proven |
| [`irq_service_level6_part3`](../../src/leon2s/irq/irq_service_level6_part3.S) | `FUN_a0060cd0` | Finish the mask and start setting bit 0x40 in the active-level register. | proven |
| [`irq_service_level6_part4`](../../src/leon2s/irq/irq_service_level6_part4.S) | `FUN_a0060ce0` | Finish 0x9F120028 and read the interrupt-6 source status. | proven |
| [`irq_service_level6_part5`](../../src/leon2s/irq/irq_service_level6_part5.S) | `FUN_a0060cf0` | Read the its source mask and drop masked sources. | proven |
| [`irq_service_level6_part6`](../../src/leon2s/irq/irq_service_level6_part6.S) | `FUN_a0060d00` | Take the acknowledge-after-call flags and start the source loop. | proven |
| [`irq_service_level6_part7`](../../src/leon2s/irq/irq_service_level6_part7.S) | `FUN_a0060d10` | Test the next pending source bit and address the handler table. | proven |
| [`irq_service_level6_part8`](../../src/leon2s/irq/irq_service_level6_part8.S) | `FUN_a0060d20` | Load the source handler and skip sources without one. | proven |
| [`irq_service_level6_part9`](../../src/leon2s/irq/irq_service_level6_part9.S) | `FUN_a0060d30` | Choose the acknowledge order for the source. | proven |
| [`irq_service_level6_part10`](../../src/leon2s/irq/irq_service_level6_part10.S) | `FUN_a0060d40` | Call the handler, then start acknowledging the source in the status register. | proven |
| [`irq_service_level6_part11`](../../src/leon2s/irq/irq_service_level6_part11.S) | `FUN_a0060d50` | Finish the late acknowledge; on the early path start acknowledging first. | proven |
| [`irq_service_level6_part12`](../../src/leon2s/irq/irq_service_level6_part12.S) | `FUN_a0060d60` | Acknowledge the source, call its handler and advance to the next source. | proven |
| [`irq_service_level6_part13`](../../src/leon2s/irq/irq_service_level6_part13.S) | `FUN_a0060d70` | Loop over the five sources, then start clearing interrupt 6. | proven |
| [`irq_service_level6_part14`](../../src/leon2s/irq/irq_service_level6_part14.S) | `FUN_a0060d80` | Clear interrupt 6 in the second-level clear register. | proven |
| [`irq_service_level6_part15`](../../src/leon2s/irq/irq_service_level6_part15.S) | `FUN_a0060d90` | Clear interrupt 6 in the LEON2 interrupt clear register. | proven |
| [`irq_service_level6_part16`](../../src/leon2s/irq/irq_service_level6_part16.S) | `FUN_a0060da0` | Drop bit 0x40 from 0x9F120028 and address the LEON2 interrupt mask. | proven |
| [`irq_service_level6_part17`](../../src/leon2s/irq/irq_service_level6_part17.S) | `FUN_a0060db0` | Unmask interrupt 6 in the LEON2 interrupt mask and return. | proven |
| [`irq_service_level7_part1`](../../src/leon2s/irq/irq_service_level7_part1.S) | `FUN_a0060dc0` | Mask interrupt 7 (bit 0x80) in the LEON2 interrupt mask (leaf, no handlers). | proven |
| [`irq_service_level7_part2`](../../src/leon2s/irq/irq_service_level7_part2.S) | `FUN_a0060dd0` | Finish the mask and start setting bit 0x80 in the active-level register. | proven |
| [`irq_service_level7_part3`](../../src/leon2s/irq/irq_service_level7_part3.S) | `FUN_a0060de0` | Finish 0x9F120028 and start clearing interrupt 7 in the second-level clear register. | proven |
| [`irq_service_level7_part4`](../../src/leon2s/irq/irq_service_level7_part4.S) | `FUN_a0060df0` | Clear interrupt 7 in the second-level clear register and the LEON2 interrupt clear register. | proven |
| [`irq_service_level7_part5`](../../src/leon2s/irq/irq_service_level7_part5.S) | `FUN_a0060e00` | Drop bit 0x80 from 0x9F120028 and start unmasking interrupt 7. | proven |
| [`irq_service_level7_part6`](../../src/leon2s/irq/irq_service_level7_part6.S) | `FUN_a0060e10` | Unmask interrupt 7 in the LEON2 interrupt mask and return. | proven |
| [`irq_service_level8_part1`](../../src/leon2s/irq/irq_service_level8_part1.S) | `FUN_a0060e1c` | Enter the level-8 interrupt service routine (leaf, no handlers). | proven |
| [`irq_service_level8_part2`](../../src/leon2s/irq/irq_service_level8_part2.S) | `FUN_a0060e20` | Mask interrupt 8 (bit 0x100) in the LEON2 interrupt mask. | proven |
| [`irq_service_level8_part3`](../../src/leon2s/irq/irq_service_level8_part3.S) | `FUN_a0060e30` | Finish the mask and set bit 0x100 in the second-level register 0x9F120028. | proven |
| [`irq_service_level8_part4`](../../src/leon2s/irq/irq_service_level8_part4.S) | `FUN_a0060e40` | Finish 0x9F120028 and clear interrupt 8 in the second-level clear register. | proven |
| [`irq_service_level8_part5`](../../src/leon2s/irq/irq_service_level8_part5.S) | `FUN_a0060e50` | Clear interrupt 8 in the LEON2 interrupt clear register and start dropping bit 0x100. | proven |
| [`irq_service_level8_part6`](../../src/leon2s/irq/irq_service_level8_part6.S) | `FUN_a0060e60` | Drop bit 0x100 from 0x9F120028 and unmask interrupt 8 in the LEON2 interrupt mask. | proven |
| [`irq_service_level8_part7`](../../src/leon2s/irq/irq_service_level8_part7.c) | `FUN_a0060e70` | The 'retl; nop' ending of the level-8 interrupt service routine. | proven |
| [`irq_service_level9_part1`](../../src/leon2s/irq/irq_service_level9_part1.S) | `FUN_a0060e78` | Enter the level-9 interrupt service routine (leaf, no handlers). | proven |
| [`irq_service_level9_part2`](../../src/leon2s/irq/irq_service_level9_part2.S) | `FUN_a0060e80` | Mask interrupt 9 (bit 0x200) in the LEON2 interrupt mask. | proven |
| [`irq_service_level9_part3`](../../src/leon2s/irq/irq_service_level9_part3.S) | `FUN_a0060e90` | Set bit 0x200 in the second-level register 0x9F120028. | proven |
| [`irq_service_level9_part4`](../../src/leon2s/irq/irq_service_level9_part4.S) | `FUN_a0060ea0` | Clear interrupt 9 in the second-level clear register and address the LEON2 interrupt clear register. | proven |
| [`irq_service_level9_part5`](../../src/leon2s/irq/irq_service_level9_part5.S) | `FUN_a0060eb0` | Clear interrupt 9 in the LEON2 interrupt clear register and drop bit 0x200 from 0x9F120028. | proven |
| [`irq_service_level9_part6`](../../src/leon2s/irq/irq_service_level9_part6.S) | `FUN_a0060ec0` | Unmask interrupt 9 in the LEON2 interrupt mask and return. | proven |
| [`irq_service_level9_part7`](../../src/leon2s/irq/irq_service_level9_part7.S) | `FUN_a0060ed0` | Last word (a nop) of the level-9 interrupt service routine. | proven |
| [`irq_service_level10_part1`](../../src/leon2s/irq/irq_service_level10_part1.S) | `FUN_a0060ed4` | Enter the level-10 interrupt service routine and address the LEON2 interrupt mask. | proven |
| [`irq_service_level10_part2`](../../src/leon2s/irq/irq_service_level10_part2.S) | `FUN_a0060ee0` | Mask interrupt 10 (bit 0x400) in the LEON2 interrupt mask and start setting 0x9F120028. | proven |
| [`irq_service_level10_part3`](../../src/leon2s/irq/irq_service_level10_part3.S) | `FUN_a0060ef0` | Set bit 0x400 in the second-level register 0x9F120028. | proven |
| [`irq_service_level10_part4`](../../src/leon2s/irq/irq_service_level10_part4.S) | `FUN_a0060f00` | Read the interrupt-10 source status and its source mask. | proven |
| [`irq_service_level10_part5`](../../src/leon2s/irq/irq_service_level10_part5.S) | `FUN_a0060f10` | Drop masked sources, take the acknowledge-after-call flags and start the loop. | proven |
| [`irq_service_level10_part6`](../../src/leon2s/irq/irq_service_level10_part6.S) | `FUN_a0060f20` | Test the next pending source bit. | proven |
| [`irq_service_level10_part7`](../../src/leon2s/irq/irq_service_level10_part7.S) | `FUN_a0060f30` | Skip idle sources and choose the acknowledge order. | proven |
| [`irq_service_level10_part8`](../../src/leon2s/irq/irq_service_level10_part8.S) | `FUN_a0060f40` | Load the source handler from the handler table and call it. | proven |
| [`irq_service_level10_part9`](../../src/leon2s/irq/irq_service_level10_part9.S) | `FUN_a0060f50` | Acknowledge the source in the status register after its handler returned. | proven |
| [`irq_service_level10_part10`](../../src/leon2s/irq/irq_service_level10_part10.S) | `FUN_a0060f60` | Advance to the next source and acknowledge it in the status register (early path). | proven |
| [`irq_service_level10_part11`](../../src/leon2s/irq/irq_service_level10_part11.S) | `FUN_a0060f70` | Call the source handler after the early acknowledge and advance to the next source. | proven |
| [`irq_service_level10_part12`](../../src/leon2s/irq/irq_service_level10_part12.S) | `FUN_a0060f80` | Loop over both sources, then start the end-of-service clear. | proven |
| [`irq_service_level10_part13`](../../src/leon2s/irq/irq_service_level10_part13.S) | `FUN_a0060f90` | Clear interrupt 10 in the second-level clear register and prepare the LEON2 block. | proven |
| [`irq_service_level10_part14`](../../src/leon2s/irq/irq_service_level10_part14.S) | `FUN_a0060fa0` | Clear interrupt 10 in the LEON2 interrupt clear register. | proven |
| [`irq_service_level10_part15`](../../src/leon2s/irq/irq_service_level10_part15.S) | `FUN_a0060fb0` | Drop the in-service bit of interrupt 10 and read the LEON2 interrupt mask. | proven |
| [`irq_service_level10_part16`](../../src/leon2s/irq/irq_service_level10_part16.S) | `FUN_a0060fc0` | Unmask interrupt 10 again and return from the service routine. | proven |
| [`irq_service_level11_part1`](../../src/leon2s/irq/irq_service_level11_part1.S) | `FUN_a0060fd0` | Mask interrupt 11 (bit 0x800) in the LEON2 interrupt mask. | proven |
| [`irq_service_level11_part2`](../../src/leon2s/irq/irq_service_level11_part2.S) | `FUN_a0060fe0` | Finish the mask and start setting bit 0x800 in the active-level register. | proven |
| [`irq_service_level11_part3`](../../src/leon2s/irq/irq_service_level11_part3.S) | `FUN_a0060ff0` | Mark interrupt 11 in service, clear it at both levels, then unmask it and return. | proven |
| [`irq_service_level12`](../../src/leon2s/irq/irq_service_level12.c) | `FUN_a006102c` | Service interrupt 12: run the handlers of its two sources and acknowledge them. | proven |
| [`irq_service_level13`](../../src/leon2s/irq/irq_service_level13.c) | `FUN_a0061138` | Service interrupt 13, which has no sources: mark it in service, clear it and unmask it. | proven |
| [`irq_service_level14`](../../src/leon2s/irq/irq_service_level14.c) | `FUN_a006119c` | Service interrupt 14, which has no sources: mark it in service, clear it and unmask it. | proven |
| [`irq_service_level15`](../../src/leon2s/irq/irq_service_level15.c) | `FUN_a0061200` | Clear interrupt 15 (non-maskable level) at both interrupt controllers. | proven |
| [`irq_set_mask_preset`](../../src/leon2s/irq/irq_set_mask_preset.c) | `FUN_a00b1fe0` | Write one of two value sets to the interrupt mask registers. | descriptive |

<a id="timer"></a>
## Timers and delays

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`timer_delay_long_units`](../../src/leon2s/timer/timer_delay_long_units.c) | `FUN_a00b1794` | Wait in an idle loop of n times 50,000 passes. | proven |
| [`timer_delay_units`](../../src/leon2s/timer/timer_delay_units.c) | `FUN_a00b160c` | Wait in a counted idle loop for a number of delay units. | proven |
| [`timer_get_ticks`](../../src/leon2s/timer/timer_get_ticks.c) | `FUN_a00b2064` | Return the current tick count. | proven |
| [`timer_stamp_older_than_50`](../../src/leon2s/timer/timer_stamp_older_than_50.c) | `FUN_a008f990` | Return whether more than 50 ticks passed since a time stamp. | proven |
| [`timer_tick_isr`](../../src/leon2s/timer/timer_tick_isr.c) | `FUN_a00618d8` | Advance the tick count, slow-tick flags and the 16 software timers on each timer interrupt. | proven |

<a id="sys"></a>
## System control: channels, modes, configuration

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`sys_core_setup_unit_0320`](../../src/leon2s/sys/sys_core_setup_unit_0320.c) | `FUN_a00b18ac` | Start the unit at core register 0x9F120320 with its buffer address. | descriptive |
| [`sys_dsc_dec_build_hdmi21_config`](../../src/leon2s/sys/sys_dsc_dec_build_hdmi21_config.c) | `FUN_a00a63a8` | Build a full DSC decoder set-up record for an HDMI 2.1 input. | derived |
| [`sys_dsc_dec_calc_pixel_clock`](../../src/leon2s/sys/sys_dsc_dec_calc_pixel_clock.c) | `FUN_a00a535c` | Compute and print the pixel clock of the DSC picture and program the clock. | proven |
| [`sys_dsc_dec_calc_reg_ratio`](../../src/leon2s/sys/sys_dsc_dec_calc_reg_ratio.c) | `FUN_a00a6110` | Return the ratio of the upper halves of decoder registers 2 and 3. | descriptive |
| [`sys_dsc_dec_copy_block`](../../src/leon2s/sys/sys_dsc_dec_copy_block.c) | `FUN_a00a60d8` | Copy 24 words between the two register areas of a DSC decoder record. | descriptive |
| [`sys_dsc_dec_fill_default_config`](../../src/leon2s/sys/sys_dsc_dec_fill_default_config.c) | `FUN_a00a507c` | Fill a DSC decoder set-up record with fixed default values. | derived |
| [`sys_dsc_dec_fill_hdmi21_timing`](../../src/leon2s/sys/sys_dsc_dec_fill_hdmi21_timing.c) | `FUN_a00a6260` | Fill the timing fields of a DSC decoder set-up record from an HDMI 2.1 input. | derived |
| [`sys_dsc_dec_get_regb4_bit2`](../../src/leon2s/sys/sys_dsc_dec_get_regb4_bit2.c) | `FUN_a00aec2c` | Return bit 2 of register 0xB4 of DSC decoder 0. | derived |
| [`sys_dsc_dec_init`](../../src/leon2s/sys/sys_dsc_dec_init.c) | `FUN_a00a47b0` | Initialise the DSC decoder: register pointers, state and default set-up. | derived |
| [`sys_dsc_dec_init_register_pointers`](../../src/leon2s/sys/sys_dsc_dec_init_register_pointers.c) | `FUN_a00a4e68` | Fill the register block pointers of the DSC decoder. | derived |
| [`sys_dsc_dec_is_dp_source`](../../src/leon2s/sys/sys_dsc_dec_is_dp_source.c) | `FUN_a00a61d4` | Return whether the DP input selected for the decoder carries a stream. | derived |
| [`sys_dsc_dec_is_hdmi21_mode_lost`](../../src/leon2s/sys/sys_dsc_dec_is_hdmi21_mode_lost.c) | `FUN_a00a621c` | Return whether byte +1 of the record of the decoder's HDMI 2.1 input is 0. | descriptive |
| [`sys_dsc_dec_is_hdmi21_source`](../../src/leon2s/sys/sys_dsc_dec_is_hdmi21_source.c) | `FUN_a00a6190` | Return whether byte +0x2D of the record of the decoder's HDMI 2.1 input equals 1. | descriptive |
| [`sys_dsc_dec_is_source_absent`](../../src/leon2s/sys/sys_dsc_dec_is_source_absent.c) | `FUN_a00a47e0` | Return whether the compressed (DSC) source of the decoder is gone. | derived |
| [`sys_dsc_dec_load_default_config`](../../src/leon2s/sys/sys_dsc_dec_load_default_config.c) | `FUN_a00a5ce8` | Set the DSC decoder clock and load its default set-up with the decoder held off. | derived |
| [`sys_dsc_dec_read_config`](../../src/leon2s/sys/sys_dsc_dec_read_config.c) | `FUN_a00a5d8c` | Read the DSC decoder registers back into a set-up record. | derived |
| [`sys_dsc_dec_reset_state`](../../src/leon2s/sys/sys_dsc_dec_reset_state.c) | `FUN_a00a5050` | Set the DSC decoder state machine back to its first state. | derived |
| [`sys_dsc_dec_run_state`](../../src/leon2s/sys/sys_dsc_dec_run_state.c) | `FUN_a00a4880` | Run the DSC decoder state machine: detect a compressed source, set up, watch. | derived |
| `sys_dsc_dec_run_state_jump_table` | `switchdataD_a00a486c` | Jump table 1 of the switch statements in sys_dsc_dec_run_state. | proven |
| [`sys_dsc_dec_set_clock`](../../src/leon2s/sys/sys_dsc_dec_set_clock.c) | `FUN_a00a4ec4` | Switch the DSC decoder clock to its start value, or set it from a pixel clock. | descriptive |
| [`sys_dsc_dec_set_pll`](../../src/leon2s/sys/sys_dsc_dec_set_pll.c) | `FUN_a00a5148` | Program a DSC decoder clock synthesiser from a pixel clock. | descriptive |
| [`sys_dsc_dec_set_regb4_bit1`](../../src/leon2s/sys/sys_dsc_dec_set_regb4_bit1.c) | `FUN_a00aec10` | Set bit 1 of register 0xB4 of DSC decoder 0. | derived |
| [`sys_dsc_dec_status_bit0`](../../src/leon2s/sys/sys_dsc_dec_status_bit0.c) | `FUN_a00a60ac` | Return bit 0 of status word 0xB0 of DSC decoder 0, or 2 for others. | descriptive |
| [`sys_dsc_dec_write_config`](../../src/leon2s/sys/sys_dsc_dec_write_config.c) | `VBP_tmp` | Write a DSC decoder set-up record to its registers and check the delay lines. | derived |
| [`sys_dsc_dec_write_default_config`](../../src/leon2s/sys/sys_dsc_dec_write_default_config.c) | `FUN_a00a5cb4` | Write the default set-up record to the DSC decoder. | derived |
| [`sys_dsc_enc_compute_pps`](../../src/leon2s/sys/sys_dsc_enc_compute_pps.c) | `FUN_a00dd488` | Compute the rate-control values and the picture parameter set of the compression encoder. | proven |
| [`sys_dsc_enc_configure`](../../src/leon2s/sys/sys_dsc_enc_configure.c) | `FUN_a00de8ac` | Fill the encoder's timing record, compute its parameters and program the encoder. | proven |
| [`sys_dsc_enc_select_route`](../../src/leon2s/sys/sys_dsc_enc_select_route.c) | `FUN_a00dcc80` | Select the encoder's route for a case and print its name. | descriptive |
| [`sys_dsc_enc_set_parameters`](../../src/leon2s/sys/sys_dsc_enc_set_parameters.c) | `FUN_a00dd398` | Unpack the compression parameters received from the main processor into the timing record. | derived |
| [`sys_dsc_enc_set_route_bits`](../../src/leon2s/sys/sys_dsc_enc_set_route_bits.c) | `FUN_a00dcc50` | Keep bits 0-5 of the route register and OR in the value shifted left by 6. | descriptive |
| [`sys_dsc_enc_write_timing_words`](../../src/leon2s/sys/sys_dsc_enc_write_timing_words.c) | `FUN_a00dccd8` | Pack the encoder's timing values into register words. | descriptive |
| [`sys_get_chip_revision`](../../src/leon2s/sys/sys_get_chip_revision.c) | `FUN_a008d800` | Return the chip revision code (0x80..0x84) from the ID registers. | derived |
| [`sys_main_part1`](../../src/leon2s/sys/sys_main_part1.S) | `FUN_a0060864` | Open the main frame and run the system set-up that prints the Leon2S banner. | proven |
| [`sys_main_part2`](../../src/leon2s/sys/sys_main_part2.S) | `FUN_a0060870` | Run the next start-up steps, including the HDMI receiver PHY set-up. | proven |
| [`sys_main_part3`](../../src/leon2s/sys/sys_main_part3.S) | `FUN_a0060880` | Run two more start-up steps, the second setting up the debug console. | proven |
| [`sys_main_part4`](../../src/leon2s/sys/sys_main_part4.S) | `FUN_a0060890` | Call hdr_init(1) and ipc_post_ready_flag, the last two start-up steps. | proven |
| [`sys_main_part5`](../../src/leon2s/sys/sys_main_part5.S) | `FUN_a00608a0` | Main loop: run the queued deferred calls and the next service task. | proven |
| [`sys_main_part6`](../../src/leon2s/sys/sys_main_part6.S) | `FUN_a00608b0` | Main loop: run the link standby / colour-space task and the debug console reader. | proven |
| [`sys_main_part7`](../../src/leon2s/sys/sys_main_part7.S) | `FUN_a00608c0` | Main loop: publish the input-port status words and run the next task. | proven |
| [`sys_main_part8`](../../src/leon2s/sys/sys_main_part8.S) | `FUN_a00608d0` | Main loop: run hdr_task and address register 0xCF03C820. | proven |
| [`sys_main_part9`](../../src/leon2s/sys/sys_main_part9.S) | `FUN_a00608e0` | Main loop: copy register 0xCF03C820 to 0xCF03C830 and repeat the loop. | proven |
| [`sys_otp_check_records`](../../src/leon2s/sys/sys_otp_check_records.c) | `FUN_a008d490` | Check the records of loaded factory data and reload or drop bad ones. | descriptive |
| [`sys_otp_find_patch`](../../src/leon2s/sys/sys_otp_find_patch.c) | `FUN_a008d1d8` | Return whether an address is listed in the patch table. | descriptive |
| [`sys_otp_load_local_data`](../../src/leon2s/sys/sys_otp_load_local_data.c) | `FUN_a008d70c` | Load three groups of factory data records into local tables. | descriptive |
| [`sys_otp_load_patch_table`](../../src/leon2s/sys/sys_otp_load_patch_table.c) | `FUN_a008d0b8` | Load the address patch table from the one-time-programmable data store. | descriptive |
| [`sys_otp_load_shared_data`](../../src/leon2s/sys/sys_otp_load_shared_data.c) | `FUN_a008d690` | Load factory data records 12..16 into shared memory and report it. | descriptive |
| [`sys_otp_read_bytes`](../../src/leon2s/sys/sys_otp_read_bytes.c) | `FUN_a008d2e0` | Read a range of bytes from the one-time-programmable data store, applying patches. | descriptive |
| [`sys_otp_read_patch_byte`](../../src/leon2s/sys/sys_otp_read_patch_byte.c) | `FUN_a008d280` | Return the replacement byte of the patch entry found last. | descriptive |
| [`sys_register_tick_hook`](../../src/leon2s/sys/sys_register_tick_hook.c) | `FUN_a00b2070` | Store a routine in the first free tick hook slot. | derived |
| [`sys_return_zero`](../../src/leon2s/sys/sys_return_zero.c) | `FUN_a0089e4c` | Return 0. | descriptive |
| [`sys_task_create`](../../src/leon2s/sys/sys_task_create.c) | `CONV2HDMITX_UpdateInterface_3` | Fill the first free record of the task table from a descriptor. | derived |
| [`sys_task_init`](../../src/leon2s/sys/sys_task_init.c) | `FUN_a00b1e70` | Initialise the tick record and the task table. | derived |
| [`sys_task_remove`](../../src/leon2s/sys/sys_task_remove.c) | `FUN_a00b222c` | Remove the task with a given id from the task table. | derived |
| [`sys_task_run_pending`](../../src/leon2s/sys/sys_task_run_pending.c) | `FUN_a00b229c` | Run every task whose time has come. | derived |
| [`sys_task_start`](../../src/leon2s/sys/sys_task_start.c) | `CONV2HDMITX_UpdateInterface_4` | Start the task whose record carries the given descriptor address: fill period, count and routine. | derived |

<a id="input"></a>
## Video inputs: detection, measurement, routing

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`input_apply_port_enable_mask`](../../src/leon2s/input/input_apply_port_enable_mask.c) | `FUN_a006d46c` | Power on the ports whose bit is set in the mask and power off the others. | derived |
| [`input_decode_port_code`](../../src/leon2s/input/input_decode_port_code.c) | `FUN_a006d5a8` | Map the codes 0x31..0x81 to the indices 0..5. | descriptive |
| [`input_get_port_option`](../../src/leon2s/input/input_get_port_option.c) | `FUN_a00703b8` | Return option bit n of the per-port option mask. | descriptive |
| [`input_get_port_option_level`](../../src/leon2s/input/input_get_port_option_level.c) | `FUN_a00703d4` | Return the second-level option bit n when option bit n is set. | descriptive |
| [`input_get_port_source_code`](../../src/leon2s/input/input_get_port_source_code.c) | `FUN_a00858f0` | Return the source code (0x51..0x81) stored for a port. | derived |
| [`input_init_phy_registers`](../../src/leon2s/input/input_init_phy_registers.c) | `FUN_a008ced8` | Load the fixed start-up settings of the receiver PHY control block. | derived |
| [`input_init_phy_registers_wrapper`](../../src/leon2s/input/input_init_phy_registers_wrapper.c) | `FUN_a006d30c` | Run the fixed receiver PHY register set-up. | descriptive |
| [`input_init_receivers`](../../src/leon2s/input/input_init_receivers.c) | `FUN_a006d31c` | Initialise the HDMI and DP receivers and their PHYs at start-up. | proven |
| [`input_load_port_flag_bits`](../../src/leon2s/input/input_load_port_flag_bits.c) | `FUN_a006d4e0` | Copy one per-port flag bit from the command byte into each port record. | descriptive |
| [`input_poll_port_services`](../../src/leon2s/input/input_poll_port_services.c) | `FUN_a006d050` | Run one pass of the receiver, DP output and cable-state service routines of the main loop. | descriptive |
| [`input_port_code_to_index`](../../src/leon2s/input/input_port_code_to_index.c) | `FUN_a00c5fb0` | Convert a port code 0x31..0x81 to the input number 0..5. | derived |
| [`input_port_fix_reg2e`](../../src/leon2s/input/input_port_fix_reg2e.c) | `FUN_a00c5c30` | Correct register 0x2E of an input when its status requires it. | descriptive |
| [`input_port_get_reg2e_bit5`](../../src/leon2s/input/input_port_get_reg2e_bit5.c) | `FUN_a00c4e4c` | Return bit 5 of register 0x2E of an input. | descriptive |
| [`input_port_handle_reg71_bits`](../../src/leon2s/input/input_port_handle_reg71_bits.c) | `FUN_a00c59e0` | Act on two status bits of register 0x71 of an input. | descriptive |
| [`input_port_raise_event`](../../src/leon2s/input/input_port_raise_event.c) | `FUN_a00c5f18` | Record an event for an input and write it to the hardware when the state changed. | descriptive |
| [`input_port_set_event_bit`](../../src/leon2s/input/input_port_set_event_bit.c) | `FUN_a00c5d34` | Write an input's event bit in its register. | descriptive |
| [`input_port_write_event_byte`](../../src/leon2s/input/input_port_write_event_byte.c) | `FUN_a00c5da8` | Write an event byte to an input's register and clear its buffer. | descriptive |
| [`input_power_off_receivers_mode0`](../../src/leon2s/input/input_power_off_receivers_mode0.c) | `FUN_a006d0fc` | Power off all HDMI and DP receivers and their links (power-off mode 0). | derived |
| [`input_power_off_receivers_mode1`](../../src/leon2s/input/input_power_off_receivers_mode1.c) | `FUN_a006d204` | Power off all HDMI and DP receivers and their links (power-off mode 1). | derived |
| [`input_read_port_timing`](../../src/leon2s/input/input_read_port_timing.c) | `FUN_a0070434` | Collect the eight timing values of a port into a reply buffer. | derived |
| [`input_run_link_tasks`](../../src/leon2s/input/input_run_link_tasks.c) | `FUN_a006fa28` | Run the link state machines of all HDMI and DP ports once. | proven |
| [`input_run_port_services`](../../src/leon2s/input/input_run_port_services.c) | `FUN_a00c6730` | Run the per-input services once, including the copy-protection service of the outputs. | derived |
| [`input_set_command_flags`](../../src/leon2s/input/input_set_command_flags.c) | `FUN_a006fff4` | Store the port action flag byte sent by the main processor. | derived |
| [`input_set_link_state`](../../src/leon2s/input/input_set_link_state.c) | `FUN_a006d53c` | Set the link state of a port record and clear its retry flag. | derived |
| [`input_set_port_option_mask`](../../src/leon2s/input/input_set_port_option_mask.c) | `FUN_a0070000` | Build the per-port option bit mask from three command bytes. | descriptive |
| [`input_set_port_type`](../../src/leon2s/input/input_set_port_type.c) | `FUN_a006d414` | Set the type of one port record, or of ports 0..5 for 0xFF. | derived |
| [`input_set_ports_power_off`](../../src/leon2s/input/input_set_ports_power_off.c) | `FUN_a006d3d8` | Set all nine port records to the power-off link state. | derived |
| [`input_set_ports_power_on`](../../src/leon2s/input/input_set_ports_power_on.c) | `FUN_a006d39c` | Set ports 0..6 to the power-on link state. | derived |
| [`input_set_ports_power_on_by_status`](../../src/leon2s/input/input_set_ports_power_on_by_status.c) | `FUN_a00b3530` | Set the link state of port records above state 3 back to 2 (power on) when status register bits ask. | descriptive |
| [`input_set_ports_power_on_wrapper`](../../src/leon2s/input/input_set_ports_power_on_wrapper.c) | `FUN_a006d3c8` | Set ports 0..6 to the power-on link state. | derived |
| [`input_update_port_records`](../../src/leon2s/input/input_update_port_records.c) | `FUN_a00c601c` | Update the record and the event bits of all six inputs. | derived |

<a id="hdmi"></a>
## HDMI

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`_hdmi21_Initialize`](../../src/leon2s/hdmi/_hdmi21_Initialize.c) | `hdmi21_Initialize` | Initialise the HDMI 2.1 receiver hardware and both ports at start-up. | proven |
| [`_hdmi_Init_Interrupt`](../../src/leon2s/hdmi/_hdmi_Init_Interrupt.c) | `hdmi_Init_Interrupt` | Set up the interrupts of both HDMI 2.1 receivers. | proven |
| [`_hdmi_PHY_Set_CTLE`](../../src/leon2s/hdmi/_hdmi_PHY_Set_CTLE.c) | `hdmi_PHY_Set_CTLE` | Set the fixed CTLE equaliser values of an HDMI port. | proven |
| [`CONV2HDMITX_UpdateInterface`](../../src/leon2s/hdmi/CONV2HDMITX_UpdateInterface.c) | `CONV2HDMITX_UpdateInterface` | Copy the input's picture format (mode, depth, clock) into an HDMI output record. | proven |
| [`CONV2HDMITX_UpdatePacket`](../../src/leon2s/hdmi/CONV2HDMITX_UpdatePacket.c) | `CONV2HDMITX_UpdatePacket` | Update and send or clear the data packets of an HDMI output from its input. | proven |
| [`Deskew_HotPlug`](../../src/leon2s/hdmi/Deskew_HotPlug.c) | `Deskew_HotPlug` | Request a hot-plug toggle of a port after a deskew failure. | proven |
| [`DRV_HDMI21_IQ_Scan_byCED`](../../src/leon2s/hdmi/DRV_HDMI21_IQ_Scan_byCED.c) | `DRV_HDMI21_IQ_Scan_byCED` | Scan the IQ setting per lane by character error counts and apply the middle of the good range. | proven |
| [`DRV_HDMI21_LMS_To_EQ`](../../src/leon2s/hdmi/DRV_HDMI21_LMS_To_EQ.c) | `DRV_HDMI21_LMS_To_EQ` | Write fixed values to the channel and lane EQ registers of an HDMI 2.1 PHY, then reset the lane EQ. | proven |
| [`DRV_HDMI21_LTS_STS_InitialSettings`](../../src/leon2s/hdmi/DRV_HDMI21_LTS_STS_InitialSettings.c) | `DRV_HDMI21_LTS_STS_InitialSettings` | Clear the link training record and set the start-up PHY registers of an HDMI 2.1 receiver. | proven |
| [`DRV_HDMI21_PHY_Freq_Detection`](../../src/leon2s/hdmi/DRV_HDMI21_PHY_Freq_Detection.c) | `DRV_HDMI21_PHY_Freq_Detection` | Measure and print the clock frequency of each lane of an HDMI 2.1 PHY. | proven |
| [`DRV_HDMI21_PHY_INV_PICDR_Reset`](../../src/leon2s/hdmi/DRV_HDMI21_PHY_INV_PICDR_Reset.c) | `DRV_HDMI21_PHY_INV_PICDR_Reset` | Reset the clock-recovery (PI-CDR) blocks of the HDMI 2.1 lanes. | proven |
| [`DRV_HDMI21_PHY_PICDR_Reset`](../../src/leon2s/hdmi/DRV_HDMI21_PHY_PICDR_Reset.c) | `DRV_HDMI21_PHY_PICDR_Reset` | Reset the clock recovery of the HDMI 2.1 lanes, by method chosen by link rate. | proven |
| [`DRV_HDMI21_Print_SCDC_Error`](../../src/leon2s/hdmi/DRV_HDMI21_Print_SCDC_Error.c) | `DRV_HDMI21_Print_SCDC_Error` | Read and print the SCDC error counters of each HDMI 2.1 lane. | proven |
| [`DRV_HDMI21_ReStart_AEQ2`](../../src/leon2s/hdmi/DRV_HDMI21_ReStart_AEQ2.c) | `DRV_HDMI21_ReStart_AEQ2` | Restart adaptive equalisation of the HDMI 2.1 lanes for the current link rate. | proven |
| [`DRV_HDMI21_RX_Init`](../../src/leon2s/hdmi/DRV_HDMI21_RX_Init.c) | `DRV_HDMI21_RX_Init` | Initialise the HDMI 2.1 receiver driver and enable both ports once. | proven |
| [`DRV_HDMI21_RX_SCDC_Chk_Err`](../../src/leon2s/hdmi/DRV_HDMI21_RX_SCDC_Chk_Err.c) | `DRV_HDMI21_RX_SCDC_Chk_Err` | Read the SCDC error counters of an HDMI 2.1 receiver and flag bad lanes. | proven |
| [`DRV_HDMI21_RXDetect_FSM_Init`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_Init.c) | `DRV_HDMI21_RXDetect_FSM_Init` | Run the start state of the HDMI 2.1 link-training state machine. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_1`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_1.c) | `DRV_HDMI21_RXDetect_FSM_LTS_1` | Run link training state 1 of an HDMI 2.1 receiver. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_2`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_2.c) | `DRV_HDMI21_RXDetect_FSM_LTS_2` | Run link training state 2 of an HDMI 2.1 receiver. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_3`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_3.c) | `DRV_HDMI21_RXDetect_FSM_LTS_3` | Run link training state 3: wait for FLT_update to clear, take the FRL rate, set lane requests 5..8. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_4`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_4.c) | `DRV_HDMI21_RXDetect_FSM_LTS_4` | Run link training state 4 of an HDMI 2.1 receiver. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err.c) | `DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err` | Check FRL rate and lane errors during link training and handle FLT updates. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err.c) | `DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err` | Run the SCDC error check state of HDMI 2.1 link training. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable.c) | `DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable` | Watch a trained HDMI 2.1 link for rate changes, lane lock loss and error bursts. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_L`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_L.c) | `DRV_HDMI21_RXDetect_FSM_LTS_L` | Run state LTS:L of an HDMI 2.1 receiver: go to LTS:3 once an FRL rate is set, else count passes. | proven |
| [`DRV_HDMI21_RXDetect_FSM_LTS_P`](../../src/leon2s/hdmi/DRV_HDMI21_RXDetect_FSM_LTS_P.c) | `DRV_HDMI21_RXDetect_FSM_LTS_P` | Run the LTS:P link training state (pattern check, FLT update) of an HDMI 2.1 receiver. | proven |
| [`DRV_HDMI21_Set_PHY`](../../src/leon2s/hdmi/DRV_HDMI21_Set_PHY.c) | `DRV_HDMI21_Set_PHY` | Set up the HDMI 2.1 PHY for the trained link rate and search the lane EQ values. | proven |
| [`DRV_HDMI21_Set_PHY_PreAEQ`](../../src/leon2s/hdmi/DRV_HDMI21_Set_PHY_PreAEQ.c) | `DRV_HDMI21_Set_PHY_PreAEQ` | Write the pre-AEQ R/C values of the four HDMI 2.1 lanes and restart them. | proven |
| [`DRV_HDMI21_TXDetect_FSM_Init`](../../src/leon2s/hdmi/DRV_HDMI21_TXDetect_FSM_Init.c) | `FUN_a00a3788` | Run the start state of the HDMI TX FRL link training: clear the FRL rate. | proven |
| [`DRV_HDMI21_TXDetect_FSM_LTS_1`](../../src/leon2s/hdmi/DRV_HDMI21_TXDetect_FSM_LTS_1.c) | `FUN_a00a3810` | Run LTS:1 of the HDMI TX FRL training: read the sink's SCDC and pick the FRL rate. | proven |
| [`DRV_HDMI21_TXDetect_FSM_LTS_2`](../../src/leon2s/hdmi/DRV_HDMI21_TXDetect_FSM_LTS_2.c) | `FUN_a00a3a10` | Run LTS:2 of the HDMI TX FRL training: write the FRL rate and FFE levels to the sink. | proven |
| [`DRV_HDMI21_TXDetect_FSM_LTS_3`](../../src/leon2s/hdmi/DRV_HDMI21_TXDetect_FSM_LTS_3.c) | `FUN_a00a3b68` | Run LTS:3 of the HDMI TX FRL training: answer the sink's link pattern and FFE requests. | proven |
| [`DRV_HDMI21_TXDetect_FSM_LTS_4`](../../src/leon2s/hdmi/DRV_HDMI21_TXDetect_FSM_LTS_4.c) | `FUN_a00a4238` | Run LTS:4 of the HDMI TX FRL training: fall back to a lower FRL rate or give up. | proven |
| [`DRV_HDMI21_TXDetect_FSM_LTS_L`](../../src/leon2s/hdmi/DRV_HDMI21_TXDetect_FSM_LTS_L.c) | `FUN_a00a4524` | Run LTS:L of the HDMI TX FRL training: write 0 to SCDC register 0x31; go to LTS:2 when in FRL mode. | proven |
| [`DRV_HDMI21_TXDetect_FSM_LTS_P`](../../src/leon2s/hdmi/DRV_HDMI21_TXDetect_FSM_LTS_P.c) | `FUN_a00a4370` | Run LTS:P of the HDMI TX FRL training: start FRL video once the sink is ready. | proven |
| [`DRV_HDMI_Config_BCH`](../../src/leon2s/hdmi/DRV_HDMI_Config_BCH.c) | `DRV_HDMI_Config_BCH` | Enable or disable BCH error correction of an HDMI receiver port. | proven |
| [`DRV_HDMI_DbgHDMITaskCtrl`](../../src/leon2s/hdmi/DRV_HDMI_DbgHDMITaskCtrl.c) | `DRV_HDMI_DbgHDMITaskCtrl` | Start or stop the HDMI EQ task or receiver timers from the debug menu. | proven |
| [`DRV_HDMI_DbgMenu`](../../src/leon2s/hdmi/DRV_HDMI_DbgMenu.c) | `DRV_HDMI_DbgMenu` | Run one HDMI debug menu command (messages, tasks, LTP force pass, PHY bit). | proven |
| [`DRV_HDMI_Del_Timer`](../../src/leon2s/hdmi/DRV_HDMI_Del_Timer.c) | `DRV_HDMI_Del_Timer` | Stop the HDMI receiver task timers of the given type. | proven |
| [`DRV_HDMI_EQDetect_Timer`](../../src/leon2s/hdmi/DRV_HDMI_EQDetect_Timer.c) | `DRV_HDMI_EQDetect_Timer` | Check each HDMI port for clock changes and restart its EQ flow when needed. | proven |
| [`DRV_HDMI_EQScan_FSM_Check_MEQ_Done`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_Check_MEQ_Done.c) | `DRV_HDMI_EQScan_FSM_Check_MEQ_Done` | EQ scan step: check skew and error state after manual EQ, else restart the PHY. | proven |
| [`DRV_HDMI_EQScan_FSM_Done`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_Done.c) | `DRV_HDMI_EQScan_FSM_Done` | EQ scan step: store the final modes, enable BCH and print the EQ exit message. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_BA_Turning`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_BA_Turning.c) | `DRV_HDMI_EQScan_FSM_PHY_BA_Turning` | EQ scan step: once all three channels report 0xF, raise the EQ value by 0, 2 or 3 and move on. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_ChkError`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_ChkError.c) | `DRV_HDMI_EQScan_FSM_PHY_ChkError` | EQ scan step: check the per-channel SCDC errors and step the RVGA index. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_DPHY`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_DPHY.c) | `DRV_HDMI_EQScan_FSM_PHY_DPHY` | EQ scan step: write four fixed PHY register fields for a clock up to 600 and go to the PICDR state. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_EQ`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_EQ.c) | `DRV_HDMI_EQScan_FSM_PHY_EQ` | EQ scan step: set the per-lane PHY and EQ table values for the clock range. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_Init`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_Init.c) | `HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE` | EQ scan step: initialise the PHY of a port for its clock and scrambling mode. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_PICDR`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_PICDR.c) | `DRV_HDMI_EQScan_FSM_PHY_PICDR` | EQ scan step: set the clock-recovery (PI-CDR) registers for the clock range. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_PLL`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_PLL.c) | `DRV_HDMI_EQScan_FSM_PHY_PLL` | EQ scan step: write the PLL registers for the measured clock range and go to the DPHY state. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_PreAEQ`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_PreAEQ.c) | `DRV_HDMI_EQScan_FSM_PHY_PreAEQ` | EQ scan step: step through the pre-AEQ table of RCT/CFT values per channel. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_PreChkError`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_PreChkError.c) | `DRV_HDMI_EQScan_FSM_PHY_PreChkError` | EQ scan step: raise the PHY's IVCO value by one when the level byte is high, then set the next state. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_PreRVGA`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_PreRVGA.c) | `DRV_HDMI_EQScan_FSM_PHY_PreRVGA` | EQ scan step: choose the RVGA gain per channel, then the best RCT value. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_R_ChkError`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_R_ChkError.c) | `DRV_HDMI_EQScan_FSM_PHY_R_ChkError` | EQ scan step: collect SCDC error counts per channel and step the pre-AEQ index. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_R_Turning`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_R_Turning.c) | `DRV_HDMI_EQScan_FSM_PHY_R_Turning` | EQ scan step: print the channel CCT/RCT values and adjust channels with RCT below 8. | proven |
| [`DRV_HDMI_EQScan_FSM_PHY_RunAEQ`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_PHY_RunAEQ.c) | `DRV_HDMI_EQScan_FSM_PHY_RunAEQ` | EQ scan step: write the found RCT/CFT values; an AEQ scan also pulses the channels and restores them. | proven |
| [`DRV_HDMI_EQScan_FSM_Search_EQTable`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_Search_EQTable.c) | `DRV_HDMI_EQScan_FSM_Search_EQTable` | EQ scan step: step each unfinished channel through the EQ table. | proven |
| [`DRV_HDMI_EQScan_FSM_Search_Process`](../../src/leon2s/hdmi/DRV_HDMI_EQScan_FSM_Search_Process.c) | `DRV_HDMI_EQScan_FSM_Search_Process` | EQ scan step: apply the RVGA table entry or search for the fewest errors. | proven |
| [`DRV_HDMI_IF_Disconnect`](../../src/leon2s/hdmi/DRV_HDMI_IF_Disconnect.c) | `DRV_HDMI_IF_Disconnect` | Mark an HDMI receiver port disconnected and update the connect state. | proven |
| [`DRV_HDMI_IF_Enable_RxPort`](../../src/leon2s/hdmi/DRV_HDMI_IF_Enable_RxPort.c) | `DRV_HDMI_IF_Enable_RxPort` | Enable or disable an HDMI receiver port interface. | proven |
| [`DRV_HDMI_IF_Init`](../../src/leon2s/hdmi/DRV_HDMI_IF_Init.c) | `DRV_HDMI_IF_Init` | Initialise the HDMI receiver interface state once. | proven |
| [`DRV_HDMI_Init_Timer`](../../src/leon2s/hdmi/DRV_HDMI_Init_Timer.c) | `DRV_HDMI_Init_Timer` | Set up the HDMI receiver task timers of the given type. | proven |
| [`DRV_HDMI_InitialSettings`](../../src/leon2s/hdmi/DRV_HDMI_InitialSettings.c) | `DRV_HDMI_InitialSettings` | Apply the initial PHY settings and trim/calibration values of the four HDMI ports. | proven |
| [`DRV_HDMI_ModeDetect_FSM_Complete`](../../src/leon2s/hdmi/DRV_HDMI_ModeDetect_FSM_Complete.c) | `DRV_HDMI_ModeDetect_FSM_Complete` | Finish mode detection: read the mode, InfoFrames and clocks, then report sync stable. | proven |
| [`DRV_HDMI_ModeDetect_FSM_FRL_Chk`](../../src/leon2s/hdmi/DRV_HDMI_ModeDetect_FSM_FRL_Chk.c) | `DRV_HDMI_ModeDetect_FSM_FRL_Chk` | Run the FRL lock check state of the HDMI 2.1 mode detection. | proven |
| [`DRV_HDMI_ModeDetect_FSM_FRL_Init`](../../src/leon2s/hdmi/DRV_HDMI_ModeDetect_FSM_FRL_Init.c) | `DRV_HDMI_ModeDetect_FSM_FRL_Init` | Run the FRL start state of the HDMI 2.1 mode-detect state machine. | proven |
| [`DRV_HDMI_ModeDetect_FSM_FRL_Payload`](../../src/leon2s/hdmi/DRV_HDMI_ModeDetect_FSM_FRL_Payload.c) | `DRV_HDMI_ModeDetect_FSM_FRL_Payload` | Run the FRL payload check state of the HDMI 2.1 mode detection. | proven |
| [`DRV_HDMI_PHY_Clr_EQ_Err`](../../src/leon2s/hdmi/DRV_HDMI_PHY_Clr_EQ_Err.c) | `DRV_HDMI_PHY_Clr_EQ_Err` | Clear the equaliser error state of an HDMI port. | proven |
| [`DRV_HDMI_Set_AudStatus`](../../src/leon2s/hdmi/DRV_HDMI_Set_AudStatus.c) | `DRV_HDMI_Set_AudStatus` | Mark the audio of an HDMI receiver port stable or not and update its mute. | proven |
| [`DRV_HDMI_Setup_IntIRQ_Events`](../../src/leon2s/hdmi/DRV_HDMI_Setup_IntIRQ_Events.c) | `DRV_HDMI_Setup_IntIRQ_Events` | Switch on the interrupt events of an HDMI 2.1 receiver and load its record; acts only on enable = 1. | proven |
| [`DRV_HDMI_Start_Timer`](../../src/leon2s/hdmi/DRV_HDMI_Start_Timer.c) | `DRV_HDMI_Start_Timer` | Start the HDMI receiver task timers of the given type with their periods. | proven |
| [`DRV_HDMIRx_Phy_Init`](../../src/leon2s/hdmi/DRV_HDMIRx_Phy_Init.c) | `DRV_HDMIRx_Phy_Init` | Initialise the HDMI receiver PHYs and start the equaliser check task. | proven |
| [`FRL_PLL`](../../src/leon2s/hdmi/FRL_PLL.c) | `FRL_PLL` | Set the FRL PLL of an HDMI 2.1 receiver for a target clock value in MHz. | proven |
| [`FSM_MODE_DETECT_STANDBY`](../../src/leon2s/hdmi/FSM_MODE_DETECT_STANDBY.c) | `FSM_MODE_DETECT_STANDBY` | Compare the measured HDMI 2.1 timing with the last pass and count the passes that stay the same. | proven |
| [`H1_H2_VTH`](../../src/leon2s/hdmi/H1_H2_VTH.c) | `H1_H2_VTH` | Print the debug line '[HDMI21]: H1_H2_VTH' when HDMI 2.1 messages are switched on. | proven |
| [`HDMI20RX2PacketSwitch`](../../src/leon2s/hdmi/HDMI20RX2PacketSwitch.c) | `FUN_a00a8708` | Write one packet-forwarding selection of an HDMI 2.0 receiver. | proven |
| [`HDMI21RX2PacketSwitch`](../../src/leon2s/hdmi/HDMI21RX2PacketSwitch.c) | `FUN_a00a8508` | Write one packet-forwarding selection of an HDMI 2.1 receiver. | proven |
| [`hdmi_apply_color_depth`](../../src/leon2s/hdmi/hdmi_apply_color_depth.c) | `FUN_a008fb7c` | Apply the colour depth sent by an HDMI source and return its bits per colour. | derived |
| [`hdmi_calc_pixel_clock`](../../src/leon2s/hdmi/hdmi_calc_pixel_clock.c) | `FUN_a00910ec` | Compute the pixel clock of an HDMI 2.0 receiver from its measured clock. | derived |
| [`hdmi_capture_audio_infoframe`](../../src/leon2s/hdmi/hdmi_capture_audio_infoframe.c) | `FUN_a0090718` | Copy the received audio InfoFrame of an HDMI receiver. | proven |
| [`hdmi_capture_avi_infoframe`](../../src/leon2s/hdmi/hdmi_capture_avi_infoframe.c) | `FUN_a00907f0` | Copy the received AVI InfoFrame of an HDMI receiver. | proven |
| [`hdmi_capture_hdr_packet`](../../src/leon2s/hdmi/hdmi_capture_hdr_packet.c) | `FUN_a0090638` | Copy the received HDR (DRM) InfoFrame of an HDMI receiver. | proven |
| [`hdmi_capture_spd_packet`](../../src/leon2s/hdmi/hdmi_capture_spd_packet.c) | `FUN_a0090568` | Copy the received SPD InfoFrame of an HDMI receiver. | derived |
| [`hdmi_capture_vendor_packet`](../../src/leon2s/hdmi/hdmi_capture_vendor_packet.c) | `FUN_a0090498` | Copy the received vendor-specific packet of an HDMI receiver. | derived |
| [`hdmi_clear_descramble_override`](../../src/leon2s/hdmi/hdmi_clear_descramble_override.c) | `FUN_a007ebd0` | Clear bit 0 of receiver register 0x136; on an HDMI 2.1 PHY set bit 16 of block-1 word +0x34 instead. | descriptive |
| [`hdmi_clear_packet_seen_flags`](../../src/leon2s/hdmi/hdmi_clear_packet_seen_flags.c) | `FUN_a008faa0` | Clear the packet received flags of an HDMI receiver record. | derived |
| [`hdmi_clear_packet_status`](../../src/leon2s/hdmi/hdmi_clear_packet_status.c) | `FUN_a008fa30` | Clear the latched packet status registers of an HDMI receiver. | derived |
| [`hdmi_clear_packet_update_flags`](../../src/leon2s/hdmi/hdmi_clear_packet_update_flags.c) | `FUN_a008fa78` | Clear the packet update flags of an HDMI receiver record. | derived |
| [`hdmi_clear_port1_double_flag`](../../src/leon2s/hdmi/hdmi_clear_port1_double_flag.c) | `FUN_a0090374` | Clear the horizontal doubling flag of HDMI receiver 1. | descriptive |
| [`hdmi_clear_scdc_config`](../../src/leon2s/hdmi/hdmi_clear_scdc_config.c) | `FUN_a008ff58` | Clear the SCDC configuration mirror registers of an HDMI receiver. | derived |
| [`hdmi_clear_shared_port_bit`](../../src/leon2s/hdmi/hdmi_clear_shared_port_bit.c) | `FUN_a00914fc` | Clear the bit of an HDMI port in the shared status register 0xCF03C890. | descriptive |
| [`hdmi_create_eq_detect_task`](../../src/leon2s/hdmi/hdmi_create_eq_detect_task.c) | `FUN_a0073578` | Register the per-port HDMI equaliser check as a timer task. | derived |
| [`hdmi_detect_vrr_signalling`](../../src/leon2s/hdmi/hdmi_detect_vrr_signalling.c) | `FUN_a008f79c` | Return the variable refresh rate flags of an HDMI receiver, read from two received packets. | derived |
| [`hdmi_eq_check_clock`](../../src/leon2s/hdmi/hdmi_eq_check_clock.c) | `EQ_handler` | Restart the equaliser of a port when its clock became unstable. | proven |
| [`hdmi_eq_check_clock_detect`](../../src/leon2s/hdmi/hdmi_eq_check_clock_detect.c) | `EQ_handler_3` | Restart the EQ flow of a port when its clock-detect state changes. | proven |
| [`hdmi_eq_check_error_regs`](../../src/leon2s/hdmi/hdmi_eq_check_error_regs.c) | `FUN_a007d140` | Read the channel error registers up to three times and report a bad value. | descriptive |
| [`hdmi_eq_clear_scan_records`](../../src/leon2s/hdmi/hdmi_eq_clear_scan_records.c) | `FUN_a0073500` | Clear the EQ scan records of the four HDMI PHYs. | derived |
| [`hdmi_eq_find_best_rct`](../../src/leon2s/hdmi/hdmi_eq_find_best_rct.c) | `RCT_Value` | Choose the RCT equaliser value of one channel from the error counts of the candidates. | proven |
| [`hdmi_eq_get_clock_ratio_mode`](../../src/leon2s/hdmi/hdmi_eq_get_clock_ratio_mode.c) | `FUN_a007b2a0` | Return the clock-ratio mode the EQ steps should use for a port. | descriptive |
| [`hdmi_eq_get_scramble_mode`](../../src/leon2s/hdmi/hdmi_eq_get_scramble_mode.c) | `FUN_a007d054` | Return the scrambling mode the EQ steps should use for a port. | descriptive |
| [`hdmi_eq_monitor_errors`](../../src/leon2s/hdmi/hdmi_eq_monitor_errors.c) | `FUN_a0079054` | Check the channel error counters and restart or confirm the EQ values. | derived |
| [`hdmi_eq_print_channel_values`](../../src/leon2s/hdmi/hdmi_eq_print_channel_values.c) | `EQ_handler_2` | Print the RVGA, RCT and CCT values of the three channels. | proven |
| [`hdmi_eq_reset_port_record`](../../src/leon2s/hdmi/hdmi_eq_reset_port_record.c) | `bch_en_flag` | Reset the EQ scan record of a port; mode 0 also toggles the BCH enable flag. | derived |
| [`hdmi_eq_run_scan_fsm`](../../src/leon2s/hdmi/hdmi_eq_run_scan_fsm.c) | `FSM_EQSCAN_DONE` | Run the EQ scan state machine of a port until a step waits, then report the result. | proven |
| [`hdmi_get_avi_color_space`](../../src/leon2s/hdmi/hdmi_get_avi_color_space.c) | `FUN_a008fb5c` | Return the colour space field of the received AVI InfoFrame. | proven |
| [`hdmi_get_bt2020_colorimetry`](../../src/leon2s/hdmi/hdmi_get_bt2020_colorimetry.c) | `FUN_a008ff08` | Return 1 or 2 when the AVI InfoFrame reports a BT.2020 colorimetry, else 0. | derived |
| [`hdmi_get_color_depth`](../../src/leon2s/hdmi/hdmi_get_color_depth.c) | `FUN_a0090dec` | Return the bits per colour (8, 10, 12, 16) of an HDMI receiver. | derived |
| `hdmi_get_color_depth_jump_table` | `switchdataD_a0090dcc` | Jump table 1 of the switch statements in hdmi_get_color_depth. | proven |
| [`hdmi_get_color_format_code`](../../src/leon2s/hdmi/hdmi_get_color_format_code.c) | `FUN_a00901a0` | Return a code for the colour format and colorimetry an HDMI source sends. | derived |
| [`hdmi_get_hdr_packet_flag`](../../src/leon2s/hdmi/hdmi_get_hdr_packet_flag.c) | `FUN_a0090f0c` | Return the HDR InfoFrame update flag of an HDMI receiver record. | derived |
| [`hdmi_get_pixel_repetition`](../../src/leon2s/hdmi/hdmi_get_pixel_repetition.c) | `FUN_a0090d7c` | Return the pixel repetition factor (1, 2 or 4) from the AVI InfoFrame. | derived |
| [`hdmi_get_port1_double_flag`](../../src/leon2s/hdmi/hdmi_get_port1_double_flag.c) | `FUN_a008fff0` | Return the horizontal doubling flag of HDMI receiver 1. | descriptive |
| [`hdmi_get_port_mode_byte`](../../src/leon2s/hdmi/hdmi_get_port_mode_byte.c) | `FUN_a007517c` | Return the per-port mode byte of an HDMI receiver. | descriptive |
| [`hdmi_get_reg6_bit0`](../../src/leon2s/hdmi/hdmi_get_reg6_bit0.c) | `FUN_a00910d0` | Return bit 0 of HDMI receiver register 6. | descriptive |
| [`hdmi_get_restart_hint`](../../src/leon2s/hdmi/hdmi_get_restart_hint.c) | `FUN_a008f9e4` | Return the status latch flag the receiver poll set this pass. | derived |
| [`hdmi_get_saved_color_depth`](../../src/leon2s/hdmi/hdmi_get_saved_color_depth.c) | `FUN_a0090f44` | Return the saved bits per colour of an HDMI receiver. | derived |
| [`hdmi_get_saved_hactive`](../../src/leon2s/hdmi/hdmi_get_saved_hactive.c) | `FUN_a0090fec` | Return the saved active width of an HDMI receiver. | derived |
| [`hdmi_get_saved_hback_porch`](../../src/leon2s/hdmi/hdmi_get_saved_hback_porch.c) | `FUN_a0091094` | Return the saved horizontal back porch of an HDMI receiver. | derived |
| [`hdmi_get_saved_hsync_width`](../../src/leon2s/hdmi/hdmi_get_saved_hsync_width.c) | `FUN_a0091008` | Return the saved horizontal sync width of an HDMI receiver. | derived |
| [`hdmi_get_saved_htotal`](../../src/leon2s/hdmi/hdmi_get_saved_htotal.c) | `FUN_a0090fd0` | Return the saved total line length of an HDMI receiver. | derived |
| [`hdmi_get_saved_pixel_clock`](../../src/leon2s/hdmi/hdmi_get_saved_pixel_clock.c) | `FUN_a0090f98` | Return the saved pixel clock of an HDMI receiver. | derived |
| [`hdmi_get_saved_reg30_bit4`](../../src/leon2s/hdmi/hdmi_get_saved_reg30_bit4.c) | `FUN_a0090f28` | Return the saved register 0x30 bit 4 of an HDMI receiver. | descriptive |
| [`hdmi_get_saved_reg55_bit0`](../../src/leon2s/hdmi/hdmi_get_saved_reg55_bit0.c) | `FUN_a0090f60` | Return the saved register 0x55 bit 0 of an HDMI receiver. | descriptive |
| [`hdmi_get_saved_reg55_bit1`](../../src/leon2s/hdmi/hdmi_get_saved_reg55_bit1.c) | `FUN_a0090f7c` | Return the saved register 0x55 bit 1 of an HDMI receiver. | descriptive |
| [`hdmi_get_saved_tmds_clock`](../../src/leon2s/hdmi/hdmi_get_saved_tmds_clock.c) | `FUN_a0090fb4` | Return the saved TMDS clock of an HDMI receiver. | derived |
| [`hdmi_get_saved_vactive`](../../src/leon2s/hdmi/hdmi_get_saved_vactive.c) | `FUN_a0091040` | Return the saved active height of an HDMI receiver. | derived |
| [`hdmi_get_saved_vback_porch`](../../src/leon2s/hdmi/hdmi_get_saved_vback_porch.c) | `FUN_a009105c` | Return the saved vertical back porch of an HDMI receiver. | descriptive |
| [`hdmi_get_saved_vsync_width`](../../src/leon2s/hdmi/hdmi_get_saved_vsync_width.c) | `FUN_a0091078` | Return the saved vertical sync width of an HDMI receiver. | derived |
| [`hdmi_get_saved_vtotal`](../../src/leon2s/hdmi/hdmi_get_saved_vtotal.c) | `FUN_a0091024` | Return the saved total frame height of an HDMI receiver. | derived |
| [`hdmi_get_scramble_lock`](../../src/leon2s/hdmi/hdmi_get_scramble_lock.c) | `FUN_a007cfec` | Return the scrambler lock status bit of a port. | descriptive |
| [`hdmi_get_scramble_status`](../../src/leon2s/hdmi/hdmi_get_scramble_status.c) | `FUN_a007ae94` | Return a scrambler status bit of a port. | descriptive |
| [`hdmi_get_tmds_clock`](../../src/leon2s/hdmi/hdmi_get_tmds_clock.c) | `FUN_a00911bc` | Return the TMDS clock of an HDMI receiver, times 4 in 1/40 mode. | derived |
| [`hdmi_init_packet_switch`](../../src/leon2s/hdmi/hdmi_init_packet_switch.c) | `FUN_a00a8844` | Load the default packet-forwarding selections of an HDMI 2.0 receiver. | derived |
| [`hdmi_init_receivers`](../../src/leon2s/hdmi/hdmi_init_receivers.c) | `FUN_a008f54c` | Load the start-up settings of both HDMI 2.0 receivers. | derived |
| [`hdmi_is_deep_color`](../../src/leon2s/hdmi/hdmi_is_deep_color.c) | `FUN_a008fe10` | Return 1 when the colour depth code of an HDMI receiver (register 0x45 bits 0..2) is not 4. | derived |
| [`hdmi_is_hdmi21_phy`](../../src/leon2s/hdmi/hdmi_is_hdmi21_phy.c) | `FUN_a0073520` | Return whether a PHY index belongs to an HDMI 2.1 receiver (2 or 3). | derived |
| [`hdmi_is_second_port`](../../src/leon2s/hdmi/hdmi_is_second_port.c) | `FUN_a008f4d0` | Return 1 for HDMI 2.0 receiver 1, 0 otherwise. | descriptive |
| [`hdmi_is_ycbcr_input`](../../src/leon2s/hdmi/hdmi_is_ycbcr_input.c) | `FUN_a008fea8` | Return whether an HDMI source sends a YCbCr picture with an AVI InfoFrame. | derived |
| [`hdmi_phy_clear_ctrl_bits`](../../src/leon2s/hdmi/hdmi_phy_clear_ctrl_bits.c) | `FUN_a0073704` | Clear bits 0 and 1 of the PHY control register 0x3600. | descriptive |
| [`hdmi_phy_clock_changed`](../../src/leon2s/hdmi/hdmi_phy_clock_changed.c) | `FUN_a0074fc4` | Return whether the measured clock differs from the saved one by more than 2. | derived |
| [`hdmi_phy_clock_in_range`](../../src/leon2s/hdmi/hdmi_phy_clock_in_range.c) | `FUN_a0078fe8` | Return whether a clock is detected and its count is within the valid range. | derived |
| [`hdmi_phy_is_eq_done`](../../src/leon2s/hdmi/hdmi_phy_is_eq_done.c) | `FUN_a0074c48` | Return whether the equaliser of a PHY has finished (link table flag). | derived |
| [`hdmi_phy_load_aeq_entry`](../../src/leon2s/hdmi/hdmi_phy_load_aeq_entry.c) | `FUN_a0074ef4` | Write one equaliser table entry to the register of one channel of a PHY. | derived |
| [`hdmi_phy_map_reg`](../../src/leon2s/hdmi/hdmi_phy_map_reg.c) | `FUN_a00a7368` | Select the page of an HDMI PHY register and return its address. | proven |
| [`hdmi_phy_power_off_first_step`](../../src/leon2s/hdmi/hdmi_phy_power_off_first_step.c) | `FUN_a0073680` | Switch the six PHY control bits used at the start of power-off. | descriptive |
| [`hdmi_phy_power_on_final_step`](../../src/leon2s/hdmi/hdmi_phy_power_on_final_step.c) | `FUN_a0073638` | Clear the three control bits that finish the PHY power-on sequence. | descriptive |
| [`hdmi_phy_pulse_channel_regs`](../../src/leon2s/hdmi/hdmi_phy_pulse_channel_regs.c) | `FUN_a00787f4` | Pulse the two control registers of each of the three channels. | descriptive |
| [`hdmi_phy_read_clock_count`](../../src/leon2s/hdmi/hdmi_phy_read_clock_count.c) | `FUN_a0074f60` | Measure the incoming clock of a PHY and return the 13-bit count. | derived |
| [`hdmi_phy_read_reg`](../../src/leon2s/hdmi/hdmi_phy_read_reg.c) | `FUN_a00a7314` | Read a paged register of an HDMI receiver PHY. | proven |
| [`hdmi_phy_request_eq_reset`](../../src/leon2s/hdmi/hdmi_phy_request_eq_reset.c) | `FUN_a00734d8` | Set the EQ reset request byte (+2) of the PHY record of a port. | proven |
| [`hdmi_phy_reset_all_lane_regs`](../../src/leon2s/hdmi/hdmi_phy_reset_all_lane_regs.c) | `FUN_a007ac7c` | Reset the TMDS channel, HDMI 2.1 lane and lane EQ registers of a port. | descriptive |
| [`hdmi_phy_reset_error_counters`](../../src/leon2s/hdmi/hdmi_phy_reset_error_counters.c) | `FUN_a007f8a4` | Clear bit 7 and set bit 6 of PHY register 0x1EA0 and pulse bit 18 of register 0x1F08. | descriptive |
| [`hdmi_phy_reset_tmds_channel_regs`](../../src/leon2s/hdmi/hdmi_phy_reset_tmds_channel_regs.c) | `FUN_a007a708` | Reset the control registers of the three TMDS channels. | descriptive |
| [`hdmi_phy_restore_power`](../../src/leon2s/hdmi/hdmi_phy_restore_power.c) | `FUN_a0073be8` | Re-run the PHY power-on sequence when bit 14 of PHY register 0x1F0C reads 0. | descriptive |
| [`hdmi_phy_run_ctrl_sequence`](../../src/leon2s/hdmi/hdmi_phy_run_ctrl_sequence.c) | `FUN_a0073738` | Run the timed bit sequence on PHY control register 0x361C. | descriptive |
| [`hdmi_phy_set_input_enable`](../../src/leon2s/hdmi/hdmi_phy_set_input_enable.c) | `FUN_a007ae30` | Set or clear the input enable bit 7 of the PHY (and its HDMI 2.1 twin). | descriptive |
| [`hdmi_phy_set_power`](../../src/leon2s/hdmi/hdmi_phy_set_power.c) | `FUN_a007381c` | Run the PHY register power-on or power-off sequence of an HDMI port. | derived |
| [`hdmi_phy_set_power_flag`](../../src/leon2s/hdmi/hdmi_phy_set_power_flag.c) | `FUN_a0073c24` | Record the power state of a PHY in its link table entry. | derived |
| [`hdmi_phy_set_rate_fields`](../../src/leon2s/hdmi/hdmi_phy_set_rate_fields.c) | `FUN_a0075360` | Set the bit fields of PHY register block 0x3630 for the port's link rate. | descriptive |
| [`hdmi_phy_switch_channel_bit21`](../../src/leon2s/hdmi/hdmi_phy_switch_channel_bit21.c) | `FUN_a0079778` | Set or clear bit 21 of the channel registers in power-up or power-down order. | descriptive |
| [`hdmi_phy_test_bit`](../../src/leon2s/hdmi/hdmi_phy_test_bit.c) | `FUN_a00a7468` | Return one bit of a paged HDMI PHY register. | proven |
| [`hdmi_phy_update_reg`](../../src/leon2s/hdmi/hdmi_phy_update_reg.c) | `FUN_a00a7488` | Read, mask and rewrite a paged HDMI PHY register. | proven |
| [`hdmi_phy_write_bit`](../../src/leon2s/hdmi/hdmi_phy_write_bit.c) | `FUN_a00a7424` | Set or clear one bit of a paged HDMI PHY register. | proven |
| [`hdmi_phy_write_reg`](../../src/leon2s/hdmi/hdmi_phy_write_reg.c) | `FUN_a00a72c0` | Write a paged register of an HDMI receiver PHY. | proven |
| [`hdmi_pll_reg_write8`](../../src/leon2s/hdmi/hdmi_pll_reg_write8.c) | `FUN_a00a832c` | Write a byte register of a pixel PLL unit. | derived |
| [`hdmi_poll_rx_status`](../../src/leon2s/hdmi/hdmi_poll_rx_status.c) | `FUN_a00908d0` | Poll the packet and status bits of a running HDMI 2.0 receiver. | derived |
| [`hdmi_port_reg_read8`](../../src/leon2s/hdmi/hdmi_port_reg_read8.c) | `FUN_a00a7e98` | Read a byte register of any HDMI receiver (ports 0..3). | proven |
| [`hdmi_port_reg_update_bits`](../../src/leon2s/hdmi/hdmi_port_reg_update_bits.c) | `FUN_a00a7e14` | Set or clear masked bits of a byte register of any HDMI receiver (ports 0..3). | proven |
| [`hdmi_port_reg_write8`](../../src/leon2s/hdmi/hdmi_port_reg_write8.c) | `FUN_a00a7dd0` | Write a byte register of any HDMI receiver (ports 0..3, 2.0 and 2.1). | proven |
| [`hdmi_pulse_reg133_bit7`](../../src/leon2s/hdmi/hdmi_pulse_reg133_bit7.c) | `FUN_a008fa00` | Pulse bit 7 of HDMI receiver register 0x133. | descriptive |
| [`hdmi_read_hactive`](../../src/leon2s/hdmi/hdmi_read_hactive.c) | `FUN_a0090010` | Return the active width of an HDMI receiver, doubled for 4:2:0. | derived |
| [`hdmi_read_hfront_porch`](../../src/leon2s/hdmi/hdmi_read_hfront_porch.c) | `FUN_a0090120` | Return the horizontal front porch measured by an HDMI receiver. | descriptive |
| [`hdmi_read_hsync_width`](../../src/leon2s/hdmi/hdmi_read_hsync_width.c) | `FUN_a0090140` | Return the horizontal sync width measured by an HDMI receiver. | derived |
| [`hdmi_read_htotal`](../../src/leon2s/hdmi/hdmi_read_htotal.c) | `FUN_a0090098` | Return the total line length of an HDMI receiver, doubled for 4:2:0. | derived |
| [`hdmi_read_infoframe`](../../src/leon2s/hdmi/hdmi_read_infoframe.c) | `FUN_a0090380` | Copy 28 bytes of a received AVI, SPD, audio or HDR InfoFrame. | proven |
| [`hdmi_read_vactive`](../../src/leon2s/hdmi/hdmi_read_vactive.c) | `FUN_a0090078` | Return the active height of an HDMI receiver. | derived |
| [`hdmi_read_vback_porch`](../../src/leon2s/hdmi/hdmi_read_vback_porch.c) | `FUN_a0090160` | Return the vertical back porch measured by an HDMI receiver. | descriptive |
| [`hdmi_read_vsync_width`](../../src/leon2s/hdmi/hdmi_read_vsync_width.c) | `FUN_a0090180` | Return the vertical sync width measured by an HDMI receiver. | derived |
| [`hdmi_read_vtotal`](../../src/leon2s/hdmi/hdmi_read_vtotal.c) | `FUN_a0090100` | Return the total frame height of an HDMI receiver. | derived |
| [`hdmi_reg_read8`](../../src/leon2s/hdmi/hdmi_reg_read8.c) | `FUN_a00a657c` | Read a byte register of an HDMI 2.0 receiver. | proven |
| [`hdmi_reg_read16`](../../src/leon2s/hdmi/hdmi_reg_read16.c) | `FUN_a00a68d0` | Read a 16-bit value from two byte registers of an HDMI 2.0 receiver. | proven |
| [`hdmi_reg_read16_stable`](../../src/leon2s/hdmi/hdmi_reg_read16_stable.c) | `FUN_a00a6938` | Read a 16-bit HDMI 2.0 receiver value until two reads agree. | proven |
| [`hdmi_reg_read24`](../../src/leon2s/hdmi/hdmi_reg_read24.c) | `FUN_a00a6668` | Read a 24-bit value from three byte registers of an HDMI 2.0 receiver. | proven |
| [`hdmi_reg_update_bits`](../../src/leon2s/hdmi/hdmi_reg_update_bits.c) | `FUN_a00a67b8` | Set or clear masked bits of a byte register of one or both HDMI 2.0 receivers. | proven |
| [`hdmi_reg_write8`](../../src/leon2s/hdmi/hdmi_reg_write8.c) | `FUN_a00a65c4` | Write a byte register of one or both HDMI 2.0 receivers. | proven |
| [`hdmi_reg_write16`](../../src/leon2s/hdmi/hdmi_reg_write16.c) | `FUN_a00a66dc` | Write a 16-bit value to two byte registers of one or both HDMI 2.0 receivers. | proven |
| [`hdmi_reset_reg340_block`](../../src/leon2s/hdmi/hdmi_reset_reg340_block.c) | `FUN_a008f4ec` | Reset HDMI receiver registers 0x340..0x343 to their start values. | descriptive |
| [`hdmi_rx21_ack_event`](../../src/leon2s/hdmi/hdmi_rx21_ack_event.c) | `FUN_a00a07b8` | Acknowledge (clear) one interrupt event of an HDMI 2.1 receiver. | derived |
| `hdmi_rx21_ack_event_jump_table` | `switchdataD_a00a0798` | Jump table 1 of the switch statements in hdmi_rx21_ack_event. | proven |
| [`hdmi_rx21_apply_lane_eq`](../../src/leon2s/hdmi/hdmi_rx21_apply_lane_eq.c) | `FUN_a007a9c0` | Write the chosen RCT/CFT values to the selected lanes and restart them. | derived |
| [`hdmi_rx21_audio_bit17_is_clear`](../../src/leon2s/hdmi/hdmi_rx21_audio_bit17_is_clear.c) | `FUN_a009c3f0` | Read bit 17 of the audio status register 50 times; return 1 when the last reading is clear. | descriptive |
| [`hdmi_rx21_audio_status_bit1`](../../src/leon2s/hdmi/hdmi_rx21_audio_status_bit1.c) | `FUN_a009c434` | Return bit 1 of the audio status register of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_calc_frame_rate`](../../src/leon2s/hdmi/hdmi_rx21_calc_frame_rate.c) | `FUN_a00a2cf4` | Compute the line rate and frame rate of an HDMI 2.1 input from its PHY clock. | derived |
| [`hdmi_rx21_calc_reg50_ratio`](../../src/leon2s/hdmi/hdmi_rx21_calc_reg50_ratio.c) | `FUN_a009dfa8` | Return the ratio of timing registers 0x50 and 0x54 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_calc_tmds_clock`](../../src/leon2s/hdmi/hdmi_rx21_calc_tmds_clock.c) | `FUN_a00a20c4` | Compute the TMDS clock of an HDMI 2.1 input from pixel clock and colour depth. | proven |
| [`hdmi_rx21_check_sr_detect`](../../src/leon2s/hdmi/hdmi_rx21_check_sr_detect.c) | `SR_detect_fail_ch` | Check each lane of an HDMI 2.1 receiver for scrambler-reset detection and return the failing lanes. | derived |
| [`hdmi_rx21_clear_all_events`](../../src/leon2s/hdmi/hdmi_rx21_clear_all_events.c) | `FUN_a00a0bfc` | Clear every pending interrupt status bit of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_clear_detect_flags`](../../src/leon2s/hdmi/hdmi_rx21_clear_detect_flags.c) | `FUN_a0096aa4` | Clear seven detection flags of an HDMI 2.1 receiver record. | descriptive |
| [`hdmi_rx21_clear_event_word`](../../src/leon2s/hdmi/hdmi_rx21_clear_event_word.c) | `FUN_a00a10ec` | Clear the per-port event word used by the HDMI 2.1 sync event handler. | descriptive |
| [`hdmi_rx21_clear_lane_bit7_all`](../../src/leon2s/hdmi/hdmi_rx21_clear_lane_bit7_all.c) | `FUN_a0079aac` | Clear bit 7 and set the control field on all four lanes. | descriptive |
| [`hdmi_rx21_clear_lane_bit7_masked`](../../src/leon2s/hdmi/hdmi_rx21_clear_lane_bit7_masked.c) | `FUN_a0079a20` | Clear bit 7 and set the control field of the lanes selected in the mask. | descriptive |
| [`hdmi_rx21_clear_lane_ctrl_all`](../../src/leon2s/hdmi/hdmi_rx21_clear_lane_ctrl_all.c) | `FUN_a00799b8` | Clear bit 7 of the four HDMI 2.1 lane control registers. | descriptive |
| [`hdmi_rx21_clear_mask_bits`](../../src/leon2s/hdmi/hdmi_rx21_clear_mask_bits.c) | `FUN_a00a2564` | Clear the control bits selected by a mask on both HDMI 2.1 receivers (newer chips). | descriptive |
| [`hdmi_rx21_clear_mode_change_signal`](../../src/leon2s/hdmi/hdmi_rx21_clear_mode_change_signal.c) | `FUN_a00a2a04` | Clear the mode-change signal bit of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_clear_mode_status`](../../src/leon2s/hdmi/hdmi_rx21_clear_mode_status.c) | `FUN_a009c87c` | Clear the detected-mode flags of an HDMI 2.1 receiver and mark audio not stable. | derived |
| [`hdmi_rx21_clear_port_ctrl_bits`](../../src/leon2s/hdmi/hdmi_rx21_clear_port_ctrl_bits.c) | `FUN_a009f66c` | Clear a fixed set of control bits of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_clear_reg1f0c_bit18`](../../src/leon2s/hdmi/hdmi_rx21_clear_reg1f0c_bit18.c) | `FUN_a00a1710` | Clear bit 18 of PHY register 0x1F0C. | descriptive |
| [`hdmi_rx21_clear_reg8_bit2`](../../src/leon2s/hdmi/hdmi_rx21_clear_reg8_bit2.c) | `FUN_a00a2bec` | Clear bit 2 of control register 8 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_clear_status_flags`](../../src/leon2s/hdmi/hdmi_rx21_clear_status_flags.c) | `FUN_a0096ad8` | Clear six status flags of an HDMI 2.1 receiver record. | descriptive |
| [`hdmi_rx21_config_bch`](../../src/leon2s/hdmi/hdmi_rx21_config_bch.c) | `FUN_a007f634` | Configure BCH error correction for an HDMI 2.1 PHY. | derived |
| [`hdmi_rx21_copy_link_timing`](../../src/leon2s/hdmi/hdmi_rx21_copy_link_timing.c) | `FUN_a006e2c4` | Copy and print the link timing of an HDMI 2.1 port into its port record. | proven |
| [`hdmi_rx21_detect_timing_change`](../../src/leon2s/hdmi/hdmi_rx21_detect_timing_change.c) | `H_ACTIVE_DIFF` | Compare the HDMI 2.1 input timing with the stored one and report a mode change. | proven |
| [`hdmi_rx21_detect_vrr_signalling`](../../src/leon2s/hdmi/hdmi_rx21_detect_vrr_signalling.c) | `FUN_a00974ec` | Store the variable refresh rate flags of an HDMI 2.1 receiver. | proven |
| [`hdmi_rx21_empty_callback`](../../src/leon2s/hdmi/hdmi_rx21_empty_callback.c) | `FUN_a00a1574` | Do nothing (empty event callback). | descriptive |
| [`hdmi_rx21_enable_event`](../../src/leon2s/hdmi/hdmi_rx21_enable_event.c) | `FUN_a00a0930` | Acknowledge and enable or disable one interrupt event of an HDMI 2.1 receiver. | derived |
| `hdmi_rx21_enable_event_jump_table` | `switchdataD_a00a0910` | Jump table 1 of the switch statements in hdmi_rx21_enable_event. | proven |
| [`hdmi_rx21_enable_sync_events`](../../src/leon2s/hdmi/hdmi_rx21_enable_sync_events.c) | `FUN_a00a0b10` | Enable or disable the sync and mode-change events of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_flag_frl_rate_change`](../../src/leon2s/hdmi/hdmi_rx21_flag_frl_rate_change.c) | `FUN_a009f5c8` | Flag an HDMI 2.1 receiver whose FRL rate changed after link training. | derived |
| [`hdmi_rx21_force_mode_detect_standby`](../../src/leon2s/hdmi/hdmi_rx21_force_mode_detect_standby.c) | `MODEDET_handler` | Send the mode detection of an HDMI 2.1 receiver back to state 0 (wait for EQ) if its EQ is not done. | proven |
| [`hdmi_rx21_frl_rate_is_zero`](../../src/leon2s/hdmi/hdmi_rx21_frl_rate_is_zero.c) | `FUN_a0098300` | Return whether the source requested no FRL rate (TMDS) on an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_get_audio_freq_code`](../../src/leon2s/hdmi/hdmi_rx21_get_audio_freq_code.c) | `FUN_a009c4a4` | Return the audio sample-rate code reported by an HDMI 2.1 receiver. | derived |
| `hdmi_rx21_get_audio_freq_code_jump_table` | `switchdataD_a009c468` | Jump table 1 of the switch statements in hdmi_rx21_get_audio_freq_code. | proven |
| [`hdmi_rx21_get_color_depth`](../../src/leon2s/hdmi/hdmi_rx21_get_color_depth.c) | `FUN_a00a26fc` | Return the colour depth (bits per colour) of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_get_colorimetry_code`](../../src/leon2s/hdmi/hdmi_rx21_get_colorimetry_code.c) | `FUN_a00a1e28` | Return a colour-space code from the colour format and colorimetry of an HDMI 2.1 input. | derived |
| [`hdmi_rx21_get_cvtem_code`](../../src/leon2s/hdmi/hdmi_rx21_get_cvtem_code.c) | `FUN_a00a26a8` | Return the first CVTEM field of an HDMI 2.1 input. | descriptive |
| [`hdmi_rx21_get_cvtem_flag`](../../src/leon2s/hdmi/hdmi_rx21_get_cvtem_flag.c) | `FUN_a00a26c4` | Return the second CVTEM field of an HDMI 2.1 input. | descriptive |
| [`hdmi_rx21_get_hactive`](../../src/leon2s/hdmi/hdmi_rx21_get_hactive.c) | `FUN_a00a27a4` | Return the horizontal active width of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_get_hback_porch`](../../src/leon2s/hdmi/hdmi_rx21_get_hback_porch.c) | `FUN_a00a2868` | Return the horizontal back porch of an HDMI 2.1 input. | derived |
| [`hdmi_rx21_get_hdmi_mode`](../../src/leon2s/hdmi/hdmi_rx21_get_hdmi_mode.c) | `FUN_a00a26e0` | Return the HDMI (not DVI) mode flag of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_get_hdmi_mode_copy`](../../src/leon2s/hdmi/hdmi_rx21_get_hdmi_mode_copy.c) | `FUN_a00a2994` | Return the HDMI (not DVI) mode flag of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_get_hdr_packet_flag`](../../src/leon2s/hdmi/hdmi_rx21_get_hdr_packet_flag.c) | `FUN_a00a268c` | Return the HDR InfoFrame received flag of an HDMI 2.1 input. | derived |
| [`hdmi_rx21_get_hfront_porch`](../../src/leon2s/hdmi/hdmi_rx21_get_hfront_porch.c) | `FUN_a00a27dc` | Return the horizontal front porch of an HDMI 2.1 input. | derived |
| [`hdmi_rx21_get_hsync_width`](../../src/leon2s/hdmi/hdmi_rx21_get_hsync_width.c) | `FUN_a00a27c0` | Return the horizontal sync width of an HDMI 2.1 input. | derived |
| [`hdmi_rx21_get_htotal`](../../src/leon2s/hdmi/hdmi_rx21_get_htotal.c) | `FUN_a00a2788` | Return the horizontal total of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_get_link_rate_code`](../../src/leon2s/hdmi/hdmi_rx21_get_link_rate_code.c) | `FUN_a00a20a8` | Return the link rate code of an HDMI 2.1 receiver (0 TMDS, 1..6 FRL rates). | derived |
| [`hdmi_rx21_get_mode_byte_2f`](../../src/leon2s/hdmi/hdmi_rx21_get_mode_byte_2f.c) | `FUN_a00a2718` | Return the mode info byte +0x2F of an HDMI 2.1 input. | descriptive |
| [`hdmi_rx21_get_mode_byte_30`](../../src/leon2s/hdmi/hdmi_rx21_get_mode_byte_30.c) | `FUN_a00a2734` | Return the mode info byte +0x30 of an HDMI 2.1 input. | descriptive |
| [`hdmi_rx21_get_mode_word_34`](../../src/leon2s/hdmi/hdmi_rx21_get_mode_word_34.c) | `FUN_a00a276c` | Return the mode info halfword +0x34 of an HDMI 2.1 input. | descriptive |
| [`hdmi_rx21_get_phy_index`](../../src/leon2s/hdmi/hdmi_rx21_get_phy_index.c) | `FUN_a00961e8` | Return the PHY number (2 or 3) of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_get_pixel_clock`](../../src/leon2s/hdmi/hdmi_rx21_get_pixel_clock.c) | `FUN_a00a2750` | Return the pixel clock of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_get_status_byte7`](../../src/leon2s/hdmi/hdmi_rx21_get_status_byte7.c) | `FUN_a00a2978` | Return status byte +7 of the record of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_get_two_port_mode`](../../src/leon2s/hdmi/hdmi_rx21_get_two_port_mode.c) | `FUN_a00a29d8` | Return the two-port mode byte of an HDMI 2.1 receiver (0 or 1). | proven |
| [`hdmi_rx21_get_vactive`](../../src/leon2s/hdmi/hdmi_rx21_get_vactive.c) | `FUN_a00a2814` | Return the vertical active height of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_get_vback_porch`](../../src/leon2s/hdmi/hdmi_rx21_get_vback_porch.c) | `FUN_a00a284c` | Return the vertical back porch of an HDMI 2.1 input. | derived |
| [`hdmi_rx21_get_vsync_width`](../../src/leon2s/hdmi/hdmi_rx21_get_vsync_width.c) | `FUN_a00a2830` | Return the vertical sync width of an HDMI 2.1 input. | derived |
| [`hdmi_rx21_get_vtotal`](../../src/leon2s/hdmi/hdmi_rx21_get_vtotal.c) | `FUN_a00a27f8` | Return the vertical total of an HDMI 2.1 input. | proven |
| [`hdmi_rx21_has_cvtem`](../../src/leon2s/hdmi/hdmi_rx21_has_cvtem.c) | `FUN_a00a03c8` | Return whether a valid compressed-video (CVTEM) packet is present on an HDMI 2.1 input. | derived |
| [`hdmi_rx21_init_audio_regs`](../../src/leon2s/hdmi/hdmi_rx21_init_audio_regs.c) | `FUN_a00a2ecc` | Set the start-up values of the audio block registers of both HDMI 2.1 receivers. | descriptive |
| [`hdmi_rx21_init_clear_reg2d_fields`](../../src/leon2s/hdmi/hdmi_rx21_init_clear_reg2d_fields.c) | `FUN_a00a2b98` | Clear fields of control registers 0x2D and 0x2E of both HDMI 2.1 receivers. | descriptive |
| [`hdmi_rx21_init_ctrl_bits_20_21`](../../src/leon2s/hdmi/hdmi_rx21_init_ctrl_bits_20_21.c) | `FUN_a00a2a28` | Set control bits 20 and 21 of both HDMI 2.1 receivers at start-up. | descriptive |
| [`hdmi_rx21_init_packet_switch`](../../src/leon2s/hdmi/hdmi_rx21_init_packet_switch.c) | `FUN_a00a8694` | Load the default packet-forwarding selections of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_init_port`](../../src/leon2s/hdmi/hdmi_rx21_init_port.c) | `INIT_handler` | Set the start-up registers and records of one HDMI 2.1 receiver port. | derived |
| [`hdmi_rx21_init_reg1_byte1`](../../src/leon2s/hdmi/hdmi_rx21_init_reg1_byte1.c) | `FUN_a00a2a80` | Set byte 1 of register 1 of both HDMI 2.1 receivers for a start-up mode. | descriptive |
| [`hdmi_rx21_init_reg2d_bits`](../../src/leon2s/hdmi/hdmi_rx21_init_reg2d_bits.c) | `FUN_a00a2b08` | Set the start-up bits of control register 0x2D of both HDMI 2.1 receivers. | descriptive |
| [`hdmi_rx21_init_register_pointers`](../../src/leon2s/hdmi/hdmi_rx21_init_register_pointers.c) | `FUN_a0096204` | Fill the register block pointers of both HDMI 2.1 receivers. | derived |
| [`hdmi_rx21_is_event_pending`](../../src/leon2s/hdmi/hdmi_rx21_is_event_pending.c) | `FUN_a00a0588` | Return 1 when an HDMI 2.1 event is pending; most events must also be enabled. | derived |
| `hdmi_rx21_is_event_pending_jump_table` | `switchdataD_a00a0568` | Jump table 1 of the switch statements in hdmi_rx21_is_event_pending. | proven |
| [`hdmi_rx21_is_format_420`](../../src/leon2s/hdmi/hdmi_rx21_is_format_420.c) | `FUN_a00a2080` | Return 1 when the colour format of an HDMI 2.1 input is 4:2:0 (format code 3), else 0. | derived |
| [`hdmi_rx21_is_frl_mode`](../../src/leon2s/hdmi/hdmi_rx21_is_frl_mode.c) | `FUN_a00a29b0` | Return whether an HDMI 2.1 receiver runs in FRL (not TMDS) mode. | derived |
| [`hdmi_rx21_is_interlaced`](../../src/leon2s/hdmi/hdmi_rx21_is_interlaced.c) | `FUN_a009c3bc` | Return whether the HDMI 2.1 receiver reports an interlaced picture. | derived |
| [`hdmi_rx21_is_port_ready`](../../src/leon2s/hdmi/hdmi_rx21_is_port_ready.c) | `FUN_a0096308` | Return whether an HDMI 2.1 receiver record has both ready flags set. | descriptive |
| [`hdmi_rx21_load_lane_values_masked`](../../src/leon2s/hdmi/hdmi_rx21_load_lane_values_masked.c) | `FUN_a00802cc` | Write the lane start values and pulse the lane reset for the lanes in the mask. | descriptive |
| [`hdmi_rx21_mask_all_events`](../../src/leon2s/hdmi/hdmi_rx21_mask_all_events.c) | `FUN_a00a2e48` | Disable all interrupt events of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_measure_payload_delay`](../../src/leon2s/hdmi/hdmi_rx21_measure_payload_delay.c) | `u32payload_delay` | Measure the FRL payload count of an HDMI 2.1 receiver and set the delay bit. | derived |
| [`hdmi_rx21_measure_pixel_clock`](../../src/leon2s/hdmi/hdmi_rx21_measure_pixel_clock.c) | `FUN_a0097680` | Measure the pixel clock of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_mode_detect_settle`](../../src/leon2s/hdmi/hdmi_rx21_mode_detect_settle.c) | `FUN_a0097f04` | Mode detection state 6 of an HDMI 2.1 receiver: step the hold count, acknowledge events, set state 7. | descriptive |
| [`hdmi_rx21_modedet_check_pll`](../../src/leon2s/hdmi/hdmi_rx21_modedet_check_pll.c) | `MODEDET_handler_3` | Mode-detect state 4: wait until the active line count is stable, then go to STANDBY, or restart EQ. | proven |
| [`hdmi_rx21_modedet_reset_state`](../../src/leon2s/hdmi/hdmi_rx21_modedet_reset_state.c) | `FUN_a009e9fc` | Set the mode-detect state of an HDMI 2.1 receiver back to the start. | derived |
| [`hdmi_rx21_modedet_restart_standby`](../../src/leon2s/hdmi/hdmi_rx21_modedet_restart_standby.c) | `FUN_a009e9cc` | Put the mode detection of an HDMI 2.1 receiver into the standby state. | derived |
| [`hdmi_rx21_modedet_set_pll_mode`](../../src/leon2s/hdmi/hdmi_rx21_modedet_set_pll_mode.c) | `MODEDET_handler_2` | Select the pixel PLL bit mode (8/10/12/16 bits) for an HDMI 2.1 input. | proven |
| [`hdmi_rx21_modedet_wait_eq_done`](../../src/leon2s/hdmi/hdmi_rx21_modedet_wait_eq_done.c) | `Jay_EQ_End` | Wait for the end of EQ tuning on an HDMI 2.1 input, then start mode detection. | derived |
| [`hdmi_rx21_modedet_watch_stable`](../../src/leon2s/hdmi/hdmi_rx21_modedet_watch_stable.c) | `FUN_a009d2f8` | Watch a stable HDMI 2.1 input for DSC, VRR and timing changes (mode-detect state 8). | derived |
| [`hdmi_rx21_on_audio_infoframe`](../../src/leon2s/hdmi/hdmi_rx21_on_audio_infoframe.c) | `FUN_a00a146c` | Mark the audio InfoFrame received and read it when allowed. | derived |
| [`hdmi_rx21_on_audio_stream_packet`](../../src/leon2s/hdmi/hdmi_rx21_on_audio_stream_packet.c) | `FUN_a00a1104` | Mark the audio stream packet received and read it when allowed. | derived |
| [`hdmi_rx21_on_hdr_infoframe`](../../src/leon2s/hdmi/hdmi_rx21_on_hdr_infoframe.c) | `FUN_a00a157c` | Mark the HDR InfoFrame received and read it when allowed. | derived |
| [`hdmi_rx21_on_spd_packet`](../../src/leon2s/hdmi/hdmi_rx21_on_spd_packet.c) | `FUN_a00a13a0` | Store the AMD FreeSync data or the standard SPD InfoFrame of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_pick_eq_step`](../../src/leon2s/hdmi/hdmi_rx21_pick_eq_step.c) | `FUN_a0079ac4` | Choose an EQ step (8/4/2/0) from two lane status fields and the link mode. | descriptive |
| [`hdmi_rx21_poll_frl_rate_change`](../../src/leon2s/hdmi/hdmi_rx21_poll_frl_rate_change.c) | `FUN_a009f654` | Check both HDMI 2.1 receivers for an FRL rate change. | derived |
| [`hdmi_rx21_print_lane_rct`](../../src/leon2s/hdmi/hdmi_rx21_print_lane_rct.c) | `HDMI_SET_DESCRAMBLE_MODE` | Print the RCT register value of the four HDMI 2.1 lanes. | proven |
| [`hdmi_rx21_pulse_bit9_set_flag`](../../src/leon2s/hdmi/hdmi_rx21_pulse_bit9_set_flag.c) | `FUN_a00a14c4` | Pulse control bit 9 of an HDMI 2.1 receiver and set a done flag. | descriptive |
| [`hdmi_rx21_pulse_bit9_set_flag_copy`](../../src/leon2s/hdmi/hdmi_rx21_pulse_bit9_set_flag_copy.c) | `FUN_a00a151c` | Pulse control bit 9 of an HDMI 2.1 receiver and set a done flag. | descriptive |
| [`hdmi_rx21_pulse_ctrl_bit`](../../src/leon2s/hdmi/hdmi_rx21_pulse_ctrl_bit.c) | `FUN_a007a050` | Pulse bit 16 of PHY register 0x2E60 with bit 20 set. | descriptive |
| [`hdmi_rx21_pulse_lane_bit4_all`](../../src/leon2s/hdmi/hdmi_rx21_pulse_lane_bit4_all.c) | `FUN_a007f9d0` | Pulse bit 4 of PHY register 0x060 of all four lanes. | descriptive |
| [`hdmi_rx21_pulse_lane_bit4_masked`](../../src/leon2s/hdmi/hdmi_rx21_pulse_lane_bit4_masked.c) | `FUN_a007f900` | Pulse bit 4 of PHY register 0x060 of each lane in the mask (set, one long delay unit, clear). | descriptive |
| [`hdmi_rx21_pulse_reg4c_bit0`](../../src/leon2s/hdmi/hdmi_rx21_pulse_reg4c_bit0.c) | `FUN_a009fe60` | Set and then clear bit 0 of register 0x4C of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_pulse_reg84_bits`](../../src/leon2s/hdmi/hdmi_rx21_pulse_reg84_bits.c) | `FUN_a009fe2c` | Set and then clear the given bits of control register 0x84 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_read_audio_cts`](../../src/leon2s/hdmi/hdmi_rx21_read_audio_cts.c) | `FUN_a009c58c` | Return the audio clock value CTS received by an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_read_audio_infoframe`](../../src/leon2s/hdmi/hdmi_rx21_read_audio_infoframe.c) | `FUN_a009faf0` | Read and decode the audio InfoFrame of an HDMI 2.1 receiver. | proven |
| [`hdmi_rx21_read_audio_n`](../../src/leon2s/hdmi/hdmi_rx21_read_audio_n.c) | `FUN_a009c558` | Return the audio clock value N received by an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_read_audio_status`](../../src/leon2s/hdmi/hdmi_rx21_read_audio_status.c) | `FUN_a009c718` | Collect the audio status fields of an HDMI 2.1 receiver into a block. | derived |
| [`hdmi_rx21_read_audio_stream_packet`](../../src/leon2s/hdmi/hdmi_rx21_read_audio_stream_packet.c) | `FUN_a00a0268` | Copy the audio stream packet bytes of an HDMI 2.1 receiver into a buffer. | derived |
| [`hdmi_rx21_read_avi_infoframe`](../../src/leon2s/hdmi/hdmi_rx21_read_avi_infoframe.c) | `FUN_a009f738` | Read and decode the AVI InfoFrame of an HDMI 2.1 receiver. | proven |
| [`hdmi_rx21_read_avi_type`](../../src/leon2s/hdmi/hdmi_rx21_read_avi_type.c) | `FUN_a009facc` | Return the packet type byte of the AVI InfoFrame area of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_read_cvtem`](../../src/leon2s/hdmi/hdmi_rx21_read_cvtem.c) | `FUN_a00a0478` | Read the compressed-video (CVTEM) packet fields of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_read_frl_rate`](../../src/leon2s/hdmi/hdmi_rx21_read_frl_rate.c) | `FUN_a00735e8` | Return the FRL rate field (bits 24..27 of register word 0x90) of an HDMI 2.1 PHY; 0 for other PHYs. | derived |
| [`hdmi_rx21_read_hdr_infoframe`](../../src/leon2s/hdmi/hdmi_rx21_read_hdr_infoframe.c) | `FUN_a009fed0` | Read and decode the HDR mastering InfoFrame of an HDMI 2.1 receiver. | proven |
| [`hdmi_rx21_read_spd_infoframe`](../../src/leon2s/hdmi/hdmi_rx21_read_spd_infoframe.c) | `FUN_a009fcb8` | Read the standard SPD (source product) InfoFrame of an HDMI 2.1 receiver. | proven |
| [`hdmi_rx21_read_vtotal`](../../src/leon2s/hdmi/hdmi_rx21_read_vtotal.c) | `FUN_a009c09c` | Return the vertical total (lines per frame) of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_reg_read8`](../../src/leon2s/hdmi/hdmi_rx21_reg_read8.c) | `FUN_a00a69b4` | Read a byte register of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_reg_update_bits`](../../src/leon2s/hdmi/hdmi_rx21_reg_update_bits.c) | `FUN_a00a6aa0` | Set or clear masked bits of a byte register of one or both HDMI 2.1 receivers. | derived |
| [`hdmi_rx21_reg_write8`](../../src/leon2s/hdmi/hdmi_rx21_reg_write8.c) | `FUN_a00a69fc` | Write a byte register of one or both HDMI 2.1 receivers. | derived |
| [`hdmi_rx21_reload_lane_regs`](../../src/leon2s/hdmi/hdmi_rx21_reload_lane_regs.c) | `FUN_a007a79c` | Reset the TMDS channel registers of a PHY and write fixed values to the lane registers in the mask. | descriptive |
| [`hdmi_rx21_reset_ced_history`](../../src/leon2s/hdmi/hdmi_rx21_reset_ced_history.c) | `FUN_a0099560` | Clear the character-error count history of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_reset_error_counter`](../../src/leon2s/hdmi/hdmi_rx21_reset_error_counter.c) | `FUN_a0098b60` | Clear the error counter of an HDMI 2.1 receiver and flag it for the LTS_L state. | descriptive |
| [`hdmi_rx21_reset_lane_ctrl_regs`](../../src/leon2s/hdmi/hdmi_rx21_reset_lane_ctrl_regs.c) | `FUN_a007abbc` | Reset the control registers of the four HDMI 2.1 lanes. | descriptive |
| [`hdmi_rx21_reset_lane_eq_regs`](../../src/leon2s/hdmi/hdmi_rx21_reset_lane_eq_regs.c) | `FUN_a0079e00` | Write the default EQ register values of all four HDMI 2.1 lanes. | descriptive |
| [`hdmi_rx21_reset_lane_setting`](../../src/leon2s/hdmi/hdmi_rx21_reset_lane_setting.c) | `FUN_a007ab94` | Set the byte setting of all four lanes to its default 0x1F. | descriptive |
| [`hdmi_rx21_reset_mode_detect_state`](../../src/leon2s/hdmi/hdmi_rx21_reset_mode_detect_state.c) | `FUN_a0096a6c` | Reset the mode-detect state of both HDMI 2.1 receivers. | derived |
| [`hdmi_rx21_reset_reg84_blocks`](../../src/leon2s/hdmi/hdmi_rx21_reset_reg84_blocks.c) | `FUN_a009fe98` | Set bits 0x71 of register 0x84 and pulse its reset bits 0xEA8A. | descriptive |
| [`hdmi_rx21_reset_rsed_history`](../../src/leon2s/hdmi/hdmi_rx21_reset_rsed_history.c) | `FUN_a0099610` | Clear the Reed-Solomon error count history of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_reset_rx_detect_state`](../../src/leon2s/hdmi/hdmi_rx21_reset_rx_detect_state.c) | `FUN_a00a29ec` | Set the link-training state of an HDMI 2.1 receiver back to the start. | derived |
| [`hdmi_rx21_restart_lanes`](../../src/leon2s/hdmi/hdmi_rx21_restart_lanes.c) | `FUN_a007f9e8` | Pulse the lane reset bits and the PHY control bit, then wait. | descriptive |
| [`hdmi_rx21_restart_port`](../../src/leon2s/hdmi/hdmi_rx21_restart_port.c) | `FUN_a00a22d4` | Restart an HDMI 2.1 receiver port: flag it, clear its controls, reset PHY errors. | derived |
| [`hdmi_rx21_run_event_callbacks`](../../src/leon2s/hdmi/hdmi_rx21_run_event_callbacks.c) | `FUN_a00a1098` | Call the callback of each set bit of an event mask from a table. | derived |
| [`hdmi_rx21_run_link_state`](../../src/leon2s/hdmi/hdmi_rx21_run_link_state.c) | `LINK_STANDBY_2` | Run one step of the HDMI 2.1 receiver link state machine for one port. | proven |
| `hdmi_rx21_run_link_state_jump_table` | `switchdataD_a006e430` | Jump table 1 of the switch statements in hdmi_rx21_run_link_state. | proven |
| [`hdmi_rx21_run_mode_detect_fsm`](../../src/leon2s/hdmi/hdmi_rx21_run_mode_detect_fsm.c) | `FLT_no_retrain` | Run the mode-detect state machine of both HDMI 2.1 receivers and re-arm its timer. | derived |
| [`hdmi_rx21_run_rx_detect_fsm`](../../src/leon2s/hdmi/hdmi_rx21_run_rx_detect_fsm.c) | `FUN_a009a41c` | Run the link-training state machine of both HDMI 2.1 receivers and re-arm its timer. | derived |
| [`hdmi_rx21_score_lane`](../../src/leon2s/hdmi/hdmi_rx21_score_lane.c) | `FUN_a0079b84` | Compute a quality score for one HDMI 2.1 lane from its eye status fields. | descriptive |
| [`hdmi_rx21_service_irq_port0`](../../src/leon2s/hdmi/hdmi_rx21_service_irq_port0.c) | `FUN_a00a28d8` | Service the interrupt of HDMI 2.1 receiver 0: HDR10+, then sync events. | derived |
| [`hdmi_rx21_service_irq_port1`](../../src/leon2s/hdmi/hdmi_rx21_service_irq_port1.c) | `FUN_a00a2928` | Service the interrupt of HDMI 2.1 receiver 1: HDR10+, then sync events. | derived |
| [`hdmi_rx21_service_packet_events`](../../src/leon2s/hdmi/hdmi_rx21_service_packet_events.c) | `FUN_a00a1150` | Run the packet-event callbacks of an HDMI 2.1 receiver and refresh its AVI data. | derived |
| [`hdmi_rx21_service_sync_events`](../../src/leon2s/hdmi/hdmi_rx21_service_sync_events.c) | `FUN_a00a0c84` | Handle pending events 8, 0x1C, 0xE, 0x16, 0xB and 0xC of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_set_audio_enable`](../../src/leon2s/hdmi/hdmi_rx21_set_audio_enable.c) | `FUN_a00a1bb0` | Enable or disable the audio output path of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_set_audio_mode_bits`](../../src/leon2s/hdmi/hdmi_rx21_set_audio_mode_bits.c) | `FUN_a00a2374` | Set audio register 9 bits 16 and 18 of an HDMI 2.1 receiver by mode. | descriptive |
| [`hdmi_rx21_set_audio_mute`](../../src/leon2s/hdmi/hdmi_rx21_set_audio_mute.c) | `FUN_a009c794` | Set or clear the audio mute bit of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_set_audio_reg9_bit21`](../../src/leon2s/hdmi/hdmi_rx21_set_audio_reg9_bit21.c) | `FUN_a00a2320` | Set or clear bit 21 of audio register 9 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_set_connected`](../../src/leon2s/hdmi/hdmi_rx21_set_connected.c) | `FUN_a00a1b58` | Mark an HDMI 2.1 receiver port connected and update the connect state. | derived |
| [`hdmi_rx21_set_ctrl_bits_1b_18`](../../src/leon2s/hdmi/hdmi_rx21_set_ctrl_bits_1b_18.c) | `FUN_a0097ff4` | Set control bit 0x1B and set or clear bit 0x18 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_set_deep_color_enable`](../../src/leon2s/hdmi/hdmi_rx21_set_deep_color_enable.c) | `FUN_a00a2010` | Set or clear the deep-colour bit of the pixel PLL register. | derived |
| [`hdmi_rx21_set_event_reg78_bit`](../../src/leon2s/hdmi/hdmi_rx21_set_event_reg78_bit.c) | `FUN_a00a0b98` | Set or clear one bit of event register 0x78 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_set_event_reg78_bit9`](../../src/leon2s/hdmi/hdmi_rx21_set_event_reg78_bit9.c) | `FUN_a00a0514` | Set bit 9 of event register 0x78 of both HDMI 2.1 receivers. | descriptive |
| [`hdmi_rx21_set_frl_clock`](../../src/leon2s/hdmi/hdmi_rx21_set_frl_clock.c) | `FUN_a009ea34` | Set the HDMI 2.1 receiver clock for the FRL rate (3, 6, 8, 10 or 12 GHz). | proven |
| `hdmi_rx21_set_frl_clock_jump_table` | `switchdataD_a009ea1c` | Jump table 1 of the switch statements in hdmi_rx21_set_frl_clock. | proven |
| [`hdmi_rx21_set_frl_clock_wrapper`](../../src/leon2s/hdmi/hdmi_rx21_set_frl_clock_wrapper.c) | `FUN_a009ec20` | Set the HDMI 2.1 receiver clock for an FRL rate. | proven |
| [`hdmi_rx21_set_lane_bit7_all`](../../src/leon2s/hdmi/hdmi_rx21_set_lane_bit7_all.c) | `FUN_a007a6f0` | Set bit 7 and the control fields on all four lanes. | descriptive |
| [`hdmi_rx21_set_lane_bit7_masked`](../../src/leon2s/hdmi/hdmi_rx21_set_lane_bit7_masked.c) | `FUN_a007a648` | Set bit 7 and the control fields of the lanes selected in the mask. | descriptive |
| [`hdmi_rx21_set_lane_ctrl_all`](../../src/leon2s/hdmi/hdmi_rx21_set_lane_ctrl_all.c) | `FUN_a00798fc` | Set the control field and bit 7 of the four HDMI 2.1 lane registers. | descriptive |
| [`hdmi_rx21_set_mask_bits`](../../src/leon2s/hdmi/hdmi_rx21_set_mask_bits.c) | `FUN_a00a2418` | Set the control bits selected by a mask on an HDMI 2.1 receiver (newer chips). | descriptive |
| [`hdmi_rx21_set_mode_change_flag`](../../src/leon2s/hdmi/hdmi_rx21_set_mode_change_flag.c) | `FUN_a009e9a4` | Set the mode-change flag of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_set_pll_color_depth`](../../src/leon2s/hdmi/hdmi_rx21_set_pll_color_depth.c) | `FUN_a00a1f84` | Set the pixel PLL colour-depth field for colour depth code 4..7. | derived |
| [`hdmi_rx21_set_pll_ctrl_bit5`](../../src/leon2s/hdmi/hdmi_rx21_set_pll_ctrl_bit5.c) | `FUN_a009645c` | Set or clear bit 5 of the FRL PLL control register of a receiver. | descriptive |
| [`hdmi_rx21_set_port_enable`](../../src/leon2s/hdmi/hdmi_rx21_set_port_enable.c) | `FUN_a00a1c74` | Enable and start, or stop and disable, an HDMI 2.1 receiver port. | derived |
| [`hdmi_rx21_set_port_flag`](../../src/leon2s/hdmi/hdmi_rx21_set_port_flag.c) | `FUN_a00962ec` | Store a flag byte of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_set_reg1f0c_bit18`](../../src/leon2s/hdmi/hdmi_rx21_set_reg1f0c_bit18.c) | `FUN_a00a1734` | Set bit 18 of PHY register 0x1F0C. | descriptive |
| [`hdmi_rx21_setup_lanes_all`](../../src/leon2s/hdmi/hdmi_rx21_setup_lanes_all.c) | `FUN_a007a630` | Write the per-lane set-up register tables for all four lanes. | descriptive |
| [`hdmi_rx21_setup_lanes_masked`](../../src/leon2s/hdmi/hdmi_rx21_setup_lanes_masked.c) | `FUN_a007a0a0` | Write the per-lane set-up register tables for the lanes in the mask. | descriptive |
| [`hdmi_rx21_start_port`](../../src/leon2s/hdmi/hdmi_rx21_start_port.c) | `FUN_a00a15c8` | Reset an HDMI 2.1 receiver port, mark it active and start the detect timers. | derived |
| [`hdmi_rx21_status04_bit17`](../../src/leon2s/hdmi/hdmi_rx21_status04_bit17.c) | `FUN_a00a28a4` | Return bit 17 of status register 4 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_status30_bit4`](../../src/leon2s/hdmi/hdmi_rx21_status30_bit4.c) | `FUN_a0097ed0` | Return bit 4 of status word 0x30 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_status70_bit17`](../../src/leon2s/hdmi/hdmi_rx21_status70_bit17.c) | `FUN_a009c6e4` | Return bit 17 of status register 0x70 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_status70_bit24`](../../src/leon2s/hdmi/hdmi_rx21_status70_bit24.c) | `FUN_a0096428` | Return bit 24 of status word 0x70 of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_stop_port`](../../src/leon2s/hdmi/hdmi_rx21_stop_port.c) | `FUN_a00a1638` | Shut an HDMI 2.1 receiver port down: flags, events, interrupts and mode state. | derived |
| [`hdmi_rx21_store_clock`](../../src/leon2s/hdmi/hdmi_rx21_store_clock.c) | `FUN_a00977cc` | Store the measured clock of an HDMI 2.1 receiver in its record. | derived |
| [`hdmi_rx21_track_ced_errors`](../../src/leon2s/hdmi/hdmi_rx21_track_ced_errors.c) | `MAX_CED` | Record the per-lane character error counts and report lanes with too many. | derived |
| [`hdmi_rx21_track_rsed_errors`](../../src/leon2s/hdmi/hdmi_rx21_track_rsed_errors.c) | `MAX_RSED` | Record the Reed-Solomon error count of the link and report when it is too high. | derived |
| [`hdmi_rx21_update_connect_state`](../../src/leon2s/hdmi/hdmi_rx21_update_connect_state.c) | `FUN_a00a1a80` | Copy the connect flag of both HDMI 2.1 receivers and restart mode detection on connected ones. | derived |
| [`hdmi_rx21_update_ctrl_bit19`](../../src/leon2s/hdmi/hdmi_rx21_update_ctrl_bit19.c) | `FUN_a0098048` | Set or clear bit 0x19 of block 1 register 0x34 of an HDMI 2.1 receiver from a block 2 status word. | descriptive |
| [`hdmi_rx21_update_frl_rate`](../../src/leon2s/hdmi/hdmi_rx21_update_frl_rate.c) | `TxFFE_Max_L` | Take over a new FRL rate request of the source and restart the LTP timer. | derived |
| [`hdmi_rx21_update_irq_bits`](../../src/leon2s/hdmi/hdmi_rx21_update_irq_bits.c) | `FUN_a009740c` | Set or clear bit 0x10 of block 1 register 0x34 of an HDMI 2.1 receiver from its status bits. | descriptive |
| [`hdmi_rx21_update_mode_info`](../../src/leon2s/hdmi/hdmi_rx21_update_mode_info.c) | `H_Total` | Fill the mode info of an HDMI 2.1 input from its timing registers and check it. | proven |
| [`hdmi_rx21_update_packet_forward_bit`](../../src/leon2s/hdmi/hdmi_rx21_update_packet_forward_bit.c) | `FUN_a00a93e4` | Set or clear bit 23 of packet word 0xE8 of an HDMI 2.1 receiver by output use. | descriptive |
| [`hdmi_rx21_update_port_mode`](../../src/leon2s/hdmi/hdmi_rx21_update_port_mode.c) | `FUN_a00980a8` | Update the mode byte and registers of an HDMI 2.1 receiver. | descriptive |
| [`hdmi_rx21_update_port_status_flags`](../../src/leon2s/hdmi/hdmi_rx21_update_port_status_flags.c) | `FUN_a006e0e4` | Refresh the status flags of an HDMI 2.1 port record. | derived |
| [`hdmi_rx21_write_all_port_enables`](../../src/leon2s/hdmi/hdmi_rx21_write_all_port_enables.c) | `FUN_a00a2c18` | Set or clear the port enable bit of both HDMI 2.1 receivers. | derived |
| [`hdmi_rx21_write_audio_level`](../../src/leon2s/hdmi/hdmi_rx21_write_audio_level.c) | `FUN_a00a1b80` | Write the audio level of an HDMI 2.1 receiver to both channel fields. | derived |
| [`hdmi_rx21_write_block30_reg2`](../../src/leon2s/hdmi/hdmi_rx21_write_block30_reg2.c) | `FUN_a00a2f70` | Write a 6-bit value and an enable bit to register 2 of block 0x30 of a receiver. | descriptive |
| [`hdmi_rx21_write_lane_setting`](../../src/leon2s/hdmi/hdmi_rx21_write_lane_setting.c) | `FUN_a007aac4` | Write a byte setting to one lane, or to all four lanes. | descriptive |
| [`hdmi_rx21_write_pll_params`](../../src/leon2s/hdmi/hdmi_rx21_write_pll_params.c) | `FUN_a00964d0` | Write the three FRL PLL parameter registers of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_write_port_enable`](../../src/leon2s/hdmi/hdmi_rx21_write_port_enable.c) | `FUN_a00a2c94` | Set or clear the port enable bit of an HDMI 2.1 receiver. | derived |
| [`hdmi_rx21_write_reg1f0c_bit18`](../../src/leon2s/hdmi/hdmi_rx21_write_reg1f0c_bit18.c) | `FUN_a00a1df0` | Set or clear bit 18 of PHY register 0x1F0C. | descriptive |
| [`hdmi_save_link_timing`](../../src/leon2s/hdmi/hdmi_save_link_timing.c) | `FUN_a0091204` | Store the measured timing, clocks and colour depth of an HDMI receiver. | derived |
| [`hdmi_scdc_bit_ratio_40`](../../src/leon2s/hdmi/hdmi_scdc_bit_ratio_40.c) | `FUN_a007af6c` | Return the source's SCDC TMDS bit-clock-ratio bit (1/40 mode) of a port. | derived |
| [`hdmi_scdc_scrambling_enabled`](../../src/leon2s/hdmi/hdmi_scdc_scrambling_enabled.c) | `FUN_a007af04` | Return the source's SCDC scrambling-enable bit of a port. | derived |
| [`hdmi_set_descramble_auto_mode`](../../src/leon2s/hdmi/hdmi_set_descramble_auto_mode.c) | `FUN_a007ed0c` | Set or clear bit 1 of receiver register 0x2F6 (HDMI 2.1: bit 17 of block-3 word +0x74). | derived |
| [`hdmi_set_descramble_mode`](../../src/leon2s/hdmi/hdmi_set_descramble_mode.c) | `FUN_a007ec30` | Set or clear the two bits that hdmi_get_scramble_lock and hdmi_get_scramble_status read. | derived |
| [`hdmi_set_port_mode_byte`](../../src/leon2s/hdmi/hdmi_set_port_mode_byte.c) | `FUN_a0077e68` | Store the per-port mode byte of an HDMI receiver. | descriptive |
| [`hdmi_set_port_ratio_flag`](../../src/leon2s/hdmi/hdmi_set_port_ratio_flag.c) | `FUN_a0083618` | Store the per-port clock-ratio flag byte. | descriptive |
| [`hdmi_set_port_reg5_bit4`](../../src/leon2s/hdmi/hdmi_set_port_reg5_bit4.c) | `FUN_a006d548` | Set bit 4 of register 5 in a TMDS receiver block. | descriptive |
| [`hdmi_set_reg2fd_bit3`](../../src/leon2s/hdmi/hdmi_set_reg2fd_bit3.c) | `FUN_a0091520` | Set bit 3 of HDMI receiver register 0x2FD. | descriptive |
| [`hdmi_set_reg08_from_avi`](../../src/leon2s/hdmi/hdmi_set_reg08_from_avi.c) | `FUN_a008facc` | Set the high nibble of HDMI receiver register 8 from the AVI field of reg 0x148. | descriptive |
| [`hdmi_set_reg135_mode`](../../src/leon2s/hdmi/hdmi_set_reg135_mode.c) | `FUN_a008fe38` | Write 6 or 9 to HDMI receiver register 0x135. | descriptive |
| [`hdmi_set_regb5_bit2`](../../src/leon2s/hdmi/hdmi_set_regb5_bit2.c) | `FUN_a008fe6c` | Set or clear bit 2 of HDMI receiver register 0xB5. | descriptive |
| [`hdmi_set_ycbcr422_bit`](../../src/leon2s/hdmi/hdmi_set_ycbcr422_bit.c) | `FUN_a008fdc8` | Set bit 1 of receiver register 0x48 when the AVI colour space field is 1, else clear it. | descriptive |
| [`hdmi_set_ycbcr_regs`](../../src/leon2s/hdmi/hdmi_set_ycbcr_regs.c) | `FUN_a00912ec` | Set the YCbCr handling registers 0x4B..0x4D of an HDMI receiver. | descriptive |
| [`hdmi_start_eq_detect_task`](../../src/leon2s/hdmi/hdmi_start_eq_detect_task.c) | `FUN_a0073540` | Start the periodic HDMI equaliser check task. | derived |
| [`hdmi_status134_bit1`](../../src/leon2s/hdmi/hdmi_status134_bit1.c) | `FUN_a008f9c0` | Return bit 1 of HDMI receiver status register 0x134. | descriptive |
| [`hdmi_stop_eq_detect_task`](../../src/leon2s/hdmi/hdmi_stop_eq_detect_task.c) | `FUN_a00735c0` | Stop the periodic HDMI equaliser check task. | derived |
| [`hdmi_tmds_restart_port`](../../src/leon2s/hdmi/hdmi_tmds_restart_port.c) | `FUN_a008ffa4` | Restart an HDMI 2.0 input port after a request from the main processor. | derived |
| [`hdmi_tmds_run_link_state`](../../src/leon2s/hdmi/hdmi_tmds_run_link_state.c) | `LINK_STANDBY` | Run one step of the HDMI 2.0 receiver link state machine for one port. | proven |
| `hdmi_tmds_run_link_state_jump_table` | `switchdataD_a006d7a8` | Jump table 1 of the switch statements in hdmi_tmds_run_link_state. | proven |
| [`hdmi_tx_apply_pending_request`](../../src/leon2s/hdmi/hdmi_tx_apply_pending_request.c) | `FUN_a00916a8` | Copy a pending HDMI TX request from the main processor into the channel record. | derived |
| [`hdmi_tx_apply_request_regs`](../../src/leon2s/hdmi/hdmi_tx_apply_request_regs.c) | `FUN_a0094594` | Write the requested option bytes of an HDMI TX channel into its registers. | descriptive |
| [`hdmi_tx_build_audio_infoframe_from_sdp`](../../src/leon2s/hdmi/hdmi_tx_build_audio_infoframe_from_sdp.c) | `FUN_a00a8f28` | Build an InfoFrame with 10 payload bytes (audio size) from a DP SDP packet. | derived |
| [`hdmi_tx_build_avi_infoframe`](../../src/leon2s/hdmi/hdmi_tx_build_avi_infoframe.c) | `FUN_a00a9020` | Build an AVI InfoFrame for an HDMI output from the colour format of a DP input. | proven |
| `hdmi_tx_build_avi_infoframe_jump_table` | `switchdataD_a00a8f8c` | Jump table 1 of the switch statements in hdmi_tx_build_avi_infoframe. | proven |
| [`hdmi_tx_build_infoframe_from_sdp`](../../src/leon2s/hdmi/hdmi_tx_build_infoframe_from_sdp.c) | `FUN_a00a8ec4` | Build an InfoFrame with 27 payload bytes and checksum from a DP SDP packet. | derived |
| [`hdmi_tx_build_pps_packet`](../../src/leon2s/hdmi/hdmi_tx_build_pps_packet.c) | `FUN_a0092db8` | Build the 161-byte compression parameter (PPS) packet of an HDMI TX port and write it to bank 2. | derived |
| [`hdmi_tx_check_hotplug`](../../src/leon2s/hdmi/hdmi_tx_check_hotplug.c) | `FUN_a0095d78` | Read and parse the sink EDID when an HDMI TX display is plugged in. | derived |
| [`hdmi_tx_check_timing`](../../src/leon2s/hdmi/hdmi_tx_check_timing.c) | `FUN_a0094c54` | Print the HDMI TX output timing, or report that the PSTABLE flag failed. | proven |
| [`hdmi_tx_clear_active`](../../src/leon2s/hdmi/hdmi_tx_clear_active.c) | `FUN_a0091b74` | Mark an HDMI TX channel as not running. | descriptive |
| [`hdmi_tx_clear_cfg_bit14`](../../src/leon2s/hdmi/hdmi_tx_clear_cfg_bit14.c) | `FUN_a0091a88` | Clear bit 14 of word 5 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_clear_ctrl_bit31`](../../src/leon2s/hdmi/hdmi_tx_clear_ctrl_bit31.c) | `FUN_a0091540` | Clear bit 31 of word 0 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_clear_frl_mode`](../../src/leon2s/hdmi/hdmi_tx_clear_frl_mode.c) | `FUN_a0091988` | Switch an HDMI TX channel record back from FRL to TMDS. | derived |
| [`hdmi_tx_clear_frl_rate_update`](../../src/leon2s/hdmi/hdmi_tx_clear_frl_rate_update.c) | `FUN_a00919b0` | Clear the 'update FRL rate' bit (word 5 bit 13) of an HDMI TX channel record. | derived |
| [`hdmi_tx_clear_status_bit31`](../../src/leon2s/hdmi/hdmi_tx_clear_status_bit31.c) | `FUN_a0091b00` | Clear bit 31 of word 1 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_copy_audio_info_from_dp`](../../src/leon2s/hdmi/hdmi_tx_copy_audio_info_from_dp.c) | `FUN_a009332c` | Build the HDMI TX audio InfoFrame from the audio data of a DP input. | derived |
| [`hdmi_tx_copy_audio_info_from_hdmi`](../../src/leon2s/hdmi/hdmi_tx_copy_audio_info_from_hdmi.c) | `FUN_a00931fc` | Copy the audio settings and InfoFrame of an HDMI input into an HDMI TX port. | derived |
| [`hdmi_tx_ddc_read`](../../src/leon2s/hdmi/hdmi_tx_ddc_read.c) | `FUN_a00c81f8` | Read a block of bytes from a device on the HDMI output's DDC channel. | proven |
| [`hdmi_tx_ddc_read_at`](../../src/leon2s/hdmi/hdmi_tx_ddc_read_at.c) | `FUN_a00c82dc` | Start a DDC read at an address and fetch the bytes. | derived |
| [`hdmi_tx_ddc_read_fifo`](../../src/leon2s/hdmi/hdmi_tx_ddc_read_fifo.c) | `FUN_a00c7fec` | Read a number of bytes from one register of the DDC master into a buffer, then wait. | derived |
| [`hdmi_tx_ddc_reset`](../../src/leon2s/hdmi/hdmi_tx_ddc_reset.c) | `FUN_a00c7bf8` | Reset the DDC master of an HDMI output until its status reads idle. | derived |
| [`hdmi_tx_ddc_reset_step_first`](../../src/leon2s/hdmi/hdmi_tx_ddc_reset_step_first.c) | `FUN_a00c7b60` | Set the low four bits of the DDC control register 0xF3. | descriptive |
| [`hdmi_tx_ddc_reset_step_second`](../../src/leon2s/hdmi/hdmi_tx_ddc_reset_step_second.c) | `FUN_a00c7b90` | Set the low nibble of the DDC control register 0xF3 to 9. | descriptive |
| [`hdmi_tx_ddc_reset_step_third`](../../src/leon2s/hdmi/hdmi_tx_ddc_reset_step_third.c) | `FUN_a00c7bc4` | Write a derived value to a DDC control register. | descriptive |
| [`hdmi_tx_ddc_start`](../../src/leon2s/hdmi/hdmi_tx_ddc_start.c) | `FUN_a00c8048` | Program the DDC master with a device address, an offset and a byte count. | proven |
| [`hdmi_tx_ddc_start_edid_tail`](../../src/leon2s/hdmi/hdmi_tx_ddc_start_edid_tail.c) | `FUN_a00c87c0` | Program the DDC master to read eight bytes near the end of an EDID block. | descriptive |
| [`hdmi_tx_ddc_write`](../../src/leon2s/hdmi/hdmi_tx_ddc_write.c) | `FUN_a00c80f0` | Write a block of bytes to a device on the HDMI output's DDC channel. | proven |
| [`hdmi_tx_dsc_setup`](../../src/leon2s/hdmi/hdmi_tx_dsc_setup.c) | `FUN_a00dd37c` | Write the compression timing and rate values of an HDMI transmitter. | derived |
| [`hdmi_tx_dsc_write_rate`](../../src/leon2s/hdmi/hdmi_tx_dsc_write_rate.c) | `FUN_a00dd154` | Compute the compressed-stream rate value of an HDMI transmitter and write it. | descriptive |
| [`hdmi_tx_dsc_write_timing`](../../src/leon2s/hdmi/hdmi_tx_dsc_write_timing.c) | `FUN_a00dcdb8` | Write the compression timing values of an HDMI transmitter. | descriptive |
| [`hdmi_tx_enable_audio_infoframe`](../../src/leon2s/hdmi/hdmi_tx_enable_audio_infoframe.c) | `FUN_a0093060` | Switch sending of the audio InfoFrame of an HDMI TX port. | derived |
| [`hdmi_tx_enable_avi_packet`](../../src/leon2s/hdmi/hdmi_tx_enable_avi_packet.c) | `FUN_a00924dc` | Switch sending of the AVI InfoFrame of an HDMI TX port on or off. | derived |
| [`hdmi_tx_enable_extra_infoframe`](../../src/leon2s/hdmi/hdmi_tx_enable_extra_infoframe.c) | `FUN_a0092608` | Switch sending of the InfoFrame in the 0x160 slot of an HDMI TX port. | descriptive |
| [`hdmi_tx_enable_packet_bits67`](../../src/leon2s/hdmi/hdmi_tx_enable_packet_bits67.c) | `FUN_a00925e4` | Set or clear the packet enable bits 6..7 of HDMI TX register 0x13E. | descriptive |
| [`hdmi_tx_enable_pps_packet`](../../src/leon2s/hdmi/hdmi_tx_enable_pps_packet.c) | `FUN_a009270c` | Switch sending of the compression parameter (PPS) packet of an HDMI TX port on or off. | proven |
| [`hdmi_tx_enable_vtem_packet`](../../src/leon2s/hdmi/hdmi_tx_enable_vtem_packet.c) | `FUN_a0092890` | Switch sending of the VTEM packet of an HDMI TX port. | derived |
| [`hdmi_tx_fill_packet_defaults`](../../src/leon2s/hdmi/hdmi_tx_fill_packet_defaults.c) | `FUN_a00a9380` | Fill an 11-byte packet record with fixed values for one of two modes. | descriptive |
| [`hdmi_tx_frl_init_timer`](../../src/leon2s/hdmi/hdmi_tx_frl_init_timer.c) | `FUN_a00a4610` | Create the HDMI TX FRL training timer with its callback. | derived |
| [`hdmi_tx_frl_start_timer`](../../src/leon2s/hdmi/hdmi_tx_frl_start_timer.c) | `FUN_a00a45d8` | Start the HDMI TX FRL training timer with its period. | derived |
| [`hdmi_tx_get_ctrl_bit30`](../../src/leon2s/hdmi/hdmi_tx_get_ctrl_bit30.c) | `FUN_a0091c5c` | Return bit 30 of word 0 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_get_ctrl_bit31`](../../src/leon2s/hdmi/hdmi_tx_get_ctrl_bit31.c) | `FUN_a0091a10` | Return bit 31 of word 0 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_get_frl_rate`](../../src/leon2s/hdmi/hdmi_tx_get_frl_rate.c) | `FUN_a009193c` | Return the FRL rate of an HDMI TX channel. | derived |
| [`hdmi_tx_get_hsync_polarity`](../../src/leon2s/hdmi/hdmi_tx_get_hsync_polarity.c) | `FUN_a0091c10` | Return the requested horizontal sync polarity of an HDMI TX channel. | proven |
| [`hdmi_tx_get_source_code`](../../src/leon2s/hdmi/hdmi_tx_get_source_code.c) | `FUN_a0091c38` | Return the input source code of an HDMI TX channel. | derived |
| [`hdmi_tx_get_status_bit31`](../../src/leon2s/hdmi/hdmi_tx_get_status_bit31.c) | `FUN_a0095ef8` | Return bit 31 of word 1 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_get_vsync_polarity`](../../src/leon2s/hdmi/hdmi_tx_get_vsync_polarity.c) | `FUN_a0091be8` | Return the requested vertical sync polarity of an HDMI TX channel. | proven |
| [`hdmi_tx_init`](../../src/leon2s/hdmi/hdmi_tx_init.c) | `FUN_a0095c30` | Reset and prepare both HDMI TX ports at start-up. | derived |
| [`hdmi_tx_init_core_regs`](../../src/leon2s/hdmi/hdmi_tx_init_core_regs.c) | `FUN_a00944e0` | Load the fixed start values of the HDMI TX core registers. | descriptive |
| [`hdmi_tx_is_active`](../../src/leon2s/hdmi/hdmi_tx_is_active.c) | `FUN_a0091bac` | Return whether an HDMI TX channel is marked as running. | descriptive |
| [`hdmi_tx_is_frl_mode`](../../src/leon2s/hdmi/hdmi_tx_is_frl_mode.c) | `FUN_a0091960` | Return whether an HDMI TX channel uses FRL instead of TMDS. | derived |
| [`hdmi_tx_is_port0_enabled`](../../src/leon2s/hdmi/hdmi_tx_is_port0_enabled.c) | `FUN_a0070404` | Return bit 0 of the command flag byte: the enable of HDMI TX port 0. | derived |
| [`hdmi_tx_is_port1_enabled`](../../src/leon2s/hdmi/hdmi_tx_is_port1_enabled.c) | `FUN_a0070414` | Return bit 1 of the command flag byte: the enable of HDMI TX port 1. | derived |
| [`hdmi_tx_is_sink_connected`](../../src/leon2s/hdmi/hdmi_tx_is_sink_connected.c) | `FUN_a0095d34` | Return whether a display is plugged into an HDMI TX port. | derived |
| [`hdmi_tx_load_reg0c_trim`](../../src/leon2s/hdmi/hdmi_tx_load_reg0c_trim.c) | `FUN_a008e004` | Load HDMI TX register 0x0C from the calibration record, default 0x0C. | descriptive |
| [`hdmi_tx_load_stored_audio_info`](../../src/leon2s/hdmi/hdmi_tx_load_stored_audio_info.c) | `FUN_a0093164` | Load the stored audio settings and audio InfoFrame into an HDMI TX port. | descriptive |
| [`hdmi_tx_mark_request_pending`](../../src/leon2s/hdmi/hdmi_tx_mark_request_pending.c) | `FUN_a00918ec` | Mark the HDMI TX request of a channel as pending. | derived |
| [`hdmi_tx_parse_hf_vsdb`](../../src/leon2s/hdmi/hdmi_tx_parse_hf_vsdb.c) | `FUN_a00a33f4` | Find the HDMI Forum VSDB in a sink EDID and store its FRL and DSC fields. | proven |
| [`hdmi_tx_phy_enable_outputs`](../../src/leon2s/hdmi/hdmi_tx_phy_enable_outputs.c) | `FUN_a008e654` | Enable the HDMI TX output stages and load the calibration value. | descriptive |
| [`hdmi_tx_phy_power_down`](../../src/leon2s/hdmi/hdmi_tx_phy_power_down.c) | `FUN_a008e6b8` | Apply the HDMI TX PHY power-down settings. | proven |
| [`hdmi_tx_phy_set_power`](../../src/leon2s/hdmi/hdmi_tx_phy_set_power.c) | `FUN_a008dbd4` | Run the HDMI TX PHY power-up or power-down register sequence. | descriptive |
| [`hdmi_tx_phy_setup_frl`](../../src/leon2s/hdmi/hdmi_tx_phy_setup_frl.c) | `FUN_a008ecb8` | Load the HDMI TX PHY settings for FRL operation. | descriptive |
| [`hdmi_tx_phy_switch_power`](../../src/leon2s/hdmi/hdmi_tx_phy_switch_power.c) | `FUN_a008e5ac` | Order the HDMI TX PHY power call and two control bits by FRL mode and rate, then wait. | descriptive |
| [`hdmi_tx_phy_tune_for_tmds_clock`](../../src/leon2s/hdmi/hdmi_tx_phy_tune_for_tmds_clock.c) | `FUN_a008f270` | Tune the HDMI TX PHY for the TMDS clock range (up to 148, 340, above). | proven |
| [`hdmi_tx_print_frl_rate`](../../src/leon2s/hdmi/hdmi_tx_print_frl_rate.c) | `FUN_a0094fb0` | Print the FRL rate of an HDMI TX port as text. | proven |
| [`hdmi_tx_pulse_regf1_bit7`](../../src/leon2s/hdmi/hdmi_tx_pulse_regf1_bit7.c) | `FUN_a0094a10` | Pulse bit 7 of HDMI TX bank 3 register 0xF1. | descriptive |
| [`hdmi_tx_read_edid`](../../src/leon2s/hdmi/hdmi_tx_read_edid.c) | `FUN_a0091db4` | Read EDID bytes of the display connected to an HDMI TX port. | proven |
| [`hdmi_tx_read_sink_edid`](../../src/leon2s/hdmi/hdmi_tx_read_sink_edid.c) | `FUN_a0095ca4` | Read the EDID base block and up to three extensions of an HDMI TX sink. | proven |
| [`hdmi_tx_reg_read8`](../../src/leon2s/hdmi/hdmi_tx_reg_read8.c) | `FUN_a00a7fd8` | Read a byte register of a bank of an HDMI transmitter. | proven |
| [`hdmi_tx_reg_update_bits`](../../src/leon2s/hdmi/hdmi_tx_reg_update_bits.c) | `FUN_a00a80cc` | Set or clear masked bits of a byte register of an HDMI transmitter bank. | proven |
| [`hdmi_tx_reg_write8`](../../src/leon2s/hdmi/hdmi_tx_reg_write8.c) | `FUN_a00a8054` | Write a byte register of a bank of an HDMI transmitter. | proven |
| [`hdmi_tx_reg_write_field`](../../src/leon2s/hdmi/hdmi_tx_reg_write_field.c) | `FUN_a00a8184` | Replace the masked bits of an HDMI transmitter bank register with new bits. | proven |
| [`hdmi_tx_reset_audio_regs`](../../src/leon2s/hdmi/hdmi_tx_reset_audio_regs.c) | `FUN_a0091e70` | Reset the audio input registers of an HDMI TX port. | descriptive |
| [`hdmi_tx_reset_channel`](../../src/leon2s/hdmi/hdmi_tx_reset_channel.c) | `FUN_a0091578` | Reset an HDMI TX channel record to its default settings. | derived |
| [`hdmi_tx_reset_keep_packets`](../../src/leon2s/hdmi/hdmi_tx_reset_keep_packets.c) | `FUN_a00943d0` | Pulse the HDMI TX reset bit while keeping the packet settings. | derived |
| [`hdmi_tx_run_frl_training`](../../src/leon2s/hdmi/hdmi_tx_run_frl_training.c) | `FUN_a00a4658` | Run the FRL link-training state machine of both HDMI TX ports and re-arm its timer. | derived |
| [`hdmi_tx_run_service`](../../src/leon2s/hdmi/hdmi_tx_run_service.c) | `FUN_a0095ea4` | Run the regular HDMI TX tasks: hot-plug, pending requests and set-up steps. | derived |
| [`hdmi_tx_run_setup_steps`](../../src/leon2s/hdmi/hdmi_tx_run_setup_steps.c) | `FUN_a00958d4` | Run the HDMI TX set-up steps (source, packets, clocks, PHY, timing check). | proven |
| [`hdmi_tx_run_step`](../../src/leon2s/hdmi/hdmi_tx_run_step.c) | `FUN_a00950a0` | Carry out one numbered set-up step (0..17) of an HDMI TX port. | derived |
| `hdmi_tx_run_step_jump_table` | `switchdataD_a0095058` | Jump table 1 of the switch statements in hdmi_tx_run_step. | proven |
| [`hdmi_tx_scdc_read`](../../src/leon2s/hdmi/hdmi_tx_scdc_read.c) | `FUN_a0091d64` | Read one SCDC register of the display connected to an HDMI TX port. | proven |
| [`hdmi_tx_scdc_write`](../../src/leon2s/hdmi/hdmi_tx_scdc_write.c) | `FUN_a0091cf4` | Write one SCDC register of the display connected to an HDMI TX port. | proven |
| [`hdmi_tx_select_link_source`](../../src/leon2s/hdmi/hdmi_tx_select_link_source.c) | `FUN_a0094798` | Select which input feeds an HDMI TX port. | proven |
| [`hdmi_tx_select_packet_source`](../../src/leon2s/hdmi/hdmi_tx_select_packet_source.c) | `FUN_a00a88b8` | Write an input's source number into the packet source field of a packet group and HDMI TX port. | derived |
| [`hdmi_tx_select_source_port`](../../src/leon2s/hdmi/hdmi_tx_select_source_port.c) | `FUN_a008ed50` | Connect or disconnect an input port as the source of an HDMI TX port. | descriptive |
| [`hdmi_tx_send_avi_infoframe`](../../src/leon2s/hdmi/hdmi_tx_send_avi_infoframe.c) | `FUN_a0092100` | Build and send the AVI InfoFrame of an HDMI TX port. | proven |
| `hdmi_tx_send_avi_infoframe_jump_table` | `switchdataD_a00920ec` | Jump table 1 of the switch statements in hdmi_tx_send_avi_infoframe. | proven |
| [`hdmi_tx_service_port`](../../src/leon2s/hdmi/hdmi_tx_service_port.c) | `FUN_a0095e08` | Check hot-plug of an enabled HDMI TX port, or shut a disabled one down. | derived |
| [`hdmi_tx_set_active`](../../src/leon2s/hdmi/hdmi_tx_set_active.c) | `FUN_a0091b3c` | Mark an HDMI TX channel as set up and running. | descriptive |
| [`hdmi_tx_set_bank4_mode`](../../src/leon2s/hdmi/hdmi_tx_set_bank4_mode.c) | `FUN_a0094e40` | Set the HDMI TX bank 4 mode bits and reg 8 bits 4..5 for a mode. | descriptive |
| [`hdmi_tx_set_bank4_offsets`](../../src/leon2s/hdmi/hdmi_tx_set_bank4_offsets.c) | `FUN_a0094b30` | Store a value (11..492) and write offsets derived from it to HDMI TX bank 4. | descriptive |
| [`hdmi_tx_set_cfg_bit14`](../../src/leon2s/hdmi/hdmi_tx_set_cfg_bit14.c) | `FUN_a0091a4c` | Set bit 14 of word 5 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_set_clock_mode_reg5`](../../src/leon2s/hdmi/hdmi_tx_set_clock_mode_reg5.c) | `FUN_a008d980` | Set the clock mode field (bits 2..3) of HDMI TX register 5. | descriptive |
| [`hdmi_tx_set_clock_mode_reg7f`](../../src/leon2s/hdmi/hdmi_tx_set_clock_mode_reg7f.c) | `FUN_a008da34` | Set the clock mode field (bits 2..3) of HDMI TX register 0x7F. | descriptive |
| [`hdmi_tx_set_color_depth`](../../src/leon2s/hdmi/hdmi_tx_set_color_depth.c) | `FUN_a0091f14` | Set the colour depth (8, 10 or 12 bits) of an HDMI TX port. | proven |
| [`hdmi_tx_set_color_depth_reg6`](../../src/leon2s/hdmi/hdmi_tx_set_color_depth_reg6.c) | `FUN_a008d920` | Set the 10/12-bit colour depth bits of HDMI TX register 6. | derived |
| [`hdmi_tx_set_color_depth_reg7f`](../../src/leon2s/hdmi/hdmi_tx_set_color_depth_reg7f.c) | `FUN_a008d9d4` | Set the 10/12-bit colour depth bits of HDMI TX register 0x7F. | derived |
| [`hdmi_tx_set_ddc_clock_divider`](../../src/leon2s/hdmi/hdmi_tx_set_ddc_clock_divider.c) | `FUN_a0091c84` | Set the 10-bit clock divider of the HDMI TX DDC master. | descriptive |
| [`hdmi_tx_set_deep_color_bit`](../../src/leon2s/hdmi/hdmi_tx_set_deep_color_bit.c) | `FUN_a0091ef0` | Set or clear the deep colour bit (reg 0x12F bit 6) of an HDMI TX port. | derived |
| [`hdmi_tx_set_frl_clock`](../../src/leon2s/hdmi/hdmi_tx_set_frl_clock.c) | `FUN_a008e958` | Select the FRL link clock (3 to 12 GHz) of an HDMI TX port. | proven |
| `hdmi_tx_set_frl_clock_jump_table` | `switchdataD_a008e940` | Jump table 1 of the switch statements in hdmi_tx_set_frl_clock. | proven |
| [`hdmi_tx_set_frl_rate`](../../src/leon2s/hdmi/hdmi_tx_set_frl_rate.c) | `FUN_a0091918` | Store the FRL rate (1..6) of an HDMI TX channel. | derived |
| [`hdmi_tx_set_frl_rate_update`](../../src/leon2s/hdmi/hdmi_tx_set_frl_rate_update.c) | `FUN_a00919e0` | Set the 'update FRL rate' bit (word 5 bit 13) of an HDMI TX channel record. | derived |
| [`hdmi_tx_set_frl_reg28_bit0`](../../src/leon2s/hdmi/hdmi_tx_set_frl_reg28_bit0.c) | `FUN_a0094ac4` | Set or clear bit 0 of HDMI TX bank 4 register 0x28. | descriptive |
| [`hdmi_tx_set_frl_reg28_bit2`](../../src/leon2s/hdmi/hdmi_tx_set_frl_reg28_bit2.c) | `FUN_a0094ae8` | Set or clear bit 2 of HDMI TX bank 4 register 0x28. | descriptive |
| [`hdmi_tx_set_frl_reg28_bits`](../../src/leon2s/hdmi/hdmi_tx_set_frl_reg28_bits.c) | `FUN_a0094b0c` | Set or clear bits 1, 3, 4 and 5 of HDMI TX bank 4 register 0x28. | descriptive |
| [`hdmi_tx_set_lane_regs_7b_9f`](../../src/leon2s/hdmi/hdmi_tx_set_lane_regs_7b_9f.c) | `FUN_a008e098` | Write one value to HDMI TX registers 0x7B and 0x9D..0x9F. | descriptive |
| [`hdmi_tx_set_low_clock_bits`](../../src/leon2s/hdmi/hdmi_tx_set_low_clock_bits.c) | `FUN_a008f450` | Set HDMI TX register 5 bits 6..7 when the clock is below a depth-based limit. | descriptive |
| [`hdmi_tx_set_packet_switch`](../../src/leon2s/hdmi/hdmi_tx_set_packet_switch.c) | `FUN_a00a89c0` | Program one packet-forwarding group of an HDMI output for its input type. | derived |
| [`hdmi_tx_set_phy_reg3b_bits`](../../src/leon2s/hdmi/hdmi_tx_set_phy_reg3b_bits.c) | `FUN_a00a338c` | Set or clear bits 4 and 5 of PHY register 0x3B of an HDMI TX port. | descriptive |
| [`hdmi_tx_set_pixel_format`](../../src/leon2s/hdmi/hdmi_tx_set_pixel_format.c) | `FUN_a0092064` | Set the pixel format bits and matching clock mode of an HDMI TX port. | derived |
| [`hdmi_tx_set_reg0a_enables`](../../src/leon2s/hdmi/hdmi_tx_set_reg0a_enables.c) | `FUN_a008da88` | Set or clear the four enable bits of HDMI TX register 0x0A. | descriptive |
| [`hdmi_tx_set_reg0d_bit2`](../../src/leon2s/hdmi/hdmi_tx_set_reg0d_bit2.c) | `FUN_a0094308` | Set or clear bit 2 of HDMI TX register 0x0D. | descriptive |
| [`hdmi_tx_set_reg3b_mode`](../../src/leon2s/hdmi/hdmi_tx_set_reg3b_mode.c) | `FUN_a008e73c` | Set or clear bit 6 of HDMI TX register 0x3B and its low mode bits. | descriptive |
| [`hdmi_tx_set_reg05_enable`](../../src/leon2s/hdmi/hdmi_tx_set_reg05_enable.c) | `FUN_a008df7c` | Set HDMI TX register 5 bit 0, or 0x0D for the special port mode. | descriptive |
| [`hdmi_tx_set_reg07_bit7`](../../src/leon2s/hdmi/hdmi_tx_set_reg07_bit7.c) | `FUN_a008e054` | Set or clear bit 7 of HDMI TX register 7. | descriptive |
| [`hdmi_tx_set_reg7c_low_nibble`](../../src/leon2s/hdmi/hdmi_tx_set_reg7c_low_nibble.c) | `FUN_a008d8e0` | Write 0x0F (on = 1) or 0 to register 0x7C of the PHY bank of an HDMI output. | descriptive |
| [`hdmi_tx_set_reg7f_bit0`](../../src/leon2s/hdmi/hdmi_tx_set_reg7f_bit0.c) | `FUN_a008db90` | Set or clear bit 0 of HDMI TX register 0x7F. | descriptive |
| [`hdmi_tx_set_reg08_bit3`](../../src/leon2s/hdmi/hdmi_tx_set_reg08_bit3.c) | `FUN_a008db4c` | Set or clear bit 3 of HDMI TX register 8. | descriptive |
| [`hdmi_tx_set_reg8_bits45`](../../src/leon2s/hdmi/hdmi_tx_set_reg8_bits45.c) | `FUN_a0094f64` | Set HDMI TX register 8 bits 4..5 and write 10 to register 0x130. | descriptive |
| [`hdmi_tx_set_reg09_mode`](../../src/leon2s/hdmi/hdmi_tx_set_reg09_mode.c) | `FUN_a008df40` | Write 0x43 or 0x42 to HDMI TX register 9. | descriptive |
| [`hdmi_tx_set_reg12f_bits`](../../src/leon2s/hdmi/hdmi_tx_set_reg12f_bits.c) | `FUN_a009434c` | Set or clear bits 0 and 7 of HDMI TX register 0x12F. | descriptive |
| [`hdmi_tx_set_reg_f1_f2_bit0`](../../src/leon2s/hdmi/hdmi_tx_set_reg_f1_f2_bit0.c) | `FUN_a009498c` | Set bit 0 of HDMI TX bank 3 registers 0xF1 and 0xF2 from the record flags. | descriptive |
| [`hdmi_tx_set_regfd_mode`](../../src/leon2s/hdmi/hdmi_tx_set_regfd_mode.c) | `FUN_a0094a50` | Set (mode 1) or clear HDMI TX register 0xFD bits 5..6 and two related fields. | descriptive |
| [`hdmi_tx_set_regs_0a_99`](../../src/leon2s/hdmi/hdmi_tx_set_regs_0a_99.c) | `FUN_a008e2c0` | Set the mode fields of HDMI TX registers 0x0A and 0x99. | descriptive |
| [`hdmi_tx_set_regs_0e_9b`](../../src/leon2s/hdmi/hdmi_tx_set_regs_0e_9b.c) | `FUN_a008e200` | Set the 3-bit fields of HDMI TX registers 0x0E and 0x9B. | descriptive |
| [`hdmi_tx_set_regs_7c_9a`](../../src/leon2s/hdmi/hdmi_tx_set_regs_7c_9a.c) | `FUN_a008e3c0` | Set the fields of HDMI TX registers 0x7C and 0x9A from one value. | descriptive |
| [`hdmi_tx_set_regs_08_98`](../../src/leon2s/hdmi/hdmi_tx_set_regs_08_98.c) | `FUN_a008e0f0` | Set the mode nibbles of HDMI TX registers 0x08, 0x98 and 0x99 from a mode. | descriptive |
| [`hdmi_tx_set_regs_39_30`](../../src/leon2s/hdmi/hdmi_tx_set_regs_39_30.c) | `FUN_a008e484` | Set HDMI TX register 0x39 bits 0..1 and register 0x30 by mode. | descriptive |
| [`hdmi_tx_set_source_route_bits`](../../src/leon2s/hdmi/hdmi_tx_set_source_route_bits.c) | `FUN_a008e7c0` | Set or clear the route bits of an HDMI TX port in register 0xCF0116B4 for an input code. | descriptive |
| [`hdmi_tx_set_status_bit31`](../../src/leon2s/hdmi/hdmi_tx_set_status_bit31.c) | `FUN_a0091ac4` | Set bit 31 of word 1 of an HDMI TX channel record. | descriptive |
| [`hdmi_tx_set_sync_polarity`](../../src/leon2s/hdmi/hdmi_tx_set_sync_polarity.c) | `FUN_a00945f0` | Set the horizontal and vertical sync polarity of an HDMI TX port. | proven |
| [`hdmi_tx_set_txffe_mode`](../../src/leon2s/hdmi/hdmi_tx_set_txffe_mode.c) | `FUN_a00a3578` | Set the transmit equaliser (TxFFE) mode and level of an HDMI TX port. | proven |
| [`hdmi_tx_set_video_clock_ranges`](../../src/leon2s/hdmi/hdmi_tx_set_video_clock_ranges.c) | `FUN_a0095f20` | Compute the HDMI TX video clock and set the clock-range registers. | proven |
| [`hdmi_tx_set_vtem_enable_state`](../../src/leon2s/hdmi/hdmi_tx_set_vtem_enable_state.c) | `FUN_a00927a0` | Set the VTEM packet enable bits of an HDMI TX port, or clear them when idle. | descriptive |
| [`hdmi_tx_setup_audio`](../../src/leon2s/hdmi/hdmi_tx_setup_audio.c) | `FUN_a00934c0` | Set up the audio path of an HDMI TX port for its audio source. | derived |
| [`hdmi_tx_setup_clock_path`](../../src/leon2s/hdmi/hdmi_tx_setup_clock_path.c) | `FUN_a008e514` | Set the HDMI TX clock ratio and colour depth fields for the chosen mode. | descriptive |
| [`hdmi_tx_stop_packets`](../../src/leon2s/hdmi/hdmi_tx_stop_packets.c) | `FUN_a0094370` | Stop all InfoFrame packets and the deep colour bit of an HDMI TX port. | derived |
| [`hdmi_tx_stop_unless_enabled`](../../src/leon2s/hdmi/hdmi_tx_stop_unless_enabled.c) | `FUN_a009584c` | Power down and reset the running HDMI TX ports unless an output is enabled. | derived |
| [`hdmi_tx_sys_reg_read8`](../../src/leon2s/hdmi/hdmi_tx_sys_reg_read8.c) | `FUN_a00a82e4` | Read a byte register of an HDMI transmitter system block. | derived |
| [`hdmi_tx_sys_reg_update_bits`](../../src/leon2s/hdmi/hdmi_tx_sys_reg_update_bits.c) | `FUN_a00a8260` | Set or clear masked bits of a byte register of an HDMI transmitter system block. | derived |
| [`hdmi_tx_sys_reg_write_masked`](../../src/leon2s/hdmi/hdmi_tx_sys_reg_write_masked.c) | `FUN_a00a8210` | Replace the masked bits of a register of an HDMI transmitter system block. | derived |
| [`hdmi_tx_update_audio_infoframe`](../../src/leon2s/hdmi/hdmi_tx_update_audio_infoframe.c) | `FUN_a0093138` | Replace the audio InfoFrame of an HDMI TX port safely. | derived |
| [`hdmi_tx_update_avi_payload`](../../src/leon2s/hdmi/hdmi_tx_update_avi_payload.c) | `FUN_a00925b8` | Replace the AVI InfoFrame payload of an HDMI TX port safely. | derived |
| [`hdmi_tx_update_extra_infoframe`](../../src/leon2s/hdmi/hdmi_tx_update_extra_infoframe.c) | `FUN_a00926e0` | Replace the packet in the 0x160 InfoFrame slot of an HDMI TX port safely. | descriptive |
| [`hdmi_tx_update_vtem_packet`](../../src/leon2s/hdmi/hdmi_tx_update_vtem_packet.c) | `FUN_a0093034` | Replace the VTEM packet of an HDMI TX port safely. | derived |
| [`hdmi_tx_write_audio_infoframe`](../../src/leon2s/hdmi/hdmi_tx_write_audio_infoframe.c) | `FUN_a0093084` | Write an audio InfoFrame header and checksum into an HDMI TX port. | derived |
| [`hdmi_tx_write_avi_payload`](../../src/leon2s/hdmi/hdmi_tx_write_avi_payload.c) | `FUN_a0092500` | Write AVI InfoFrame payload bytes into an HDMI TX port. | derived |
| [`hdmi_tx_write_extra_infoframe`](../../src/leon2s/hdmi/hdmi_tx_write_extra_infoframe.c) | `FUN_a009262c` | Write a packet header and checksum into the 0x160 InfoFrame slot of an HDMI TX port. | descriptive |
| [`hdmi_tx_write_pps_packet`](../../src/leon2s/hdmi/hdmi_tx_write_pps_packet.c) | `FUN_a0092944` | Write a 161-byte compression parameter (PPS) packet into bank 2 of an HDMI TX port. | derived |
| [`hdmi_tx_write_reg0c`](../../src/leon2s/hdmi/hdmi_tx_write_reg0c.c) | `FUN_a008dfe4` | Write a value to HDMI TX register 0x0C. | descriptive |
| [`hdmi_tx_write_vtem_payload`](../../src/leon2s/hdmi/hdmi_tx_write_vtem_payload.c) | `FUN_a0092cec` | Write the VTEM packet bytes into page 3 of an HDMI TX port. | derived |
| [`hdmi_unit_pulse_reg3`](../../src/leon2s/hdmi/hdmi_unit_pulse_reg3.c) | `FUN_a00b1e30` | Pulse bit 2 of register 3 of a PLL unit. | descriptive |
| [`hdmi_unit_write_setup`](../../src/leon2s/hdmi/hdmi_unit_write_setup.c) | `FUN_a00b1d00` | Write the set-up registers (two 24-bit values) of a PLL unit and pulse its control register. | descriptive |
| `hdmi_unit_write_setup_jump_table` | `switchdataD_a00b1cdc` | Jump table 1 of the switch statements in hdmi_unit_write_setup. | proven |
| [`hdmi_update_port_status_flags`](../../src/leon2s/hdmi/hdmi_update_port_status_flags.c) | `FUN_a006d61c` | Refresh the VRR, signal and cable flags of an HDMI 2.0 port record. | derived |
| [`hdmi_update_reg137_bit1`](../../src/leon2s/hdmi/hdmi_update_reg137_bit1.c) | `FUN_a008f744` | Set or clear bit 1 of HDMI receiver register 0x137 from status regs 0x281/0x282. | descriptive |
| [`HDMITX_PacketSwitch_Bypass`](../../src/leon2s/hdmi/HDMITX_PacketSwitch_Bypass.c) | `HDMITX_PacketSwitch_Bypass` | Pass the data packets of an HDMI or DP input straight through to an HDMI output. | proven |
| [`TMDS_PowerOff`](../../src/leon2s/hdmi/TMDS_PowerOff.c) | `TMDS_PowerOff` | Power off the receiver PHY of an HDMI port. | proven |
| [`TMDS_PowerOn`](../../src/leon2s/hdmi/TMDS_PowerOn.c) | `TMDS_PowerOn` | Power on the receiver PHY of an HDMI port. | proven |

<a id="dp"></a>
## DisplayPort

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`dp_ack_link_events`](../../src/leon2s/dp/dp_ack_link_events.c) | `FUN_a00856fc` | Acknowledge the two event bits of a DP receiver and update register 0xAF. | descriptive |
| [`dp_ack_status_bit4`](../../src/leon2s/dp/dp_ack_status_bit4.c) | `FUN_a00ad684` | Copy the inverse of bit 4 of receiver register 0x8F into bit 1 of register 0x22A. | descriptive |
| [`dp_api_pulse_reg30e_clear`](../../src/leon2s/dp/dp_api_pulse_reg30e_clear.c) | `FUN_a00b0724` | Clear register 0x30E of a port inside its control pulse. | descriptive |
| [`dp_apply_format_code`](../../src/leon2s/dp/dp_apply_format_code.c) | `FUN_a00ae0dc` | Write the register values for a format code and its unit format field. | descriptive |
| [`dp_apply_port_link_bytes`](../../src/leon2s/dp/dp_apply_port_link_bytes.c) | `FUN_a00ae3a0` | Apply three link setting bytes of a port's record to its link block and register 0xC8. | descriptive |
| [`dp_apply_port_record`](../../src/leon2s/dp/dp_apply_port_record.c) | `FUN_a0084d04` | Write the fixed register set-up of a DP receiver block, then its stored settings record if valid. | descriptive |
| [`dp_apply_port_settings`](../../src/leon2s/dp/dp_apply_port_settings.c) | `FUN_a00af98c` | Write the register sequence that applies a port's stored settings. | derived |
| [`dp_block_get_reg88_bit7`](../../src/leon2s/dp/dp_block_get_reg88_bit7.c) | `FUN_a00aeb24` | Return 1 when bit 7 of the word at +0x88 of the DisplayPort block or bit 2 of register 0x463 is set, else 0. | descriptive |
| [`dp_block_get_reg88_bit15`](../../src/leon2s/dp/dp_block_get_reg88_bit15.c) | `FUN_a00aeadc` | Return 1 when bit 15 of the word at +0x88 of the DisplayPort block and bit 0 of register 0x463 are both set, else 0. | descriptive |
| [`dp_calc_pixel_clock`](../../src/leon2s/dp/dp_calc_pixel_clock.c) | `FUN_a00acc54` | Compute a port's pixel clock value from two 24-bit measurements and the link mode. | derived |
| [`dp_calc_rate_value`](../../src/leon2s/dp/dp_calc_rate_value.c) | `FUN_a00aceec` | Compute a rate value from four registers and a 2-bit selector. | descriptive |
| [`dp_calc_stream_clock`](../../src/leon2s/dp/dp_calc_stream_clock.c) | `FUN_a00aef04` | Read the stream's clock measurement values and program the clock recovery from them. | derived |
| [`dp_check_stream_clock`](../../src/leon2s/dp/dp_check_stream_clock.c) | `FUN_a00aec50` | Arm the stream clock check of a port, or return whether it passes or has timed out. | descriptive |
| [`dp_check_timing_change`](../../src/leon2s/dp/dp_check_timing_change.c) | `FUN_a006e990` | Read the DP link timing, compare it with the saved values and report a mode change. | proven |
| [`dp_clear_port_pending_bit`](../../src/leon2s/dp/dp_clear_port_pending_bit.c) | `FUN_a00ad060` | Clear the pending bit of port 0 or 1, or of both. | descriptive |
| [`dp_clear_port_status_bytes`](../../src/leon2s/dp/dp_clear_port_status_bytes.c) | `FUN_a00aba14` | Clear eight status bytes of a DP port record. | descriptive |
| [`dp_clear_reg3d0_value`](../../src/leon2s/dp/dp_clear_reg3d0_value.c) | `FUN_a00ac5a4` | Wait for DP receiver status bit 6 of register 0xC1, then clear registers 0x3D0..0x3D2. | descriptive |
| [`dp_clear_reg223_bit7`](../../src/leon2s/dp/dp_clear_reg223_bit7.c) | `FUN_a00ad764` | Clear bit 7 of register 0x223 of a port. | descriptive |
| [`dp_clear_start_bits`](../../src/leon2s/dp/dp_clear_start_bits.c) | `FUN_a00abb30` | Clear the start-up bits of a DP receiver around register 0xC0 bit 4. | descriptive |
| [`dp_clear_status_event`](../../src/leon2s/dp/dp_clear_status_event.c) | `FUN_a00ab964` | Clear one numbered status event of a DP receiver. | descriptive |
| `dp_clear_status_event_jump_table` | `switchdataD_a00ab93c` | Jump table 1 of the switch statements in dp_clear_status_event. | proven |
| [`dp_copy_tx_readings_to_rx`](../../src/leon2s/dp/dp_copy_tx_readings_to_rx.c) | `FUN_a00ae3e4` | Copy six readings of DP transmitter output 0 into receiver registers 0xCA..0xCF; write 0x7F to 0xD6. | descriptive |
| [`dp_enable_dsc`](../../src/leon2s/dp/dp_enable_dsc.c) | `FUN_a00af168` | Switch the DSC reception of a DP port on or off and print the choice. | proven |
| [`dp_flag_port_stream_reset`](../../src/leon2s/dp/dp_flag_port_stream_reset.c) | `FUN_a006d568` | Flag a DP port for a stream reset and clear its status bit 6. | descriptive |
| [`dp_get_color_depth`](../../src/leon2s/dp/dp_get_color_depth.c) | `FUN_a00acb94` | Return the colour depth of a port's stream in bits per colour: 6, 8, 10, 12 or 16. | proven |
| `dp_get_color_depth_jump_table` | `switchdataD_a00acb80` | Jump table 1 of the switch statements in dp_get_color_depth. | proven |
| [`dp_get_color_format_code`](../../src/leon2s/dp/dp_get_color_format_code.c) | `FUN_a00ada24` | Work out the colour format code of a port's stream. | derived |
| `dp_get_color_format_code_jump_table` | `switchdataD_a00ad8f0` | Jump table 1 of the switch statements in dp_get_color_format_code. | proven |
| [`dp_get_hactive`](../../src/leon2s/dp/dp_get_hactive.c) | `FUN_a00acac0` | Return the horizontal active width of a DP input. | derived |
| [`dp_get_link_flag`](../../src/leon2s/dp/dp_get_link_flag.c) | `FUN_a00856d0` | Return bit 1 of register 0xAF of a DP receiver. | descriptive |
| [`dp_get_link_rate_index`](../../src/leon2s/dp/dp_get_link_rate_index.c) | `FUN_a00ab690` | Return the link rate of a DP receiver as an index (RBR, HBR, HBR2, HBR3, other). | proven |
| [`dp_get_msa_bit3`](../../src/leon2s/dp/dp_get_msa_bit3.c) | `FUN_a00ad7c8` | Return bit 3 of indirect register 8 when a stream is present. | descriptive |
| [`dp_get_port_pending_bit`](../../src/leon2s/dp/dp_get_port_pending_bit.c) | `FUN_a00ad5a4` | Return the pending bit of port 0 or 1. | descriptive |
| [`dp_get_port_record_block_b8`](../../src/leon2s/dp/dp_get_port_record_block_b8.c) | `FUN_a00b02f0` | Return the address of the block at +0xB8 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_block_df`](../../src/leon2s/dp/dp_get_port_record_block_df.c) | `FUN_a00b035c` | Return the address of the block at +0xDF of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_117`](../../src/leon2s/dp/dp_get_port_record_byte_117.c) | `FUN_a00b1494` | Return byte 0x117 of a port's DisplayPort record. | descriptive |
| [`dp_get_port_record_byte_125`](../../src/leon2s/dp/dp_get_port_record_byte_125.c) | `FUN_a00b0470` | Return byte 0x125 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_127`](../../src/leon2s/dp/dp_get_port_record_byte_127.c) | `FUN_a00b048c` | Return byte 0x127 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_129`](../../src/leon2s/dp/dp_get_port_record_byte_129.c) | `FUN_a00b14b0` | Return byte 0x129 of a port's DisplayPort record, 0 for other ports. | descriptive |
| [`dp_get_port_record_byte_b5`](../../src/leon2s/dp/dp_get_port_record_byte_b5.c) | `FUN_a00b0264` | Return byte 0xB5 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_b6`](../../src/leon2s/dp/dp_get_port_record_byte_b6.c) | `FUN_a00b0248` | Return byte 0xB6 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_b7`](../../src/leon2s/dp/dp_get_port_record_byte_b7.c) | `FUN_a00b0280` | Return byte 0xB7 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_dc`](../../src/leon2s/dp/dp_get_port_record_byte_dc.c) | `FUN_a00b02b8` | Return byte 0xDC of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_dd`](../../src/leon2s/dp/dp_get_port_record_byte_dd.c) | `FUN_a00b029c` | Return byte 0xDD of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_de`](../../src/leon2s/dp/dp_get_port_record_byte_de.c) | `FUN_a00b02d4` | Return byte 0xDE of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_ef`](../../src/leon2s/dp/dp_get_port_record_byte_ef.c) | `FUN_a00b0324` | Return byte 0xEF of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f0`](../../src/leon2s/dp/dp_get_port_record_byte_f0.c) | `FUN_a00b0308` | Return byte 0xF0 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f1`](../../src/leon2s/dp/dp_get_port_record_byte_f1.c) | `FUN_a00b0340` | Return byte 0xF1 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f2`](../../src/leon2s/dp/dp_get_port_record_byte_f2.c) | `FUN_a00b0374` | Return byte 0xF2 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f3`](../../src/leon2s/dp/dp_get_port_record_byte_f3.c) | `FUN_a00b0390` | Return byte 0xF3 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f4`](../../src/leon2s/dp/dp_get_port_record_byte_f4.c) | `FUN_a00b03ac` | Return byte 0xF4 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f5`](../../src/leon2s/dp/dp_get_port_record_byte_f5.c) | `FUN_a00b03c8` | Return byte 0xF5 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f6`](../../src/leon2s/dp/dp_get_port_record_byte_f6.c) | `FUN_a00b03e4` | Return byte 0xF6 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f7`](../../src/leon2s/dp/dp_get_port_record_byte_f7.c) | `FUN_a00b0400` | Return byte 0xF7 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_byte_f8`](../../src/leon2s/dp/dp_get_port_record_byte_f8.c) | `FUN_a00b041c` | Return byte 0xF8 of a DisplayPort input's record. | descriptive |
| [`dp_get_port_record_word_fc`](../../src/leon2s/dp/dp_get_port_record_word_fc.c) | `FUN_a00b0438` | Return the word at +0xFC of a DisplayPort input's record. | descriptive |
| [`dp_get_port_setting_112`](../../src/leon2s/dp/dp_get_port_setting_112.c) | `FUN_a00ab674` | Return setting byte +0x112 of a DP port record. | descriptive |
| [`dp_get_port_swap`](../../src/leon2s/dp/dp_get_port_swap.c) | `FUN_a0083ec4` | Return the DP receiver port swap flag. | descriptive |
| [`dp_get_reg2a9_bit2`](../../src/leon2s/dp/dp_get_reg2a9_bit2.c) | `FUN_a00b1434` | Return bit 2 of register 0x2A9 of a port. | descriptive |
| [`dp_get_reg3a_bit6`](../../src/leon2s/dp/dp_get_reg3a_bit6.c) | `FUN_a00b1418` | Return bit 6 of register 0x3A of a port. | descriptive |
| [`dp_get_reg9f_field`](../../src/leon2s/dp/dp_get_reg9f_field.c) | `FUN_a00d6624` | Return the 2-bit field at bits 6-7 of register 0x9F of a port. | descriptive |
| [`dp_get_reg461_bit0`](../../src/leon2s/dp/dp_get_reg461_bit0.c) | `FUN_a00ad668` | Return bit 0 of register 0x461 of a port. | descriptive |
| [`dp_get_reg480_bit0`](../../src/leon2s/dp/dp_get_reg480_bit0.c) | `FUN_a00ae238` | Return bit 0 of register 0x480 of a port. | descriptive |
| [`dp_get_regc1_bit0`](../../src/leon2s/dp/dp_get_regc1_bit0.c) | `FUN_a00d6694` | Return bit 0 of register 0xC1 of a port. | descriptive |
| [`dp_get_unit_route_bit`](../../src/leon2s/dp/dp_get_unit_route_bit.c) | `FUN_a00adf64` | Return one of the four route status bits of a port. | descriptive |
| [`dp_get_vactive`](../../src/leon2s/dp/dp_get_vactive.c) | `FUN_a00acb00` | Return the active line count of a DP input: the 16-bit value of registers 0x8B / 0x8C. | derived |
| [`dp_handle_block_event`](../../src/leon2s/dp/dp_handle_block_event.c) | `FUN_a00aeb6c` | Note a block event for a port and pulse its control bit when one of two event bits is set. | descriptive |
| [`dp_has_slice_count`](../../src/leon2s/dp/dp_has_slice_count.c) | `FUN_a00af320` | Return whether a port's slice count is non-zero while bit 6 of register 0x8F is set. | derived |
| [`dp_init_port`](../../src/leon2s/dp/dp_init_port.c) | `FUN_a00b1028` | Run the full set-up sequence of a DisplayPort input. | derived |
| [`dp_init_port_registers`](../../src/leon2s/dp/dp_init_port_registers.c) | `FUN_a0083fb8` | Write the fixed start-up register sequence of a DP receiver. | descriptive |
| [`dp_init_port_settings`](../../src/leon2s/dp/dp_init_port_settings.c) | `FUN_a00ab8b8` | Load the default settings into a DP port record. | derived |
| [`dp_irq_disable_port`](../../src/leon2s/dp/dp_irq_disable_port.c) | `FUN_a00b0540` | Switch the interrupt sources of DisplayPort input 0 or 1 off. | descriptive |
| [`dp_irq_enable_port`](../../src/leon2s/dp/dp_irq_enable_port.c) | `FUN_a00b0518` | Switch the interrupt sources of DisplayPort input 0 or 1 on. | descriptive |
| [`dp_is_format_code_group_3`](../../src/leon2s/dp/dp_is_format_code_group_3.c) | `FUN_a00ad828` | Return whether a format code is one of twelve listed values. | descriptive |
| [`dp_is_high_rate_mode`](../../src/leon2s/dp/dp_is_high_rate_mode.c) | `FUN_a00aea64` | Test chip revision above 0x83, high nibble of register 0x481 equal 4 and active width 3440. | descriptive |
| [`dp_is_link_trained`](../../src/leon2s/dp/dp_is_link_trained.c) | `FUN_a00ad27c` | Return whether at least one lane of a port's link has both of its status bits set. | proven |
| [`dp_is_msa_bit4_clear`](../../src/leon2s/dp/dp_is_msa_bit4_clear.c) | `FUN_a00ad6ec` | Select indirect register 8 and return whether bit 4 of its value is clear. | descriptive |
| [`dp_is_port_ready_for_service`](../../src/leon2s/dp/dp_is_port_ready_for_service.c) | `FUN_a00ad3e0` | Return 1 when the port's bit in 0xCF0132C0 is set or its record byte 0x11F and the pulse flag are 1. | descriptive |
| [`dp_is_reg44_low_bits_set`](../../src/leon2s/dp/dp_is_reg44_low_bits_set.c) | `FUN_a00ad644` | Return whether either of the low two bits of register 0x44 is set. | descriptive |
| [`dp_is_stream_present`](../../src/leon2s/dp/dp_is_stream_present.c) | `FUN_a00ad784` | Return whether a port receives a video stream. | derived |
| [`dp_is_trained_with_reg223_bit7`](../../src/leon2s/dp/dp_is_trained_with_reg223_bit7.c) | `FUN_a00ad320` | Return whether port setting 0x115 is on, the link is trained and bit 7 of register 0x223 is set. | descriptive |
| [`dp_isr_port0`](../../src/leon2s/dp/dp_isr_port0.c) | `FUN_a00ae850` | Interrupt work for port 0: copy and clear the status registers into a ring when signalled. | descriptive |
| [`dp_isr_port1`](../../src/leon2s/dp/dp_isr_port1.c) | `FUN_a00aea0c` | Interrupt work for port 1: read the status block when enabled, then the common step. | descriptive |
| [`dp_map_port`](../../src/leon2s/dp/dp_map_port.c) | `FUN_a0083ed0` | Map a DP port number to its receiver block, honouring the port swap. | derived |
| [`dp_map_port_lane_unit`](../../src/leon2s/dp/dp_map_port_lane_unit.c) | `FUN_a00add48` | Return the receiver unit that a port and lane pair is mapped to. | derived |
| [`dp_mst_advance_tx_index`](../../src/leon2s/dp/dp_mst_advance_tx_index.c) | `FUN_a00da388` | Step past the head message of the reply ring and clear its ready bit when asked. | descriptive |
| [`dp_mst_append_chunk_to_message`](../../src/leon2s/dp/dp_mst_append_chunk_to_message.c) | `FUN_a00d985c` | Append the body bytes of a received chunk to the message being assembled. | derived |
| [`dp_mst_clear_busy_bit`](../../src/leon2s/dp/dp_mst_clear_busy_bit.c) | `FUN_a00d7ca4` | Clear bit 7 of the port's control word at +0xC0. | descriptive |
| [`dp_mst_clear_ready_bit`](../../src/leon2s/dp/dp_mst_clear_ready_bit.c) | `FUN_a00da960` | Set the pending flag when nothing was sent; on request clear the ready bit of the last record kind. | descriptive |
| [`dp_mst_count_pending_chunks`](../../src/leon2s/dp/dp_mst_count_pending_chunks.c) | `FUN_a00dbf24` | Add up the fill levels of the four chunk rings. | descriptive |
| [`dp_mst_crc8_data`](../../src/leon2s/dp/dp_mst_crc8_data.c) | `FUN_a00d9988` | Compute the 8-bit checksum of a message body. | derived |
| [`dp_mst_dispatch_request`](../../src/leon2s/dp/dp_mst_dispatch_request.c) | `FUN_a00d9698` | Call the handler for the request number of a received MST message. | proven |
| [`dp_mst_downstream_task`](../../src/leon2s/dp/dp_mst_downstream_task.c) | `FUN_a00dbe74` | Fetch messages from the output and run the notification sequence when idle. | derived |
| [`dp_mst_fetch_downstream_message`](../../src/leon2s/dp/dp_mst_fetch_downstream_message.c) | `FUN_a00db784` | Read a 48-byte message chunk from the output's DPCD 0x1400 or 0x1600 over AUX. | proven |
| [`dp_mst_find_message_bounds`](../../src/leon2s/dp/dp_mst_find_message_bounds.c) | `FUN_a00d7cd0` | Scan the received chunks of the current port for the end slot of the first complete message. | derived |
| [`dp_mst_find_up_message_end`](../../src/leon2s/dp/dp_mst_find_up_message_end.c) | `FUN_a00d9d50` | Find the first stored message row from the output that carries the end flag of a message. | derived |
| [`dp_mst_forward_down_request`](../../src/leon2s/dp/dp_mst_forward_down_request.c) | `FUN_a00db53c` | Send a stored down request on to the output over AUX, with payload handling. | derived |
| [`dp_mst_forward_task`](../../src/leon2s/dp/dp_mst_forward_task.c) | `FUN_a00dbed4` | Forward a waiting down request while the notify flag is set; otherwise discard the queued requests. | derived |
| [`dp_mst_get_port_tx_state`](../../src/leon2s/dp/dp_mst_get_port_tx_state.c) | `FUN_a00d9e44` | Return the transmit state of the current port. | descriptive |
| [`dp_mst_get_reply_timeout`](../../src/leon2s/dp/dp_mst_get_reply_timeout.c) | `FUN_a00dabf8` | Return the reply time-out of 3000 ticks. | derived |
| [`dp_mst_get_reply_timeout_copy`](../../src/leon2s/dp/dp_mst_get_reply_timeout_copy.c) | `FUN_a00dac00` | Return the reply time-out of 3000 ticks. | derived |
| [`dp_mst_get_request_number`](../../src/leon2s/dp/dp_mst_get_request_number.c) | `FUN_a00d95e4` | Return the request number of the message that is being handled. | derived |
| [`dp_mst_get_ring_distance`](../../src/leon2s/dp/dp_mst_get_ring_distance.c) | `FUN_a00d9e5c` | Return the distance between a ring's read and write index. | descriptive |
| [`dp_mst_get_rx_chunk_address`](../../src/leon2s/dp/dp_mst_get_rx_chunk_address.c) | `FUN_a00d66bc` | Return the address of the received-chunk row that the current port reads next. | derived |
| [`dp_mst_get_state_byte_47`](../../src/leon2s/dp/dp_mst_get_state_byte_47.c) | `FUN_a00dc084` | Return the MST service's state byte at 0xA8078847. | descriptive |
| [`dp_mst_get_state_byte_52`](../../src/leon2s/dp/dp_mst_get_state_byte_52.c) | `FUN_a00dc09c` | Return the MST service's state byte at 0xA8078852. | descriptive |
| [`dp_mst_get_state_byte_53`](../../src/leon2s/dp/dp_mst_get_state_byte_53.c) | `FUN_a00dc090` | Return the MST service's state byte at 0xA8078853. | descriptive |
| [`dp_mst_handle_allocate_payload`](../../src/leon2s/dp/dp_mst_handle_allocate_payload.c) | `FUN_a00d84f4` | Answer the MST request 0x11 (ALLOCATE_PAYLOAD). | proven |
| [`dp_mst_handle_clear_payload_table`](../../src/leon2s/dp/dp_mst_handle_clear_payload_table.c) | `FUN_a00d8714` | Answer the MST request 0x14 (CLEAR_PAYLOAD_ID_TABLE). | proven |
| [`dp_mst_handle_connection_status`](../../src/leon2s/dp/dp_mst_handle_connection_status.c) | `FUN_a00d82c8` | Answer the MST request 0x02 (CONNECTION_STATUS_NOTIFY). | proven |
| [`dp_mst_handle_enum_path_resources`](../../src/leon2s/dp/dp_mst_handle_enum_path_resources.c) | `FUN_a00d8300` | Answer the MST request 0x10 (ENUM_PATH_RESOURCES). | proven |
| [`dp_mst_handle_link_address`](../../src/leon2s/dp/dp_mst_handle_link_address.c) | `FUN_a00d7e6c` | Answer the MST request 0x01 (LINK_ADDRESS). | proven |
| [`dp_mst_handle_power_down_phy`](../../src/leon2s/dp/dp_mst_handle_power_down_phy.c) | `FUN_a00d904c` | Answer the MST request 0x25 (POWER_DOWN_PHY). | proven |
| [`dp_mst_handle_power_up_phy`](../../src/leon2s/dp/dp_mst_handle_power_up_phy.c) | `FUN_a00d8fdc` | Answer the MST request 0x24 (POWER_UP_PHY). | proven |
| [`dp_mst_handle_query_stream_enc_status`](../../src/leon2s/dp/dp_mst_handle_query_stream_enc_status.c) | `FUN_a00d90dc` | Answer the MST request 0x38 (QUERY_STREAM_ENC_STATUS). | proven |
| [`dp_mst_handle_remote_dpcd_read`](../../src/leon2s/dp/dp_mst_handle_remote_dpcd_read.c) | `FUN_a00d87fc` | Answer the MST request 0x20 (REMOTE_DPCD_READ). | proven |
| [`dp_mst_handle_remote_dpcd_write`](../../src/leon2s/dp/dp_mst_handle_remote_dpcd_write.c) | `FUN_a00d8b90` | Answer the MST request 0x21 (REMOTE_DPCD_WRITE). | proven |
| [`dp_mst_handle_remote_i2c_read`](../../src/leon2s/dp/dp_mst_handle_remote_i2c_read.c) | `FUN_a00d8d20` | Answer the MST request 0x22 (REMOTE_I2C_READ). | proven |
| [`dp_mst_handle_remote_i2c_write`](../../src/leon2s/dp/dp_mst_handle_remote_i2c_write.c) | `FUN_a00d8f58` | Answer the MST request 0x23 (REMOTE_I2C_WRITE). | proven |
| [`dp_mst_is_record_changed`](../../src/leon2s/dp/dp_mst_is_record_changed.c) | `FUN_a00da9e8` | Return whether a table byte selected by the record differs from the record. | descriptive |
| [`dp_mst_is_reply_unmatched`](../../src/leon2s/dp/dp_mst_is_reply_unmatched.c) | `FUN_a00da288` | Return 1 when the waiting reply's request number differs from the last request noted for it. | derived |
| [`dp_mst_notify_task`](../../src/leon2s/dp/dp_mst_notify_task.c) | `FUN_a00dbc8c` | Step the three-state notification sequence, retrying after a time-out. | descriptive |
| [`dp_mst_pack_19_byte_record`](../../src/leon2s/dp/dp_mst_pack_19_byte_record.c) | `FUN_a00d7648` | Pack the 19-byte descriptor into the byte stream of an MST reply. | descriptive |
| [`dp_mst_pack_24_byte_record`](../../src/leon2s/dp/dp_mst_pack_24_byte_record.c) | `FUN_a00d787c` | Pack the 24-byte record into the byte stream of an MST reply. | descriptive |
| [`dp_mst_pack_allocate_payload_reply`](../../src/leon2s/dp/dp_mst_pack_allocate_payload_reply.c) | `FUN_a00d76f4` | Pack the payload allocation reply into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_byte_run`](../../src/leon2s/dp/dp_mst_pack_byte_run.c) | `FUN_a00d78d8` | Pack the run of bytes into the byte stream of an MST reply. | descriptive |
| [`dp_mst_pack_dpcd_read_reply`](../../src/leon2s/dp/dp_mst_pack_dpcd_read_reply.c) | `FUN_a00d7744` | Pack the remote DPCD read reply into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_enum_path_reply`](../../src/leon2s/dp/dp_mst_pack_enum_path_reply.c) | `FUN_a00d76ac` | Pack the path resources reply into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_header`](../../src/leon2s/dp/dp_mst_pack_header.c) | `FUN_a00d68cc` | Pack the header of an MST message chunk and add its 4-bit checksum. | proven |
| [`dp_mst_pack_i2c_read_reply`](../../src/leon2s/dp/dp_mst_pack_i2c_read_reply.c) | `FUN_a00d77c4` | Pack the remote I2C read reply into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_link_address_reply`](../../src/leon2s/dp/dp_mst_pack_link_address_reply.c) | `FUN_a00d74ec` | Pack the link address reply into the byte stream of an MST reply. | proven |
| [`dp_mst_pack_port_reply`](../../src/leon2s/dp/dp_mst_pack_port_reply.c) | `FUN_a00d77a8` | Pack the port-only reply into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_port_reply_copy`](../../src/leon2s/dp/dp_mst_pack_port_reply_copy.c) | `FUN_a00d7828` | Pack the port-only reply into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_port_reply_high`](../../src/leon2s/dp/dp_mst_pack_port_reply_high.c) | `FUN_a00d7844` | Pack the port-only reply with the port in the upper nibble into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_port_reply_high_copy`](../../src/leon2s/dp/dp_mst_pack_port_reply_high_copy.c) | `FUN_a00d7860` | Pack the port-only reply with the port in the upper nibble into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_request_number`](../../src/leon2s/dp/dp_mst_pack_request_number.c) | `FUN_a00d7638` | Pack the request number into the byte stream of an MST reply. | derived |
| [`dp_mst_pack_request_number_copy`](../../src/leon2s/dp/dp_mst_pack_request_number_copy.c) | `FUN_a00d7734` | Pack the request number into the byte stream of an MST reply. | derived |
| [`dp_mst_parse_chunk_header`](../../src/leon2s/dp/dp_mst_parse_chunk_header.c) | `FUN_a00d6890` | Unpack the header of a received chunk when it starts a message. | derived |
| [`dp_mst_parse_request`](../../src/leon2s/dp/dp_mst_parse_request.c) | `FUN_a00d73b4` | Unpack the body of a received MST request by its request type. | proven |
| [`dp_mst_queue_chunk`](../../src/leon2s/dp/dp_mst_queue_chunk.c) | `FUN_a00d6a54` | Pack a chunk header and store it in the reply header ring (queue 1) or the forward ring (queue 3). | derived |
| [`dp_mst_queue_clear_payload_table_request`](../../src/leon2s/dp/dp_mst_queue_clear_payload_table_request.c) | `FUN_a00d9a78` | Queue a CLEAR_PAYLOAD_ID_TABLE request (0x14) of its own making in the forward ring. | derived |
| [`dp_mst_queue_fixed_up_message`](../../src/leon2s/dp/dp_mst_queue_fixed_up_message.c) | `FUN_a00db9d4` | Queue a message with fixed header fields. | descriptive |
| [`dp_mst_queue_reply_header`](../../src/leon2s/dp/dp_mst_queue_reply_header.c) | `FUN_a00d9524` | Build the reply header from a received message header and store it in the reply header ring. | derived |
| [`dp_mst_queue_short_message`](../../src/leon2s/dp/dp_mst_queue_short_message.c) | `FUN_a00d97bc` | Copy a header, lower its low nibble by one, drop its first address nibble and queue it. | descriptive |
| [`dp_mst_read_payload_words`](../../src/leon2s/dp/dp_mst_read_payload_words.c) | `FUN_a00b1394` | Wait for the ready flag and read 63 words of the payload table from the hardware. | descriptive |
| [`dp_mst_receive_task`](../../src/leon2s/dp/dp_mst_receive_task.c) | `FUN_a00d9be4` | Take the first chunk of a complete received message, dispatch or pass it on, and skip the message. | derived |
| [`dp_mst_reset_port`](../../src/leon2s/dp/dp_mst_reset_port.c) | `FUN_a00dc0a8` | Clear the MST service's records for a port and print a line. | descriptive |
| [`dp_mst_select_port`](../../src/leon2s/dp/dp_mst_select_port.c) | `FUN_a00dc264` | Store the port that the MST service works on. | descriptive |
| [`dp_mst_send_down_reply_step`](../../src/leon2s/dp/dp_mst_send_down_reply_step.c) | `FUN_a00da49c` | Send the next chunk of a down reply and raise the ready bit. | derived |
| [`dp_mst_send_nak`](../../src/leon2s/dp/dp_mst_send_nak.c) | `FUN_a00d9474` | Answer an unsupported MST request with a refusal that carries the device's 16-byte id. | proven |
| [`dp_mst_send_reply`](../../src/leon2s/dp/dp_mst_send_reply.c) | `FUN_a00d791c` | Build the reply body for a request type and queue it as a down reply. | derived |
| [`dp_mst_send_status_message`](../../src/leon2s/dp/dp_mst_send_status_message.c) | `FUN_a00dba70` | Build a message from 16 register bytes and two status reads and send it. | descriptive |
| [`dp_mst_send_up_message_step`](../../src/leon2s/dp/dp_mst_send_up_message_step.c) | `FUN_a00daa98` | Send the next message fetched from the output (down reply or up request) on to the source. | derived |
| [`dp_mst_set_enable`](../../src/leon2s/dp/dp_mst_set_enable.c) | `FUN_a00dc040` | Store the MST service's enable byte and clear four state bytes when it is 0. | descriptive |
| [`dp_mst_set_flag_6099`](../../src/leon2s/dp/dp_mst_set_flag_6099.c) | `FUN_a00dc034` | Store the flag byte at 0xA8076099. | descriptive |
| [`dp_mst_set_option_byte`](../../src/leon2s/dp/dp_mst_set_option_byte.c) | `FUN_a00dc078` | Store the MST service's option byte. | descriptive |
| [`dp_mst_set_option_word`](../../src/leon2s/dp/dp_mst_set_option_word.c) | `FUN_a00d66b0` | Store the MST option value received from the main processor. | descriptive |
| [`dp_mst_set_reply_ready`](../../src/leon2s/dp/dp_mst_set_reply_ready.c) | `FUN_a00d7bf8` | Write bit 3 of control word 0xF7 while it still reads as set, then set bit 7 of word 0x30. | descriptive |
| [`dp_mst_task`](../../src/leon2s/dp/dp_mst_task.c) | `FUN_a00dc214` | Run the MST message service once: receive, transmit and, for port 0, forwarding. | descriptive |
| [`dp_mst_transmit_task`](../../src/leon2s/dp/dp_mst_transmit_task.c) | `FUN_a00dac08` | Run the transmit side: send replies and up messages chunk by chunk, with time-outs. | derived |
| [`dp_mst_trim_up_message_record`](../../src/leon2s/dp/dp_mst_trim_up_message_record.c) | `FUN_a00da6ac` | Write a stored message from the output to the port's registers, its address part shortened by one. | derived |
| [`dp_mst_unpack_10_byte_record`](../../src/leon2s/dp/dp_mst_unpack_10_byte_record.c) | `FUN_a00d72d8` | Unpack the 10-byte record from a received MST message. | descriptive |
| [`dp_mst_unpack_19_byte_record`](../../src/leon2s/dp/dp_mst_unpack_19_byte_record.c) | `FUN_a00d6b98` | Unpack the 19-byte record from a received MST message. | descriptive |
| [`dp_mst_unpack_allocate_payload`](../../src/leon2s/dp/dp_mst_unpack_allocate_payload.c) | `FUN_a00d6cfc` | Unpack the payload allocation fields from a received MST message. | derived |
| [`dp_mst_unpack_dpcd_read`](../../src/leon2s/dp/dp_mst_unpack_dpcd_read.c) | `FUN_a00d6df8` | Unpack the remote DPCD read fields from a received MST message. | derived |
| [`dp_mst_unpack_dpcd_write`](../../src/leon2s/dp/dp_mst_unpack_dpcd_write.c) | `FUN_a00d6e94` | Unpack the remote DPCD write fields from a received MST message. | derived |
| [`dp_mst_unpack_header`](../../src/leon2s/dp/dp_mst_unpack_header.c) | `FUN_a00d6724` | Unpack the header of an MST message chunk. | proven |
| [`dp_mst_unpack_i2c_read`](../../src/leon2s/dp/dp_mst_unpack_i2c_read.c) | `FUN_a00d6f70` | Unpack the remote I2C read fields from a received MST message. | derived |
| [`dp_mst_unpack_i2c_write`](../../src/leon2s/dp/dp_mst_unpack_i2c_write.c) | `FUN_a00d714c` | Unpack the remote I2C write fields from a received MST message. | derived |
| [`dp_mst_unpack_port_byte`](../../src/leon2s/dp/dp_mst_unpack_port_byte.c) | `FUN_a00d6b4c` | Unpack the port number byte from a received MST message. | descriptive |
| [`dp_mst_unpack_port_pair`](../../src/leon2s/dp/dp_mst_unpack_port_pair.c) | `FUN_a00d7210` | Unpack the two-byte port setting from a received MST message. | descriptive |
| [`dp_mst_unpack_port_pair_copy`](../../src/leon2s/dp/dp_mst_unpack_port_pair_copy.c) | `FUN_a00d7274` | Unpack the two-byte port setting from a received MST message. | descriptive |
| [`dp_mst_unpack_seven_bit_value`](../../src/leon2s/dp/dp_mst_unpack_seven_bit_value.c) | `FUN_a00d6dac` | Unpack the 7-bit value from a received MST message. | descriptive |
| [`dp_mst_unpack_two_byte_fields`](../../src/leon2s/dp/dp_mst_unpack_two_byte_fields.c) | `FUN_a00d6c98` | Unpack the two packed bytes from a received MST message. | descriptive |
| [`dp_mst_update_payload_table`](../../src/leon2s/dp/dp_mst_update_payload_table.c) | `FUN_a00dae90` | Read the payload table, list each stream's id, start and count, pass one change to the output. | derived |
| [`dp_mst_wait_downstream_ready`](../../src/leon2s/dp/dp_mst_wait_downstream_ready.c) | `FUN_a00d64ec` | Wait, in up to ten tries, until the output reports that it has taken the message. | derived |
| [`dp_mst_write_chunk_body`](../../src/leon2s/dp/dp_mst_write_chunk_body.c) | `FUN_a00da030` | Write the next body bytes of the outgoing message and their checksum to the port's registers. | derived |
| [`dp_mst_write_chunk_header`](../../src/leon2s/dp/dp_mst_write_chunk_header.c) | `FUN_a00d9edc` | Build the header of the next outgoing chunk and write it to the port's registers. | descriptive |
| [`dp_mst_write_record_tail`](../../src/leon2s/dp/dp_mst_write_record_tail.c) | `FUN_a00da838` | Copy the remaining bytes of the current record to the port's registers. | descriptive |
| [`dp_paged_reg_read8`](../../src/leon2s/dp/dp_paged_reg_read8.c) | `FUN_a00a74b8` | Read a paged register of a DP receiver through the register window. | derived |
| [`dp_paged_reg_update_bits`](../../src/leon2s/dp/dp_paged_reg_update_bits.c) | `FUN_a00a7718` | Set or clear masked bits of a paged DP receiver register. | derived |
| [`dp_paged_reg_write8`](../../src/leon2s/dp/dp_paged_reg_write8.c) | `FUN_a00a7614` | Write a byte to a paged register of DP receiver 0 or 1 through the page-select registers. | derived |
| [`dp_port_task`](../../src/leon2s/dp/dp_port_task.c) | `FUN_a00b0738` | Run the service of the DisplayPort inputs once: status, test requests and time-outs. | derived |
| [`dp_probe_selector_levels`](../../src/leon2s/dp/dp_probe_selector_levels.c) | `FUN_a00af524` | Probe a status register for five selector values and return a 2-bit result. | descriptive |
| [`dp_program_port`](../../src/leon2s/dp/dp_program_port.c) | `FUN_a00abff0` | Write the full register set-up of a DP receiver from its port record. | derived |
| [`dp_pulse_hpd_block`](../../src/leon2s/dp/dp_pulse_hpd_block.c) | `FUN_a00acff4` | Pulse bit 1 of register 0xCF0132C0 and apply a per-port follow-up. | descriptive |
| [`dp_pulse_pll_unit_reg3`](../../src/leon2s/dp/dp_pulse_pll_unit_reg3.c) | `FUN_a008b914` | Pulse bit 2 of register 3 of PLL unit 4 (DP receiver 0) or unit 6 (any other receiver). | descriptive |
| [`dp_pulse_reg20_bit3`](../../src/leon2s/dp/dp_pulse_reg20_bit3.c) | `FUN_a00ad734` | Pulse bit 3 of register 0x20 of a port. | descriptive |
| [`dp_pulse_reg30e_clear`](../../src/leon2s/dp/dp_pulse_reg30e_clear.c) | `FUN_a00d6560` | Clear register 0x30E of a port inside a pulse of bit 7 of register 0x30. | descriptive |
| [`dp_pulse_reg487_bit2`](../../src/leon2s/dp/dp_pulse_reg487_bit2.c) | `FUN_a00b1350` | Pulse bit 2 of register 0x487 of a port. | descriptive |
| [`dp_read_lane_status`](../../src/leon2s/dp/dp_read_lane_status.c) | `FUN_a0085684` | Read the lane status register 0x40A of a DP receiver. | descriptive |
| [`dp_read_reg3d0_value`](../../src/leon2s/dp/dp_read_reg3d0_value.c) | `FUN_a00ac620` | Return the 24-bit value of DP receiver registers 0x3D0..0x3D2. | descriptive |
| [`dp_read_reg90_word`](../../src/leon2s/dp/dp_read_reg90_word.c) | `FUN_a00acb40` | Return the 16-bit value of register 0x90 of a port. | descriptive |
| [`dp_read_reg92_word`](../../src/leon2s/dp/dp_read_reg92_word.c) | `FUN_a00acb60` | Return the 16-bit value of register 0x92 of a port. | descriptive |
| [`dp_read_reg34400_bit0`](../../src/leon2s/dp/dp_read_reg34400_bit0.c) | `FUN_a00aba4c` | Return bit 0 of register 0xCF034400. | descriptive |
| [`dp_read_slice_count`](../../src/leon2s/dp/dp_read_slice_count.c) | `FUN_a00af1e8` | Return the slice count of a port's DSC stream: the quotient of two 16-bit stream values. | proven |
| [`dp_read_status_block`](../../src/leon2s/dp/dp_read_status_block.c) | `FUN_a00ae5e4` | Read a port's queued status bytes and run a register 0x24 bit sequence for three known patterns. | descriptive |
| [`dp_reg_read8`](../../src/leon2s/dp/dp_reg_read8.c) | `FUN_a00a6bb8` | Read a byte register of a DP receiver. | proven |
| [`dp_reg_read16`](../../src/leon2s/dp/dp_reg_read16.c) | `FUN_a00a6da8` | Read a 16-bit value from two byte registers of a DP receiver. | proven |
| [`dp_reg_read16_stable`](../../src/leon2s/dp/dp_reg_read16_stable.c) | `FUN_a00a6e8c` | Read a 16-bit DP receiver value until two reads agree. | proven |
| [`dp_reg_read24`](../../src/leon2s/dp/dp_reg_read24.c) | `FUN_a00a6e10` | Read a 24-bit value from three byte registers of a DP receiver. | proven |
| [`dp_reg_read24_stable`](../../src/leon2s/dp/dp_reg_read24_stable.c) | `FUN_a00a6f08` | Read a DP receiver value of three registers until two reads agree (low 16 bits). | proven |
| [`dp_reg_update_bits`](../../src/leon2s/dp/dp_reg_update_bits.c) | `FUN_a00a6c98` | Set or clear masked bits of a byte register of one or both DP receivers. | proven |
| [`dp_reg_write8`](../../src/leon2s/dp/dp_reg_write8.c) | `FUN_a00a6c00` | Write a byte register of one or both DP receivers. | proven |
| [`dp_reprogram_clock_registers`](../../src/leon2s/dp/dp_reprogram_clock_registers.c) | `FUN_a00ad0c4` | Recompute a port's clock value and rewrite its registers 0x45 / 0x47. | descriptive |
| [`dp_reset_port`](../../src/leon2s/dp/dp_reset_port.c) | `FUN_a00afbbc` | Reset a DisplayPort input and apply its settings again. | derived |
| [`dp_reset_port_logic`](../../src/leon2s/dp/dp_reset_port_logic.c) | `FUN_a00aba5c` | Pulse the reset and option bits of a DP receiver (registers 0x3E, 0xF7, 0x20). | descriptive |
| [`dp_reset_receiver_flags`](../../src/leon2s/dp/dp_reset_receiver_flags.c) | `FUN_a00d649c` | Clear the receiver's status flags and pulse two reset bits. | descriptive |
| [`dp_run_link_state`](../../src/leon2s/dp/dp_run_link_state.c) | `DP_GetClrSpace` | Run one step of the DisplayPort receiver link state machine for one port. | proven |
| `dp_run_link_state_jump_table` | `switchdataD_a006ed40` | Jump table 1 of the switch statements in dp_run_link_state. | proven |
| [`dp_select_lane_mask`](../../src/leon2s/dp/dp_select_lane_mask.c) | `FUN_a00af764` | Select the lane mask of a port from its lane mapping. | descriptive |
| [`dp_set_bank_registers`](../../src/leon2s/dp/dp_set_bank_registers.c) | `FUN_a00b12cc` | Write a pair of bank registers depending on a per-port test. | descriptive |
| [`dp_set_clock_divider`](../../src/leon2s/dp/dp_set_clock_divider.c) | `FUN_a00aee08` | Write a 16-bit value and an n-bit mask to the clock registers of a port. | descriptive |
| [`dp_set_dsc_4_slices_option`](../../src/leon2s/dp/dp_set_dsc_4_slices_option.c) | `FUN_a00b14dc` | Store the 'DSC 3440 4 slices' option byte and print it with the port number. | proven |
| [`dp_set_lane_option_bit`](../../src/leon2s/dp/dp_set_lane_option_bit.c) | `FUN_a00857d0` | Set or clear bit 2 of the four lane registers of a DP receiver. | descriptive |
| [`dp_set_lane_switches`](../../src/leon2s/dp/dp_set_lane_switches.c) | `FUN_a0084c94` | Set the four per-lane on/off switches of a DP receiver from a mask. | descriptive |
| [`dp_set_mode_registers`](../../src/leon2s/dp/dp_set_mode_registers.c) | `FUN_a00b115c` | Write the register values for mode 0, 1 or 2 of a DisplayPort block. | descriptive |
| [`dp_set_port0_setting_112`](../../src/leon2s/dp/dp_set_port0_setting_112.c) | `FUN_a00afd74` | Store a setting byte of port 0 and apply the port's settings again. | descriptive |
| [`dp_set_port_control_bit`](../../src/leon2s/dp/dp_set_port_control_bit.c) | `FUN_a00af858` | Set or clear the port's bit in control register 0xCF012448. | descriptive |
| [`dp_set_port_enable_bits`](../../src/leon2s/dp/dp_set_port_enable_bits.c) | `FUN_a0083f04` | Set or clear the four enable bits of a DP receiver. | descriptive |
| [`dp_set_port_event_bit`](../../src/leon2s/dp/dp_set_port_event_bit.c) | `FUN_a00b1470` | Set the bit of a port in the event register 0xCF03C894. | descriptive |
| [`dp_set_port_flag_bit`](../../src/leon2s/dp/dp_set_port_flag_bit.c) | `FUN_a00ab884` | Set or clear one bit of the DP port flag byte. | descriptive |
| [`dp_set_port_record_byte_125`](../../src/leon2s/dp/dp_set_port_record_byte_125.c) | `FUN_a00b0454` | Store byte 0x125 of a DisplayPort input's record. | descriptive |
| [`dp_set_port_setting_11e`](../../src/leon2s/dp/dp_set_port_setting_11e.c) | `CONV2HDMITX_UpdateInterface_2` | Write a setting to register 0x21d of a port and print it, only when record byte 0x11e is non-zero. | descriptive |
| [`dp_set_port_setting_115`](../../src/leon2s/dp/dp_set_port_setting_115.c) | `FUN_a00afd04` | Store a setting byte of a port and apply the port's settings again. | descriptive |
| [`dp_set_port_setting_116`](../../src/leon2s/dp/dp_set_port_setting_116.c) | `FUN_a00afd3c` | Store a setting byte of a port and apply the port's settings again. | descriptive |
| [`dp_set_port_swap`](../../src/leon2s/dp/dp_set_port_swap.c) | `FUN_a0083e34` | Set or clear the DP receiver port swap. | descriptive |
| [`dp_set_reg2a8_mode`](../../src/leon2s/dp/dp_set_reg2a8_mode.c) | `FUN_a00c6760` | Write the mode registers at 0x2A8 of a DisplayPort block by an on/off flag. | descriptive |
| [`dp_set_reg3_bit5`](../../src/leon2s/dp/dp_set_reg3_bit5.c) | `FUN_a00add0c` | Set or clear bit 5 of register 3 of a port. | descriptive |
| [`dp_set_reg3a_bit6`](../../src/leon2s/dp/dp_set_reg3a_bit6.c) | `FUN_a00b1450` | Set bit 6 of register 0x3A of a port. | descriptive |
| [`dp_set_reg9f_field`](../../src/leon2s/dp/dp_set_reg9f_field.c) | `FUN_a00d65a0` | Write the 2-bit field at bits 6-7 of register 0x9F of a port. | descriptive |
| [`dp_set_reg30_bit6`](../../src/leon2s/dp/dp_set_reg30_bit6.c) | `FUN_a00ae1c0` | Set bit 6 of register 0x30 of a port while bit 5 of register 0 is cleared, then restore register 0. | descriptive |
| [`dp_set_reg40_bit7`](../../src/leon2s/dp/dp_set_reg40_bit7.c) | `FUN_a00ae378` | Set bit 7 of register 0x40 of a port. | descriptive |
| [`dp_set_reg40_bits_6_7`](../../src/leon2s/dp/dp_set_reg40_bits_6_7.c) | `FUN_a00ae344` | Set bits 6 and 7 of register 0x40 of a port and the low bits of register 0x44. | descriptive |
| [`dp_set_reg44_high_bits`](../../src/leon2s/dp/dp_set_reg44_high_bits.c) | `FUN_a00ae254` | Write bits 4..7 of a value to register 0x44 and set bit 4 of register 0x40 when any of them is set. | descriptive |
| [`dp_set_reg44_low_bits`](../../src/leon2s/dp/dp_set_reg44_low_bits.c) | `FUN_a00ad09c` | Set the low two bits of register 0x44 of a port. | descriptive |
| [`dp_set_reg55_bits`](../../src/leon2s/dp/dp_set_reg55_bits.c) | `FUN_a00b1224` | Write bits 6 and 4 of register 0x55 by a mode 0..2. | descriptive |
| [`dp_set_reg226_bit2`](../../src/leon2s/dp/dp_set_reg226_bit2.c) | `FUN_a00ad6cc` | Set bit 2 of register 0x226 of a port. | descriptive |
| [`dp_set_reg1143c_bits`](../../src/leon2s/dp/dp_set_reg1143c_bits.c) | `FUN_a00abba8` | Set bits 0..2 of register 0xCF01143C. | descriptive |
| [`dp_set_regs_c5_c4`](../../src/leon2s/dp/dp_set_regs_c5_c4.c) | `FUN_a00aea3c` | Write registers 0xC5 and 0xC4 of a port. | descriptive |
| [`dp_set_service_flag`](../../src/leon2s/dp/dp_set_service_flag.c) | `FUN_a00ad054` | Store the service flag byte at 0xA8079313. | descriptive |
| [`dp_set_unit_format_field`](../../src/leon2s/dp/dp_set_unit_format_field.c) | `FUN_a00adf84` | Write the 2-bit format field of the unit a port is mapped to. | descriptive |
| [`dp_set_unit_route_field`](../../src/leon2s/dp/dp_set_unit_route_field.c) | `FUN_a00add8c` | Write the 2-bit route field of the unit a port is mapped to and note it in a mask. | descriptive |
| [`dp_setup_port_regs`](../../src/leon2s/dp/dp_setup_port_regs.c) | `FUN_a00ac66c` | Write the fixed register set-up of a DP receiver port. | derived |
| [`dp_setup_service_block`](../../src/leon2s/dp/dp_setup_service_block.c) | `FUN_a00ad478` | Write the service block registers with a factor of 1 or 8 and update the service flags. | descriptive |
| [`dp_start_port`](../../src/leon2s/dp/dp_start_port.c) | `FUN_a00b05e8` | Start a DisplayPort input: reset it, set it up and switch its interrupts on. | derived |
| [`dp_start_stream`](../../src/leon2s/dp/dp_start_stream.c) | `FUN_a00afeb8` | Start the reception of a port's stream, optionally from scratch. | derived |
| [`dp_status_reg_read8`](../../src/leon2s/dp/dp_status_reg_read8.c) | `FUN_a00a6f78` | Read a byte register of a DP receiver status block. | derived |
| [`dp_status_reg_update_bits`](../../src/leon2s/dp/dp_status_reg_update_bits.c) | `FUN_a00a7058` | Set or clear masked bits of a byte register of one or both DP receiver status blocks. | derived |
| [`dp_status_reg_write8`](../../src/leon2s/dp/dp_status_reg_write8.c) | `FUN_a00a6fc0` | Write a byte register of one or both DP receiver status blocks. | derived |
| [`dp_stop_port`](../../src/leon2s/dp/dp_stop_port.c) | `FUN_a00b0568` | Stop a DisplayPort input that is active: interrupts off and its blocks reset. | derived |
| [`dp_store_port_register_value`](../../src/leon2s/dp/dp_store_port_register_value.c) | `FUN_a00b04a8` | Read the 16-bit registers 0x94, 0x96, 0x98 and 0x9A of a port and store them in its record. | descriptive |
| [`dp_toggle_status_bit`](../../src/leon2s/dp/dp_toggle_status_bit.c) | `FUN_a00af464` | Bring bit 0 of register 0x461 of a port to the state given by a flag, changing it only if it differs. | descriptive |
| [`dp_tx_aux_read_byte`](../../src/leon2s/dp/dp_tx_aux_read_byte.c) | `FUN_a008639c` | Read one byte from a sink register over AUX. | derived |
| [`dp_tx_aux_read_reply`](../../src/leon2s/dp/dp_tx_aux_read_reply.c) | `FUN_a0086154` | Collect the AUX reply bytes and check the reply code. | derived |
| [`dp_tx_aux_request`](../../src/leon2s/dp/dp_tx_aux_request.c) | `FUN_a00863d4` | Run an AUX transaction (byte-sized arguments). | derived |
| [`dp_tx_aux_request_copy`](../../src/leon2s/dp/dp_tx_aux_request_copy.c) | `FUN_a0086400` | Run an AUX transaction (byte-sized arguments). | derived |
| [`dp_tx_aux_send_request`](../../src/leon2s/dp/dp_tx_aux_send_request.c) | `FUN_a0086030` | Write an AUX request (command, address, length, data) and start it. | derived |
| [`dp_tx_aux_transfer`](../../src/leon2s/dp/dp_tx_aux_transfer.c) | `FUN_a00862e4` | Run an AUX transaction with up to 10 attempts. | derived |
| [`dp_tx_aux_write_byte`](../../src/leon2s/dp/dp_tx_aux_write_byte.c) | `FUN_a0086360` | Write one byte to a sink register over AUX. | derived |
| [`dp_tx_calc_pixel_clock`](../../src/leon2s/dp/dp_tx_calc_pixel_clock.c) | `FUN_a0089898` | Compute the pixel clock of a DP output from its M/N values and link rate. | derived |
| [`dp_tx_check_caps_byte1`](../../src/leon2s/dp/dp_tx_check_caps_byte1.c) | `FUN_a0087074` | Compare byte 1 of a DP output's sink caps record. | descriptive |
| [`dp_tx_check_channel_eq`](../../src/leon2s/dp/dp_tx_check_channel_eq.c) | `FUN_a0087364` | Return the training result code from the lane status bytes. | derived |
| [`dp_tx_check_clock_recovery`](../../src/leon2s/dp/dp_tx_check_clock_recovery.c) | `FUN_a00870a4` | Return whether clock recovery is done on the active lanes. | derived |
| [`dp_tx_check_level_crossing`](../../src/leon2s/dp/dp_tx_check_level_crossing.c) | `FUN_a0088fec` | Report when a measured level crosses 40 in either direction. | descriptive |
| [`dp_tx_check_training_lost`](../../src/leon2s/dp/dp_tx_check_training_lost.c) | `FUN_a0088c5c` | Check the trained outputs and return 1 at the first output that lost its link, else 0. | proven |
| [`dp_tx_choose_link_config`](../../src/leon2s/dp/dp_tx_choose_link_config.c) | `FUN_a0086c48` | Choose link rate and lane count from the sink caps and the configured limits. | derived |
| [`dp_tx_clear_caps_valid`](../../src/leon2s/dp/dp_tx_clear_caps_valid.c) | `FUN_a00866b8` | Clear the valid bit of a DP output's sink capability record. | descriptive |
| [`dp_tx_ctl_reg_read8`](../../src/leon2s/dp/dp_tx_ctl_reg_read8.c) | `FUN_a00a7acc` | Read a byte register of a DP / eDP transmitter control bank. | derived |
| [`dp_tx_ctl_reg_update_bits`](../../src/leon2s/dp/dp_tx_ctl_reg_update_bits.c) | `FUN_a00a7bf8` | Set or clear masked bits of a byte register of a DP / eDP transmitter control bank. | derived |
| [`dp_tx_ctl_reg_write8`](../../src/leon2s/dp/dp_tx_ctl_reg_write8.c) | `FUN_a00a7b64` | Write a byte register of a DP / eDP transmitter control bank. | derived |
| [`dp_tx_edp_run_hpd_actions`](../../src/leon2s/dp/dp_tx_edp_run_hpd_actions.c) | `eDP_IsHPDAction_Off` | Handle plug, unplug and IRQ events of the eDP outputs. | proven |
| [`dp_tx_force_hpd_check`](../../src/leon2s/dp/dp_tx_force_hpd_check.c) | `FUN_a0088fd4` | Make the next HPD pass treat one DP output as freshly plugged. | derived |
| [`dp_tx_get_ctl_state_code`](../../src/leon2s/dp/dp_tx_get_ctl_state_code.c) | `FUN_a00aa7cc` | Return a small code (0..5, 7) decoded from a control register of a DP output. | descriptive |
| [`dp_tx_get_hpd_event_bits`](../../src/leon2s/dp/dp_tx_get_hpd_event_bits.c) | `FUN_a0083710` | Return the three event bits recorded for a link output. | descriptive |
| `dp_tx_get_hpd_event_bits_jump_table` | `switchdataD_a00836f4` | Jump table 1 of the switch statements in dp_tx_get_hpd_event_bits. | proven |
| [`dp_tx_get_hpd_pulse`](../../src/leon2s/dp/dp_tx_get_hpd_pulse.c) | `FUN_a008899c` | Return 1 or 2 from the first two hot-plug event bits of an output. | descriptive |
| [`dp_tx_get_hpd_status`](../../src/leon2s/dp/dp_tx_get_hpd_status.c) | `FUN_a0083e28` | Return the hot-plug status byte of the link outputs. | derived |
| [`dp_tx_get_link_state`](../../src/leon2s/dp/dp_tx_get_link_state.c) | `FUN_a0086bd8` | Return the link state (0..4) from the DP output status registers. | descriptive |
| [`dp_tx_get_max_adjust_request`](../../src/leon2s/dp/dp_tx_get_max_adjust_request.c) | `FUN_a0086fb0` | Return the highest adjust request over the lanes. | descriptive |
| [`dp_tx_get_mode_flag`](../../src/leon2s/dp/dp_tx_get_mode_flag.c) | `FUN_a00866a4` | Return bit 29 of the first path record's mode word. | descriptive |
| [`dp_tx_get_path_bits_per_colour`](../../src/leon2s/dp/dp_tx_get_path_bits_per_colour.c) | `FUN_a00876ec` | Return the bits per colour (byte 0x15) of a video path record. | derived |
| [`dp_tx_get_path_byte20`](../../src/leon2s/dp/dp_tx_get_path_byte20.c) | `FUN_a0087710` | Return byte 20 of a video path record. | descriptive |
| [`dp_tx_get_path_option`](../../src/leon2s/dp/dp_tx_get_path_option.c) | `FUN_a0086678` | Return bit 15 of the option word of a video path. | descriptive |
| [`dp_tx_get_reg70_bit4`](../../src/leon2s/dp/dp_tx_get_reg70_bit4.c) | `FUN_a0088f28` | Return bit 4 of register 0x70 of a DP output. | descriptive |
| [`dp_tx_get_status_byte`](../../src/leon2s/dp/dp_tx_get_status_byte.c) | `FUN_a0088f84` | Return a DP output status byte published to the main processor. | descriptive |
| [`dp_tx_handle_test_request`](../../src/leon2s/dp/dp_tx_handle_test_request.c) | `FUN_a00883d0` | Answer a sink's automated test request (link training test). | derived |
| `dp_tx_handle_test_request_jump_table` | `switchdataD_a00883b4` | Jump table 1 of the switch statements in dp_tx_handle_test_request. | proven |
| [`dp_tx_hpd_event_bit2`](../../src/leon2s/dp/dp_tx_hpd_event_bit2.c) | `FUN_a0088a80` | Return whether hot-plug event bit 2 of an output is set. | descriptive |
| [`dp_tx_hpd_is_low`](../../src/leon2s/dp/dp_tx_hpd_is_low.c) | `FUN_a0083648` | Return whether the hot-plug line of a link output is low. | descriptive |
| `dp_tx_hpd_is_low_jump_table` | `switchdataD_a008362c` | Jump table 1 of the switch statements in dp_tx_hpd_is_low. | proven |
| [`dp_tx_hpd_option_stub`](../../src/leon2s/dp/dp_tx_hpd_option_stub.c) | `FUN_a0089420` | Return 0 (an HPD option that is switched off in this build). | descriptive |
| [`dp_tx_hpd_option_stub_copy`](../../src/leon2s/dp/dp_tx_hpd_option_stub_copy.c) | `FUN_a00aa7bc` | Return 0; dp_tx_init_ports skips the set-up of DP output 0 when this is non-zero. | descriptive |
| [`dp_tx_hpd_option_stub_copy2`](../../src/leon2s/dp/dp_tx_hpd_option_stub_copy2.c) | `FUN_a00aa7c4` | Return 0; dp_tx_init_ports skips the set-up of a DP output 1..4 when this is non-zero. | descriptive |
| [`dp_tx_hpd_option_stub_copy3`](../../src/leon2s/dp/dp_tx_hpd_option_stub_copy3.c) | `FUN_a00b12c4` | Return 0 (an HPD option that is switched off in this build). | descriptive |
| [`dp_tx_init_ctl_banks`](../../src/leon2s/dp/dp_tx_init_ctl_banks.c) | `FUN_a00aa3a4` | Write the start-up values of a DP / eDP transmitter control bank. | derived |
| [`dp_tx_init_port_extra_regs`](../../src/leon2s/dp/dp_tx_init_port_extra_regs.c) | `FUN_a0085b14` | Write the remaining fixed start-up registers of a DP output. | descriptive |
| [`dp_tx_init_port_link_regs`](../../src/leon2s/dp/dp_tx_init_port_link_regs.c) | `FUN_a0085b80` | Write the start-up link registers of a DP output and store its default limits. | derived |
| [`dp_tx_init_port_phy`](../../src/leon2s/dp/dp_tx_init_port_phy.c) | `FUN_a0085dcc` | Set up the PHY power and drive registers of a DP output. | descriptive |
| [`dp_tx_init_ports`](../../src/leon2s/dp/dp_tx_init_ports.c) | `FUN_a0085ea8` | Initialise the five DP outputs and their PHYs at start-up. | derived |
| [`dp_tx_init_sink_caps`](../../src/leon2s/dp/dp_tx_init_sink_caps.c) | `FUN_a00866e0` | Fill the sink capability records of the embedded DP outputs with defaults and two reads. | derived |
| [`dp_tx_is_connected`](../../src/leon2s/dp/dp_tx_is_connected.c) | `FUN_a0088af0` | Return whether the hot-plug line of an output is high. | derived |
| [`dp_tx_is_link_active`](../../src/leon2s/dp/dp_tx_is_link_active.c) | `FUN_a0088ea0` | Return whether an output is connected and its link is in the running state. | descriptive |
| [`dp_tx_mode_requested_0`](../../src/leon2s/dp/dp_tx_mode_requested_0.c) | `FUN_a0070424` | Return whether the main processor requested the DP output mode update 0. | derived |
| [`dp_tx_mode_requested_1`](../../src/leon2s/dp/dp_tx_mode_requested_1.c) | `FUN_a006ffb4` | Return whether the main processor requested the DP output mode update 1. | derived |
| [`dp_tx_mode_requested_2`](../../src/leon2s/dp/dp_tx_mode_requested_2.c) | `FUN_a006ffc4` | Return whether the main processor requested the DP output mode update 2. | derived |
| [`dp_tx_mode_requested_3`](../../src/leon2s/dp/dp_tx_mode_requested_3.c) | `FUN_a006ffd4` | Return whether the main processor requested the DP output mode update 3. | derived |
| [`dp_tx_mode_requested_4`](../../src/leon2s/dp/dp_tx_mode_requested_4.c) | `FUN_a006ffe4` | Return whether the main processor requested the DP output mode update 4. | derived |
| [`dp_tx_option_enabled_stub`](../../src/leon2s/dp/dp_tx_option_enabled_stub.c) | `FUN_a0089750` | Return 1 (an output option that is always on in this build). | descriptive |
| [`dp_tx_option_enabled_stub_copy`](../../src/leon2s/dp/dp_tx_option_enabled_stub_copy.c) | `FUN_a008d8d8` | Return 1; ipc_dispatch_command sends this value back as a reply byte. | descriptive |
| [`dp_tx_option_enabled_stub_copy2`](../../src/leon2s/dp/dp_tx_option_enabled_stub_copy2.c) | `FUN_a00c9368` | Return 1 (an output option that is always on in this build). | descriptive |
| [`dp_tx_phy_apply_output_options`](../../src/leon2s/dp/dp_tx_phy_apply_output_options.c) | `FUN_a00ab584` | Write the stored per-output PHY option bytes, or the defaults. | descriptive |
| [`dp_tx_phy_init_dptx_unit`](../../src/leon2s/dp/dp_tx_phy_init_dptx_unit.c) | `FUN_a00aa00c` | Write the fixed start-up register list of the DPTX transmitter PHY unit. | derived |
| [`dp_tx_phy_init_edp_unit`](../../src/leon2s/dp/dp_tx_phy_init_edp_unit.c) | `FUN_a00a9c4c` | Write the fixed start-up register list of the eDP transmitter PHY unit. | derived |
| [`dp_tx_phy_power_down_dptx_unit`](../../src/leon2s/dp/dp_tx_phy_power_down_dptx_unit.c) | `FUN_a00aa200` | Clear the enable bits of the DPTX transmitter PHY unit. | derived |
| [`dp_tx_phy_power_down_edp_unit`](../../src/leon2s/dp/dp_tx_phy_power_down_edp_unit.c) | `FUN_a00a9e74` | Write the fixed power-down register list of the eDP transmitter PHY unit. | derived |
| [`dp_tx_phy_power_down_output`](../../src/leon2s/dp/dp_tx_phy_power_down_output.c) | `FUN_a00ab4f8` | Power down the PHY lanes of one DP / eDP output. | derived |
| [`dp_tx_phy_power_up_output`](../../src/leon2s/dp/dp_tx_phy_power_up_output.c) | `FUN_a00ab4a8` | Power up the PHY lanes of one DP / eDP output. | derived |
| [`dp_tx_phy_reg_read8`](../../src/leon2s/dp/dp_tx_phy_reg_read8.c) | `FUN_a00a7d88` | Read a byte register of a DP transmitter PHY unit. | derived |
| [`dp_tx_phy_reg_update_bits`](../../src/leon2s/dp/dp_tx_phy_reg_update_bits.c) | `FUN_a00a7d04` | Set or clear masked bits of a byte register of a DP transmitter PHY unit. | derived |
| [`dp_tx_phy_reg_write8`](../../src/leon2s/dp/dp_tx_phy_reg_write8.c) | `FUN_a00a7cc0` | Write a byte register of a DP transmitter PHY unit. | derived |
| [`dp_tx_phy_set_link_rate`](../../src/leon2s/dp/dp_tx_phy_set_link_rate.c) | `FUN_a00aa5e8` | Program the transmitter PHY clock for a DP link rate (RBR, HBR, HBR2, HBR3). | derived |
| [`dp_tx_phy_set_pll_enable`](../../src/leon2s/dp/dp_tx_phy_set_pll_enable.c) | `FUN_a00aa538` | Enable (with set-up values) or disable the PLL of a DP transmitter PHY unit. | descriptive |
| [`dp_tx_phy_write_dptx_option`](../../src/leon2s/dp/dp_tx_phy_write_dptx_option.c) | `FUN_a00aa2d0` | Write register 0x37 of the DPTX PHY unit from a stored option byte. | descriptive |
| [`dp_tx_phy_write_edp_options`](../../src/leon2s/dp/dp_tx_phy_write_edp_options.c) | `FUN_a00aa308` | Write registers 0x3D/0x60/0x83/0xA6 of the eDP PHY unit from stored option bytes. | descriptive |
| [`dp_tx_phy_write_output_field`](../../src/leon2s/dp/dp_tx_phy_write_output_field.c) | `FUN_a00aa88c` | Write the PHY nibble field that belongs to one DP / eDP output. | descriptive |
| `dp_tx_phy_write_output_field_jump_table` | `switchdataD_a00aa878` | Jump table 1 of the switch statements in dp_tx_phy_write_output_field. | proven |
| [`dp_tx_post_action_flags`](../../src/leon2s/dp/dp_tx_post_action_flags.c) | `FUN_a0088f90` | Add pending action flags for one DP output. | derived |
| [`dp_tx_read_link_status`](../../src/leon2s/dp/dp_tx_read_link_status.c) | `FUN_a0086e58` | Read the sink's link status (lane lock and adjust requests). | proven |
| [`dp_tx_read_sink_caps`](../../src/leon2s/dp/dp_tx_read_sink_caps.c) | `FUN_a008686c` | Read the sink's DPCD capabilities and store rate, lanes and options. | proven |
| [`dp_tx_read_sink_edid`](../../src/leon2s/dp/dp_tx_read_sink_edid.c) | `FUN_a0088b60` | Read the 256-byte EDID of a sink over I2C-over-AUX. | derived |
| [`dp_tx_refresh_reg73`](../../src/leon2s/dp/dp_tx_refresh_reg73.c) | `FUN_a008996c` | Refresh register 0x73 of a DP output on a timer while bit 0 of reg 0x7B is set. | descriptive |
| [`dp_tx_reg_read8`](../../src/leon2s/dp/dp_tx_reg_read8.c) | `FUN_a00a78b4` | Read a byte register of a DP / eDP transmitter. | proven |
| [`dp_tx_reg_read24`](../../src/leon2s/dp/dp_tx_reg_read24.c) | `FUN_a00a79c4` | Read a 24-bit value from three byte registers of a DP / eDP transmitter. | proven |
| [`dp_tx_reg_read24_stable`](../../src/leon2s/dp/dp_tx_reg_read24_stable.c) | `FUN_a00a7a5c` | Read a 24-bit DP / eDP transmitter value until two reads agree. | proven |
| [`dp_tx_reg_update_bits`](../../src/leon2s/dp/dp_tx_reg_update_bits.c) | `FUN_a00a7940` | Set or clear masked bits of a byte register of a DP / eDP transmitter. | proven |
| [`dp_tx_reg_write8`](../../src/leon2s/dp/dp_tx_reg_write8.c) | `FUN_a00a78fc` | Write a byte register of a DP / eDP transmitter. | proven |
| [`dp_tx_request_pacing_update`](../../src/leon2s/dp/dp_tx_request_pacing_update.c) | `FUN_a0089e24` | Enable the pacing update of a DP output and clear its updated and rewritten marks. | derived |
| [`dp_tx_run_hpd_actions`](../../src/leon2s/dp/dp_tx_run_hpd_actions.c) | `DPTX_IsHPDAction_Off` | Handle plug, unplug and IRQ events of the DP output. | proven |
| [`dp_tx_run_output_tasks`](../../src/leon2s/dp/dp_tx_run_output_tasks.c) | `FUN_a0089d38` | Run the hot-plug handling and the pacing update of each DP output the main processor requested. | derived |
| [`dp_tx_set_bits_1_1`](../../src/leon2s/dp/dp_tx_set_bits_1_1.c) | `FUN_a00b230c` | Forward the fixed arguments (1, 1) to a DisplayPort output routine. | descriptive |
| [`dp_tx_set_ctl_reg8_bits67`](../../src/leon2s/dp/dp_tx_set_ctl_reg8_bits67.c) | `FUN_a00aa49c` | Set bits 6 and 7 of control register 8 of a DP / eDP transmitter by mode. | descriptive |
| [`dp_tx_set_ctl_reg9_bit3`](../../src/leon2s/dp/dp_tx_set_ctl_reg9_bit3.c) | `FUN_a00aa45c` | Set or clear bit 3 of control register 9 of a DP / eDP transmitter. | descriptive |
| [`dp_tx_set_ctrl_bit1`](../../src/leon2s/dp/dp_tx_set_ctrl_bit1.c) | `FUN_a0088f4c` | Clear bit 1 of control register 0xCF018E80 for mode 1, set it otherwise. | descriptive |
| [`dp_tx_set_drive_level_base`](../../src/leon2s/dp/dp_tx_set_drive_level_base.c) | `FUN_a00ab548` | Store the base swing and pre-emphasis values of one lane of a DP output. | derived |
| [`dp_tx_set_drive_levels`](../../src/leon2s/dp/dp_tx_set_drive_levels.c) | `FUN_a00aaf94` | Set the voltage swing and pre-emphasis of the lanes of a DP output. | derived |
| [`dp_tx_set_fastmute_pattern`](../../src/leon2s/dp/dp_tx_set_fastmute_pattern.c) | `FUN_a0089e54` | Switch the fast-mute pattern of a DP output on or off. | derived |
| [`dp_tx_set_lane_count`](../../src/leon2s/dp/dp_tx_set_lane_count.c) | `FUN_a0087794` | Program the lane count of a DP output, keeping enhanced framing. | derived |
| [`dp_tx_set_lane_drive_levels`](../../src/leon2s/dp/dp_tx_set_lane_drive_levels.c) | `FUN_a0086540` | Write the voltage swing and pre-emphasis of the lanes to the sink. | derived |
| [`dp_tx_set_lane_routing`](../../src/leon2s/dp/dp_tx_set_lane_routing.c) | `FUN_a0085914` | Write the lane selection bits of a DP output path from its lane counts. | descriptive |
| [`dp_tx_set_link_option`](../../src/leon2s/dp/dp_tx_set_link_option.c) | `FUN_a00858cc` | Store the link option byte of a DP output. | descriptive |
| [`dp_tx_set_link_pattern`](../../src/leon2s/dp/dp_tx_set_link_pattern.c) | `FUN_a00aa930` | Set the link pattern registers of a DP / eDP transmitter for a pattern mode. | derived |
| `dp_tx_set_link_pattern_jump_table` | `switchdataD_a00aa904` | Jump table 1 of the switch statements in dp_tx_set_link_pattern. | proven |
| [`dp_tx_set_link_rate`](../../src/leon2s/dp/dp_tx_set_link_rate.c) | `FUN_a0087734` | Program the link rate of a DP output and its PHY clock. | derived |
| [`dp_tx_set_max_lane_count`](../../src/leon2s/dp/dp_tx_set_max_lane_count.c) | `FUN_a0085888` | Store the maximum lane count (1, 2 or 4) of a DP output. | derived |
| [`dp_tx_set_max_link_rate`](../../src/leon2s/dp/dp_tx_set_max_link_rate.c) | `FUN_a0085830` | Store the maximum link rate code (RBR/HBR/HBR2/HBR3) of a DP output. | derived |
| [`dp_tx_set_pattern_and_levels`](../../src/leon2s/dp/dp_tx_set_pattern_and_levels.c) | `FUN_a008642c` | Write the training pattern and the drive level of all four lanes. | derived |
| [`dp_tx_set_reg11_mode`](../../src/leon2s/dp/dp_tx_set_reg11_mode.c) | `FUN_a0088ee0` | Set or clear the register 0x11 / 0x66 mode of a DP output. | descriptive |
| [`dp_tx_set_reg70_bit4`](../../src/leon2s/dp/dp_tx_set_reg70_bit4.c) | `FUN_a0089758` | Set or clear bit 4 of register 0x70 of a DP output. | descriptive |
| [`dp_tx_set_reg70_bit5`](../../src/leon2s/dp/dp_tx_set_reg70_bit5.c) | `FUN_a0087d50` | Set or clear bit 5 of register 0x70 of a DP output. | descriptive |
| [`dp_tx_set_sink_power`](../../src/leon2s/dp/dp_tx_set_sink_power.c) | `FUN_a00865b8` | Switch the sink to normal (D0) or power-save (D3) state, with retries. | proven |
| [`dp_tx_set_training_pattern`](../../src/leon2s/dp/dp_tx_set_training_pattern.c) | `FUN_a00864d4` | Select training pattern 1..4 (scrambling off) in the sink. | proven |
| [`dp_tx_set_video_timing`](../../src/leon2s/dp/dp_tx_set_video_timing.c) | `FUN_a0087ec8` | Program the video timing and stream registers of a DP output. | derived |
| `dp_tx_set_video_timing_jump_table` | `switchdataD_a0087e60` | Jump table 1 of the switch statements in dp_tx_set_video_timing. | proven |
| [`dp_tx_switch_reg_setup`](../../src/leon2s/dp/dp_tx_switch_reg_setup.c) | `FUN_a0087db4` | Switch a DP output between two register set-ups (regs 0x76, 0xA0, 0x67). | descriptive |
| [`dp_tx_take_action_flags`](../../src/leon2s/dp/dp_tx_take_action_flags.c) | `FUN_a0088fb0` | Return and clear the pending action flags of one DP output. | derived |
| [`dp_tx_train_channel_eq`](../../src/leon2s/dp/dp_tx_train_channel_eq.c) | `FUN_a008743c` | Run the channel-equalisation phase of link training on the selected outputs. | derived |
| [`dp_tx_train_clock_recovery`](../../src/leon2s/dp/dp_tx_train_clock_recovery.c) | `FUN_a0087110` | Run the clock-recovery phase of link training on the selected outputs. | derived |
| [`dp_tx_train_links`](../../src/leon2s/dp/dp_tx_train_links.c) | `TRAINING_NORESPONSE` | Train the links of the DP outputs and report each channel's result. | proven |
| [`dp_tx_update_edp_fastmute`](../../src/leon2s/dp/dp_tx_update_edp_fastmute.c) | `FUN_a0089e74` | Switch the fast-mute pattern of eDP outputs 1..4 from a control bit. | proven |
| [`dp_tx_update_edp_post_pattern`](../../src/leon2s/dp/dp_tx_update_edp_post_pattern.c) | `FUN_a0089f00` | Switch the post pattern of eDP outputs 1..4 from a control bit. | proven |
| [`dp_tx_update_hpd_status`](../../src/leon2s/dp/dp_tx_update_hpd_status.c) | `FUN_a0083870` | Read the hot-plug registers of the link outputs into the status byte and event word. | derived |
| [`dp_tx_write_downspread`](../../src/leon2s/dp/dp_tx_write_downspread.c) | `FUN_a008661c` | Write the spread-spectrum setting of the link to the sink. | derived |
| [`dp_tx_write_link_config`](../../src/leon2s/dp/dp_tx_write_link_config.c) | `FUN_a0086df4` | Write link rate and lane count (with enhanced framing) to the sink. | derived |
| [`dp_tx_write_reg57_latched`](../../src/leon2s/dp/dp_tx_write_reg57_latched.c) | `FUN_a008983c` | Write a 16-bit value to register 0x57 of a DP output and latch it. | descriptive |
| [`dp_tx_write_regs_69_6a`](../../src/leon2s/dp/dp_tx_write_regs_69_6a.c) | `FUN_a0087d8c` | Write registers 0x69 and 0x6A of a DP output. | descriptive |
| [`dp_unit_reg_update_bits`](../../src/leon2s/dp/dp_unit_reg_update_bits.c) | `FUN_a00a8400` | Set or clear masked bits of a byte register of one or all eight DP units. | derived |
| [`dp_unit_reg_write8`](../../src/leon2s/dp/dp_unit_reg_write8.c) | `FUN_a00a8370` | Write a byte register of one or all eight DP units. | derived |
| [`dp_unit_restart`](../../src/leon2s/dp/dp_unit_restart.c) | `FUN_a00afdf4` | Restart the receiver unit of a port, in one of two ways by mode. | descriptive |
| [`dp_unit_set_bit3`](../../src/leon2s/dp/dp_unit_set_bit3.c) | `FUN_a00b0078` | Set or clear bit 3 of register 0 of a port's receiver unit, clearing bit 7 when setting. | descriptive |
| [`dp_unit_set_bits_10_80`](../../src/leon2s/dp/dp_unit_set_bits_10_80.c) | `FUN_a00b0004` | Write two control bits of a port's receiver unit with opposite values. | descriptive |
| [`dp_unit_set_field`](../../src/leon2s/dp/dp_unit_set_field.c) | `FUN_a00af94c` | Write 0 and 0x6A to unit registers 0 and 1 of the receiver unit a port is mapped to. | descriptive |
| [`dp_unit_set_reg0b_field`](../../src/leon2s/dp/dp_unit_set_reg0b_field.c) | `FUN_a00b00e0` | Write the 2-bit field of register 0x0B of a port's receiver unit. | descriptive |
| [`dp_unit_set_reg1_bit5_and_reg3`](../../src/leon2s/dp/dp_unit_set_reg1_bit5_and_reg3.c) | `FUN_a00afdb0` | Set bit 5 of register 1 and write 2 to register 3 of the receiver unit a port is mapped to. | descriptive |
| [`dp_unit_write_two_24bit_values`](../../src/leon2s/dp/dp_unit_write_two_24bit_values.c) | `FUN_a00af8bc` | Write two 24-bit values to registers 4..6 and 8..10 of the receiver unit a port is mapped to. | descriptive |
| [`dp_update_fec_ready`](../../src/leon2s/dp/dp_update_fec_ready.c) | `FUN_a00ac41c` | Report and apply a change of the FEC-ready state of a DP receiver. | proven |
| [`dp_update_pending_bits`](../../src/leon2s/dp/dp_update_pending_bits.c) | `FUN_a00ad5cc` | Set the pending bit of each ready port while the service flag is set, then pulse the HPD block. | descriptive |
| [`dp_update_port_status_flags`](../../src/leon2s/dp/dp_update_port_status_flags.c) | `FUN_a006e820` | Refresh the signal and stream flags of a DP port record. | derived |
| [`dp_update_range_flag`](../../src/leon2s/dp/dp_update_range_flag.c) | `FUN_a00af690` | Update a port's range flag from a measurement, at most once per 40 ticks. | descriptive |
| [`dp_update_reg46_bit2`](../../src/leon2s/dp/dp_update_reg46_bit2.c) | `FUN_a00b0138` | Compare hactive and the 0x8B/0x8C value with two listed pairs and update bit 2 of register 0x46. | descriptive |
| [`dp_update_reg46_bit3`](../../src/leon2s/dp/dp_update_reg46_bit3.c) | `FUN_a00b06e0` | Set bit 3 of a port's register 0x46 while dp_is_trained_with_reg223_bit7 holds, else clear it. | descriptive |
| [`dp_write_capability_regs`](../../src/leon2s/dp/dp_write_capability_regs.c) | `FUN_a00abe20` | Rewrite the capability registers 0x200..0x203 and 0x266 of a DP receiver. | derived |
| [`dp_write_dpcd_reg`](../../src/leon2s/dp/dp_write_dpcd_reg.c) | `FUN_a00ac4ec` | Write a DP receiver register at 0x200 or above with write access opened. | derived |
| [`dp_write_lane_tables`](../../src/leon2s/dp/dp_write_lane_tables.c) | `FUN_a00b0e54` | Build two nibble tables from the stored lane data and write them to the port's registers. | descriptive |
| [`dp_write_low_reg`](../../src/leon2s/dp/dp_write_low_reg.c) | `FUN_a00ac550` | Write a DP receiver register below 0x200. | derived |
| [`dp_write_phy_table`](../../src/leon2s/dp/dp_write_phy_table.c) | `FUN_a00848cc` | Write the two fixed PHY register tables of a DP receiver with a reset pulse between. | descriptive |
| [`dp_write_port_option_regs`](../../src/leon2s/dp/dp_write_port_option_regs.c) | `FUN_a00abbc4` | Write DP receiver registers 0x3B0..0x3C4 from the port record settings. | derived |
| [`dp_write_port_reg`](../../src/leon2s/dp/dp_write_port_reg.c) | `FUN_a00856a8` | Write a register of a DP receiver, mapping the port to its block. | derived |
| [`dp_write_port_reg_wrapper`](../../src/leon2s/dp/dp_write_port_reg_wrapper.c) | `FUN_a00ac584` | Write a paged DP receiver register. | proven |
| [`dp_write_port_stop_sequence`](../../src/leon2s/dp/dp_write_port_stop_sequence.c) | `FUN_a008442c` | Write the fixed register sequence used when a DP receiver is stopped. | descriptive |
| [`dp_write_rate_divider_regs`](../../src/leon2s/dp/dp_write_rate_divider_regs.c) | `FUN_a00ab6e0` | Write DP receiver registers 0x26..0x2C from 48000 divided by a value. | descriptive |
| [`dp_write_reg_ab`](../../src/leon2s/dp/dp_write_reg_ab.c) | `FUN_a0084c74` | Write register 0xAB of a DP receiver. | descriptive |
| [`DPTX_SetBrilliantMode`](../../src/leon2s/dp/DPTX_SetBrilliantMode.c) | `DPTX_SetBrilliantMode` | Recompute the DP output pacing registers when clock, depth or lanes change. | proven |

<a id="hdcp"></a>
## Copy protection (HDCP)

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`hdcp_get_default_id_reversed`](../../src/leon2s/hdcp/hdcp_get_default_id_reversed.c) | `FUN_a00c12d8` | Copy a built-in 16-byte value into the caller's buffer in reverse order. | descriptive |
| [`hdcp_get_default_keys_first`](../../src/leon2s/hdcp/hdcp_get_default_keys_first.c) | `FUN_a00c0c08` | Copy the first built-in key-selection value and key block into the caller's buffers. | derived |
| [`hdcp_get_default_keys_second`](../../src/leon2s/hdcp/hdcp_get_default_keys_second.c) | `FUN_a00c0c78` | Copy the second built-in key-selection value and key block into the caller's buffers. | derived |
| [`hdcp_get_default_tables`](../../src/leon2s/hdcp/hdcp_get_default_tables.c) | `FUN_a00c0ecc` | Copy three built-in tables into the caller's buffers. | descriptive |
| [`hdcp_hash_feed_byte`](../../src/leon2s/hdcp/hdcp_hash_feed_byte.c) | `FUN_a00ca074` | Feed one byte to the hash block at 0xCF018E00; at counter 0 run the start sequence after it. | derived |
| [`hdcp_is_ksv_valid`](../../src/leon2s/hdcp/hdcp_is_ksv_valid.c) | `FUN_a00c83e4` | Check that a 5-byte key-selection value has exactly twenty one-bits. | proven |
| [`hdcp_repeater_collect_status`](../../src/leon2s/hdcp/hdcp_repeater_collect_status.c) | `FUN_a00c55c8` | Pass the device lists and summed counts of a DisplayPort input's outputs to its receiver. | derived |
| [`hdcp_repeater_report_downstream`](../../src/leon2s/hdcp/hdcp_repeater_report_downstream.c) | `FUN_a00c4e70` | Write the summed device counts, flags and report counter of the outputs showing an HDMI input to it. | derived |
| [`hdcp_rx_dp_calculate_v`](../../src/leon2s/hdcp/hdcp_rx_dp_calculate_v.c) | `FUN_a00ca130` | Hash the DisplayPort receiver's KSV list, Binfo and M0; write the 20 result bytes to its registers. | proven |
| [`hdcp_rx_dp_load_hdcp2_tables`](../../src/leon2s/hdcp/hdcp_rx_dp_load_hdcp2_tables.c) | `FUN_a00c1550` | Load the HDCP 2 tables into the DisplayPort input. | descriptive |
| [`hdcp_rx_dp_load_keys`](../../src/leon2s/hdcp/hdcp_rx_dp_load_keys.c) | `FUN_a00c1318` | Load the key-selection value and the key block into the DisplayPort input. | derived |
| [`hdcp_rx_dp_poll_v_calculation`](../../src/leon2s/hdcp/hdcp_rx_dp_poll_v_calculation.c) | `FUN_a00c5ae4` | On status bit 3 of a DisplayPort input, run hdcp_rx_dp_calculate_v when register 0x2A8 bit 1 is set. | derived |
| [`hdcp_rx_dp_task`](../../src/leon2s/hdcp/hdcp_rx_dp_task.c) | `FUN_a00c44e4` | Run the copy-protection state machine of the DisplayPort inputs. | derived |
| `hdcp_rx_dp_task_jump_table` | `switchdataD_a00c44ac` | Jump table 1 of the switch statements in hdcp_rx_dp_task. | proven |
| [`hdcp_rx_get_port_status_bit`](../../src/leon2s/hdcp/hdcp_rx_get_port_status_bit.c) | `FUN_a00c0a04` | Return a status bit for the first input record that has a given flag bit set. | descriptive |
| [`hdcp_rx_hdmi21_load_hdcp2_tables`](../../src/leon2s/hdcp/hdcp_rx_hdmi21_load_hdcp2_tables.c) | `FUN_a00c10c4` | Load four byte tables into an HDMI 2.1 input. | descriptive |
| [`hdcp_rx_hdmi21_load_keys`](../../src/leon2s/hdcp/hdcp_rx_hdmi21_load_keys.c) | `FUN_a00c0dfc` | Load the key-selection value and the key block into an HDMI 2.1 input. | derived |
| [`hdcp_rx_hdmi21_task`](../../src/leon2s/hdcp/hdcp_rx_hdmi21_task.c) | `FUN_a00c3ae8` | Run the copy-protection state machine of the two HDMI 2.1 inputs. | derived |
| `hdcp_rx_hdmi21_task_jump_table` | `switchdataD_a00c3ab0` | Jump table 1 of the switch statements in hdcp_rx_hdmi21_task. | proven |
| [`hdcp_rx_hdmi21_watch_counters`](../../src/leon2s/hdcp/hdcp_rx_hdmi21_watch_counters.c) | `FUN_a00c2f58` | Check two 16-bit counters of an HDMI 2.1 input at a limited rate. | descriptive |
| [`hdcp_rx_hdmi_load_hdcp2_tables`](../../src/leon2s/hdcp/hdcp_rx_hdmi_load_hdcp2_tables.c) | `FUN_a00c0f88` | Load the four tables (16, 522, 11 and 320 bytes) into an HDMI 2.0 input. | descriptive |
| [`hdcp_rx_hdmi_load_keys`](../../src/leon2s/hdcp/hdcp_rx_hdmi_load_keys.c) | `FUN_a00c0ce8` | Load the key-selection value and the key block into an HDMI 2.0 input. | derived |
| [`hdcp_rx_hdmi_recheck_ports`](../../src/leon2s/hdcp/hdcp_rx_hdmi_recheck_ports.c) | `FUN_a00c1ac0` | Move the HDMI 2.0 and 2.1 inputs in state 5 or 6 on to state 7 once their event bit is set. | descriptive |
| [`hdcp_rx_hdmi_task`](../../src/leon2s/hdcp/hdcp_rx_hdmi_task.c) | `FUN_a00c32f4` | Run the copy-protection state machine of the two HDMI 2.0 inputs. | derived |
| `hdcp_rx_hdmi_task_jump_table` | `switchdataD_a00c32bc` | Jump table 1 of the switch statements in hdcp_rx_hdmi_task. | proven |
| [`hdcp_rx_hdmi_watch_counters`](../../src/leon2s/hdcp/hdcp_rx_hdmi_watch_counters.c) | `FUN_a00c2de4` | Check two 16-bit counters of an HDMI 2.0 input at a limited rate. | descriptive |
| [`hdcp_rx_is_port_authenticated`](../../src/leon2s/hdcp/hdcp_rx_is_port_authenticated.c) | `FUN_a00c30e4` | Return a 0/1 status of an input's protection block. | descriptive |
| [`hdcp_rx_key_load_step`](../../src/leon2s/hdcp/hdcp_rx_key_load_step.c) | `FUN_a00c2758` | Do one step of the three-step key sequence of an input and return 1 after the last step. | descriptive |
| [`hdcp_rx_load_keys_block_first`](../../src/leon2s/hdcp/hdcp_rx_load_keys_block_first.c) | `FUN_a00c0a88` | Load the 5-byte key-selection value and the 282-byte key block into a receiver (first path). | derived |
| [`hdcp_rx_reset_port`](../../src/leon2s/hdcp/hdcp_rx_reset_port.c) | `FUN_a00c1778` | Reset the copy-protection record of an input and its hardware bits. | descriptive |
| [`hdcp_rx_set_ddc_addresses`](../../src/leon2s/hdcp/hdcp_rx_set_ddc_addresses.c) | `FUN_a00c18fc` | Write the fixed device address values of the inputs' protection ports. | descriptive |
| [`hdcp_rx_set_port_option`](../../src/leon2s/hdcp/hdcp_rx_set_port_option.c) | `FUN_a00c19b8` | Write an option of an input's protection block; set by a command from the main processor. | descriptive |
| [`hdcp_rx_step_hdcp2_bytes`](../../src/leon2s/hdcp/hdcp_rx_step_hdcp2_bytes.c) | `FUN_a00c224c` | Step the first 8 bytes of an HDCP 2 byte table on: shift down by one, last = old first + 1. | descriptive |
| [`hdcp_rx_update_port_status`](../../src/leon2s/hdcp/hdcp_rx_update_port_status.c) | `FUN_a00c3144` | Update an input's bit in the status mask and its state byte, with a time-out. | descriptive |
| [`hdcp_tx_check_cp_irq`](../../src/leon2s/hdcp/hdcp_tx_check_cp_irq.c) | `FUN_a00cf9e8` | Acknowledge a copy-protection interrupt flag of the output and test two status bytes. | derived |
| [`hdcp_tx_check_stored_keys`](../../src/leon2s/hdcp/hdcp_tx_check_stored_keys.c) | `FUN_a00c6968` | Compare a stored 3-byte sum with the sum computed over the first key set or the HDCP 2 data. | derived |
| [`hdcp_tx_clear_ksv_table`](../../src/leon2s/hdcp/hdcp_tx_clear_ksv_table.c) | `FUN_a00c79c8` | Clear the stored 5-byte key-selection values: all three rows for port 3, else row 0 only. | derived |
| [`hdcp_tx_disable_output`](../../src/leon2s/hdcp/hdcp_tx_disable_output.c) | `FUN_a00ccad4` | Switch the protection of an output off. | derived |
| [`hdcp_tx_dp_get_enable_bit`](../../src/leon2s/hdcp/hdcp_tx_dp_get_enable_bit.c) | `FUN_a00c972c` | Return the protection enable bit of the DisplayPort output. | descriptive |
| [`hdcp_tx_dp_run_state`](../../src/leon2s/hdcp/hdcp_tx_dp_run_state.c) | `FUN_a00d0968` | Call the handler for the current state of the DisplayPort output's handshake. | derived |
| `hdcp_tx_dp_run_state_jump_table` | `switchdataD_a00d0828` | Jump table 1 of the switch statements in hdcp_tx_dp_run_state. | proven |
| [`hdcp_tx_dp_set_bypass`](../../src/leon2s/hdcp/hdcp_tx_dp_set_bypass.c) | `FUN_a00c68f8` | Set or clear bit 6 of the DisplayPort protection control register and print it. | descriptive |
| [`hdcp_tx_dp_set_enable`](../../src/leon2s/hdcp/hdcp_tx_dp_set_enable.c) | `FUN_a00cca38` | Switch the protection of the DisplayPort output on or off. | derived |
| [`hdcp_tx_dp_state_check_link`](../../src/leon2s/hdcp/hdcp_tx_dp_state_check_link.c) | `FUN_a00d0798` | State handler: set the step result from the sink check, then start a timer and switch protection off. | descriptive |
| [`hdcp_tx_dp_state_check_link_bits`](../../src/leon2s/hdcp/hdcp_tx_dp_state_check_link_bits.c) | `FUN_a00cd4fc` | State handler: check the link status of the DisplayPort output. | descriptive |
| [`hdcp_tx_dp_state_compare_aux_block`](../../src/leon2s/hdcp/hdcp_tx_dp_state_compare_aux_block.c) | `FUN_a00ce4cc` | Read a 32-byte block over AUX and compare it with the engine's result block. | descriptive |
| [`hdcp_tx_dp_state_compare_reads`](../../src/leon2s/hdcp/hdcp_tx_dp_state_compare_reads.c) | `FUN_a00cd31c` | State handler: read the AUX status and value bytes, compare them with two registers, switch protection on. | descriptive |
| [`hdcp_tx_dp_state_compare_results`](../../src/leon2s/hdcp/hdcp_tx_dp_state_compare_results.c) | `FUN_a00cdcdc` | State handler: compare two 32-byte results and choose the next step. | descriptive |
| [`hdcp_tx_dp_state_exchange_first`](../../src/leon2s/hdcp/hdcp_tx_dp_state_exchange_first.c) | `FUN_a00ce66c` | State handler: read a block over AUX, start an engine step and store its result (first form). | descriptive |
| [`hdcp_tx_dp_state_exchange_third`](../../src/leon2s/hdcp/hdcp_tx_dp_state_exchange_third.c) | `FUN_a00cea60` | State handler: start an engine step and read the answer block over AUX (third form). | descriptive |
| [`hdcp_tx_dp_state_init_counters`](../../src/leon2s/hdcp/hdcp_tx_dp_state_init_counters.c) | `FUN_a00cdb0c` | State handler: for a plain receiver clear the device counters and load its BKSV; then count both up. | descriptive |
| [`hdcp_tx_dp_state_read_bksv`](../../src/leon2s/hdcp/hdcp_tx_dp_state_read_bksv.c) | `FUN_a00ccfa8` | State handler: read the receiver's five key-selection bytes over AUX and check them. | descriptive |
| [`hdcp_tx_dp_state_read_caps`](../../src/leon2s/hdcp/hdcp_tx_dp_state_read_caps.c) | `FUN_a00ccf0c` | State handler: switch protection off and read the receiver's capability byte over AUX. | descriptive |
| [`hdcp_tx_dp_state_read_hdcp2_messages`](../../src/leon2s/hdcp/hdcp_tx_dp_state_read_hdcp2_messages.c) | `FUN_a00cfd38` | State handler: read the message blocks at DPCD 0x69000 into the work buffers. | descriptive |
| [`hdcp_tx_dp_state_read_message`](../../src/leon2s/hdcp/hdcp_tx_dp_state_read_message.c) | `FUN_a00cd5e4` | State handler: read a two-byte header and a data block over AUX and pass them to the hardware. | descriptive |
| [`hdcp_tx_dp_state_read_receiver_ids`](../../src/leon2s/hdcp/hdcp_tx_dp_state_read_receiver_ids.c) | `FUN_a00cef6c` | State handler: read the device list message over AUX, check its value with the engine, take counts. | derived |
| [`hdcp_tx_dp_state_read_two_blocks`](../../src/leon2s/hdcp/hdcp_tx_dp_state_read_two_blocks.c) | `FUN_a00cfb40` | State handler: read 32 bytes over AUX (0x69473) and compare them with 32 bytes from the engine. | descriptive |
| [`hdcp_tx_dp_state_reset_session`](../../src/leon2s/hdcp/hdcp_tx_dp_state_reset_session.c) | `FUN_a00d0550` | State handler: clear the session data of a port and write the start blocks over AUX. | descriptive |
| [`hdcp_tx_dp_state_send_32_bytes`](../../src/leon2s/hdcp/hdcp_tx_dp_state_send_32_bytes.c) | `FUN_a00ce420` | State handler: fetch 32 bytes from the engine and send them over AUX. | descriptive |
| [`hdcp_tx_dp_state_send_engine_result`](../../src/leon2s/hdcp/hdcp_tx_dp_state_send_engine_result.c) | `FUN_a00cf6bc` | State handler: run an engine step and send its result over AUX. | descriptive |
| [`hdcp_tx_dp_state_send_key_block`](../../src/leon2s/hdcp/hdcp_tx_dp_state_send_key_block.c) | `FUN_a00cdde0` | State handler: wait for the engine, then send a prepared data block in 16 groups over AUX. | descriptive |
| [`hdcp_tx_dp_state_send_lc_init`](../../src/leon2s/hdcp/hdcp_tx_dp_state_send_lc_init.c) | `FUN_a00ce864` | State handler: check the receiver status byte, then send the bytes 0xB0..0xB7 over AUX to 0x692F0. | derived |
| [`hdcp_tx_dp_state_send_session_key`](../../src/leon2s/hdcp/hdcp_tx_dp_state_send_session_key.c) | `FUN_a00cec18` | State handler: send 16 engine bytes and 8 fixed bytes over AUX to 0x69318 and 0x69328. | derived |
| [`hdcp_tx_dp_state_send_stream_manage`](../../src/leon2s/hdcp/hdcp_tx_dp_state_send_stream_manage.c) | `FUN_a00cf7b4` | State handler: write 4 result bytes to AUX 0x693F0 and the stream byte pairs to 0x693F5 onwards. | derived |
| [`hdcp_tx_dp_state_stay`](../../src/leon2s/hdcp/hdcp_tx_dp_state_stay.c) | `FUN_a00cd2f0` | State handler: set the result to 3 (stay in this state). | derived |
| [`hdcp_tx_dp_state_stay_copy`](../../src/leon2s/hdcp/hdcp_tx_dp_state_stay_copy.c) | `FUN_a00cf954` | State handler: set the result to 3 (stay in this state). | derived |
| [`hdcp_tx_dp_state_sync_enable`](../../src/leon2s/hdcp/hdcp_tx_dp_state_sync_enable.c) | `FUN_a00cdc74` | Set the enable bit to the value of dp_tx_option_enabled_stub_copy2 (always 1) when it differs from the current bit. | descriptive |
| [`hdcp_tx_dp_state_sync_enable_copy`](../../src/leon2s/hdcp/hdcp_tx_dp_state_sync_enable_copy.c) | `FUN_a00cf980` | State handler: set the result to 'next' and bring the enable bit to the wanted value. | descriptive |
| [`hdcp_tx_dp_state_wait_timer`](../../src/leon2s/hdcp/hdcp_tx_dp_state_wait_timer.c) | `FUN_a00d00e0` | State handler: wait for a port timer, then switch two register bits. | descriptive |
| [`hdcp_tx_engine_exchange_long_tables`](../../src/leon2s/hdcp/hdcp_tx_engine_exchange_long_tables.c) | `FUN_a00c255c` | Run the engine's two-pass exchange on the result tables and keep the last 17 bytes read back. | descriptive |
| [`hdcp_tx_engine_exchange_tables`](../../src/leon2s/hdcp/hdcp_tx_engine_exchange_tables.c) | `FUN_a00c77dc` | Run the two-round table exchange with the engine and combine the result with ROM tables. | descriptive |
| [`hdcp_tx_engine_load_key_blocks`](../../src/leon2s/hdcp/hdcp_tx_engine_load_key_blocks.c) | `FUN_a00c9cc8` | Write the two prepared blocks to the engine. | descriptive |
| [`hdcp_tx_engine_load_table`](../../src/leon2s/hdcp/hdcp_tx_engine_load_table.c) | `FUN_a00c9e44` | Load a 384-byte table into the engine of an output and read 32 bytes back. | derived |
| [`hdcp_tx_engine_load_three_tables`](../../src/leon2s/hdcp/hdcp_tx_engine_load_three_tables.c) | `FUN_a00c22a0` | Send three 128-byte tables to the protection engine. | descriptive |
| [`hdcp_tx_engine_read_384_bytes`](../../src/leon2s/hdcp/hdcp_tx_engine_read_384_bytes.c) | `FUN_a00c9de8` | Read a block from the engine into a cleared 384-byte buffer and write it back to bank 4. | descriptive |
| [`hdcp_tx_engine_read_block`](../../src/leon2s/hdcp/hdcp_tx_engine_read_block.c) | `FUN_a00c9d28` | Read a block of bytes from the protection engine of an output. | descriptive |
| [`hdcp_tx_engine_read_result`](../../src/leon2s/hdcp/hdcp_tx_engine_read_result.c) | `FUN_a00c2488` | Read 64 byte pairs from the engine when its done bit is set. | descriptive |
| [`hdcp_tx_engine_reg_read8`](../../src/leon2s/hdcp/hdcp_tx_engine_reg_read8.c) | `FUN_a00a7fa0` | Read a byte register of a copy-protection engine unit. | derived |
| [`hdcp_tx_engine_reg_update_bits`](../../src/leon2s/hdcp/hdcp_tx_engine_reg_update_bits.c) | `FUN_a00a7f1c` | Set or clear masked bits of a byte register of a copy-protection engine unit. | derived |
| [`hdcp_tx_engine_reg_write8`](../../src/leon2s/hdcp/hdcp_tx_engine_reg_write8.c) | `FUN_a00a7ee0` | Write a byte register of a copy-protection engine unit. | derived |
| [`hdcp_tx_engine_run_step_first`](../../src/leon2s/hdcp/hdcp_tx_engine_run_step_first.c) | `FUN_a00c9b58` | Write zero words to bank 6 of the engine, then run the register sequence that starts a step. | descriptive |
| [`hdcp_tx_engine_start_command`](../../src/leon2s/hdcp/hdcp_tx_engine_start_command.c) | `FUN_a00c87e8` | Give the protection engine a command code and a 16-bit length. | derived |
| [`hdcp_tx_engine_write_bank3_block`](../../src/leon2s/hdcp/hdcp_tx_engine_write_bank3_block.c) | `FUN_a00c9c98` | Write 0 to engine register 0, then write a data block of size/16 words to bank 3. | descriptive |
| [`hdcp_tx_engine_write_block`](../../src/leon2s/hdcp/hdcp_tx_engine_write_block.c) | `FUN_a00c99a4` | Write a block of bytes to the protection engine of an output. | descriptive |
| [`hdcp_tx_get_output_status`](../../src/leon2s/hdcp/hdcp_tx_get_output_status.c) | `FUN_a00c9750` | Return the protection status bit of an output. | descriptive |
| [`hdcp_tx_get_timer`](../../src/leon2s/hdcp/hdcp_tx_get_timer.c) | `FUN_a00cfb20` | Update the timers and return one of them. | derived |
| [`hdcp_tx_hash_message_buffer`](../../src/leon2s/hdcp/hdcp_tx_hash_message_buffer.c) | `FUN_a00ca4e8` | Hash bytes 1..138 of the message buffer in the block at 0xCF018E00 and store the 32 result bytes. | derived |
| [`hdcp_tx_hdmi_check_reauth_request`](../../src/leon2s/hdcp/hdcp_tx_hdmi_check_reauth_request.c) | `FUN_a00cc9f8` | Return whether the receiver asks for a new handshake, and note it. | derived |
| [`hdcp_tx_hdmi_clear_an_request`](../../src/leon2s/hdcp/hdcp_tx_hdmi_clear_an_request.c) | `FUN_a00c85b8` | Clear bit 3 of register 0x0F of an HDMI output. | descriptive |
| [`hdcp_tx_hdmi_disable`](../../src/leon2s/hdcp/hdcp_tx_hdmi_disable.c) | `FUN_a00cc974` | Switch the protection of an HDMI output off. | descriptive |
| [`hdcp_tx_hdmi_generate_an`](../../src/leon2s/hdcp/hdcp_tx_hdmi_generate_an.c) | `FUN_a00c85e4` | Let the engine produce the session's random value and read its eight bytes. | derived |
| [`hdcp_tx_hdmi_get_reg9_bit2`](../../src/leon2s/hdcp/hdcp_tx_hdmi_get_reg9_bit2.c) | `FUN_a00cc9ac` | Return 1 when bit 2 of register 9 of an HDMI output's block is set, else 0. | descriptive |
| [`hdcp_tx_hdmi_get_status_bit6`](../../src/leon2s/hdcp/hdcp_tx_hdmi_get_status_bit6.c) | `FUN_a00c9370` | Return status bit 6 of an HDMI output's protection block. | descriptive |
| [`hdcp_tx_hdmi_load_fixed_streams`](../../src/leon2s/hdcp/hdcp_tx_hdmi_load_fixed_streams.c) | `FUN_a00c0b48` | Write the fixed byte stream to both HDMI outputs and adjust one register on each. | descriptive |
| [`hdcp_tx_hdmi_probe_receiver`](../../src/leon2s/hdcp/hdcp_tx_hdmi_probe_receiver.c) | `FUN_a00c966c` | Try up to ten times to reach the receiver's protection port and read its version. | derived |
| [`hdcp_tx_hdmi_pulse_reg0f_bit2`](../../src/leon2s/hdcp/hdcp_tx_hdmi_pulse_reg0f_bit2.c) | `FUN_a00c7ccc` | Clear bit 2 of register 0x0F of an HDMI output, optionally setting it again after a wait. | descriptive |
| [`hdcp_tx_hdmi_read_bcaps`](../../src/leon2s/hdcp/hdcp_tx_hdmi_read_bcaps.c) | `FUN_a00c8360` | Read the receiver's capability byte. | proven |
| [`hdcp_tx_hdmi_read_bksv`](../../src/leon2s/hdcp/hdcp_tx_hdmi_read_bksv.c) | `FUN_a00c850c` | Read the receiver's key-selection value, load it into the engine and check it. | proven |
| [`hdcp_tx_hdmi_read_hdcp2_version`](../../src/leon2s/hdcp/hdcp_tx_hdmi_read_hdcp2_version.c) | `FUN_a00c8328` | Read the receiver's HDCP 2 version byte. | proven |
| [`hdcp_tx_hdmi_read_ksv_fifo`](../../src/leon2s/hdcp/hdcp_tx_hdmi_read_ksv_fifo.c) | `FUN_a00c8824` | Read the list of downstream key-selection values and feed it to the engine byte by byte. | derived |
| [`hdcp_tx_hdmi_read_message`](../../src/leon2s/hdcp/hdcp_tx_hdmi_read_message.c) | `FUN_a00c9810` | Read a message from the receiver in 16-byte blocks, waiting for each block to fill the DDC fifo. | derived |
| [`hdcp_tx_hdmi_read_ri`](../../src/leon2s/hdcp/hdcp_tx_hdmi_read_ri.c) | `FUN_a00c8760` | Read the receiver's two link-check bytes. | proven |
| [`hdcp_tx_hdmi_read_rx_status`](../../src/leon2s/hdcp/hdcp_tx_hdmi_read_rx_status.c) | `FUN_a00c9798` | Read the receiver's two status bytes over the HDMI output's control channel. | derived |
| [`hdcp_tx_hdmi_run_fixed_block`](../../src/leon2s/hdcp/hdcp_tx_hdmi_run_fixed_block.c) | `FUN_a00ca6d4` | Write a 16-byte fixed block to the engine, wait and read 32 result bytes. | descriptive |
| [`hdcp_tx_hdmi_run_state`](../../src/leon2s/hdcp/hdcp_tx_hdmi_run_state.c) | `FUN_a00d03a0` | Call the handler for the current state of an HDMI output's handshake. | derived |
| `hdcp_tx_hdmi_run_state_jump_table` | `switchdataD_a00d0260` | Jump table 1 of the switch statements in hdcp_tx_hdmi_run_state. | proven |
| [`hdcp_tx_hdmi_set_enable`](../../src/leon2s/hdcp/hdcp_tx_hdmi_set_enable.c) | `FUN_a00c89b8` | Switch the protection of an HDMI output on or off. | derived |
| [`hdcp_tx_hdmi_set_reg4_bit7`](../../src/leon2s/hdcp/hdcp_tx_hdmi_set_reg4_bit7.c) | `FUN_a00c9968` | Set or clear bit 7 of register 4 of an HDMI output's protection block. | descriptive |
| [`hdcp_tx_hdmi_set_reg27_bit0`](../../src/leon2s/hdcp/hdcp_tx_hdmi_set_reg27_bit0.c) | `FUN_a00c8a1c` | Set or clear bit 0 of register 0x27 of an HDMI output. | descriptive |
| [`hdcp_tx_hdmi_set_repeater_bits`](../../src/leon2s/hdcp/hdcp_tx_hdmi_set_repeater_bits.c) | `FUN_a00c8444` | Set or clear two control bits of an HDMI output by a flag of its record. | descriptive |
| [`hdcp_tx_hdmi_state_check_link`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_check_link.c) | `FUN_a00c9398` | State handler: run the link checks of an HDMI output and update its record. | descriptive |
| [`hdcp_tx_hdmi_state_check_ri`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_check_ri.c) | `FUN_a00c8b18` | State handler: compare the receiver's link-check bytes with the engine's. | derived |
| [`hdcp_tx_hdmi_state_check_v`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_check_v.c) | `FUN_a00c90b4` | State handler: read the repeater's 20-byte check value and compare it with the engine's. | derived |
| [`hdcp_tx_hdmi_state_compare_results`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_compare_results.c) | `FUN_a00cab10` | State handler: compare the engine's 32 result bytes, write the receiver id, store the repeater flag. | descriptive |
| [`hdcp_tx_hdmi_state_forward_16_bytes`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_forward_16_bytes.c) | `FUN_a00cc1d4` | State handler: read 16 bytes from the engine and send them to the receiver. | descriptive |
| [`hdcp_tx_hdmi_state_pass`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_pass.c) | `FUN_a00c9334` | State handler: set the result of the state to 'done'. | descriptive |
| [`hdcp_tx_hdmi_state_pass_copy`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_pass_copy.c) | `FUN_a00cdc40` | State handler: set the result of the state to 'done'. | derived |
| [`hdcp_tx_hdmi_state_probe`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_probe.c) | `FUN_a00ccd20` | State handler: probe the receiver and go on or give up. | descriptive |
| [`hdcp_tx_hdmi_state_read_32_bytes`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_read_32_bytes.c) | `FUN_a00caf78` | State handler: run the fixed block, read 32 bytes from the receiver, compare them with the result. | descriptive |
| [`hdcp_tx_hdmi_state_read_message`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_read_message.c) | `FUN_a00ca8c4` | State handler: read a message from the receiver and store its parts. | descriptive |
| [`hdcp_tx_hdmi_state_read_pairing_info`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_read_pairing_info.c) | `FUN_a00cb1d4` | State handler: read the receiver's 16-byte message, store it with 16 engine bytes and keep its id. | derived |
| [`hdcp_tx_hdmi_state_read_repeater_info`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_read_repeater_info.c) | `FUN_a00c8c64` | State handler: read the repeater's status and its list of downstream devices. | derived |
| [`hdcp_tx_hdmi_state_read_result_block`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_read_result_block.c) | `FUN_a00cb56c` | State handler: read 32 engine bytes and the receiver's 32-byte message and compare them. | descriptive |
| [`hdcp_tx_hdmi_state_read_second_result`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_read_second_result.c) | `FUN_a00cc5f8` | State handler: read 32 bytes of the engine into the second buffer and compare. | descriptive |
| [`hdcp_tx_hdmi_state_read_status_reg`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_read_status_reg.c) | `FUN_a00c8a80` | State handler: read a status register and choose the next state. | descriptive |
| [`hdcp_tx_hdmi_state_refresh_status`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_refresh_status.c) | `FUN_a00cc900` | State handler: refresh the status of an output and correct its encryption bit. | descriptive |
| [`hdcp_tx_hdmi_state_run_checks`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_run_checks.c) | `FUN_a00ccdb4` | State handler: read the receiver's capability and key selection, send the random value and own key. | descriptive |
| [`hdcp_tx_hdmi_state_send_engine_bytes`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_send_engine_bytes.c) | `FUN_a00caee4` | State handler: fetch bytes from the engine and send them to the receiver. | descriptive |
| [`hdcp_tx_hdmi_state_send_key_block`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_send_key_block.c) | `FUN_a00cad8c` | State handler: wait for the engine and send the prepared block to the receiver. | descriptive |
| [`hdcp_tx_hdmi_state_send_lc_init`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_send_lc_init.c) | `FUN_a00cb3e8` | State handler: send message 9 (fixed bytes 1..8) to the engine and the receiver, wait for the engine. | derived |
| [`hdcp_tx_hdmi_state_send_session_key`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_send_session_key.c) | `FUN_a00cb7a0` | State handler: send message 0xB (16 engine bytes and 8 fixed bytes) to the receiver. | derived |
| [`hdcp_tx_hdmi_state_send_stream_manage`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_send_stream_manage.c) | `FUN_a00cc2f8` | State handler: for a repeater, load the stream counter into the engine and send message 0x10. | derived |
| [`hdcp_tx_hdmi_state_start`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_start.c) | `FUN_a00ccb04` | State handler: once the retry time is reached and the engine is free, reset and send message 2. | descriptive |
| [`hdcp_tx_hdmi_state_start_engine`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_start_engine.c) | `FUN_a00c91f8` | Count one more device and level in the record; for a plain receiver also load its id into the engine. | descriptive |
| [`hdcp_tx_hdmi_state_stay`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_stay.c) | `FUN_a00c8aec` | State handler: set the result to 3 (stay in this state). | derived |
| [`hdcp_tx_hdmi_state_stay_copy`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_stay_copy.c) | `FUN_a00cc8d4` | State handler: set the result to 3 (stay in this state). | derived |
| [`hdcp_tx_hdmi_state_wait_clear_an_request`](../../src/leon2s/hdcp/hdcp_tx_hdmi_state_wait_clear_an_request.c) | `FUN_a00d01f4` | State handler: stay while timer port + 8 runs, then clear the An request bit of the output. | derived |
| [`hdcp_tx_hdmi_update_record`](../../src/leon2s/hdcp/hdcp_tx_hdmi_update_record.c) | `FUN_a00cbb50` | Update an HDMI output's record from the received status and message bytes. | derived |
| [`hdcp_tx_hdmi_write_aksv`](../../src/leon2s/hdcp/hdcp_tx_hdmi_write_aksv.c) | `FUN_a00c86bc` | Send the monitor's own key-selection value to the receiver. | proven |
| [`hdcp_tx_hdmi_write_an`](../../src/leon2s/hdcp/hdcp_tx_hdmi_write_an.c) | `FUN_a00c8688` | Send the session's random value to the receiver. | proven |
| [`hdcp_tx_hdmi_write_fixed_stream`](../../src/leon2s/hdcp/hdcp_tx_hdmi_write_fixed_stream.c) | `FUN_a00c7d5c` | Write the ksv and key block, framed by fixed bytes, to registers 0xFC and 0xFE of an HDMI output. | descriptive |
| [`hdcp_tx_init_port_record`](../../src/leon2s/hdcp/hdcp_tx_init_port_record.c) | `FUN_a00c7a4c` | Initialise the copy-protection record of an output. | derived |
| [`hdcp_tx_reg_read`](../../src/leon2s/hdcp/hdcp_tx_reg_read.c) | `FUN_a00c7770` | Read a register of an output's protection block. | derived |
| [`hdcp_tx_reg_update_bits`](../../src/leon2s/hdcp/hdcp_tx_reg_update_bits.c) | `FUN_a00c76c0` | Set or clear bits of a register of an output's protection block. | derived |
| [`hdcp_tx_reg_write`](../../src/leon2s/hdcp/hdcp_tx_reg_write.c) | `FUN_a00c7654` | Write a register of an output's protection block. | derived |
| [`hdcp_tx_select_next_state`](../../src/leon2s/hdcp/hdcp_tx_select_next_state.c) | `FUN_a00d0d78` | Pick the next state of an output's handshake from the step result and start that state's timer. | derived |
| `hdcp_tx_select_next_state_jump_table` | `switchdataD_a00d0af8` | Jump table 1 of the switch statements in hdcp_tx_select_next_state. | proven |
| `hdcp_tx_select_next_state_jump_table2` | `switchdataD_a00d0c38` | Jump table 2 of the switch statements in hdcp_tx_select_next_state. | proven |
| [`hdcp_tx_service_port`](../../src/leon2s/hdcp/hdcp_tx_service_port.c) | `FUN_a00d12e4` | Check and update the state of one output's copy-protection handshake and run its handler. | derived |
| [`hdcp_tx_set_encryption_bit`](../../src/leon2s/hdcp/hdcp_tx_set_encryption_bit.c) | `FUN_a00cc834` | Set or clear the encryption control bit of an output. | descriptive |
| [`hdcp_tx_set_timer`](../../src/leon2s/hdcp/hdcp_tx_set_timer.c) | `FUN_a00d0530` | Update the timers and start one of them with a value. | derived |
| [`hdcp_tx_task`](../../src/leon2s/hdcp/hdcp_tx_task.c) | `FUN_a00d17a8` | Run the copy-protection service for the three video outputs. | derived |
| [`hdcp_tx_update_timers`](../../src/leon2s/hdcp/hdcp_tx_update_timers.c) | `FUN_a00cfab8` | Count the copy-protection timers down by the ticks that have passed. | derived |
| [`InitHDCP`](../../src/leon2s/hdcp/InitHDCP.c) | `FUN_a00c1c18` | Load the copy-protection keys and tables into the inputs and HDMI outputs; built-in if none stored. | proven |

<a id="hdr"></a>
## HDR

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`hdr_ack_dp_metadata`](../../src/leon2s/hdr/hdr_ack_dp_metadata.c) | `FUN_a00d2e9c` | Acknowledge the metadata flag of a DisplayPort source. | descriptive |
| [`hdr_apply_tone_curve`](../../src/leon2s/hdr/hdr_apply_tone_curve.c) | `FUN_a00d31f8` | Copy one of two stored 0x101-entry tone curves (chosen by an option bit) and write it to hardware. | derived |
| [`hdr_blend_values`](../../src/leon2s/hdr/hdr_blend_values.c) | `FUN_a00d36e4` | Blend two values with a weight of n/256. | proven |
| [`hdr_build_guided_curve`](../../src/leon2s/hdr/hdr_build_guided_curve.c) | `FUN_a00627a8` | Compute a guided knee point and Bezier anchors from scene and panel brightness. | derived |
| [`hdr_build_hdr10plus_tone_curve`](../../src/leon2s/hdr/hdr_build_hdr10plus_tone_curve.c) | `FUN_a0062fc8` | Build and load the 257-point tone-mapping table from the received HDR10+ metadata. | derived |
| [`hdr_build_static_tone_curve`](../../src/leon2s/hdr/hdr_build_static_tone_curve.c) | `FUN_a0062bac` | Build the 257-point tone curve for static HDR from content and panel peak brightness. | derived |
| [`hdr_check_metadata_timeout`](../../src/leon2s/hdr/hdr_check_metadata_timeout.c) | `FUN_a00624b4` | Clear the HDR10+ metadata-present flag when no new packet arrived for 200 ticks. | derived |
| [`hdr_dump_hdr10plus_metadata`](../../src/leon2s/hdr/hdr_dump_hdr10plus_metadata.c) | `targeted_system_display_maximum_luminance` | Print the received HDR10+ metadata, the guided curve and the tone-mapping table when requested. | proven |
| [`hdr_evaluate_bezier`](../../src/leon2s/hdr/hdr_evaluate_bezier.c) | `FUN_a0062a34` | Evaluate the Bezier tone curve at one input level from the anchor weights. | derived |
| [`hdr_evaluate_tone_curve`](../../src/leon2s/hdr/hdr_evaluate_tone_curve.c) | `FUN_a0062b64` | Return one tone-curve point mixed from the knee and the Bezier part. | derived |
| [`hdr_fill_unused_anchors`](../../src/leon2s/hdr/hdr_fill_unused_anchors.c) | `FUN_a00629fc` | Set the Bezier anchors beyond the used count to full scale. | derived |
| [`hdr_find_percentile_luminance`](../../src/leon2s/hdr/hdr_find_percentile_luminance.c) | `FUN_a006250c` | Find or interpolate the 50th and 99th percentile brightness from the HDR10+ percentile list. | derived |
| [`hdr_get_peak_luminance`](../../src/leon2s/hdr/hdr_get_peak_luminance.c) | `FUN_a00d3ef0` | Return the stored peak luminance. | derived |
| [`hdr_get_status_code`](../../src/leon2s/hdr/hdr_get_status_code.c) | `FUN_a00d3efc` | Return the HDR status code that is reported to the main processor. | descriptive |
| [`hdr_has_metadata_changed`](../../src/leon2s/hdr/hdr_has_metadata_changed.c) | `FUN_a00d2b88` | Return 1 when the HDR settings must be applied again, and store the current metadata values. | derived |
| [`hdr_init`](../../src/leon2s/hdr/hdr_init.c) | `FUN_a00d27fc` | Initialise the HDR service: neutral curve, default record, coefficients and HDR10+ set-up. | derived |
| [`hdr_init_default_metadata`](../../src/leon2s/hdr/hdr_init_default_metadata.c) | `FUN_a0062308` | Fill the HDR10+ metadata record with default values. | derived |
| [`hdr_init_hdr10plus`](../../src/leon2s/hdr/hdr_init_hdr10plus.c) | `FUN_a0062434` | Enable the HDR10+ interrupt source, store the panel peak luminance and load default metadata. | derived |
| [`hdr_is_source_hdr_active`](../../src/leon2s/hdr/hdr_is_source_hdr_active.c) | `FUN_a00d2e00` | Return whether the current source reports an HDR signal. | derived |
| [`hdr_is_update_due`](../../src/leon2s/hdr/hdr_is_update_due.c) | `FUN_a00d3670` | Return whether more than 200 ticks have passed since the last curve update. | derived |
| [`hdr_mark_source_active`](../../src/leon2s/hdr/hdr_mark_source_active.c) | `FUN_a00d36a4` | Mark the current source as HDR-active, or clear the mark. | descriptive |
| [`hdr_print_static_state`](../../src/leon2s/hdr/hdr_print_static_state.c) | `FUN_a00d2920` | Print the static HDR state and read the tone-mapping table back. | proven |
| [`hdr_read_hdr10plus_metadata`](../../src/leon2s/hdr/hdr_read_hdr10plus_metadata.c) | `FUN_a0061d60` | Read the 27 HDR10+ infoframe bytes from the receiver and unpack them into the metadata record. | proven |
| [`hdr_read_source_metadata`](../../src/leon2s/hdr/hdr_read_source_metadata.c) | `FUN_a00d38a8` | Read EOTF type, mastering luminance and MaxCLL of the source; clamp the mastering luminance. | derived |
| [`hdr_request_curve_table_reload`](../../src/leon2s/hdr/hdr_request_curve_table_reload.c) | `FUN_a0063950` | Request a reload of the tone-curve row table before the next static curve build. | derived |
| [`hdr_request_reload`](../../src/leon2s/hdr/hdr_request_reload.c) | `FUN_a00d3f54` | Mark the HDR settings as changed and request a reload of the curve table. | derived |
| [`hdr_reset_tone_curve`](../../src/leon2s/hdr/hdr_reset_tone_curve.c) | `FUN_a00d264c` | Fill the 257-entry tone curve with the neutral value 0x400. | proven |
| [`hdr_select_metadata_receiver`](../../src/leon2s/hdr/hdr_select_metadata_receiver.c) | `FUN_a0061f5c` | Select which HDMI receiver and register set the HDR10+ metadata is read from. | derived |
| [`hdr_select_source`](../../src/leon2s/hdr/hdr_select_source.c) | `FUN_a00d25f4` | Store the source that the HDR service follows and reset its state. | derived |
| [`hdr_set_enable`](../../src/leon2s/hdr/hdr_set_enable.c) | `FUN_a00d3f30` | Switch the HDR curve service on or off. | descriptive |
| [`hdr_set_mode_byte`](../../src/leon2s/hdr/hdr_set_mode_byte.c) | `FUN_a00d3f88` | Store an HDR mode byte and mark the settings as changed. | descriptive |
| [`hdr_set_option_byte`](../../src/leon2s/hdr/hdr_set_option_byte.c) | `FUN_a00d3f70` | Store an HDR option byte and mark the settings as changed. | descriptive |
| [`hdr_set_peak_luminance`](../../src/leon2s/hdr/hdr_set_peak_luminance.c) | `FUN_a00d3eb0` | Store the panel's peak luminance, limited to 10000 (1000 when 0 is given). | derived |
| [`hdr_set_source_disable_bit`](../../src/leon2s/hdr/hdr_set_source_disable_bit.c) | `FUN_a00d2618` | Set or clear the bit of a source that switches HDR processing off for it. | derived |
| [`hdr_smooth_level`](../../src/leon2s/hdr/hdr_smooth_level.c) | `FUN_a00d3704` | Move the stored level a step towards a target, or set it at once. | derived |
| [`hdr_task`](../../src/leon2s/hdr/hdr_task.c) | `FUN_a00d3c40` | Run the HDR service once: read the source's metadata and update or switch off the tone curve. | derived |
| [`hdr_tmo_disable`](../../src/leon2s/hdr/hdr_tmo_disable.c) | `FUN_a00d2c38` | Switch the tone-mapping stages off when they are on. | derived |
| [`hdr_tmo_disable_and_print`](../../src/leon2s/hdr/hdr_tmo_disable_and_print.c) | `FUN_a00d2d1c` | Switch the tone-mapping stages off and print a line when the second set is on. | derived |
| [`hdr_tmo_enable`](../../src/leon2s/hdr/hdr_tmo_enable.c) | `FUN_a00d2ca8` | Switch the tone-mapping stages on when they are off and print a line. | derived |
| [`hdr_tmo_enable_second`](../../src/leon2s/hdr/hdr_tmo_enable_second.c) | `FUN_a00d2d8c` | Switch the second tone-mapping set on and print a line. | descriptive |
| [`hdr_tmo_set_reg_f10_bit`](../../src/leon2s/hdr/hdr_tmo_set_reg_f10_bit.c) | `FUN_a00d2434` | Write one control bit of the tone-mapping register 0xD0013F10. | descriptive |
| [`hdr_tmo_set_reg_f50_bit`](../../src/leon2s/hdr/hdr_tmo_set_reg_f50_bit.c) | `FUN_a00d2300` | Write one control bit of the tone-mapping register 0xD0013F50. | descriptive |
| [`hdr_tmo_set_reg_f60_f70_bit`](../../src/leon2s/hdr/hdr_tmo_set_reg_f60_f70_bit.c) | `FUN_a00d23bc` | Write bit 31 of the tone-mapping register 0xD0013F60 (selector 0) or 0xD0013F70. | descriptive |
| [`hdr_tmo_set_reg_fd0_bit`](../../src/leon2s/hdr/hdr_tmo_set_reg_fd0_bit.c) | `FUN_a00d2210` | Write one control bit of the tone-mapping register 0xD0013FD0. | descriptive |
| [`hdr_tmo_set_reg_fe0_bit`](../../src/leon2s/hdr/hdr_tmo_set_reg_fe0_bit.c) | `FUN_a00d2288` | Write one control bit of the tone-mapping register 0xD0013FE0. | descriptive |
| [`hdr_tmo_set_table_index`](../../src/leon2s/hdr/hdr_tmo_set_table_index.c) | `FUN_a00d2378` | Write the table index field of the tone-mapping block. | descriptive |
| [`hdr_tmo_setup_mode`](../../src/leon2s/hdr/hdr_tmo_setup_mode.c) | `FUN_a00d2678` | Set the tone-mapping block up for a mode. | descriptive |
| [`hdr_tmo_write_coefficients`](../../src/leon2s/hdr/hdr_tmo_write_coefficients.c) | `FUN_a00d24ac` | Write nine table values into the coefficient fields of the tone-mapping block. | descriptive |
| [`hdr_tmo_write_curve`](../../src/leon2s/hdr/hdr_tmo_write_curve.c) | `FUN_a00d3114` | Write the tone curve table to the tone-mapping block. | derived |
| [`hdr_tmo_write_gain_table`](../../src/leon2s/hdr/hdr_tmo_write_gain_table.c) | `FUN_a00d2f20` | Write the running sums of a byte table to the tone-mapping block. | descriptive |
| `hdr_tmo_write_gain_table_jump_table` | `switchdataD_a00d2f00` | Jump table 1 of the switch statements in hdr_tmo_write_gain_table. | proven |
| [`hdr_update_and_ack_tmds_port0`](../../src/leon2s/hdr/hdr_update_and_ack_tmds_port0.c) | `FUN_a00914c4` | Update HDR10+ data of HDMI receiver 0 and clear its packet status bit. | derived |
| [`hdr_update_and_ack_tmds_port1`](../../src/leon2s/hdr/hdr_update_and_ack_tmds_port1.c) | `FUN_a00914e0` | Update HDR10+ data of HDMI receiver 1 and clear its packet status bit. | derived |
| [`hdr_update_hdr10plus_hdmi21_port0`](../../src/leon2s/hdr/hdr_update_hdr10plus_hdmi21_port0.c) | `FUN_a00638cc` | Run the HDR10+ update when receiver 2 (HDMI 2.1 port 0) is the selected source. | derived |
| [`hdr_update_hdr10plus_hdmi21_port1`](../../src/leon2s/hdr/hdr_update_hdr10plus_hdmi21_port1.c) | `FUN_a00638a0` | Run the HDR10+ update when receiver 3 (HDMI 2.1 port 1) is the selected source. | derived |
| [`hdr_update_hdr10plus_metadata`](../../src/leon2s/hdr/hdr_update_hdr10plus_metadata.c) | `FUN_a006370c` | Check the receiver for a new HDR10+ packet and rebuild the tone curve when its content changed. | proven |
| [`hdr_update_hdr10plus_tmds_port0`](../../src/leon2s/hdr/hdr_update_hdr10plus_tmds_port0.c) | `FUN_a0063924` | Run the HDR10+ update when receiver 0 (HDMI 2.0 port 0) is the selected source. | derived |
| [`hdr_update_hdr10plus_tmds_port1`](../../src/leon2s/hdr/hdr_update_hdr10plus_tmds_port1.c) | `FUN_a00638f8` | Run the HDR10+ update when receiver 1 (HDMI 2.0 port 1) is the selected source. | derived |
| [`hdr_update_smoothed_level`](../../src/leon2s/hdr/hdr_update_smoothed_level.c) | `FUN_a00d378c` | Compute the new target level and smooth towards it. | descriptive |
| [`hdr_update_tone_curve`](../../src/leon2s/hdr/hdr_update_tone_curve.c) | `FUN_a00d3364` | Derive the curve parameters from the HDR mastering luminance and program the curve block. | derived |

<a id="osd"></a>
## On-screen menu

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`osd_read_memory_blocks`](../../src/leon2s/osd/osd_read_memory_blocks.c) | `FUN_a006c9c0` | Read 8-word blocks of packed data through the 0xCF011F80 register port. | derived |
| [`osd_read_packed_chunk`](../../src/leon2s/osd/osd_read_packed_chunk.c) | `FUN_a006cb98` | Read one chunk of up to 480 packed words for the OSD unpacker. | derived |
| [`osd_request_unzip`](../../src/leon2s/osd/osd_request_unzip.c) | `FUN_a006cfac` | Queue an OSD unpack request and report it busy to the main processor. | proven |
| [`osd_run_pending_unzip`](../../src/leon2s/osd/osd_run_pending_unzip.c) | `FUN_a006cfe8` | Run a queued OSD unpack request and report completion. | proven |
| [`osd_unzip_data`](../../src/leon2s/osd/osd_unzip_data.c) | `FUN_a006cc24` | Expand run-length packed OSD data into 256-word blocks and write them to OSD memory. | proven |
| [`osd_write_memory_blocks`](../../src/leon2s/osd/osd_write_memory_blocks.c) | `FUN_a006c788` | Write unpacked 8-word blocks into OSD memory, directly or through the register port. | derived |

<a id="audio"></a>
## Sound

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`audio_calc_dp_sample_rate`](../../src/leon2s/audio/audio_calc_dp_sample_rate.c) | `FUN_a008c538` | Compute the audio sample rate of a DP receiver in Hz. | proven |
| [`audio_calc_hdmi21_sample_rate`](../../src/leon2s/audio/audio_calc_hdmi21_sample_rate.c) | `FUN_a00a211c` | Compute the audio sample rate of an HDMI 2.1 receiver from N, CTS and link clock. | proven |
| `audio_calc_hdmi21_sample_rate_jump_table` | `switchdataD_a00a2100` | Jump table 1 of the switch statements in audio_calc_hdmi21_sample_rate. | proven |
| [`audio_calc_hdmi_sample_rate`](../../src/leon2s/audio/audio_calc_hdmi_sample_rate.c) | `FUN_a0091388` | Compute the audio sample rate of an HDMI receiver from N and CTS. | proven |
| [`audio_check_dp_fifo_unmute`](../../src/leon2s/audio/audio_check_dp_fifo_unmute.c) | `FUN_a008b9ec` | Unmute DP audio once the stream has been stable long enough. | proven |
| [`audio_check_hdmi21_rate_valid`](../../src/leon2s/audio/audio_check_hdmi21_rate_valid.c) | `FUN_a00a2230` | Report every 40 ticks whether an HDMI 2.1 receiver's audio rate is in range. | derived |
| [`audio_check_hdmi_rate_valid`](../../src/leon2s/audio/audio_check_hdmi_rate_valid.c) | `FUN_a0091420` | Report every 40 ticks whether an HDMI receiver's audio rate is in range. | derived |
| [`audio_clear_dp_status`](../../src/leon2s/audio/audio_clear_dp_status.c) | `FUN_a008b8ac` | Clear the audio status registers 3 and 4 of a DP receiver. | descriptive |
| [`audio_clear_level_step`](../../src/leon2s/audio/audio_clear_level_step.c) | `FUN_a008a9b0` | Clear the audio level step registers when a step is pending. | descriptive |
| [`audio_clear_main_enable`](../../src/leon2s/audio/audio_clear_main_enable.c) | `FUN_a008a7a0` | Clear bit 0 of the main audio control register. | descriptive |
| [`audio_configure`](../../src/leon2s/audio/audio_configure.c) | `FUN_a008cba8` | Store the 3-byte audio configuration and initialise the audio block with it. | derived |
| [`audio_dp_status_bit4`](../../src/leon2s/audio/audio_dp_status_bit4.c) | `FUN_a008b8f4` | Return bit 4 of audio status register 4 of a DP receiver. | descriptive |
| [`audio_dp_status_bit6`](../../src/leon2s/audio/audio_dp_status_bit6.c) | `FUN_a008b8d4` | Return bit 6 of audio status register 4 of a DP receiver. | descriptive |
| [`audio_enable_unit_dp`](../../src/leon2s/audio/audio_enable_unit_dp.c) | `FUN_a008b75c` | Enable or disable an audio unit fed by a DP source. | descriptive |
| [`audio_enable_unit_hdmi`](../../src/leon2s/audio/audio_enable_unit_hdmi.c) | `FUN_a008b5d0` | Enable or disable an audio unit fed by an HDMI source. | descriptive |
| [`audio_find_outputs_of_source`](../../src/leon2s/audio/audio_find_outputs_of_source.c) | `FUN_a0089f98` | Return a mask of the audio outputs that use a given source. | derived |
| [`audio_flag_dp_resync`](../../src/leon2s/audio/audio_flag_dp_resync.c) | `FUN_a008ae18` | Mark a DP audio source for a fresh FIFO set-up. | descriptive |
| [`audio_get_output_source`](../../src/leon2s/audio/audio_get_output_source.c) | `FUN_a0089f84` | Return the source id routed to one audio output. | derived |
| [`audio_get_source_unit`](../../src/leon2s/audio/audio_get_source_unit.c) | `FUN_a008a040` | Return the audio unit (0..3) a source is assigned to. | derived |
| `audio_get_source_unit_jump_table` | `switchdataD_a0089ff4` | Jump table 1 of the switch statements in audio_get_source_unit. | proven |
| [`audio_init_ctrl_registers`](../../src/leon2s/audio/audio_init_ctrl_registers.c) | `FUN_a008a6f4` | Load fixed values into the audio control registers. | descriptive |
| [`audio_init_main_registers`](../../src/leon2s/audio/audio_init_main_registers.c) | `FUN_a008a470` | Load the start values of the main audio control registers. | descriptive |
| [`audio_init_register_groups`](../../src/leon2s/audio/audio_init_register_groups.c) | `FUN_a008a590` | Load seven fixed register groups of the audio interface block. | descriptive |
| [`audio_is_source_selected`](../../src/leon2s/audio/audio_is_source_selected.c) | `FUN_a008b2bc` | Return whether a source number is set in the audio select registers. | descriptive |
| [`audio_mute_dp_fifo`](../../src/leon2s/audio/audio_mute_dp_fifo.c) | `FUN_a008b934` | Mute the audio FIFO of a DP receiver and mark it muted. | derived |
| [`audio_poll_dp_status`](../../src/leon2s/audio/audio_poll_dp_status.c) | `FUN_a008bc44` | Sample the audio status of both DP receivers and return them as two bits. | descriptive |
| [`audio_read_dp_maud`](../../src/leon2s/audio/audio_read_dp_maud.c) | `FUN_a008b838` | Return the audio M value (Maud) of a DP receiver. | derived |
| [`audio_read_dp_naud`](../../src/leon2s/audio/audio_read_dp_naud.c) | `FUN_a008b850` | Return the audio N value (Naud) of a DP receiver, never 0. | derived |
| [`audio_reg_read8`](../../src/leon2s/audio/audio_reg_read8.c) | `FUN_a00a71b4` | Read a byte register of an audio unit. | proven |
| [`audio_reg_write8`](../../src/leon2s/audio/audio_reg_write8.c) | `FUN_a00a7168` | Write a byte register of an audio unit. | proven |
| [`audio_reg_write_masked`](../../src/leon2s/audio/audio_reg_write_masked.c) | `FUN_a00a71fc` | Replace the masked bits of a register of one or all four audio units. | proven |
| [`audio_reset_dp_fifo`](../../src/leon2s/audio/audio_reset_dp_fifo.c) | `FUN_a008b6f4` | Reset the audio FIFO of a DP receiver. | derived |
| [`audio_reset_output_regs`](../../src/leon2s/audio/audio_reset_output_regs.c) | `FUN_a008a7bc` | Reset seven audio output registers to 0x88. | descriptive |
| [`audio_route_source`](../../src/leon2s/audio/audio_route_source.c) | `FUN_a008c9a8` | Route an audio source to an output and set up its audio unit. | derived |
| [`audio_run_service`](../../src/leon2s/audio/audio_run_service.c) | `FUN_a008c8b0` | Run the regular audio checks: DP FIFO unmute, unit options and unit states. | derived |
| [`audio_set_config_bit6`](../../src/leon2s/audio/audio_set_config_bit6.c) | `FUN_a008a1f8` | Write 0x40 to the audio configuration register when the argument is 1. | descriptive |
| [`audio_set_dp_rx_level`](../../src/leon2s/audio/audio_set_dp_rx_level.c) | `FUN_a008a9ec` | Write a 16-bit audio level to a DisplayPort receiver. | descriptive |
| [`audio_set_dp_unit_option`](../../src/leon2s/audio/audio_set_dp_unit_option.c) | `FUN_a008a1b4` | Set the DP option bit of an audio unit. | descriptive |
| [`audio_set_hdmi21_rx_level`](../../src/leon2s/audio/audio_set_hdmi21_rx_level.c) | `FUN_a008aadc` | Write a 16-bit audio level to an HDMI 2.1 receiver. | descriptive |
| [`audio_set_hdmi21_unit_option`](../../src/leon2s/audio/audio_set_hdmi21_unit_option.c) | `FUN_a008a110` | Set the HDMI 2.1 option bit of an audio unit. | descriptive |
| [`audio_set_hdmi_rx_level`](../../src/leon2s/audio/audio_set_hdmi_rx_level.c) | `FUN_a008aab0` | Write a 16-bit audio level to an HDMI 2.0 receiver. | descriptive |
| [`audio_set_hdmi_rx_reg126_bit5`](../../src/leon2s/audio/audio_set_hdmi_rx_reg126_bit5.c) | `FUN_a0090e4c` | Set or clear bit 5 of HDMI receiver audio register 0x126. | descriptive |
| [`audio_set_hdmi_rx_reg126_mode`](../../src/leon2s/audio/audio_set_hdmi_rx_reg126_mode.c) | `FUN_a0090e6c` | Set the mode bits 0 and 2 of HDMI receiver audio register 0x126. | descriptive |
| [`audio_set_hdmi_tx_source`](../../src/leon2s/audio/audio_set_hdmi_tx_source.c) | `FUN_a0091ebc` | Store the audio source of an HDMI TX port and reset its audio input. | derived |
| [`audio_set_input_levels`](../../src/leon2s/audio/audio_set_input_levels.c) | `FUN_a008aaf8` | Apply a 16-bit audio level to all HDMI and DP receivers. | descriptive |
| [`audio_set_mute`](../../src/leon2s/audio/audio_set_mute.c) | `FUN_a008a868` | Mute or unmute the audio outputs selected in the audio configuration. | derived |
| [`audio_set_output0_mute`](../../src/leon2s/audio/audio_set_output0_mute.c) | `FUN_a008a824` | Mute or unmute audio output 0. | derived |
| [`audio_set_output_level`](../../src/leon2s/audio/audio_set_output_level.c) | `FUN_a008aa18` | Apply a 16-bit level to the main audio output for its current source. | descriptive |
| [`audio_set_output_source`](../../src/leon2s/audio/audio_set_output_source.c) | `FUN_a008b32c` | Route an audio source to one audio output. | derived |
| `audio_set_output_source_jump_table` | `switchdataD_a008b308` | Jump table 1 of the switch statements in audio_set_output_source. | proven |
| [`audio_set_shared_enable_bits`](../../src/leon2s/audio/audio_set_shared_enable_bits.c) | `FUN_a008a238` | Set enable bits 4..7 of a shared audio register under the hardware lock. | descriptive |
| `audio_set_shared_enable_bits_jump_table` | `switchdataD_a008a224` | Jump table 1 of the switch statements in audio_set_shared_enable_bits. | proven |
| [`audio_set_source_enable`](../../src/leon2s/audio/audio_set_source_enable.c) | `FUN_a008ae80` | Switch the audio capture of one source on or off. | derived |
| `audio_set_source_enable_jump_table` | `switchdataD_a008ae34` | Jump table 1 of the switch statements in audio_set_source_enable. | proven |
| [`audio_set_source_unit`](../../src/leon2s/audio/audio_set_source_unit.c) | `FUN_a008aba8` | Assign an audio source to an audio unit (the DP sources 4..7 have fixed units 0..3). | derived |
| `audio_set_source_unit_jump_table` | `switchdataD_a008ab5c` | Jump table 1 of the switch statements in audio_set_source_unit. | proven |
| [`audio_set_unit_frequency`](../../src/leon2s/audio/audio_set_unit_frequency.c) | `FUN_a008b53c` | Program the frequency word of one audio unit. | descriptive |
| [`audio_set_unit_mode`](../../src/leon2s/audio/audio_set_unit_mode.c) | `FUN_a008bd1c` | Set the 2-bit mode field of an audio unit. | descriptive |
| [`audio_setup_unit`](../../src/leon2s/audio/audio_setup_unit.c) | `FUN_a008bddc` | Program an audio unit for the type of source assigned to it. | derived |
| `audio_setup_unit_jump_table` | `switchdataD_a008bd48` | Jump table 1 of the switch statements in audio_setup_unit. | proven |
| [`audio_start_level_step`](../../src/leon2s/audio/audio_start_level_step.c) | `FUN_a008a974` | Arm the audio level step registers with a start value. | descriptive |
| [`audio_unmute_dp_fifo`](../../src/leon2s/audio/audio_unmute_dp_fifo.c) | `FUN_a008b9b0` | Reset and unmute the audio FIFO of a DP receiver. | derived |
| [`audio_update_dp_32k_mode`](../../src/leon2s/audio/audio_update_dp_32k_mode.c) | `FUN_a008c5d8` | Switch an audio unit's 32 kHz setting when the DP sample rate enters or leaves it. | derived |
| [`audio_update_dp_maud_flag`](../../src/leon2s/audio/audio_update_dp_maud_flag.c) | `FUN_a008b694` | Set a DP receiver audio flag when the Maud low byte is far from 0x80. | descriptive |
| [`audio_update_units`](../../src/leon2s/audio/audio_update_units.c) | `FUN_a008c6f8` | Enable or disable each used audio unit by the state of its input port. | derived |
| [`audio_write_level_high_byte`](../../src/leon2s/audio/audio_write_level_high_byte.c) | `FUN_a008a95c` | Write a level byte to the audio register 0xCF0110E4. | descriptive |
| [`audio_write_level_regs`](../../src/leon2s/audio/audio_write_level_regs.c) | `FUN_a008a924` | Write a 16-bit level value to the two audio level register pairs. | descriptive |

<a id="ipc"></a>
## Messages between the processors

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`ipc_build_port_descriptor`](../../src/leon2s/ipc/ipc_build_port_descriptor.c) | `FUN_a006fbac` | Build the 4-word mailbox descriptor of one input port. | proven |
| [`ipc_dispatch_command`](../../src/leon2s/ipc/ipc_dispatch_command.c) | `FUN_a0070b7c` | Carry out one command message received from the main processor. | proven |
| `ipc_dispatch_command_jump_table` | `switchdataD_a0070728` | Jump table 1 of the switch statements in ipc_dispatch_command. | proven |
| `ipc_dispatch_command_jump_table2` | `switchdataD_a0070740` | Jump table 2 of the switch statements in ipc_dispatch_command. | proven |
| `ipc_dispatch_command_jump_table3` | `switchdataD_a0070758` | Jump table 3 of the switch statements in ipc_dispatch_command. | proven |
| `ipc_dispatch_command_jump_table4` | `switchdataD_a007077c` | Jump table 4 of the switch statements in ipc_dispatch_command. | proven |
| [`ipc_init_mailbox`](../../src/leon2s/ipc/ipc_init_mailbox.c) | `FUN_a0072958` | Write 0 to the word at 0x9F130000, 0x100 below mailbox portal 1, at start-up. | descriptive |
| [`ipc_mailbox_read`](../../src/leon2s/ipc/ipc_mailbox_read.c) | `FUN_a0072970` | Read words from mailbox portal 0 or 1. | proven |
| [`ipc_mailbox_write`](../../src/leon2s/ipc/ipc_mailbox_write.c) | `FUN_a0072a4c` | Write words to mailbox portal 0 or 1. | proven |
| [`ipc_poll_command`](../../src/leon2s/ipc/ipc_poll_command.c) | `FUN_a0072900` | Read a command message from the main processor and carry it out when valid. | proven |
| [`ipc_post_ready_flag`](../../src/leon2s/ipc/ipc_post_ready_flag.c) | `FUN_a006fb00` | Set the ready bit in mailbox slot 0 for the main processor. | derived |
| [`ipc_publish_port_status`](../../src/leon2s/ipc/ipc_publish_port_status.c) | `FUN_a00700cc` | Send the changed input port records and the HPD status to the main processor. | proven |
| [`ipc_publish_status_flags`](../../src/leon2s/ipc/ipc_publish_status_flags.c) | `FUN_a006fedc` | Publish eight status flags (OSD unzip busy and others) to the main processor. | derived |
| [`ipc_read_mailbox_slot`](../../src/leon2s/ipc/ipc_read_mailbox_slot.c) | `FUN_a006faa8` | Read words from a mailbox slot shared with the main processor. | proven |
| [`ipc_read_port_id_list`](../../src/leon2s/ipc/ipc_read_port_id_list.c) | `FUN_a006fca8` | Read the seven port ids the main processor assigned to the mailbox slots. | derived |
| [`ipc_release_8051_access`](../../src/leon2s/ipc/ipc_release_8051_access.c) | `FUN_a0062b94` | Tell the 8051 controller the shared table write is finished. | derived |
| [`ipc_request_8051_access`](../../src/leon2s/ipc/ipc_request_8051_access.c) | `FUN_a0062f3c` | Ask the 8051 controller for access to the shared table and wait for its grant. | derived |
| [`ipc_send_reply`](../../src/leon2s/ipc/ipc_send_reply.c) | `FUN_a006fd78` | Send a reply message with id and up to 28 data bytes in mailbox slot 10. | derived |
| [`ipc_set_message_checksum`](../../src/leon2s/ipc/ipc_set_message_checksum.c) | `FUN_a006fb3c` | Store the XOR checksum of a mailbox message in its top byte. | proven |
| [`ipc_set_port_changed_bit`](../../src/leon2s/ipc/ipc_set_port_changed_bit.c) | `FUN_a006fc58` | Set the changed bit of one port in the mailbox status word. | derived |
| [`ipc_verify_message`](../../src/leon2s/ipc/ipc_verify_message.c) | `FUN_a006fd04` | Check the 0x55 marker and the XOR checksum of a received mailbox message. | proven |
| [`ipc_write_mailbox_slot`](../../src/leon2s/ipc/ipc_write_mailbox_slot.c) | `FUN_a006fad4` | Write words to a mailbox slot shared with the main processor. | proven |

<a id="uart"></a>
## Serial ports

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`uart_init`](../../src/leon2s/uart/uart_init.c) | `FUN_a0072b7c` | Reset and configure the debug console UART and enable its receive interrupt. | derived |
| [`uart_put_char`](../../src/leon2s/uart/uart_put_char.c) | `FUN_a006122c` | Send one character on the debug console UART. | proven |
| [`uart_put_hex8`](../../src/leon2s/uart/uart_put_hex8.c) | `FUN_a00613cc` | Print a byte as two hexadecimal digits on the debug console. | proven |
| [`uart_put_hex32`](../../src/leon2s/uart/uart_put_hex32.c) | `FUN_a0061348` | Print a 32-bit value as eight hexadecimal digits on the debug console. | proven |
| [`uart_put_string`](../../src/leon2s/uart/uart_put_string.c) | `FUN_a0061280` | Send a zero-terminated string on the debug console, adding a carriage return after each line feed. | proven |
| [`uart_read_rx_byte`](../../src/leon2s/uart/uart_read_rx_byte.c) | `FUN_a0072c6c` | Take the next received byte from the debug console ring buffer. | proven |
| [`uart_rx_isr`](../../src/leon2s/uart/uart_rx_isr.c) | `FUN_a0061450` | Store a received debug-console byte in the receive ring buffer. | proven |

<a id="reg"></a>
## Register access

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`reg_clear_bit`](../../src/leon2s/reg/reg_clear_bit.c) | `FUN_a00a73d4` | Clear bit n of a word array (register block). | proven |
| [`reg_read8`](../../src/leon2s/reg/reg_read8.c) | `FUN_a006155c` | Read one byte of a register through an aligned 32-bit access. | proven |
| [`reg_read8_wrapper`](../../src/leon2s/reg/reg_read8_wrapper.c) | `FUN_a00615dc` | Read one byte of a register (out-of-line wrapper of reg_read8). | derived |
| [`reg_read32`](../../src/leon2s/reg/reg_read32.c) | `FUN_a0061528` | Read a 32-bit hardware register. | proven |
| [`reg_read32_copy`](../../src/leon2s/reg/reg_read32_copy.c) | `FUN_a00618c0` | Read a 32-bit hardware register. | proven |
| [`reg_read32_wrapper`](../../src/leon2s/reg/reg_read32_wrapper.c) | `FUN_a00615ac` | Read a 32-bit hardware register (out-of-line wrapper of reg_read32). | derived |
| [`reg_read_list_word`](../../src/leon2s/reg/reg_read_list_word.c) | `FUN_a00a6544` | Read a 32-bit register of the first block of a register list. | derived |
| [`reg_read_port_indirect`](../../src/leon2s/reg/reg_read_port_indirect.c) | `FUN_a0061eb4` | Read through the index register 0x1B8 of a receiver port block; registers other than 0x1B8 give 0. | descriptive |
| [`reg_read_word`](../../src/leon2s/reg/reg_read_word.c) | `FUN_a00b22fc` | Return the word at an address. | derived |
| [`reg_set_bit`](../../src/leon2s/reg/reg_set_bit.c) | `FUN_a00a73ac` | Set bit n of a word array (register block). | proven |
| [`reg_test_bit`](../../src/leon2s/reg/reg_test_bit.c) | `FUN_a00a7408` | Return bit n of a word array (register block). | proven |
| [`reg_write8`](../../src/leon2s/reg/reg_write8.c) | `FUN_a0061578` | Write one byte of a register through an aligned 32-bit read-modify-write. | proven |
| [`reg_write8_wrapper`](../../src/leon2s/reg/reg_write8_wrapper.c) | `FUN_a00615f4` | Write one byte of a register (out-of-line wrapper of reg_write8). | derived |
| [`reg_write32`](../../src/leon2s/reg/reg_write32.c) | `FUN_a0061534` | Write a 32-bit hardware register. | proven |
| [`reg_write32_copy`](../../src/leon2s/reg/reg_write32_copy.c) | `FUN_a00618cc` | Write a 32-bit hardware register. | proven |
| [`reg_write32_masked`](../../src/leon2s/reg/reg_write32_masked.c) | `FUN_a0061540` | Change only the masked bits of a 32-bit hardware register. | proven |
| [`reg_write32_masked_wrapper`](../../src/leon2s/reg/reg_write32_masked_wrapper.c) | `FUN_a00615cc` | Change the masked bits of a 32-bit register (out-of-line wrapper of reg_write32_masked). | derived |
| [`reg_write32_wrapper`](../../src/leon2s/reg/reg_write32_wrapper.c) | `FUN_a00615bc` | Write a 32-bit hardware register (out-of-line wrapper of reg_write32). | derived |
| [`reg_write_bit_field`](../../src/leon2s/reg/reg_write_bit_field.c) | `FUN_a00614b8` | Replace bits lo..hi of a word with a value. | proven |
| [`reg_write_bit_field_copy`](../../src/leon2s/reg/reg_write_bit_field_copy.c) | `FUN_a0061a6c` | Replace bits lo..hi of a word with a value. | proven |
| [`reg_write_bit_range`](../../src/leon2s/reg/reg_write_bit_range.c) | `FUN_a00d21e0` | Write a value into the bits lo..hi of a register. | proven |
| [`reg_write_word`](../../src/leon2s/reg/reg_write_word.c) | `FUN_a00b2304` | Store a word at an address. | derived |
| [`SC_MaskSetByte`](../../src/leon2s/reg/SC_MaskSetByte.c) | `SC_MaskSetByte` | Write masked bits to a register of one or all blocks of a register list. | proven |

<a id="dbg"></a>
## Debug facilities

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`dbg_cmd_mailbox_dump`](../../src/leon2s/dbg/dbg_cmd_mailbox_dump.c) | `FUN_a0070704` | Console command: print the mailbox contents. | derived |
| [`dbg_command_line_init`](../../src/leon2s/dbg/dbg_command_line_init.c) | `FUN_a00b34a8` | Reset the command line state and print the welcome banner. | proven |
| [`dbg_dump_memory_bytes`](../../src/leon2s/dbg/dbg_dump_memory_bytes.c) | `CED_ALL_2` | Print memory as lines of address, bytes and characters. | proven |
| [`dbg_dump_memory_words`](../../src/leon2s/dbg/dbg_dump_memory_words.c) | `CED_ALL_3` | Print memory as lines of four words. | proven |
| [`dbg_format_hex32`](../../src/leon2s/dbg/dbg_format_hex32.c) | `FUN_a00b281c` | Write a value as eight upper-case hexadecimal digits into a buffer. | proven |
| [`dbg_format_number`](../../src/leon2s/dbg/dbg_format_number.c) | `FUN_a0072e60` | Format an unsigned number in a base with padding and sign for the printf. | proven |
| [`dbg_handle_input_line`](../../src/leon2s/dbg/dbg_handle_input_line.c) | `FUN_a00b28d0` | Handle a line typed on the debug serial port: memory read and write lines and named commands. | proven |
| [`dbg_hdmi_menu_wrapper`](../../src/leon2s/dbg/dbg_hdmi_menu_wrapper.c) | `FUN_a00a1e18` | Run the HDMI debug menu command. | derived |
| [`dbg_line_checksum_digit`](../../src/leon2s/dbg/dbg_line_checksum_digit.c) | `FUN_a00b288c` | Compute the check digit: '0' plus the low four bits of the byte sum of two 32-bit values. | derived |
| [`dbg_parse_hex_digits`](../../src/leon2s/dbg/dbg_parse_hex_digits.c) | `FUN_a00b2790` | Convert a number of hexadecimal characters to a value. | proven |
| [`dbg_parse_number`](../../src/leon2s/dbg/dbg_parse_number.c) | `FUN_a00b25f8` | Convert a text of up to 32 characters to a number, hexadecimal with 0x or decimal. | proven |
| [`dbg_print_string`](../../src/leon2s/dbg/dbg_print_string.c) | `FUN_a00734c4` | Print a plain string on the debug console. | proven |
| [`dbg_printf`](../../src/leon2s/dbg/dbg_printf.c) | `FUN_a0073044` | Print formatted text on the debug console (printf). | proven |
| [`dbg_report_stack_overflow`](../../src/leon2s/dbg/dbg_report_stack_overflow.c) | `FUN_a00b1cb0` | Print the stack overflow message with two core register values. | proven |
| [`dbg_set_hdmi_message_flags`](../../src/leon2s/dbg/dbg_set_hdmi_message_flags.c) | `EN_HDMI_MSG_INIT_INFO` | Switch HDMI debug message groups on or off and list their state. | proven |
| [`dbg_strcmp`](../../src/leon2s/dbg/dbg_strcmp.c) | `FUN_a00b1568` | Compare two texts. | proven |
| [`dbg_strlen`](../../src/leon2s/dbg/dbg_strlen.c) | `FUN_a00b1538` | Return the length of a text. | proven |
| [`dbg_write_chars`](../../src/leon2s/dbg/dbg_write_chars.c) | `FUN_a0072fd8` | Write n characters to the debug console, adding a carriage return after each line feed. | proven |
| [`dbg_write_memory_word`](../../src/leon2s/dbg/dbg_write_memory_word.c) | `CED_ALL_4` | Store a word at an address and print it. | proven |
| [`MAILBOX_DUMP`](../../src/leon2s/dbg/MAILBOX_DUMP.c) | `MAILBOX_DUMP` | Print the 48 words of mailbox portal 1 on the debug console. | proven |

<a id="lib"></a>
## Library routines

| Name | Label | What it does | Basis |
|---|---|---|---|
| [`lib_copy_bytes_word_access`](../../src/leon2s/lib/lib_copy_bytes_word_access.c) | `FUN_a0061608` | Copy bytes, writing the middle part as aligned 32-bit words. | derived |
| [`lib_copy_words`](../../src/leon2s/lib/lib_copy_words.c) | `FUN_a00b1508` | Copy a number of 32-bit words. | proven |
| [`lib_div_round_up`](../../src/leon2s/lib/lib_div_round_up.c) | `FUN_a00617f0` | Divide and round the result up. | proven |
| [`lib_interpolate_clamped`](../../src/leon2s/lib/lib_interpolate_clamped.c) | `FUN_a0062718` | Interpolate linearly between two values and clamp outside the given range. | derived |
| [`lib_make_bit_range_mask`](../../src/leon2s/lib/lib_make_bit_range_mask.c) | `FUN_a0089058` | Return a byte with bits first..last set. | proven |
| [`lib_memcpy`](../../src/leon2s/lib/lib_memcpy.c) | `FUN_a00b15d8` | Copy a block of memory. | proven |
| [`lib_memset`](../../src/leon2s/lib/lib_memset.c) | `FUN_a00b15ac` | Fill a block of memory with one byte value. | proven |
| [`lib_round_up_to_multiple`](../../src/leon2s/lib/lib_round_up_to_multiple.c) | `FUN_a006182c` | Round a value up to a multiple of another. | proven |
| [`lib_swap_word_bytes`](../../src/leon2s/lib/lib_swap_word_bytes.c) | `FUN_a0061864` | Reverse the byte order of each 32-bit word in a buffer. | proven |
| [`lib_write_masked_byte`](../../src/leon2s/lib/lib_write_masked_byte.c) | `FUN_a00a6428` | Replace the masked bits of a 32-bit word in memory and clear every bit above bit 7. | descriptive |
