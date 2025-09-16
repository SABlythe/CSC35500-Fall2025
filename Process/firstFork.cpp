#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  cout << "pid=" << getpid() << endl;

  int pid=fork();
  if (pid!=0)
    cout << "in parent, pid=" << getpid() << endl;
  else
    cout << "in child, pid=" << getpid() << endl;

  return 0;
}
