/// Strongly Connected Component
/*
    God Help Me
    Indrojit Mondal,Dept OF CSE, University Of Barisal */
#include<bits/stdc++.h>
using namespace std;
int StrCount =0;
string StringHome[100];
int Search_Index(string s)
{
    for(int I=0; I<=StrCount; I++)
    {
        if(s==StringHome[I])
        {
            return I;
        }
    }
    StrCount = StrCount + 1;
    StringHome[StrCount] =s;
    return StrCount;
}
vector<int>G[100];
vector<int>R[100];
stack<int>Stack;
int Color[100];
int Time=0;
int D[100];
int F[100];
void DFS(int U)
{
   Time = Time +1;
   Color[U]=1;
   D[U] = Time;
   for(int I =0; I<G[U].size(); I++)
   {
       int V = G[U][I];
       if(Color[V]==0)
       {
          DFS(V);
       }
   }
   Color[U]=2;
   Time = Time +1 ;
   F[U] = Time;
   Stack.push(U);
}
bool Visited[100];
vector<int>Components[100];
int Mark=0;
void DFS2(int Mark,int U)
{
   Components[Mark].push_back(U) ;
   Visited[U]= true;
   for(int I=0; I<R[U].size(); I++)
   {
       int V = R[U][I];
       if(Visited[V]==false)
       {
           DFS2(Mark,V);
       }
   }
}
int main()
{
    int V,E;
    string s1,s2;
    int Node1, Node2;
    cin>>V>>E;
    for(int I=1; I<=E; I++)
    {
        cin>>s1>>s2;
        Node1 = Search_Index(s1);
        Node2 = Search_Index(s2);
        G[Node1].push_back(Node2);
        R[Node2].push_back(Node1);
    }
    for(int I=1; I<=V; I++)
    {
        if(Color[I]==0)
        {
            DFS(I);
        }
    }
    /// Find SCC
    while(!Stack.empty())
    {
        int U= Stack.top();
        Stack.pop();
        if(Visited[U]==false)
        {
            Mark = Mark +1;
            DFS2(Mark,U);
        }
    }
    cout<<"SCC = "<<Mark<<endl;
    cout<<endl;
    for(int I=1; I<=Mark; I++)
    {
         cout<<I<<" : ";
        for(int J=0; J<Components[I].size(); J++)
        {
            int V = Components[I][J];
            cout<<StringHome[V]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
