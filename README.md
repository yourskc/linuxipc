# Linux IPC - Between C and Python

 Let's use POSIX message queues for proper IPC between a C program and a Python program on Linux.

## 1. C to Python 

**C Program (Sender)**

This C program sends messages to a POSIX message queue.

sender.c

Compile the C program:

```
gcc sender.c -o sender -lrt
```

**Python Program (Receiver)**

This C program receives messages from a POSIX message queue.

receiver.py

**Install the required library for Python:**
```
pip install posix-ipc
```
**Run the Programs**
```
python3 receiver.py
```

In another terminal, run the C sender:
```
./sender
```
**Expected Output**
```
Received: Message 1 from C program
Received: Message 2 from C program
Received: Message 3 from C program
Received: Message 4 from C program
Received: Message 5 from C program
```

## 2. Python to C

**Python Program (Sender)**

sender.py

**Install the required library for Python:**
```
pip install posix-ipc
```

**C Program (Receiver)**

receiver.c

**Compile the C program:**
```
gcc receiver.c -o receiver -lrt
```

**Run the Programs**

./receiver

In another terminal, run the Python sender:

```
python3 sender.py

```

**Expected Output**
```
Received: Message 1 from Python program
Received: Message 2 from Python program
Received: Message 3 from Python program
Received: Message 4 from Python program
Received: Message 5 from Python program
```
















