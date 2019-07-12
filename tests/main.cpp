
//#define CATCH_CONFIG_MAIN
//#include "catch2/catch.hpp"

#include "src/mylib/List.hpp"

int main(int count, char** argv) {
    using mylib::List;
    using mylib::Node;

    List<int> list;
    list.Push(1);
    list.Push(2);
    list.Push(3);
    list.Push(4);
    list.Push(5);
    list.Push(6);
    list.Push(7);
    list.Push(8);
    list.Echo();
    std::cout << "-----------test serach---------" << std::endl;
    auto item = list.Search(4);
    item->data_ = 19;
    list.Echo();

    std::cout << "---------test insert-- ---------" << std::endl;
    auto item_insert = new Node<int>(33);
    list.InsertAfter(2, item_insert);
    list.Echo();

    std::cout << " -----------test del-- ------- " << std::endl;
    list.DeleteAfter(3);
    list.Echo();
    return 0;
}
