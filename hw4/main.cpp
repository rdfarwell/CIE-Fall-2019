/*
 * Name: Dean Farwell
 * Date: 10/13/2019
 * Filename: main.cpp
 * Note: Early turn-in
 * Description: A doodle point clone taken from another user, then modified and cleaned by me. This is an intro to SFML.
 */

#include <SFML/Graphics.hpp>
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

    RenderWindow app(VideoMode(400, 533), "Doodle Game!"); // creates the display window
    app.setFramerateLimit(60); // limits the frame rate to 60

    Texture t1,t2,t3; // initialze the three different sprites we will use in the game
    t1.loadFromFile("images/background.png"); // loads and checks the background image file
    if (!t1.loadFromFile("images/background.png")) {
        return EXIT_FAILURE;
    }

    t2.loadFromFile("images/platform.png"); // loads and checks the platfrom image file
    if (!t2.loadFromFile("images/platform.png")) {
        return EXIT_FAILURE;
    }

    t3.loadFromFile("images/doodle.png");  // loads and checks the character image file
    if (!t3.loadFromFile("images/doodle.png")) {
        return EXIT_FAILURE;
    }

    Sprite sBackground(t1), sPlat(t2), sPers(t3); // sets the three loaded images as sprites

    point plat[20]; // creates an array of 20 platforms to be displayed, although only 10 are used at a time

    for (int i = 0; i < 10; i++) { // creates 10 random platforms
       plat[i].setX(rand()%400);
       plat[i].setY(rand()%533);
      }

	int x = 100, y = 100, h = 200; // initialize start conditions for the character
    float dx = 0, dy = 0;

    while (app.isOpen()) { // while the window is open
        Event e; // creates an event of game running
        while (app.pollEvent(e)) { // checks if the game is running
            if (e.type == Event::Closed) {
                app.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) { // if right arrow pressed, character moves three pixels right
            x += 3;
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) { // if left arrow pressed, character moves three pixels left
            x -= 3;
        }

        dy += 0.2; // counters used to tracking platform storage and location
        y += dy;

        if (y > 500) {
            dy = -10;
        }

	    if (y < h) { // determines the height of the character and creates new platforms above the current ones
            for (int i = 0; i < 10; i++) {
                y = h;
                plat[i].setY(plat[i].getY() - dy);
                if (plat[i].getY() > 533) {
                    plat[i].setY(0);
                    plat[i].setX(rand()%400);
                }
            }
        }

	    for (int i = 0; i < 10; i++) { // checks if the character is touching any of the displayed platforms
            if ((x + 50 > plat[i].getX()) && (x + 20 < plat[i].getX() + 68) && (y + 70 > plat[i].getY()) && (y + 70 < plat[i].getY() + 14) && (dy > 0)) {
                dy = -10;
            }
        }

	    sPers.setPosition(x, y); // dipslays the chracter and backround image
        app.draw(sBackground);
        app.draw(sPers);

        for (int i = 0; i < 10; i++) { // displays each platform
            sPlat.setPosition(plat[i].getX(), plat[i].getY());
            app.draw(sPlat);
        }

        app.display(); // pushes all the drawings to the screen
    }

    return 0;
}