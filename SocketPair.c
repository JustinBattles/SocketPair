/* Put includes up here. */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define K 1024

void parent(pid_t pid, int sv[2])
{
  close(sv[0]);

  char buf[K];

  int r, w, t;
  
  while ((r = read(STDIN_FILENO, buf, K)) > 0) {
  t = 0;

  do {
  
    w = write(sv[1], buf, r);
    t += w;

  } while (t < r);

   
  read(sv[1], buf, K);

  write(STDOUT_FILENO, buf, r);
  
  }
 	
  close(sv[1]);
}


void child(int sv[2])
{

  close(sv[1]);

  char buf[K];
  int r, w, t;

  while ((r = read(sv[0], buf, K )) > 0) {

for (int i = 0; i < r; i++) {
    if (isupper(buf[i])) 
      buf[i] = ((buf[i] - 'A' + 13) % 26) + 'A';
    else if (islower(buf[i]))
      buf[i] = ((buf[i] - 'a' + 13) % 26) + 'a';
  }

  
  t = 0; 

  do {
  
   w = write(sv[0], buf+t, r-t);
   t += w;
  } while (t < r);
 }
  

  close(sv[0]);

}


int main(void)
{
  int sv[2];
  int fd = socketpair(AF_UNIX, SOCK_STREAM, 0, sv);


pid_t pid = fork();

if (pid < 0) {
  perror("fork");
  return -1;
}

if (pid > 0) parent(pid, sv);
else child(sv);


return 0;


}
