#include<iostream>
#include <list>
#include <string>
using namespace std;

struct A {
	list<string> names;
	A() {
		cout << "construct A \n";
	}
	~A() {
		cout << "destroy A \n";
	}
};

int main() {
	//A* a = (A*)malloc(sizeof(A));
	void* a = malloc(sizeof(A) * 100);

	// placement new能够在已分配的堆内存上构造对象
	// 应用于对象池，当需要频繁申请内存构造对象，并频繁销毁的时候（如游戏中），可以使用对象池
	// new (pointer) TypeInitializer;
	// pointer 是一个指向已分配内存的指针，表示要在该内存位置上构造对象。
	// TypeInitializer 是对象类型的构造函数，用于在给定的内存位置上构造对象。
	A* b = new(a) A();
	A* c = new((A*)a + 1) A();
	A* d = new((char*)a + sizeof(A)*2) A();
	if (b != NULL) {
		b->names.push_back("A");
		b->names.push_back("B");
		b->~A();
	}
	free(a);
	return 0;
}
