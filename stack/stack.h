#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

typedef struct StackType {
    int arr[SIZE];
    int top;
} StackType;

void init(StackType *s){
    s->top = -1;
}

bool isEmpty(StackType *s){
    return (s->top == -1);
}

bool isFull(StackType *s){
    return (s->top == SIZE -1);
}

void push(StackType *s, int a){
    if (!isFull(s)){
        s->arr[++(s->top)] = a;
        cout << "stack has pushed " << a << endl;
    }
    else {
        cout << "Stack is full.\n";
    }
}

int pop(StackType *s){
    if(!isEmpty(s)){
        return s->arr[s->top--];
    }
    else {
        cout << "Stack is empty.\n";
        return -1;
    }
}

int peek(StackType *s){
    if(!isEmpty(s)){
        return s->arr[s->top];
    }
    else {
        cout << "Stack is empty.\n";
        return -1;
    }
}

/*int main(){
    StackType s;
    init(&s);
    string command;
    int value;

    while (true){
        cout << "Enter command \"push <value>, pop, peek, exit\": ";
        cin >> command;

        if (command == "push"){
            if (cin >> value){
                push(&s, value);
            } else {
                cout << "Invalid value for push command.\n";
                cin.clear(); // Clear error flags
                cin.ignore(100, '\n'); // Discard invalid input
            }
        }
        else if (command == "pop"){
            int popped = pop(&s);
            if (popped != -1){
                cout << "popped: " << popped << endl;
            }
        }
        else if (command == "peek"){
            int topElement = peek(&s);
            if (topElement != -1){
                cout << "peek: " << topElement << endl;
            }
        }
        else if (command == "exit"){
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid command.\n";
        }
    }
    return 0;
}*/