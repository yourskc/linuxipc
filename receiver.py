import posix_ipc

QUEUE_NAME = '/my_queue'
MAX_SIZE = 1024

# Open the message queue
mq = posix_ipc.MessageQueue(QUEUE_NAME, posix_ipc.O_CREAT)

try:
    while True:
        message, _ = mq.receive()
        print(f"Received: {message.decode()}")
except KeyboardInterrupt:
    pass
finally:
    # Cleanup: Close and unlink the message queue
    mq.close()
    mq.unlink()