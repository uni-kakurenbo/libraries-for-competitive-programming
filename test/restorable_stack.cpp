#include <iostream>
#include <string>

#include "template.hpp"
#include "data_structure/restorable_stack.hpp"

signed main() {
    int q; std::cin >> q;
    RestorableStack<int> A;

    LOOP(q) {
        std::string query; std::cin >> query;
        if (query == "ADD") {
            int x; std::cin >> x; A.push(x);
            std::cout << A.top() << spc;
        }
        if (query == "DELETE") {
            if(!A.empty()) A.pop();
            std::cout << A.top_or(-1) << spc;
        }
        if (query == "SAVE") {
            int x; std::cin >> x; A.save(x);
            std::cout << A.top_or(-1) << spc;
        }
        if (query == "LOAD") {
            int x; std::cin >> x;
            A.stored(x) ? A.load(x) : A.clear();
            std::cout << A.top_or(-1) << spc;
        }
    }

    return 0;
}
