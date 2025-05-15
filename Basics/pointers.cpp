#include <iostream>
#include <vector>
using namespace std;

// int changeVal(int &ptr)
// {
//     ptr = 20;
// }
// changeVal(a);
// cout << "a = " << a << endl;

int main()
{

    int a = 10;
    int *ptr1 = &a;
    int *ptr2 = ptr1 + 2;

    //    int* ptr=&a;        //Pointer initialization
    //    cout<<ptr<<endl;

    //    cout<<*ptr<<endl;   //value at address of a

    //    int** ptr2 = &ptr;  //pointer to pointer
    //    cout<<ptr2<<endl;

    //    int* ptr3=NULL;     //Null pointer
    //    cout<<ptr3<<endl;


    // int* ptr=&a;                                     //pointer arithmetic

    // cout<<"Original = "<<ptr<<endl; ptr++;           // pointer increment operation
    // cout<<"ptr++ = "<<ptr<<endl; ptr++;
    // cout<<"ptr++ = "<<ptr<<endl;ptr--;                //pointer decrement operation
    // cout<<"ptr-- = "<<ptr<<endl; ptr--;
    // cout<<"ptr-- = "<<ptr<<endl;


    //  cout<<ptr1<<endl;
    //  cout<<ptr2<<endl;                 //substraction of two pointer
    //  cout<<ptr2-ptr1<<endl;


    // cout<<ptr1<<endl;          //pointer comparision
    // cout<<ptr2<<endl;
    // cout<<(ptr1<ptr2)<<endl;   // <    -> 1(true)
    // cout<<(ptr1>ptr2)<<endl;   // >    -> 0(false)
    // cout<<(ptr1<=ptr2)<<endl;  // <=   -> 1(true)
    // cout<<(ptr1>=ptr2)<<endl;  // >=   -> 0(false)
    // cout<<(ptr1==ptr2)<<endl;  // ==   -> 0(false) 


    return 0;
}