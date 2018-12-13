#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


// int open(const char *path, int oflags);
// int open(const char *path, int oflags, mode_t mode);

// 第一个参数 path ： 路径名或者文件名。路径名为绝对路径名。
// 第二个参数 oflags： 打开文件所采取的动作。
// 下面三个选项是必须选择其中之一的。
// O_RDONLY    文件只读
// O_WRONLY    文件只写
// O_RDWR      文件可读可写
// 下面是可以任意选择的
// O_APPEND    每次写操作都写入文件的末尾
// O_CREAT     如果指定文件不存在，则创建这个文件
// O_EXCL      如果要创建的文件已存在
// O_TRUNC     如果文件存在，并且以只写/读写方式打开，则清空文件全部内容
// O_NOCTTY    如果路径名指向终端设备，不要把这个设备用作控制终端
// O_NONBLOCK  如果路径名指向 FIFO/块文件/字符文件，则把文件的打开和后继 I/O 设置为非阻塞模式（nonblocking mode）
// O_NDELAY    和 O_NONBLOCK 功能类似,调用 O_NDELAY 和实用的 O_NONBLOCK 功能是一样的

void file_open_ext (void);
void file_write_ext (void);
void file_read_ext (void);

char *g_text1 = "./text1.txt";
char *g_text2 = "./text2.txt"

int main (int argc, char *argv[])
{
	int fd = 0;

	printf("file I/O study\n");

	file_open_ext();

	file_write_ext();

	file_read_ext();
}

void file_open_ext (void)
{
	int fd = 0;

	printf("file open practice ...\n");

	fd = open(g_text1, O_RDWR, 0777)
	if (fd < 0) {
		printf("open %s failed\n", g_text1);
	}
	else {
		printf("%s fd is %d\n", g_text1, fd);
	}
	printf("file close %s, res is %d\n", g_text1, close(fd));

	fd = open(g_text2, O_RDWR | O_CREAT, 0777);
	if (fd < 0) {
		printf("open %s failed\n", g_text2);
	}
	else {
		printf("%s fd is %d\n", g_text2, fd);
	}
	printf("file close %s, res is %d\n", g_text2, close(fd));
}

void file_write_ext (void)
{
	int fd = 0;
	char *write_buf = "Hello, this is file I/O practice.\n";
	ssize_t write_len = 0;

	printf("file write practice ...\n");

	fd = open(g_text2, O_RDWR, 0777);
	if (fd < 0) {
		printf("open %s failed\n", g_text2);
	}
	else {
		printf("%s fd is %d\n", g_text2, fd);
	}

	write_len = write(fd, write_buf, strlen(write_buf));
	if (write_len == -1) {
		perror("write");
	}
	else {
		printf("write function is OK\n");
	}
	close(fd);
}

void file_read_ext (void)
{

	
}
