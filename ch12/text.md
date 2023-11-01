# 12
Applications that use application-level concurrency are known as *concurrent programs*. Three basis approaches for building concurrent programs:

 + Processes. Each logic control flow is a process that is scheduled and maintained by the kernel. Since each process has its own virtual address spaces, flows that want to communicate with each other must use some kinds of explicit *interprocess communication(IPC)* mechanism.
 + I/O multiplexing. Applications explicit schedule their own logical flow in the context of a single process. Logical flows are modeled as state machines that the main program explicitly transitions from state to state  
 + Threads. Logical flows that run in the context of a single process and are scheduled by the kernel.

## 12.1 Concurrent Programming with Processes
Suppose two clients and a server that is listening for connection requests on a listening descriptor(3). Now suppose that the server
After accepting the connection request, the server forks a child, which gets a complete copy of the server’s descriptor table.
The child closes its copy of listening descriptor 3, and the parent closes its copy of connected descriptor 4, since they are no longer needed.
Since the connected descriptors in the parent and child each point to the
same file table entry, it is crucial for the parent to close its copy of the connected descriptor. Otherwise, the file table entry for connected descriptor 4 will never be released, and the resulting memory leak will eventually consume the available memory and crash the system.
Now suppose that after the parent creates the child for client 1, it accepts
a new connection request from client 2 and returns a new connected descriptor
(say, 5), as shown in Figure 12.3. The parent then forks another child, which begins
servicing its client using connected descriptor 5, as shown in Figure 12.4. At this
point, the parent is waiting for the next connection request and the two children
are servicing their respective clients concurrently.

### 12.1.1 A Concurrent Server Based on Processes
Servers typically run for long periods of time, so we must include a SIGCHLD handler that reaps zombie children. Since SIGCHLD signals are blocked while the SIGCHLD handler is executing, and since Linux signals are not queued, the SIGCHLD handler must be prepared to reap multiple zombie children.

## 12.2 Concurrent Programming with I/O Multiplexing
1) allocate
2) assign one variable of this type to another
3)
select function takes two inputs:
  + a descriptor set(fdset) called readset
  + the cardinality(n) of the read set()
the select function blocks until at least one descriptor in the read set is ready for reading. <According to man select, A file descriptor is considered ready if it is possible to perform a corresponding I/O operation(e.g., read(2), or a sufficiently small write(2)) without blocking.>

While this program is a good example of using select, it still leaves something
to be desired. The problem is that once it connects to a client, it continues echoing
input lines until the client closes its end of the connection. Thus, if you type a
command to standard input, you will not get a response until the server is finished
with the client. A better approach would be to multiplex at a finer granularity,
echoing (at most) one text line each time through the server loop.

### 12.2.1 A Concurrent Event-Driven Server Based on I/O Multiplexing
I/O multiplexing can be used as the basis for concurrent event-driven programs,
where flows make progress as a result of certain events. The general idea is to
model logical flows as state machines. Informally, a state machine is a collection of
states, input events, and transitions that map states and input events to states. Each
transition maps an (input state, input event) pair to an output state. A self-loop is
a transition between the same input and output state. State machines are typically
drawn as directed graphs, where nodes represent states, directed arcs represent
transitions, and arc labels represent input events. A state machine begins execution
in some initial state. Each input event triggers a transition from the current state
to the next state.
For each new client k, a concurrent server based on I/O multiplexing creates
a new state machine sk and associates it with connected descriptor dk. As shown
