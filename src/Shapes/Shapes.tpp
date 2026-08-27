namespace Shapes 
{
	line::line(const Vector<float>& start, const  Vector<float>& end, const sf::Color& ColorS, const sf::Color& ColorEnd):vertices(sf::PrimitiveType::Lines, 2)
	{
		vertices[0].position = sf::Vector2f({ start.x, start.y });
		vertices[0].color = ColorS;

		vertices[1].position = sf::Vector2f({ end.x, end.y });
		vertices[1].color = ColorEnd;
	}
	void line::draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		target.draw(vertices, states);
	}
}