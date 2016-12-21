//
//  unionFind.cpp
//  prog2
//
//  Created by Isaiah Egan on 5/19/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#include "unionFind.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

unionFind::unionFind(int nodes) : n(nodes)
{
    dis.resize(n+1);
    for (int i=1; i<n+1; i++)
    {
        dis[i] = node(i);
    }
}

int unionFind::find(int x)
{
    if(dis[x].parent == x)
    {
        return x;
    }
    
    else
    {
        dis[x].parent = find(dis[x].parent);
        return dis[x].parent;
    }
}

void unionFind::uni(int i, int j)
{
    int q1 = find(i);
    int q2 = find(j);
    
    if (dis[q1].subSize > dis[q2].subSize)
    {
        dis[q2].parent = q1;
    }
    
    else if (dis[q1].subSize < dis[q2].subSize)
    {
        dis[q1].parent = q2;
    }
    
    else
    {
        dis[q1].parent = q2;
        dis[q2].subSize ++;
    }
}



