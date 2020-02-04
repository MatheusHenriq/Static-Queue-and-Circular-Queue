#include <iostream>
#include "queue.hpp"

using namespace std;

int main(){

	CircularQueue<int> a(10);

	a.Push(1);
	a.Push(2);
	a.Push(3);
	a.Push(4);
	a.Push(5);
	a.Push(6);
	a.Pop();
	a.Pop();
	a.Push(7);
	a.Push(8);
	a.Push(9);
	a.Push(10);
	a.Push(11);
	a.Show();

	return 0;
}