#include <iostream>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

void h(int s)
{
  int pid= waitpid(0, nullptr, WNOHANG);
  cout << "get here, s=" << s << endl;
  cout << "child that finished:" << pid << endl;
}

int main()
{
  if (fork())
  {
    signal(SIGCHLD, h);

    int n;
    cin >> n;
    cout << "got " << n << endl;
  }
  else
  {
    sleep(5);
    cout << "child done!" << endl;

  }

  return 0;
}

