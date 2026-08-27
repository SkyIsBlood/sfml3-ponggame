
void core::border(Entity<float>& e)
{
    {
        float bounce = 1;
        auto size = e.texture.getSize();
        float HSW = static_cast<float>(size.x / 2);
        float HSH = static_cast<float>(size.y / 2);
        auto position = e.position;


        //check right and left
        if ((position.x + HSW) >= Config::WindowWidth)
        {
            e.position.x = Config::WindowWidth - HSW;
            e.velocity.x = e.velocity.x * -bounce;
        }
        else if (e.position.x < 0)
        {
            e.position.x = HSW;
            e.velocity.x *= -bounce;

        }
        //check down and up
        if ((e.position.y + HSH) >= Config::WindowHeight)
        {
            e.position.y = Config::WindowHeight - HSH;
            e.velocity.y = e.velocity.y * -bounce;
        }
        else if (e.position.y < 0)
        {
            e.position.y = HSH;
            e.velocity.y = e.velocity.y * -bounce;
        }
    }

}
void core::withblock(Entity<float>& A, const Entity<float>& B ,float dt)
{
    // entity A is the ball while entity B is the static object
    float bounce = 1;
    auto sizeA = A.texture.getSize();
    auto sizeB = B.texture.getSize();
    float HwB = static_cast<float>(sizeB.x / 2);
    float HhB = static_cast<float>(sizeB.y / 2);
    float HwA = static_cast<float>(sizeA.x / 2);
    float HhA = static_cast<float>(sizeA.y / 2);



    Vector<float> RPA = (A.position) - (B.position);//reletive position 
    //Vector<float> rpAF = (RPA + A.velocity + Vector<float>(0, sizeA.y / 2) + Config::GRAVITY) * dt; //future position 
    bool overlap_x = std::abs(RPA.x) <= (HwB + HwA);
    bool overlap_y = std::abs(RPA.y) <= (HhB + HhA);

    if (overlap_x && overlap_y && A.velocity.y > 0)
    {
        //correct he position of the ball
        A.position.y = B.position.y - HhB - HhA;
        float offset = std::clamp(RPA.x / HwB, -1.0f, 1.0f);
        float speed = A.velocity.mag();
        const float MAX_BOUNCE_ANGLE = 90.0f * (3.14159265f / 180.0f);
        float bounce_angle = MAX_BOUNCE_ANGLE * offset;
        A.velocity.x = speed * std::cos(bounce_angle);
        A.velocity.y = - speed * std::sin(bounce_angle);

    }
}

void core::mainloop(sf::RenderWindow& mainwindow)
{
    const float SPEED = 80; //speed of the platform 
    const float MAX_SPEED = 120; //max speed
    float dt;
    float last = 0;
    float now;
    bool left = false;
    bool right = false;
    Vector<float> gravity = Config::GRAVITY;
    sf::Clock clock;


    //init the entities
    Entity<float> ball(Assets::ball, Vector<float>(Config::WindowWidth/2,Config::WindowHeight/2), 1 ,1,15);
    Entity<float> block(Assets::block, Vector<float>(Config::WindowWidth / 2, 500), 1.f,0.7,MAX_SPEED);
    
    //set the ball position
    ball.velocity = Vector<float>(3, 10);
    
    
    
    clock.start();
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
        core::border(ball);
        core::withblock(ball, block,dt);


        // rendering to the screen 
        Renderer::render(mainwindow,ball);
        Renderer::render(mainwindow, block);
        mainwindow.display();
    }
}
