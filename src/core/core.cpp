#include "core.hpp"
int core::border(Entity<float>& e)
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
        
        if (e.position.y < 0)
        {
            e.position.y = HSH;
            e.velocity.y = e.velocity.y * -bounce;
        }
        else if ((e.position.y + HSH) >= Config::WindowHeight)
        {
            e.position.y = Config::WindowHeight - HSH;
            e.velocity.y = e.velocity.y * -bounce;
            return 1;
        }
        return 0;
    }

}
void core::withblock(Entity<float>& A, const Entity<float>& B ,float & ball_speed)
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
        ball_speed *= bounce;
        float dir;
        if (offset < 0.3 && offset > -0.3) {dir = 0; }
        else if (offset > 0.3) {dir = 1; }
        else if (offset < -0.3 ) {dir = -1; }
        std::cout << "ball speed : "<<ball_speed << std::endl;
        A.velocity.x = dir;
        A.velocity.y = -1;
        A.velocity.setmag(ball_speed);
    }
}
void core::showhearts(int& hearts, sf::RenderWindow& mainwindow)
{
    for ( int i = 0 ;i <  hearts ; i ++)
    {
        Vector<float> scale(1, 1);
        Vector<float> pos = Vector<float>((scale.x * (16 + 2)  * i  ), (0));
        
        Renderer::render_sprite(mainwindow , Assets::heart ,pos ,scale);
    }
}