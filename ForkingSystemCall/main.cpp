#include <string>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
// Consts
const size_t BUFFER_SIZE = 8192;


///	Example prototypes
/// You may or may not want to solve the assignment this way.
///	Feel free to erase the following stubs and implement your own design instead (just make sure you pass your tests).
bool prompt();
void executeCommand(std::string command);


int main()
{
	 pid_t process_id;
   //set = to fork
   process_id = fork();
   if(process_id == 0) { execlp("/bin/ls", "ls", NULL);}
   while(process_id > 0){
       wait(NULL);
       printf("Child process finished");
	   exit(0);
   } return 0;

}

bool prompt()
{
	return false;
}

void executeCommand(std::string command)
{
	
}

