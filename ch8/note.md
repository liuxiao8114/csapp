# Chapter 8 Exceptional Control Flow
Systems must also be able to react to changes in system state that are not captured by internal program variables and are not necessarily related to the execution of the program.
Modern systems react to these situations by making abrupt changes as exceptional control flow.

+ exceptions lie at the intersection of the hardware and the operating system.
+ system calls are exceptions that provide applications with entry points into the operating system.
+ processes and signals lie at the intersection of applications and the operating system.
+ nonlocal jumps are an application-level form of ECF.

## 8.1 Exceptions
An exception is an abrupt change in the control flow in response to some change in the processor's state.
The state is encoded in various bits and signals inside the processor.
The change in state is known as an event. The event might be directly(VM page faults, arithmetic overflow, divide by zero) or unrelated(system timer off, IO request completes) to the execution of the current instruction.

when the processor detects that the event has occurred, it makes an indirect procedure call(the exception), through a jump table called an *exception table*, to an operating system subroutine(the *exception handler*) that is specifically designed to process the particular kind of event.

### 8.1.1 Exception Handling
At system boot time, the operating system allocates and initializes a jump table called an exception table.

An exception
+ Exception handlers run in *kernel mode*

### 8.1.2 Classes of Exceptions
Exceptions can be divided into four classes: *interrupts*, *traps*, *faults* and *aborts*.

Fig 8.4 Classes of exceptions
Class         Cause                             Async/sync
------------------------------------------------------------------
Interrupt     Signal from IO device             Async        Always
Trap          Intentional exception             Sync         Always
Fault         Potentially recoverable error     Sync         Might return to current
Abort         Nonrecoverable error

#### Interrupts

#### Traps and System Calls
The most important use of traps is to provide a procedure-like interface between user programs and the kernel, known as a system call.

#### Faults

### 8.1.3 Exceptions in Linux/x86-64 Systems
General protection fault(exception 13)
Page fault(exception 14): The handler maps the appropriate page of virtual memory on disk into a page of physical memory and then restarts the faulting instruction.

## 8.2 Processes
The classic definition of a process is an instance of a program in execution. Each program in the system runs in the context of some process. The context consists of the state that the program needs to run correctly.

### 8.2.1 Logical Control Flow
Processes take turns using the processor. Each

### 8.2.2 Concurrent Flows
+ concurrent flow
  A logical flow whose execution overlaps in time with another flow.
+ concurrency
+ multitasking
+ time slice

### 8.2.3 Private Address Space
### 8.2.4 User and Kernel Modes
A process running application code is initially in user mode. The only way for the process to change from user mode to kernel mode is via an exception such as an interrupt, a fault or a trapping system call.

### 8.2.5 Context Switches
The operating system kernel implements multitasking using a higher-level form of exceptional control flow known as a context switch. The kernel maintains a context for each process. The context is the state that the kernel needs to restart a preempted process. It consists of the values of objects such as:
+ the general-purpose registers
+ the floating-point registers
+ status registers
+ the program counter
+ user's stack
+ kernel's stack
+ various kernel data structures such as:
  + page table
  + process table
  + file table

## 8.3 System Call Error Handling

## 8.4 Process Control

### 8.4.1 Obtaining Process IDs
+ getpid

### 8.4.2 Creating and Terminating Processes
We can think of a process as being in one of three states:
Running
Stopped. The execution of the process is suspended and will not be scheduled.
Terminated. The process is stopped permanently.
  1) receiving a signal whose default action is to terminate the process
  2) returning from the main routine
  3) calling the exit function

+ exit: terminates the process with an exit status
+ fork: A parent process creates a new running child process
  +
  + diff: PIDs

### 8.4.3 Reaping Child Processes
+ waitpid: A process waits for its children to terminate or stop
```c
pid_t waitpid(pid_t pid, int *startusp, int options);
```

#### Determining the Members of the Wait Set
The
#### Checking the Exit status of a Reaped Child
#### Error Conditions

### 8.4.4 Putting Processes to Sleep
+ sleep
+ pause

### 8.4.5 Loading and Running Programs
+ execve
```c
#include <unistd.h>
int execve(const char *filenname)

```
Fig 8.22
Typical organization of the user stack when a new program starts

envp[0]
------------------------
argv[argc] = NULL
argv[argc-1]
...
argv[0]
------------------------
Stack frame for
libc_start_main
------------------------
Future stack frame for
main
------------------------

### 8.4.6 Using fork and execve to Run Programs
## 8.5 Signals
A signal is a small message that notifies a process that an event of some type has occurred in the system. Each signal type corresponds to some kind of system event. Signals provide a mechanism for exposing the occurrence of some exceptions to user processes.

### 8.5.1 Signal Terminology
+ Sending a signal
+ Receiving a signal
  signal handler
+ pending signal
  A signal that has been sent but not yet received is called a pending signal.
  A process can selectively block the receipt of certain signals. When a signal is blocked, it can be delivered, but the resulting pending signal will not be received until the process unblocks the signal.
  For each process, the kernel maintains the set of pending signals in the pending bit vector, and the set of blocked signals in the blocked bit vector.

Fig 8.27
Signal handling

  |
Icurr ->
        |
Inext <-
  |        

1.
2.
3.
4.

### 8.5.2 Sending Signals
#### Process Groups
#### Sending Signals with the /bin/kill Program
#### Sending Signals from the keyboard
#### Sending Signals with the kill Function
#### Sending Signals with the alarm Function

### 8.5.3 Receiving Signals
Fig 8.31 Handlers can be interrupted by other handlers

### 8.5.4 Blocking and Unblocking Signals
+ signprocmask: changes the set of currently blocked signals

### 8.5.5 Writing Signal Handlers

### 8.5.7 Explicitly Waiting for Signals
when a Linux shell creates a foreground job, it must wait for it terminates and be reaped by the SIGCHLD handler before accepting the next user command.  
