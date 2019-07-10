
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

    auto item = list.Search(3);
    item->data_ = 19;
    list.Echo();

    list.InsertAfter(item);
    list.Echo();

    list.DeleteAfter();
    list.Echo();
    return 0;
}
