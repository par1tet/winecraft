#include <glm/glm.hpp>
#include <iostream>
#include <math.h>

using namespace std;

bool isCollision(glm::vec3 coordinates[], float sizes[], int index) {
    bool isCollisionReturn = false;

    float vertexCubeIndex[2][3];

    system("clear");

    for(int j = 0; j != 2; ++j){
        int sings[2][3] = {
            {1, 1, 1},
            {-1, -1, -1},
        };

        float vert[3];

        for(int k = 0; k != 3; ++k) { 
            vert[k] = coordinates[index][k] + (1 * sings[j][k] * sizes[index]);
        }

        vertexCubeIndex[j][0] = round(vert[0] * 100) / 100;
        vertexCubeIndex[j][1] = round(vert[1] * 100) / 100;
        vertexCubeIndex[j][2] = round(vert[2] * 100) / 100;
    }

    cout << coordinates[index][0] << " : " << coordinates[index][1] << endl;

    for(int ik = 0;ik != 2;ik++){
        cout << vertexCubeIndex[ik][0] << ":" << vertexCubeIndex[ik][1];
        cout << endl;
    }   

    for(int i = 0; i != 2; ++i) {
        if(index == i) continue;   

        float vertexCube[8][3];

        for(int j = 0; j != 8; ++j){
            int sings[8][3] = {
                {1, 1, 1},
                {1, 1, -1},
                {1, -1, 1},
                {1, -1, -1},
                {-1, 1, 1},
                {-1, 1, -1},
                {-1, -1, 1},
                {-1, -1, -1},
            };

            float vert[3];

            for(int k = 0; k != 3; ++k) { 
                vert[k] = coordinates[i][k] + (1 * sings[j][k] * sizes[i]);
            }

            vertexCube[j][0] = vert[0];
            vertexCube[j][1] = vert[1];
            vertexCube[j][2] = vert[2];
        }

        cout << coordinates[i][0] << " : " << coordinates[i][1] << endl;

        for(int ik = 0;ik != 8;ik++){
            cout << vertexCube[ik][0] << ":" << vertexCube[ik][1] << ":" << vertexCube[ik][2];
            cout << endl;
        }

        for(int ik = 0;ik != 8; ++ik){
            int counterColisioins = 0;

            for(int jk = 0;jk != 3; ++jk){
                if(vertexCubeIndex[0][jk] <= vertexCube[ik][jk] <= vertexCubeIndex[1][jk]){
                    counterColisioins++;
                }
            }

            cout << counterColisioins << endl;

            if(counterColisioins == 2){
                isCollisionReturn = true;
            }
        }
    }


    return isCollisionReturn;
}