#define MAXSIZE 100
#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct {
	int *base;
	int *top;
	int stacksize;
}sqstack;
bool InitStack(sqstack *s){
	s->base=(int *)malloc(MAXSIZE * sizeof(int));
	if (!s->base){
		cout<<"ERRO"<<endl;
		return false;
	}
	s->top=s->base;
	s->stacksize=MAXSIZE;
	cout<<"init finish"<<endl;
	return true;
}
bool StackEmpty(sqstack *s){
	return s->top==s->base;
}
int StackLength(sqstack *s){
	return s->top-s->base;
}
void DestroyStack(sqstack *s){
	free (s->base);
	s->base=NULL;
	s->top=NULL;
	s->stacksize=0;
	cout<<"Destroy finish."<<endl;
}
void ClearStack(sqstack *s){
	s->top=s->base;
	cout<<"clear finish"<<endl;
}
bool Push(sqstack *s,int e){
	if(s->top-s->base==s->stacksize){
		cout<<"stack is full"<<endl;
		return false;
	}
	*(s->top)=e;
	s->top++;
	cout<<"Push finish"<<endl;
	return true;
}
bool Pop(sqstack *s,int *e){
	if(StackEmpty(s)){
		cout<<"stack is NULL"<<endl;
		return false;
	}
	s->top--;
	*e=*(s->top);
	cout<<"Out:"<<*e<<endl;
	return true;
}
bool GetTop(sqstack *s,int *e)
{
	if(StackEmpty(s)){
		cout<<"Erro"<<endl;
		return false;
	}
	*e=*(s->top-1);
	return true;
}
int main(){
	sqstack *s=(sqstack *)malloc(sizeof(sqstack));
	int e;
	InitStack(s);
	Push(s,3);
	GetTop(s,&e);
	cout<<e<<endl;
}