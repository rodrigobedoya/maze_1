//
// Created by rodrigo on 11/5/17.
//

#include "Wall.h"

Wall::Wall(sf::Texture* texture, sf::Vector2f position)
{
    body.setSize(sf::Vector2f(20.0f,20.0f)); // set size
    body.setOrigin(body.getSize()/2.0f); //set Origin (center)
    body.setTexture(texture);   //set Texture
    body.setPosition(position); // set position
}

Wall::~Wall() {

}

void Wall::Draw(sf::RenderWindow &window)
{
    window.draw(body);

}


