#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "driver.h"

int main(int argc, char *argv[])
{
	int fd = -1;
	char buf[128] = {};

	fd = open(DRIVER_PATH, O_RDWR);
	if (-1 == fd)
	{
		perror("Dirver open");
		return -1;
	}
	
	
//	read(fd, buf, sizeof(buf));



//	write(fd, buf, sizeof(buf));


	close(fd);

	return 0;
}

