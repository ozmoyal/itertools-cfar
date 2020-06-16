#include <iostream>
using namespace std;

namespace itertools{
class range{

private:
    int first,last;

public:
    range(int _first,int _last){
        first = _first;
        last = _last;
    }

    //begin , opreator++ , opreator != ,

    class iterator{

    private:
        int val;


    public:
        iterator(int _val):val(_val){}

        iterator& operator++() {
            ++val;
            return *this;
        }

        bool operator!=(iterator& other ) const{
            return this->val != other.val;
        }

        int operator* (){
            return val;
        }
    };

    iterator begin(){
        return iterator(first);
    }

    iterator end(){
        return iterator(last);
    }

};
}