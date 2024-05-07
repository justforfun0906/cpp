#ifndef FUNCTION_H
#define FUNCTION_H
class Darray {
    public:
        Darray() {
            capacity = 100;
            size = 0;
            data = new int[capacity];
        };
        ~Darray();
        int& operator[](int);
        void pushback(int x);
        void popback(void);
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};
#endif
Darray::~Darray(){
    delete[] data;
}
int& Darray::operator[](int index){
    return data[index];
}
void Darray::pushback(int x){
    if(size == capacity) resize();
    data[size++] = x;
}
void Darray::popback(void){
    if(size > 0) size--;
}
void Darray::clear(void){
    size = 0;
}
int Darray::length(void){
    return size;
}
void Darray::resize(void){
    int *tmp = new int[capacity*2];
    for(int i=0; i<size; i++){
        tmp[i] = data[i];
    }
    delete[] data;
    data = tmp;
    capacity *= 2;
}