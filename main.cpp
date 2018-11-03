//
//  main.cpp
//  cs307homework1
//
//  Created by Feyiz on 31/10/18.
//  Copyright © 2018 Feyiz. All rights reserved.
//

#include <iostream>
#include <pthread.h>
#include "seats.h"
#include <cstdlib>


using namespace std;

#define NUM_THREADS  2
int f1, f2, turn;

Airplane a(50, 2);

struct thread_data {
    int  thread_id;
};

void *reserve2(void* threadarg)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadarg;
    
    while(a.istheplanefull()== false)
    {
        f2=1;
        turn=1;
        while((f2==1)&&(turn==1))
        {}
        while(f2== 1){
    
            int limit_for_x = 50;
            int limit_for_y = 2;
        
            int random_x = rand() % limit_for_x;
            int random_y = rand() % limit_for_y;
        
            if (a.getdata(random_x, random_y) == 0)
            {
                my_data = (struct thread_data *)threadarg;
                a.manipulatedata(random_x, random_y, my_data->thread_id);
                cout << "Seat Number  " << random_x*2 + random_y +1 << " is reserved by TravelAgencyTA2" << endl;
            
                f2 = 0;
            }
        }
        
    }
    return 0;
}

void *reserve1(void* threadarg)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadarg;
    
    while(a.istheplanefull() == false)
    {
        f1=1;
        turn=0;
        while((f1==1)&&(turn==0))
        {}
        
        while(f1 == 1){
            
            int limit_for_x = 50;
            int limit_for_y = 2;
    
            int random_x = rand() % limit_for_x;
            int random_y = rand() % limit_for_y;
    
            if (a.getdata(random_x, random_y) == 0)
            {
                a.manipulatedata(random_x, random_y, my_data->thread_id);
                cout << "Seat Number  " << random_x*2 + random_y +1 << " is reserved by TravelAgencyTA1" << endl;
                
                f1 = 0;
            }
        }
        
    }
    return 0;
}
int main() {
    
    system("cls");
    system("title berk feyiz");
    
    
    cout << "initialize..." << endl;
    a.printAirplane();

    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    
    
    td[0].thread_id =1;
    td[1].thread_id =2;
    pthread_create( &threads[0], NULL, reserve1, (void *)&td[0]);
    pthread_create( &threads[1], NULL, reserve2, (void *)&td[1]);
    while(!a.istheplanefull()){
    
    }
    cout << "The plane is full, finishing the execution of the other 2 threads and printing the Matrix to the console." << endl;
    
    
    
    a.printAirplane();

    
    
   exit(EXIT_SUCCESS);
    
}
