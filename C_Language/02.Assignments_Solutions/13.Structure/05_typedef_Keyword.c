void main() 
{
    
    typedef int apple; // typedef : to change any datatype's name as desired 
    apple a = 5;

    typedef struct Student
    {
        int rollno;
        double cgpa;
        char grade;
    }yash; // it's not an object but it's another name to address 'struct Student' datatype;

    yash gorde; // gorde is object of yash datatype i.e struct Student datatype
}