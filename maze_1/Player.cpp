//
// Created by rodrigo on 11/5/17.
//

#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
    animation(texture, imageCount, switchTime) //initializing animation
{
    this->speed = speed; //using this to differentiate same name variables
    row = 0;

    body.setSize(sf::Vector2f(18.0f,18.0f)); //set size of player
    body.setPosition(40.0f,40.0f); //starting position
    body.setOrigin(body.getSize()/2.0f); //set origin (center)
    body.setTexture(texture); //choose texture

}

Player::~Player() {

}

void Player::Update(float deltaTime,sf::Texture& playerTexture) //second parameter used just for when the image isn't moving
{
    sf::Vector2f movement(0.0f,0.0f);


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= speed * deltaTime;
        row = 1;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += speed * deltaTime;
            row = 2;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -= speed * deltaTime;
        row = 3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += speed * deltaTime;
        row = 0;
    }

    else if(movement.x==0 && movement.y==0) //when it isn't moving ww don't want any animation so:
    {
        sf::Vector2u textureSize = playerTexture.getSize(); //getting the size of a single sprite
        textureSize.x /= 3; //sprite width
        textureSize.y/=4; //sprite height

        body.setTextureRect(sf::IntRect(textureSize.x*1,textureSize.y*row,textureSize.x,textureSize.y));
        //always choses the sprite in the first column of the last row, change value of row in constructor to choose
        //where it faces at start(0 = down, 1 = Left, 2 = right, 3 = up)
        return; //cuts out the void function(since the rest is animation stuff we don't want)
    }

    animation.Update(row,deltaTime); //choose which set of sprites to use for the animation(see directions in previous comment)
    body.setTextureRect(animation.uvRect); //sets size of sprite
    body.move(movement); //moves the player

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}

sf::Vector2f Player::GetPosition()
    {
        return body.getPosition();
    }






