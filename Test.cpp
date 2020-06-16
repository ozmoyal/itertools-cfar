#include "doctest.h"
#include <iostream>
#include <vector>
#include <limits>

#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"


using namespace itertools;
using namespace std;


TEST_CASE("range"){
    int j = 0;
    for (int i: range(0,101)){
        CHECK(i == j++);
    }
}
