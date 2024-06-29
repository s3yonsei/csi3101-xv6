#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"

void thread_main(void* arg)
{
	int* argint = arg;
	printf(1, "hello from child thread argument:%d\n", *argint);
	sleep(300);
	printf(1, "hello from child thread byebye\n");
	return;
}

int main(int argc, char** argv)
{
	int id = 10;
	int tid;
	printf(1, "hello from main thread\n");

	tid = thread_create(thread_main, &id);

	thread_join(tid);

	printf(1, "hello from main thread, child has joined\n");

	exit();
}

