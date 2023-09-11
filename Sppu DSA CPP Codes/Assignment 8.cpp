#include<iostream>
 #include<iomanip>
using namespace std;
#define n 4


#define m 15
class node {
private:
int arr[3];

friend class dynPro;
 friend class obst;
 
};



class dynPro {
 private:
node *ptr[n + 1];

public:

int findC(int i, int j, int &k); 
friend class obst;
};


int dynPro::findC(int i, int j, int &K) { 
int k = i + 1;


int min = (ptr[i] + (k - 1))->arr[1] + (ptr[k] + j)->arr[1];
 K = k;
k++;

while (k <= j) {

if (min > ((ptr[i] + (k - 1))->arr[1] + (ptr[k] + j)->arr[1])) {



min = (ptr[i] + (k - 1))->arr[1] + (ptr[k] + j)->arr[1];
 K = k;
} 
k++;
 
}

return min;

}



class obst { 
private:
string str[n];

int p[n];	//probability of successful search

int q[n + 1];	//probability of unsuccessful search 
dynPro o;
string tree[(2 * n + 1)];

public:

obst(string S[], int P[], int Q[]) {
 for (int i = 0; i < n; i++) {
str[i] = S[i];

p[i] = P[i];

q[i] = Q[i];

}

q[(n)] = Q[(n)];

tree[0] = " ->";

for (int i = 1; i < (2 * n + 1); i++) { 
tree[i] = "none";
}
 
}

void input();

void findMinCost();

void construct(int i, int j, int po); 
void display();
};

void obst::findMinCost() { 
int i = 0;
int j = 0;
int x = n + 1; while (x > 0) {
o.ptr[i] = new node[(n + 1)]; 
i++;
x--;

}

i = 0;

j = 0;

int it = n + 1;
while (it > 0) {
while (j < (n + 1)) {

if (i == j) {

(o.ptr[i] + j)->arr[0] = this->q[i];
 
(o.ptr[i] + j)->arr[1] = 0;

(o.ptr[i] + j)->arr[2] = 0;
 i++;
j++;

} else {

(o.ptr[i] + j)->arr[0] = (o.ptr[i] + (j - 1))->arr[0]

+ this->p[(j - 1)] + this->q[j];

int K = i;

int c = o.findC(i, j, K);

c = c + (o.ptr[i] + j)->arr[0];

(o.ptr[i] + j)->arr[1] = c;

(o.ptr[i] + j)->arr[2] = K; 
i++;
j++;

}

}

it--;

i = 0;

j = (n + 1) - it;

}

it = n + 1; i = 0;
j = 0;
 
cout << "\n#Output: " << endl; 
while (it > 0)
while (j < (n + 1)) {


cout << "w" << (o.ptr[i] + j)->arr[0];

cout << "c" << (o.ptr[i] + j)->arr[1];

cout << "r" << (o.ptr[i] + j)->arr[2]; 
i++;
j++;

cout << "\t";

}

cout << "\n"; it--;
i = 0;

j = (n + 1) - it;

}




void obst::construct(int i, int j, int po) { 
if ((o.ptr[i] + j)->arr[2] == 0)
return;

else {
 
this->tree[po] = this->str[((o.ptr[i] + j)->arr[2] - 1)];

this->construct(i, ((o.ptr[i] + j)->arr[2] - 1), 2 * po);

this->construct(((o.ptr[i] + j)->arr[2]), j, (2 * po + 1));

}

}

void obst::display() {

cout << "\n#Required Optimal Binary Search tree is:" << endl;
 for (int i = 0; i < (2 * n + 1); i++) {
if (this->tree[i] == "none") 
continue;
cout << this->tree[i] << "\t";

}

cout<<"\n(Array Implementation)" << endl;

}


int main() {

int p[n] = { 3, 3, 1, 1 };

int q[(n + 1)] = { 2, 3, 1, 1, 1 };

string str[n] = { "do", "if", "int", "while" };
 cout << "#Key set is: " << endl;
for (int i = 0; i < n; i++) { cout << str[i] << "\t";
}
 
cout<<endl;

cout << "\n#Successful search probability is: " << endl; 
for (int i = 0; i < n; i++) {
cout << p[i] << "\t";

}

cout<<endl;

cout << "\n#Unsuccessful search probability is: " << endl;
 for (int i = 0; i < (n + 1); i++) {
cout << q[i] << "\t";

}

cout<<endl;

obst obj(str, p, q);
 obj.findMinCost(); 
 obj.construct(0, n, 1); 
 obj.display(); 
 cout<<"\n#END"<<endl;
}

