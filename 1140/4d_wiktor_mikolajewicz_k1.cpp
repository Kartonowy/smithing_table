
// Utwórz strukturę Monitor zawierającą dane:
// - producent
// - model
// - przekatna
// Zbuduj kilka jej egzemplarzy w postaci Stosu 
// dynamicznego (Stack, LIFO),
// a następnie napisz funkcję, która dodaje 
// kolejny element do stosu
//
// Zbuduj tablicę dynamiczną 3D przechowującą 
// próbki pomiarowe temperatury
// w pomieszczeniu wygenerowane na 
// regularnej siatce.


#include <cstdlib>
#include <iostream>
#include <string>

struct Monitor {
    std::string producent;
    std::string model;
    int przekatna;
};

struct Node {
    struct Monitor* monitor;
    struct Node* next;
};

struct Monitor* createMonitor(std::string producent, std::string model, int przekatna) {
    struct Monitor* newMonitor = new Monitor;
    newMonitor->producent = producent;
    newMonitor->model = model;
    newMonitor->przekatna = przekatna;
    return newMonitor;
}

struct Node* createNode(struct Monitor* monitor) {
    struct Node* newNode = new Node;
    newNode->monitor = monitor;
    newNode->next = nullptr;
    return newNode;
}

void addToStack(struct Node* bottom, struct Node* toBeAdded) {
    struct Node* iter = bottom;
    while(iter->next != nullptr) {
        iter = iter->next;
    }
    iter->next = toBeAdded;
}

void printStack(struct Node* bottom) {
    struct Node* iter = bottom;
    if (iter->next != nullptr) {
        printStack(iter->next);
    }
    std::cout << iter->monitor->przekatna << std::endl;
}

int main() {
    std::cout << "Zadanie 1:" << std::endl;

    Node* bottom = createNode(createMonitor("HP", "Quick", 27));
    addToStack(bottom, createNode(createMonitor("ASUS", "OLED", 24)));
    addToStack(bottom, createNode(createMonitor("LENOVO", "THINKMONITOR", 27)));
    addToStack(bottom, createNode(createMonitor("LEGION", "GAMING X", 32)));
    addToStack(bottom, createNode(createMonitor("HP", "QLED", 18)));
    addToStack(bottom, createNode(createMonitor("ASUS", "QLED", 25)));
    printStack(bottom);

    std::cout << "Zadanie 2:" << std::endl;

    const int X = 10;
    const int Y = 10;
    const int Z = 10;

    float*** table = (float***)malloc(sizeof(float) * X * Y * Z); //float*** table = new float** [X];

    srand(time(0));
    for (int i = 0; i<X; ++i) {

        table[i]= (float**)malloc(sizeof(float) * Y * Z); //table[i] = new float* [Y];
        for (int j = 0; j<Y; ++j) {

            table[i][j]= (float*)malloc(sizeof(float) * Z); //table[i][j] = new float [Z];
            for (int k = 0; k<Z; ++k) {
                table[i][j][k] = (float)std::rand()/(float)RAND_MAX * 25 + 15;
            }
        }
    }

    return 0;
}
