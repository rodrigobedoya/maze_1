//
// Created by rodrigo on 11/5/17.
//

#ifndef UNTITLED_WALL_H
#define UNTITLED_WALL_H

#include <SFML/Graphics.hpp>
#include "Collider.h"


class Wall
{

public:
    Wall(sf::Texture* texture, sf::Vector2f position);
    virtual ~Wall();

    void Draw(sf::RenderWindow& window);
    Collider GetCollider(){return Collider(body);}

    sf::FloatRect GetGlobalBounds(){return body.getGlobalBounds();}
    sf::Vector2f GetOrigin(){return body.getOrigin();}
    sf::Vector2f GetPosition(){return body.getPosition();}


private:
    sf::RectangleShape body;
};


#endif //UNTITLED_WALL_H
