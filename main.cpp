#include "tree.hpp"
#include <iostream>

using namespace BSTree;

int main() {


    Tree<int> tree = {5, 3, 4, 2, 7, 9, 6, 8};

    pre_iterator<int> it = tree.begin();
    pre_iterator <int> it1 = tree.end();
   std::cout << *it << std::endl;
 std::cout << *it1 << std::endl;

      auto end = tree.end();

      for (; it != end; ++it ) {
          std::cout << *it << ' ';
      }
        std::cout << *it << ' ';

      std::cout << std::endl;

      auto rit = tree.rbegin();
      auto rend = tree.rend();
      std::cout << *rit << std::endl;
      std::cout << *rend << std::endl;
      for(; rit != rend; ++rit) {
        std::cout << *rit << ' ';
      }
      std::cout << *rend << std::endl;
      std::cout << std::endl;

}
