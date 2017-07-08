
#include <iostream>
#include <unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>
///cccccccccccccccc
using namespace std;
void printids(const char * s){
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    cout<<s<<" pid is :"<<pid<<", tid is :"<<tid<<endl;
}

void *thr_fn(void *arg){
    printids("new thread :");
    return (void *)0;
}

int main(){
pthread_t ntid;
int err;
err = pthread_create(&ntid,NULL,thr_fn,NULL);
if(err != 0)
    cout<<"create thread fail , the err is "<<err<<endl;
printids("main thread:");
sleep(1);
exit(0);
}
///xxxxxxxxxxxxxxxxx
