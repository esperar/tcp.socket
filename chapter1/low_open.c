#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
void error_handling(char *message);

int main(void) 
{
    // fd : 데이터 수신대상을 나타내는 파일 디스크립터
    // buf : 수신한 데이터를 저장할 버퍼의 주소 값
    // nbytes : 수신할 최대 바이트 수
    
    int fd;
    char buf[] = "Let's go!\n";

    fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);
    if(fd == -1)
        error_handling("open() error!");
    printf("file descriptor: %d\n", fd);

    if (write(fd, buf, sizeof(buf)) == -1)
        error_handling("write() error!");
    close(fd);
    return 0;    
}

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}