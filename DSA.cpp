# include<iostream>
#include<string>
#include<iomanip>
using namespace std;
char arr[]={'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'g', 'G', 'H', 'h', 'i', 'I', 'j', 'J', 'K', 'k', 'l', 'L', 'm', 'M', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '.', ' '};
struct ADDRESS {
int Piyush_House_no;
char Piyush_Street_name[30];
char Piyush_City[30];
char Piyush_State[30];
char Piyush_Country[30];
int Piyush_Pin;
};
struct DATE{
int date;
int month;
int year;
};
struct citizen{
long long int Piyush_Adhaar_no;
char Piyush_Citizen_name[30];
char Piyush_Citizen_father_name[30];
char Piyush_Citizen_mother_name[30];
int Piyush_rank;
char Piyush_department_workplace[30];
struct DATE date;
struct ADDRESS address;
};
class node{
    private:
    struct citizen citizen_data;
    node* next;
    public:
    void create(node **);
    void input();
    bool date_chk(DATE* );
    bool chk(char *,char * );
    void display(node *);
    void search(node *);
    void del(node*);
    void disp(node* ptr);
    void update(node *);
};
void node:: disp(node* ptr){
cout<<"Aadhaar Number         : "<<ptr->citizen_data.Piyush_Adhaar_no<<endl;
cout<<"Citizen Name           : "<<ptr->citizen_data.Piyush_Citizen_name<<endl;
cout<<"Citizen Father's Name  : "<<ptr->citizen_data.Piyush_Citizen_father_name<<endl;
cout<<"Citizen Mother's Name  : "<<ptr->citizen_data.Piyush_Citizen_mother_name<<endl;
cout<<"Rank                   : "<<ptr->citizen_data.Piyush_rank<<endl;
cout<<"Dept. of Workplace     : "<<ptr->citizen_data.Piyush_department_workplace<<endl;
cout<<"Date of Joining        : "<<ptr->citizen_data.date.date<<"/"<<ptr->citizen_data.date.month<<"/"<<ptr->citizen_data.date.year<<endl;
cout<<"Country Name           : "<<ptr->citizen_data.address.Piyush_Country<<endl;
cout<<"State Name             : "<<ptr->citizen_data.address.Piyush_State<<endl;
cout<<"Pin                    : "<<ptr->citizen_data.address.Piyush_Pin<<endl;
cout<<"Street Name            : "<<ptr->citizen_data.address.Piyush_Street_name<<endl;
cout<<"House Number           : "<<ptr->citizen_data.address.Piyush_House_no<<endl;

}
void node::del(node* ptr) {
    if (ptr == nullptr) {
        cout << "No element in the list " << endl;
        return;
    }
    
    node* temp = nullptr;
    long long int Piyush_var;
    cout << "Enter Aadhaar no. to be deleted: ";
    cin >> Piyush_var;
    
    while (ptr != nullptr) {
        if (ptr->citizen_data.Piyush_Adhaar_no== Piyush_var) {
            if (temp != nullptr) {
                temp->next = ptr->next;
                delete ptr;
                cout << "Successfully Deleted" << endl;
                return;
            } else {
                
                node* tempNext = ptr->next;
                delete ptr;
                ptr = tempNext;
                cout << "Successfully Deleted" << endl;
                return;
            }
        }
        temp = ptr;
        ptr = ptr->next;
    }
    
    cout << "Record not found" << endl;
}

void node::search(node*ptr){
	if(ptr==NULL){
		cout<<"No element in the list";
		return;
}
	long long int Piyush_var;
	int f=0;
	cout<<"Enter Aadhaar no. to be searched :";
	cin>>Piyush_var;
	while(ptr!=NULL){
		if(ptr->citizen_data.Piyush_Adhaar_no==Piyush_var){
			f=1;
			break;	
		}
		ptr=ptr->next; 
}
if(f==1){
	cout<<"Record found\n";
	disp(ptr);
}
else{
	cout<<"No record found\n";
}	
}
void node :: display(node * ptr){
while(ptr!=NULL){
    disp(ptr);
    ptr=ptr->next;
}
}
bool node::chk(char *str,char * arr){
    int i=0,c;
while(str[i]!='\0'){
    c=0;
for (int j = 0;arr[j]!='\0' ; j++)
{
    if(str[i]==arr[j]){
        c=1;
        break;
    }
}
if(c==0){
    return 0;
}
i++;
}
return 1;
}
bool  node :: date_chk(DATE *DT){
if(DT->date >=1 && DT->date <=31 && DT->month>=1 && DT->month<=12 && DT->year>=1920 && DT->year <=2023){
    if(DT->year%100==0){
        if(DT->year%400==0){
            if(DT->date>29 && DT->month==2) return 0;
            else if(DT->date==31 &&(DT->month==4||DT->month==6||DT->month==9||DT->month==11))
			return 0;
            else return 1;
        }
        else{
            if(DT->date>28 && DT->month==2) return 0;
            else if(DT->date==31 &&(DT->month==4||DT->month==6||DT->month==9||DT->month==11))
			return 0;
            else return 1;
        }
    }
    else if(DT->year% 4==0){
            if(DT->date>29 && DT->month==2) return 0;
            else if(DT->date==31 &&(DT->month==4||DT->month==6||DT->month==9||DT->month==11))
			return 0;
            else return 1;
    }
    else{
            if(DT->date>28 && DT->month==2) return 0;
            else if(DT->date==31 &&(DT->month==4||DT->month==6||DT->month==9||DT->month==11))
			return 0;
            else return 1;
    }
    
}
else return 0;
}
void node :: input(){
    cout<<"Enter Adhaar number: ";
    cin>>citizen_data.Piyush_Adhaar_no;
    cin.ignore();
    cout<<"Enter Name of Citizen: ";
    cin.getline(citizen_data.Piyush_Citizen_name,30);
     while(!chk(citizen_data.Piyush_Citizen_name,arr)){
    cout<<"Invalid character\nRe-Enter Name of Citizen: ";
    cin.getline(citizen_data.Piyush_Citizen_name,30);    
    }
    cout<<"Enter Father's Name: ";
    cin.getline(citizen_data.Piyush_Citizen_father_name,30);
    while(!chk(citizen_data.Piyush_Citizen_father_name,arr)){
    cout<<"Invalid character\nRe-Enter father Name of Citizen: ";
    cin.getline(citizen_data.Piyush_Citizen_father_name,30);    
    }
    cout<<"Enter Mother's Name: ";
    cin.getline(citizen_data.Piyush_Citizen_mother_name,30);
    while(!chk(citizen_data.Piyush_Citizen_mother_name,arr)){
    cout<<"Invalid character\nRe-Enter Mother Name of Citizen: ";
    cin.getline(citizen_data.Piyush_Citizen_mother_name,30);    
    }
    cout<<"Enter Rank: ";
    cin>>citizen_data.Piyush_rank;
    cin.ignore();
    cout<<"Enter Department of Workplace: ";
    cin.getline(citizen_data.Piyush_department_workplace,30);
    while(!chk(citizen_data.Piyush_department_workplace,arr)){
    cout<<"Invalid character\nRe-Enter Department of Workplace: ";
    cin.getline(citizen_data.Piyush_department_workplace,30);    
    }
    cout<<"Enter date of joining: ";
    cin>>citizen_data.date.date>>citizen_data.date.month>>citizen_data.date.year;
    while(!date_chk(&citizen_data.date)){
    cout<<"Re-Enter date of joining: ";
    cin>>citizen_data.date.date>>citizen_data.date.month>>citizen_data.date.year;       
    }
    cin.ignore();
    cout<<"*Address Details are required to fill\n";
    cout<<"Enter House number : ";
    cin>>citizen_data.address.Piyush_House_no;
    cin.ignore();
    cout<<"Enter Street Name : ";
    cin.getline(citizen_data.address.Piyush_Street_name,30);
    while(!chk(citizen_data.address.Piyush_Street_name,arr)){
    cout<<"Invalid character\nRe-Enter Street Name of Citizen: ";
    cin.getline(citizen_data.address.Piyush_Street_name,30);    
    }
    cout<<"Enter City Name : ";   
    cin.getline(citizen_data.address.Piyush_City,30);
    while(!chk(citizen_data.address.Piyush_City,arr)){
    cout<<"Invalid character\nRe-Enter City Name : ";
    cin.getline(citizen_data.address.Piyush_City,30);    
    }
    cout<<"Enter State Name : ";
    cin.getline(citizen_data.address.Piyush_State,30);
    while(!chk(citizen_data.address.Piyush_State,arr)){
    cout<<"Invalid character\nRe-Enter State Name: ";
    cin.getline(citizen_data.address.Piyush_State,30);    
    }
    cout<<"Enter Country Name : ";
    cin.getline(citizen_data.address.Piyush_Country,30);
    while(!chk(citizen_data.address.Piyush_Country,arr)){
    cout<<"Invalid character\nRe-Enter Country Name of Citizen: ";
    cin.getline(citizen_data.address.Piyush_Country,30);    
    }
    cout<<"Enter Pin Number : ";
    cin>>citizen_data.address.Piyush_Pin;
    cin.ignore();
    
}
void node::create(node ** ptr){
    node*newnode=new node;
    if(newnode==NULL){
        cout<<"Memory error\n";
        return;
    }
   newnode->input();
   newnode->next=NULL;
    node*temp;
    if(*ptr==NULL){
       *ptr=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void node::update(node *ptr) {
    if (ptr == NULL) {
        cout << "No element in the list" << endl;
        return;
    }

    long long int Piyush_var;
    int f = 0;
    cout << "Enter Aadhaar no. to be updated: ";
    cin >> Piyush_var;

    while (ptr != NULL) {
        if (ptr->citizen_data.Piyush_Adhaar_no == Piyush_var) {
            f = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (f == 1) {
        cout << "Updating record:" << endl;
        ptr->input();
        cout << "Record updated successfully" << endl;
    } else {
        cout << "No record found for updating" << endl;
    }
}
int main(){
node*start=NULL;
node obj;
int ch;
while(1){

cout<<"Press  1 : To Insert  \n";
cout<<"Press  2 : To Delete  \n";
cout<<"Press  3 : To Search  \n";
cout<<"Press  4 : To Update  \n";
cout<<"Press  5 : To Display \n";
cout<<"Press  6 : To Exit   \n";
cout<<" Enter operaton to be performed :";
cin>>ch;
switch(ch){
    case 1:
        obj.create(&start);
        cout<<"SUCCESSFULLY ADDED\n";
    break;
    case 2:
    	obj.del(start);
    break;
    case 3:
    	obj.search(start);
    break;
    case 4:
    	obj.update(start);
    break;
    case 5:
        obj.display(start);
    break;
    case 6:
        exit(1);
    break; 
    default:
        cout<<"Invalid  Input : \n";
}
}
return 0;
}