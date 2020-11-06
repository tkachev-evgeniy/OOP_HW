#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;

void fillvectorrand (vector<int> &v, int min, int max) {
    for (int i = 0; i<v.size(); ++i) {
        v[i]=rand()%(max+1-min)+min;
    }
}

void printvector (const vector<int> &v) {
    for (int i = 0; i<v.size(); ++i) {
        cout << v[i] <<" ";
    }
    cout << endl;
}

int unique (vector<int> v) {
    if (v.empty()) return 0;
    int uniq = 1;
    sort(v.begin(),v.end());
    for (int i = 1; i<v.size(); ++i) {
        if (v[i]!=v[i-1]) uniq++;
    }
    return uniq;


}

int main()
{
    const int LENGTH = 10;
    vector<int> v(LENGTH);
    fillvectorrand(v,5,0);
    printvector(v);
    cout << unique(v) << " unique elements" << endl;


   // vector<int>::iterator it =v.begin
   // for (int i =0; i<LENGTH; ++i) {vector[i]=rand()%5} ;
    //}




}
