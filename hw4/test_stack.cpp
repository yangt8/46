#include <iostream>
#include <fstream>
#include "Stack.hpp"
#include "ArrayStack.cpp"
#include "LinkedStack.cpp"
using namespace std;


void printout(ostream& out, string word)      //O(1)
{
    out << word << endl;
}


void fillAll(string file_name, Stack & L)   //O(N)
{
    try
    {
    ifstream f(file_name);
    if (f){
    string w;
    while (f>>w)
    {
         L.push(w);
    }
    f.close();
    }
    else
        cout << "Error: Invalid file to read." << endl;
    }

    catch (ContainerOverflow& e)
    {
        cout << e.get_message()<< endl;
    }
}

void emptyAll(string file_name, Stack & L)   //O(N)
{
    try
    {
    ofstream f(file_name);
    if (f){
    while (L.isEmpty() != true)
    {
        printout(f,L.pop());
    }
    f.close();
    }
    else
        cout << "Error: Invalid file to write." << endl;
    }
    catch (ContainerUnderflow& e)
    {
        cout << e.get_message()<< endl;
    } 
}


bool isBalanced(string brackets)   //O(N^2)
    {   
        LinkedStack l;
        string l1="{[(<";
        string l2="}])>";
        if (brackets.length()%2 != 0)
            return false;
        unsigned int num=0;
        for (unsigned int i = 0; i < brackets.length(); i++)
        {
            int pos = -1;
            if (l1.find(brackets[i])!= string::npos)
                pos = l1.find(brackets[i]);
            if (pos != -1)
            {
                string s;
                s = brackets[i];
                l.push(s);
                num++;
            }
            else
            {
                if (i==0)
                    return false;
                int pos1= l2.find(brackets[num]);
                string ss;
                ss = l1[pos1];
                if (l.isEmpty() && num != brackets.length())
                    return false;
                if (l.pop() != ss)
                    return false;
                num++;
            }
        }
        return (num == brackets.length() && l.isEmpty());
    }


void test_stack(string input_file, string output_file1, string output_file2)   //O(N)
{
    ArrayStack AS(45500);
    fillAll(input_file, AS);
    emptyAll(output_file1, AS);
    
    LinkedStack LS;
    fillAll(input_file, LS);
    emptyAll(output_file2, LS);
}

int main(int argc, char * argv[])   //O(N^2)
{
   cout << "---------TEST isBalanced---------" << endl;
   cout <<"isBalanced('({(())})((([({})])))(((((<>([{()}])(<>))))))()''): " <<isBalanced("({(())})((([({})])))(((((<>([{()}])(<>))))))()") << endl;
   cout <<"isBalanced('({(<>)})((([({})])))(((((()([{()}])(())))))''): " <<isBalanced("({(<>)})((([({})])))(((((()([{()}])(())))))") << endl;
   cout <<"isBalanced('({(<>)})((([({})])))((((([]([{<>}])(()))))))()])''): "<< isBalanced("({(<>)})((([({})])))((((([]([{<>}])(()))))))()])") << endl;

    const char * input_file; 
    const char * output_file1;
    const char * output_file2;
    if (argc == 4)
    {
        input_file = argv[1];
        output_file1 = argv[2];
        output_file2 = argv[3];
    }
    else
    {
        cout << "Error: Invalid number of arguments." << endl;
    }
    cout << "---------TEST Stack---------" << endl;
    test_stack(input_file,output_file1,output_file2);
    
	return 0;
}
