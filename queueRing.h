#pragma once
#include<iostream>
using namespace std;

class cqueue112 {
	int size = 0;
	int* arr = nullptr;
public:
	cqueue112() = default;

	void push(char ch) {
		this->size++;
		int* n_arr = new int[this->size];
		for (size_t i = 1; i < this->size; i++)
		{
			n_arr[i] = this->arr[i - 1];
		}
		n_arr[0] = ch;
		if (this->arr != nullptr)
			delete[] this->arr;
		this->arr = n_arr;
	}

	void pop(bool to_end = true) {
		if (this->arr == nullptr)
			return;
		if (to_end) {
			for (int i = this->size - 1; i > 0; i--) {
				swap(this->arr[i], this->arr[i - 1]);
			}
			return;
		}
		if (this->size == 1) {
			this->~cqueue112();
			return;
		}
		int* n_arr = new int[this->size - 1];
		for (size_t i = 0; i < this->size - 1; i++)
		{
			n_arr[i] = this->arr[i];
		}
		delete[] this->arr;
		this->arr = n_arr;
		this->size--;
	}

	void printQueue() const {
		for (size_t i = 0; i < this->size; i++)
		{
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}

	int back() const {
		return this->arr[0];
	}
	int front() const {
		return this->arr[this->size - 1];
	}
	int& back() {
		return this->arr[0];
	}
	int& front() {
		return this->arr[this->size - 1];
	}

	bool empty() const {
		return this->size == 0;
	}

	int getSize() const {
		return this->size;
	}

	cqueue112(const cqueue112& cq) {
		if (cq.arr == nullptr)
			return;
		this->size = cq.size;
		this->arr = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = cq.arr[i];
		}
	}

	cqueue112& operator=(const cqueue112& cq) {
		if (this == &cq)
			return *this;;
		this->~cqueue112();
		if (cq.arr == nullptr)
			return *this;
		this->size = cq.size;
		this->arr = new int[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->arr[i] = cq.arr[i];
		}
		return *this;
	}

	cqueue112(cqueue112&& cq) {
		swap(this->size, cq.size);
		swap(this->arr, cq.arr);
	}

	cqueue112& operator=(cqueue112&& cq) {
		swap(this->size, cq.size);
		swap(this->arr, cq.arr);
		return *this;
	}

	~cqueue112() {
		if (this->arr != nullptr) {
			delete[] this->arr;
			this->size = 0;
			this->arr = nullptr;
		}
	}
};
