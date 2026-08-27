
template <typename T>
Entity<T>::Entity(const std::string& texture_path
					,const Vector<T>& position
					,float mass,float friction,float max_velocity
):Body::Body<T>(position, mass,friction , max_velocity)
{
	
	if (!texture.loadFromFile(texture_path)) 
	{
		exit(-1);
	}
	
}