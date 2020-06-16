#include <iostream>
#include <iostream>
#include <vector>

using namespace std;
namespace itertools{

typedef struct{
        template <typename T>
        T operator ()(T a, T b) const{
            return a+b;
        }
    } plus;


template  <typename T,typename Func = plus>
class accumulate{
public:
    T _container;
     Func function;//Creating new function



    accumulate(T container,Func func=plus()):_container(container),function(func){

    }//Init List
class iterator{
public:

    typename T::iterator iter;  //Data Member
    decltype(*(_container.begin())) _data;
    int count;
    Func function;


    explicit iterator(typename T::iterator _iter,Func func):iter(_iter),_data(*iter),count(0),function(func) {

    }    //Constructor

    bool operator !=(const iterator& other){
        return other.iter != iter;
    }

    auto operator *(){


        if(count ==0) {
            count++;
            return *iter;
        }

        _data = function(_data , *iter);
        return _data;

    }

    iterator& operator ++() {
        ++iter;
        return *this;
    }

};


    iterator begin(){
        return iterator(_container.begin(),function);
    }

    iterator end(){
        return iterator(_container.end(),function);
    }



};

}