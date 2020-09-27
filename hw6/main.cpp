/*
 * Name: Dean Farwell
 * Date: 11/11/2019
 * Filename: hw6/main.cpp
 * Note: Early Turn-In
 * Description: The game asteroids, in which we were to comment, add a ufo, and control asteroid spawn
 * Extra Credit: Cleaned code, Moved Animation to its own header file, created a forcefield powerup,
 *               output score after each death to check, display score during game and resets when player dies
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include <time.h>
#include <list>
#include <cmath>
#include <iostream>

using namespace sf;

const int W = 1200; // Window dimensions
const int H = 800;

float DEGTORAD = 0.017453f; // Global Variable to convert degrees to radians

class Entity { // main class for all entities for creating
public:
    float x, y, dx, dy, R, angle;
    bool life;
    std::string name;
    Animation anim;

    Entity() {
        life = 1;
    }

    void settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1) {
        anim = a;
        x = X;
        y = Y;
        angle = Angle;
        R = radius;
    }

    virtual void update() {};

    void draw(RenderWindow &app) {
        anim.getSprite().setPosition(x, y);
        anim.getSprite().setRotation(angle+90);
        app.draw(anim.getSprite());

        CircleShape circle(R);
        circle.setFillColor(Color(255,0,0,170));
        circle.setPosition(x, y);
        circle.setOrigin(R, R);
        //app.draw(circle);
    }

    virtual ~Entity() {};
};


class asteroid : public Entity {
public:
    static unsigned int getCount() {
        return count;
    }

    asteroid() {
        ++count;
        dx = rand() % 8 - 4;
        dy = rand() % 8 - 4;
        name = "asteroid";
    }

    void update() {
        x += dx;
        y += dy;

        if (x > W) {
            x = 0;
        }
        if (x < 0) {
            x = W;
        }
        if (y > H) {
            y = 0;
        }
        if (y < 0) {
            y = H;
        }
    }

    ~asteroid() {
        --count;
    }

private:
    static unsigned int count;
};

unsigned int asteroid::count{0};

class bullet : public Entity {
public:
    bullet() {
        name = "bullet";
    }

    void update() {
        dx = cos(angle*DEGTORAD) * 6; // Bullet Speed
        dy = sin(angle*DEGTORAD) * 6;
        // angle+=rand()%6-3;
        x += dx;
        y += dy;

        if (x > W || x < 0 || y > H || y < 0) { // gets rid of bullets when they leave the screen
            life = 0;
        }
    }
};


class player : public Entity {
public:
    bool thrust;

    player() {
        name = "player";
    }

    void update() {
        if (thrust) {
            dx += cos(angle*DEGTORAD) * 0.2;
            dy += sin(angle*DEGTORAD) * 0.2;
        }
        else {
            dx *= 0.99;
            dy *= 0.99;
        }

        int maxSpeed = 15;
        float speed = sqrt(dx*dx + dy*dy);

        if (speed > maxSpeed) {
            dx *= maxSpeed/speed;
            dy *= maxSpeed/speed;
        }

        x += dx;
        y += dy;

        if (x > W) {
            x = 0;
        }
        if (x < 0) {
            x = W;
        }
        if (y > H) {
            y = 0;
        }
        if (y < 0) {
            y = H;
        }
    }
};

class ufo : public Entity {
public:
    ufo() {
        dx = rand() % 8 - 4;
        name = "ufo";
    }

    void update() {
        x += dx;
        y += dy;

        if (x > W) {
            x = 0;
        }
        if (x < 0) {
            x = W;
        }
        if (y > H) {
            y = 0;
        }
        if (y < 0) {
            y = H;
        }
    }
};

class forcefield : public Entity {
public:
    forcefield() {
        name = "forcefield";
    }

    void update() {
        if (x > W) {
            x = 0;
        }
        if (x < 0) {
            x = W;
        }
        if (y > H) {
            y = 0;
        }
        if (y < 0) {
            y = H;
        }
    }
};

bool isCollide(Entity *a, Entity *b) { // function to check if two entities are colliding
    return (b->x - a->x) * (b->x - a->x) + (b->y - a->y) * (b->y - a->y) < (a->R + b->R) * (a->R + b->R);
}

int main() {
    srand(time(0)); // establishes random numbers based off of time
    int uFO = 0, scoreVal = 0; // tracker for ufo appearances and score
    bool ufoLife = false, ffLife = false, pickup = false;
    std::string sc = "score ";

    RenderWindow app(VideoMode(W, H), "Asteroids!"); // creates the window
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7, t8, t9;
    SoundBuffer ufoSound;
    Font disp;

    t1.loadFromFile("images/spaceship.png"); // open each image for each texture
    t2.loadFromFile("images/background.jpg"); // all images as given until noted
    t3.loadFromFile("images/explosions/type_C.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_blue.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");
    t8.loadFromFile("images/ufo.png");  // Free for personal use from sccpre.cat
    t9.loadFromFile("images/forcefield.png"); // created by me

    ufoSound.loadFromFile("sounds/ufoSound.ogg"); // Free for personal use from soundbible.com (Missle alert Sound)

    disp.loadFromFile("fonts/begok.ttf"); // Free for personal use from 1001freefonts.com by Carlos Matteoli

    t1.setSmooth(true);
    t2.setSmooth(true);
    t9.setSmooth(true);

    Sprite background(t2);

    Text score; // create score text for display
    score.setFont(disp);
    score.setCharacterSize(20);
    score.setFillColor(Color::White);


    Animation sExplosion(t3, 0,0,256,256, 48, 0.5); // sets up the animations
    Animation sRock(t4, 0,0,64,64, 16, 0.2);
    Animation sRock_small(t6, 0,0,64,64, 16, 0.2);
    Animation sBullet(t5, 0,0,32,64, 16, 0.8);
    Animation sPlayer(t1, 40,0,40,40, 1, 0);
    Animation sPlayer_go(t1, 40,40,40,40, 1, 0);
    Animation sExplosion_ship(t7, 0,0,192,192, 64, 0.5);
    Animation sUFO(t8, 0, 0, 105, 64);
    Animation sForcefield(t9, 0, 0, 64, 64);

    std::list<Entity*> entities; // creates a vector to store entities

    Sound ufoS;
    ufoS.setBuffer(ufoSound);

    for (int i = 0; i < 15; i++) { // creates 15 asteroids
        asteroid *a = new asteroid();
        a->settings(sRock, rand()%W, rand()%H, rand()%360, 25);
        entities.push_back(a);
    }

    player *p = new player(); // creates the player
    p->settings(sPlayer,200,200,0,20);
    entities.push_back(p);

    /////main loop/////
    while (app.isOpen()) {
        Event event;

        while (app.pollEvent(event)) {
            if (event.type == Event::Closed) { // checks for closed app
                app.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) { // checks if space is pressed to fire bullets
                    bullet *b = new bullet();
                    b->settings(sBullet, p->x, p->y, p->angle, 10);
                    entities.push_back(b);
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) { // turns right
            p->angle += 3;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { // turns left
            p->angle -= 3;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) { // move forward in direction player is facing
            p->thrust = true;
        }
        else {
            p->thrust = false; // otherwise don't move
        }

        for(auto a:entities) { // loops through every entity in the vector
            for (auto b:entities) {
                if ((a->name == "asteroid" || a->name == "ufo") && b->name == "bullet") { // if the two entities are a bullet and an asteroid or ufo
                    if (isCollide(a, b)) { // if they are colliding, destroys both objects
                        a->life = false;
                        b->life = false;

                        Entity *e = new Entity(); // creates an explosion
                        e->settings(sExplosion, a->x, a->y);
                        e->name = "explosion";
                        entities.push_back(e);

                        if (a->name == "ufo") { // score for killing ufo
                            scoreVal += 15;
                        }
                        else { // score for killing asteroid
                            scoreVal++;
                        }

                        if (a->name == "asteroid") { // creates small asteroids if big one is killed
                            for (int i = 0; i < 2; i++) {
                                if (a->R == 15) {
                                    continue;
                                }

                                scoreVal += 4;

                                Entity *e = new asteroid(); // creates new asteroids (small)
                                e->settings(sRock_small, a->x, a->y, rand() % 360, 15);
                                entities.push_back(e);
                            }
                        }
                    }
                }

                if (a->name == "player" && (b->name == "asteroid" || b->name == "ufo")) { // if the active entities are a player and asteroid
                    if (isCollide(a, b)) { // if they are colliding
                        b->life = false; // kill the asteroid/ufo

                        Entity *e = new Entity(); // play explosion
                        e->settings(sExplosion_ship, a->x, a->y);
                        e->name = "explosion";
                        entities.push_back(e);

                        if (pickup == false) { // if they don't have forcefield proceed as normal
                            p->settings(sPlayer, W / 2, H / 2, 0, 20); // set player to respawn location
                            p->dx = 0;
                            p->dy = 0;
                            std::cout << "Score: " << scoreVal << std::endl;
                            scoreVal = 0;
                        }
                        else { // otherwise kill the forcefield
                            pickup = false;
                            ffLife = false;
                        }
                    }
                }

                if (a->name == "forcefield" && ffLife == false) { //kills forecfield if necessary
                    a->life = false;
                }

                if (a->name == "player" && b->name == "forcefield" && ffLife == true) { // checks if the player picks up the forcefield
                    if (isCollide(a, b)) {
                        pickup = true;
                        b->settings(sForcefield, a->x, a->y);
                    }
                }

                if (a->name == "player" && b->name == "forcefield" && pickup == true) { // once forcefield is picked up, the position matches that of the player
                        b->settings(sForcefield, a->x, a->y);
                }
            }
        }

        if (p->thrust) { // if thrust is true, thrust sprite is shown
            p->anim = sPlayer_go;
        }
        else { // else normal sprite
            p->anim = sPlayer;
        }

        for(auto e:entities) {
            if (e->name == "explosion") { // checks if the explosion animation is complete and delete it
                if (e->anim.isEnd()) {
                    e->life = 0;
                }
            }
        }

        if(rand()%150 == 0 && ffLife == false) { // creation of new forcecield powerup
            forcefield * f = new forcefield();
            f->settings(sForcefield,rand()%W,rand()%H,0,64);
            entities.push_back(f);
            ffLife = true;
        }

        if (asteroid::getCount() <= 0) {
            for (int i = 0; i < 15; i++) { // creates 15 asteroids
                asteroid *a = new asteroid();
                a->settings(sRock, rand()%W, rand()%H, rand()%360, 25);
                entities.push_back(a);
            }
        }

//        if (rand()%150 == 0) { // creates new asteroids at random (1 in 150 chance)
//            asteroid *a = new asteroid();
//            a->settings(sRock, 0,rand()%H, rand()%360, 25);
//            entities.push_back(a);
//         }

        if (uFO > 300 && ufoLife == false) {
            ufoLife = true;
            uFO = 0;
            ufo *u = new ufo();
            u->settings(sUFO, rand()%W, rand()%H, rand()%360, 64);
            entities.push_back(u);
            ufoS.play();
        }
        else {
            uFO += 1;
        }

        for(auto i = entities.begin(); i != entities.end();) { // checks for "dead" entities for removal
            Entity *e = *i;

            e->update();
            e->anim.update();

            if (e->life == false) {
                if (e->name == "ufo") {
                    ufoLife = false;
                }
                i=entities.erase(i);
                delete e;
            }
            else {
                i++;
            }
        }

        //////draw//////
        app.draw(background); // displays the background

        for(auto i:entities) { // displays each entity
            i->draw(app);
        }

        score.setString(sc + std::to_string(scoreVal)); // prepare score for display
        app.draw(score);

        app.display();
    }

    return 0;
}
