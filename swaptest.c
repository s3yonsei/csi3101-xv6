#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

char buffer1[4096];
char buffer2[4096];

int main(int argc, char** argv)
{
	int blkno = 10;
	int i;

	if ( argc < 2 ) {
		printf(1, "Usage: %s blkno\n", argv[0]);
		exit();
	}

	blkno = atoi(argv[1]);

	memset(buffer1, '1', 4096);

	swapwrite(buffer1, blkno);

	swapread(buffer2, blkno);

	for ( i=0; i <4096; ++i ) {
		if ( buffer1[i] != buffer2[i] )
			printf(1, "different at %d\n", i);
	}

	exit();
}

