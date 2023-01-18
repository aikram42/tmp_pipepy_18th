#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int fd;

	fd = open ("chundy.tmp", O_RDONLY | O_CREAT | O_EXCL, 0666);
	// sleep(2);
	close (fd);
	unlink("chundy.tmp");
}