#include <fstream>
#include <stdexcept>

#include "Map.hpp"

Map::Map(std::string mapFilename)
{
	loadTextures();
	loadMap(mapFilename);
}


// ------------------- Load -------------------
void Map::loadTextures()
{
	sf::Texture* texture = new sf::Texture();

	texture = new sf::Texture();
	if (!texture->loadFromFile("assets/2 Dungeon Tileset/1 Tiles/Tile_20.png")) {
		delete texture;
		throw std::runtime_error("Failed to load floor texture");
	}
	_textures[TileType::FLOOR] = texture;
}

void Map::loadMap(std::string filename)
{
	std::ifstream file(filename);
	if (!file) {
		throw std::runtime_error("Failed to open " + filename);
	}

	std::vector<std::vector<TileType>> mapData;
	std::string line;
	while (std::getline(file, line)) {
		if (line.empty())
			throw std::runtime_error("Empty line found in " + filename);

		mapData.push_back(std::vector<TileType>());
		for (const auto& token : line) {
			if (!isValidTileType(token))
				throw std::runtime_error("Invalid tile type in " + filename + ": " + token);
			mapData.back().push_back(static_cast<TileType>(token));
		}
	}
	file.close();

	if (mapData.empty())
		throw std::runtime_error("Map file is empty or malformed");

	_size.y = mapData.size();
	_size.x = 0;
	for (const auto& row : mapData)
		if (row.size() > _size.x)
			_size.x = row.size();

	_data = std::make_unique<TileType[]>(static_cast<size_t>(_size.x * _size.y));
	for (unsigned int y = 0; y < _size.y; ++y) {
		for (unsigned int x = 0; x < _size.x; ++x) {
			_data[y * _size.x + x] = (x < mapData[y].size()) ? mapData[y][x] : TileType::EMPTY;
		}
	}

	_filename = filename;
}


// ------------------- Getters -------------------
sf::Vector2u Map::getMapSize() const
{
	return _size;
}

TileType& Map::operator[](sf::Vector2u coords)
{
	unsigned int x = coords.x;
	unsigned int y = coords.y;

	if (x >= _size.x || y >= _size.y)
		throw std::out_of_range("Map coordinates out of range");

	return _data[y * _size.x + x];
}

const TileType& Map::operator[](sf::Vector2u coords) const
{
	unsigned int x = coords.x;
	unsigned int y = coords.y;

	if (x >= _size.x || y >= _size.y)
		throw std::out_of_range("Map coordinates out of range");

	return _data[y * _size.x + x];
}


// ------------------- TileType -------------------
bool isValidTileType(int value)
{
	switch (value) {
		case TileType::EMPTY:
		case TileType::FLOOR:
		case TileType::PLAYER:
			return true;

		default:
			return false;
	}
}


// ------------------- Draw -------------------
void Map::draw(sf::RenderWindow &window, sf::Vector2f tileSize) const
{
	sf::Vector2u coords(0, 0);
	while (coords.y < _size.y) {
		coords.x = 0;
		while (coords.x < _size.x) {
			const TileType& tileType = (*this)[coords];
			if (tileType == TileType::EMPTY)
				continue;

			sf::Texture const* texture = _textures.at(tileType);
			sf::Sprite sprite(*texture);
			sprite.setPosition(sf::Vector2f(coords.x * tileSize.x, coords.y * tileSize.y));
			sf::Vector2f scale(
				tileSize.x / sprite.getTexture().getSize().x,
				tileSize.y / sprite.getTexture().getSize().y
			);
			sprite.setScale(scale);
			window.draw(sprite);

			coords.x++;
		}
		coords.y++;
	}
}
