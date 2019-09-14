#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
class Stack
{
private:
  T * stack;
  int size;
public:
  Stack() { stack = new T[size=1]; stack[0]=0; }
  Stack(T value){ stack = new T[size=1]; stack[0]=value; }
  void Push(T value)    // добавляет элемент в конец стека
  {
       T* result = new T[size];
       for (int i = 0; i < size; i++)
       {
           result[i]=stack[i];
       }
       delete [] stack;
       this->stack = new T[++size];
       for (int i = 0; i < size; i++)
       {
           stack[i]=result[i];
       }
       delete[] result;
       stack[size-1]=value;
  }
  void Pop()   // удаляет последний элемент
  {
       T* result = new T[size];
       for (int i = 0; i < size; i++)
       {
           result[i]=stack[i];
       }
       delete [] stack;
       stack = new T[--size];
       for (int i = 0; i < size; i++)
       {
           stack[i]=result[i];
       }
       delete[] result;
  }
  T Peek() { return stack[size-1]; }   // возвращает последний элемент
  int Count() { return size; }  // возвращает количество элементов в стеке
  void PrintStack() // выводит содержимое стека
  {
      cout<<"The Stack:\n";
  for (int i=0;i<size;i++)
  {
      cout<<stack[i]<<endl;
  }
  }
  bool IsEmpty() { return size==0; } // проверка на пустоту
  ~Stack() { delete [] stack; cout<<"\nStack was deleted"<<endl; }
};

int main()
{
    Stack<double> stack(2.1);
    stack.Push(2.2);
    stack.PrintStack();
    cout<<"The size of stack is "<<stack.Count()<<endl;
    stack.Push(3);
    stack.PrintStack();
    cout<<"The size of stack is "<<stack.Count()<<endl;
    stack.Push(5);
    stack.PrintStack();
    cout<<"The size of stack is "<<stack.Count()<<endl;
    stack.Pop();
    stack.PrintStack();
    cout<<"The tail of stack is "<<stack.Peek()<<endl;
    cout<<"The size of stack is "<<stack.Count()<<endl;
    return 0;
}
