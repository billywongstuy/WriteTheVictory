#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int randy() {
  printf("Here ->");
  int s = open("/dev/random",O_RDONLY);
  int *a;
  read(s,a,4);
  return *a;
}

int main() {
  int a1[10];
  int a2[10];
  int i = 0;
  int fd;
  printf("Generating random numbers:\n");
  for (i; i < 10; i++) {
    int r = randy();
    a1[i] = r;
    printf("\trandom %d: %d\n",i,r);
  }
  
  umask(0000);
  //CREATE THE FILE
  fd = open("file.txt",O_CREAT,0666);
  close(fd);

  //WRITE TO THE FILE
  fd = open("file.txt",O_RDWR);
  printf("Writing numbers to file...\n");
  write(fd,a1,sizeof(a1));
  close(fd);

  //READ THE FILE
  fd = open("file.txt",O_RDWR);
  printf("Reading numbers from file...\n");
  read(fd,a2,sizeof(a2));
  close(fd);

  //CHECK THE ARRAY
  printf("Verification that written values were the same:\n");

  for (i = 0; i < 10; i++) {
    printf("\trandom %d: %d\n",i,a2[i]);
  }

  return 0;
}
