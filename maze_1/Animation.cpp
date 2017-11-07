//
// Created by rodrigo on 11/5/17.
//

#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount; //first one is private variable from class, second is parameter
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x); //determine width of a single sprite
    uvRect.height = texture->getSize().y / float(imageCount.y); //height of a single sprite
}

Animation::~Animation() {}

void Animation::Update(int row, float deltaTime)
{
    currentImage.y = row; //choose row of a sprites to animate a specific action
    totalTime += deltaTime;

    if(totalTime >= switchTime);
    {
        totalTime -= switchTime;
        currentImage.x++; //advance in the row

        if(currentImage.x >= imageCount.x) //to repeat the sprites
        {
            currentImage.x = 0;
        }
    }

    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}
