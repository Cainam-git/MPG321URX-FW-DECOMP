! trap_window_underflow_entry  (FUN_a0028060)
!
! Trap table slot 0x06 (window underflow): reads %psr and %tbr and jumps to the handler at 0xa00292d0.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2m FUN_a0028060 @ 0xa0028060  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028060
	.type FUN_a0028060, #function
FUN_a0028060:
! Slot of trap type 0x06, window_underflow. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! the window-underflow handler in trap_handle_faults (0xA00292D0), which reloads
! the register window below from its stack so that the RESTORE can be retried.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0029000), %l4       ! upper bits of the handler address 0xA00292D0
	jmp  %l4 + 0x2d0                  ! jump to 0xA00292D0: window-underflow handler
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0028060, .-FUN_a0028060
