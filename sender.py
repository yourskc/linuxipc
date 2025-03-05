import posix_ipc
import time

QUEUE_NAME = '/my_queue'
MAX_SIZE = 1024

# Create or open the message queue
mq = posix_ipc.MessageQueue(QUEUE_NAME, posix_ipc.O_CREAT)

try:
    for i in range(5):
        message = f"Message {i + 1} from Python program"
        mq.send(message.encode())
        print(f"Sent: {message}")
        time.sleep(1)
finally:
    # Cleanup: Close and unlink the message queue
    mq.close()
    mq.unlink()
    
