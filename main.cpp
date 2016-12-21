//
//  main.cpp
//  prog2
//
//  Created by Isaiah Egan on 5/18/16.
//  Copyright © 2016 Isaiah Egan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

#include "unionFind.hpp"

using namespace std;

struct comp
{
    inline bool operator() (edge& x, edge& y)
    {
        return (x.w < y.w);
    }
};

int MST(vector<edge> ed, int n)
{
    unionFind UF = unionFind(n); //union find
    vector<edge> MST;               //final product that we continuously add to
    sort(ed.begin(), ed.end(), comp()); //sort the edges
    int iter = 0;

    while (MST.size()<n-1) //create the MST
    {
        
        edge cand = ed[iter];
        int s1 = UF.find(cand.n1.value);
        int s2 = UF.find(cand.n2.value);
        
        if (s1!=s2) //add to MST
        {
            MST.push_back(cand);
            UF.uni(s1, s2);
            cout<<"Edge ("<<cand.n1.value<<","<<cand.n2.value<<") successfully inserted"<<endl;
        }
        
        else if (s1==s2)//output error message
        {
            cout<<"Edge ("<<cand.n1.value<<","<<cand.n2.value<<") creates cycle"<<endl;
        }

        iter++;
    }
    
    int path = 0;
    for (unsigned int i=0; i<MST.size(); i++)
    {
        cout<<MST[i].n1.value<<" ";
        cout<<MST[i].n2.value<<endl;
        path+=MST[i].w;
    }
    return path;
    
}

int main()
{
    string x, y, z;
    
    vector<edge> edges; //container for all edges
                    
    cin >> x >> y;
    
    int n = atoi(x.c_str());
    int e = atoi(y.c_str());
    if (e<n-1)
    {
        cout<<"ERROR: MST not found"<<endl;
        exit(1);
    }
    
    while(cin >> x >> y >> z)
    {
        int f = atoi(x.c_str());
        int s = atoi(y.c_str());
        int w = atoi(z.c_str());
        edges.push_back(edge(f, s, w));
    }


    int weight = MST(edges, n);
    cout << weight << endl;
    return 0;
}
