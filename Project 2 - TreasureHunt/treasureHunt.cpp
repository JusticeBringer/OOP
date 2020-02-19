#include <iostream>
#include "treasureMapHunt.h"
#include "hunter.h"
#include "hunterOne.h"
#include "hunterTwo.h"
#include "hunterThree.h"
#include "hunterFour.h"

using namespace std;

TreasureMap::TreasureMap () : rows(0), columns(0), pas(0), nrHunters(0){
    matrix = new int*[0];
    matrix[0] = new int [0];    //initiere constructor fara parametri
    
    ArrHunter.push_back(new HunterOne(rows, columns));
    ArrHunter.push_back(new HunterTwo(rows, columns));  //initializare vectori
    ArrHunter.push_back(new HunterThree(rows, columns));    //de cautatori
    ArrHunter.push_back(new HunterFour(rows, columns));
}

TreasureMap::TreasureMap ( unsigned linii, unsigned coloane, unsigned numarAgenti)
                         : rows(linii), columns(coloane), pas(0), nrHunters(numarAgenti){
    if(test() == 0 )
        return;                 //constructor cu parametri 
                                //folosing lista de initializare

    matrix = new int*[rows + 1];        //initierea matricii
    for(int i = 1; i <= rows + 1; i++)
        matrix[i] = new int [columns + 1];

    ArrHunter.push_back(new HunterOne(rows, columns));
    ArrHunter.push_back(new HunterTwo(rows, columns));  //initializare vectori
    ArrHunter.push_back(new HunterThree(rows, columns));    //de cautatori
    ArrHunter.push_back(new HunterFour(rows, columns));
    
    HunterOne(rows, columns);
    HunterTwo(rows, columns);   //apelare constructori 
    HunterThree(rows, columns); //cu parametri
    HunterFour(rows, columns);
}

TreasureMap::TreasureMap (const TreasureMap &ob) : rows(ob.rows), columns(ob.columns), nrHunters(ob.nrHunters){
    matrix = new int* [ob.rows];
    for(int i = 1; i <= rows; i++)
        matrix[i] = new int [ob.columns];   

    for(unsigned i = 1; i <= rows; i++)
        for(unsigned j = 1; j <= columns; j++)   //copiere matrix
            matrix[i][j] = ob.matrix[i][j];
}

TreasureMap::~TreasureMap (){
    pas = 0;

    for(int i = 1; i <= rows; i++)
        delete [] matrix[i];         //stergere matrix
    delete [] matrix;
}

bool TreasureMap::test (){
    if(rows == 0 || columns == 0){ // daca nu avem coloane sau randuri
        return 0;
    }
    if(rows * columns <= 224){ //daca matricea nu e 15 x 15
        return 0;               
    }
    return 1;
}

std::pair <unsigned, unsigned> TreasureMap::findTreasure(){
    std::pair <unsigned, unsigned> aux;
    for( int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            if(matrix[i][j] == 9){      
                aux.first  = i;     //gasire prima comoara
                aux.second = j;     //de sus in jos
                return aux;
            }
}

void TreasureMap::showMatrix (){
    if(test() == 0)
        std::exit(0);
                                        //afisare harta
    for( int i = 1; i <= rows; i++){
        for (int j = 1; j <= columns; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;     
    }
}

void TreasureMap::detalii(){        //afisarea detaliilor modificarilor
                                                    //de pe harta
    if(ArrHunter[0]->poz.first == rows * 2)
        cout << "\nCautatorul 1 a iesit din joc ";
    else
        cout << "\nCautatorul 1 s-a mutat pe pozitia "
             << ArrHunter[0]->poz.first << " "
             << ArrHunter[0]->poz.second;
    if(ArrHunter[1]->poz.first == rows * 2)
        cout <<"\nCautatorul 2 a iesit din joc ";
    else
        cout << "\nCautatorul 2 s-a mutat pe pozitia "
             << ArrHunter[1]->poz.first << " "
             << ArrHunter[1]->poz.second;
    if(ArrHunter[2]->poz.first == rows * 2)
        cout << "\nCautatorul 3 a iesit din joc ";
    else
        cout << "\nCautatorul 3 s-a mutat pe pozitia "
             << ArrHunter[2]->poz.first << " "
             << ArrHunter[2]->poz.second;
    if(ArrHunter[3]->poz.first == rows * 2)
        cout << "\nCautatorul 4 a iesit din joc ";
    else
        cout << "\nCautatorul 4 s-a mutat pe pozitia "
             << ArrHunter[3]->poz.first << " "
             << ArrHunter[3]->poz.second;
    
    cout << "\nPana acum, ";
    if(Comori.size() == 0 || Comori.size() > 1){
        cout << "s-au luat ";
        cout << Comori.size() << " comori\n";
    }
    else{
        cout << "s-a luat ";
        cout << Comori.size() << " comoara\n";
    }

    if(Comori.size() != 0){
        for(unsigned it = 0; it < Comori.size(); it++)
            if(Comori[it] != 0)
                cout << "\nCautatorul " << Comori[it] << " detine o comoara";
    }

    if(pas % 4 == 3){
        cout << "\nCautatorul 1 va face 2 mutari runda urmatoare";
    }

    if(pas % 2 == 1){
        cout << "\nCautatorul 4 va face 2 mutari runda urmatoare";
    }
    
    if(pas % 4 == 3){
        cout << "\nCautatorii 2 si 3 sunt pe cale sa execute miscarea ingheata pozitiile";
    }

    if(pas % 6 == 5){
        cout << "\nCautatorul 2 se va pozitiona (posibil) langa o comoara runda urmatoare";
    }

    if(pas % 8 == 7){
        cout << "\nCautatorul 3 se va pozitiona (posibil) langa o comoara runda urmatoare";
    }
}

bool TreasureMap::inLimitsRows(unsigned x){
    if(x < 1)
        return false;
    if(x > rows)        //daca indicele de linie
        return false;   //e peste limita matricei
    return true;
}

bool TreasureMap::inLimitsColumns(unsigned x){
    if(x < 1)
        return false;
    if(x > columns)     //daca indicele de coloana
        return false;   //e peste limita matricei
    return true;
}

unsigned TreasureMap::randomRow(unsigned x){
    srand (time(NULL));    //generare aleatorie
    return rand() % x;
}

unsigned TreasureMap::randomCol(unsigned x){
    srand (time(NULL));    //generare aleatorie
    return (rand() % x);
}

void TreasureMap::generateTreasures(){
    unsigned nrComori = 3;
    unsigned nr = 1;        
                                //functie ce genereaza 3 indici
                                //si ii pune pe harta (comorile)
                                // comoara = valoarea 9
    while(nrComori > 0){
        unsigned varRow = randomRow(rows);
        unsigned varCol = randomCol(columns);

        if(nr % 3 == 0){
            varRow += 1;
            varCol -= 5;        //pozitionare comori
        }                       //in locatii diferite
        else if(nr % 3 == 1){
            varRow -= 2;
            varCol += 3;
           }
            else{
                varRow += 7;
                varCol -= 2;
            }

        if((varRow == 1 && varCol == 1)     //daca comoara ar fi
             || (varRow == 1 && varCol == columns)  //plasata
             || (varRow == rows && varCol == 1)      //in colturi
             || (varRow == rows && varCol == columns))
                nrComori = nrComori;
        else{
            if(inLimitsRows(varRow) && inLimitsColumns(varCol)
               && matrix[varRow][varCol] != 9){ //daca e o pozitie libera
                    matrix[varRow][varCol] = 9;
                    nrComori -= 1;
            }
            else
                nrComori = nrComori;
        }
        nr += 1;
    }
}

std::pair <unsigned, unsigned> TreasureMap::getNextPoz(
                        std::pair <unsigned, unsigned> pereche){
     
    if(inLimitsRows(pereche.first - 1) == true 
       && inLimitsColumns(pereche.second - 1) == true
       && (matrix[pereche.first - 1][pereche.second - 1] == 0
           || matrix[pereche.first - 1][pereche.second - 1] == 9)){
        pereche.first  -= 1;
        pereche.second -= 1;    //deasupra si la stanga

        return pereche;
    }
    if(inLimitsRows(pereche.first - 1) == true
       && (matrix[pereche.first - 1][pereche.second] == 0
           || matrix[pereche.first - 1][pereche.second] == 9)){
        pereche.first -= 1; //deasupra

        return pereche;
    }
    if(inLimitsRows(pereche.first - 1) == true 
       && inLimitsColumns(pereche.second + 1) == true
       && (matrix[pereche.first - 1][pereche.second + 1] == 0
           || matrix[pereche.first - 1][pereche.second + 1] == 9)){
        pereche.first  -= 1;    //deasupra si la dreapta
        pereche.second += 1;

        return pereche;
    }
    if(inLimitsColumns(pereche.second - 1) == true 
       && (matrix[pereche.first][pereche.second - 1] == 0
           || matrix[pereche.first][pereche.second - 1] == 9)){
        pereche.second -= 1;    //o poz. la stanga

        return pereche;
    }
    if(inLimitsColumns(pereche.second + 1) == true
       && (matrix[pereche.first][pereche.second + 1] == 0
           || matrix[pereche.first][pereche.second + 1] == 9)){
        pereche.second += 1;    //o poz. la dreapta

        return pereche;
    }
    if(inLimitsRows(pereche.first + 1) == true 
       && inLimitsColumns(pereche.second - 1) == true
       && (matrix[pereche.first + 1][pereche.second - 1] == 0
           || matrix[pereche.first + 1][pereche.second - 1] == 9)){
        pereche.first  += 1;
        pereche.second -= 1;    //dedesupt si la stanga

        return pereche;
    }
    if(inLimitsRows(pereche.first + 1) == true
       && (matrix[pereche.first + 1][pereche.second] == 0
           || matrix[pereche.first + 1][pereche.second] == 9)){
        pereche.first += 1; //dedesupt

        return pereche;
    }
    if(inLimitsRows(pereche.first + 1) == true 
       && inLimitsColumns(pereche.second + 1) == true
       && (matrix[pereche.first + 1][pereche.second + 1] == 0
           || matrix[pereche.first + 1][pereche.second + 1] == 9)){
        pereche.first  += 1;
        pereche.second += 1;    //dedesupt si la dreapta

        return pereche;
    }
    pereche.first  = rows * 2;
    pereche.second = columns * 2;   //nu exista indici valizi

    return pereche;
}

void TreasureMap::moveHunters(Hunter* hnt, unsigned i, unsigned& ok){
    poz = hnt->movePoz();
    hnt->scadPoz();
    
    if(inLimitsRows(poz.first) && inLimitsColumns(poz.second))
        if(matrix[poz.first][poz.second] == 9){
            hnt->poz = poz;     //daca e comoara
            matrix[poz.first][poz.second] = i;
            ok = 1;
        }
        else{
            if(matrix[poz.first][poz.second] == 0){
                hnt->poz = poz; //daca e nevizitata
                matrix[poz.first][poz.second] = i;
                ok = 2;
            }
        }
    //daca nu s-a putut muta dupa algoritmul de mutare
    //verifica daca poate lua o pozitie adiacenta
    if(ok == 0){
        poz = getNextPoz(hnt->poz);

        if(inLimitsRows(poz.first) && inLimitsColumns(poz.second))
            if(matrix[poz.first][poz.second] == 9){
               hnt->poz = poz;  //comoara
               matrix[poz.first][poz.second] = i;
               ok = 1;
            }
            else{
                if(matrix[poz.first][poz.second] == 0){
                    hnt->poz = poz; //nevizitat
                    matrix[poz.first][poz.second] = i;
                    ok = 0;
                }
            }
    }
}

void TreasureMap::stopPoz(unsigned okay, unsigned i){
    if(okay == 1    //daca da peste comoara sa nu se mai miste
       && inLimitsRows(ArrHunter[i]->poz.first)
       && inLimitsColumns(ArrHunter[i]->poz.second)){
        cout << "Comoara de pozitia " << ArrHunter[i]->poz.first
             << " " << ArrHunter[i]->poz.second 
             << " a fost luata de cautatorul " << i + 1 << endl;
        ArrHunter[i]->poz.first  = rows * 2;
        ArrHunter[i]->poz.second = columns * 2;
        Comori.push_back(i + 1);
    }
}

void TreasureMap::changeMatrix(){
    unsigned ok = 0;
    std::pair <unsigned, unsigned> aux;

    //--------------------------Mutarea----------------------
    
    unsigned chanceHntDoi = ArrHunter[1]->moveOrNot();
    unsigned chanceHntTrei = ArrHunter[2]->moveOrNot();

    if(chanceHntDoi <= 15 && chanceHntTrei <= 30 //sansa e potrivita
       && ArrHunter[1]->movePas % 4 == 0){      //si pasul e multiplu de 4
           ; //nimic, toti sar runda aceasta
       }
    else{
        if(chanceHntDoi <=15    //daca sansa a fost <= 15
           && ArrHunter[1]->movePas % 4 == 0 //si pasul e multiplu de 4
           && ArrHunter[1]->poz.first != rows * 2) {  //si nu are comoara
               moveHunters(ArrHunter[1], 2, ok);    //mutam doar H2
               stopPoz(ok, 1);
           }
        else{
            if(chanceHntTrei <= 30 
               && ArrHunter[2]->movePas % 4 == 0
               && ArrHunter[2]->poz.first != rows * 2){                   //daca sansa a fost <= 30
                    moveHunters(ArrHunter[2], 3, ok);   //si pasul e multiplu de 4
                    stopPoz(ok, 2);                     //si nu are comoara
                                                        //mutam doar H3
            }   

            else{
                if(ArrHunter[0]->movePas % 4 == 0){   //2 mutari
                    moveHunters(ArrHunter[0], 1, ok);  //la 4 runde
                    stopPoz(ok, 0);     
                    ok = 0;                             //Cautator 1
                    moveHunters(ArrHunter[0], 1, ok);
                    stopPoz(ok, 0);
                }
                else{
                    moveHunters(ArrHunter[0], 1, ok);
                    stopPoz(ok, 0);
                }

                if(ArrHunter[1]->poz.first != rows * 2){
                    ok = 0; //odata la 6 mutari se muta intr-o pozitie adiacenta 
                    if(ArrHunter[1]->movePas % 6 == 0){     //primei comori
                        aux = findTreasure();               //daca se poate
                        aux = getNextPoz(aux);
                        
                        if(aux.first != rows * 2){
                            ArrHunter[1]->poz = aux;
                            ArrHunter[1]->scadPoz();
                            moveHunters(ArrHunter[1], 2, ok);
                        }
                    }
                    else{
                        moveHunters(ArrHunter[1], 2, ok);   //Cautator 2
                        stopPoz(ok, 1);
                    }
                }

                if(ArrHunter[2]->poz.first != rows * 2){
                    ok = 0; //odata la 8 mutari se muta intr=o pozitie adiacenta
                    if(ArrHunter[2]->movePas % 8 == 0){     //primei comori
                        aux = findTreasure();               //daca se poate
                        aux = getNextPoz(aux);

                        if(aux.first != rows * 2){
                            ArrHunter[2]->poz = aux;
                            ArrHunter[2]->scadPoz();
                            moveHunters(ArrHunter[2], 3, ok);
                        }
                    }
                    else{
                        moveHunters(ArrHunter[2], 3, ok);   //Cautator 3
                        stopPoz(ok, 2);
                    }
                }

                ok = 0;
                if(ArrHunter[0]->movePas % 2 == 0){     //2 mutari
                    moveHunters(ArrHunter[3], 4, ok);   //la 2 runde
                    stopPoz(ok, 3);     
                    ok = 0;
                    moveHunters(ArrHunter[3], 4, ok);   //Cautator 4
                    stopPoz(ok, 3);
                }
                else{
                    moveHunters(ArrHunter[3], 4, ok);
                    stopPoz(ok, 3);
                }
            }
        }   
    }

    //----------------------Incheierea jocului--------------------

    if(Comori.size() == 3){ //au fost luate cele 3 comori
        cout << "Au fost luate toate cele 3 comori. Jocul s-a terminat!";
        exit(0);
    }

    std::pair <unsigned, unsigned> var;
    var = getNextPoz(ArrHunter[0]->poz);    //daca nu se mai pot misca
    if(pas > 50){
        if(var.first == rows * 2){
            var = getNextPoz(ArrHunter[1]->poz);
            if(var.first == rows * 2){
                var = getNextPoz(ArrHunter[2]->poz);
                if(var.first == rows * 2){
                    var = getNextPoz(ArrHunter[3]->poz);
                    if(var.first == rows * 2){
                        if(Comori.size() != 0)
                            cout << "\nCastigatorul jocului a fost cautatorul "
                                << Comori[0];
                        cout << "Nu mai exista mutari valide. Jocul s-a terminat!";
                        exit(0);
                    }
                }
            }
        }     
    }
}

void TreasureMap::desfasurare(){
    if(test() == false){
        cout << "\t \t \t Matrice mai mica de 15x15. Jocul se va inchide\n";
        exit(0);
    }

    std::cout << "\n \t \t \t \t \t \tBine ati venit la Treasure Hunt\n\n";
    std::cout << "Pentru incepere joc apasati tasta 1 si enter\n";
    std::cout << "Pentru terminarea jocului apasati tasta 2 si enter";
    
    unsigned tasta;
    cout << "\n\n \t \t \t \t Tasta dumneavoastra este: ";
    cin >> tasta;

    if(tasta != 1){
        cout << "\nAti iesit din joc. Va mai asteptam!\n";
        exit(0);
    }

    ArrHunter[0]->poz = HunterOne(rows, columns).poz;   //punere valori de inceput
    ArrHunter[1]->poz = HunterTwo(rows, columns).poz;   //in vectorii Cautatori
    ArrHunter[2]->poz = HunterThree(rows, columns).poz;
    ArrHunter[3]->poz = HunterFour(rows, columns).poz;

    matrix[ArrHunter[0]->poz.first][ArrHunter[0]->poz.second] = 1;  //pozitionarea
    matrix[ArrHunter[1]->poz.first][ArrHunter[1]->poz.second] = 2;  //cautatorilor
    matrix[ArrHunter[2]->poz.first][ArrHunter[2]->poz.second] = 3;  //in cele
    matrix[ArrHunter[3]->poz.first][ArrHunter[3]->poz.second] = 4;  //4 colturi
    
    generateTreasures();    //generarea comorilor pe harta

    pas = 0;
    cout << "\n \n \t \t \t \t \t Ati intrat in joc!";

    while(tasta != 9){
        cout << "\n Pasul curent este " << pas;
        cout << "\n Pentru afisarea hartii apasati tasta 1";
        cout << "\n Pentru afisarea modificarilor hartii apasati tasta 2";
        cout << "\n Pentru trecere la runda urmatoare apasati tasta 3";
        cout << "\n Pentru iesire din joc apasati tasta 9";

        cout << "\n\n \t \t \t \t Tasta dumneavoastra este: ";
        cin >> tasta;

        switch (tasta){
            case 1:
                showMatrix();   //afisare harta
                break;
            case 2:
                detalii();  //afisare detalii de pe harta
                break;
            case 3:
                pas += 1;
                ArrHunter[0]->movePas += 1; //actualizare 
                ArrHunter[1]->movePas += 1; //pas curent
                ArrHunter[2]->movePas += 1; //dar retinut
                ArrHunter[3]->movePas += 1; //in vectorii 
                                            //Cautatorilor

                changeMatrix(); //actualizare pozitii
                
                break;
            case 9:
                if(Comori.size() != 0)
                    cout << "\nCastigatorul jocului a fost cautatorul "
                         << Comori[0] << endl;
                cout << "\nAti iesit din joc. Va mai asteptam!\n";
                exit(0);
            default:
                cout << "\nNu am recunoscut tasta introdusa";
                cout << "\nVa rugam introduceti alta tasta";
                break;
        }
    }
}