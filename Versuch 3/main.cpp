#include <iostream>
#include "GEOKO.h"
#include "POOL.h"
#include"TE.h"
#include<string>
#include <fstream>
#include<cstring>
#include <iomanip>
    /*
    AD-Praktikum SoSe 2021
    Gruppe:11
    Name, Vorname, Mat.-Nr.:Fatima AL KHTTABI ,111456555
    Name, Vorname, Mat.-Nr. des Praktikumsparners: Ahmad AL HOUSSAINI ,11145964
    Abgabe am:12.07.21
    Praktikumsblatt:3

    */
using namespace std;
int main() {
    int choice=2;
    long j = 0;
    int max1 = 5;
    string data[100][2];

    int a;

    double b, l;
    POOL* P1 = NULL;
    GEOKO* Mitte = NULL;

    GEOKO* G1 = NULL;
    int antw = 1;
    char* name = new char[100];
    while (antw == 1) {
        cout << "Mit dieses Programm kann man das folgendes machen:" << endl;
        cout << " 1. Daten einlesen und POOL-Objekt erstellen " << endl;
        cout << " 2. Liste sortieren mit Heap Sort " << endl;
        cout << " 3. Liste sortieren mit, InsertionsSort" << endl;
        cout << " 4. Daten der Liste schreiben " << endl;
        cout << " 5. Baumstruktur prüfen " << endl;
        cout << " 6. Ende" << endl;
        cout << "Bitte waehlen Sie von dem Menu eine Funktion aus" << endl;
        cin >> a;


        if (a == 1) {
            cout << "Anzahl der Daten für den Baum eingeben :" << endl;
            cout << "max1 : " << endl;
            cin >> max1;
            P1 = new POOL(max1);
            cout << "geben Sie einen Dateinamen der Daten ein : Daten1 oder Daten2 ? " << endl;
            cin >> name;
            /*cout << " 1 oder 2 " << endl;
            cin >> e;
            switch (e) {****/

            if ((strcmp(name, "Daten1") == 0)) {
                choice = 1;
                ifstream file;
                file.open("Daten1.csv");
                string line;
                while ((j < max1) && (!file.eof()))
                {

                    file >> line;
                    cout << line << endl;
                    l = stod(line);
                    cout << setprecision(10) << "Laenge  " << l << endl;
                    file >> line;
                    b = stod(line);
                    cout << line << endl;
                    cout << setprecision(10) << "Breite : " << b << endl;
                    G1 = new GEOKO(l, b);
                    P1->addElement(G1);
                    j++;
                }
                cout << "die Koordinaten des Mittelpunktes :   <Laenge " << P1->getMitte_lange() << " , Breite " << P1->getMitte_breite() << ">" << endl;
                file.close();
            }
            else if (((strcmp(name, "Daten2") == 0))) {
                choice = 2;

                ifstream file;
                file.open("Daten2.csv");
                string line;
                while ((j < max1) && (!file.eof()))
                {
                    j++;
                    file >> line;
                    cout << line << endl;
                    l = stod(line);
                    cout << setprecision(10) << "Laenge :" << l << endl;
                    file >> line;
                    b = stod(line);
                    cout << line << endl;
                    cout << setprecision(10) << "Breite :" << b << endl;
                    G1 = new GEOKO(l, b);
                    P1->addElement(G1);

                }
                cout << "die Koordinaten des Mittelpunktes  <Laenge " << P1->getMitte_lange() << " , Breite " << P1->getMitte_breite() << ">" << endl;
                file.close();

            }

        }
        else if (a == 2) {

            P1->heapSort();
        }
        else if (a == 3) {
            P1->inSort();
        }
        else if (a == 4) {


            // create an ofstream for the file output

            if (choice==1) {

                // create an ofstream for the file output
                ofstream fs;
                // create a name for the file output
                string filename = "daten1_S.csv";
                //create and open the .csv file
                fs.open(filename);

                fs <<setprecision(10)<<P1->getAnz() << "," << setprecision(10)<< P1->getMitte_lange() << "," << setprecision(10) << P1->getMitte_breite() << endl;
                long i = 0;
                // write the data to the output file
                while (i < P1->getAnz()) {

                    fs << P1->get_kooordinaten(i);
                    i++;
                }




            }
            else if (choice==2) {

                // create an ofstream for the file output
                   ofstream fs;
                    // create a name for the file output
                    string filename = "daten2_S.csv";
                     //create and open the .csv file

                    fs.open(filename);

                    fs << P1->getAnz() << "," << P1->getMitte_lange() << "," << P1->getMitte_breite() << endl;


                    long i = 0;
                    // write the data to the output file
                    while (i <P1->getAnz()) {

                       fs << P1->get_kooordinaten(i);
                        i++;



                    }

                    fs.close();






            }
            else
                cout << "die Datei gibt es nicht !" << endl;
        }
        else if (a == 5) {

        if (P1->pruefeBaum())
            cout << "richtig" << endl;
        else
            cout << "falsch" << endl;

        }
        else if (a == 6) {

            cout << "Ende" << endl;
        }

        else {
            cout << "was sie eingegben haben , ist kein methode" << endl;
        }

        cout << "moechten Sie weiter testen? falls ja bitte 1 eingeben, ansonst wird das Programm aufgehoert" << endl;
        cin >> antw;
        if (antw == 1)
            antw = 1;
        else
            cout << "Aufwiedersehen ! " << endl;


    }
}
