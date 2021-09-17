#pragma once
#include <core/utils.h>
#include <sdk/world/Tile.h>

struct World;

#pragma pack(push, 1)
GTClass WorldTileMap {
   public:
    void* vftable;
    CL_Vec2i size; //basically world width, height (usually 100, 60)
    char pad0[8];  //TODO: probaly 2 4-byte variable here, or 1 8-byte variable

   public:
    std::vector<Tile> tiles;
    World* world;

    CL_Vec2i& WorldSize() {
        return size;
    }
    //make own func instead of calling, to verify our tiles are correct!

    Tile* GetTileSafe(int col, int row) {
        if (col >= size.x || row >= size.y || col < 0 || row < 0)
            return nullptr;
        else
            return &tiles[col + row * size.x];
    }
    Tile* GetTileSafe(CL_Vec2i vec) {
        return GetTileSafe(vec.x, vec.y);
    }
};

#pragma pack(pop)
