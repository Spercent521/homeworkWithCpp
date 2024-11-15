// #include <iostream>
// #include <random>
// using namespace std;

// typedef struct node
// {
//     int n=0;
//     struct node* next;
// }node;


// int main()
// {   
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> distrib(1, 100);

//     node Head;
//     struct node* head=&Head;
//     for(int i=1;i<=10;++i){
//         node node;
//         node.n=distrib(gen);
//         if(i==10){
//             struct node* an=&node;
//         }
//     }
    
//     int f=head.n;

//     for(int i=1;i<=10;++i){
//         cout<<head.next.n<<endl;
//     }

//     return 0;
// }

#include <iostream>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于time()

struct node {
    int n;
    struct node *next;
};

// 函数声明
node* createList(int size);
void printList(node *head);
void deleteList(node *head);

int main() {
    // 初始化随机数生成器
    srand(time(0));

    // 创建一个包含10个随机整数的单链表
    node *head = createList(10);

    // 打印链表中的元素
    std::cout << "The 10 random integers in the list are:" << std::endl;
    printList(head);

    // 删除链表，释放内存
    deleteList(head);

    return 0;
}

// 创建一个单链表并填充随机整数
node* createList(int size) {
    node *head = nullptr, *tail = nullptr, *newNode = nullptr;

    for (int i = 0; i < size; ++i) {
        // 分配新节点
        newNode = new node;
        newNode->n = rand() % 100; // 随机数范围[0, 99]
        newNode->next = nullptr;

        // 插入到链表末尾
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// 打印链表中的元素
void printList(node *head) {
    node *current = head;
    while (current != nullptr) {
        std::cout << current->n << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 删除链表，释放内存
void deleteList(node *head) {
    node *current = head;
    while (current != nullptr) {
        node *next = current->next;
        delete current;
        current = next;
    }
}