#include<iostream>
using namespace std;

int main(){
    int n = 4;

    // for(int i=1;i<=n;i++){           1 2 3 4 
    //     for(int j=1;j<=n;j++){       1 2 3 4 
    //         cout<<j<<" ";            1 2 3 4 
    //     }                            1 2 3 4 
    //     cout<<endl;
    // }
    
    // for (int i = 0; i < n; i++)      * * * *
    // {                                * * * *
    //    for (int j = 0; j < n; j++)   * * * *
    //    {                             * * * *
    //       cout<<"*"<<" ";
    //    }
    //    cout<<endl;
    // }

    // int number=1;                         1 2 3 4
    //  for (int i = 1; i <=n; i++)          5 6 7 8
    // {                                     9 10 11 12
    //    for (int j = 1; j <= n; j++)       13 14 15 16
    //    {
    //       cout<<number<<" ";
    //       number++;
    //    }
    //    cout<<endl;
    // }
    

    //  char alpha='A';                        
    //  for (int i = 1; i <=n; i++)          
    // {                                   A B C D 
    //    for (int j = 1; j <= n; j++)     E F G H    
    //    {                                I J K L
    //       cout<<alpha<<" ";             M N O P
    //       alpha++;
    //    }
    //    cout<<endl;
    // }

    
    //    for (int i = 0; i < n; i++)         * 
    //     {                                  * * 
    //        for (int j = 0; j < i+1; j++)   * * * 
    //        {                               * * * *
    //           cout<<"*"<<" ";
    //        }
    //        cout<<endl;
    //     }


    
    //    for (int i = 0; i < n; i++)              1
    //     {                                       1 2  
    //        for (int j = 1; j <= i+1; j++)       1 2 3 
    //        {                                    1 2 3 4 
    //           cout<<j<<" ";
              
    //        }
    //        cout<<endl;
    //     }



    //  int num=1; 
    //    for (int i = 0; i < n; i++)           1
    //     {                                    2 2
    //        for (int j = 0; j < i+1; j++)     3 3 3
    //        {                                 4 4 4 4
    //           cout<<num<<" ";
    
    //        }
    //        num++;
    //        cout<<endl;
    //     }

    
    

    //  char ch='A'; 
    //    for (int i = 0; i < n; i++)           A
    //     {                                    B B
    //        for (int j = 0; j < i+1; j++)     C C C
    //        {                                 D D D D
    //           cout<<ch<<" ";
    
    //        }
    //        ch++;
    //        cout<<endl;
    //     }

    // for(int i=0;i<n;i++)
    // {                               
    //    for(int j=i+1;j>0;j--)                 1
    //    {                                      2 1
    //      cout<<j<<" ";                        3 2 1
    //    }                                      4 3 2 1
    //    cout<<endl;
    // }


    //   int number=1;                            1
    //      for (int i = 0; i <n; i++)            2 3 
    //     {                                      4 5 6
    //        for (int j = 0; j < i+1; j++)       7 8 9 10
    //        {
    //           cout<<number<<" ";
    //           number++;
    //        }
    //        cout<<endl;
    //     }
        
    //   char ch='A';                               A
    //      for (int i = 0; i <n; i++)              B C
    //     {                                        D E F
    //        for (int j = 0; j < i+1; j++)         G H I J
    //        {
    //           cout<<ch<<" ";
    //           ch++;
    //        }
    //        cout<<endl;
    //     }

        
                         
    //  for (int i = 0; i < n; i++)             A
    // {                                        B A
    //    for (int j = i+1; j > 0; j--)         C B A
    //    {                                     D C B A
    //       cout<<(char)('A' + j-1)<<" ";
    //    }
    //    cout<<endl;
    // }
                
    //    for(int i=0;i<n;i++)                 
    //    {                                1 1 1 1
    //     for (int k = 0; k<i; k++)        2 2 2
    //         {                             3 3
    //            cout<<" ";                  4
    //         }
    //     for(int j=n;j>i;j--)
    //         {
    //            cout<<i+1<<" ";
    //         }
    //      cout<<endl;
    //    }
         

                  
    //    for(int i=0;i<n;i++)
    //    {                                 1111
    //     for (int k = 0; k<i; k++)         222
    //         {                              33
    //            cout<<" ";                   4
    //         }
    //     for(int j=n;j>i;j--)
    //         {
    //            cout<<i+1;
    //         }
    //      cout<<endl;
    //    }
          
                //   OR 

    //    for(int i=0;i<n;i++)                 1111
    //    {                                     222
    //     for (int k = 0; k<i; k++)             33
    //         {                                  4
    //            cout<<" ";
    //         }
    //     for(int j=0;j<n-i;j++)
    //         {
    //            cout<<i+1;
    //         }
    //      cout<<endl;
    //    }

          
    //   char ch='A';                       
    //    for(int i=0;i<n;i++)                 AAAA
    //    {                                     BBB
    //     for (int k = 0; k<i; k++)             CC
    //         {                                  D
    //            cout<<" ";
    //         }
    //     for(int j=0;j<n-i;j++)
    //         {
    //            cout<<ch;
               
    //         }
    //      ch++;
    //      cout<<endl;
    //    }
          

    //   for(int i=0;i<n;i++)
    //   {
    //     for(int j=0;j<n-i;j++)                1
    //     {                                    121
    //        cout<<" ";                       12321
    //     }                                  1234321
    //     for(int k=0;k<i+1;k++)
    //     {
    //         cout<<k+1;
    //     }
    //     for(int k=i;k>0;k--)
    //     {
    //         cout<<k;
    //     }
    //     cout<<endl;
    //   }

    
    // for(int i=0;i<n;i++){
    //     for (int j = 0; j < n-i; j++)
    //     {
    //         cout<<" ";
    //     }
    //        cout<<"*";
    //    for (int j = 0; j <2*i-1; j++)                       *
    //     {                                                  * *
    //         cout<<" ";                                    *   *
    //     }                                                *     *
    //     if(i != 0){                                       *   *
    //       cout<<"*";                                       * *
    //     }                                                   *
    //     
    //
    //     cout<<endl;
    // }
    //
    // for(int i=n-2;i>=0;i--){
    //     for (int j = 0; j < n-i; j++)
    //     {
    //         cout<<" ";
    //     }
    //        cout<<"*";
    //    for (int j = 0; j <2*i-1; j++)
    //     {
    //         cout<<" ";
    //     }
    //     if(i != 0){
    //       cout<<"*";
    //     }
    //     
    //
    //     cout<<endl;
    // }




                                                 
            // *      *
            // **    **
            // ***  ***
            // ********
            // ********
            // ***  ***
            // **    **
            // *      *                                          
                                    

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //          cout<<"*";
    //     }
    //     for(int k=0;k<(2*(n-i)-2);k++){
    //           cout<<" ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //          cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=n-1;i>=0;i--){
    //     for(int j=0;j<i+1;j++){
    //          cout<<"*";
    //     }
    //     for(int k=0;k<(2*(n-i)-2);k++){
    //           cout<<" ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //          cout<<"*";
    //     }
    //     cout<<endl;
    // }






    return 0;
}