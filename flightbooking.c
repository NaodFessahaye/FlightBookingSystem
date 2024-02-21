#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void mainMenu();

class Management{
    public:
        Management(){
            mainMenu();
        }

};

class Details{
    public:
        static string name, gender;
        int phonenum;
        int age;
        string add;
        static int cId;
        char arr[100];

        void information(){
            cout<<"enter id";
            cin>>cId;
            cout<<"enter name";
            cin>>name;
            cout<<"enter age";
            cin>>age;
            cout<<"enter address";
            cin>>add;
            cout<<"enter gender";
            cin>>gender;
        }
};

int Details::cId;
string Details::name;
string Details::gender;

class registeration{
    public:
        static int choice;
        int choice1;
        int back;
        static float charges;

        ;

        void flights(){
            string flightsN[]={"Dubai","Canada","USA","UK","JAPAN","GERMAN"};
            int len = sizeof(flightsN) / sizeof(flightsN[0]);
            for(int a=0;a<len;a++){
                cout<<(a+1)<<"flight to"<<flightsN[a]<<endl;
            
            }
            cout<<"press the number of the country og which u want to to book flights";
            cin>> choice;

            switch(choice){
                case 1:
                    {
                        cout<<"DUBAI: following are the flights"<<endl;
                        cout<<"1 dub -498, 2 dub - 500, 3 dub - 600"<<endl;
                        cout<<"selct which flight";
                        cin>>choice1;

                        if(choice1==1){
                            charges == 1000;
                            cout<<"flight 498 booked"<<endl;
                        }
                        else if(choice1 == 2){
                            charges = 2000;
                            cout<<"flight 500 booked"<<endl;
                        }
                        else if(choice1 ==3){
                            charges = 3000;
                            cout<<"flight 600 booked"<<endl;

                        }
                        else{
                            cout<<"invalid"<<endl;
                            flights();
                        }

                        cout<<"press any key to go back to main"<<endl;
                        cin>>back;
                        if(back==1){
                            mainMenu();
                         }
                        else{
                            mainMenu();
                        }
                    }
                case 2:
                    {
                        cout<<"CANADIAN aIRLIINES: following are the flights"<<endl;
                        cout<<"1 CAD -498, 2 CAD - 500, 3 CAD - 600"<<endl;
                        cout<<"selct which flight";
                        cin>>choice1;

                        if(choice1==1){
                            charges == 1000;
                            cout<<"flight 498 booked"<<endl;
                        }
                        else if(choice1 == 2){
                            charges = 2000;
                            cout<<"flight 500 booked"<<endl;
                        }
                        else if(choice1 ==3){
                            charges = 3000;
                            cout<<"flight 600 booked"<<endl;

                        }
                        else{
                            cout<<"invalid"<<endl;
                            flights();
                        }

                        cout<<"press any key to go back to main"<<endl;
                        cin>>back;
                        if(back==1){
                            mainMenu();
                         }
                        else{
                            mainMenu();
                        }
                    }
                case 3:
                    {
                        cout<<"USA aIRLIINES: following are the flights"<<endl;
                        cout<<"1 USA -498, 2 USA - 500, 3 USA - 600"<<endl;
                        cout<<"selct which flight";
                        cin>>choice1;

                        if(choice1==1){
                            charges == 1000;
                            cout<<"flight 498 booked"<<endl;
                        }
                        else if(choice1 == 2){
                            charges = 2000;
                            cout<<"flight 500 booked"<<endl;
                        }
                        else if(choice1 ==3){
                            charges = 3000;
                            cout<<"flight 600 booked"<<endl;

                        }
                        else{
                            cout<<"invalid"<<endl;
                            flights();
                        }

                        cout<<"press any key to go back to main"<<endl;
                        cin>>back;
                        if(back==1){
                            mainMenu();
                         }
                        else{
                            mainMenu();
                        }
                    }
                case 4:
                    {
                        cout<<"UK aIRLIINES: following are the flights"<<endl;
                        cout<<"1 UK -498, 2 UK - 500, 3 UK - 600"<<endl;
                        cout<<"selct which flight";
                        cin>>choice1;

                        if(choice1==1){
                            charges == 1000;
                            cout<<"flight 498 booked"<<endl;
                        }
                        else if(choice1 == 2){
                            charges = 2000;
                            cout<<"flight 500 booked"<<endl;
                        }
                        else if(choice1 ==3){
                            charges = 3000;
                            cout<<"flight 600 booked"<<endl;

                        }
                        else{
                            cout<<"invalid"<<endl;
                            flights();
                        }

                        cout<<"press any key to go back to main"<<endl;
                        cin>>back;
                        if(back==1){
                            mainMenu();
                         }
                        else{
                            mainMenu();
                        }
                    }
            case 5:
                    {
                        cout<<"Japan aIRLIINES: following are the flights"<<endl;
                        cout<<"1 jap -498, 2 jap - 500, 3 jap - 600"<<endl;
                        cout<<"selct which flight";
                        cin>>choice1;

                        if(choice1==1){
                            charges == 1000;
                            cout<<"flight 498 booked"<<endl;
                        }
                        else if(choice1 == 2){
                            charges = 2000;
                            cout<<"flight 500 booked"<<endl;
                        }
                        else if(choice1 ==3){
                            charges = 3000;
                            cout<<"flight 600 booked"<<endl;

                        }
                        else{
                            cout<<"invalid"<<endl;
                            flights();
                        }

                        cout<<"press any key to go back to main"<<endl;
                        cin>>back;
                        if(back==1){
                            mainMenu();
                         }
                        else{
                            mainMenu();
                        }
                    }
            case 6:
                    {
                        cout<<"German aIRLIINES: following are the flights"<<endl;
                        cout<<"1 Ger -498, 2 ger - 500, 3 ger - 600"<<endl;
                        cout<<"selct which flight";
                        cin>>choice1;

                        if(choice1==1){
                            charges == 1000;
                            cout<<"flight 498 booked"<<endl;
                        }
                        else if(choice1 == 2){
                            charges = 2000;
                            cout<<"flight 500 booked"<<endl;
                        }
                        else if(choice1 ==3){
                            charges = 3000;
                            cout<<"flight 600 booked"<<endl;

                        }
                        else{
                            cout<<"invalid"<<endl;
                            flights();
                        }

                        cout<<"press any key to go back to main"<<endl;
                        cin>>back;
                        if(back==1){
                            mainMenu();
                         }
                        else{
                            mainMenu();
                        }
                    }
            default:
                {
                   cout<<"invalid";
                   mainMenu(); 
                }
            }
            
        
        }

};

float registeration::charges;
int registeration::choice;

class ticket : public registeration, Details{
    public:
        void Bill(){
            string desitnation = "";
            ofstream outf("record.txt");
            {
                outf<<"customer Id"<<Details::cId<<endl;
                outf<<"customer Name"<<Details::name<<endl;
                outf<<"customer gender"<<Details::gender<<endl;
                
                if(registeration::choice ==1){
                    desitnation = "Dubai";
                }
                else if(registeration::choice ==2){
                    desitnation = "Canada";
                }
                else if(registeration::choice ==3){
                    desitnation = "USA";
                }
                else if(registeration::choice ==4){
                    desitnation = "UK";
                }
                else if(registeration::choice ==5){
                    desitnation = "Japan";
                }
                else if(registeration::choice ==1){
                    desitnation = "Germany";
                }
                outf<<"desitnation"<<desitnation<<endl;
                outf<<"desitnation"<<registeration::charges<<endl;

            }
            outf.close();
        }

        void display(){
            ifstream ifs("record.txt");
                if(!ifs){
                    cout<<"file error"<<endl;
                }
                while(!ifs.eof()){
                    ifs.getline(arr,100);
                    cout<<arr<<endl;
                }
            
        ifs.close();
        }

};

void mainMenu(){
    int lchoice;
    int schoice;
    int back;

    cout<<"YTZ Airlines\n"<<endl;
    cout<<"press1 to add customer, 2 to add flight reg, 3 for tickt an charges, 4 to Exit"<<endl;
    cout<<"enter choic:";
    cin>>lchoice;

    Details d;
    registeration r;
    ticket t;

    switch(lchoice){
        case 1:
            {
                cout<<"customer"<<endl;
                d.information();
                cout<<"press any key to go back to main menu";
                cin>>back;
                if(back ==1){
                    mainMenu();
                }
                else{
                    mainMenu();
                }
                break;
            }
        case 2:
            {
                cout<<"book flight"<<endl;
                r.flights();
                break;
            }
        case 3:{
        cout<<"get ticket"<<endl;
        t.Bill();
        cout<<"press 1 to display ticket";
        cin>>back;
        if(back==1){
            t.display();
            cout<<"press any key to go back to main menu";
            cin>>back;
            if(back==1){
                mainMenu();
            }
            else{
                mainMenu();
            }
        }
        else{
            mainMenu();
        }
        break;
    }
    case 4:{
        cout<<"exit"<<endl;
        break;
    }

    default:{
        cout<<"invalid"<<endl;
        mainMenu();
        break;
    }
}
}


int main(){
    Management Nobj;
    return 0;
}
