#include <iostream>
#include <unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>
using namespace std;

void * fun1(void *arg){
    cout<<"thread 1 return "<<endl;
    return (void *)1;
}
void * fun2(void *arg){
    cout<<"thread 2 return "<<endl;
    return (void *)2;
}

void nothing()
{
    //do nothing;
    return ;
}


int main(){
    int err;
    pthread_t tid1,tid2;
    void *ret;
    pthread_create(&tid1,NULL,fun1,NULL);
    pthread_create(&tid2,NULL,fun2,NULL);
    pthread_join(tid1,&ret);
    cout<<"thred 1 exit:"<<reinterpret_cast<int>(ret)<<endl;
    pthread_join(tid2,&ret);
    cout<<"thred 2 exit:"<<reinterpret_cast<int>(ret)<<endl;
}



















