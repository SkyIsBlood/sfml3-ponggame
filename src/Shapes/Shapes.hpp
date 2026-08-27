namespace Shapes
{
	struct line:public sf::Drawable
	{
		sf::VertexArray vertices;

		line(const Vector<float>& start ,const Vector<float>& end ,const sf::Color& ColorS ,const sf::Color& ColorEnd);

		private:
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}


#include "Shapes.tpp"