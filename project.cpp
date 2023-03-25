// libraries
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;
// Global variables and array
// string functions

const int userarrsize = 50;
string users[userarrsize];
string passwords[userarrsize];
// doctor array
string doctor[userarrsize];
string doctorpasswords[userarrsize];
string doctorsalary[userarrsize];
string doctorfee[userarrsize];
// patient array
string patient[userarrsize];
string patientpasswords[userarrsize];
string patientage[userarrsize];
string patientdisease[userarrsize];
string patientcontact[userarrsize];
string patientmedicine[userarrsize];
string patienttest[userarrsize];
string patienttestresult[userarrsize];
string reviews[userarrsize];
string appointmentday[userarrsize];
string appointmenttime[userarrsize];
string patientprescription[userarrsize];
string billpayment[userarrsize];
string recommendationdisease[userarrsize];
int diseaseindex[userarrsize];
string validationtest[userarrsize];
string validationappointment[userarrsize];
// int functions
int usercount = 0;
int doctorusercount = 0;
int patientusercount = 0;
int reviewcount = 0;
int testcount = 0;

// prototypes of function
// header functions
void hms();
void header();
void adminheader();
void doctorheader();
void patientheader();
// system cls function
void clearscreen();
string mainmenu();
// login functions
string adminlogin();
bool signup(string, string);
bool signin(string, string);
// admin functions
string adminmenu();
string patientmenu();
void loginInterface();
void admininterface();
void doctorinterface();
void patientinterface(int);
bool logindoctor(string, string);
bool doctoradd(string, string, string, string);
bool loginpatient(string, string, string, string, string, string);
int patientcheck(string, string);
bool reviewsaved(string);
bool addfee(string, string);
bool salarycheck(string, string);
bool doctordelete(string);
//  doctor function
string doctormenu();
bool patientappointment(string, string, string);
bool patientdeleteappointment(string);
bool patientdelete(string);
bool addprescription(string, string);
bool validationofsametest(string);
// patient function
int checkprescription(string);
int feechecker(string);
bool satisfactionofbill(string, string);
int addition(string, string);
void testchecker(string, string,string);
// validations function
bool validation(string);
bool validationofsameadmin(string);
bool validationofsamedoctor(string);
bool validationofsamepatient(string);
bool validationofalphabets(string);
bool validationofalphabetandnum(string);
bool validationofappointment(string, string);
bool validationOfPassword(string);
bool validationOfSameAppointment(string);
// store functions
void storeusersdata(string, string);
void storedoctorsdata(string, string, string, string);
void storepatientdata(string, string, string, string, string, string);
void storepatientreviews(string);
void storebillpayments(string, string);
void storeappointments(string, string, string);
void storeprescription(string, string);
void storetest(string, string, string);
void rewritedoctordata();
void rewritepatientdata();
void rewriteappointment();
// load functions
void loaduserdata();
void loaddoctordata();
void loadpatientdata();
void loadpatientreviews();
void loadbillpayments();
void loadappointments();
void loadprescription();
void loadtest();
string getfielddata(string, int);
// sorting functions
void sortingofarraydoctor();
void sortingofarraypatient();
// color function
void colorontext(int num);
// recommendation function
void printrecommendation();
string findrecommendation();
// gotoxy function
void gotoxy(int x, int y);

// main function
main()
{
    loaduserdata();
    loaddoctordata();
    loadpatientdata();
    loadpatientreviews();
    loadbillpayments();
    loadappointments();
    loadprescription();
    loadtest();
    system("cls");
    string menuoption = "0";
    while (menuoption != "4")
    {
        hms();
        header();
        menuoption = mainmenu();
        if (menuoption == "1")
        {
            loginInterface();
        }

        if (menuoption == "2")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name;
            string password;
            cout << "enter name: ";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            bool check = logindoctor(name, password);
            if (check == true)
            {
                clearscreen();
                doctorinterface();
            }
            else
            {
                colorontext(4);
                cout << "your credential is not correct" << endl;
                colorontext(7);
            }
        }

        if (menuoption == "3")
        {
            system("cls");
            hms();
            header();
            patientheader();
            string name;
            string password;
            cout << "enter patient name: ";
            cin >> name;
            cout << "enter password:";
            cin >> password;
            int check = patientcheck(name, password);
            if (check != (-1))
            {
                clearscreen();
                patientinterface(check);
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential" << endl;
                colorontext(7);
            }
        }
        clearscreen();
    }
}

// function starts from here
// function starts from here
// function starts from here
bool validationOfSameAppointment(string name)
{
    for(int i=0;patientusercount;i++)
    {
        if(patient[i]==name)
        {
            if(appointmentday[i]=="" && appointmenttime[i]=="")
            {
                return false;
            }
            else
            {
            return true;
            }
        }
    }
    return 0;
}
void loginInterface()
{
    string loginoption = "0";
    while (loginoption != "3")
    {
        system("cls");
        hms();
        string loginoption = adminlogin();
        if (loginoption == "2")
        {
            system("cls");
            bool satisfy;
            hms();
            header();
            adminheader();
            string name;
            string password;
            cout << "enter id name: ";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            bool check = validationofsameadmin(name);
            if (check == false)
            {

                satisfy = signup(name, password);
                if (satisfy == true)
                {
                    storeusersdata(name, password);
                    cout << "sucessfully signup" << endl;
                }
                else
                {
                    colorontext(4);
                    cout << "Users in the System have exceeded the Capacity" << endl;
                    colorontext(7);
                }
            }
            else
            {
                colorontext(4);
                cout << "Already exist" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        else if (loginoption == "1")
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name;
            string password;
            cout << "enter id : ";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            bool option = signin(name, password);
            if (option == true)
            {
                clearscreen();
                admininterface();
            }
            else if (option == false)
            {
                colorontext(4);
                cout << "you enter wrong credential." << endl;
                colorontext(7);
            }
            clearscreen();
        }
        else if (loginoption == "3")
        {
            break;
        }
    }
}
bool validationOfPassword(string password)
{
    int lengthPassword = password.length();
    if (lengthPassword == 8)
    {
        return true;
    }
    return false;
}

void rewriteappointment()
{
    fstream file;
    file.open("appointments.txt", ios::out);
    for (int i = 0; i < patientusercount; i++)
    {
        file << patient[i] << ",";
        file << appointmentday[i] << ",";
        file << appointmenttime[i] << endl;
    }
    file.close();
}

bool validationofsametest(string name)
{
    bool check = true;
    for (int i = 0; i < testcount; i++)
    {
        if (validationtest[i] == name)
        {
            check = false;
            break;
        }
    }
    return check;
}

void printrecommendation()
{
    colorontext(4);
    string disease = findrecommendation();
    gotoxy(88, 15);
    cout << "######################################################" << endl;
    gotoxy(88, 16);
    cout << "#    Recommendation:                                 #" << endl;
    gotoxy(88, 17);
    cout << "#\t" << disease << " is spreading in society                #" << endl;
    gotoxy(88, 18);
    cout << "#    so beaware of this                              #" << endl;
    gotoxy(88, 19);
    cout << "######################################################" << endl;
    colorontext(7);
}
string findrecommendation()
{
    for (int i = 0; i < patientusercount; i++)
    {
        int count = 0;
        recommendationdisease[i] = patientdisease[i];
        for (int j = 0; j < patientusercount; j++)
        {
            if (recommendationdisease[i] == patientdisease[j])
            {
                count++;
            }
        }
        diseaseindex[i] = count;
    }

    string find;
    for (int i = 0; i < patientusercount; i++)
    {
        int largest = diseaseindex[i];
        int index = i;
        for (int j = 0; j < patientusercount; j++)
        {
            if (largest < diseaseindex[j])
            {
                largest = diseaseindex[j];
                index = j;
            }
        }
        find = recommendationdisease[index];
    }
    return find;
}

void rewritepatientdata()
{
    fstream file;
    file.open("patientdata.txt", ios::out);
    for (int i = 0; i < patientusercount; i++)
    {
        if (i > 1)
        {
            file << endl;
            file << patient[i] << ",";
            file << patientpasswords[i] << ",";
            file << patientage[i] << ",";
            file << patientdisease[i] << ",";
            file << patientmedicine[i] << ",";
            file << patientcontact[i];
        }
        else
        {
            file << patient[i] << ",";
            file << patientpasswords[i] << ",";
            file << patientage[i] << ",";
            file << patientdisease[i] << ",";
            file << patientmedicine[i] << ",";
            file << patientcontact[i];
        }
    }
}

void rewritedoctordata()
{
    fstream file;
    file.open("doctordata.txt", ios ::out);
    for (int i = 0; i < doctorusercount; i++)
    {
        if (i > 0)
        {
            file << endl;
            file << doctor[i] << ",";
            file << doctorpasswords[i] << ",";
            file << doctorsalary[i] << ",";
            file << doctorfee[i];
        }
        else
        {

            file << doctor[i] << ",";
            file << doctorpasswords[i] << ",";
            file << doctorsalary[i] << ",";
            file << doctorfee[i];
        }
    }
    file.close();
}
string getfielddata(string line, int num)
{
    string item;
    int count = 1;

    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            count++;
        }
        else if (count == num)
        {
            item = item + line[i];
        }
    }
    return item;
}

bool validationofalphabetandnum(string name)
{
    bool check = false;
    for (int i = 0; i < name.length(); i++)
    {
        if ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || (name[i] >= 48 && name[i] <= 57))
        {
            check = true;
        }
        else
        {
            check = false;
            break;
        }
    }
    return check;
}

void storetest(string name, string test, string result)
{
    fstream file;
    file.open("testdata.txt", ios::app);
    file << name << ",";
    file << test << ",";
    file << result << endl;
    file.close();
}

void loadtest()
{
    fstream file;
    string line, name, test1, result;
    while (!file.eof())
    {
        getline(file, line);
        name = getfielddata(line, 1);
        test1 = getfielddata(line, 2);
        result = getfielddata(line, 3);
        for (int i = 0; i < patientusercount; i++)
        {
            if (name == patient[i])
            {
                patienttest[i] = test1;
                patienttestresult[i] = result;
                validationtest[testcount]=name;
                testcount++;
            }
        }
    }
    file.close();
}
void loadprescription()
{
    fstream file;
    bool waste;
    file.open("prescription.txt", ios::in);
    string line, name, prescription;
    while (!file.eof())
    {
        getline(file, line);
        name = getfielddata(line, 1);
        prescription = getfielddata(line, 2);
        waste = addprescription(name, prescription);
    }
    file.close();
}

void storeprescription(string name, string prescription)
{
    fstream file;
    file.open("prescription.txt", ios::app);
    file << name << ",";
    file << prescription << endl;
    file.close();
}

bool validationofappointment(string day, string time)
{
    bool check = false;
    bool check3 = false;
    if (day == "monday" || day == "tuesday" || day == "wednesday" || day == "thursday" || day == "friday" || day == "saturday" || day == "sunday")
    {
        check = true;
    }
    bool check2 = validationofalphabetandnum(time);
    if (check2 == true)
    {
        if (time.length() == 4)
        {
            if ((time[2] == 'a' || time[2] == 'p') && time[3] == 'm' && ((time[0] == 48 && (time[1] >= 48 && time[1] <= 57)) || (time[0] == 49 && (time[1] == 49 || time[1] == 50))))
            {

                check3 = true;
            }
        }
    }
    if (check == true && check3 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}
void storeappointments(string name, string day, string time)
{
    fstream file;
    file.open("appointments.txt", ios::app);
    file << name << ",";
    file << day << ",";
    file << time << endl;
    file.close();
}

void loadappointments()
{
    fstream file;
    string line;
    file.open("appointments.txt", ios::in);
    string name, day, time;
    bool waste;
    while (!file.eof())
    {
        getline(file, line);
        name = getfielddata(line, 1);
        day = getfielddata(line, 2);
        time = getfielddata(line, 3);
        waste = patientappointment(name, day, time);
    }
    file.close();
}
void sortingofarraydoctor()
{
    for (int i = 0; i < doctorusercount; i++)
    {
        string largest = doctorsalary[i];
        int index = i;
        for (int j = i; j < doctorusercount; j++)
        {
            if (largest < doctorsalary[j])
            {
                largest = doctorsalary[j];
                index = j;
            }
        }

        string temp = doctorsalary[i];
        doctorsalary[i] = doctorsalary[index];
        doctorsalary[index] = temp;

        string temp1 = doctor[i];
        doctor[i] = doctor[index];
        doctor[index] = temp1;

        string temp2 = doctorfee[i];
        doctorfee[i] = doctorfee[index];
        doctorfee[index] = temp2;

        string temp3 = doctorpasswords[i];
        doctorpasswords[i] = doctorpasswords[index];
        doctorpasswords[index] = temp3;
    }
}
void sortingofarraypatient()
{
    for (int i = 0; i < patientusercount; i++)
    {
        string smallest = patientage[i];
        int index = i;
        for (int j = i; j < patientusercount; j++)
        {
            if (smallest > patientage[j])
            {
                smallest = patientage[j];
                index = j;
            }
        }

        string temp = patientage[i];
        patientage[i] = patientage[index];
        patientage[index] = temp;

        string temp1 = patient[i];
        patient[i] = patient[index];
        patient[index] = temp1;

        string temp2 = patientpasswords[i];
        patientpasswords[i] = patientpasswords[index];
        patientpasswords[index] = temp2;

        string temp3 = patientdisease[i];
        patientdisease[i] = patientdisease[index];
        patientdisease[index] = temp3;

        string temp4 = patientmedicine[i];
        patientmedicine[i] = patientmedicine[index];
        patientmedicine[index] = temp4;

        string temp5 = patientcontact[i];
        patientcontact[i] = patientcontact[index];
        patientcontact[index] = temp5;
    }
}

void storebillpayments(string name, string total1)
{
    fstream file;
    file.open("bill payment.txt", ios::app);
    file << name << ",";
    file << total1 << endl;
    file.close();
}
void loadbillpayments()
{

    fstream file;
    string line, name, billpayments;
    file.open("bill payment.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line);
        name = getfielddata(line, 1);
        billpayments = getfielddata(line, 2);
        for (int i = 0; i < patientusercount; i++)
        {
            if (name == patient[i])
            {
                billpayment[i] = billpayments;
            }
        }
    }
    file.close();
}

bool validationofalphabets(string name)
{
    bool check = false;
    for (int i = 0; i < name.length(); i++)
    {
        if ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122))
        {
            check = true;
        }
        else
        {
            check = false;
            break;
        }
    }
    return check;
}

void storepatientreviews(string review)
{
    fstream file;
    file.open("patientreviews.txt", ios::app);
    if (reviewcount > 1)
    {
        file << endl;
        file << review;
    }
    else
    {
        file << review;
    }
    file.close();
}

void loadpatientreviews()
{
    fstream file;
    string line;
    file.open("patientreviews.txt", ios::in);
    while (!file.eof())
    {
        file >> reviews[reviewcount];
        reviewcount++;
    }
    file.close();
}

void loadpatientdata()
{
    fstream file;
    string line;
    file.open("patientdata.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        patient[patientusercount] = getfielddata(line, 1);
        patientpasswords[patientusercount] = getfielddata(line, 2);
        patientage[patientusercount] = getfielddata(line, 3);
        patientdisease[patientusercount] = getfielddata(line, 4);
        patientmedicine[patientusercount] = getfielddata(line, 5);
        patientcontact[patientusercount] = getfielddata(line, 6);
        patientusercount++;
    }
    file.close();
}

void loaddoctordata()
{
    string line;
    fstream file;
    file.open("doctordata.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        doctor[doctorusercount] = getfielddata(line, 1);
        doctorpasswords[doctorusercount] = getfielddata(line, 2);
        doctorsalary[doctorusercount] = getfielddata(line, 3);
        doctorfee[doctorusercount] = getfielddata(line, 4);
        doctorusercount++;
    }
    file.close();
}
void loaduserdata()
{
    string line;
    fstream file;
    file.open("admindata.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        users[usercount] = getfielddata(line, 1);
        passwords[usercount] = getfielddata(line, 2);
        usercount++;
    }
    file.close();
}

void storepatientdata(string name, string password, string age, string disease, string medicine, string contact)
{
    fstream file;
    file.open("patientdata.txt", ios::app);
    if (patientusercount > 1)
    {
        file << endl;
        file << name << ",";
        file << password << ",";
        file << age << ",";
        file << disease << ",";
        file << medicine << ",";
        file << contact;
    }
    else
    {
        file << name << ",";
        file << password << ",";
        file << age << ",";
        file << disease << ",";
        file << medicine << ",";
        file << contact;
    }
    file.close();
}

bool validationofsamepatient(string name)
{
    bool check = false;
    for (int i = 0; i < patientusercount; i++)
    {
        if (name == patient[i])
        {
            check = true;
            break;
        }
    }
    return check;
}
void storedoctorsdata(string name, string password, string salary, string fee)
{
    fstream file;
    file.open("doctordata.txt", ios::app);
    if (doctorusercount > 1)
    {
        file << endl;
        file << name << ',';
        file << password << ',';
        file << salary << ',';
        file << fee;
    }
    else
    {

        file << name << ',';
        file << password << ',';
        file << salary << ',';
        file << fee;
    }
    file.close();
}
bool validationofsamedoctor(string name)
{
    bool check = false;
    for (int i = 0; i < doctorusercount; i++)
    {
        if (name == doctor[i])
        {
            check = true;
            break;
        }
    }
    return check;
}

void storeusersdata(string name, string password)
{
    fstream file;
    file.open("admindata.txt", ios::app);
    file << name << ",";
    file << password << endl;
    file.close();
}

bool validationofsameadmin(string name)
{
    bool check = false;
    for (int i = 0; i < usercount; i++)
    {
        if (name == users[i])
        {
            check = true;
            break;
        }
    }
    return check;
}

bool validation(string check1)
{
    bool check2 = false;
    int i = 0;
    while (check1[i] != '\0')
    {
        if (check1[i] == '0' || check1[i] == '1' || check1[i] == '2' || check1[i] == '3' || check1[i] == '4' || check1[i] == '5' || check1[i] == '6' || check1[i] == '7' || check1[i] == '8' || check1[i] == '9')
        {
            check2 = true;
        }
        else
        {
            check2 = false;
            break;
        }
        i++;
    }
    return check2;
}

bool loginpatient(string name, string password, string age, string disease, string medicine, string contact)
{
    bool check1 = validation(age);
    bool check2 = validation(contact);
    bool check3 = validationofalphabets(name);
    bool check4 = validationofalphabetandnum(disease);
    bool check5 = validationofalphabetandnum(medicine);
    bool check6 = false;
    if (contact.length() == 11)
    {
        check6 = true;
    }

    if (check1 == true && check2 == true && check3 == true && check4 == true && check5 == true && check6 == true)
    {
        if (patientusercount < userarrsize)
        {
            patient[patientusercount] = name;
            patientpasswords[patientusercount] = password;
            patientage[patientusercount] = age;
            patientdisease[patientusercount] = disease;
            patientmedicine[patientusercount] = medicine;
            patientcontact[patientusercount] = contact;
            patientusercount++;
            return true;
        }

        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return 0;
}

bool reviewsaved(string review)
{
    if (reviewcount < userarrsize)
    {
        reviews[reviewcount] = review;
        reviewcount++;
        return true;
    }
    return false;
}
bool salarycheck(string name, string salary)
{
    bool check1 = validation(salary);
    if (check1 == true)
    {
        for (int index = 0; index < doctorusercount; index++)
        {
            if ((doctor[index] == name))
            {
                doctorsalary[index] = salary;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return 0;
}

void doctorinterface()
{
    string doctoroption = "0";

    while (doctoroption != "10")
    {
        hms();
        header();
        doctorheader();

        doctoroption = doctormenu();
        if (doctoroption == "1")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            printrecommendation();
            string name, age, disease, medicine, contact;
            string password;
            cout << "enter patient  name: ";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            cout << "enter patient age:";
            cin >> age;
            cout << "enter disease: ";
            cin >> disease;
            cout << "enter medicine: ";
            cin >> medicine;
            cout << "enter contact (without spaces): ";
            cin.ignore();
            getline(cin, contact);
            bool validationcheck = validationofsamepatient(name);
            if (validationcheck == false)
            {
                bool check = loginpatient(name, password, age, disease, medicine, contact);
                bool check1 = validationOfPassword(password);
                if (check == true && check1 == true)
                {
                    storepatientdata(name, password, age, disease, medicine, contact);
                    cout << "sucessfully login!" << endl;
                }
                else
                {
                    colorontext(4);
                    cout << "you enter wrong credential" << endl;
                    colorontext(7);
                }
            }
            else
            {
                colorontext(4);
                cout << "Already exists" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        if (doctoroption == "5")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name, day, time;
            cout << "enter name of patient: ";
            cin >> name;
            cout << "enter day of appointment: ";
            cin >> day;
            cout << "time  in hours withoutspaces(am/pm): ";
            cin >> time;
            bool checkvalidation = validationofappointment(day, time);
            checkvalidation=true;
            if (checkvalidation == true)
            {
                bool check = patientappointment(name, day, time);
                if (check == true)
                {
                    storeappointments(name, day, time);
                    cout << "appointment added" << endl;
                }
                else
                {
                    colorontext(4);
                    cout << "you enter wrong credential" << endl;
                    colorontext(7);
                }
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong details" << endl;
                colorontext(7);
            }
            clearscreen();
        }
        if (doctoroption == "6")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name, prescription;
            cout << "enter name: ";
            cin >> name;
            cout << "enter prescription: ";
            cin.ignore();
            getline(cin, prescription);
            bool check = addprescription(name, prescription);
            if (check == true)
            {
                storeprescription(name, prescription);
                cout << "added prescription!" << endl;
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        if (doctoroption == "4")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name;
            cout << "enter patient name: ";
            cin >> name;
            bool check1=validationOfSameAppointment(name);
            bool check2 = patientdeleteappointment(name);
            if (check2 == true && check1==true)
            {
                rewriteappointment();
                cout << "appointment cancel sucessfully!" << endl;
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential!" << endl;
                colorontext(7);
            }
            clearscreen();
        }
        if (doctoroption == "2")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name, password;
            cout << "enter discharge patient name: ";
            cin >> name;
            bool check = patientdelete(name);
            if (check == true)
            {
                rewritepatientdata();
                cout << "patient discharge!" << endl;
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        if (doctoroption == "3")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            cout << "sorting on age:" << endl;
            sortingofarraypatient();
            cout << "patient"
                 << "\t\t"
                 << "appointmentday"
                 << "\t\t"
                 << "appointmenttime" << endl;
            for (int index = 0; index < patientusercount; index++)
            {
                cout << patient[index] << "\t\t" << appointmentday[index] << "\t\t\t" << appointmenttime[index] << endl;
            }
            clearscreen();
        }

        if (doctoroption == "9")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            cout << "patients"
                 << "\t"
                 << "passwords"
                 << "\t"
                 << "age"
                 << "\t"
                 << "diseases"
                 << "\t"
                 << "medicine"
                 << "\t"
                 << "contacts" << endl;
            void sortingofarraypatient();
            for (int index = 0; index < patientusercount; index++)
            {
                cout << patient[index] << "\t\t" << patientpasswords[index] << "\t\t" << patientage[index] << "\t" << patientdisease[index] << "\t\t" << patientmedicine[index] << "\t\t" << patientcontact[index] << endl;
            }
            clearscreen();
        }
        if (doctoroption == "8")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            string name, test,result;
            cout << "enter patient name: ";
            cin >> name;
            cout << "enter test name: ";
            cin >> test;
            cout<< "Enter result: ";
            cin >>result;

            testchecker(name, test,result);

            clearscreen();
        }

        if (doctoroption == "7")
        {
            system("cls");
            hms();
            header();
            doctorheader();
            cout << "patients"
                 << "\t"
                 << "payments" << endl;
            for (int index = 0; index < patientusercount; index++)
            {
                cout << patient[index] << "\t\t" << billpayment[index] << endl;
            }

            clearscreen();
        }
    }
}

void testchecker(string name, string test,string result)
{
    bool check = validationofalphabets(name);
    bool check1 = validationofalphabetandnum(test);
    bool check3 = validationofsametest(name);
    bool check4=false;
    if(result=="positive"|| result=="negative")
    {
        check4=true;
    }
    if (check == true && check1 == true && check3 == false && check4==true)
    {
        int j = 0;
        bool recordnew = false;
        for (int index = 0; index < patientusercount; index++)
        {
            if (patient[index] == name)
            {
                patienttest[index] = test;
                validationtest[testcount] = name;
                patienttestresult[index]=result;
                storetest(name,test,result);
                testcount++;
                recordnew = true;
                j = index;
                break;
            }
        }
        if(recordnew==false)
        {
         colorontext(4);
        cout << "please!enter correctly " << endl;
        colorontext(7); 
        }
        else
        {
            cout<<"added sucessfully! "<<endl;
        }
    }
    else
    {
        colorontext(4);
        cout << "please!enter correctly " << endl;
        colorontext(7);
    }
}

bool addprescription(string name, string prescription)
{
    for (int index = 0; index < patientusercount; index++)
    {
        if (patient[index] == name)
        {
            patientprescription[index] = prescription;
            return true;
        }
    }
    return false;
}

bool patientdelete(string name)
{
    bool recordnew = false;
    int j;
    for (int index = 0; index < patientusercount; index++)
    {
        if ((patient[index] == name))
        {
            j = index;
            recordnew = true;
            break;
        }
    }

    if (recordnew == true)
    {
        for (int i = j; i < patientusercount - 1; i++)
        {
            patient[i] = patient[i + 1];
            patientpasswords[i] = patientpasswords[i + 1];
            patientage[i] = patientage[i + 1];
            appointmentday[i] = appointmentday[i + 1];
            appointmenttime[i] = appointmenttime[i + 1];
            patientcontact[i] = patientcontact[i + 1];
        }
        patientusercount--;
    }
    return recordnew;
}
bool patientdeleteappointment(string name)
{
    bool recordnew = false;
    int j = 0;
    for (int index = 0; index < patientusercount; index++)
    {
        if (patient[index] == name)
        {
            j = index;
            recordnew = true;
            break;
        }
    }

    if (recordnew == true)
    {

        appointmentday[j] = "";
        appointmenttime[j] = "";
    }
    return recordnew;
}
bool patientappointment(string name, string day, string time)
{

    for (int index = 0; index < patientusercount; index++)
    {
        if (name == patient[index])
        {
            appointmentday[index] = day;
            appointmenttime[index] = time;
            return true;
        }
    }

    return false;
}
bool doctordelete(string name)
{
    bool recordnew = false;
    int j = 0;
    for (int index = 0; index < doctorusercount; index++)
    {
        if ((doctor[index] == name))
        {
            j = index;
            recordnew = true;
            break;
        }
    }

    if (recordnew == true)
    {
        for (int i = j; i < doctorusercount - 1; i++)
        {
            doctor[i] = doctor[i + 1];
            doctorpasswords[i] = doctorpasswords[i + 1];
            doctorsalary[i] = doctorsalary[i + 1];
            doctorfee[i] = doctorfee[i + 1];
        }
        doctorusercount--;
    }

    return recordnew;
}

int patientcheck(string name, string password)
{
    int count = -1;
    for (int index = 0; index < patientusercount; index++)
    {
        if ((patient[index] == name) && (patientpasswords[index] == password))
        {
            count = index;
        }
    }
    return count;
}

void patientinterface(int check)
{
    int count = check;
    string patientoption = "0";
    while (patientoption != "7")
    {
        system("cls");
        hms();
        header();
        patientheader();
        patientoption = patientmenu();
        if (patientoption == "5")
        {
            system("cls");
            hms();
            header();
            patientheader();
            string review;
            cout << "enter your review: ";
            cin.ignore();
            getline(cin, review);
            bool check = reviewsaved(review);
            if (check == true)
            {
                storepatientreviews(review);
                cout << "your review saved sucessfully." << endl;
            }
            else
            {
                colorontext(4);
                cout << "sorry!your review does not saved in record" << endl;
                colorontext(7);
            }
            clearscreen();
        }
        if (patientoption == "1")
        {
            system("cls");
            hms();
            header();
            patientheader();
            cout << "your prescription: " << endl;
            cout << patientprescription[count] << endl;

            clearscreen();
        }
        if (patientoption == "2")
        {
            system("cls");
            hms();
            header();
            patientheader();
            string fee, test;

            cout << "enter doctor fee: ";
            cin >> fee;
            cout << "enter test fee: ";
            cin >> test;
            bool check = satisfactionofbill(fee, test);
            if (check == true)
            {

                int total = addition(fee, test);
                string total1 = to_string(total);
                cout << "total bill you paid: " << total1 << endl;
                billpayment[count] = total1;
                storebillpayments(patient[count], total1);
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential" << endl;
                colorontext(7);
            }

            clearscreen();
        }
        if (patientoption == "3")
        {
            system("cls");
            hms();
            header();
            patientheader();
            string name;
            cout << "your doctor name: ";
            cin >> name;
            int check = feechecker(name);
            if (check != (-1))
            {
                cout << "your doctor fee: " << endl;
                cout << doctorfee[check] << endl;
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        if (patientoption == "4")
        {
            system("cls");
            hms();
            header();
            patientheader();
            cout << "your appointment:" << endl;
            cout << appointmentday[count] << endl;
            cout << appointmenttime[count] << endl;
            clearscreen();
        }

        if (patientoption == "6")
        {
            system("cls");
            hms();
            header();
            patientheader();
            cout << "your test name: ";
            cout << patienttest[count] << endl;
            cout << "your test result :";
            cout << patienttestresult[count] << endl;

            clearscreen();
        }
    }
}

bool satisfactionofbill(string fee, string test)
{
    bool check = validation(fee);
    bool check1 = validation(test);
    if (check == true && check1 == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}

int addition(string fee, string test)
{

    int first = stoi(fee);
    int second = stoi(test);
    int total = first + second;
    return total;
}
int feechecker(string name)
{
    int count = -1;
    for (int index = 0; index < doctorusercount; index++)
    {
        if (doctor[index] == name)
        {
            count = index;
            break;
        }
    }
    return count;
}
bool logindoctor(string name, string password)
{
    for (int index = 0; index < doctorusercount; index++)
    {
        if ((doctor[index] == name) && (doctorpasswords[index] == password))
        {
            return true;
        }
    }
    return false;
}
bool doctoradd(string name, string password, string salary, string fee)
{
    bool check1 = validation(fee);
    bool check3 = validation(salary);
    bool check2 = validationofalphabets(name);
    bool check4 = validationOfPassword(password);

    if (check1 == true && check3 == true && check2 == true && check4 == true)
    {

        if (doctorusercount < userarrsize)
        {
            doctor[doctorusercount] = name;
            doctorpasswords[doctorusercount] = password;
            doctorsalary[doctorusercount] = salary;
            doctorfee[doctorusercount] = fee;
            doctorusercount++;
            return true;
        }
        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
    return 0;
}

bool signup(string name, string password)
{
    bool check1 = validationofalphabets(name);
    bool check2 = validationOfPassword(password);

    if (check1 == true && check2 == true)
    {
        if (usercount < userarrsize)
        {
            users[usercount] = name;
            passwords[usercount] = password;
            usercount++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return 0;
}

bool signin(string name, string password)
{
    for (int index = 0; index < usercount; index++)
    {
        if ((users[index] == name) && (passwords[index] == password))
        {
            return true;
        }
    }
    return false;
}

bool addfee(string name, string fee)
{
    bool check1 = validation(fee);
    if (check1 == true)
    {
        for (int index = 0; index < doctorusercount; index++)
        {
            if (doctor[index] == name)
            {
                doctorfee[index] = fee;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return 0;
}
void admininterface()
{
    string adminoption = "0";
    while (adminoption != "9")
    {
        hms();
        header();
        adminheader();
        adminoption = adminmenu();
        if (adminoption == "3")
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name;
            string password;
            string salary;
            string fee;

            cout << "enter doctor id:";
            cin >> name;
            cout << "enter password: ";
            cin >> password;
            cout << "enter salary: ";
            cin >> salary;
            cout << "enter fee: ";
            cin >> fee;
            bool check = validationofsamedoctor(name);

            if (check == false)
            {
                bool option = doctoradd(name, password, salary, fee);
                if (option == true)
                {
                    storedoctorsdata(name, password, salary, fee);
                    cout << "sucessfully added" << endl;
                }
                else
                {
                    colorontext(4);
                    cout << "you exceed the limit! So try again" << endl;
                    colorontext(7);
                }
            }
            else
            {
                colorontext(4);
                cout << "Already exist." << endl;
                colorontext(7);
            }

            clearscreen();
        }
        if (adminoption == "5")
        {
            system("cls");
            hms();
            header();
            adminheader();
            cout << "Reviews by patient: " << endl;
            for (int index = 0; index < reviewcount; index++)
            {
                cout << index + 1 << "." << reviews[index] << endl;
            }
            clearscreen();
        }

        if (adminoption == "1")
        {
            system("cls");
            hms();
            header();
            adminheader();
            sortingofarraydoctor();
            cout << " Decending sorting salary: " << endl;
            cout << "\t"
                 << "doctors"
                 << "\t\t"
                 << "passwords"
                 << "\t\t"
                 << "salary"
                 << "\t\t"
                 << "fee" << endl;
            for (int index = 0; index < doctorusercount; index++)
            {
                cout << index + 1 << "."
                     << "\t" << doctor[index] << "\t"
                     << "\t" << doctorpasswords[index] << "\t\t" << doctorsalary[index] << "\t" << doctorfee[index] << endl;
            }

            clearscreen();
        }

        if (adminoption == "2")
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name, fee;
            cout << "enter doctor name: ";
            cin >> name;
            cout << "enter fee: ";
            cin >> fee;
            bool check = addfee(name, fee);
            if (check == true)
            {
                rewritedoctordata();
                cout << "Doctor  fee update sucessfully" << endl;
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        if (adminoption == "8")
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name, password, salary;
            cout << "enter doctor name: ";
            cin >> name;
            cout << "enter doctor salary: ";
            cin >> salary;
            bool check = salarycheck(name, salary);
            if (check == true)
            {
                rewritedoctordata();
                cout << "doctor salary update!" << endl;
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential!" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        if (adminoption == "4")
        {
            system("cls");
            hms();
            header();
            adminheader();
            string name, password;
            cout << "enter doctor name: ";
            cin >> name;
            bool check = doctordelete(name);

            if (check == true)
            {
                rewritedoctordata();
                cout << "doctor deleted." << endl;
            }
            else
            {
                colorontext(4);
                cout << "you enter wrong credential" << endl;
                colorontext(7);
            }
            clearscreen();
        }

        if (adminoption == "6")
        {
            system("cls");
            hms();
            header();
            sortingofarraypatient();
            cout << "Aecending sorting of age:" << endl;
            cout << "patients"
                 << "\t"
                 << "passwords"
                 << "\t"
                 << "age"
                 << "\t"
                 << "disease"
                 << "\t\t"
                 << "medicine"
                 << "\t"
                 << "contact" << endl;
            for (int index = 0; index < patientusercount; index++)
            {
                cout << patient[index] << "\t\t" << patientpasswords[index] << "\t\t" << patientage[index] << "\t" << patientdisease[index] << "\t\t" << patientmedicine[index] << "\t\t" << patientcontact[index] << endl;
            }
            clearscreen();
        }

        if (adminoption == "7")
        {
            system("cls");
            hms();
            header();
            adminheader();
            cout << "bill payments" << endl;
            cout << endl;
            cout << "patients"
                 << "\t"
                 << "payments" << endl;
            for (int index = 0; index < patientusercount; index++)
            {
                cout << patient[index] << "\t\t" << billpayment[index] << endl;
            }
            clearscreen();
        }
    }
}

string adminlogin()
{
    string option;
    colorontext(2);
    cout << "Login menu!" << endl;
    cout << endl
         << endl;
    cout << "1.signin" << endl;
    cout << "2.signup" << endl;
    cout << "3.exit" << endl;
    cout << endl;
    cout << "option: ";
    cin >> option;
    colorontext(7);
    return option;
}
void clearscreen()
{
    cout << "Press any key to continue!" << endl;
    getch();
    system("cls");
}

string mainmenu()
{
    string option;
    colorontext(2);
    cout << "Select one of the following option: " << endl;
    cout << endl
         << endl;
    cout << "1.Admin" << endl;
    cout << "2.Doctor" << endl;
    cout << "3.Patient" << endl;
    cout << "4.exit " << endl;

    cout << endl;
    cout << "Option: ";
    cin >> option;
    colorontext(7);
    return option;
}
string adminmenu()
{
    colorontext(2);
    cout << "Select one of the following!" << endl;
    cout << endl
         << endl;
    cout << "1.view record" << endl;
    cout << "2.update fee" << endl;
    cout << "3.add doctor" << endl;
    cout << "4.delete doctor" << endl;
    cout << "5.view reviews" << endl;
    cout << "6.view patient" << endl;
    cout << "7.view bill payments" << endl;
    cout << "8.update salary" << endl;
    cout << "9.exit" << endl;
    cout << endl
         << endl;
    string option;
    cout << "Option: ";
    cin >> option;
    colorontext(7);
    return option;
}

string doctormenu()
{
    colorontext(2);
    cout << "Select the following option!" << endl;
    cout << endl
         << endl;
    cout << "1.add patient" << endl;
    cout << "2.delete patient" << endl;
    cout << "3.view appointment" << endl;
    cout << "4.cancel appointment" << endl;
    cout << "5.add appointment" << endl;
    cout << "6.add prescription" << endl;
    cout << "7.view bill payment" << endl;
    cout << "8.generate test reports" << endl;
    cout << "9.view record" << endl;
    cout << "10.exit" << endl;
    cout << endl
         << endl;
    string option;
    cout << "Option:";
    cin >> option;
    colorontext(7);
    return option;
}

string patientmenu()
{
    colorontext(2);
    cout << "select the following option!";
    cout << endl
         << endl;
    cout << "1.view prescription" << endl;
    cout << "2.bill payment" << endl;
    cout << "3.checkup fee" << endl;
    cout << "4.view appointment" << endl;
    cout << "5.give review" << endl;
    cout << "6.view test reports." << endl;
    cout << "7.exit" << endl;
    cout << endl
         << endl;
    string option;
    cout << "Option: ";
    cin >> option;
    colorontext(7);
    return option;
}

void hms()
{
    colorontext(3);
    cout << "         ###        ###     ###                   ###     ##################       " << endl;
    cout << "         ###        ###     ##  ##             ##  ##     ##                       " << endl;
    cout << "         ###        ###     ##     ##      ##      ##       ##                     " << endl;
    cout << "         ###        ###     ##         ##          ##         ##                   " << endl;
    cout << "         ###        ###     ##                     ##           ##                 " << endl;
    cout << "         ##############     ##                     ##             ##               " << endl;
    cout << "         ###        ###     ##                     ##               ##             " << endl;
    cout << "         ###        ###     ##                     ##                 ##           " << endl;
    cout << "         ###        ###     ##                     ##                   ##         " << endl;
    cout << "         ###        ###     ##                     ##                     ##       " << endl;
    cout << "         ###        ###     ##                     ##      ##################      " << endl;
    cout << endl;
    colorontext(7);
}

void header()
{
    colorontext(3);
    cout << "*************************************************************" << endl;
    cout << "****************|Hospital management System|*****************" << endl;
    cout << "*************************************************************" << endl;
    colorontext(7);
    cout << endl;
}

void adminheader()
{
    colorontext(3);
    cout << "              ************                " << endl;
    cout << "              |Admin menu|                " << endl;
    cout << "              ************                " << endl;
    colorontext(7);
    cout << endl;
}

void doctorheader()
{
    colorontext(3);
    cout << "              *************                " << endl;
    cout << "              |Doctor menu|                " << endl;
    cout << "              *************                " << endl;
    colorontext(7);
    cout << endl;
}

void patientheader()
{
    colorontext(3);
    cout << "              *************                 " << endl;
    cout << "              |patient menu|                " << endl;
    cout << "              *************                 " << endl;
    colorontext(7);
    cout << endl;
}
void colorontext(int num)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, num);
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
