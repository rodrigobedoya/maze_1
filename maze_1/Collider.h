//
// Created by rodrigo on 11/5/17.
//

#ifndef UNTITLED_COLLIDER_H
#define UNTITLED_COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider {

public:
    Collider(sf::RectangleShape& body);
    virtual ~Collider();

    void Move(float dx, float dy);

    bool CheckCollision(Collider &other, float push);
    sf::Vector2f GetPosition(){
        return body.getPosition();
    }

    sf::Vector2f GetHalfSize(){
        return body.getSize() / 2.0f;
    }


private:
    sf::RectangleShape& body;

};


#endif //UNTITLED_COLLIDER_H
