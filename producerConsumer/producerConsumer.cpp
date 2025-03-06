#include<iostream>
#include<thread>
#include<mutex>
#include <queue>
#include<atomic>
#include<condition_variable>

using namespace std;
mutex mut;
condition_variable fulled;

queue<int> buffer_pipe;
size_t buffer_size=10;

atomic<int> global_count{1};

// void producer(int i){
//     try{
//         unique_lock<mutex> lock(mut);
//         fulled.wait(lock,[]{return buffer_pipe.size()<buffer_size;});
//         buffer_pipe.push(i);
//         cout<<global_count++<<endl;
//         cout<<"Produced "<<i<<endl;
//         fulled.notify_one();
//         lock.unlock(); 
//     }catch(const exception &e){
//         cerr<<"Exeception"<<e.what()<<endl;
//     }
// }

// void consumer(){
//     try{
//         unique_lock<mutex> lock(mut);
//         fulled.wait(lock,[]{return buffer_pipe.size()>0;});
//         int consumed = buffer_pipe.front();
//         buffer_pipe.pop();
//         cout<<global_count++<<endl;
//         cout<<"consumer "<<consumed<<endl;
//         fulled.notify_one();
//         lock.unlock();
//     }catch(const exception&e){
//         cerr<<"Exeception: "<< e.what()<<endl;
//     }
// }

void producer(int start,int count){
    try{
        for(size_t i=start;i<start+count;i++){
            unique_lock<mutex> lock(mut);
            fulled.wait(lock,[]{return buffer_pipe.size()<buffer_size;});
            buffer_pipe.push(i);
            // cout<<global_count<<endl;
            global_count++;
            // cout<<"Producer "<<i<<endl;
            // lock.unlock();
            fulled.notify_one();
        }
    }catch(const exception& e){
        cerr<<"exception "<<e.what()<<endl;
    }
}

void consumer(int start,int count){
    try{
        for(size_t i=start;i<count+start;i++){
            unique_lock<mutex> lock(mut);
            fulled.wait(lock,[]{return buffer_pipe.size()>0;});
            int consumed = buffer_pipe.front();
            buffer_pipe.pop();
            // cout<<global_count++<<endl;
            global_count++;
            // cout<<"consumered "<<consumed<<endl;
            // lock.unlock();    
            fulled.notify_one();
        }
    }catch (const exception& e){
        cerr<<"expection "<<e.what()<<endl;
    }
}



int main(){
    const size_t no_thread =10;
    const size_t total =1000000;

    vector<thread> producerThread,consumerThread;
    int mini_packet = (total+(no_thread-1))/no_thread;

    for(size_t i=0;i<no_thread-1;i++){
        int start = i*mini_packet;
        producerThread.emplace_back(producer,start,mini_packet);
        consumerThread.emplace_back(consumer,start,mini_packet);
    }

    producerThread.emplace_back(producer,(no_thread-1)*mini_packet,total-(no_thread-1)*mini_packet);
    consumerThread.emplace_back(consumer,(no_thread-1)*mini_packet,total-(no_thread-1)*mini_packet);

    for(auto &i:producerThread) i.join();
    for(auto &i:consumerThread) i.join();

    cout<<"completed"<<global_count<<endl;

}