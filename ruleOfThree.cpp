    #include <iostream>
    using namespace std;

    class
        Array
    {
    private:
        int size;
        int *vals;

    public:
        ~Array();
        Array(int s, int *v);

        // user defined copy constructor 
        Array(Array &Obj){
            size = Obj.size;
            vals = new int[size];
            for(int i=0;i<size;i++){
                vals[i] = Obj.vals[i];
            }
            
        }

    };
    Array::~Array()
    {
        delete vals;
        vals = NULL;
        cout<<"Destructor Called"<<endl;
    }
    Array::Array(int s,
                int *v)
    {
        size = s;
        vals = new int[size];
        std::copy(v, v + size, vals);
    }
    int main()
    {
        int vals[4] = {11, 22, 33, 44};
        Array a1(4, vals);
        // This line causes problems.
        Array a2(a1);

    }