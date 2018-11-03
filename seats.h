//
//  seats.h
//  cs307homework1
//
//  Created by Feyiz on 31/10/18.
//  Copyright © 2018 Feyiz. All rights reserved.
//

#ifndef seats_h
#define seats_h

#include <iostream>

using namespace std;

class Airplane
{
private:
    int **p;
    int x;
    int y;
    
public:
    Airplane(int rows, int columns);
    void printAirplane();
    int * gethead();
    int getdata(int row, int column);
    void manipulatedata(int row, int column, int reservedby);
    bool istheplanefull();


};

Airplane::Airplane(int rows, int columns) {
    
    x = rows;
    y = columns;
    int ** new_matrix = new int*[x];
    
    for(unsigned int i = 0; i < x; i++)
    {
        new_matrix[i] = new int[y];
    }
    
    for(unsigned int j= 0; j < x; j++)
    {
        for(unsigned int k = 0; k< y; k++)
        {
            new_matrix[j][k] = 0;
        }
    }
    p = new_matrix;
}

void Airplane::printAirplane()
{
    for(int q = 0;  q< y; q++)
    {
        for(int g = 0; g < x; g++)
        {
            cout << p[g][q] << "  ";
        }
        cout << endl;
    }
}

int *Airplane::gethead(){
    return *p;
}

int Airplane::getdata(int row, int column)
{
    return p[row][column];
}

void Airplane::manipulatedata(int row, int column, int reservedby)
{
    p[row][column] = reservedby;
}

bool Airplane::istheplanefull()
{
    int count = 0;
    for (unsigned int i = 0; i<50 ; i++)
    {
        for(unsigned int j = 0; j <2; j++)
        {
            if(p[i][j] == 0)
            {return false;}
        }
    }
    if(count == 0)
        {return true;}
    else
        {return false;}
}

#endif /* seats_h */
