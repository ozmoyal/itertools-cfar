#include <iostream>
#include <iostream>
#include <vector>

namespace itertools{

using namespace std;


    template  <typename Boola,typename T>
    class compress {
    public:
        T _container;
        Boola borolarr;//Creating new function

        compress (T cont,Boola func):_container(cont),borolarr(func){}

        class iterator{
        public:
            typename T::iterator iter;  //Data Member
            typename Boola::iterator booliter;


            explicit iterator(typename T::iterator _iter,typename Boola::iterator _boolarr):iter(_iter),booliter(_boolarr) {}

            bool operator !=(const iterator& other){
                while (other.iter!=iter){
                    if(*booliter== true){
                        return other.iter != iter;
                    }
                    else{
                        ++iter;
                        ++booliter;
                    }
                }

                return false;
            }

            auto operator *(){

                return *iter;
            }

            iterator& operator ++() {
                ++iter;
                ++booliter;
                return *this;
            }
//{5,9,7,8}

        };

        iterator begin(){
            return iterator(_container.begin(),borolarr.begin());

        }

        iterator end(){
            return iterator(_container.end(),borolarr.end());

        }


    };
}