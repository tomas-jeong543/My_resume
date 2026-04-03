#define CAPACITY 20
#include<iostream>

using namespace std;

int current_capa = CAPACITY;

typedef struct {
	char* key;
	int value;
	unsigned long hash;
}Entry;

Entry* bucket[CAPACITY];

void init() {
	for (int i = 0; i < CAPACITY; i++) {
		bucket[i] = nullptr;
	}
}

void removeAll() {
	for (int i = 0; i < current_capa; i++) {
		delete bucket[i]->key;
		delete bucket[i];
		bucket[i] = nullptr;
	}
}
unsigned long hashfunc(const char* str) {
	unsigned long hash = 5381;
	int c;
	while ((c = *str++)) {
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}

void insert(const char* key, int value) {
	unsigned long h = hashfunc(key);
	unsigned long idx = h % current_capa;
	if (bucket[idx] != nullptr) {
		cout << "충돌 발생으로 인한 종료" << endl;
		return;
	}
	else {
		Entry* tmp = new Entry;
		tmp->hash = h;
		tmp->key =const_cast<char*>(key);
		tmp->value = value;

		bucket[idx] = tmp;
	}
}
int get(const char* key) {
	unsigned long index = hashfunc(key) % current_capa;
	if (bucket[index] && strcmp(bucket[index]->key, key) == 0) {
		return bucket[index]->value;
	}
	return -1;
}
void remove_entry(const char* key) {
	unsigned long index = hashfunc(key) % current_capa;
	if (bucket[index] && strcmp(bucket[index]->key, key) == 0) {
		delete bucket[index]->key;
		delete bucket[index];
		bucket[index] = nullptr;
	}
}

void printHashmap() {
	for (int i = 0; i < current_capa; i++) {
		if (bucket[i]) {
			cout << bucket[i]->key << ":" << bucket[i]->value << ":" << bucket[i]->hash << endl;
		}
	}
}

int main() {
	init();
	insert("sadsda", 213);
	insert("sadsda", 212);
	printHashmap();
	removeAll();
	return 0;
}