#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
	int fd_sensor;
	int fd_lcd;

	fd_sensor = open("/dev/sht20_device", O_RDONLY);
	if (fd_sensor < 0) {
		perror("SHT20 open error\n");
		return -1;
	}

	fd_lcd = open("/dev/hd44780_device", O_WRONLY);
	if (fd_lcd < 0) {
		perror("LCD open error\n");
		return -1;
	}

	int len = 0;
	char buf[32];
	while (1) {
		len = read(fd_sensor, buf, sizeof(buf) - 1);
		if (len > 0) {
			buf[len] = '\0';
			printf("%s\n", buf);
			write(fd_lcd, buf, len);
		}

		sleep(1);
	}

	close(fd_sensor);
	close(fd_lcd);

	return 0;
}
