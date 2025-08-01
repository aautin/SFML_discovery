#ifndef MAP_HPP
# define MAP_HPP

# include <unordered_map>
# include <memory>
# include <SFML/Graphics.hpp>

// ------------------- TileType -------------------
enum TileType : int
{
	EMPTY = '0',
	FLOOR = '1',
	PLAYER = '2',
};
bool	isValidTileType(int value);


// ------------------- Map -------------------
class Map
{
	public:
		Map(std::string mapFilename);
		~Map() {}

		void			render(sf::RenderWindow &window, sf::Vector2u tileSize) const;

		sf::Vector2u	getMapSize() const;
		TileType&		operator[](sf::Vector2u coords);
		const TileType&	operator[](sf::Vector2u coords) const;

		sf::Vector2u	extractPlayerPosition();

	private:
		void	loadTextures();
		void	loadMap(std::string filename);

		std::unordered_map<TileType, sf::Texture*>	_textures;
		std::string									_filename;
		std::unique_ptr<TileType[]>					_data;
		sf::Vector2u								_size;
};

#endif