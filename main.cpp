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
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;


Airplane a(50, 2);

struct thread_data {
    int  thread_id;
};

void *reserve(void* threadarg)
{
    
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadarg;
    
    int limit_for_x = 50;
    int limit_for_y = 2;
    int start = 1;
    
    int random_x = random() % limit_for_x + start;
    int random_y = random() % limit_for_y + start;
    
    if (a.getdata(random_x, random_y) == 0)
    {
        a.manipulatedata(random_x, random_y, my_data->thread_id);
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
    int i;
    while(!a.istheplanefull())
    {
        for( i = 0; i < NUM_THREADS; i++ )
        {
            td[i].thread_id = i+1;
            pthread_create(&threads[i], NULL, reserve, (void *)&td[i]);
        }
    
        for( i = 0; i < NUM_THREADS; i++ )
        {
            pthread_join(threads[i], NULL);
        }
        a.printAirplane();
    }
    
   exit(EXIT_SUCCESS);
}
