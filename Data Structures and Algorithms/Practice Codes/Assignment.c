#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CARS 5
#define CAR_ID_LENGTH 6

struct Node {
char action[5]; // Action to perform: "push" (return car)
//or "pop" (rent car)
char customerName[100]; // Customer's name
char carId[CAR_ID_LENGTH]; // Car ID that the customer rented,
//empty if not rented
struct Node* next; // Pointer to the next node in the queue
};

typedef struct {
char carIds[MAX_CARS][CAR_ID_LENGTH]; // Array to hold car IDs
//contiguously
int top; // Index of the top element in the stack
} CarStack;

typedef struct Queue{
struct Node *front; // Pointer to the front of the queue
struct Node *rear; // Pointer to the rear of the queue
} *Queue;

Queue createQueue();
void initializeCarStack(CarStack* s);
int pushCar(CarStack* s, char *carId);
int isCarStackEmpty(CarStack* s);
int isCarStackFull(CarStack* s);
void enqueue(Queue q, char *action, char *customerName, char
*carId);
int isQueueEmpty(Queue q);
char* popCar(CarStack* s);
struct Node* dequeue(Queue q);


int main(){
	
	Queue customerQueue = createQueue();
	CarStack carStack;
	initializeCarStack(&carStack);
	
	pushCar(&carStack, "Ca123");
	pushCar(&carStack, "Ca456");
	pushCar(&carStack, "Ca789");
	pushCar(&carStack, "Ca439");
	pushCar(&carStack, "Ca956");
	pushCar(&carStack, "Ca829");
	
	enqueue(customerQueue, "pop", "Alice", "");
	enqueue(customerQueue, "pop", "Charlie", "");
	enqueue(customerQueue, "push", "Bob", "Ca999");
	enqueue(customerQueue, "push", "Andy", "Ca439");
	enqueue(customerQueue, "pop", "Robert", "");
	
	int i;
	struct Node* trav;
	
	for(i = 0; i <= carStack.top;i++){
		printf("%5s\n", carStack.carIds[i]);
	}
	
	for(trav = customerQueue->front;trav != NULL;trav = trav->next){
		printf("%3s, %-s, %5s\n", trav->action, trav->customerName, trav->carId);
	}

	return 0;
}

Queue createQueue(){
	Queue tempQ = malloc(sizeof(struct Queue));
	
	if(tempQ != NULL){
	tempQ->front = NULL;
	tempQ->rear = NULL;
	return tempQ;	
	}
}

void initializeCarStack(CarStack* s){
	s->top = -1;
}

int pushCar(CarStack* s, char *carId){
	if(!isCarStackFull(s)){
		s->top++;
		strcpy(s->carIds[s->top],carId);
		return 1;	
	}else{
		return 0;
	}
}

char* popCar(CarStack* s){
	if(!isCarStackEmpty(s)){
		char *temp = malloc(sizeof(char) * CAR_ID_LENGTH);
		strcpy(temp,s->carIds[s->top]); 
		s->top--;
		return temp;
	}else{
		return NULL;
	}
}

int isCarStackFull(CarStack* s){
	return (s->top == MAX_CARS - 1) ? 1 : 0;
}

int isCarStackEmpty(CarStack* s){
	return (s->top == -1) ? 1 : 0;
}

void enqueue(Queue q, char *action, char *customerName, char
*carId){
	
	struct Node* temp = malloc(sizeof(struct Node));
 	if(temp != NULL){
 	strcpy(temp->action,action);
 	strcpy(temp->customerName, customerName);
 	strcpy(temp->carId, carId);
 	if(isQueueEmpty(q)){
 		q->front = temp;
	 }else{
	 	q->rear->next = temp;
	 }
	 q->rear = temp;
 		}
}

struct Node* dequeue(Queue q){
	if(!isQueueEmpty(q)){
		Queue temp;
		temp->front = q->front;
		q->front = q->front->next;
		free(temp);
		}
		
		if(q->front == NULL){
			q->rear = NULL;
		}

}
	
int isQueueEmpty(Queue q){
	return (q->front == NULL) ? 1 : 0;
}


