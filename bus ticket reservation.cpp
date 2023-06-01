#include <bits/stdc++.h>
using namespace std;

const int R = 10;
const int C = 4;
int Serialnum = 1;
int avl = 0;

string Bus_seat[R][C] =
{
    {"1.Empty",       "2.Empty",       "3.Empty",      "4.Empty"},
    {"5.Empty",       "6.Empty",       "7.Empty",      "8.Empty"},
    {"9.Empty",       "10.Empty",     "11.Empty",     "12.Empty"},
    {"13.Empty",     "14.Empty",     "15.Empty",     "16.Empty"},
    {"17.Empty",     "18.Empty",     "19.Empty",     "20.Empty"},
    {"21.Empty",     "22.Empty",     "23.Empty",     "24.Empty"},
    {"25.Empty",     "26.Empty",     "27.Empty",     "28.Empty"},
    {"29.Empty",     "30.Empty",     "31.Empty",     "32.Empty"},
    {"33.Empty",     "34.Empty",     "35.Empty",     "36.Empty"},
    {"37.Empty",     "38.Empty",     "39.Empty",     "40.Empty"}
};

int chkng[R][C] =
{
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1},
    {-1,       -1,       -1,      -1}
};

struct seat_det
{
    string Jdate;
    string Jn;
    string frm;
    string To;
    vector<int> seat_num;
};


seat_det HAJO[40];
void book();
void cancel();
void availability();
void details();

int main()
{
    int num;

    cout << "\n\n   -----------------------------\n";
    cout << "\t    BUS RESERVATION";
    cout << "\n   -----------------------------\n\n";
    cout << "   -----------------------------  MAIN MENU  -----------------------------\n\n";
    cout << "   [1] Book Seat\n\n";
    cout << "   [2] Cancel Your Ticket\n\n";
    cout << "   [3] View Available Seats\n\n";
    cout << "   [4] View Your Booking Details\n\n";
    cout << "   [5] Exit\n\n";
    cout << "   -----------------------------\n";
    cout << "   ENTER YOUR CHOICE: ";
    cin >> num;
    while(1)
    {
        switch (num)
        {
        case 1:
            book();
            break;
        case 2:
            cancel();
            break;
        case 3:
            availability();
            break;
        case 4:
            details();
            break;
        case 5:
            cout << "\n\n   -----------------------------\n";
            cout << "   THANK YOU FOR USING THIS BUS RESERVATION SYSTEM";
            cout << "\n   -----------------------------\n";
            cout << "   Made By:\n   MD. Sadat Alam Protik\n";
            exit(0);
            return 0;
        }
    }
}

void book()
{
    if(Serialnum == 40)
    {
        cout<<"Sorry! No Seat Available now!"<<endl;
        return;
    }

    cout << endl;
    int nos;
    string name, jfrom, desto, daite;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << Bus_seat[i][j] << "     ";
        }
        cout << "\n";
    }

    cout << endl;

    cout << "Enter Your Journey Date (DD-MM-YYYY): ";
    cin >> daite;
    HAJO[Serialnum].Jdate = daite;

    cout << endl;
    cout << "Enter Your name: ";
    cin >> name;
    HAJO[Serialnum].Jn = name;
    cout << endl;

    cout << "From Where you want to start your journey: ";
    cin >> jfrom;
    HAJO[Serialnum].frm = jfrom;
    cout << endl;

    cout << "Where you want to go: ";
    cin >> desto;
    HAJO[Serialnum].To = desto;
    cout << endl;



        cout << "Enter the number of seats you need: ";
        cin >> nos;

        cout << endl;

        vector<int> ara(nos);
        cout << "Enter seat number/s: ";
        for (int i = 0; i < nos; i++)
        {
            cin >> ara[i];
            if(chkng [(ara[i]-1)/4][((ara[i]-1)%4)] == 1)
            {
                cout<<"This seat Already booked! Enter empty one!"<<endl;
                i--;
                continue;
            }
            HAJO[Serialnum].seat_num.push_back(ara[i]);
            chkng [(ara[i]-1)/4][((ara[i]-1)%4)] = 1;
        }


        for(int i = 0; i<nos; i++)
        {
            int tempo = (HAJO[Serialnum].seat_num[i]-1);
            Bus_seat [tempo/4][(tempo%4)] = HAJO[Serialnum].Jn;
        }

        cout << endl;


    cout<<"Your total cost is "<<200*nos<<" Taka"<<endl;
    cout<<"Your Ticket serial number is "<<Serialnum<<endl;
    cout<<"Thank you"<<endl;



    Serialnum++;
    avl+=nos;

    cout << endl;


    cout << "Press 0 to return to the main menu: ";
    int choice;
    cin >> choice;

    if (choice == 0)
        main();

    cout << "Invalid choice. Please try again.\n\n";
}







void cancel()
{
    int snum;
    cout << "Enter your Ticket Serial Number: ";
    cin >> snum;

    if (snum >= Serialnum || snum < 1)
    {
        cout << "Invalid Serial Number." << endl;
        cancel();
    }
    else
    {
        vector<int> seatNumbers = HAJO[snum].seat_num;

        for (int i = 0; i < seatNumbers.size(); i++)
        {
            int seatIndex = seatNumbers[i] - 1;
            Bus_seat[seatIndex / C][seatIndex % C] = to_string(seatNumbers[i]) + ".Empty";
            chkng [seatIndex / C][seatIndex % C] = -1;
        }

        HAJO[snum].Jdate = "";
        HAJO[snum].Jn = "";
        HAJO[snum].frm = "";
        HAJO[snum].To = "";
        HAJO[snum].seat_num.clear();

        cout << "Ticket canceled successfully.\n";

        cout << "Press 0 to return to the main menu: ";
        int choice;
        cin >> choice;

        if (choice == 0)
            main();

        cout << "Invalid choice. Please try again.\n\n";
    }
}








void availability()
{
    while (true)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << Bus_seat[i][j] << "     ";
            }
            cout << "\n";
        }

        cout << "Press 0 to return to the main menu: ";
        int choice;
        cin >> choice;

        if (choice == 0)
            main();

        cout << "Invalid choice. Please try again.\n\n";
    }
}


void details()
{
    int tmp;
    cout << endl;
    cout<<"Enter your ticket serial number: ";
    cin>>tmp;
    cout<<"Your Journey Date: "<<HAJO[tmp].Jdate<<endl;
    cout<<"Your name: "<<HAJO[tmp].Jn<<endl;
    cout<<"From: "<<HAJO[tmp].frm<<endl;
    cout<<"To: "<<HAJO[tmp].To<<endl;
    cout<<"Seat Number: "<<endl;
    for(int i=0; i<HAJO[tmp].seat_num.size(); i++)
    {
        cout<<HAJO[tmp].seat_num[i]<<" ";
    }
    cout << endl;

    cout << "Press 0 to return to the main menu: ";
    int choice;
    cin >> choice;

    if (choice == 0)
        main();

    cout << "Invalid choice. Please try again.\n\n";
}
