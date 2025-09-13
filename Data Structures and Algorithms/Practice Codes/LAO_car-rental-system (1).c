#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100         
#define CAR_ID_LENGTH 10   


struct Node {
    char action[5];           
    char customerName[100];   
    char carId[CAR_ID_LENGTH]; 
    struct Node* next;        
};


typedef struct {
    char carIds[MAX_CARS][CAR_ID_LENGTH]; 
    int top;                             
} CarStack;


struct Queue {
    struct Node *front;       
    struct Node *rear;       
};


typedef struct Queue* QueuePtr;


void initializeCarStack(CarStack* s) {
    s->top = -1;              
}


int pushCar(CarStack* s, char *carId) {
    if (s->top == MAX_CARS - 1) { 
        printf("Stack is full. Cannot push %s onto the stack.\n", carId);
        return 0;              
    }
    strcpy(s->carIds[++(s->top)], carId); 
    return 1;                  
}


char* popCar(CarStack* s) {
    if (s->top == -1) {       
        printf("Stack is empty. No cars available.\n");
        return NULL;           
    }
    return s->carIds[(s->top)--]; // Return the car ID at the top and decrement the top
}

// Function to check if the stack is empty
int isCarStackEmpty(CarStack* s) {
    return s->top == -1;       // Return true if the stack is empty
}

// Function to check if the stack is full
int isCarStackFull(CarStack* s) {
    return s->top == MAX_CARS - 1; // Return true if the stack is full
}

// Function to create a queue
QueuePtr createQueue() {
    QueuePtr q = (QueuePtr)malloc(sizeof(struct Queue)); // Allocate memory for the queue
    q->front = q->rear = NULL; // Initialize front and rear pointers to NULL
    return q;                  // Return the created queue
}

// Function to enqueue an action to the queue
void enqueue(QueuePtr q, char *action, char *customerName, char *carId) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node
    strcpy(temp->action, action);   // Copy the action to the node
    strcpy(temp->customerName, customerName); // Copy the customer's name to the node
    strcpy(temp->carId, carId);     // Copy the car ID to the node
    temp->next = NULL;              // Set the next pointer to NULL

    if (q->rear == NULL) {          // If the queue is empty
        q->front = q->rear = temp;  // Both front and rear point to the new node
        return;
    }
    q->rear->next = temp;           // Link the new node at the end of the queue
    q->rear = temp;                 // Update the rear pointer to the new node
}

// Function to dequeue an action from the queue
struct Node* dequeue(QueuePtr q) {
    if (q->front == NULL)           // Check if the queue is empty
        return NULL;                // Return NULL if the queue is empty
    
    struct Node* temp = q->front;   // Store the front node temporarily
    q->front = q->front->next;      // Move the front pointer to the next node

    if (q->front == NULL)           // If the queue becomes empty after dequeue
        q->rear = NULL;             // Set rear to NULL

    return temp;                    // Return the dequeued node
}

// Function to check if the queue is empty
int isQueueEmpty(QueuePtr q) {
    return q->front == NULL;        // Return true if the queue is empty
}

// Function to process customer actions
void processCustomerActions(QueuePtr q, CarStack* carStack) {
    while (!isQueueEmpty(q)) {          // Process actions until the queue is empty
        struct Node* customerAction = dequeue(q); // Dequeue the next action
        
        if (strcmp(customerAction->action, "pop") == 0) { // If the action is to rent a car
            char* carId = popCar(carStack); // Pop a car from the stack
            if (carId != NULL) {         // If a car is available
                printf("%s rented car %s\n", customerAction->customerName, carId);
                strcpy(customerAction->carId, carId); // Assign the car ID to the customer
            }
        } else if (strcmp(customerAction->action, "push") == 0) { // If the action is to return a car
            if (pushCar(carStack, customerAction->carId)) { // Push the car back onto the stack
                printf("%s returned car %s\n", customerAction->customerName, customerAction->carId);
            }
        }
        free(customerAction);         // Free the memory allocated for the processed action
    }
}

// Main function
int main() {
    QueuePtr customerQueue = createQueue(); // Create a queue to manage customer actions
    CarStack carStack;                   // Declare a stack for car IDs
    initializeCarStack(&carStack);       // Initialize the car stack

    // Adding cars to the stack
    pushCar(&carStack, "Ca123");
    pushCar(&carStack, "Ca456");
    pushCar(&carStack, "Ca789");
    pushCar(&carStack, "Ca439");
    pushCar(&carStack, "Ca956");
    pushCar(&carStack, "Ca829");

    // Enqueue customer actions
    enqueue(customerQueue, "pop", "Alice", "");  
    enqueue(customerQueue, "pop", "Charlie", ""); 
    enqueue(customerQueue, "push", "Bob", "Ca999"); 
    enqueue(customerQueue, "push", "Andy", "Ca439"); 
    enqueue(customerQueue, "pop", "Robert", ""); 
    
    // Process customer actions
    processCustomerActions(customerQueue, &carStack);

    return 0;
}

