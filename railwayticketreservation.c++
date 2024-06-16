#include<bits/stdc++.h>
using namespace std;
//train Data base
vector<string>tno={"12345","2543","3535"},tname={"Delhi Express","Mumbai exppress","Hyderabad Express"},source={"Delhi","Mumbai","Hyderabad"},dest={"Kolkata","Chennai","Banglore"},adate={"23/06/24","26/06/24","03/07/24"},atime={"16:00","18:00","13:00"},
ddate={"22/06/24","25/06/24","02/07/24"},dtime={"08:00","06:00","11:00"},pnr{"757455","85744","45744"};
vector<int>seats={150,134,98};//train seats
vector<string>fare={"1200","2500","1500"};//train fares
vector<string>:: iterator it;//iterator for find the train no
int idx;
string t_no;
vector<string> pname,page,pgender;//passenger database
int noseats;//no of seats selected by passenger
//Passenger Operations
class Passenger{
public:
    Passenger(){
        cout<<"1.search \n 2.Booking \n";
        cout<<"\n ---------------------------------------\n";
        cout<<"Select operations:"<<endl;
        int choose;cin>>choose;
        if(choose ==1){//for searching train db
            search();
        }
        else if(choose==2){//for booking train in db
            cout<<"Enter the train no:\n";
            string num;cin>>num;
            Booking(num);
        }
    }
    //search function
    void search(){
         cout<<"enter the source and destination:";
                    string s,d;cin>>s>>d;
                    it=find(source.begin(),source.end(),s);int i;
                    if(it!=source.end()){
                        i=it-source.begin();
                        if(dest[i]==d){
                            cout<<"Yes\n";
                            cout<<"Train no:"<<tno[i]<<"\n";
                            cout<<"Train Name:"<<tname[i]<<"\n";
                            cout<<"Source:"<<source[i]<<"\n";
                            cout<<"destination:"<<dest[i]<<"\n";
                            cout<<"departure date and time:"<<ddate[i]<<"\t"<<dtime[i]<<"\n";
                            cout<<"Arrival date and Time:"<<atime[i]<<"\t"<<atime[i]<<"\n";
                            cout<<"seats available:"<<seats[i]<<"\n";
                            cout<<"Ticket Fare:"<<fare[i]<<"\n";
                }
                //No train for selected destination
                else{
                    cout<<"No train found\n";
                }
            }
            //No train for selected source
            else{
                cout<<"No train found\n";
            }
            return;
    }
    //function for booking trains
    void Booking(string num){
        it=find(tno.begin(),tno.end(),num);
        int i=it-tno.begin();
        cout<<"Available seats:"<<seats[i]<<"\t"<<"Fare :"<<fare[i]<<"\n";
        cout<<"enter the details:\n";
        cout<<"enter Name:";string pn;cin>>pn;pname.push_back(pn);
        cout<<"enter age:";string pa;cin>>pa;page.push_back(pa);
        cout<<"enter gender:";string pg;cin>>pg;pgender.push_back(pg);
        cout<<"enter the no of seats:";cin>>noseats;
        cout<<"Passenger Name:"<<pname[i]<<endl;
        cout<<"Passenger age:"<<page[i]<<endl;
        cout<<"Passenger gender:"<<pgender[i]<<endl;
        cout<<"\n 1.confirm\n 2.cancel\n";
        cout<<"enter conformation: ";
        int c;cin>>c;
        if(c==1){//asking for conformation
            seats[i]-=noseats;
            confirm(i);
        }
        else{//canceling the ticket
            page.pop_back();
            pname.pop_back();
            pgender.pop_back();
            cout<<"Canceled Successfully\n";
        }
    }
    //function for conformation of tickests
    void confirm(int i){
        cout<<"Your Tickets have been confirmed Successfully\n";
        cout<<"Your PNR number is:"<<pnr[i]<<"\n";
    }
};
class Train{
public:
    //adding a new train to the data base
    void enter(){
        cout<<"enter Train no:";
        string n;cin>>n;tno.push_back(n);
        cout<<"enter Train Name:";
        string t_name;cin>>t_name;tname.push_back(t_name);
        cout<<"enter Source:";
        string sor;cin>>sor;source.push_back(sor);
        cout<<"enter destination:";
        string de;cin>>de;dest.push_back(de);
        cout<<"enter departure date and time:";
        string dd;cin>>dd;ddate.push_back(dd);
        string dt;cin>>dt;dtime.push_back(dt);
        cout<<"enter Arrival date and Time:";
        string ad;cin>>ad;adate.push_back(ad);
        string ati;cin>>ati;atime.push_back(ati);
        cout<<"enter ticket fare:";
        string f;cin>>f;fare.push_back(f);
        seats.push_back(250);
        cout<<"You have successfully added"<<endl;
    }
    //function for updating the train data base
    void update(string t_no){
        it=find(tno.begin(),tno.end(),t_no);int i;
        if(it!=tno.end()){
            i=it-tno.begin();
            cout<<"Original data:\n";
            cout<<"\n ---------------------------------------\n";
            cout<<"Train no:"<<tno[i]<<"\n";
            cout<<"Train Name:"<<tname[i]<<"\n";
            cout<<"Source:"<<source[i]<<"\n";
            cout<<"destination:"<<dest[i]<<"\n";
            cout<<"departure date and time:"<<ddate[i]<<"\t"<<dtime[i]<<"\n";
            cout<<"Arrival date and Time:"<<atime[i]<<"\t"<<atime[i]<<"\n";
            cout<<"seats available:"<<seats[i]<<"\n";
            cout<<"Ticket Fare:"<<fare[i]<<"\n";
            cout<<"\n ---------------------------------------\n";
            cout<<"Enter new Train Name:";string nm;cin>>nm;tname[i]=nm;
            cout<<"enter new Source:";
            string sor;cin>>sor;source[i]=sor;
            cout<<"enter new destination:";
            string de;cin>>de;dest[i]=de;
            cout<<"enter new departure date and time:";
            string dd;cin>>dd;ddate[i]=dd;
            string dt;cin>>dt;dtime[i]=dt;
            cout<<"enter Arrival date and Time:";
            string ad;cin>>ad;adate[i]=ad;
            string ati;cin>>ati;atime[i]=ati;
            cout<<"Successfully Updated\n";
            cout<<"\n ---------------------------------------\n";
            cout<<"Train no:"<<tno[i]<<"\n";
            cout<<"Train Name:"<<tname[i]<<"\n";
            cout<<"Source:"<<source[i]<<"\n";
            cout<<"destination:"<<dest[i]<<"\n";
            cout<<"departure date and time:"<<ddate[i]<<"\t"<<dtime[i]<<"\n";
            cout<<"Arrival date and Time:"<<atime[i]<<"\t"<<atime[i]<<"\n";
            cout<<"seats available:"<<seats[i]<<"\n";
            cout<<"Ticket Fare:"<<fare[i]<<"\n";
            cout<<"\n ---------------------------------------\n";
        }
        else{
            cout<<"Train not found\n";
        }
    }
    //function for reading the train database
    int read(int idx){
        if(idx>tno.size()){
            return 0;
        }
        int i=idx-1;
        cout<<idx<<"\n";
        cout<<"Train no:"<<tno[i]<<"\n";
        cout<<"Train Name:"<<tname[i]<<"\n";
        cout<<"Source:"<<source[i]<<"\n";
        cout<<"destination:"<<dest[i]<<"\n";
        cout<<"departure date and time:"<<ddate[i]<<"\t"<<dtime[i]<<"\n";
        cout<<"Arrival date and Time:"<<atime[i]<<"\t"<<atime[i]<<"\n";
        cout<<"seats available:"<<seats[i]<<"\n";
        cout<<"Ticket Fare:"<<fare[i]<<"\n";
    }
    //function for deleting the train information from db
    void del(){
        for(int i=0;i<tno.size();i++){
            cout<<tno[i]<<"\t"<<tname[i]<<"\n";
        }
        cout<<"enter train no to delete:";string no;cin>>no;
        it=find(tno.begin(),tno.end(),no);int i;
        if(it!=tno.end()){
            i=it-tno.begin();
        tno.erase(tno.begin()+i);
        tname.erase(tname.begin()+i);
        source.erase(source.begin()+i);
        dest.erase(dest.begin()+i);
        ddate.erase(ddate.begin()+i);
        dtime.erase(dtime.begin()+i);
        adate.erase(adate.begin()+i);
        atime.erase(atime.begin()+i);
        seats.erase(seats.begin()+i);
        cout<<"Train Deleted successfully\n available trains\n";
        for(int i=0;i<tno.size();i++){
            cout<<tno[i]<<"\t"<<tname[i]<<"\n";
        }
        }
        //train with the specified id is not found
        else{
            cout<<"Train not found";
        }
    }
};
//Admin operations
class Admin{
public:
    //function for searching the user in the Admin db
    void user(map<string,string>&admin_det){
        cout<<"Enter your Name:";
        string name;cin>>name;//asking for username
        if(admin_det.find(name)!=admin_det.end()){
            cout<<"Enter Password:";//asking for password
            string p;cin>>p;
            if(p==admin_det[name]){
                while(1){
                    int opt;
                    cout<<"\n 1.Add train info \n 2.Update train info \n 3.Read Train info \n 4.Delete Train info\n 5.exit\n";
                    cout<<"\n ---------------------------------------\n";
                    cout<<"Enter the operation:";
                    cin>>opt;
                    switch(opt){
                        case 1:Train t1;//adding a new train in db
                        t1.enter();break;
                        case 2:cout<<"\n enter train no:";//updating the train information
                        cin>>t_no;
                        t1.update(t_no);break;
                        case 3:cout<<"\n enter train id:";//reading the train db
                            cin>>idx;
                            if(idx>tno.size()){
                                cout<<"No Train fund\n";break;
                            }
                            else{
                                t1.read(idx);break;
                            }
                        case 4:t1.del();//deleting a train from the db
                        default:exit(0);
                    }
                }
            }
            //incorrect password
            else{
                cout<<"Wrong password";
            }
        }
        //incorrect username
        else{
            cout<<"User not Found\n";
        }
    }
};
int main(){
    map<string,string>admin_det;
    //admin dataset with username and password
    admin_det["Nitish"]="9503";
    admin_det["Goutam"]="6103";
    admin_det["Sravya"]="1234";
    admin_det["Reethu"]="6546";
    cout<<"1.Admin \t 2.Passenger \n";//choosing the user type
    cout<<"\n ---------------------------------------\n";
    cout<<"select passenger or admin: ";
    int user_type;
    cin>>user_type;
    switch(user_type){
        case 1: Admin a;
                    a.user(admin_det);break;
        case 2:Passenger p;
    }
}
