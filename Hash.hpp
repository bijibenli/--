#pragma once
#include<iostream>
using namespace std;
const int SIZE = 1000;
const int M = 999997;

struct HashTable 
{
    struct Node //¿≠¡¥∑®  ∑¿÷π≥ÂÕª
    {
        int next, value, key;
    } data[SIZE];

    int head[M], size;

    int f(int key) 
    { 
        return key % M; 
    }

    int get(int key) 
    {
        for (int p = head[f(key)]; p; p = data[p].next)
        {
            if (data[p].key == key)
            {
                return data[p].value;
            }
        }
        return -1;
    }

    int modify(int key, int value) 
    {
        for (int p = head[f(key)]; p; p = data[p].next)
        {
            if (data[p].key == key)
            {
                return data[p].value = value;
            }
        }
    }

    int add(int key, int value) 
    {
        if (get(key) != -1) return -1;
        Node node;
        node.next = head[f(key)];
        node.key = key;
        node.value = value;
        data[++size] = node;
        head[f(key)] = size;
        return value;
    }
};

HashTable q_sh;