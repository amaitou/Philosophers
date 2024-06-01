---
![shutterstock_753294010](https://user-images.githubusercontent.com/49293816/227395777-3407312a-63ea-4cde-a12d-a45d8711f287.jpeg)

---
# Table of contents

- [Philosophers](https://github.com/amaitou/Philosophers#philosophers)
- [The Dining Philosophers Problem](https://github.com/amaitou/Philosophers#the-dining-philosophers-problem)
- [Threads](https://github.com/amaitou/Philosophers#threads)
	- [Difference between threads and processes](https://github.com/amaitou/Philosophers#difference-between-threads-and-processes)
	- [Thread Problems](https://github.com/amaitou/Philosophers#thread-problems)
	- [Race Condition](https://github.com/amaitou/Philosophers#race-condition)
		- [Locks or Mutexes](https://github.com/amaitou/Philosophers#locks-or-mutexes) 
		- [Semaphors](https://github.com/amaitou/Philosophers#semaphors)
---
# **Philosophers**

This project mainly aims to help you understand the basics of threads by solving a classical problem known as `The Dining Philosophers Problem` (we will see it later).

This project consists of two parts:
- **Mandatory part**
- **Bonus Part**

> Note: The **Bonus Part** is not that necessary to validate the project, but it gives some extra XPs and days for the **` The Blackhole`**.

---

# Project Structure

```
|____.gitignore
|____includes
| |____philo.h
|____Makefile
|____README.md
|____sources
| |____philo.c
| |____philo_detach.c
| |____philo_init.c
| |____philo_routine.c
| |____philo_utils.c
```
---

# **The Dining Philosophers Problem**

The dining philosophers problem is a classic synchronization problem in computer science that was introduced by Edsger Dijkstra in 1965. The problem involves a group of philosophers who are sitting at a round table, each with a bowl of rice and a single chopstick between them. The philosophers spend their time thinking, eating and sleeping, and they need chopsticks to eat their rice.

The problem arises when all the philosophers reach for their left chopstick at the same time, leaving no chopstick for the philosopher on their right. This situation is called a deadlock, and it can cause the philosophers to starve.

The dining philosophers problem is a classic example of a concurrency problem, where multiple processes are trying to access shared resources in a way that can cause conflicts and synchronization issues.

To solve this problem you must be familiar with a concept in computer science that comes under the name of `Threads` (our next topic).

---

# **Threads**

In computer programming, a thread is a lightweight process that can run concurrently with other threads within the same process. Threads are often used to execute multiple tasks simultaneously, allowing an application to be more responsive and efficient.

A thread shares the same memory space and system resources as other threads within the same process, but each thread has its own program counter, stack, and set of registers. This allows multiple threads to execute code independently of each other, even if they are running the same program.

Threads can be created and managed by the operating system or by the application itself. Threads can also communicate with each other and share data through shared memory or message-passing mechanisms.

### **Difference between threads and processes**

Threads and processes are both units of execution in computer programs, but they differ in several key ways:



- `Relationship to resources`: A process has its own memory space, while threads share the same memory space. Each process has its own set of resources (such as file handles and network sockets), while threads share the same resources as the process.

	---

- `Overhead`: Creating a new process is more resource-intensive than creating a new thread, as a new process requires its own memory space and resources. Context switching between processes is also more expensive than context switching between threads, as the operating system must switch between different memory spaces and resources.

- `Communication and synchronization`: Interprocess communication (IPC) is more complex than interthread communication, as processes must use IPC mechanisms (such as pipes or sockets) to exchange data. Threads, on the other hand, can communicate and share data directly through shared memory or other mechanisms.

	---

- `Concurrency`: Threads can execute concurrently within the same process, while processes execute independently of each other.

	---

- `Security`: Processes are isolated from each other and have their own security context, while threads share the same security context as the process.

	---

In summary, processes are more isolated and independent units of execution, while threads are lighter-weight units of execution that share resources and memory within a process. Processes are typically used for more complex and independent tasks, while threads are used for concurrent and parallel tasks within the same program.

---

### **Thread Problems**

Using threads in a program can introduce several potential problems, including:

- `Race conditions`: Race conditions occur when two or more threads access and modify a shared resource simultaneously, leading to unpredictable behavior and errors. This can occur if the threads are not properly synchronized, such as when one thread is reading while another is writing to the same resource.

	---

- `Deadlocks`: Deadlocks occur when two or more threads are waiting for each other to release a resource, leading to a situation where neither thread can proceed. This can occur if the threads acquire resources in a different order, or if they do not release resources properly.

	---

- `Priority inversion`: Priority inversion occurs when a lower-priority thread holds a resource that a higher-priority thread needs, preventing the higher-priority thread from executing. This can occur if the scheduler does not properly handle thread priorities.

	---

- `Starvation`: Starvation occurs when a thread is unable to acquire a required resource due to other threads continually using it, leading to the thread being unable to make progress.

	---

- `Oversubscription`: Oversubscription occurs when too many threads are created or scheduled, leading to contention for resources and slowing down the program.

	---

To avoid these problems, proper synchronization mechanisms and thread-safe programming techniques must be used to ensure that threads can execute safely and efficiently. This includes the use of locks, semaphores, and other synchronization primitives to control access to shared resources, as well as careful design and testing of the program to avoid common concurrency issues.

### **Race Condition**

Since `The Dining Philosophers Problem` Occurs when there is a **Race Condition** that ladt will be our main problem to solve using some techniques such as:
- > Locks
- > Semaphors

	---

---
#### **Locks or Mutexes**

Mutexes are a type of synchronization mechanism used to prevent race conditions in multithreaded programs. A mutex, short for mutual exclusion, is a type of lock that allows only one thread to access a shared resource at a time.

When a thread wants to access a shared resource, it first acquires the mutex lock associated with that resource. If the mutex lock is currently held by another thread, the requesting thread is blocked until the mutex is released by the holding thread. Once the mutex lock is acquired, the thread can safely access the shared resource without interference from other threads. When the thread is finished accessing the shared resource, it releases the mutex lock so that other threads can access the resource.

Mutexes can be implemented using operating system primitives or programming language constructs. In most programming languages, mutexes are implemented as a data structure that contains a flag indicating whether the mutex is currently locked or unlocked, and functions for acquiring and releasing the mutex.

Mutexes are a powerful tool for preventing race conditions in multithreaded programs, but they can also introduce new problems such as deadlocks if not used properly. Deadlocks can occur if two or more threads are waiting for mutex locks held by other threads, leading to a situation where none of the threads can proceed. To avoid deadlocks, proper locking protocols and design patterns must be followed, such as always acquiring locks in a consistent order and avoiding nested locks.

---

#### **Semaphors**

Semaphores are a type of synchronization mechanism used to control access to shared resources in multithreaded programs. A semaphore is a non-negative integer counter that can be incremented or decremented by threads as they access a shared resource.

A semaphore can be used to limit the number of threads that can access a resource at the same time, or to signal an event between threads. When a thread wants to access a resource protected by a semaphore, it first checks the value of the semaphore. If the value is greater than zero, the thread decrements the semaphore counter and proceeds to access the resource. If the value is zero, the thread is blocked until the semaphore value becomes greater than zero.

When a thread finishes accessing the resource, it increments the semaphore counter, signaling to other threads that the resource is available again. This allows other waiting threads to proceed and access the resource.

Semaphore has two types which are:
- > Counted Semaphors:
	
	Counting semaphores is a type of semaphore used to control access to a shared resource in multithreaded programs. <br />
	
	A counting semaphore is initialized with a positive integer value, which represents the maximum number of threads that can access the shared resource simultaneously. When a thread wants to access the shared resource, it decrements the semaphore value by one. If the semaphore value is already zero, the thread is blocked until another thread releases the shared resource by incrementing the semaphore value.

	When a thread releases the shared resource, it increments the semaphore value by one, which allows another waiting thread to access the shared resource.

- > Binary Semaphors:

	A binary semaphore is a synchronization mechanism that has two possible values: 0 and 1. It is commonly used to control access to a shared resource where only one thread can access the resource at a time.

	A binary semaphore can be thought of as a lock with two states: `locked (0)` and `unlocked (1)`. When a thread wants to access the shared resource, it first acquires the semaphore by setting its value to 0 _(locking the semaphore)_, and then releases it by setting its value to 1 (unlocking the semaphore) when it is done. If the semaphore value is already 0, the thread is blocked until another thread releases the semaphore by setting its value to 1.

	Binary semaphores are often used in conjunction with mutual exclusion mechanisms such as mutexes and critical sections to ensure that only one thread can access a shared resource at a time. In this case, the binary semaphore is used to signal whether the shared resource is currently being used or not.

	One important thing to note is that binary semaphores do not guarantee fairness in resource allocation. If multiple threads are waiting to acquire a binary semaphore, there is no guarantee that they will acquire the semaphore in the order in which they requested it. This can lead to situations where some threads may starve for access to the shared resource if other threads are constantly acquiring and releasing the semaphore.

	---

	To implement semaphores under this definition, we define a semaphore as follows:

	```c
		typedef struct
		{ 
			int value;
			struct process *list; 
		} semaphore;
	```

	Each semaphore has an integer value and a list of processes list. When a process must wait on a `semaphore`, it is added to the list of processes. A `signal()` operation removes one process from the list of waiting processes and awakens that process.

	---

	Now, the `wait()` semaphore operation can be defined as:

	```c
		wait(semaphore *S) 
		{ 
			S->value--;
			if (S->value < 0)
			{
				// add this process to S->list;
			} 	
		}
	```

	---
	and the `signal()` semaphore operation can be defined as:

	```c
		signal(semaphore *S) 
		{ 
			S->value++;
			if (S->value <= 0) 
			{
				// remove a process P from S->list; wakeup(P);
			}
		}
	```

	The list of waiting processes can be easily implemented by a link field in each process control block (PCB). Each semaphore contains an integer value and a pointer to a list of PCBs. One way to add and remove processes from the list so as to ensure bounded waiting is to use a FIFO queue, where the semaphore contains both head and tail pointers to the queue. In general, however, the list can use any queueing strategy. Correct usage of semaphores does not depend on a particular queueing strategy for the semaphore lists.

	Note -> If you want to get close and close to knowing more about `PCBs` I suggest reading this article  [Scaler - Process Cotnrol Table](https://www.scaler.com/topics/operating-system/process-control-block-in-os/)

---

### **Contact Me**

* [Twitter][_1]

[_1]: https://twitter.com/amait0u

