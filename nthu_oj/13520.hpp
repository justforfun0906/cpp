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
        void clear(void);
        int length(void);
    private:
        void resize(void); // double the capacity
        int *data;
        int capacity;
        int size;
};
Darray::~Darray() {
    delete[] data;
}
int& Darray::operator[](int index) {
    if(index < 0 || index >= size) {
        throw "Index out of range";
    } else {
        return data[index];
    }
}
void Darray::pushback(int x){
    if(size == capacity) {
        resize();
    }
    data[size++] = x;
}
void Darray::clear(void){
    size = 0;
}
int Darray::length(void){
    return size;
}
void Darray::resize(void){
    int *new_data = new int[capacity * 2];
    for(int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity *= 2;
}
#endif
