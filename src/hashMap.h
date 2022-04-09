//
// Created by ll on 2022/4/8.
//

#ifndef COURSE_AUXILIARY_SYSTEM_HASHMAP_H
#define COURSE_AUXILIARY_SYSTEM_HASHMAP_H

static int primes[27] =
        {
                57, 97, 193, 389, 769,
                1543, 3079, 6151, 12289, 24593,
                49157, 98317, 196613, 393241, 786433,
                1572869, 3145739, 6291469, 12582917, 25165843,
                50331653, 100663319, 201326611, 402653189, 805306457,
        };//from web

template<class T1, class T2>
struct Pair {
    T1 first;
    T2 second;

    pair() : first(T1()), second(T2()) {}

    pair(const T1 &a, const T2 &b) : first(a), second(b) {}
};

template<class T>
struct TreeNode {
    TreeNode *left, right;
    T val;

    TreeNode() : left(nullptr), right(nullptr) {}

    TreeNode(T _val) : left(nullptr), right(nullptr), val(_val) {}
};

template<class T>
struct Node {
    T val;
    Node *next;

    Node() : next(nullptr) {}

    Node(T _val) : next(nullptr), val(_val) {}
};

template<class T1, class T2>
class HashNode {
public:
    T1 key;
    T2 value;
    HashNode *next;

    HashNode(T1 _key, T2 _value) {
        key = _key;
        value = _value;
        next = nullptr;
    }

    HashNode &operator = (const HashNode &node) {
        key = node.key;
        value = node.value;
        next = node.next;
        return *this;
    }
};

template<class T1, class T2, class HashFunc>
class HashMap {
public:
    HashMap(int size);

    ~HashMap();

    bool put(const T1 &key, const T2 &value);

    bool del(const T1 &key);

    T2 &get(const T1 &key);

    T2 &operator[](const T1 &key);

private:
    HashFunc hash;//需定义传入对于T1的哈希值计算函数！
    HashNode<T1, T2> **table;//指针数组
    int size;
};

template<class T1, class T2, class HashFunc>
HashMap<T1, T2, HashFunc>::HashMap(int _size):size(_size) {
    table = new HashNode<T1, T2> *[_size];
    for (int i = 0; i < _size; i++) {
        table[i] = nullptr;
    }
}

template<class T1, class T2, class HashFunc>
HashMap<T1, T2, HashFunc>::~HashMap() {
    for (int i = 0; i < size; i++) {
        HashNode<T1, T2> *node = table[i];
        while (node) {
            HashNode<T1, T2> *tmp = node;
            node = node->next;
            delete tmp;
        }
    }
    delete table;
}

template<class T1, class T2, class HashFunc>
bool HashMap<T1, T2, HashFunc>::put(const T1 &_key, const T2 &_value) {
    int index = hash(_key) % size;
    HashNode<T1, T2> *node = table[index];
    while (node) {
        if (node->key == _key) {
            return false;//已有该值
        }
        node = node->next;
    }
    node = new HashNode<T1, T2>(_key, _value);
    node->next = table[index];
    table[index] = node;
    return true;
}

template<class T1, class T2, class HashFunc>
T2 &HashMap<T1, T2, HashFunc>::get(const T1 &_key) {
    int index = hash(_key) % _size;
    HashNode<T1, T2> *node = table[index];
    while (node) {
        if (node->key == _key) {
            return node->value;
        }
        node = node->next;
    }
    return nullptr;
//    node = new HashNode<T1, T2>(key, valueNull);
//    node->next = table[index];
//    table[index] = node;
//    return table[index]->value;//没有就添加
}


template<class T1, class T2, class HashFunc>
T2 &HashMap<T1, T2, HashFunc>::operator[](const T1 &key) {
    return get(key);
}

template<class T1, class T2, class HashFunc>
bool HashMap<T1, T2, HashFunc>::del(const T1 &_key) {
    int index = hash(_key) % size;
    HashNode<T1, T2> *node = table[index];
    HashNode<T1, T2> *preNode = NULL;
    while (node) {
        if (node->key == _key) {
            if (preNode == nullptr) {
                table[index] = node->next;
            } else {
                preNode->next = node->next;
            }
            delete node;
            return true;
        } else {
            preNode = node;
            node = node->next;
        }
    }
    return false;
}


#endif //COURSE_AUXILIARY_SYSTEM_HASHMAP_H
