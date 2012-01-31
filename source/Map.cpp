#include "Map.hpp"

Map::Map(string filename,Screen* s,vector<Sprite*> *spr){
	screen = s;
	sprites = spr;
	std::ifstream map(filename.c_str());
	int x = 0, y = 0;
	
	for(int t = 0; t < TILES_PER_SCREEN; t++){
		int tileType = -1;
		map >> tileType;
		
		if((tileType >= 0)&&(tileType < TOTAL_TILES)){
			tiles.push_back(new Tile(screen,(*sprites)[1],tileType,x,y));
		}
		
		x += TILE_WIDTH;
		
		if(x >= 640){
			x = 0;
			y += TILE_HEIGHT;
		}
	}
	
	/*std::cout << vTiles.max_size() << std::endl;
	std::cout << vTiles.size() << std::endl;*/
	
	map.close();
	
	
}

Map::~Map(){
	tiles.clear();
}

void Map::render(){
	for(int i = 0; i < tiles.size(); i++){
		tiles[i]->render();
	}
}

bool Map::isCollide(Entitiy *other){
	for(i=0; i<tiles.size();i++){
		if((other->isCollisionWith(tiles[i]))&&(tiles[i].gType == WATER))
			return true;
	}
	
	return false;
}