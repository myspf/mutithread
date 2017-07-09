#include <iostream>
#include <unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<stdlib.h>
#include <fstream>
using namespace std;
int global;
class Mutex{
public:
	Mutex()
	{
		pthread_mutex_init(&m_,NULL);
	}
	~Mutex()
	{
		pthread_mutex_destroy(&m_);	
	}
	void lock()
	{
		pthread_mutex_lock(&m_);
	}
	void unlock()
	{
		pthread_mutex_unlock(&m_);
	}

private:
	pthread_mutex_t m_;
};
//////this is a mutex
Mutex m;
class Info{
public:
	Info(){
		for(int i = 0 ;i<10;i++)
			a[i] = 0;
	}
	int a[10];
};
Info info; 
void *f1(void *arg){
		while(1){
	for(int i = 0 ;i < 10 ;i++){
		info.a[i] = i*30;	
	}
	
	}

return (void *)0;
}

void *f2(void *arg){
	while(1){
	for(int i = 0 ;i < 10 ;i++){
		info.a[i] = i*30;	
	}
	
}
return (void *)0;
}

int main(){
	pthread_t t1,t2;
	void *ret;
	pthread_create(&t1,NULL,f1,NULL);
	pthread_create(&t2,NULL,f2,NULL);
	pthread_join(t1,&ret);
	pthread_join(t2,&ret);
	cout<<"global is :"<<global<<endl;
	return 0;
}
////add some comment

///add anewline
