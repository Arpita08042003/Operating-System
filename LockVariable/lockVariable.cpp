//  mutex (Mutual Exclusive Lock)

#include<iostream>
#include<thread>
#include<atomic> 

using namespace std;


class thread_object{
    int lock =0;
    public:
        void operator()(int& x,int id){
            for(int i=0;i<10000;i++){
                while(lock!=0);
                lock =1;
                x++;
                cout<<x<<" "<<id<<"  ";
                lock =0;
            }
        } 
};



// atomic<int> lock(0); 
// class thread_object{
//     private:
//         bool acquire_lock(){
//             int ex=0;
//             return lock.compare_exchange_strong(ex,1,memory_order_acquire);
//         }
//         void release_lock(){
//             lock.store(0,memory_order_release);
//         }
//     public:
//         void operator()(int &x,int id){
//             for(int i=0;i<10000;i++){
//                 while(!acquire_lock());
//                 cout<<id<<" "<<x<<endl;
//                 x++;
//                 release_lock();
//             }
//         }
// };


 

int main(){
    thread_object obj;
    int x=0;
    thread t1(obj,ref(x),1);
    thread t2(obj,ref(x),2);
    t1.join();
    t2.join();
    cout<<endl<<x<<endl;
}
