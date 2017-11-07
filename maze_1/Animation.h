//
// Created by rodrigo on 11/5/17.
//

#ifndef UNTITLED_ANIMATION_H
#define UNTITLED_ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation
{

public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    virtual ~Animation();

    void Update(int row, float deltaTime); //deltaTime is time between update

    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount; //stores images value(quantity)
    sf::Vector2u currentImage;

    float totalTime; //time since last image change
    float switchTime; //time required for switch(animation speed)

};


#endif //UNTITLED_ANIMATION_H
