#include <bits/stdc++.h>

using namespace std;



struct point{
    int x, y;
};


int orientation(point p, point q, point r) 
{ 
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if (val==0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

point pref;

float dist(point p, point q){
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}


int Comparator(const void *p, const void *q) 
{ 
   point *p1 = (point *)p; 
   point *p2 = (point *)q; 
       //find orientation and then compare orientation of p1 and p2 wrt p0
   int r = orientation(pref, *p1, *p2); 
    //same polar angle->return the point with closer to p0 first
   if (r == 0){
     if(dist(pref, *p2) >= dist(pref, *p1)) return -1;
	else return 1; }
  
   if(r==2) return -1;
   else return 1; 
}

point next_to_top(stack<point> &S){
    point p = S.top();
    S.pop();
    point next = S.top();
    S.push(p);
    return next;
}

void convex_hull(point points[], int n){
    int ymin = points[0].y;
    int min = 0;

    for(int i=0; i<n; i++){
        if(points[i].y < ymin) {
            ymin = points[i].y;
            min = i;
        }
        if(points[i].y == ymin){
            if(points[i].x < points[min].x) {
                ymin = points[i].y;
                min = i;
            }
        }
    }
    
    swap(points[0], points[min]);
    pref = points[0];

    qsort(&points[1], n-1, sizeof(points[0]), Comparator);
    int a=1;

    for(int i=0; i<n; i++){
        while(i<n && orientation(pref, points[i], points[i+1]) ==0) i++;
        points[a] = points[i];
        a++;
    }

    stack <point>S;

    S.push(pref);
    S.push(points[1]);
    S.push(points[2]);

    for(int i=3; i<a; i++){
        if(orientation(next_to_top(S), S.top() , points[i]) != 2) S.pop();  
        S.push(points[i]);

    }

    cout<<S.size()<<endl;

    while(!S.empty()){
        point p = S.top();
        cout<<p.x<<","<<p.y<<endl;
        S.pop();
    }

}

int main(){
    int t;
    cin>>t;
    //cout<<"t="<<t<<endl;
    point points[t];
    for(int i=0; i<t; i++){
        cin>>points[i].x>>points[i].y;
    }
    
    convex_hull(points, t);
    return 0;
}
