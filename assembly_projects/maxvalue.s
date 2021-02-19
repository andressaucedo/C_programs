#ASM
#PURPOSE: This program finds the highest value item in a set of data items
#
#
#VARIABLES
#
# %edi    # holds current position in list
# %ebx    # holds current highest value in list
# %eax    # holds current element being examined
#
#  The following memory locations are used:
# data_items    # address where list is stored
#

.section .data

data_items:
.long 3,67,34,222,45,75,54,34,44,33,22,11,66,0

.section .text

.globl _start
_start:
movl $0, %edi     # move 0 into the index register
movl data_items (,%edi,4), %eax     #load the first byte of data
movl %eax, %ebx     # since this is the first time, %eax is the largest

start_loop:       # start program loop
  cmpl $0, %eax     #check to see if we've hit the end
  je loop_exit
  incl %edi     # load next value
  movl data_items(,%edi,4), %eax
  cmpl %ebx, %eax     # compare values
  jle start_loop      # jump to loop beginning if %eax < %ebx
  movl %eax, %ebx     # move value to the largest placeholder
  jmp start_loop      # jump loop to the beginning

  loop_exit:
  # %ebx is the return value, and it already has the number
    movl $1, %eax     # 1 is the exit() syscall
    int $0x80
