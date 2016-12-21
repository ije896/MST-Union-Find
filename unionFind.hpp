//
//  unionFind.hpp
//  prog2
//
//  Created by Isaiah Egan on 5/19/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#ifndef unionFind_hpp
#define unionFind_hpp

#include <stdio.h>
#include <vector>
using namespace std;

struct node
{
    node(): value(0), subSize(1), parent(0) {};
    node(int v) : value(v), subSize(1), parent(v) {};
    int value;
    int subSize;
    int parent;
};

struct edge
{
    edge(int n1, int n2, int w) : n1(n1), n2(n2), w(w) {};
    node n1;
    node n2;
    int w;
};

class unionFind
{
public:
    
    unionFind(): n(0) {};
    unionFind(int n);
    int find(int x);
    void uni(int i, int j);
    
private:
    
    int n;
    vector<node> dis;
    
};

#endif /* unionFind_hpp */
