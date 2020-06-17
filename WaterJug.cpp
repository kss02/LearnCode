/* This program uses BFS to find the solution for famous Water-Jug problem.....
Two jugs Jug1 and Jug2 with finite max capacity are given and no markings available to measure the water level in the jugs
Given a target level which is needed to be measured in Jug1......
Find the possibilty for above problem and if  possible determine path for the result

Operations: Continuos water supply i.e jugs can be filled any time
            Jug can be emptied or water can be poured from one jug to another........
      
*/      
      
      
#include <bits/stdc++.h> 
#define pii pair<int, int> 
#define mp make_pair 
using namespace std; 

void BFS(int a, int b, int target) 
{ 
	
	map<pii, int> m; 
	bool isSolvable = false; 
	vector<pii> path; 

	queue<pii> q; 
	q.push({ 0, 0 });

	while (!q.empty()) { 

		pii u = q.front(); 

		q.pop();

if (m[{ u.first, u.second }] == 1) 
			continue; 

if ((u.first > a || u.second > b || 
			u.first < 0 || u.second < 0)) 
			continue; 

path.push_back({ u.first, u.second }); 
m[{ u.first, u.second }] = 1; 

		if (u.first == target || u.second == target) { 
			isSolvable = true; 
			if (u.first == target) { 
				if (u.second != 0) 
        path.push_back({ u.first, 0 }); 
			} 
			else { 
				if (u.first != 0) 
        path.push_back({ 0, u.second }); 
			} 
  int sz = path.size(); 
			for (int i = 0; i < sz; i++) 
				cout << "(" << path[i].first 
					<< ", " << path[i].second << ")\n"; 
			break; 
		} 
    
    q.push({ u.first, b }); 
		q.push({ a, u.second }); 

		for (int ap = 0; ap <= max(a, b); ap++) { 
      int c = u.first + ap; 
			int d = u.second - ap; 

if (c == a || (d == 0 && d >= 0)) 
				q.push({ c, d }); 

      c = u.first - ap; 
			d = u.second + ap; 

			
			if ((c == 0 && c >= 0) || d == b) 
				q.push({ c, d }); 
		} 

		q.push({ a, 0 }); 
		q.push({ 0, b });  
	} 

 
	if (!isSolvable) 
		cout << "No solution"; 
} 


int main() 
{ 
	int Jug1 , Jug2 , target ; 
  cout<<"Enter Jug1 capacity:"<<endl;
  cin>>Jug1;
  
  cout<<"Enter Jug2 capacity:"<<endl;
  cin>>Jug2;
  
  cout<<"Enter Target Level:"<<endl;
  cin>>target;
  
	cout<<"AI Processing........ (BFS)"<<endl;
	
  BFS(Jug1, Jug2, target); 
	return 0; 
} 