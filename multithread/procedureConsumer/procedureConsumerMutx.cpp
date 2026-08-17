#include<mutex>
#include<iostream>
#include<condition_variable>
#include<queue>

using namespace std; 

mutex mtx; 
condition_variable cv; 
queue<int> q;
const int MAX_SIZE =5; 
void procedure()
{
    int i=0;
    while(true)
    {
       lock_guard<mutex> lock(mtx);
       cv.wait(lock, []{return q.size() < MAX_SIZE });
       q.push(i);
       cv.notify_all()
       this_thread::sleep_for(chrono::milliseconds(100));
    }
}
void consumer()
{
    while(true)
    {
       lock_guard<mutex> lock(mtx);
       cv.wait(lock, []{return !q.front() });
       int value = q.front();q.pop();
       cout<<"consumer"<<value;
       cv.notify_all()
       this_thread::sleep_for(chrono::milliseconds(100));
    }
}
int main() {
    std::thread t1(producer), t2(consumer);
    t1.join(); t2.join();
}


