#include <iostream>
#include <string>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstring>
// Consts
const size_t BUFFER_SIZE = 8192;


///	Example prototypes
/// You may or may not want to solve the assignment this way.
///	Feel free to erase the following stubs and implement your own design instead (just make sure you pass your tests).
bool prompt();
void executeCommand(char command[BUFFER_SIZE]);


int main()
{
std::cout << "Hello, my name is Randy Do. Welcome to my forker! \n";
char command[BUFFER_SIZE];
bool exit_ = false;

while(!exit_){
   std::cout << "\n" << "cmd> ";
   std::cin.getline(command, BUFFER_SIZE);
   
   //check for exit
   if(strcmp(command, "exit") == 0) {
      std::cout << "Thank you for using my forker!\n";
      break;
   }

   //echo
   std::cout << "You entered: " << command << std::endl;
   executeCommand(command);
   std::cout << "Thanks for using my forker!\n";
   }
return 0;
}



bool prompt()
{
   return true;
}

void executeCommand(char command[BUFFER_SIZE])
{
int result = 0;
pid_t pid;
pid = fork();

//child process
if(pid == 0) { 
   result = execlp(command, command, (char*)NULL);
   if(result < 0){ 
      std::cout << "Failed to execute command: " << command << " \nNo such file or directory\n";
      exit(0);
   }
}

//back to parent
else if(pid > 0){
   result = wait(NULL);
   if(result < 0){
      std::cout << "Failed to wait\n";
   }
}

//error
else{ 
perror("Failed to fork child");
 }
}
