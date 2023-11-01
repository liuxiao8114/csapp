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
...
We will focus on the key abstractions that a process provides to the application:
+ An independent logical control flow that provides the illusion that our program has exclusive use of the processor.
+ A private address space that provides the illusion that our program has exclusive use of the memory system.

### 8.2.1 Logical Control Flow
we would observe a series of program counter (PC) values that
corresponded exclusively to instructions contained in our program’s executable
object file or in shared objects linked into our program dynamically at run time.
This sequence of PC values is known as a logical control flow, or simply logical.
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
 + Running.
 + Stopped. The execution of the process is suspended and will not be scheduled.
    A process stops as a result of receiving a SIGSTOP, SIGTSTP, SIGTTIN,
    or SIGTTOU signal, and it remains stopped until it receives a SIGCONT
    signal, at which point it becomes running again.
 + Terminated. The process is stopped permanently.
  1) receiving a signal whose default action is to terminate the process
  2) returning from the main routine
  3) calling the exit function

+ exit: terminates the process with an exit status
+ fork: A parent process creates a new running child process
  +
  + diff: PIDs

### 8.4.3 Reaping Child Processes
When a process terminates for any reason, the kernel does not remove it from
the system immediately. Instead, the process is kept around in a terminated state
until it is reaped by its parent. When the parent reaps the terminated child, the
kernel passes the child's exit status to the parent and then discards the terminated
process, at which point it ceases to exist. A terminated process that has not yet
been reaped is called a zombie.
When a parent process terminates, the kernel arranges for the init process
to become the adopted parent of any orphaned children. The init process, which
has a PID of 1, is created by the kernel during system start-up, never terminates,
and is the ancestor of every process. If a parent process terminates without reaping
its zombie children, then the kernel arranges for the init process to reap them.
However, long-running programs such as shells or servers should always reap their
zombie children. Even though zombies are not running, they still consume system
memory resources.
A process waits for its children to terminate or stop by calling the waitpid
function.
+ waitpid: A process waits for its children to terminate or stop
```c
pid_t waitpid(pid_t pid, int *statusp, int options);
// returns PID of child if OK, 0(if WNOHANG), or -1 on error
```

By default, waitpid suspends execution of the calling process until a child process in its wait set terminates.
If a process in the wait set has already terminated at the time of the call, then waitpid returns immediately.
In either case, waitpid returns the PID of the terminated child that caused waitpid to return.
At this point, the terminated child has been reaped and the kernel removes all traces of it from the system.

#### Determining the Members of the Wait Set
The
#### Checking the Exit status of a Reaped Child
If the statusp pointer is not NULL
WIF
WEXITSTATUS(status)

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

Fig 8.27 Signal handling
  |
  | 1) Signal received by process
Icurr ----> 2) Control passes to signal handler
          | 3) Signal handler runs
Inext <---- 4) Signal handler returns to next instruction
  |        
  |

### 8.5.2 Sending Signals
#### Process Groups
#### Sending Signals with the /bin/kill Program
#### Sending Signals from the keyboard
#### Sending Signals with the kill Function
#### Sending Signals with the alarm Function

### 8.5.3 Receiving Signals
When the kernel switches a process p from kernel mode to user mode(eg. returning from a system call or completing a context switch).


Fig 8.31 Handlers can be interrupted by other handlers
| 1) Program catches signal s
Icurr -> 2) Control passes to handler S
      |  3) Program catches signal t
      -----> 4) Control passes to handler T
           |
      <----- 5) Handler T returns to handler S
Inext <- 6) Handler S returns to main program
| 7) Main program resumes

### 8.5.4 Blocking and Unblocking Signals
+ signprocmask: changes the set of currently blocked signals
  int signprocmask(int how, sigset_t *set, sigset_t *blocked);

  SIG_BLOCK   blocked = blocked | set
  SIG_UNBLOCK blocked = blocked & ~set
  SIG_SETMASK blocked = set

### 8.5.5 Writing Signal Handlers
Protect accesses to shared global data structures by blocking all signals.
If a handler shares a global data structure with the main program or with
other handlers, then your handlers and main program should temporarily
block all signals while accessing (reading or writing) that data structure.
The reason for this rule is that accessing a data structure d from the main
program typically requires a sequence of instructions. If this instruction
sequence is interrupted by a handler that accesses d, then the handler
might find d in an inconsistent state, with unpredictable results. Temporarily
blocking signals while you access d guarantees that a handler will
not interrupt the instruction sequence.

### 8.5.6 Synchronizing Flows to Avoid Nasty Concurrency

### 8.5.7 Explicitly Waiting for Signals
when a Linux shell creates a foreground job, it must wait for it terminates and be reaped by the SIGCHLD handler before accepting the next user command.  

```c
  int sigsuspend(const sigset_t *mask);
```
The sigsuspend function temporarily replaces the current blocked set with mask and suspends the process until the receipt of a signal whose action is either to run a handler or to terminate the process.

##
