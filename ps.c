#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char** argv)
{
	unsigned int i;
	int sum=0;
	for (i=0; i< 1000000000; ++i)
		sum += i;
	printf(1, "%d\n", sum);

	//uncomment the following line when your ps system call is ready
	//ps(); 
	exit();
}


