#include "mainloop.hpp"

void MAINLOOP::mainloop(sf::RenderWindow& mainwindow)
{
    float dt;
    float last = 0 ;
    float now;
    bool left = false;
    bool right = false;
    const float SPEED = 100; //speed of the platform 
    const float MAX_SPEED = 120; //max speed
    int hearts = Config::LIVES;
    bool alive = true;
    sf::Clock clock;
    float ball_speed = 5;
    // why i did that ...i don't remember ? 
    //init the entities
    Entity<float> ball(Assets::ball, Vector<float>(Config::WindowWidth / 2, Config::WindowHeight / 2), 1, 1, 15);
    Entity<float> block(Assets::block, Vector<float>(Config::WindowWidth / 2, 500), 1.f, 0.2, MAX_SPEED);
    ball.velocity.y = ball_speed;

    while (mainwindow.isOpen())
    {
        mainwindow.clear(Config::BACKGROUND);
        //delta time claculation
        now = clock.getElapsedTime().asSeconds();
        dt = now - last;
        last = now;
        //event checking
        while (const auto event = mainwindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                mainwindow.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Escape)
                {
                    mainwindow.close();
                }
                if (keyPressed->code == sf::Keyboard::Key::D)
                {
                    right = true;
                }
                if (keyPressed->code == sf::Keyboard::Key::A)
                {
                    left = true;
                }
            }
            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyReleased->code == sf::Keyboard::Key::D)
                {
                    right = false;
                }
                if (keyReleased->code == sf::Keyboard::Key::A)
                {
                    left = false;
                }
            }

        }


        // holding a key 
        if (right)
        {
            block.applyforce(Vector<float>(SPEED, 0));
        }
        if (left)
        {
            block.applyforce(Vector<float>(-SPEED, 0));
        }

        //updating entities
        block.update(dt);
        ball.update(dt);
        //  can't remember why i did it like that ...but when i deleted it it break everything
        if (core::border(ball))
        {
            hearts -= 1;
        }
        core::showhearts(hearts, mainwindow);
        core::withblock(ball, block, ball_speed);
        // rendering to the screen 
        Renderer::render_entity(mainwindow,ball);
        Renderer::render_entity(mainwindow,block);
        mainwindow.display();
    }
}