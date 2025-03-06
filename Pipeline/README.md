# Processes Communication 

### What is **Process** ?
> - Compiled code, that is ready to execute
> - runs in an isolated environment

### How they communicated if needed ?
> There are many ways to do so but the most common one is *pipe*.
> In this *output* of p1(one process) act as *input* of p2(other process)

## What is Pipes?
Pipes are one of the oldest and most widely used method for inter-process communication(IPC) in Unix-based system. A pipe create a communication channel between two process, allowing data to flow from one process to another in a *unidirectional manner*.

here **pipe()** is system call (function) in which we provide *file description* : one for read and other for write obv.
[0] -> read, [1]->write

there is pipeline.cpp file where you can find code for pipeline and you can try **_cat test.txt|grep hello_** (in shell, you know then you know ;))

*Some imp links*

- (https://tabreztalks.medium.com/inter-process-communication-using-pipes-and-signals-in-c-on-unix-based-machine-6f3c862ecfa5)
- (https://medium.com/@serversidedigest/creating-a-unix-style-process-pipeline-in-c-1196163f4a16)
- 