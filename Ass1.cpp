#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#define mytype string
#define INF 100000

using namespace std;

struct node
{
    mytype vertex;
    struct node *next;
};


int n;

vector < mytype > v;


map < mytype , mytype > par;

void make_set(mytype node){
    par.insert(pair<mytype,mytype>(node,node));
}

mytype find_set(mytype n){
    if(par[n] == n){
        return n;
    }
    par[n] = find_set(par[n]);
    return par[n];
}

void union_set(mytype a , mytype b){
    mytype u = find_set(a);
    mytype v = find_set(b);
    if(u != v){
        par[u] = v;
    }
}

int func(map<mytype , node* > ver){
    for(int i = 0 ; i < n ; i++){
        make_set(v[i]);
    }
    for(int i = 0 ; i < n ; i++){
        node* t = ver[v[i]];
        t = t->next;
        while(t != NULL){
            union_set(v[i] , t->vertex);
            t = t->next;
        }
    }
    int ans = 0;
    map < mytype , mytype >::iterator it;
    for(it = par.begin() ; it != par.end() ; it++){
        if(it->first == it->second){
            ans++;
        }
    }
    return ans;
}

int main()
{
    cout << "Nodes ? " << endl;
    cin >> n;

    map<mytype , node* > ver;


    cout << "Enter " << n << " vertices : " << endl;
    for(int i = 0 ; i < n ; i++){
        mytype x;
        cin >> x;
        v.push_back(x);
    }


    for(int i = 0 ; i < n ; i++){
        cout << "Enter number of Adjacence node of " << v[i] << " : \n";
        int e;
        cin >> e;
        node *head = new node();
        head->vertex = v[i];
        head->next = NULL;
        node *current = head;
        cout << "Enter Adjacence nodes of " << v[i] << " : \n";
        for(int j = 0 ; j < e ; j++){
            mytype val;
            cin >> val;
            node *neww = new node();
            neww->vertex = val;
            current->next = neww;
            neww->next = NULL;
            current = neww;
        }
        ver.insert(pair < mytype , node* >(v[i] , head));

    }

   cout << func(ver) << endl;
}

