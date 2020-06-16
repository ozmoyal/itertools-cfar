#include <iostream>
#include <iostream>
#include <vector>

using namespace std;
namespace itertools{

    template  <typename Func,typename T>
    class filterfalse{
    public:
        T _container;
        Func function;//Creating new function

        filterfalse(Func func,T cont):function(func),_container(cont){}

        class iterator{
        public:
            typename T::iterator iter;  //Data Member
            Func function;


            explicit iterator(typename T::iterator _iter,Func func):iter(_iter),function(func) {}
           // {2,4,6,5}
            bool operator !=(const iterator& other){
                while (other.iter != iter){
                    if(!function(*iter)){
                        return other.iter != iter;
                    }
                    else{
                        ++iter;
                    }
                }
                return false;
            }

            auto operator *(){

                return *iter;
            }

            iterator& operator ++() {
                ++iter;
                return *this;
            }
//{5,9,7,8}

        };

            iterator begin(){
                return iterator(_container.begin(),function);

            }

            iterator end(){
                return iterator(_container.end(),function);

            }


    };
}