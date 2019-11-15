#include <iostream>
#include <fstream> // for doing file I/O
using namespace std;
// Class MyString defines a class similar to "std::string"

class MyString
{
  char * buf; // points to the array holding the characters in this MyString object.
  // Must be allocated in constructor and, maybe in other functions as well
  // This C-string must be null termiated and that is how you know the length
  // strlen() will count the number of characters up to the first null character
  
  // utility method to handle errors, note throws an exception to prevent
  // access to undefined values.  Always call this method when you detect a fatal error from
  // any of your methods.
  void error(const char *s)    //1001
  {
    cerr << "Error: " << s << endl; //1000
    throw 0; //1
  }

private:

  int strlen(const char *s) const  // T(N) = 3N+2
  { 
    int len = 0; //1
    while (s[len] != '\0' )  //2N
      ++len;  //N
    return len; //1
  }


  char * strdup(const char *s) const// T(N) = 3n^2+13N+1011
  {
    NumAllocations++;//2
    return strcpy(new char[strlen(s) + 1], s); 
  }

  int strcmp(char *str1,char *str2) const   // T(N) = 3N^2+8N+2
  {
    if (strlen(str1)!=strlen(str2))//6N+5
      return 0; //1
    else
      for (int i=0; i<strlen(str1); i++)//3N^2+4N+1
      {
        if (str1[i]!=str2[i]) //3N
          return 0; //N
      }
      return 1; //1
  }

  char * strrev(char *dest, char *sr) const // T(N) = 6N^2+10N+2
  {
    for (unsigned int i=1;i<=strlen(sr) ;i++) //3N^2+4N+1
      dest[strlen(sr)-i]=sr[i-1]; //(3N+6)N
    return dest; //1
  }

  char * strstr(char * str1, const string & str2) const// T(N) = 12N^2+10N+2
  {
    for (int i=0; i<strlen(str1);i++)//3N^2+4N+1
    {
      if (str1[i]==str2[0]) //3N
      {
        int u=1; //N
        for (int j =1;j< str2.size();j++) //3N^2+N
        {
          if (str1[i+j]!=str2[j]) //4N^2
            u=-1; //N^2
        }
        if (u==1) //N
          return str1+i; //N^2
      }
    }
    return NULL; //1
  }

  char * strcpy(char *dst, const char *src) const  // T(N) = 3N^2+10N+6
  {
    dst[strlen(src)] = '\0';//3N+4
    for (unsigned int i=0;i<strlen(src);i++) //3N^2+4N+1
      dst[i]=src[i]; //3N
    return dst;  //1
  }

  char *str2dup(char* s,char* buf) const// T(N) = 3N^2+10N+7
  { 
    return strcpy(s, buf);  //3N^2+10N+6
  }

  char *strcat(char *v,char *s) const // T(N) = 3N^2+11N+4
  {
    int j=strlen(v); //3N+2
    for (unsigned int i=0;i<strlen(s);i++) //3N^2+4N+1
    {
      v[j+i]=s[i];//4N
    }
    return v;//1
  }

public:
  static int NumAllocations;

  explicit MyString( const char* s = "") // T(N) = 3n^2+13N+1011
  // constructs this object from a c-string s (s is an array of char terminated by ‘\0’)
  // parameter, s, defaults to the empty string “”
  // write and use strdup() to implment this constructor, 
  // it allocates a new array, then uses strcpy() to copy chars from array s to the new array
  {
    buf = strdup(s);  //3n^2+13N+1011
  }
  
  // copy constructor for a MyString, must make a deep copy of
  // s for this.  You can use strdup() you wrote
  MyString( const MyString & s ) // T(N) = 3n^2+13N+1011
  {
    buf = strdup(s.buf);  //3n^2+13N+1011
  }
  
  // assigns this MyString from MyString s, MUST DO DEEP ASSIGNMENT
  // remember, both this and s have been previously constructed
  // so they each have storage pointed to by buf
  MyString & operator = ( const MyString & s )// T(N) = 3n^2+13N+3013
  {
    if (this != &s) //1
    {
      delete[] buf;  //1000
      buf = strdup(s.buf); //3n^2+13N+1011
      NumAllocations--; //1000
    }
    return *this; //1
  }
  
  // return a reference to the char at position index, 0 is the first element and so on
  // index must be in bounds (see method above)
  char & operator [] ( const int index ) // T(N) = 2
  {
    return buf[index]; //2
  }
   
  int length() const   // T(N) = 3N+3
  {
    return strlen(buf); //3N+3
  }
  
  // returns the index of the first occurance of c in this MyString
  // indices range from 0 to length()-1
  // returns -1 if the character c is not in this MyString
  int indexOf( char c ) const  // T(N) = 3N^2+6N+2
  {
    for (int i=0; i<strlen(buf);i++) //3N^2+4N+1
    {
      if (buf[i]==c) //2N
        return i; //N
    }
    return -1; //1
  }
  
  // returns the index of the first occurance of pat in this MyString
  // indices range from 0 to length()-1
  // returns -1 if the character string pat is not in this MyString
  // write and use strstr() to implement this function
  int indexOf( const string & pat ) const // T(N) = 12N^2+10N+4
  {
    if (strstr(buf,pat)==NULL) //12N^2+8N+3
      return -1; //1
    else
      return strstr(buf,pat)-buf; //12N^2+10N+4
  }
  
  // True if the two MyStrings contain the same chars in same position
  // e.g, "abc"=="abc" returns true
  // write and use strcmp() to implement this function
  bool operator == ( const MyString & s ) const // T(N) = 9N^2+10N+4
  {
    return (strcmp(buf,s.buf)!=0); //9N^2+10N+
  }
  
  // concatenates this and s to make a new MyString
  // e.g., "abc"+"def" returns "abcdef"
  // write and use str2dup() to implement this function, it should allocate a new array then call strcpy() and strcat()
  MyString operator + ( const MyString & s ) const // T(N) = 9N^2+49N+3042
  {
    MyString m; 
    char* v = new char[strlen(buf) + strlen(s.buf)+1]; //6N+1007
    NumAllocations++;//1
    v[strlen(buf)+strlen(s.buf)]='\0'; //6N+6
    str2dup(v,buf);  //3N^2+10N+7
    v[strlen(buf)]='\0'; //3N+4
    strcat(v,s.buf); //3N^2+11N+4
    delete[] m.buf; //1000
    NumAllocations--;
    m.buf= v; //1
    return m; //1
  }



  // concatenates s onto end of this
  // e.g., s = "abc"; s+="def" now s is "abcdef"
  // use str2dup()
  MyString & operator += ( const MyString & s ) // T(N) = 6N^2+36N+2032
  {
    char* v = new char[strlen(buf) + strlen(s.buf)+1]; //6N+1007
    NumAllocations++; //1
    v[strlen(buf)+strlen(s.buf)]='\0'; //6N+6
    str2dup(v,buf);  //3N^2+10N+7
    v[strlen(buf)]='\0'; //3N+4
    strcat(v,s.buf); //3N^2+11N+4
    delete[] buf; //1000
    NumAllocations--; //1
    buf = v; //1
    return *this; //1

  }
  
  // returns another MyString that is the reverse of this MyString
  // e.g., s = "abc"; s.reverse() returns "cba"
  // write strrev(char *dest, char *src) like strcpy but copies the reverse of src into dest, then use it
  MyString reverse() const // T(N) = 9N^2+29N+3019
  {
    MyString m;  //3n^2+13N+1011
    char* v = new char[strlen(buf)+1];  //3N+1004
    NumAllocations++; //1
    v[strlen(buf)]='\0'; //3N+4
    strrev(v,buf); //6N^2+10N+2
    delete[] m.buf; //1000
    NumAllocations--;//1
    m.buf = v; //1
    return m; //1
  }
  
  // prints out this MyString to the ostream out
  void print( ostream & out ) const // T(N) = 3N^2+106N+1
  {
    for (unsigned int i=0;i<strlen(buf);i++) //3N^2+4N+1
    {
      if (buf[i]!='\0') //2N
        out<<buf[i];  //1001N
    }
  }
  
  // reads a word from the istream in and this MyString
  // becomes the same as the characters in that word
  // use getline() to implement read()
  void read( istream & in ) // T(N) = 3n^2+13N+3014
  {
    char local[2014]; //1
    in.getline(local,2014);//1001
    delete[] buf;//1000
    NumAllocations--;//1
    buf = strdup(local);//3n^2+13N+1011
  }
  
  // destruct a MyString, must free up any storage allocated within MyString
  ~MyString()  // T(N) = 1001
  {
    NumAllocations--; //1
    delete[] buf; //1000
  }
};

int MyString::NumAllocations = 0;

// these two I/O methods are complete as long as you define print and read methods correctly
inline ostream & operator << ( ostream & out, const MyString & str )// T(N) = 3N^2+106N+2
{
  str.print(out); //3N^2+106N+1
  return out;  //1
}

inline istream & operator >> ( istream & in, MyString & str ) //T(n)=3n^2+13N+3015
{
  str.read(in); //3n^2+13N+3014
  return in; //1
}

// TBD: Write all these testing functions and add more of your own
// follow my example and write a function to test each method.
// Name each of these functions so they clearly indicate what they are testing

MyString copyConstructorTest(MyString l)  // T(N) = 1
{
  return l; //1
}

void testReverse()  // T(N) = 15N^2+1045N+8032
{
  ifstream in("input.txt"); //1000
  MyString l; //3N^2+13N+1010
  while ( in >> l ) //1000N
  {
    cout << copyConstructorTest(l) //N
         << " " << l.length() << " " //3N^2+2N
         << l.reverse() << endl; // 9N^2+29N+4022
  }       //1000
}


void testCopy() // T(N) = 21N^2+248N+7028
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test Copy" << endl;//1000
  MyString m("abc");//3n^2+13N+1011
  MyString m1(m); //3n^2+13N+1011
  cout << "m: " << m << endl; //3N^2+106N+1001
  cout << "m1: " << m1 << endl; //3N^2+106N+1001
  if (m==m1) //9N^2+10N+4
    cout <<"m==m1 is true." << "\n" << endl; //1000
}

void testAssign() // T(N) = 21N^2+248N+8030
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test Assign" << endl;//1000
  MyString m("abc");//3n^2+13N+1011
  MyString m1=m;  //3n^2+13N+3013
  cout << "m: " << m << endl;//3N^2+106N+1001
  cout << "m1: " << m1 << endl;//3N^2+106N+1001
  if (m1==m)                  //9N^2+10N+4
    cout <<"m==m1 is true." << "\n" <<endl;//1000
}

void testIndex() // T(N) = 6N^2+119N+4014
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test Index" << endl;//1000
  MyString m("abcdefg");//3n^2+13N+1011
  cout <<"m: "<< m << "   m[3]: "<< m[3] <<"\n" << endl; //3N^2+106N+1003
}

void testLength() // T(N) = 6N^2+116N+4015
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test Length" << endl;//1000
  MyString m("abcdefg"); //3n^2+13N+1011
  cout <<"m: "<< m << "   m.length(): "<< m.length() <<"\n" << endl; //3N^2+103N+1004
}

void testInDexOfChar() // T(N) = 12N^2+131N+4016
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test IndexOfChar" << endl;//1000
  MyString m("abcdefg");//3n^2+13N+1011
  cout <<"m: "<< m << "   m.indexOf('b'):"<< m.indexOf('b') << "   m.indexOf('e'):" << m.indexOf('p')<<"\n" <<endl; //9N^2+118N+1005
}

void testInDexOfStr() // T(N) = 30N^2+139N+4020
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test IndexOfStr" << endl;//1000
  MyString m("abcdefgh"); //3n^2+13N+1011
  cout <<"m: "<< m << "   m.indexOf('def'):"<< m.indexOf("def") << "   m.indexOf('ded'):" << m.indexOf("ded")<<"\n" <<endl; //27N^2+126N+1009
}

void testEqualOperator() // T(N) = 21N^2+248N+4028
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test EqualOperator" << endl;//1000
  MyString m1("abcd");//3n^2+13N+1011
  MyString m2("abcd");//3n^2+13N+1011
  if (m1==m2)         //9N^2+10N+4
    cout <<"m1: "<< m1 << "   m2: "<< m2 << "   m1==m2 is true." << "\n" <<endl;//6N^2+212N+1002

}

void testAddOperator() // T(N) = 39N^2+336N+12104
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test AddOperator" << endl;//1000
  MyString m1("abcd");//3n^2+13N+1011
  MyString m2("efgh");//3n^2+13N+1011
  MyString m4("abcdefgh");//3n^2+13N+1011
  MyString m3;//3n^2+13N+1011
  m3=m1+m2;   //12N^2+62N+6054
  if (m3==m4) //9N^2+10N+4
    cout <<"m3: "<< m3 << "   m4: "<< m4 << "   m3==m4 is true." << "\n" <<endl;//6N^2+212N+1002
}

void testAddEqualOperator() // T(N) = 30N^2+297N+7071
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test AddEqualOperator" << endl;//1000
  MyString m1("abcd");//3n^2+13N+1011
  MyString m2("efgh");//3n^2+13N+1011
  MyString m3("abcdefgh");//3n^2+13N+1011
  m1+=m2;              //6N^2+36N+2032
  if (m1==m3)          //9N^2+10N+4
    cout <<"m1: "<< m1 << "   m3: "<< m3 << "   m1==m3 is true." <<"\n" <<endl;//6N^2+212N+1002
}

void testReverse2()  // T(N) = 27N^2+171N+7049
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test Reverse2" << endl;//1000
  MyString m1("abcd");//3n^2+13N+1011
  MyString m2("dcba");//3n^2+13N+1011
  if (m1.reverse()==m2)//9N^2+10N+4
    cout <<"m1.reverse(): "<< m1.reverse() << "   m2: "<< m2 << "   m1.reverse()==m2 is true." <<"\n" << endl;//12N^2+135N+4023
}

void testRead()  // T(N) = 9N^2+132N+8026
{
  cout << "-----------------------------------------------------------" << endl;//1000
  cout << "test Read" << endl;//1000
  MyString m; //3n^2+13N+1011
  cout << "Please input a word: " << endl;//1000
  cin >>  m ; //3n^2+13N+3014
  cout << "Your input is: " << m <<"\n"<< endl; //3N^2+106N+1001
}

// write more test functions here
// ...

int main()
{
  // This try/catch will catch any exception thrown by MyString::error()
  // while calling test functions.
  try {
    testReverse();
    testCopy();
    testAssign();
    testIndex();
    testLength();
    testInDexOfChar();
    testInDexOfStr();
    testEqualOperator();
    testAddOperator();
    testAddEqualOperator();
    testReverse2();
    testRead();
    // put more test function calls here written just above
  }
  catch (int i) {
    cout << "Got an exception: " << i << endl;
  }
  cerr << "Net memory allocated at program end: " << MyString::NumAllocations << endl;
  cerr << "(should be zero! positive = memory leak, negative = duplicate delete)\n";
  return 0;
}
