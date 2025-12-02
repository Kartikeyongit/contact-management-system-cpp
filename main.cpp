#include<bits/stdc++.h>
using namespace std;

class Contact{
public:
string name;
string phone;
string email;
};

vector<Contact>v;

void save(){
ofstream out("contacts.txt");
for(auto &c:v) out<<c.name<<" "<<c.phone<<" "<<c.email<<"\n";
}

void load(){
v.clear();
ifstream in("contacts.txt");
Contact c;
while(in>>c.name>>c.phone>>c.email) v.push_back(c);
}

void addContact(){
string n,p,e;
cout<<"Enter name: ";cin>>n;
cout<<"Enter phone: ";cin>>p;
cout<<"Enter email: ";cin>>e;
v.push_back({n,p,e});
save();
cout<<"Contact added.\n";
}

void viewAll(){
if(v.empty()){cout<<"No contacts found.\n";return;}
cout<<"\nName\tPhone\tEmail\n";
for(auto &c:v) cout<<c.name<<"\t"<<c.phone<<"\t"<<c.email<<"\n";
}

void searchContact(){
cout<<"Search by name or phone: ";
string x;cin>>x;
bool f=0;
for(auto &c:v){
if(c.name==x||c.phone==x){
cout<<c.name<<" "<<c.phone<<" "<<c.email<<"\n";
f=1;
}
}
if(!f) cout<<"Not found.\n";
}

void updateContact(){
cout<<"Enter name or phone to update: ";
string x;cin>>x;
bool f=0;
for(auto &c:v){
if(c.name==x||c.phone==x){
cout<<"New name: ";cin>>c.name;
cout<<"New phone: ";cin>>c.phone;
cout<<"New email: ";cin>>c.email;
save();
cout<<"Contact updated.\n";
f=1;
}
}
if(!f) cout<<"Not found.\n";
}

void deleteContact(){
cout<<"Enter name or phone to delete: ";
string x;cin>>x;
vector<Contact>temp;
bool f=0;
for(auto &c:v){
if(c.name!=x&&c.phone!=x) temp.push_back(c);
else f=1;
}
v=temp;
save();
if(f) cout<<"Deleted.\n";
else cout<<"Not found.\n";
}

int main(){
load();
while(true){
cout<<"\n===== Contact Management System =====\n";
cout<<"1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Update Contact\n5. Delete Contact\n6. Exit\n";
cout<<"Enter choice: ";
int ch;cin>>ch;
if(ch==1) addContact();
else if(ch==2) viewAll();
else if(ch==3) searchContact();
else if(ch==4) updateContact();
else if(ch==5) deleteContact();
else break;
}
}
