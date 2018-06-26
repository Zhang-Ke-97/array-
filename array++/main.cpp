//
//  main.cpp
//  array++
//
//  Created by Ke on 2018/6/25.
//  Copyright © 2018年 Ke. All rights reserved.
//

#include<iostream>

template<typename T, int L, int H>
class Array{
private:
    T* data; //储存数据
    size_t length = H-L+1; //确定data的长度
    
public:
    Array(){
        data = new T[length]; //为data获取内存空间
    }
    
    ~Array(){
        if (data!=NULL) delete data; //释放data所占据的内存
    }
    
    size_t get_length(){
        return length;
    }
    
    T getIndex(int i){ //获取index=i处的数据
        if(i>=L && i<=H) return *(data+i-L);
        else return *(data); //如果i超出范围 则返回data的第一个数据
    }
    
    T* begin() {return data;}
    T* end() {return data+length;}

    
    /** linear search
     @param v search v in Array arr
     @return Address of v if v is found, NULL if v is not found
     */
    T* linear_search(T v){
        bool found = false;
        T* iterator = this->begin();
        for (; iterator != this->end(); iterator++) {
            if (!found && *iterator == v) {found=true;}
        }
        if (found) {
            return iterator;
        }else{
            return NULL;
        }
    }
    
    
    T& operator [](int i){ //operator overload 获取index=i处的数据的**引用**
        if(i>=L && i<=H) return *(data+i-L);
        else return *(data); //如果i超出范围 则返回data的第一个数据
    }
    
    void setIndex(int i, T value){ //更改index=i处的数据
        if(i>=L && i<=H) *(data+i-L)=value;
        else {std::cout<< "illegal index!";}
    }
    
};



int main(int argc, const char * argv[]) {
    
    Array<int, -2, 1> iarr;
    // Array<int, 1, -1> arrError; <- das darf nicht compilieren
    iarr[-2] = 0;
    iarr[-1] = 42;
    iarr[0] = 0;
    iarr[1] = 0;

    std::cout << "iarr.length = " << iarr.get_length() << std::endl; // 4
    std::cout << "iarr[-1] = " << iarr[-1] << std::endl; // 42
    
    for(int i = -2; i <=1 ; i++){
        std::cout<<iarr[i]<<", ";
    }
    std::cout<<std::endl << "Try with char-Array:" << std::endl;;
    Array<char, 2, 5> arr;
    arr.setIndex(2, 'c');
    arr.setIndex(3, 'd');
    arr[4] = 'e';
    arr[5] = 'f';
    std::cout<<"arr[2] = " <<arr[2]<< std::endl;
    std::cout<<"arr[3] = "<<arr.getIndex(3) << std::endl;
    if(arr.linear_search('f')!=NULL){
        std::cout<<"found f"<<std::endl;
    }else{
        std::cout<<"f not found"<<std::endl;
    }
    return 0;
}
