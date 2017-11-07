#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include <vector>

//Sample maze (1== wall, 0 == space)
int maze1 [16][33] =
        {
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},
                {1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1},
                {1,0,0,1,0,1,1,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1},
                {1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1},
                {1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,0,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1},
                {1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
                {1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1}
        };

int wallCount();
void generateWalls(sf::Texture* texture,sf::Vector2f size,sf::Vector2f position,int rows,int columns,vector <Wall>* walls);


int main()
{
    //Create Window
    sf::RenderWindow window(sf::VideoMode(1200,700), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);

    //setting player's texture
    sf::Texture playerTexture;
    playerTexture.loadFromFile("/home/rodrigo/CLionProjects/maze_1/playerSprites.png");

    sf::Texture wallTexture;
    wallTexture.loadFromFile("/home/rodrigo/CLionProjects/maze_1/wall2Texture.png");


    vector<Wall> walls;


    //Creating player object
    Player player(&playerTexture,sf::Vector2u(3,4),0.3f,150.0f);



    //creating walls
    walls.reserve(wallCount());
    sf::Vector2f WallPosition(20.0f,20.0f);
    for (int i = 0; i < 16; ++i)
    {
        for (int j = 0; j < 33; ++j)
        {
            if(maze1[i][j]==1)
            {
                WallPosition.x = (j+1)*20;
                WallPosition.y = (i+1)*20;
                walls.push_back (Wall(&wallTexture,WallPosition));
            }
        }
    }


    //Wall wall1(&wallTexture,sf::Vector2f(100.0f,100.0f),sf::Vector2f(400.0f,200.0f));
    //Wall wall2(&wallTexture,sf::Vector2f(100.0f,100.0f),sf::Vector2f(300.0f,0.0f));

    //create a clock
    float deltaTime;
    sf::Clock clock;


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;


            }

        }

        //animate and move the player


        //wall1.GetCollider().CheckCollision(player.GetCollider(),0.0f);
        //wall2.GetCollider().CheckCollision(player.GetCollider(),0.0f);

        //set background color
        window.clear(sf::Color::White);

        player.Update(deltaTime,playerTexture);

        for (int i = 0; i < wallCount(); ++i)
        {
            walls[i].Draw(window);
        }

        //creating collision
        bool Collition = false;
        Wall CollidedWall(&wallTexture,sf::Vector2f(0,0));
        for (int j = 0; j < wallCount() ; ++j)
        {
            if (player.GetGlobalBounds().intersects(walls[j].GetGlobalBounds()))
            {
                CollidedWall = walls[j];
                Collition = true;

            }
        }

        if (Collition)
        {
            sf::Vector2f WallPosition = CollidedWall.GetPosition();
            sf::Vector2f PlayerPosition = player.GetPosition();
            float dx = PlayerPosition.x - WallPosition.x;
            float dy = PlayerPosition.y - WallPosition.y;

            sf::Vector2f Intersection = player.GetOrigin() - CollidedWall.GetOrigin();
            float intersectX = Intersection.x;
            float intersectY = Intersection.y;

            if(intersectX > intersectY)
            {
                if( dx > 0)
                {
                    player.Move(-intersectX, 0);
                }
                else
                {
                    player.Move(intersectX, 0);
                }
            }

            else
            {
                if (dy > 0)
                {
                    player.Move(0,-intersectY);
                }
                else
                {
                    player.Move(0,intersectY);
                }
            }

        }




        player.Draw(window);
        //wall1.Draw(window);
        //wall2.Draw(window);

        window.display();
    }

    return 0;
}

int wallCount() {
    int counter = 0;
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 33; ++j) {
            if (maze1[i][j] == 1) { counter += 1; }
        }
    }
    return counter; }

/*
void generateWalls(sf::Texture* texture,sf::Vector2f size,sf::Vector2f position,int rows, int columns,vector<Wall> &walls)
{
    int counter=0;
    walls.reserve(250);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (maze1[i][j]==1)
            {
                position.x = (j+1)*20;
                position.y = (i+1)*20;
                walls.push_back (Wall(texture,size,position));
                counter+=1;
            }
        }
    }

}
*/
