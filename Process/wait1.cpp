#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char *argv[])
{
  int id = fork();
  if (id==0)  // child
    {
      for (int tnum=1; tnum<=10; tnum++)
	{
	  cout << tnum << ") childish behavior" << endl;
	  sleep(1);
	}
    }    
  else // parent
    {
      waitpid(id, nullptr,0);
      cout << "tantrum over" << endl;
    }

  cout << "All done!!" << endl;
  
  return 0;
}
