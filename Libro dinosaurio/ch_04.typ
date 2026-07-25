= Chapter 3
== Information

Thread: Basic unit of CPU utilization; it comprises a thread ID, a program counter, a register set and a stack

Data parallelism focuses on distributing subsets of the same data across multiple computing cores and performing the same operation on each core.

Task parallelism involves distributing not data but tasks (threads) across multiple computing cores.

Relationship between user threads and kernel threads:
- many-to-one
- one-to-one
- many-to-many
- two level model

General strategies for creating multiple threads:
- Asynchronous threading
- Synchronous threading

Pthreads

OpenMP: Set of compiler directives as well as an API for programs.

Intel Threading Building Blocks(TBB): Template library that supports design applications in C++.

Signal handling

Thread-local storage (TLS)

In between the user and the kernel threads there is a intermediate data structure known as lightweight process/virtual processor (LWP)