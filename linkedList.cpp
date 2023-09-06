#include <iostream>
using namespace std;
class Node{
    private:
        int value;
        Node* next=nullptr;
    public:
        Node(int value,Node* next){
            this->value=value;
            this->next=next;
        }
        int getValue(){
            return value;
        }
        Node* getNext(){
            return next;
        }
        void setNext(Node* newValue){
            this->next=newValue;
        }
        void setValue(int value){
            this->value=value;
        }
};
class LinkedList{
    private:
        Node* head=nullptr;
        int numNodes=0;
    public :
        LinkedList(){};
        void add(int value){
            Node* tmp=new Node(value,head);
            head=tmp;
            numNodes++;
        }
        void addLast(int value){
            Node* tmp=new Node(value,nullptr);
            if(numNodes==0){
                head=tmp;
                numNodes++;
                return;
            }
            Node*current=head;
            while(current->getNext()!=nullptr){
                current=current->getNext();
            }
            current->setNext(tmp);
            numNodes++;
        }
        void add(int value,int index){
            if(index==0){
                this->add(value);
                numNodes++;
                return;
            }
            Node*current=head;
            for(int i=0;i<index-1;i++){
                current=current->getNext();
            }
            Node*tmp=new Node(value,current->getNext());
            current->setNext(tmp);
            numNodes++;
        }
        int  remove(int index){
            if(numNodes==0){
                throw out_of_range("Empty");
            }
            int removeValue;
            if(index==0){
                removeValue=head->getValue();
                head=head->getNext();
            }
            else{
                Node*current=head;
                for(int i=0;i<index-1;i++){
                    current=current->getNext();
                }
                removeValue=current->getNext()->getValue();
                current->setNext(current->getNext()->getNext());
            }
            numNodes--;
            return removeValue;
        }
        int getValue(int index){
            if(index<0){
                throw out_of_range("Invalid Index");
            }
            Node*current=head;
            for (int i=0;i<index;i++){
                current=current->getNext();
            }
            return current->getValue();
        }
        void removeFrom(int index){
            if(numNodes==0){
                throw out_of_range("Empty");
            }
            int value=this->getValue(index);
            Node*current=head;
            for(int i=0;current!=nullptr;current=current->getNext()){
                if(current->getValue()>value){
                    this->remove(i);
                    continue;
                }
                i++;
            }
        }
        void print(){
            Node*current=head;
            while(current!=nullptr){
                printf("%d ",current->getValue());
                current=current->getNext();
            }
        }
};
int main(){
    LinkedList  list;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        list.addLast(tmp);
    }
    int index;
    cin>>index;
    try{
        list.removeFrom(index);
    }
    catch(out_of_range mess){
        cout<<mess.what();
    }
    list.print();
    return 0;
}