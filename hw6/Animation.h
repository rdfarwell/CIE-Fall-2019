/*
 * Name: Dean Farwell
 * Date: 11/15/2019
 * Filename: hw6/Animation.h
 * Note: Early Turn-In
 * Description : Animation class that controls the movement of the image so that an object appears animated
 */

#ifndef ASTEROIDS_ANIMATION_H
#define ASTEROIDS_ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(); // Constructors
    Animation(sf::Texture &t, int x = 0, int y = 0, int w = 0, int h = 0, int count = 1, float Speed = 0);

    void update(); // Updates current animation frame
    bool isEnd(); // Checks if the animation is complete

    sf::Sprite &getSprite();

private:
    float Frame, speed;
    sf::Sprite sprite;
    std::vector<sf::IntRect> frames;
};

#endif //ASTEROIDS_ANIMATION_H