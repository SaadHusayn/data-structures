#ifndef MY_CLASS_H
#define MY_CLASS_H

namespace N {

    
        class MyClass{
        int var;
        public:
        explicit MyClass(int v);
        int getVar() const;
        void setVar(int newVar);
        void display() const;
    };
}



#endif