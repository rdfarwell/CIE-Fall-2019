/*
 * Name: Dean Farwell
 * Date: 10/20/2019
 * Filename: main.cpp
 * Note: Early turn-in
 * Description: My own mix of the DoodlePoint games, but as a satirical look on Connor (He gave me permission)
 *              My two additions are wrap around and a power up
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>

using namespace sf;

// class that creates a point of x and y and contains getter and setter functions.
class point {
public:
    void setX(const int &x);
    void setY(const int &y);
    const int &getX() const;
    const int &getY() const;
private:
    int m_x;
    int m_y;
};

// setter function for x
void point::setX(const int &x) {
    m_x = x;
}

// setter function for y
void point::setY(const int &y) {
    m_y = y;
}

// getter function for x
const int &point::getX() const {
    return m_x;
}

// getter function for y
const int &point::getY() const {
    return m_y;
}

int main() {
    srand(time(0)); // creates a random number based on the time for placing platforms

    RenderWindow app(VideoMode(400, 533), "Connor Paul Lichamer"); // creates the display window
    app.setFramerateLimit(60); // limits the frame rate to 60

    Texture t1,t2,t3,t4; // initialze the three different sprites we will use in the game
    Font fancy; // init the font
    SoundBuffer death, jump; // init the two sounds
    Music soundtrack; //  init the background song

    // loads and checks the background image file
    t1.loadFromFile("images/black.png"); // black background created by me
    if (!t1.loadFromFile("images/black.png")) {
        return EXIT_FAILURE;
    }

    t2.loadFromFile("images/Jeep.png"); // picture of Connor's Jeep, asked him for permission, edited by me
    if (!t2.loadFromFile("images/Jeep.png")) {
        return EXIT_FAILURE;
    }

    t3.loadFromFile("images/Connor.png");  // picture of Connor, taken by me, used with permission, edited by me
    if (!t3.loadFromFile("images/Connor.png")) {
        return EXIT_FAILURE;
    }

    t4.loadFromFile("images/ACE.png"); // using ACE Hardware logo under fair use, education only, not for profit, not many will see it
    if (!t4.loadFromFile("images/ACE.png")) {
        return EXIT_FAILURE;
    }

    fancy.loadFromFile("fonts/Bostella.ttf"); // Bostella by dcoxy, https://www.1001freefonts.com/, License: Free for personal use.
    if (!fancy.loadFromFile("fonts/Bostella.ttf")) {
        return EXIT_FAILURE;
    }

    death.loadFromFile("sounds/death.ogg"); // Recorded by me
    if (!death.loadFromFile("sounds/death.ogg")) {
        return EXIT_FAILURE;
    }

    jump.loadFromFile("sounds/jump.ogg"); // Recorded by me
    if (!jump.loadFromFile("sounds/jump.ogg")) {
        return EXIT_FAILURE;
    }

    soundtrack.openFromFile("sounds/soundtrack.ogg"); // Recorded by me
    if (!soundtrack.openFromFile("sounds/soundtrack.ogg")) {
        return EXIT_FAILURE;
    }

    Sprite sBackground(t1), sPlat(t2), sPers(t3), sPU(t4); // sets the three loaded images as sprites

    point plat[20]; // creates an array of 20 platforms to be displayed, although only 10 are used at a time
    point powerUp;

    int j = 0; // checks for creating power up
    int check = 0;

    for (int i = 0; i < 10; i++) { // creates 10 random platforms
       plat[i].setX(rand()%400);
       plat[i].setY(rand()%533);
    }

	int x = 100, y = 100, h = 200; // initialize start conditions for the character
    float dx = 0, dy = 0;
    int scoreNum = 0, dead = 0;

    Sound deathSound; // init death sound as a sound
    deathSound.setBuffer(death);

    Sound jumpSound; // init jump sound as a sound
    jumpSound.setBuffer(jump);

    soundtrack.setLoop(true); // set the background music to loop

    Text over; // creates the game over text
    over.setFont(fancy);
    over.setString("   Game Over!\nPress R to restart");
<<<<<<< .mine
    over.setCharacterSize(60);
    over.setPosition(50, 20);
||||||| .r168939
    over.setCharacterSize(70);
    over.setPosition(100, 20);
=======
    over.setCharacterSize(70);
    over.setPosition(40, 20);
>>>>>>> .r169967
    over.setFillColor(Color::Red);

    Text score; // creates the score text
    score.setFont(fancy);
    score.setCharacterSize(40);
    score.setFillColor(Color::Red);

    soundtrack.play(); // starts the background music

    while (app.isOpen()) { // while the window is open
        Event e; // creates an event of game running
        while (app.pollEvent(e)) { // checks if the game is running
            if (e.type == Event::Closed) {
                app.close();
            }
        }

        if (y + 50 >= 533) { // checks for character at bottom, death
            if (dead == 0) {
                deathSound.play(); // play death sound
                dead = 1;
            }

            app.draw(over); // display the game over screen

            if (Keyboard::isKeyPressed(Keyboard::R)) {
                for (int i = 0; i < 10; i++) { // creates 10 random platforms
                    plat[i].setX(rand()%400);
                    plat[i].setY(rand()%533);
                }

                x = 100; // resets all locations and scores
                y = 100;
                h = 200;
                dy = 0;
                scoreNum = 0;
                dead = 0;
            }
        }

        else { // if not dead
            if (Keyboard::isKeyPressed(Keyboard::Right)) { // if right arrow pressed, character moves three pixels right
                x += 3;
            }

            if (Keyboard::isKeyPressed(Keyboard::Left)) { // if left arrow pressed, character moves three pixels left
                x -= 3;
            }

            dy += 0.2; // counters used to tracking platform storage and location
            y += dy;
            j += 1;
            scoreNum += h / 100; // creates a score based on time alive
            std::string sc = "Score: ";
            sc += std::to_string(scoreNum); // adds the score to the string for output
            score.setString(sc); // sets score object as the score string

            if (y < h) { // determines the height of the character and creates new platforms above the current ones
                for (int i = 0; i < 10; i++) { // in charge of moving the platforms
                    y = h;
                    plat[i].setY(plat[i].getY() - dy);
                    if (plat[i].getY() > 533) { // creates the platforms
                        plat[i].setY(0);
                        plat[i].setX(rand() % 400);

                        if ((j >= 200) && (check != 1)) { // creates a powerup at certain intervals
                            powerUp.setX(plat[i].getX() + 15);
                            powerUp.setY(plat[i].getY() - 30);
                            check = 1;
                            j = 0;
                        }
                    }
                }
                powerUp.setY(powerUp.getY() - dy); // moves powerup and checks if it is out of bounds
                if (powerUp.getY() > 533) {
                    powerUp.setY(-100);
                    powerUp.setX(-100);
                    check = 0;
                    j = 0;
                }
            }

            if (x > 400) { // checks if user is off screen to the right, and moves them to the far left
                x = -40;
            }

            if (x + 40 < 0) { // checks if user is off screen to the left, and moves them to the far right
                x = 400;
            }

            for (int i = 0; i < 10; i++) { // checks if the character is touching any of the displayed platforms
                if ((x + 65 > plat[i].getX()) && (x + 20 < plat[i].getX() + 71) && (y + 110 > plat[i].getY()) &&
                    (y + 110 < plat[i].getY() + 10) && (dy > 0)) {
                    jumpSound.play();
                    dy = -10;
                }
            }

            if ((x + 40 > powerUp.getX())  && (x + 20 < powerUp.getX() + 40) && (y + 110 > powerUp.getY()) && // checks if the character is touching a power up
                (y + 110 < powerUp.getY() + 25)) {
                jumpSound.play();
                dy = -30;
            }

            sPers.setPosition(x, y); // displays the character and background image
            app.draw(sBackground);
            app.draw(sPers);
            app.draw(score);

            sPU.setPosition(powerUp.getX(), powerUp.getY()); // displays the power up
            app.draw(sPU);

            for (int i = 0; i < 10; i++) { // displays each platform
                sPlat.setPosition(plat[i].getX(), plat[i].getY());
                app.draw(sPlat);
            }
        }

        app.display(); // pushes all the drawings to the screen
    }

    return 0;
}