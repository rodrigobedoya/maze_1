//
// Created by rodrigo on 11/5/17.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Wall.h"


class Player
{

public:
    Player(sf::Texture*, sf::Vector2u imageCount, float switchTime, float speed);
    virtual ~Player();

    void Update(float deltaTime,sf::Texture& playerTexture);
    void Draw(sf::RenderWindow& window);

    sf::Vector2f GetPosition();
    Collider GetCollider() {
        return Collider(body);
    }

    sf::FloatRect GetGlobalBounds(){return body.getGlobalBounds();}
    sf::Vector2f GetOrigin(){return body.getOrigin();}
    void Move(float dx,float dy){body.move(dx,dy);}


private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
};


#endif //UNTITLED_PLAYER_H
