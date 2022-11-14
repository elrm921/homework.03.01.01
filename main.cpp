#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

once_flag flag;
void client(int &cnt)
{
    call_once(flag, [&cnt]()
        {
            cnt = 1;
            cout << "Clients: " << cnt << endl;
        });
    while (cnt < 5)
    {
        this_thread::sleep_for(1s);
        cnt++;
        cout << "Clients: " << cnt << endl;
    }
}

void operatr(int &cnt)
{
    call_once(flag, [&cnt]()
        {
            cnt = 1;
            cout << "Clients: " << cnt << endl;
        });
    while (cnt > 0)
    {
        this_thread::sleep_for(2s);
        cnt--;
        cout << "Clients: " << cnt << endl;
    }
}

int main()
{
    int num = 0;
    thread T1(client, ref(num));
    thread T2(operatr, ref(num));
    T1.join();
    T2.join();

    return 0;
}