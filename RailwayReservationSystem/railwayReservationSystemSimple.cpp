#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


class Passenger{
    public:
    string name;
    int age;
    string gender;


    Passenger(){

    }
    Passenger(string name,string gender,int age){
        this->name=name;
        this->gender;
        this->age=age;
    }

};
class Ticket{
    public:
    int pnrNumber;
   
    vector<Passenger> passengers;

    int trainNumber;

    Ticket(){

    }
    Ticket(int pnrNumber,int trainNumber,vector<Passenger> passengers){
        this->pnrNumber=pnrNumber;
        this->trainNumber=trainNumber;
        this->passengers=passengers;
    }


};

class Train{
    public:

    int trainNumber;
    string trainName;
    string source;
    string destination;
    int totalSeats;

    int availableSeats;

    Train(){

    }
    Train(int trainNumber, string trainName, string source, string destination, int totalSeats){
        this->trainNumber=trainNumber;
        this->trainName=trainName;
        this->source= source;
        this->destination= destination;
        this->totalSeats= totalSeats;
        this->availableSeats= totalSeats;
    }
};

class  RailwayReservationSystem{
    vector<Train> trains;
    unordered_map<int,Ticket> bookings;
    int pnr;
    
    public:
    RailwayReservationSystem(){
        this->pnr=1246;
        //initialization of trains
        trains.push_back(Train(12440,"sgnr-ned express","sgnr","ned",440));
        trains.push_back(Train(12138,"Punjab Mail","fzr","csmt",440));
    }
    void displayTrainInfo(){

        cout<<"Availabe seats"<<endl;
        int n = trains.size();
        for(int i=0;i<n;i++){
            cout<<"train Number : "<<trains[i].trainNumber<<endl;
            cout<<"train Name : "<<trains[i].trainName<<endl;
            cout<<"train source : "<<trains[i].source<<endl;
            cout<<"train Destination : "<<trains[i].destination<<endl;
            if(trains[i].availableSeats==0){
                cout<<"No Seats availabe"<<endl;
            }
            else{
                cout<<"Availabe Seats : "<<trains[i].availableSeats<<endl;
            }cout<<endl;           
        }
        cout<<endl;
    }
    void bookTicket(){
        cout<<"Enter the Train Number"<<endl;
        int trainNumber;
        cin>>trainNumber;
        for(int i=0;i<2;i++ ){
            if(trains[i].trainNumber==trainNumber){
                if(trains[i].availableSeats > 0 ){
                    cout<<"Enter Total passengers"<<endl;
                    int num;
                    cin>>num;
                    vector<Passenger> passengers;
                    if(num > 6){
                        cout<<"Only six Passsenger allowed per ticket \n "<<endl;
                        return;
                    }
                    else{
                        string  name;
                        int age;
                        string gender;
                        int j=1;

                        while(trains[i].availableSeats>0 && num>0){
                            cout<<"Enter Name  for Passenger "<<j<<" : ";
                            cin>>name;
                            cout<<endl<<"Enter Age  for Passenger "<<j<<" : ";
                            cin>>age;
                            cout<<endl<<"Enter gender for Passenger "<<j<<" : ";
                            cin>>gender;
                            cout<<endl;
                            passengers.push_back(Passenger(name,gender,age));
                            trains[i].availableSeats--;
                            num--;
                            j++; 
                        }
                    }
                    if(num>0){
                        cout<<"No more tickets available"<<endl;
                    }
                    bookings[pnr]=Ticket(pnr,trainNumber,passengers);
                    cout<<"Booking succesfull \n This is your PNR Number : "<<pnr<<endl;
                    pnr++;
                    return;

                }
                else{
                    cout<<"No Seats available for your train "<<trainNumber<<endl;
                    return;

                }

            }


        }
        cout<<"No Trains with Such name"<<endl;


    }
    void showTicket(){
        int ticketID;
        cout << "Enter PNR to view status : ";
        cin >> ticketID;

        auto it = bookings.find(ticketID);
        if (it!=bookings.end())
        {
            cout<<"Your Ticket Status For PNR "<<ticketID<<endl;
            cout<<"Train Number : "<<it->second.trainNumber<<endl;

            for(auto passenger : it->second.passengers){
                    cout<<"Name : "<<passenger.name<<endl;

                    cout<<" Age : " <<passenger.age <<endl;;

                    cout<<" gender : "<<passenger.gender<<endl;
            }
        }
        else{
            cout<<"No such PNR found"<<endl;
        }
    }
    void cancelTicket(){
        int ticketID;
        cout << "Enter PNR to cancel ticket: ";
        cin >> ticketID;

        auto it = bookings.find(ticketID);
        if (it!=bookings.end())
        {
            int trainNumber = it->second.trainNumber;
            int numPassengers = it->second.passengers.size();

            for (auto& train : trains) {
                if (train.trainNumber == trainNumber) {
                    train.availableSeats += numPassengers;
                    break;
                }
            }
            bookings.erase(it);
            cout << "Ticket cancelled successfully.\n";
        }
        else{
            cout<<"No such PNR found"<<endl;
        }


    }

    void menu(){
        cout<<"WelCome to Railway reservation system"<<endl;
        int num;
        do {
            cout<< "Enter your choice from menu :"<<endl;
            cout<< "1: Show train info"<<endl;
            cout<< "2: Book train ticket"<<endl;
            cout<< "3: Show ticket info"<<endl;
            cout<< "4: Cancel ticket"<<endl;
            cout<< "5: Exit"<<endl;
 
            cin>>num;
            switch (num)
            {
                case 1:
                    displayTrainInfo();
                    break;
                case 2:
                    bookTicket();
                    break;
                case 3:
                    showTicket();
                    break;
                case 4:
                    cancelTicket();
                    break;
                case 5:
                    cout<<"Thanks for using Railway Reservation System "<<endl;
                    break;
                default:
                    cout<<"Enter a valid Choice"<<endl;
                    break;
                }
        }while(num != 5);

    }


};
int main(){
    RailwayReservationSystem system;
    system.menu();

    return 0;
}
