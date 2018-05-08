#ifndef INDEX_H
#define INDEX_H

#include "base.h"

template <typename _Key>
class xhash {
    size_t operator() (const _Key &k) const {
        return size_t(k);
    }
};

template<typename _Key, typename _Value, typename _HashFun=xhash<_Key>, typename _Equal_K=std::equal_to<_Key> >
class hash_map {
};

typedef class Nodes_{
public:
    string url;
    Nodes_* next;
    Nodes_* first;
} Nodes;

int init_index();

#endif
