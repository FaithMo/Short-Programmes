#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

const int NUM_COLUMNS1 = 6;
const int NUM_ROWS1 = 5;
const int NUM_COLUMNS = 7;
const int NUM_ROWS = 5;
string calender_array[NUM_ROWS1][NUM_COLUMNS];


string available_time[5][2] =  {"9.00","11.00","11.30","13.30",
                                "14.00","16.00","16.30","18.30",
                                "19.00","21.00"};

void time_schedule(){

    cout<<setw(15)<<"Start"<<setw(12)<<"Finish"<<endl;
    for(int a = 0; a < 5; a++)
    {
        cout<<a+1<<". ";
        for(int b = 0; b < 2; b++)
        {
            cout<<setw(12)<<available_time[a][b];
        }
        cout<<endl;
    }
};

int validate_time_option(int choose_timeP) {
    /*validate time option*/
    while(choose_timeP < 1 || choose_timeP > 5)
    {
        cout<<"Incorrect option! Please choose from 1-5."<<endl;
        cin>>choose_timeP;
    }

    return choose_timeP;
};

string calender[] = {"01","02","03","04","05","06",
                    "07","08","09","10","11","12",
                    "13","14","15","16","17","18",
                    "19","20","21","22","23","24",
                    "25","26","27","28","29","30",
                    "31","  ","  ","  ","  "};

void init()
{
    int index = 0;
    for(int i = 0; i < NUM_ROWS; i++)
    {
        for(int j = 0; j < NUM_COLUMNS; j++)
        {
            calender_array[i][j] = calender[index];
            index++;
        }
    }
};

/*function to display the calender*/
 void displayCalender() {
     cout.setf(ios::fixed);
     cout.precision(2);
     cout<<"Month calender"<<endl;
     cout<<endl;

     for(int i = 0; i < NUM_ROWS1; i++)
    {
        for(int j = 0; j < NUM_COLUMNS; j++)
        {
                cout<<"|"<<calender_array[i][j]<<"|";
        }
        cout<<endl;
    }
 }

/*function to validate day option*/
bool validate_day_number(string day_optionP)
{
    bool isAvailable = false;
    for(int i = 0; i < NUM_ROWS1 && isAvailable == false; i++)
    {
        for(int j= 0; j < NUM_COLUMNS; j++)
        {
            /*check if the day is available */
            if(calender_array[i][j] == day_optionP)
            {
                isAvailable = true;
                break;
            }
        }
    }
};

void update_day_number( string &choose_dayP)
{
    for(int i = 0; i < NUM_ROWS1; i++)
    {
        for(int j= 0; j < NUM_COLUMNS; j++)
        {
            /*check if the day number is available then mark it as booked */
            if(calender_array[i][j] == choose_dayP)
            calender_array[i][j] = "**"; /*mark the booked days with ** as soon as it gets booked*/
        }
    }
}
/*function to calculate te ticket price*/
float calculate_price(string open_timeP, float priceP)
{

    if(open_timeP == "19.00")
    {
        priceP = 350.00;
    }else{
        priceP = 300.00;
    }

    return priceP;
}
//function to display price 
void display_price(string full_nameP, string choose_dayP, string close_timeP,
                    string open_timeP, float price)
{
    
    float ticket_price;
    ticket_price = calculate_price(open_timeP, price);
    /*mark booked seats with a **/
    update_day_number(choose_dayP);
    
    cout<<"***********************************************************************************"<<endl;
    cout<<"Price confirmation for your appointment"<<endl;
    cout<<"***********************************************************************************"<<endl;
    cout<<"Name\t\t: " << full_nameP<<endl;
    cout<<"Day Chosen\t: " << choose_dayP<< endl;
    cout<<"Starting time\t: "<< open_timeP << endl;
    cout<<"Finishing time\t: "<<close_timeP<<endl;
    cout<<"Amount  \t: R"<<ticket_price<<endl;
    cout<<"************************************************************************************"<<endl;
    cout<<"Thank you for booking with us. For queries contact our receptionist:\n - Rosie: 0111 111 1111"<<endl;
    cout<<"************************************************************************************"<<endl;
}

int main ()
{
    init();

    string full_name;
    int choose_time;
    int validate_time;
    string open_time;
    string close_time;
    string choose_day;
    bool isDay_number;
    char input;
    float price;
    

    /*declare variables to count the number of bookings for each time */
    int option_01 = 0;
    int option_02 = 0;
    int option_03 = 0;
    int option_04 = 0;
    int option_05 = 0;

    do{
    cout<<"Welcome to Dr. Mypain's Booking system"<<endl;
    cout<<"\nEnter full name:"<<endl;
    getline(cin,full_name);

    cout<<"\nThe operating hours from Monday-Friday are:"<<endl;
    time_schedule();

    cout<<"Choose the time by entering the option number (1-5) from the displayed list:"<<endl;
    cin>>choose_time;

    validate_time = validate_time_option(choose_time);

    switch (validate_time)
    {
    case 1:
        if(option_01 == 0)
        {
            init();
        }
        open_time = "9.00";
        close_time = "11.00";
        option_01++;
        cout<<"\nThe availabe days for "<<open_time<<" are as follows:"<<endl;
        cout<<endl;
        displayCalender();
        if(option_01 >= 1)
        {
            cout<<"\nDays indicated with an asterisk mean that the time you chose is already booked."<<endl;
            cout<<"\nIf not indicated, you may continue."<<endl;
        }
        break;
    case 2:
        if(option_02 == 0)
        {
            init();
        }
        open_time = "11.30";
        close_time = "13.30";
        option_02++; /* update number of bookings*/
        cout<<"\nThe availabe days for "<<open_time<<" are as follows:"<<endl;
        cout<<endl;
        displayCalender();
        if(option_02 >= 1)
        {
            cout<<"\nDays indicated with an asterisk mean that the time you chose is already booked."<<endl;
            cout<<"\nIf not indicated, you may continue."<<endl;
        }
        break;

    case 3:
        if(option_03 == 0)
        {
            init();
        }
        open_time = "14.00";
        close_time = "16.00";
        option_03++; /* update number of bookings*/
        cout<<"\nThe availabe days for "<<open_time<<" are as follows:"<<endl;
        cout<<endl;
        displayCalender();
        if(option_03 >= 1)
        {
            cout<<"\nDays indicated with an asterisk mean that the time you chose is already booked."<<endl;
            cout<<"\nIf not indicated, you may continue."<<endl;
        }
        break;

    case 4:
        if(option_04 == 0)
        {
            init();
        }
        open_time = "16.30";
        close_time = "18.30";
        option_04++; /* update number of bookings*/
        cout<<"\nThe availabe days for "<<open_time<<" are as follows:"<<endl;
        cout<<endl;
        displayCalender();
        if(option_04 >= 1)
        {
            cout<<"\nDays indicated with an asterisk mean that the time you chose is already booked."<<endl;
            cout<<"\nIf not indicated, you may continue."<<endl;
        }
        break;

    case 5:
        if(option_05 == 0)
        {
            init();
        }
        open_time = "19.00";
        close_time = "21.00";
        option_05++; /* update number of bookings*/
        cout<<"\nThe availabe days for "<<open_time<<" are as follows:"<<endl;
        cout<<endl;
        displayCalender();
        if(option_05 >= 1)
        {
            cout<<"\nDays indicated with an asterisk mean that the time you chose is already booked."<<endl;
            cout<<"\nIf not indicated, you may continue."<<endl;
        }
        break;

    default:
        cout<<"\nThe are no spaces available for the day choosen!"<<endl;
        return 0;
        break;
    }

    cout<<"\nPlease key in a day number to choose a day(eg:01)"<<endl;
    cin>>choose_day;
    while(choose_day == "**")
        {
            cout<<"Please note all days marked with ** are already booked."<<endl;
            cout<<"Please choose a different day option: "<<endl;
            cin>>choose_day;
        }

    isDay_number = validate_day_number(choose_day);
    while(isDay_number != true)
        {
            cout<<"Sorry the day is taken. Please choose a day that is available"<<endl;
            cin>>choose_day;
            isDay_number = validate_day_number(choose_day);
        }
    cout<<endl;
    display_price(full_name, choose_day, close_time, open_time, price);
    cout<<"\nDo you wish to make another appointment:(Y/N)" << endl;
    cin >> input;
    cin.get();

    }while(input=='Y' || input=='y');/*condition for do while loop */



    return 0;
};