#include <assert.h>
#include "TextureHolder.h"

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(this->instance == nullptr);
	instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& _filename)
{
	// Get a reference to m_Textures using m_S_Instance
	auto& m = TextureHolder::instance->textures;
	// auto is the equivalent of map<string, Texture>

	// Create an iterator to hold a key-value-pair (kvp)
	// and search for the required kvp
	// using the passed in file name
	auto keyValuePair = m.find(_filename);
	// auto is equivelant of map<string, Texture>::iterator
	
		
	// Did we find a match?
	if (keyValuePair != m.end())
	{
		// Yes
		// Return the texture,
		// the second part of the kvp, the texture
		return keyValuePair->second;
	}
	else
	{
		// File name not found
		// Create a new key value pair using the filename
		auto& texture = m[_filename];
		// Load the texture from file in the usual way
		texture.loadFromFile(_filename);

		// Return the texture to the calling code
		return texture;
	}
}