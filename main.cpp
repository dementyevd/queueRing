#include"queueRing.h"

void main() {
	cqueue112 q1;
	q1.push(5);
	q1.push(6);
	q1.push(7);
	q1.printQueue();
	q1.pop();
	q1.printQueue();
	q1.pop(0);
	q1.printQueue();
	cqueue112 q2 = q1;
	q2.printQueue();

}