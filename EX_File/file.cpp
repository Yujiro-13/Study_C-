#include <fstream>
#include <iostream>

#define MAZESIZE_X 32
#define MAZESIZE_Y 32

struct t_wall
{
    unsigned char north : 2;
    unsigned char east : 2;
    unsigned char south : 2;
    unsigned char west : 2;
};

struct t_map
{
    t_wall wall[MAZESIZE_X][MAZESIZE_Y];
};

const char* MAP_FILE_PATH = "map.txt";

void map_write(t_map* map)
{
    std::ofstream ofile(MAP_FILE_PATH, std::ios::out | std::ios::binary);
    if (ofile.fail())
    {
        std::cerr << "Failed to open " << MAP_FILE_PATH << " for writing" << std::endl;
        return;
    }

    ofile.write(reinterpret_cast<const char*>(map), sizeof(t_map));

    ofile.close();
}

t_map map_read()
{
    t_map map;
    std::ifstream ifile(MAP_FILE_PATH, std::ios::in | std::ios::binary);
    if (ifile.fail())
    {
        std::cerr << "Failed to open " << MAP_FILE_PATH << " for reading" << std::endl;
        return map;
    }

    ifile.read(reinterpret_cast<char*>(&map), sizeof(t_map));

    ifile.close();

    // 以下はデバッグ用の出力
    std::cout << "map->wall[0][0].north: " << static_cast<int>(map.wall[0][0].north) << std::endl;
    std::cout << "map->wall[0][0].east: " << static_cast<int>(map.wall[0][0].east) << std::endl;
    std::cout << "map->wall[0][0].south: " << static_cast<int>(map.wall[0][0].south) << std::endl;
    std::cout << "map->wall[0][0].west: " << static_cast<int>(map.wall[0][0].west) << std::endl;
    std::cout << "map->wall[11][26].north: " << static_cast<int>(map.wall[11][26].north) << std::endl;
    std::cout << "map->wall[14][18].east: " << static_cast<int>(map.wall[14][18].east) << std::endl;
    std::cout << "map->wall[4][31].south: " << static_cast<int>(map.wall[4][31].south) << std::endl;
    std::cout << "map->wall[25][8].west: " << static_cast<int>(map.wall[25][8].west) << std::endl;

    return map;
}

int main()
{
    t_map myMap;

    myMap.wall[0][0].north = 0;
    myMap.wall[0][0].east = 1;
    myMap.wall[0][0].south = 1;
    myMap.wall[0][0].west = 1;
    myMap.wall[11][26].north = 0;
    myMap.wall[14][18].east = 1;
    myMap.wall[4][31].south = 0;
    myMap.wall[25][8].west = 1;

    map_write(&myMap);
    myMap = map_read();

    // Now, 'myMap' contains the data read from the file.

    return 0;
}
