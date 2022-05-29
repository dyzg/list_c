#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Student {
    unsigned int no;
    char name[20];
    unsigned int score;
}Data;

typedef struct Node {
    Data data;
    struct Node* pNext;
}node;

node* creatList() {
    node* header = (node*)malloc(sizeof(node));
    if (header == NULL)
    {
        printf("creatList malloc failed!\n");
        return NULL;
    }
    
    header->pNext = NULL;
    return header;
}

node* creatNode(Data data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("creatNode malloc failed!\n");
        return NULL;
    }
    strcpy(newNode->data.name, data.name);
    newNode->data.no = data.no;
    newNode->data.score = data.score;
    newNode->pNext = NULL;
    return newNode;
}

void addData(node* list, Data data) {
    node* newNode = creatNode(data);
    if (newNode == NULL) {
        printf("Creat Node error!");
        return;
    }
    newNode->pNext = list->pNext;
    list->pNext = newNode;
}
node* searchDataByNo(node* list, Data data) {
    node* pMove = list->pNext;
    while (pMove != NULL && pMove->data.no != data.no) {
        pMove = pMove->pNext;
    }

    return pMove;
}

/*
void modifyDataByNo(Node* list, int no) {
    Node* pModify = list->pNext;
    while (pModify != NULL && pModify->data->no != no) {
        pModify = pModify->pNext;
    }
    if (pModify != NULL)
        memcopy(pModify->data, modData);
}
*/
void deleteData(node* list, Data data) {
    node* preNode = list;
    node* posNode = list->pNext;
    while (posNode != NULL && posNode->data.no != data.no) {
        preNode = posNode;
        posNode = preNode->pNext;
    }
    if (posNode == NULL)
        printf("no data to delete");
    else {
        preNode->pNext = posNode->pNext;
        free(posNode);
        printf("delete data success!\n");
    }
}

void printList(node* list){
    node* pMove = list->pNext;
    printf("学号\t 姓名\t 分数\n");
    while (pMove != NULL) {
        printf("%d\t %s\t %d\n", pMove->data.no, pMove->data.name, pMove->data.score);
        pMove = pMove->pNext;
    }
}
int main()
{
    node* studentList = creatList();
    Data student1 = { 1, "xiaoming", 50 };
    Data student2 = { 2, "xiaohong", 70 };
    Data student3 = { 3, "xiaozhang", 80 };
    addData(studentList, student1);
    addData(studentList, student2);
    addData(studentList, student3);

    printList(studentList);
    deleteData(studentList, student1);
    printList(studentList);    
    return 0;

}
