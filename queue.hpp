#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <exception>

template<typename T>
class Queue{

protected:
	T *queue;
	int size;
	int count;

public:
	Queue(int N){
		size = N;
		queue = new T[size];
		count = 0;
	}

	virtual void Push(T data){
		if(IsFull()){
			throw std::overflow_error("Queue is Full");
		}
		queue[count] = data;
		count++;

	}

	virtual void Pop(){
		if(IsEmpty()){
			throw std::underflow_error("Queue is already Empty!!!");
		}
		for(int i = 1; i<count; i++){
			queue[i-1] = queue[i];
		}

		count--;

	}

	virtual int IsFull(){
		return count == size;
	}

	virtual int IsEmpty(){
		return count == 0;
	}

	virtual void Show(){
		std::cout<<"[ ";
		for(int i=0; i<count; i++){
			std::cout<<queue[i]<<",";
		}
		std::cout<<"\b ]"<<std::endl;

	}

	~Queue(){
		delete[] queue;
	}

};

template <typename T>
class CircularQueue : public Queue<T>{

private:
	int first;
	int aux;

public:
	CircularQueue(int N) : Queue<T>(N){
		first = aux = -1;
	}

	virtual void Push(T data){
		if(IsFull()){
			throw std::overflow_error("Queue is Full");
		}
		
		if(IsEmpty()){
			first = 0;
			aux = 0;
			Queue<T>::queue[aux] = data;
		}

		else{
			aux = (aux + 1) % Queue<T>::size;
			Queue<T>::queue[aux] = data;
		}

		Queue<T>::count++;

	}

	virtual void Pop(){
		if(IsEmpty()){
			throw std::underflow_error("Queue is already Empty!!!");
		}

		if(aux == first){
			aux = -1;
			first = -1;
			Queue<T>::count--;
		}
		
		else{
			Queue<T>::queue[first] = 0;
			first = (first+1)%Queue<T>::size;
			Queue<T>::count--;
		}
		
	}

	virtual int IsFull(){
		return (aux + 1)%Queue<T>::size == first;
	}

	virtual int IsEmpty(){
		if((first == -1 ) && (aux == -1)){
			return 1;
		}
		
		else{
			return 0;
		}
	}


	virtual void Show(){

		std::cout<<"[ ";
		
		for(int i=0; i<Queue<T>::size; i++){
			std::cout<<Queue<T>::queue[i]<<' ';
		}


		std::cout<<"\b ]"<<std::endl;
	}

	~CircularQueue(){
		delete[] Queue<T>::queue;
	}	

};

#endif