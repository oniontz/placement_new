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

	// placement new�ܹ����ѷ���Ķ��ڴ��Ϲ������
	// Ӧ���ڶ���أ�����ҪƵ�������ڴ湹����󣬲�Ƶ�����ٵ�ʱ������Ϸ�У�������ʹ�ö����
	// new (pointer) TypeInitializer;
	// pointer ��һ��ָ���ѷ����ڴ��ָ�룬��ʾҪ�ڸ��ڴ�λ���Ϲ������
	// TypeInitializer �Ƕ������͵Ĺ��캯���������ڸ������ڴ�λ���Ϲ������
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
